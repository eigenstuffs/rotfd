# Closure cell objects

All eight CPython v2.1 cell-object functions match at
0x801359FC..0x80135D2C (816 bytes). The type and strings occupy
0x802D14A0..0x802D1554, and the small-data string occupies
0x80375ED8..0x80375EE0, including alignment padding.

The historical `PyCellObject` uses `PyObject_VAR_HEAD`: its value pointer is
at offset 0xC, not 0x8. Cyclic GC is disabled, while traversal/clear callbacks
remain in the type. Allocation calls `_PyObject_New` and disposal calls
`_PyObject_Del`. The source preserves `cellobject.c` diagnostic line numbers
22 and 33 through `#line`.

GC/2.0 with speed optimization, deferred inlining, no pooling, and no C++
exceptions matches the full unit. Isolated verification resolved 29
relocations; integration passes the full DOL SHA-1. The four-byte gap before
the eight-aligned class type is retained outside this unit.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/cellobject.c` | `.data` | `0x802D14A0..0x802D1551` (177 bytes) | `0x802D1551..0x802D1554` (3 bytes) |
| `Objects/cellobject.c` | `.sdata` | `0x80375ED8..0x80375EDD` (5 bytes) | `0x80375EDD..0x80375EE0` (3 bytes) |

Current native objdiff credits `Objects/cellobject.c`: 182 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
