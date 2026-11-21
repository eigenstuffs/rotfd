#!/usr/bin/env python3

from argparse import ArgumentParser
import os
import json
import math
from pathlib import Path
from typing import Optional, Tuple

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))


UNIT_KEYS_TO_DIFF = [
    "fuzzy_match_percent",
    "matched_code_percent",
    "matched_data_percent",
    "complete_code_percent",
    "complete_data_percent",
]

FUNCTION_KEYS_TO_DIFF = [
    "fuzzy_match_percent",
]

Change = Tuple[str, str, float, float]


def positive_integer(value) -> Optional[int]:
    # Protobuf JSON encodes uint64 addresses and sizes as decimal strings.
    # Do not let bools, floats, or partially parsed strings establish identity.
    if type(value) is int:
        return value if value > 0 else None
    if isinstance(value, str) and value.isascii() and value.isdecimal():
        parsed = int(value)
        return parsed if parsed > 0 else None
    return None


def reconcile_function_names(functions: list[dict]) -> list[dict]:
    """Pair unique removals/additions at the same address and extent in one unit.

    This is only a reporting view: original records and measured scores remain
    unchanged. Count every before/after address, including two-sided records,
    so an alias or duplicate cannot hide a removal or a genuine regression.
    """
    addresses = []
    counts = {"from": {}, "to": {}}
    for function in functions:
        metadata = function.get("metadata", {})
        address = (
            positive_integer(metadata.get("virtual_address"))
            if isinstance(metadata, dict)
            else None
        )
        addresses.append(address)
        if address is not None:
            for side in counts:
                if side in function:
                    counts[side][address] = counts[side].get(address, 0) + 1

    removed = {}
    for index, (function, address) in enumerate(zip(functions, addresses)):
        if (
            address is None
            or counts["from"].get(address) != 1
            or counts["to"].get(address) != 1
        ):
            continue
        if "from" in function and "to" not in function:
            before = function["from"]
            size = positive_integer(before.get("size")) if isinstance(before, dict) else None
            if size is not None:
                removed[address] = (index, size)

    replacements = {}
    omitted = set()
    for index, (function, address) in enumerate(zip(functions, addresses)):
        if address not in removed or "to" not in function or "from" in function:
            continue
        after = function["to"]
        size = positive_integer(after.get("size")) if isinstance(after, dict) else None
        old_index, old_size = removed[address]
        if size != old_size or function["name"] == functions[old_index]["name"]:
            continue
        replacements[index] = {**function, "from": functions[old_index]["from"]}
        omitted.add(old_index)

    return [
        replacements.get(index, function)
        for index, function in enumerate(functions)
        if index not in omitted
    ]


def nonnegative_integer(value) -> Optional[int]:
    if type(value) is int and value >= 0:
        return value
    if isinstance(value, str) and value.isascii() and value.isdecimal():
        return int(value)
    return None


def _name(value) -> bool:
    return isinstance(value, str) and bool(value) and value.strip() == value


def _perfect(value) -> bool:
    return type(value) in (int, float) and value == 100


def _percentage(value) -> bool:
    return type(value) in (int, float) and math.isfinite(value) and 0 <= value <= 100


def _module(unit: dict) -> Optional[tuple[str, int]]:
    metadata = unit.get("metadata")
    if not isinstance(metadata, dict) or not _name(metadata.get("module_name")):
        return None
    module_id = nonnegative_integer(metadata.get("module_id"))
    if module_id is None:
        return None
    return metadata["module_name"], module_id


def _range(record: dict) -> Optional[tuple[int, int]]:
    metadata = record.get("metadata")
    address = positive_integer(metadata.get("virtual_address")) if isinstance(metadata, dict) else None
    size = positive_integer(record.get("size"))
    if address is None or size is None or address + size > 2**64:
        return None
    return address, address + size


