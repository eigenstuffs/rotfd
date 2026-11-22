#!/usr/bin/env python3
"""Export durable progress from objdiff's report, after verifying the built DOL.

Writes PROGRESS.md and progress/<version>.json from build/<version>/report.json.
"""

import argparse
import hashlib
import json
from pathlib import Path

if __package__:
    from .audit_source_extents import assert_source_extents
else:
    from audit_source_extents import assert_source_extents


COUNTS = (
    "total_code", "matched_code", "complete_code", "total_data", "matched_data",
    "complete_data", "total_functions", "matched_functions", "total_units",
    "complete_units",
)


def measures(raw):
    result = {key: int(raw.get(key, 0)) for key in COUNTS}
    for matched, total in (
        ("matched_code", "total_code"), ("complete_code", "total_code"),
        ("matched_data", "total_data"), ("complete_data", "total_data"),
        ("matched_functions", "total_functions"), ("complete_units", "total_units"),
    ):
        if not 0 <= result[matched] <= result[total]:
            raise ValueError(f"Invalid progress: {matched} exceeds {total}")
        result[matched + "_percent"] = (
            100.0 * result[matched] / result[total] if result[total] else 0.0
        )
    result["fuzzy_match_percent"] = float(raw.get("fuzzy_match_percent", 0))
    return result


def sha1(path):
    return hashlib.sha1(path.read_bytes()).hexdigest()


def make_snapshot(report, version, expected_sha1, actual_sha1):
    if report.get("version") != 2:
        raise ValueError("Expected objdiff report schema version 2")
    if actual_sha1 != expected_sha1:
        raise ValueError("Built DOL does not match the original; refusing a verified snapshot")
    totals = measures(report["measures"])
    units = []
    functions = []
    # Derive a mutually exclusive partition from unit assignments. Missing
    # categories always remain visible in the overall denominator.
    category_names = {c["id"]: c["name"] for c in report.get("categories", [])}
    category_names.setdefault("unclassified", "Unclassified Original Code / Data")
    category_totals = {}
    category_fuzzy_weight = {}
    for unit in report["units"]:
        meta = unit.get("metadata", {})
        counts = measures(unit.get("measures", {}))
        category_ids = meta.get("progress_categories", [])
        category = next((c for c in category_ids if c not in ("dol", "modules")), "unclassified")
        category_counts = category_totals.setdefault(category, {key: 0 for key in COUNTS})
        for key in COUNTS:
            category_counts[key] += counts[key]
        category_fuzzy_weight[category] = category_fuzzy_weight.get(category, 0) + counts["total_code"] * counts["fuzzy_match_percent"]
        source = meta.get("source_path", "")
        complete = bool(meta.get("complete", False))
        if complete and (not source or counts["complete_units"] != 1):
            raise ValueError(f"Inconsistent complete unit: {unit['name']}")
        if source:
            units.append({
                "name": unit["name"], "source": source, "category": category,
                "status": "linked" if complete else "nonmatching", "measures": counts,
            })
        for function in unit.get("functions", []):
            address = function.get("metadata", {}).get("virtual_address")
            # A fuzzy score is useful for choosing work, but is explicitly not
            # recorded as a byte-match verdict in the ledger.
            functions.append({
                "address": f"0x{int(address):08X}" if address is not None else "",
                "symbol": function["name"], "size": int(function.get("size", 0)),
                "unit": unit["name"], "category": category, "source": source,
                "unit_status": "linked" if complete else ("nonmatching" if source else "assembly"),
                "objdiff_fuzzy_percent": float(function.get("fuzzy_match_percent", 0)),
            })
    for key in COUNTS:
        if sum(c[key] for c in category_totals.values()) != totals[key]:
            raise ValueError(f"Unit totals disagree with report aggregate: {key}")
    if len(functions) != totals["total_functions"]:
        raise ValueError("Function inventory does not agree with the report total")
    for category, counts in category_totals.items():
        counts["fuzzy_match_percent"] = category_fuzzy_weight[category] / counts["total_code"] if counts["total_code"] else 0.0
    summary = {
        "schema_version": 1, "game_id": version,
        "title": "SpongeBob SquarePants: Revenge of the Flying Dutchman",
        "verification": {"dol_sha1": actual_sha1, "expected_sha1": expected_sha1, "byte_identical": True},
        "measures": totals,
        "categories": [
            {"id": key, "name": category_names.get(key, key), "measures": measures(value)}
            for key, value in sorted(category_totals.items())
        ],
        "source_units": sorted(units, key=lambda u: u["name"]),
    }
    return summary, sorted(functions, key=lambda f: (f["address"], f["symbol"]))


def markdown(summary):
    m = summary["measures"]
    lines = [
        "# Progress", "",
        f"Rebuilt `main.dol` SHA-1 `{summary['verification']['dol_sha1']}` matches the original.", "",
        "| | Matched |", "| --- | ---: |",
        f"| Code | {m['matched_code']:,} / {m['total_code']:,} bytes ({m['matched_code_percent']:.2f}%) |",
        f"| Functions | {m['matched_functions']:,} / {m['total_functions']:,} |",
        f"| Data | {m['matched_data']:,} / {m['total_data']:,} bytes ({m['matched_data_percent']:.2f}%) |",
        f"| Units | {m['complete_units']:,} / {m['total_units']:,} |", "",
    ]
    return "\n".join(lines)


def write_progress(version="GSQE78", build_dir=Path("build"), root=Path("."), check=False):
    report_path = root / build_dir / version / "report.json"
    expected = (root / "config" / version / "build.sha1").read_text().split()[0]
    original = root / "orig" / version / "main.dol"
    if sha1(original) != expected:
        raise ValueError("Original DOL hash differs from the configured reference")
    report = json.loads(report_path.read_text())
    objdiff_bytes = (root / "objdiff.json").read_bytes()
    extent_audit = assert_source_extents(json.loads(objdiff_bytes), report, root)
    extent_audit["config_sha256"] = hashlib.sha256(objdiff_bytes).hexdigest()
    extent_audit["report_sha256"] = hashlib.sha256(report_path.read_bytes()).hexdigest()
    summary, functions = make_snapshot(
        report, version, expected, sha1(root / build_dir / version / "main.dol")
    )
    summary["verification"]["report_sha256"] = hashlib.sha256(report_path.read_bytes()).hexdigest()
    summary.pop("source_units", None)
    outputs = {
        root / build_dir / version / "source_extents.json": json.dumps(extent_audit, indent=2) + "\n",
        root / "PROGRESS.md": markdown(summary),
        root / "progress" / f"{version}.json": json.dumps(summary, indent=2) + "\n",
    }
    for path, contents in outputs.items():
        if check:
            if not path.exists() or path.read_text() != contents:
                raise ValueError(f"Stale progress export: {path}; run ninja")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            if not path.exists() or path.read_text() != contents:
                path.write_text(contents)
    print("Progress exports verified" if check else "Progress exports: PROGRESS.md, progress/" + version + ".json")
    return summary


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--version", default="GSQE78", choices=["GSQE78"])
    parser.add_argument("--build-dir", type=Path, default=Path("build"))
    parser.add_argument("--check", action="store_true", help="check exports against an already refreshed report")
    args = parser.parse_args()
    try:
        write_progress(args.version, args.build_dir, check=args.check)
    except (OSError, ValueError, KeyError) as error:
        parser.exit(1, f"progress: {error}\n")


if __name__ == "__main__":
    main()
