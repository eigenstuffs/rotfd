# Traceback objects and printing

The five emitted traceback functions match at 0x801733AC..0x80173A28
(1,660 bytes): `PyTraceBack_Print`, `tb_displayline`, `PyTraceBack_Here`,
`tb_dealloc`, and `tb_getattr`. The constructor and internal print loop are
inline helpers in the original executable.

Source follows CPython v2.1 `Python/traceback.c`. Data at
0x802DB300..0x802DB450 includes the member/type tables, original diagnostics,
and output formats. Small data occupies 0x803765D8..0x803765F8. The target uses
the slash path separator and 1,024-byte maximum path length. Its traceback
object layout, frame references, thread error state, and trash-chain cleanup
match the corresponding reconstructed interpreter units.

GC/2.0 with speed optimization, deferred inlining, no pooling, and no C++
exceptions reproduces all text/data. Ninety relocations were resolved before
the byte comparison. Integration passes the complete original DOL SHA-1.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/traceback.c` | `.data` | `0x802DB300..0x802DB44D` (333 bytes) | `0x802DB44D..0x802DB450` (3 bytes) |
| `Python/traceback.c` | `.sdata` | `0x803765D8..0x803765F6` (30 bytes) | `0x803765F6..0x803765F8` (2 bytes) |

Current native objdiff credits `Python/traceback.c`: 363 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