def _complete_source(unit: dict, prior_owner: bool = False) -> bool:
    """Require explicit source ownership and complete measured allocations."""
    metadata = unit.get("metadata")
    measures = unit.get("measures")
    if not _name(unit.get("name")) or _module(unit) is None:
        return False
    if not isinstance(metadata, dict) or not isinstance(measures, dict):
        return False
    if metadata.get("complete") is not True or metadata.get("auto_generated") is not False:
        return False
    source = metadata.get("source_path")
    if not _name(source) or Path(source).suffix not in (".c", ".cpp", ".cc", ".cxx", ".cp", ".C", ".c++"):
        return False
    if any(not (_percentage(measures.get(key, 0)) if prior_owner and key == "matched_data_percent"
                else _perfect(measures.get(key))) for key in UNIT_KEYS_TO_DIFF):
        return False
    totals = []
    for kind in ("code", "data"):
        total = nonnegative_integer(measures.get("total_" + kind, 0))
        if total is None:
            return False
        matched = nonnegative_integer(measures.get("matched_" + kind, 0))
        complete = nonnegative_integer(measures.get("complete_" + kind, 0))
        if complete != total or matched is None or matched > total:
            return False
        if matched != total and not (prior_owner and kind == "data"):
            return False
        totals.append(total)
    sections = unit.get("sections", [])
    functions = unit.get("functions", [])
    if not isinstance(sections, list) or not isinstance(functions, list):
        return False
    positive_sections = []
    for section in sections:
        if not isinstance(section, dict):
            return False
        size = nonnegative_integer(section.get("size", 0))
        if size is None:
            return False
        if not size:
            continue
        score = section.get("fuzzy_match_percent", 0)
        valid_score = _percentage(score) if prior_owner and section.get("name") not in (".text", ".init") else _perfect(score)
        if not _name(section.get("name")) or _range(section) is None or not valid_score:
            return False
        positive_sections.append(section)
    if not positive_sections or len({s["name"] for s in positive_sections}) != len(positive_sections):
        return False
    if sum(positive_integer(s["size"]) for s in positive_sections) != sum(totals):
        return False
    if any(not isinstance(f, dict) or not _name(f.get("name")) or _range(f) is None
           or not _perfect(f.get("fuzzy_match_percent")) for f in functions):
        return False
    if sum(positive_integer(f["size"]) for f in functions) != totals[0]:
        return False
    if len({f["name"] for f in functions}) != len(functions):
        return False
    if any(nonnegative_integer(measures.get(key, 0)) != len(functions)
           for key in ("total_functions", "matched_functions")):
        return False
    if not _perfect(measures.get("matched_functions_percent")):
        return False
    if any(nonnegative_integer(measures.get(key)) != 1 for key in ("total_units", "complete_units")):
        return False
    return True


