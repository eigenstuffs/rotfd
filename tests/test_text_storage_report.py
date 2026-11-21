"""Reporting metadata must never replace or change the actual link input."""

from pathlib import Path
import tempfile
import unittest

from test_text_storage import fixture
from tools.normalize_text_storage import normalize
from tools.normalize_text_storage_v2 import write_report_copy


class TextStorageReportTests(unittest.TestCase):
    def test_report_copy_preserves_raw_link_object(self):
        data, contract, _, _ = fixture()
        with tempfile.TemporaryDirectory() as directory:
            original = Path(directory) / "raw.o"
            target = Path(directory) / "report/storage.o"
            original.write_bytes(data)
            result = write_report_copy(original, target, contract)
            self.assertEqual(original.read_bytes(), data)
            self.assertEqual(target.read_bytes(), normalize(data, contract))
            self.assertEqual(write_report_copy(original, target, contract), result)
            self.assertEqual(original.read_bytes(), data)

    def test_rejects_normalized_or_changed_link_input(self):
        data, contract, _, _ = fixture()
        for invalid in (normalize(data, contract), data + b"changed"):
            with self.subTest(invalid=invalid[-8:]), tempfile.TemporaryDirectory() as directory:
                original = Path(directory) / "raw.o"
                target = Path(directory) / "storage.o"
                original.write_bytes(invalid)
                target.write_bytes(b"keep")
                with self.assertRaisesRegex(ValueError, "exact generated"):
                    write_report_copy(original, target, contract)
                self.assertEqual(original.read_bytes(), invalid)
                self.assertEqual(target.read_bytes(), b"keep")


if __name__ == "__main__":
    unittest.main()
