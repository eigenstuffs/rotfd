import copy
import json
import tempfile
import unittest
from pathlib import Path

from tools.changes_fmt import get_changes, reconcile_function_names


class FunctionIdentityFormattingTests(unittest.TestCase):
    def function(self, name, side, score=100.0, address="2149531164", size="236"):
        return {
            "name": name,
            side: {"fuzzy_match_percent": score, "size": size},
            "metadata": {"virtual_address": address},
        }

    def changes(self, functions=None, units=None):
        if units is None:
            units = [{"name": "main/Game/file_lifecycle", "functions": functions}]
        with tempfile.TemporaryDirectory() as directory:
            report = Path(directory) / "changes.json"
            raw = json.dumps({"units": units})
            report.write_text(raw)
            result = get_changes(str(report))
            self.assertEqual(report.read_text(), raw)
            return result

    def assert_unpaired(self, records):
        regressions, progressions = self.changes(records)
        self.assertIn(("old", "fuzzy_match", 100.0, 0.0), regressions)
        self.assertIn(("native", "fuzzy_match", 0.0, 100.0), progressions)

    def test_equal_rename_preserves_input_and_new_identity(self):
        records = [
            self.function("old", "from"),
            self.function("native", "to", address=2149531164, size=236),
        ]
        records[1]["metadata"]["demangled_name"] = "File::~File()"
        original = copy.deepcopy(records)
        merged = reconcile_function_names(records)
        self.assertEqual(records, original)
        self.assertEqual(merged, [{**original[1], "from": original[0]["from"]}])
        self.assertEqual(self.changes(records), ([], []))
        with self.subTest(same_name_split_is_not_a_rename=True):
            records[1]["name"] = "old"
            self.assertEqual(self.changes(records), (
                [("old", "fuzzy_match", 100.0, 0.0)],
                [("old", "fuzzy_match", 0.0, 100.0)],
            ))

    def test_renamed_decline_remains_a_real_regression(self):
        records = [self.function("old", "from"), self.function("native", "to", 90.0)]
        self.assertEqual(
            self.changes(records),
            ([("native", "fuzzy_match", 100.0, 90.0)], []),
        )

    def test_renamed_progression_uses_both_measured_scores(self):
        records = [self.function("old", "from", 50.0), self.function("native", "to", 75.0)]
        self.assertEqual(
            self.changes(records),
            ([], [("native", "fuzzy_match", 50.0, 75.0)]),
        )

    def test_moved_address_is_not_reconciled(self):
        self.assert_unpaired([
            self.function("old", "from"),
            self.function("native", "to", address="2149531168"),
        ])

    def test_changed_extent_is_not_reconciled(self):
        self.assert_unpaired([
            self.function("old", "from"),
            self.function("native", "to", size="240"),
        ])

    def test_missing_or_malformed_identity_is_not_reconciled(self):
        invalid = [None, True, False, 0, -1, 236.0, "", "0", "-1", "+236",
                   " 236", "236 ", "236.0", "0xEC", "2e2", "２３６", [], {}]
        for field in ("virtual_address", "size"):
            for side in ("from", "to"):
                for value in invalid:
                    with self.subTest(field=field, side=side, value=value):
                        records = [self.function("old", "from"), self.function("native", "to")]
                        record = records[0 if side == "from" else 1]
                        target = record["metadata"] if field == "virtual_address" else record[side]
                        target[field] = value
                        self.assert_unpaired(records)
                with self.subTest(field=field, side=side, value="missing"):
                    records = [self.function("old", "from"), self.function("native", "to")]
                    record = records[0 if side == "from" else 1]
                    target = record["metadata"] if field == "virtual_address" else record[side]
                    del target[field]
                    self.assert_unpaired(records)
        for metadata in (None, [], {}, "invalid"):
            with self.subTest(metadata=metadata):
                records = [self.function("old", "from"), self.function("native", "to")]
                records[1]["metadata"] = metadata
                self.assert_unpaired(records)

    def test_duplicate_removed_address_blocks_even_with_malformed_size(self):
        for size in ("236", "240", None):
            with self.subTest(size=size):
                self.assert_unpaired([
                    self.function("old", "from"),
                    self.function("removed_alias", "from", size=size),
                    self.function("native", "to"),
                ])

    def test_duplicate_added_and_two_sided_addresses_are_ambiguous(self):
        extras = [self.function("added_alias", "to", size=None)]
        two_sided = self.function("existing", "from")
        two_sided["to"] = {"fuzzy_match_percent": 100.0, "size": "236"}
        extras.append(two_sided)
        for extra in extras:
            with self.subTest(extra=extra):
                self.assert_unpaired([
                    self.function("old", "from"),
                    self.function("native", "to"),
                    extra,
                ])
        # A two-sided record at a different address is not ambiguous.
        two_sided["metadata"]["virtual_address"] = "2149531400"
        self.assertEqual(self.changes([
            self.function("old", "from"), self.function("native", "to"), two_sided,
        ]), ([], []))

    def test_records_in_different_units_are_never_reconciled(self):
        regressions, progressions = self.changes(units=[
            {"name": "main/old_owner", "functions": [self.function("old", "from")]},
            {"name": "main/new_owner", "functions": [self.function("native", "to")]},
        ])
        self.assertEqual(regressions, [("old", "fuzzy_match", 100.0, 0.0)])
        self.assertEqual(progressions, [("native", "fuzzy_match", 0.0, 100.0)])


if __name__ == "__main__":
    unittest.main()