def find_unit_migrations(baseline: dict, report: dict) -> list[dict]:
    """Return read-only proof receipts for retired complete source owners.

    Every old allocation must have one current owner at every byte, and every
    old entry must have one exact current replacement. All report units take
    part in ambiguity checks, including incomplete and autogenerated units.
    This does not edit reports, infer source from names, or compare aggregates.
    """
    before = baseline.get("units", []) if isinstance(baseline, dict) else []
    after = report.get("units", []) if isinstance(report, dict) else []
    if not isinstance(before, list) or not isinstance(after, list):
        return []
    if any(not isinstance(u, dict) for u in before + after):
        return []
    # An allocation with an unknown module/address cannot safely be excluded
    # from alias checks. Fail closed for the complete reports, rather than
    # assuming malformed unrelated-looking records belong somewhere else.
    for unit in before + after:
        sections = unit.get("sections", [])
        functions = unit.get("functions", [])
        if not isinstance(sections, list) or not isinstance(functions, list):
            return []
        if (sections or functions) and (not _name(unit.get("name")) or _module(unit) is None):
            return []
        if any(not isinstance(f, dict) or not _name(f.get("name")) or _range(f) is None for f in functions):
            return []
        for section in sections:
            if not isinstance(section, dict):
                return []
            size = nonnegative_integer(section.get("size", 0))
            if size is None or (size and (not _name(section.get("name")) or _range(section) is None)):
                return []
    name_counts = [{}, {}]
    function_maps = [{}, {}]
    section_maps = [{}, {}]
    for side, units in enumerate((before, after)):
        for unit in units:
            name = unit.get("name")
            if _name(name):
                name_counts[side][name] = name_counts[side].get(name, 0) + 1
            module = _module(unit)
            if module is None:
                continue
            for function in unit.get("functions", []) if isinstance(unit.get("functions", []), list) else []:
                if not isinstance(function, dict):
                    continue
                metadata = function.get("metadata")
                address = positive_integer(metadata.get("virtual_address")) if isinstance(metadata, dict) else None
                if address is not None:
                    function_maps[side].setdefault((module, address), []).append((unit, function))
            for section in unit.get("sections", []) if isinstance(unit.get("sections", []), list) else []:
                if isinstance(section, dict) and _name(section.get("name")):
                    section_maps[side].setdefault((module, section["name"]), []).append((unit, section))

    receipts = []
    for old in before:
        name = old.get("name")
        if not _name(name) or name_counts[0].get(name) != 1 or name in name_counts[1] or not _complete_source(old, prior_owner=True):
            continue
        module = _module(old)
        section_receipts = []
        function_receipts = []
        valid = True
        for section in old["sections"]:
            old_range = _range(section)
            if old_range is None:  # Zero-sized sections do not own bytes.
                continue
            start, end = old_range
            spans = []
            original_owners = 0
            for owner, original in section_maps[0].get((module, section["name"]), []):
                original_range = _range(original)
                if original_range is not None and original_range[0] < end and start < original_range[1]:
                    original_owners += 1
            if original_owners != 1:
                valid = False
            for owner, current in section_maps[1].get((module, section["name"]), []):
                current_range = _range(current)
                if current_range is None:
                    metadata = current.get("metadata")
                    address = positive_integer(metadata.get("virtual_address")) if isinstance(metadata, dict) else None
                    if address is not None and start <= address < end:
                        valid = False
                    continue
                low, high = current_range
                if low < end and start < high:
                    if name_counts[1].get(owner.get("name")) != 1 or not _complete_source(owner):
                        valid = False
                    spans.append((max(low, start), min(high, end), owner["name"]))
            cursor = start
            owners = []
            for low, high, owner_name in sorted(spans):
                if low != cursor:  # Both gaps and overlapping aliases fail.
                    valid = False
                cursor = high
                owners.append(owner_name)
            if cursor != end:
                valid = False
            section_receipts.append({"name": section["name"], "address": start,
                                     "size": end - start, "owners": sorted(set(owners))})
        for function in old.get("functions", []):
            start, end = _range(function)
            key = (module, start)
            replacements = function_maps[1].get(key, [])
            if len(function_maps[0].get(key, [])) != 1 or len(replacements) != 1:
                valid = False
                continue
            owner, replacement = replacements[0]
            if (name_counts[1].get(owner.get("name")) != 1 or not _complete_source(owner)
                    or _range(replacement) != (start, end) or not _perfect(replacement.get("fuzzy_match_percent"))):
                valid = False
                continue
            # Objdiff currently omits binding. If either report supplies it,
            # require the same explicit value on the other side.
            if any(function.get(k) != replacement.get(k) for k in ("binding", "scope")):
                valid = False
            if any(function.get("metadata", {}).get(k) != replacement.get("metadata", {}).get(k)
                   for k in ("binding", "scope")):
                valid = False
            if not any(s["name"] == section["name"] and _range(s)[0] <= start and end <= _range(s)[1]
                       for s in owner["sections"] if _range(s) is not None
                       for section in old["sections"] if _range(section) is not None
                       and _range(section)[0] <= start and end <= _range(section)[1]):
                valid = False
            function_receipts.append({"from": function["name"], "to": replacement["name"],
                                      "address": start, "size": end - start, "unit": owner["name"]})
        if valid:
            receipts.append({"retired_unit": name, "module_name": module[0], "module_id": module[1],
                             "replacement_units": sorted({owner for s in section_receipts for owner in s["owners"]}),
                             "sections": section_receipts, "functions": function_receipts})
    return receipts


