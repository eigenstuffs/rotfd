"""Real ELF extent fixtures for source-data ownership, not fuzzy match scores."""

import copy
from pathlib import Path
import struct
import tempfile
import unittest

from tools.audit_source_extents import (
    allocated_sections, assert_source_extents, audit_source_extents,
)


def elf32(path, sections):
    """Write a minimal PPC ELF32 with (name, size, flags, type) sections."""
    strings = bytearray(b"\0.shstrtab\0")
    name_offsets = []
    for name, _, _, _ in sections:
        name_offsets.append(len(strings))
        strings.extend(name.encode() + b"\0")
    blob = bytearray(52)
    blob[:16] = b"\x7fELF\x01\x02\x01" + bytes(9)
    strings_offset = len(blob)
    blob.extend(strings)
    headers = [(0,) * 10, (1, 3, 0, 0, strings_offset, len(strings), 0, 0, 1, 0)]
    for (name, size, flags, kind), name_offset in zip(sections, name_offsets):
        offset = len(blob)
        if kind != 8:
            blob.extend(bytes(size))
        headers.append((name_offset, kind, flags, 0, offset, size, 0, 0, 8, 0))
    shoff = len(blob)
    for header in headers:
        blob.extend(struct.pack(">10I", *header))
    struct.pack_into(">HHIIIIIHHHHHH", blob, 16, 1, 20, 1, 0, 0, shoff, 0,
                     52, 0, 0, 40, len(headers), 1)
    path.write_bytes(blob)


class SourceExtentTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.config = {"units": [{
            "name": "main/unit", "base_path": "source.o", "target_path": "original.o",
            "metadata": {"complete": True, "source_path": "src/unit.c"},
        }]}
        self.report = {"units": [{
            "name": "main/unit",
            "metadata": {"complete": True, "source_path": "src/unit.c"},
            "sections": [],
        }]}

    def objects(self, source, target):
        elf32(self.root / "source.o", source)
        elf32(self.root / "original.o", target)
        self.report["units"][0]["sections"] = [
            {"name": name, "size": str(size),
             "metadata": {"virtual_address": str(0x80000000 + index * 0x1000)}}
            for index, (name, size, flags, _) in enumerate(target) if flags & 2
        ]

    def audit(self):
        return audit_source_extents(self.config, self.report, self.root)

    def test_rejects_initialized_padding_despite_perfect_objdiff_score(self):
        self.objects([(".sdata", 4, 3, 1)], [(".sdata", 8, 3, 1)])
        self.report["units"][0]["sections"][0]["fuzzy_match_percent"] = 100
        result = self.audit()
        self.assertFalse(result["passed"])
        self.assertEqual(result["bytes_beyond_source"], 4)

    def test_rejects_bss_padding_without_reading_a_file_payload(self):
        self.objects([(".sbss", 1, 3, 8)], [(".sbss", 8, 3, 8)])
        result = self.audit()
        self.assertEqual(result["bytes_beyond_source"], 7)
        self.assertTrue(result["findings"][0]["includes_bss"])

    def test_internal_alignment_and_unallocated_metadata_do_not_fail(self):
        self.objects([(".data", 12, 3, 1), (".debug", 3, 0, 1)],
                     [(".data", 12, 3, 1), (".debug", 900, 0, 1)])
        self.assertTrue(self.audit()["passed"])
        self.assertEqual(self.audit()["checked_data_sections"], 1)

    def test_unused_weak_metadata_and_text_alignment_do_not_fail(self):
        self.objects([(".text", 80, 6, 1), ("extab", 24, 2, 1)],
                     [(".text", 84, 6, 1), ("extab", 16, 2, 1)])
        result = self.audit()
        self.assertTrue(result["passed"])
        self.assertEqual(len(result["compiler_excess_sections"]), 1)

    def test_multiple_pieces_are_aggregated_without_tail_address_inference(self):
        self.objects([(".data", 4, 3, 1), (".data", 8, 3, 1)],
                     [(".data", 8, 3, 1), (".data", 8, 3, 1)])
        result = self.audit()
        self.assertEqual(result["bytes_beyond_source"], 4)
        self.assertEqual(len(result["aggregated_sections"]), 1)
        self.assertNotIn("tail_start", result["findings"][0])

    def test_overlapping_report_pieces_are_rejected(self):
        self.objects([(".data", 16, 3, 1)],
                     [(".data", 8, 3, 1), (".data", 8, 3, 1)])
        pieces = self.report["units"][0]["sections"]
        pieces[1]["metadata"] = copy.deepcopy(pieces[0]["metadata"])
        with self.assertRaisesRegex(ValueError, "overlapping report pieces"):
            self.audit()

    def test_missing_emitted_data_is_not_silently_skipped(self):
        self.objects([(".text", 4, 6, 1)], [(".data", 8, 3, 1)])
        self.assertEqual(self.audit()["bytes_beyond_source"], 8)

    def test_incomplete_and_fallback_units_are_not_source_claims(self):
        self.objects([(".data", 4, 3, 1)], [(".data", 8, 3, 1)])
        self.config["units"][0]["metadata"]["complete"] = False
        self.report["units"][0]["metadata"]["complete"] = False
        self.assertEqual(self.audit()["checked_source_units"], 0)
        self.config["units"][0]["metadata"]["complete"] = True
        self.report["units"][0]["metadata"]["complete"] = True
        del self.config["units"][0]["metadata"]["source_path"]
        del self.report["units"][0]["metadata"]["source_path"]
        del self.config["units"][0]["base_path"]
        self.assertEqual(self.audit()["checked_source_units"], 0)

    def test_report_source_claim_requires_complete_config_and_object(self):
        self.objects([(".data", 4, 3, 1)], [(".data", 4, 3, 1)])
        original = copy.deepcopy(self.config)
        for mutation in ("missing", "incomplete", "no_base", "different_source"):
            with self.subTest(mutation=mutation):
                self.config = copy.deepcopy(original)
                if mutation == "missing":
                    self.config["units"] = []
                elif mutation == "incomplete":
                    self.config["units"][0]["metadata"]["complete"] = False
                elif mutation == "no_base":
                    del self.config["units"][0]["base_path"]
                else:
                    self.config["units"][0]["metadata"]["source_path"] = "src/other.c"
                with self.assertRaisesRegex(ValueError, "report claims complete source src/unit.c"):
                    self.audit()

    def test_config_source_claim_requires_object_even_without_report_claim(self):
        self.objects([(".data", 4, 3, 1)], [(".data", 4, 3, 1)])
        del self.config["units"][0]["base_path"]
        self.report["units"][0]["metadata"]["complete"] = False
        with self.assertRaisesRegex(ValueError, "configured complete source src/unit.c has no base_path"):
            self.audit()

    def test_config_source_claim_cannot_match_incomplete_or_fallback_report(self):
        self.objects([(".data", 4, 3, 1)], [(".data", 4, 3, 1)])
        self.report["units"][0]["metadata"]["complete"] = False
        with self.assertRaisesRegex(ValueError, "missing from the refreshed report"):
            self.audit()
        self.report["units"][0]["metadata"]["complete"] = True
        del self.report["units"][0]["metadata"]["source_path"]
        with self.assertRaisesRegex(ValueError, "source ownership differs"):
            self.audit()

    def test_assertion_reports_source_section_and_exact_extent_difference(self):
        self.objects([(".sbss", 1, 3, 8)], [(".sbss", 8, 3, 8)])
        with self.assertRaisesRegex(
                ValueError, r"src/unit.c \.sbss: 8 owned bytes, 1 emitted \(7 beyond source\)"):
            assert_source_extents(self.config, self.report, self.root)
        self.objects([(".sbss", 1, 3, 8)], [(".sbss", 1, 3, 8)])
        self.assertTrue(assert_source_extents(self.config, self.report, self.root)["passed"])

    def test_stale_report_and_missing_complete_unit_fail(self):
        self.objects([(".data", 4, 3, 1)], [(".data", 4, 3, 1)])
        self.report["units"][0]["sections"][0]["size"] = "8"
        with self.assertRaisesRegex(ValueError, "rebuild the report"):
            self.audit()
        self.report["units"] = []
        with self.assertRaisesRegex(ValueError, "missing from the refreshed report"):
            self.audit()

    def test_report_cannot_keep_a_section_removed_from_the_target(self):
        self.objects([(".text", 4, 6, 1)], [(".text", 4, 6, 1)])
        self.report["units"][0]["sections"].append({"name": ".data", "size": "8"})
        with self.assertRaisesRegex(ValueError, "report section absent from target ELF"):
            self.audit()

    def test_malformed_elf_fails_closed(self):
        path = self.root / "invalid.o"
        path.write_bytes(b"not an ELF")
        with self.assertRaisesRegex(ValueError, "expected a 32-bit ELF"):
            allocated_sections(path)


if __name__ == "__main__":
    unittest.main()
