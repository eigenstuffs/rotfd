# Menu3D glyph, item and configuration parsers

Integrated on 2026-09-27 as `src/Game/menu3d_parsers.cpp` with GC/1.3.2,
`-O4,p -inline auto -str reuse,readonly -pool on -Cpp_exceptions off`.
This partial original translation unit owns three functions and their shared
compiler-generated string pool and constants:

| Function | Original address | Bytes | Actual relocations |
| --- | --- | ---: | ---: |
| Glyph-token parsing | `80216DE8` | 1,076 | 78 |
| Item parsing | `8021721C` | 1,252 | 87 |
| Configuration parsing | `80217700` | 2,208 | 108 |

All 4,536 retained code bytes and all 273 actual relocations match. The 343-byte
`.rodata` range `802AE710..802AE867` and 232-byte `.sdata2` range
`8037ADA8..8037AE90` also match. Their 56 sized objects contain 498 semantic
bytes plus 77 bytes of compiler-emitted internal alignment. The single original
byte at `802AE867..802AE868` has separate NonMatching ownership with explicit
byte alignment. No section is rounded up for source credit.

The glyph parser translates nine input-symbol tokens into single-byte glyphs,
joining tokens with spaces. The item parser reads names, eight parameter hashes,
neighbor hashes, alignment, visibility and center settings. As in the original,
it has no array-bound guard for parameter tokens. It accumulates flags in an
unsigned byte before copying them into the item's 16-bit field; consequently
`FOREVERACCESS`'s 0x100 bit truncates. This observed quirk is preserved.
Unlike the neighboring Menu2D parser, it has no POSITION or alternate-color
branch. Its item constructor still initializes the two-float position.

The configuration parser loads a file through the manager's native virtual
slot, reads type/count/resource/world settings and five color groups, and
finishes through menu virtual slot 0x54. FONT recognizes FONT_BIG and
FONT_SMALL as one and zero, otherwise printing the original diagnostic.
Bitmap lookup uses `fn_80263308` and a native derived-handle conversion with
its own reference increment and temporary destruction. These differ from the
Menu2D font/bitmap path. Names and opaque interfaces are reconstructed working
names; source comments and pointer layouts do not establish original class names.

The original Name default constructor remains the strong source owner at
`800A59D4`. Its identical 12-byte weak duplicate and four unreferenced destructor
helpers (344 bytes) are excluded. Native linker selection and dead stripping
remove these 356 bytes; they are not counted again. Other Menu3D functions,
dispatch tables, RTTI and constructor constants keep their separate ownership.

The complete original-target scan covered all 4,092 configured objects before
integration, with no missing targets, unresolved relocations or ambiguous
section bases. All 73 direct references into these data extents belong to the
three parsers. All 67 SDA2 references also match raw original instruction
operands; 25 pool-relative string uses account for the long-string objects.
Each of the 56 sized data objects has a verified consumer. The five integer
color-conversion sites share the double constant and float divisor.

Reproduce the strict retained-byte and allocation inventory checks with
`python3 scratch/game_menu3d_parsers/strict.py --production`. The diagnostic
comparator alone is not the acceptance gate. Ownership evidence is in
`scratch/game_menu3d_parsers/ownership_summary.json`;
`scratch/menu3d_parsers_link_proof.json` records final strong-symbol selection,
weak-helper removal and uncredited padding. The full acceptance checkpoint is
`scratch/menu3d_parsers_checkpoint.json`.

The rebuilt DOL is byte-identical, all 626 source units match, the original
baseline is unchanged, all 23 tests pass, and source extent and assembly-token
audits pass. No previously linked source file changed in this integration.
