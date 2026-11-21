#!/usr/bin/env python3
"""Export durable progress from objdiff's report, after verifying the built DOL.

The original report.json remains the decomp.dev interchange format. These
smaller exports are reviewable in Git and never infer matches from source size,
Ghidra output, symbol names, or the presence of a file.
"""

import argparse
import csv
import hashlib
import io
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
    version = summary["game_id"]
    lines = [
        "# Decompilation progress", "",
        "Generated by `ninja` from the objdiff report after the DOL hash check. "
        "Do not edit totals by hand.", "",
        f"**{version}** · Rebuilt DOL SHA-1: `{summary['verification']['dol_sha1']}` **PASS**", "",
        "| Measure | Verified result |", "| --- | ---: |",
        f"| Matched code | {m['matched_code']:,} / {m['total_code']:,} bytes ({m['matched_code_percent']:.4f}%) |",
        f"| Matched functions | {m['matched_functions']:,} / {m['total_functions']:,} |",
        f"| Matched data | {m['matched_data']:,} / {m['total_data']:,} bytes ({m['matched_data_percent']:.4f}%) |",
        f"| Code linked from source | {m['complete_code']:,} / {m['total_code']:,} bytes ({m['complete_code_percent']:.4f}%) |",
        f"| Completed build units | {m['complete_units']:,} / {m['total_units']:,} |", "",
        "The build still uses original assembly for unfinished units. A matching "
        "DOL is the reconstruction baseline, not 100% source decompilation. "
        "Generated build units are provisional splits, not recovered original files.", "",
        "## Coverage by assigned subsystem", "",
        "| Subsystem | Matched code / total bytes | Matched functions | Linked units |",
        "| --- | ---: | ---: | ---: |",
    ]
    for c in summary["categories"]:
        cm = c["measures"]
        lines.append(f"| {c['name']} | {cm['matched_code']:,} / {cm['total_code']:,} "
                     f"({cm['matched_code_percent']:.4f}%) | {cm['matched_functions']:,} / "
                     f"{cm['total_functions']:,} | {cm['complete_units']:,} / {cm['total_units']:,} |")
    lines += ["", "Subsystems include only assigned units. Unclassified code remains in "
              "the totals; a fully matched identified subset does not complete an entire SDK.", "",
              "## Source units", "", "| Source | Status | Matched functions | Matched code |",
              "| --- | --- | ---: | ---: |"]
    for unit in summary["source_units"]:
        um = unit["measures"]
        lines.append(f"| [{unit['source']}]({unit['source']}) | {unit['status']} | "
                     f"{um['matched_functions']} / {um['total_functions']} | "
                     f"{um['matched_code']} / {um['total_code']} |")
    lines += ["", "## Work and evidence", "",
              f"- [Function inventory](progress/{version}-functions.csv): addresses, sizes, source ownership, unit status and fuzzy scores. Unit status describes the enclosing build unit, not an individual function's match result.",
              f"- [Machine-readable summary](progress/{version}.json).",
              "- [Roadmap](docs/ROADMAP.md) and [matching policy](docs/PROGRESS_POLICY.md).",
              "- Full decomp.dev-compatible report: `build/" + version + "/report.json`.",
              "- Compare a saved baseline with `ninja changes`; save one before editing with `ninja baseline`.",
              "- Extracted scripts and Ghidra output are research references, excluded from source completion.", ""]
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
    stream = io.StringIO(newline="")
    fields = ("address", "symbol", "size", "unit", "category", "source", "unit_status", "objdiff_fuzzy_percent")
    writer = csv.DictWriter(stream, fieldnames=fields, lineterminator="\n")
    writer.writeheader()
    writer.writerows(functions)
    outputs = {
        root / build_dir / version / "source_extents.json": json.dumps(extent_audit, indent=2) + "\n",
        root / "PROGRESS.md": markdown(summary),
        root / "progress" / f"{version}.json": json.dumps(summary, indent=2) + "\n",
        root / "progress" / f"{version}-functions.csv": stream.getvalue(),
    }
    for path, contents in outputs.items():
        if check:
            if not path.exists() or path.read_text() != contents:
                raise ValueError(f"Stale progress export: {path}; run ninja")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            if not path.exists() or path.read_text() != contents:
                path.write_text(contents)
    print("Progress exports verified" if check else "Progress exports: PROGRESS.md, progress/" + version + "*")
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
