"""Reject linked data ownership beyond the compiled source's allocated sections.

Run after rebuilding the original objects, source objects, and native objdiff
report. This is an extent guard, not a substitute for byte/relocation matching.
Compiler-owned internal alignment remains inside ELF sh_size. Extra compiler
output from unused weak functions or exception metadata is permitted. Executable
section tails are deliberately excluded: objdiff counts functions, not text
section length (for example the uncredited MetroTRK alignment).
"""

import argparse
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import struct


def allocated_sections(path):
    """Read allocated section extents from a 32-bit ELF, including SHT_NOBITS."""
    data = Path(path).read_bytes()
    if len(data) < 52 or data[:5] != b"\x7fELF\x01" or data[5] not in (1, 2):
        raise ValueError(f"{path}: expected a 32-bit ELF object")
    endian = "<" if data[5] == 1 else ">"
    offset = struct.unpack_from(endian + "I", data, 32)[0]
    stride, count, names_index = struct.unpack_from(endian + "HHH", data, 46)
    if stride < 40 or not count or names_index >= count or offset + stride * count > len(data):
        raise ValueError(f"{path}: invalid ELF section table")
    headers = [struct.unpack_from(endian + "10I", data, offset + stride * i)
               for i in range(count)]
    names_header = headers[names_index]
    if names_header[4] + names_header[5] > len(data):
        raise ValueError(f"{path}: truncated ELF section names")
    names = data[names_header[4]:names_header[4] + names_header[5]]
    result = []
    for header in headers:
        name_offset, kind, flags, _, file_offset, size, _, _, alignment, _ = header
        if not flags & 2:  # SHF_ALLOC
            continue
        end = names.find(b"\0", name_offset)
        if name_offset >= len(names) or end < 0:
            raise ValueError(f"{path}: invalid allocated section name")
        if kind != 8 and file_offset + size > len(data):  # SHT_NOBITS has no file payload.
            raise ValueError(f"{path}: truncated allocated section")
        result.append({
            "name": names[name_offset:end].decode("utf-8"),
            "size": size,
            "alignment": alignment,
            "nobits": kind == 8,
            "executable": bool(flags & 4),
        })
    return result


def _index_units(document, label):
    indexed = {}
    for unit in document["units"]:
        if unit["name"] in indexed:
            raise ValueError(f"{label}: duplicate unit {unit['name']}")
        indexed[unit["name"]] = unit
    return indexed


def _groups(sections):
    grouped = defaultdict(list)
    for section in sections:
        grouped[section["name"]].append(section)
    return grouped


def _report_size(pieces, unit, section):
    """Aggregate distinct report pieces without assuming a contiguous layout."""
    intervals = []
    for piece in pieces:
        size = int(piece["size"])
        if size < 0:
            raise ValueError(f"{unit} {section}: negative report section size")
        address = piece.get("metadata", {}).get("virtual_address")
        if len(pieces) > 1 and address is None:
            raise ValueError(f"{unit} {section}: repeated report pieces need addresses")
        if address is not None and size:
            start = int(address)
            intervals.append((start, start + size))
    intervals.sort()
    if any(left[1] > right[0] for left, right in zip(intervals, intervals[1:])):
        raise ValueError(f"{unit} {section}: overlapping report pieces")
    return sum(int(piece["size"]) for piece in pieces)


