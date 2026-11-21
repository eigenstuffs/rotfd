"""The storage correction must preserve original bytes and reject wider inputs."""

import hashlib
import struct
import unittest

from tools.normalize_text_storage import normalize


def fixture():
    symbol_names = b"\0pad_03_801EF5C8_text\0lbl_801EF5C8\0"
    section_names = b"\0.text\0.symtab\0.strtab\0.shstrtab\0"
    symtab_at = 108
    string_at = symtab_at + 48
    section_names_at = string_at + len(symbol_names)
    table_at = (section_names_at + len(section_names) + 3) & ~3
    data = bytearray(table_at + 5 * 40)
    data[:16] = b"\x7fELF\x01\x02\x01" + bytes(9)
    struct.pack_into(">HHIIIIIHHHHHH", data, 16,
                     1, 20, 1, 0, 0, table_at, 0, 52, 0, 0, 40, 5, 4)
    struct.pack_into(">IIIBBH", data, symtab_at + 16, 1, 0, 44, 2, 0, 1)
    struct.pack_into(">IIIBBH", data, symtab_at + 32,
                     symbol_names.index(b"lbl_"), 0, 0, 0x10, 0, 1)
    data[string_at:string_at + len(symbol_names)] = symbol_names
    data[section_names_at:section_names_at + len(section_names)] = section_names
    sections = [
        (0,) * 10,
        (1, 1, 6, 0, 64, 44, 0, 0, 4, 0),
        (7, 2, 0, 0, symtab_at, 48, 3, 2, 4, 16),
        (15, 3, 0, 0, string_at, len(symbol_names), 0, 0, 1, 0),
        (23, 3, 0, 0, section_names_at, len(section_names), 0, 0, 1, 0),
    ]
    for i, section in enumerate(sections):
        struct.pack_into(">10I", data, table_at + i * 40, *section)
    corrected = bytearray(data)
    corrected[symtab_at + 16 + 11] = 0
    corrected[symtab_at + 16 + 12] = 0
    contract = {
        "size": 44,
        "original_label": "lbl_801EF5C8",
        "synthetic_symbol": "pad_03_801EF5C8_text",
        "generated_sha256": hashlib.sha256(data).hexdigest(),
        "normalized_sha256": hashlib.sha256(corrected).hexdigest(),
    }
    return bytes(data), contract, symtab_at + 16, table_at


class TextStorageTests(unittest.TestCase):
    def test_only_synthetic_extent_and_type_change(self):
        data, contract, pad_at, _ = fixture()
        result = normalize(data, contract)
        self.assertEqual(len(result), len(data))
        self.assertEqual([i for i, pair in enumerate(zip(data, result)) if pair[0] != pair[1]],
                         [pad_at + 11, pad_at + 12])
        self.assertEqual(result[64:108], bytes(44))
        self.assertEqual(result[pad_at + 16:pad_at + 32], data[pad_at + 16:pad_at + 32])

    def test_already_normalized_is_idempotent(self):
        data, contract, _, _ = fixture()
        result = normalize(data, contract)
        self.assertEqual(normalize(result, contract), result)

    def test_changed_object_cannot_be_normalized(self):
        data, contract, pad_at, _ = fixture()
        for offset in (64, pad_at + 7, pad_at + 16 + 12, len(data) - 1):
            with self.subTest(offset=offset):
                changed = bytearray(data)
                changed[offset] ^= 1
                with self.assertRaisesRegex(ValueError, "SHA-256"):
                    normalize(bytes(changed), contract)

    def test_pins_do_not_replace_structural_guards(self):
        data, contract, pad_at, table_at = fixture()
        for offset, value, message in (
                (64, 1, "only zero"),
                (pad_at + 12, 0x12, "synthetic symbol"),
                (pad_at + 16 + 12, 0, "global label"),
                (table_at + 40 + 23, 40, "extent"),
                (table_at + 80 + 7, 9, "relocations")):
            with self.subTest(message=message):
                changed = bytearray(data)
                changed[offset] = value
                modified_contract = dict(contract, generated_sha256=hashlib.sha256(changed).hexdigest())
                with self.assertRaisesRegex(ValueError, message):
                    normalize(bytes(changed), modified_contract)


if __name__ == "__main__":
    unittest.main()
