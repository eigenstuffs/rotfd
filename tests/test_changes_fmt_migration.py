import copy
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

from tools.changes_fmt import find_unit_migrations, get_changes


class SourceOwnershipMigrationTests(unittest.TestCase):
    def record(self, name, address, size):
        return {"name": name, "size": str(size), "fuzzy_match_percent": 100.0,
                "metadata": {"virtual_address": str(address)}}

    def unit(self, name, start, sizes, data=False):
        size = sum(sizes)
        functions = []
        address = start
        for index, length in enumerate(sizes):
            functions.append(self.record(name + "_" + str(index), address, length))
            address += length
        sections = [self.record(".text", start, size)]
        if data:
            sections.append(self.record(".data", 0x9000, 4))
        return {
            "name": "main/" + name,
            "metadata": {"module_name": "main", "module_id": 0, "complete": True,
                         "auto_generated": False, "source_path": "src/" + name + ".cpp"},
            "measures": {
                "fuzzy_match_percent": 100.0,
                "total_code": str(size), "matched_code": str(size), "complete_code": str(size),
                "matched_code_percent": 100.0, "complete_code_percent": 100.0,
                "total_data": "4" if data else "0", "matched_data": "4" if data else "0",
                "complete_data": "4" if data else "0", "matched_data_percent": 100.0,
                "complete_data_percent": 100.0, "total_functions": len(functions),
                "matched_functions": len(functions), "matched_functions_percent": 100.0,
                "total_units": 1, "complete_units": 1,
            },
            "sections": sections, "functions": functions,
        }

    def setUp(self):
        self.before = {"units": [self.unit("old_a", 0x1000, [4, 4], data=True),
                                 self.unit("old_b", 0x1008, [8])]}
        self.after = {"units": [self.unit("native", 0x1000, [4, 4, 8], data=True)]}

    def removed(self, unit):
        change = {"name": unit["name"], "metadata": copy.deepcopy(unit["metadata"]),
                  "from": copy.deepcopy(unit["measures"])}
        for key in ("sections", "functions"):
            change[key] = [{"name": item["name"], "metadata": copy.deepcopy(item["metadata"]),
                            "from": {"size": item["size"], "fuzzy_match_percent": item["fuzzy_match_percent"]}}
                           for item in unit[key]]
        return change

    def changes(self, before=None, after=None, document=None, optional=True):
        before = self.before if before is None else before
        after = self.after if after is None else after
        document = {"units": [self.removed(unit) for unit in before["units"]]} if document is None else document
        with tempfile.TemporaryDirectory() as directory:
            paths = [Path(directory) / name for name in ("changes.json", "baseline.json", "report.json")]
            texts = [json.dumps(value) for value in (document, before, after)]
            for path, text in zip(paths, texts):
                path.write_text(text)
            result = get_changes(*map(str, paths)) if optional else get_changes(str(paths[0]))
            self.assertEqual([path.read_text() for path in paths], texts)
            return result

    def assert_retained(self, after=None, before=None, document=None, name="main/old_a"):
        regressions, _ = self.changes(before=before, after=after, document=document)
        self.assertTrue(any(owner == name and key == "matched_code" and old > new
                            for owner, key, old, new in regressions), regressions)

    def test_merge_receipt_and_input_preservation(self):
        original = copy.deepcopy((self.before, self.after))
        receipts = find_unit_migrations(self.before, self.after)
        self.assertEqual((self.before, self.after), original)
        self.assertEqual([item["retired_unit"] for item in receipts], ["main/old_a", "main/old_b"])
        self.assertEqual(receipts[0]["replacement_units"], ["main/native"])
        self.assertEqual(receipts[0]["sections"][0], {
            "name": ".text", "address": 0x1000, "size": 8, "owners": ["main/native"]})
        self.assertEqual(receipts[0]["functions"][0], {
            "from": "old_a_0", "to": "native_0", "address": 0x1000, "size": 4, "unit": "main/native"})
        self.assertEqual(self.changes(), ([], []))

    def test_default_behavior_is_unchanged_without_reports(self):
        self.assert_retained(document={"units": [self.removed(self.before["units"][0])]},
                             after={"units": []})
        regressions, _ = self.changes(optional=False)
        self.assertIn(("old_a_0", "fuzzy_match", 100.0, 0.0), regressions)

    def test_adjacent_multiple_owners_can_cover_one_retired_range(self):
        after = {"units": [self.unit("native_a", 0x1000, [4], data=True),
                            self.unit("native_b", 0x1004, [4]), self.unit("native_c", 0x1008, [8])]}
        self.assertEqual(self.changes(after=after), ([], []))
        self.assertEqual(find_unit_migrations(self.before, after)[0]["replacement_units"],
                         ["main/native_a", "main/native_b"])

    def test_missing_data_or_code_coverage_remains_visible(self):
        for section_name in (".data", ".text"):
            after = copy.deepcopy(self.after)
            after["units"][0]["sections"] = [s for s in after["units"][0]["sections"] if s["name"] != section_name]
            with self.subTest(section=section_name):
                self.assert_retained(after=after)

    def test_gap_and_overlapping_section_aliases_are_rejected(self):
        gap = {"units": [self.unit("first", 0x1000, [4], data=True),
                          self.unit("last", 0x1008, [8])]}
        self.assert_retained(after=gap)
        for complete in (True, False):
            after = copy.deepcopy(self.after)
            alias = self.unit("alias", 0x1002, [4])
            alias["metadata"]["complete"] = complete
            after["units"].append(alias)
            with self.subTest(alias_complete=complete):
                self.assert_retained(after=after)

    def test_function_aliases_in_either_report_are_rejected_even_with_bad_size(self):
        for side in ("before", "after"):
            for size in ("4", None):
                before, after = copy.deepcopy((self.before, self.after))
                alias = {"name": "main/alias", "metadata": {"module_name": "main", "module_id": 0},
                         "functions": [self.record("alias", 0x1000, 4)]}
                alias["functions"][0]["size"] = size
                (before if side == "before" else after)["units"].append(alias)
                document = {"units": [self.removed(self.before["units"][0])]}
                with self.subTest(side=side, size=size):
                    self.assert_retained(before=before, after=after, document=document)

    def test_changed_entry_address_size_or_section_is_rejected(self):
        for kind in ("address", "size", "section"):
            after = copy.deepcopy(self.after)
            unit = after["units"][0]
            if kind == "address":
                unit["functions"][0]["metadata"]["virtual_address"] = str(0x1001)
            elif kind == "size":
                unit["functions"][0]["size"] = "8"
            else:
                unit["sections"][0]["name"] = ".init"
            with self.subTest(kind=kind):
                self.assert_retained(after=after)

    def test_partial_nonmatching_or_non_source_owners_are_rejected(self):
        for key, value in (("complete", False), ("complete", 1), ("auto_generated", True),
                           ("source_path", "src/original.s"), ("source_path", None)):
            after = copy.deepcopy(self.after)
            after["units"][0]["metadata"][key] = value
            with self.subTest(key=key, value=value):
                self.assert_retained(after=after)
        for side in ("before", "after"):
            for key in ("fuzzy_match_percent", "matched_code_percent", "complete_code_percent",
                        "matched_data_percent", "complete_data_percent"):
                if side == "before" and key == "matched_data_percent":
                    continue
                before, after = copy.deepcopy((self.before, self.after))
                (before if side == "before" else after)["units"][0]["measures"][key] = 99.99
                with self.subTest(side=side, key=key):
                    self.assert_retained(before=before, after=after)
        after = copy.deepcopy(self.after)
        after["units"][0]["functions"][0]["fuzzy_match_percent"] = 99.99
        self.assert_retained(after=after)

    def test_missing_or_malformed_identity_is_rejected(self):
        invalid = [None, True, 0, -1, 4.0, "", "0", "-4", "+4", " 4", "4.0", "0x4", "４", [], {}]
        for key in ("virtual_address", "size"):
            for value in invalid:
                after = copy.deepcopy(self.after)
                record = after["units"][0]["functions"][0]
                (record["metadata"] if key == "virtual_address" else record)[key] = value
                with self.subTest(key=key, value=value):
                    self.assert_retained(after=after)
        for key in ("virtual_address", "size"):
            after = copy.deepcopy(self.after)
            record = after["units"][0]["sections"][0]
            del (record["metadata"] if key == "virtual_address" else record)[key]
            self.assert_retained(after=after)

    def test_module_identity_and_optional_binding_must_agree(self):
        for key, value in (("module_name", "other"), ("module_name", None),
                           ("module_id", 1), ("module_id", True), ("module_id", None)):
            after = copy.deepcopy(self.after)
            after["units"][0]["metadata"][key] = value
            with self.subTest(key=key, value=value):
                self.assert_retained(after=after)
        for location in (None, "metadata"):
            before, after = copy.deepcopy((self.before, self.after))
            old = before["units"][0]["functions"][0]
            current = after["units"][0]["functions"][0]
            (old if location is None else old[location])["binding"] = "global"
            (current if location is None else current[location])["binding"] = "weak"
            self.assert_retained(before=before, after=after)

    def test_duplicate_unit_names_are_rejected(self):
        for side in ("before", "after"):
            before, after = copy.deepcopy((self.before, self.after))
            units = (before if side == "before" else after)["units"]
            units.append(copy.deepcopy(units[0]))
            document = {"units": [self.removed(self.before["units"][0])]}
            with self.subTest(side=side):
                self.assert_retained(before=before, after=after, document=document)

    def test_baseline_section_aliases_and_inconsistent_totals_are_rejected(self):
        before = copy.deepcopy(self.before)
        before["units"].append({"name": "main/alias", "metadata": {"module_name": "main", "module_id": 0},
                                "sections": [self.record(".data", 0x9000, 4)]})
        self.assert_retained(before=before, document={"units": [self.removed(self.before["units"][0])]})
        for key in ("total_code", "matched_code", "complete_code", "total_data", "matched_data", "complete_data",
                    "total_functions", "matched_functions", "complete_units"):
            after = copy.deepcopy(self.after)
            after["units"][0]["measures"][key] = "0"
            with self.subTest(key=key):
                self.assert_retained(after=after)

    def test_complete_prior_owner_with_partial_data_comparison_can_migrate(self):
        before = copy.deepcopy(self.before)
        unit = before["units"][0]
        unit["measures"]["matched_data"] = "0"
        unit["measures"]["matched_data_percent"] = 0.0
        unit["sections"][1]["fuzzy_match_percent"] = 52.38
        self.assertEqual(self.changes(before=before), ([], []))
        self.assertEqual(len(find_unit_migrations(before, self.after)), 2)
        # Protobuf JSON omits zero scalar values in real native reports.
        del unit["measures"]["matched_data"]
        del unit["measures"]["matched_data_percent"]
        self.assertEqual(self.changes(before=before), ([], []))
        # Partial comparison is allowed only on the prior data side.
        after = copy.deepcopy(self.after)
        after["units"][0]["sections"][1]["fuzzy_match_percent"] = 52.38
        self.assert_retained(before=before, after=after)
        unit["sections"][0]["fuzzy_match_percent"] = 99.99
        self.assert_retained(before=before)

    def test_malformed_prior_data_scores_and_counts_remain_visible(self):
        for field, values in (
            ("matched_data_percent", [None, True, "100", -1, 100.01, float("nan"), float("inf")]),
            ("matched_data", [None, True, -1, "-1", "5", 4.0, "4.0", []]),
        ):
            for value in values:
                before = copy.deepcopy(self.before)
                before["units"][0]["measures"][field] = value
                with self.subTest(field=field, value=value):
                    self.assert_retained(before=before, document={"units": [self.removed(self.before["units"][0])]})
        for value in (None, True, "100", -1, 100.01, float("nan"), float("inf")):
            before = copy.deepcopy(self.before)
            before["units"][0]["sections"][1]["fuzzy_match_percent"] = value
            with self.subTest(section_score=value):
                self.assert_retained(before=before)

    def test_zero_sized_sections_are_ignored_and_malformed_reports_fail_closed(self):
        before = copy.deepcopy(self.before)
        before["units"][0]["sections"].append({"size": "0"})
        document = {"units": [self.removed(self.before["units"][0])]}
        self.assertEqual(self.changes(before=before, document=document), ([], []))
        for invalid in (None, [], {}, {"units": None}, {"units": [None]}):
            self.assertEqual(find_unit_migrations(invalid, self.after), [])
            self.assertEqual(find_unit_migrations(self.before, invalid), [])

    def test_unknown_module_or_allocation_identity_on_aliases_fails_closed(self):
        for side in ("before", "after"):
            for kind in ("functions", "sections"):
                for field in ("module_name", "module_id", "virtual_address", "size"):
                    before, after = copy.deepcopy((self.before, self.after))
                    alias = {"name": "main/unknown", "metadata": {"module_name": "main", "module_id": 0},
                             kind: [self.record(".text" if kind == "sections" else "alias", 0x1000, 4)]}
                    if field in ("module_name", "module_id"):
                        del alias["metadata"][field]
                    elif field == "virtual_address":
                        del alias[kind][0]["metadata"][field]
                    else:
                        alias[kind][0]["size"] = None
                    (before if side == "before" else after)["units"].append(alias)
                    document = {"units": [self.removed(self.before["units"][0])]}
                    with self.subTest(side=side, kind=kind, field=field):
                        self.assert_retained(before=before, after=after, document=document)

    def test_numerical_changes_in_retained_units_and_aggregates_are_never_hidden(self):
        after = copy.deepcopy(self.after)
        after["units"].append(copy.deepcopy(self.before["units"][0]))
        self.assert_retained(after=after)
        document = {"from": {"matched_code_percent": 90.0}, "to": {"matched_code_percent": 89.0},
                    "units": [self.removed(unit) for unit in self.before["units"]]}
        self.assertEqual(self.changes(document=document), ([(None, "matched_code", 90.0, 89.0)], []))

    def test_inconsistent_duplicate_or_two_sided_change_rows_are_retained(self):
        for kind in ("score", "to", "duplicate", "function"):
            document = {"units": [self.removed(self.before["units"][0])]}
            unit = document["units"][0]
            if kind == "score":
                unit["from"]["matched_code_percent"] = 99.0
            elif kind == "to":
                unit["to"] = {"matched_code_percent": 50.0}
            elif kind == "duplicate":
                document["units"].append(copy.deepcopy(unit))
            else:
                unit["functions"][0]["from"]["fuzzy_match_percent"] = 90.0
            with self.subTest(kind=kind):
                regressions, _ = self.changes(document=document)
                self.assertTrue(any(name == "main/old_a" and key == "matched_code" for name, key, _, _ in regressions))

    def test_cli_requires_both_reports_and_supports_optional_reconciliation(self):
        with tempfile.TemporaryDirectory() as directory:
            paths = [Path(directory) / name for name in ("changes.json", "baseline.json", "report.json")]
            for path, value in zip(paths, ({"units": [self.removed(u) for u in self.before["units"]]}, self.before, self.after)):
                path.write_text(json.dumps(value))
            command = [sys.executable, "tools/changes_fmt.py", str(paths[0])]
            default = subprocess.run(command, capture_output=True, text=True, check=True)
            self.assertIn("old_a", default.stdout)
            optional = subprocess.run(command + ["--baseline", str(paths[1]), "--report", str(paths[2])],
                                      capture_output=True, text=True, check=True)
            self.assertEqual(optional.stdout.strip(), "")
            missing = subprocess.run(command + ["--baseline", str(paths[1])], capture_output=True, text=True)
            self.assertNotEqual(missing.returncode, 0)
            self.assertIn("must be supplied together", missing.stderr)


if __name__ == "__main__":
    unittest.main()
