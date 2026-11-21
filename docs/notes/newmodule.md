# Object-construction module (`new`)

`src/Modules/newmodule.c` reconstructs the complete CPython 2.1 `Modules/newmodule.c` implementation present in GSQE78. The original built-in module table at `0x802E95F4` names `new` and points at `initnew` (`0x801A90E0`). This provides independent evidence for the translation unit identity.

The original seven-function text range is `0x801A90E0..0x801A96F4` (1,556 bytes), followed immediately by the `_codecs` module. Owned initialized data spans `.data` `0x802E8BA8..0x802E901C` (1,140 bytes) and `.sdata` `0x80377438..0x8037744C` (20 bytes), including the six method descriptions, method table, module documentation, argument formats, and error messages.

All upstream function algorithms and data initializers compile unchanged. The source embeds the already verified runtime object declarations plus CPython 2.1 function and code object declarations; it uses the original 32-bit PowerPC ABI and disabled cyclic garbage collection. Compiler flags are GC/2.0, Gekko hardware floating point, `-enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -pool off -Cpp_exceptions off`. Deferred inlining produces the original reverse source function order.

`scratch/newmodule/verify.py` applies the original target addresses to every compiled text and data relocation and compares the results directly against `orig/GSQE78/main.dol`. Its result is `TEXT 1556 1556`, `.data 1140 EXACT`, `.sdata 20 EXACT`. The candidate manifest includes explicit symbol scopes for all owned static functions and documentation/table objects. This isolated verification is ready for integration; whole-DOL linking and SHA-1 verification remain the final integration check.

Upstream source and license are retained in `reference/cpython-2.1`; the reconstructed source records its CPython provenance.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Modules/newmodule.c` | `.data` | `0x802E8BA8..0x802E9019` (1,137 bytes) | `0x802E9019..0x802E901C` (3 bytes) |

Current native objdiff credits `Modules/newmodule.c`: 1,157 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