def _removed_unit_agrees(change: dict, old: dict) -> bool:
    """Do not suppress inconsistent or two-sided native change records."""
    if "to" in change or change.get("from") != old.get("measures") or _module(change) != _module(old):
        return False
    for key in ("sections", "functions"):
        changes = change.get(key, [])
        originals = old.get(key, [])
        if not isinstance(changes, list):
            return False
        if key == "sections":
            originals = [s for s in originals if positive_integer(s.get("size")) is not None]
            changes = [s for s in changes if isinstance(s, dict)
                       and isinstance(s.get("from"), dict)
                       and positive_integer(s["from"].get("size")) is not None]
        if len(changes) != len(originals):
            return False
        by_name = {record["name"]: record for record in originals}
        if len(by_name) != len(originals) or len({r.get("name") for r in changes if isinstance(r, dict)}) != len(changes):
            return False
        for record in changes:
            if not isinstance(record, dict) or "to" in record or record.get("name") not in by_name:
                return False
            original = by_name[record["name"]]
            measures = record.get("from")
            if not isinstance(measures, dict) or measures.get("fuzzy_match_percent") != original.get("fuzzy_match_percent"):
                return False
            if _range({**record, "size": measures.get("size")}) != _range(original):
                return False
    return True


def format_float(value: float) -> str:
    if value < 100.0 and value > 99.99:
        value = 99.99
    return "%6.2f" % value


def get_changes(changes_file: str, baseline_file: Optional[str] = None,
                report_file: Optional[str] = None) -> Tuple[list[Change], list[Change]]:
    changes_file = os.path.relpath(changes_file, root_dir)
    with open(changes_file, "r") as f:
        changes_json = json.load(f)

    migrations = set()
    if baseline_file is not None and report_file is not None:
        with open(baseline_file, "r") as f:
            baseline = json.load(f)
        with open(report_file, "r") as f:
            report = json.load(f)
        receipts = find_unit_migrations(baseline, report)
        old_units = {u["name"]: u for u in baseline["units"]} if receipts else {}
        changed_units = {}
        for unit in changes_json.get("units", []):
            changed_units.setdefault(unit.get("name"), []).append(unit)
        migrations = {r["retired_unit"] for r in receipts
                      if len(changed_units.get(r["retired_unit"], [])) == 1
                      and _removed_unit_agrees(changed_units[r["retired_unit"]][0], old_units[r["retired_unit"]])}

    regressions = []
    progressions = []

    def diff_key(object_name: Optional[str], object: dict, key: str):
        # Objdiff gives empty data sets 100% coverage. Removing a text-only
        # fallback split must not turn its zero data bytes into a regression.
        if key.endswith("data_percent") and not any(
            int(object.get(side, {}).get("total_data", 0))
            for side in ("from", "to")
        ):
            return
        from_value = object.get("from", {}).get(key, 0.0)
        to_value = object.get("to", {}).get(key, 0.0)
        key = key.removesuffix("_percent")
        change = (object_name, key, from_value, to_value)
        if from_value > to_value:
            regressions.append(change)
        elif to_value > from_value:
            progressions.append(change)

    for key in UNIT_KEYS_TO_DIFF:
        diff_key(None, changes_json, key)

    def diff_unit_key(object_name: str, unit: dict, key: str):
        # Objdiff's unit fuzzy score and code coverage describe code bytes.
        # A removed data-only fallback has no code score that can regress.
        empty_code = not unit.get("functions")
        for side in ("from", "to"):
            measures = unit.get(side, {})
            if not isinstance(measures, dict):
                empty_code = False
                continue
            for count_key in ("total_code", "matched_code", "complete_code"):
                count = measures.get(count_key, 0)
                valid_zero = (type(count) is int and count == 0) or (
                    isinstance(count, str) and count.isascii()
                    and count.isdecimal() and int(count) == 0
                )
                if not valid_zero:
                    empty_code = False
        if empty_code and key in (
            "fuzzy_match_percent", "matched_code_percent", "complete_code_percent"
        ):
            return
        diff_key(object_name, unit, key)

    for unit in changes_json.get("units", []):
        unit_name = unit["name"]
        if unit_name in migrations:
            continue
        for key in UNIT_KEYS_TO_DIFF:
            diff_unit_key(unit_name, unit, key)
        # Ignore sections
        for func in reconcile_function_names(unit.get("functions", [])):
            func_name = func["name"]
            for key in FUNCTION_KEYS_TO_DIFF:
                diff_key(func_name, func, key)

    return regressions, progressions


