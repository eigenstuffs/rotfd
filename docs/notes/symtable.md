# Symbol-table entry objects

`src/Python/symtable.c` reconstructs the complete CPython 2.1 `Python/symtable.c` translation unit. It implements symbol-table entry allocation, representation, destruction, and attribute access; the compiler's symbol analysis remains in the separate `Python/compile.c` translation unit.

The four original functions occupy `0x801A2310..0x801A26A8` (920 bytes), immediately between `Python/pythonrun.c` and `Python/sysmodule.c`. Owned initialized data spans `.data` `0x802E36D8..0x802E3840` (360 bytes) and `.sdata` `0x80377038..0x80377064` (44 bytes). These sections contain the attribute table, `PySymtableEntry_Type`, attribute names, and representation format.

All upstream algorithms and initializers compile unchanged. Local declarations embed the verified CPython 2.1 object, symbol-table, compiler, and grammar layouts. `PyObject_New` and `PyObject_Del` use their original out-of-line allocation/deallocation APIs. The type has the original 108-byte layout and default flags `0x6B`.

GC/2.0 compilation uses `-proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -pool off -Cpp_exceptions off`. `scratch/symtable/verify.py` resolves all text and data relocations to original addresses, then compares the resulting bytes with `orig/GSQE78/main.dol`: `TEXT 920 920`, `.data 360 EXACT`, `.sdata 44 EXACT`. The candidate includes explicit global/local symbol scopes. Whole-DOL linking and SHA-1 verification are performed during integration.

The source records CPython provenance and its upstream license at `reference/cpython-2.1/LICENSE`.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/symtable.c` | `.data` | `0x802E36D8..0x802E383E` (358 bytes) | `0x802E383E..0x802E3840` (2 bytes) |
| `Python/symtable.c` | `.sdata` | `0x80377038..0x80377063` (43 bytes) | `0x80377063..0x80377064` (1 byte) |

Current native objdiff credits `Python/symtable.c`: 401 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
