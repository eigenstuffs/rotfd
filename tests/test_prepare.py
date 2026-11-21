import hashlib
from pathlib import Path
import tempfile
import unittest

from tools.prepare import prepare


class PrepareTests(unittest.TestCase):
    def test_bad_hash_cannot_replace_reference(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "input.dol"
            dest = Path(directory) / "reference.dol"
            source.write_bytes(b"wrong")
            dest.write_bytes(b"keep")
            with self.assertRaisesRegex(ValueError, "SHA-1 mismatch"):
                prepare(source, dest, hashlib.sha1(b"expected").hexdigest())
            self.assertEqual(dest.read_bytes(), b"keep")

    def test_valid_source_cannot_replace_other_reference(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "input.dol"
            dest = Path(directory) / "reference.dol"
            source.write_bytes(b"expected")
            dest.write_bytes(b"keep")
            with self.assertRaisesRegex(ValueError, "Refusing to replace"):
                prepare(source, dest, hashlib.sha1(b"expected").hexdigest())
            self.assertEqual(dest.read_bytes(), b"keep")


if __name__ == "__main__":
    unittest.main()
