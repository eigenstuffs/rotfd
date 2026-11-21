import json
import tempfile
import unittest
from pathlib import Path

from tools.changes_fmt import get_changes


class EmptyCodeFormattingTests(unittest.TestCase):
    def changes(self, unit):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "changes.json"
            text = json.dumps({"units": [unit]})
            path.write_text(text)
            result = get_changes(str(path))
            self.assertEqual(path.read_text(), text)
            return result

    def scores(self):
        return {
            "fuzzy_match_percent": 100.0,
            "matched_code_percent": 100.0,
            "complete_code_percent": 100.0,
        }

    def test_removed_data_only_unit_has_no_empty_code_regression(self):
        for count in (None, 0, "0"):
            with self.subTest(count=count):
                before = {**self.scores(), "total_data": "43640"}
                if count is not None:
                    before["total_code"] = count
                self.assertEqual(self.changes({"name": "original-data", "from": before}), ([], []))
        # The three meaningless code percentages do not hide genuine data loss.
        regressions, progressions = self.changes({
            "name": "matched-data",
            "from": {**self.scores(), "total_data": "8", "matched_data_percent": 100.0,
                     "complete_data_percent": 100.0},
        })
        self.assertEqual({key for _, key, _, _ in regressions}, {"matched_data", "complete_data"})
        self.assertEqual(progressions, [])

    def test_both_sides_must_have_zero_code_and_data_scores_remain_visible(self):
        unit = {
            "name": "data",
            "from": {**self.scores(), "total_code": "0", "total_data": "8", "matched_data_percent": 100.0},
            "to": {"total_code": 0, "total_data": "8", "matched_data_percent": 50.0},
        }
        self.assertEqual(self.changes(unit), ([("data", "matched_data", 100.0, 50.0)], []))
        for side in ("from", "to"):
            for count_key in ("total_code", "matched_code", "complete_code"):
                with self.subTest(side=side, count_key=count_key):
                    changed = json.loads(json.dumps(unit))
                    changed[side][count_key] = "4"
                    regressions, _ = self.changes(changed)
                    self.assertEqual({key for _, key, _, _ in regressions},
                                     {"fuzzy_match", "matched_code", "complete_code", "matched_data"})

    def test_individual_function_fuzzy_decline_is_always_reported(self):
        for count in (None, 0, "0"):
            with self.subTest(unit_count=count):
                unit = {"name": "code", "functions": [{
                    "name": "function", "from": {"size": "4", "fuzzy_match_percent": 100.0},
                    "to": {"size": "4", "fuzzy_match_percent": 75.0},
                }]}
                if count is not None:
                    unit["from"] = {"total_code": count}
                    unit["to"] = {"total_code": count}
                self.assertEqual(self.changes(unit), ([("function", "fuzzy_match", 100.0, 75.0)], []))

    def test_malformed_code_counts_never_establish_empty_code(self):
        invalid = [None, True, False, -1, 0.0, "", "-0", "+0", " 0", "0 ", "0.0", "0x0", "０", [], {}]
        for side in ("from", "to"):
            for value in invalid:
                with self.subTest(side=side, value=value):
                    unit = {"name": "malformed", "from": self.scores(), "to": {}}
                    unit[side]["total_code"] = value
                    regressions, _ = self.changes(unit)
                    self.assertEqual({key for _, key, _, _ in regressions},
                                     {"fuzzy_match", "matched_code", "complete_code"})


if __name__ == "__main__":
    unittest.main()
