import json
import tempfile
import unittest
from pathlib import Path

from tools.changes_fmt import get_changes


class ChangesFormattingTests(unittest.TestCase):
    def changes(self, unit):
        with tempfile.TemporaryDirectory() as directory:
            report = Path(directory) / "changes.json"
            report.write_text(json.dumps({"units": [unit]}))
            return get_changes(str(report))

    def test_removed_text_only_split_has_no_data_regression(self):
        regressions, progressions = self.changes({
            "name": "main/auto_text",
            "from": {
                "total_code": "4",
                "matched_data_percent": 100.0,
                "complete_data_percent": 100.0,
            },
        })
        self.assertEqual((regressions, progressions), ([], []))

    def test_removed_source_still_reports_code_and_data_loss(self):
        regressions, _ = self.changes({
            "name": "main/source",
            "from": {
                "total_code": "4",
                "total_data": "8",
                "matched_code_percent": 100.0,
                "matched_data_percent": 100.0,
                "complete_data_percent": 100.0,
            },
        })
        self.assertEqual(
            {key for _, key, _, _ in regressions},
            {"matched_code", "matched_data", "complete_data"},
        )

    def test_nonempty_data_change_remains_visible(self):
        regressions, progressions = self.changes({
            "name": "main/data",
            "from": {"total_data": "8", "matched_data_percent": 100.0},
            "to": {"total_data": "8", "matched_data_percent": 50.0},
        })
        self.assertEqual(regressions, [("main/data", "matched_data", 100.0, 50.0)])
        self.assertEqual(progressions, [])


if __name__ == "__main__":
    unittest.main()