def audit_source_extents(config, report, root=Path(".")):
    """Return violations without altering the report, objects, or source.

    Same-name ELF sections are summed, never mapped to inferred tail addresses.
    This conservatively detects an ownership total larger than all emitted
    pieces combined; it cannot prove the placement of individual pieces.
    """
    root = Path(root)
    configured = _index_units(config, "objdiff configuration")
    reported = _index_units(report, "objdiff report")
    # Validate both directions before filtering: a stale report must not retain
    # credit merely because its configured source has become incomplete/missing.
    for name, unit in reported.items():
        metadata = unit.get("metadata", {})
        if not metadata.get("complete") or not metadata.get("source_path"):
            continue
        candidate = configured.get(name, {})
        candidate_metadata = candidate.get("metadata", {})
        if (not candidate_metadata.get("complete") or not candidate.get("base_path")
                or candidate_metadata.get("source_path") != metadata["source_path"]):
            raise ValueError(f"{name}: report claims complete source {metadata['source_path']} "
                             "without matching complete configuration and base_path")
    findings = []
    checked_units = 0
    checked_sections = 0
    aggregated_sections = []
    compiler_excess = []
    for name, unit in configured.items():
        metadata = unit.get("metadata", {})
        if not metadata.get("complete"):
            continue
        if not metadata.get("source_path"):
            if unit.get("base_path"):
                raise ValueError(f"{name}: configured complete source object lacks source_path")
            continue  # Legitimate original fallback has no source ownership.
        if not unit.get("base_path"):
            raise ValueError(f"{name}: configured complete source {metadata['source_path']} "
                             "has no base_path")
        if name not in reported or not reported[name].get("metadata", {}).get("complete"):
            raise ValueError(f"{name}: complete source unit missing from the refreshed report")
        source = metadata.get("source_path")
        if not source or reported[name].get("metadata", {}).get("source_path") != source:
            raise ValueError(f"{name}: source ownership differs between configuration and report")
        target = _groups(allocated_sections(root / unit["target_path"]))
        compiled = _groups(allocated_sections(root / unit["base_path"]))
        sections = _groups(reported[name].get("sections", []))
        checked_units += 1
        for section, report_pieces in sections.items():
            if section not in target and any(int(piece["size"]) for piece in report_pieces):
                raise ValueError(f"{name} {section}: report section absent from target ELF; "
                                 "rebuild the report")
        for section, target_pieces in target.items():
            if any(piece["executable"] for piece in target_pieces):
                if not all(piece["executable"] for piece in target_pieces):
                    raise ValueError(f"{name} {section}: mixed executable/data section pieces")
                continue
            original_size = sum(piece["size"] for piece in target_pieces)
            report_pieces = sections.get(section, [])
            reported_size = _report_size(report_pieces, name, section)
            if original_size != reported_size:
                raise ValueError(f"{name} {section}: target ELF size {original_size} differs "
                                 f"from report size {reported_size}; rebuild the report")
            source_pieces = compiled.get(section, [])
            if any(piece["executable"] for piece in source_pieces):
                raise ValueError(f"{name} {section}: source section is executable but target is data")
            emitted_size = sum(piece["size"] for piece in source_pieces)
            checked_sections += 1
            record = {
                "unit": name,
                "source": source,
                "section": section,
                "source_bytes": emitted_size,
                "target_bytes": original_size,
                "reported_bytes": reported_size,
                "source_piece_count": len(source_pieces),
                "target_piece_count": len(target_pieces),
                "report_piece_count": len(report_pieces),
                "includes_bss": any(piece["nobits"] for piece in target_pieces),
            }
            if max(len(source_pieces), len(target_pieces), len(report_pieces)) > 1:
                aggregated_sections.append(record)
            if reported_size > emitted_size:
                findings.append(dict(record, bytes_beyond_source=reported_size - emitted_size))
            elif emitted_size > reported_size:
                compiler_excess.append(record)  # Dead-stripped weak output is not a deficit.
    return {
        "schema_version": 1,
        "passed": not findings,
        "checked_source_units": checked_units,
        "checked_data_sections": checked_sections,
        "bytes_beyond_source": sum(item["bytes_beyond_source"] for item in findings),
        "findings": findings,
        "aggregated_sections": aggregated_sections,
        "compiler_excess_sections": compiler_excess,
        "scope": "Allocated data/BSS extents only; no executable-tail inference or byte-match replacement.",
    }


def assert_source_extents(config, report, root=Path(".")):
    """Return a passing audit, or raise ValueError before publishing progress."""
    result = audit_source_extents(config, report, root)
    if result["findings"]:
        details = "; ".join(
            f"{item['source']} {item['section']}: {item['reported_bytes']} owned bytes, "
            f"{item['source_bytes']} emitted ({item['bytes_beyond_source']} beyond source)"
            for item in result["findings"]
        )
        raise ValueError(f"Source extents: {result['bytes_beyond_source']} data/BSS bytes "
                         f"beyond emitted source; {details}")
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--config", type=Path, default=Path("objdiff.json"))
    parser.add_argument("--report", type=Path, default=Path("build/GSQE78/report.json"))
    parser.add_argument("--output", type=Path, help="write the audit result as JSON")
    args = parser.parse_args()
    try:
        config_bytes = (args.root / args.config).read_bytes()
        report_bytes = (args.root / args.report).read_bytes()
        result = audit_source_extents(json.loads(config_bytes), json.loads(report_bytes), args.root)
        result["config_sha256"] = hashlib.sha256(config_bytes).hexdigest()
        result["report_sha256"] = hashlib.sha256(report_bytes).hexdigest()
        if args.output:
            output = args.root / args.output
            output.parent.mkdir(parents=True, exist_ok=True)
            output.write_text(json.dumps(result, indent=2) + "\n")
    except (OSError, ValueError, KeyError, UnicodeError, struct.error) as error:
        parser.exit(1, f"source extents: {error}\n")
    for item in result["findings"]:
        print(f"{item['source']} {item['section']}: {item['reported_bytes']} owned bytes, "
              f"{item['source_bytes']} emitted ({item['bytes_beyond_source']} beyond source)")
    if result["findings"]:
        parser.exit(1, f"source extents: {result['bytes_beyond_source']} data/BSS bytes "
                    f"beyond emitted source in {len(result['findings'])} sections\n")
    print(f"Source extents PASS: {result['checked_source_units']} linked source units, "
          f"{result['checked_data_sections']} data/BSS sections")


if __name__ == "__main__":
    main()
