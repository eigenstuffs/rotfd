"""Report-only linker-alias resolution on a minimal relocatable ELF."""

from pathlib import Path
import struct
import tempfile
import unittest

from tools.elfmini import Elf
from tools.resolve_link_aliases import load_aliases, resolve


def object_with_refs(path, names):
    """Write a PPC ELF32 whose .data holds one ADDR32 relocation per undefined name."""
    shstr = b"\0.data\0.rela.data\0.symtab\0.strtab\0.shstrtab\0"
    off = {n: shstr.index(n.encode() + b"\0") for n in
           (".data", ".rela.data", ".symtab", ".strtab", ".shstrtab")}
    strtab = bytearray(b"\0")
    syms = bytearray(16)  # null symbol
    syms += struct.pack(">IIIBBH", 0, 0, 0, 3, 0, 1)  # section symbol for .data
    for name in names:
        name_off = len(strtab)
        strtab += name.encode() + b"\0"
        syms += struct.pack(">IIIBBH", name_off, 0, 0, 0x10, 0, 0)  # GLOBAL NOTYPE UND
    data = bytes(4 * len(names))
    rela = b"".join(struct.pack(">IIi", 4 * i, ((2 + i) << 8) | 1, 0) for i in range(len(names)))
    blob = bytearray(52)
    blob[:16] = b"\x7fELF\x01\x02\x01" + bytes(9)
    layout = []
    for content in (data, rela, bytes(syms), bytes(strtab), shstr):
        while len(blob) % 4:
            blob.append(0)
        layout.append((len(blob), len(content)))
        blob += content
    headers = [(0,) * 10,
               (off[".data"], 1, 3, 0, *layout[0], 0, 0, 4, 0),
               (off[".rela.data"], 4, 0, 0, *layout[1], 3, 1, 4, 12),
               (off[".symtab"], 2, 0, 0, *layout[2], 4, 2, 4, 16),
               (off[".strtab"], 3, 0, 0, *layout[3], 0, 0, 1, 0),
               (off[".shstrtab"], 3, 0, 0, *layout[4], 0, 0, 1, 0)]
    shoff = len(blob)
    for header in headers:
        blob += struct.pack(">10I", *header)
    struct.pack_into(">HHIIIIIHHHHHH", blob, 16, 1, 20, 1, 0, 0, shoff, 0,
                     52, 0, 0, 40, len(headers), 5)
    path.write_bytes(blob)


class LinkAliasTests(unittest.TestCase):
    def test_load_aliases_accepts_only_simple_symbol_aliases(self):
        with tempfile.TemporaryDirectory() as tmp:
            script = Path(tmp) / "ldscript.tpl"
            script.write_text(
                'SECTIONS {\n'
                '    _stack_end = $LAST_SECTION_SYMBOL + SIZEOF($LAST_SECTION_NAME);\n'
                '    __ArenaHi = $ARENAHI;\n'
                '    __OSDBJUMPEND = __OSSetExceptionHandler;\n'
                '    thunk8_f__1AFv = "@8@f__1AFv"; // comment\n'
                '}\n')
            self.assertEqual(load_aliases(script), {
                "__OSDBJUMPEND": "__OSSetExceptionHandler",
                "thunk8_f__1AFv": "@8@f__1AFv",
            })

    def test_renames_undefined_alias_references_only(self):
        with tempfile.TemporaryDirectory() as tmp:
            src, out = Path(tmp) / "in.o", Path(tmp) / "out.o"
            object_with_refs(src, ["thunk8_f__1AFv", "plain_symbol"])
            count = resolve(str(src), str(out), {"thunk8_f__1AFv": "@8@f__1AFv"})
            self.assertEqual(count, 1)
            before, after = Elf(str(src)), Elf(str(out))
            names = [r["sym"]["name"] for r in after.relocs[1]]
            self.assertEqual(names, ["@8@f__1AFv", "plain_symbol"])
            self.assertEqual(after.data(1), before.data(1))
            self.assertEqual([(r["offset"], r["type"], r["addend"]) for r in after.relocs[1]],
                             [(r["offset"], r["type"], r["addend"]) for r in before.relocs[1]])

    def test_object_without_aliases_is_copied_verbatim(self):
        with tempfile.TemporaryDirectory() as tmp:
            src, out = Path(tmp) / "in.o", Path(tmp) / "out.o"
            object_with_refs(src, ["plain_symbol"])
            self.assertEqual(resolve(str(src), str(out), {"thunk8_f__1AFv": "@8@f__1AFv"}), 0)
            self.assertEqual(out.read_bytes(), src.read_bytes())


if __name__ == "__main__":
    unittest.main()
