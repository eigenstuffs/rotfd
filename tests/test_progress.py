"""Progress accounting must never turn assembly coverage into source matches."""

import copy
import unittest

from tools.progress import make_snapshot


def fixture():
    return {
        "version": 2,
        "measures": {"total_code": "12", "matched_code": "4", "complete_code": "4", "fuzzy_match_percent": 100 / 3,
                     "total_functions": 2, "matched_functions": 1, "total_units": 2, "complete_units": 1},
        "units": [
            {"name": "main/runtime", "metadata": {"complete": True, "source_path": "src/runtime.c", "progress_categories": ["sdk"]},
             "measures": {"total_code": "4", "matched_code": "4", "complete_code": "4", "fuzzy_match_percent": 100, "total_functions": 1, "matched_functions": 1, "total_units": 1, "complete_units": 1},
             "functions": [{"name": "known", "size": "4", "fuzzy_match_percent": 100, "metadata": {"virtual_address": "2147487744"}}]},
            {"name": "main/auto", "metadata": {"auto_generated": True},
             "measures": {"total_code": "8", "total_functions": 1, "total_units": 1},
             "functions": [{"name": "fn_unknown", "size": "8", "metadata": {"virtual_address": "2147487748"}}]},
        ], "categories": [{"id": "sdk", "name": "Identified SDK / Runtime"}],
    }


def partial_fixture():
    report = fixture()
    work = report["units"][1]
    work["name"] = "main/work"
    work["metadata"] = {"complete": False, "source_path": "src/work.c", "progress_categories": ["sdk"]}
    work["measures"].update({"matched_code": "4", "total_functions": 2,
                             "matched_functions": 1, "fuzzy_match_percent": 75})
    work["functions"] = [
        {"name": "matched_in_partial_unit", "size": "4", "fuzzy_match_percent": 100,
         "metadata": {"virtual_address": "2147487748"}},
        {"name": "unfinished", "size": "4", "fuzzy_match_percent": 50,
         "metadata": {"virtual_address": "2147487752"}},
    ]
    report["measures"].update({"matched_code": "8", "total_functions": 3,
                                "matched_functions": 2, "fuzzy_match_percent": 250 / 3})
    return report


class ProgressTests(unittest.TestCase):
    def test_unclassified_assembly_keeps_denominator(self):
        summary, functions = make_snapshot(fixture(), "GSQE78", "hash", "hash")
        self.assertEqual(summary["measures"]["total_code"], 12)
        self.assertAlmostEqual(summary["measures"]["matched_code_percent"], 100 / 3)
        unknown = next(c for c in summary["categories"] if c["id"] == "unclassified")
        self.assertEqual(unknown["measures"]["matched_code"], 0)
        self.assertEqual(unknown["measures"]["total_code"], 8)
        self.assertEqual([f["unit_status"] for f in functions], ["linked", "assembly"])

    def test_fuzzy_score_does_not_make_unit_complete(self):
        report = fixture()
        report["units"][1]["metadata"]["source_path"] = "src/work.c"
        report["units"][1]["functions"][0]["fuzzy_match_percent"] = 100
        summary, functions = make_snapshot(report, "GSQE78", "hash", "hash")
        self.assertEqual(functions[1]["unit_status"], "nonmatching")
        self.assertEqual(summary["measures"]["complete_units"], 1)

    def test_partial_unit_counts_matches_without_claiming_linked_source(self):
        summary, functions = make_snapshot(partial_fixture(), "GSQE78", "hash", "hash")
        self.assertEqual(summary["measures"]["matched_functions"], 2)
        self.assertEqual(summary["measures"]["matched_code"], 8)
        self.assertEqual(summary["measures"]["complete_code"], 4)
        self.assertEqual(summary["measures"]["complete_units"], 1)
        self.assertEqual(functions[1]["objdiff_fuzzy_percent"], 100)
        self.assertEqual(functions[1]["unit_status"], "nonmatching")
        work = next(u for u in summary["source_units"] if u["source"] == "src/work.c")
        self.assertEqual(work["status"], "nonmatching")
        self.assertEqual(work["measures"]["matched_functions"], 1)

    def test_category_fuzzy_weights_code_and_keeps_data_separate(self):
        report = partial_fixture()
        report["measures"].update({"total_data": "1000", "total_units": 3})
        report["units"].append({
            "name": "main/auto_data", "metadata": {"progress_categories": ["sdk"]},
            "measures": {"total_data": "1000", "total_units": 1, "fuzzy_match_percent": 100},
        })
        summary, _ = make_snapshot(report, "GSQE78", "hash", "hash")
        sdk = next(c["measures"] for c in summary["categories"] if c["id"] == "sdk")
        # One 4-byte unit at 100% and one 8-byte unit at 75%; data has no code weight.
        self.assertAlmostEqual(sdk["fuzzy_match_percent"], 250 / 3)
        self.assertAlmostEqual(sdk["matched_code_percent"], 200 / 3)
        self.assertEqual(sdk["total_data"], 1000)
        self.assertEqual(sdk["matched_data"], 0)

    def test_rejects_bad_binary(self):
        with self.assertRaisesRegex(ValueError, "Built DOL"):
            make_snapshot(fixture(), "GSQE78", "original", "different")

    def test_rejects_inconsistent_aggregate(self):
        report = copy.deepcopy(fixture())
        report["measures"]["total_code"] = "100"
        with self.assertRaisesRegex(ValueError, "Unit totals disagree"):
            make_snapshot(report, "GSQE78", "hash", "hash")


if __name__ == "__main__":
    unittest.main()
