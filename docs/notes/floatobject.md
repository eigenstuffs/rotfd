# Python floating-point objects

The complete translation unit follows CPython 2.1
`Objects/floatobject.c`. The reconstruction retains upstream algorithms and
comments; the upstream license is in `reference/cpython-2.1/LICENSE`.

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x80143500–0x8014597C | 9,340 |
| `.data` | 0x802D2C98–0x802D2F7C | 740 |
| `.sdata` | 0x80376148–0x8037616C | 36 |
| `.sbss` | 0x80377DE8–0x80377DF0 | 8 |
| `.sdata2` | 0x80379F40–0x80379F78 | 56 |

An isolated compile verified all 26 functions, 9,340 instruction bytes, and
832 initialized data bytes against the original DOL after applying all
relocations. The candidate manifest in
`config/GSQE78/candidates/floatobject.json` records function sizes, owned
objects, section boundaries, and external symbol identities. The complete
linked DOL SHA-1 remains the final acceptance check.

The compiler is CodeWarrior GC/2.0 with `-proc gekko -fp hardware -enum int
-str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred
-pool off -Cpp_exceptions off`. Explicit `static inline` declarations on
`fill_free_list`, `convert_to_double`, `powu`, and `PyFloat_AsStringEx`
reproduce the original emission: none has a separate body. The remaining
functions appear in reversed source order under deferred compilation.

The source covers arithmetic and three-argument powers, float/int/long
coercion, conversion from text, decimal formatting, hashing, comparisons,
reference management, allocation blocks, and finalization. Each float is 16
bytes with its double at offset eight. A 1,000-byte allocation block contains
62 floats, following an eight-byte header area. Both the free-list and
block-list globals belong to this unit.

The local ABI declarations model the GameCube runtime rather than the host
C library: `FILE` has an 80-byte stride, and `stderr` is `__files[2]`; character
classification reads an unsigned-byte table; `errno` is a global; and
`HUGE_VAL` reads the original external double. String bytes start at offset
0x14. The type object is 0x6C bytes and its numeric table is 0x88 bytes.

The `.data` and `.sdata` ends above include the final padding to four bytes.
The following translation unit starts at 0x802D2F80 and 0x80376170,
respectively; their additional alignment gaps remain outside this unit.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/floatobject.c` | `.data` | `0x802D2C98..0x802D2F7A` (738 bytes) | `0x802D2F7A..0x802D2F7C` (2 bytes) |
| `Objects/floatobject.c` | `.sdata` | `0x80376148..0x80376169` (33 bytes) | `0x80376169..0x8037616C` (3 bytes) |

Current native objdiff credits `Objects/floatobject.c`: 835 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