def generate_changes_plaintext(changes: list[Change]) -> str:
    if len(changes) == 0:
        return ""

    table_total_width = 136
    percents_max_len = 7 + 4 + 7
    key_max_len = max(len(key) for _, key, _, _ in changes)
    name_max_len = max(len(name or "Total") for name, _, _, _ in changes)
    max_width_for_name_col = table_total_width - 3 - key_max_len - 3 - percents_max_len
    name_max_len = min(max_width_for_name_col, name_max_len)

    out_lines = []
    for name, key, from_value, to_value in changes:
        if name is None:
            name = "Total"
        if len(name) > name_max_len:
            name = name[: name_max_len - len("[...]")] + "[...]"
        out_lines.append(
            f"{name:>{name_max_len}} | {key:<{key_max_len}} | {format_float(from_value)}% -> {format_float(to_value)}%"
        )

    return "\n".join(out_lines)


def generate_changes_markdown(changes: list[Change], description: str) -> str:
    if len(changes) == 0:
        return ""

    out_lines = []
    name_max_len = 100

    out_lines.append("<details>")
    out_lines.append(
        f"<summary>Detected {len(changes)} {description} compared to the base:</summary>"
    )
    out_lines.append("")  # Must include a blank line before a table
    out_lines.append("| Name | Type | Before | After |")
    out_lines.append("| ---- | ---- | ------ | ----- |")

    for name, key, from_value, to_value in changes:
        if name is None:
            name = "Total"
        else:
            if len(name) > name_max_len:
                name = name[: name_max_len - len("...")] + "..."
            name = f"`{name}`"  # Surround with backticks
        key = key.replace("_", " ").capitalize()
        out_lines.append(
            f"| {name} | {key} | {format_float(from_value)}% | {format_float(to_value)}% |"
        )

    out_lines.append("</details>")

    return "\n".join(out_lines)


def main():
    parser = ArgumentParser(description="Format objdiff-cli report changes.")
    parser.add_argument(
        "--baseline", type=Path,
        help="Read-only full baseline report for strict retired-source ownership reconciliation.",
    )
    parser.add_argument(
        "--report", type=Path,
        help="Read-only full current report; ownership reconciliation requires both reports.",
    )
    parser.add_argument(
        "report_changes_file",
        type=Path,
        help="""path to the JSON file containing the changes, generated by objdiff-cli.""",
    )
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        help="""Output file (prints to console if unspecified)""",
    )
    parser.add_argument(
        "--all",
        action="store_true",
        help="""Includes progressions as well.""",
    )
    args = parser.parse_args()

    if (args.baseline is None) != (args.report is None):
        parser.error("--baseline and --report must be supplied together")
    regressions, progressions = get_changes(args.report_changes_file, args.baseline, args.report)

    if args.output:
        markdown_output = generate_changes_markdown(regressions, "regressions")
        if args.all:
            markdown_output += generate_changes_markdown(progressions, "progressions")
        with open(args.output, "w", encoding="utf-8") as f:
            f.write(markdown_output)
    else:
        if args.all:
            changes = progressions + regressions
        else:
            changes = regressions
        text_output = generate_changes_plaintext(changes)
        print(text_output)


if __name__ == "__main__":
    main()
