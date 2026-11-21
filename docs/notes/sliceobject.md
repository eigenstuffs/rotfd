# Slice and ellipsis objects

`src/Objects/sliceobject.c` reconstructs the six emitted slice/ellipsis
functions and their type data from CPython v2.1. The upstream
`PySlice_GetIndices` body has no corresponding linked function in this TU:
the next function at 0x8015AC30 is string-object cleanup. It is omitted from
the reconstruction of this executable.

| Section | Start | End, exclusive | Bytes |
| --- | --- | --- | ---: |
| .text | 0x8015A80C | 0x8015AC30 | 1,060 |
| .data | 0x802D4960 | 0x802D4A5C | 252 |
| .sdata | 0x803762F8 | 0x80376338 | 64 |

The emitted functions are `slice_compare`, `slice_getattr`, `slice_repr`,
`slice_dealloc`, `PySlice_New`, and `ellipsis_repr`. The comparison helper is
`PyObject_Cmp` at 0x80134DE8. Both type objects and the singleton ellipsis are
included in owned data.

GC/2.0 with speed optimization, deferred inlining, disabled data pooling,
and disabled C++ exceptions reproduces all text and data after relocation.
The integrated complete executable passes the original SHA-1, and objdiff
reports all six functions and owned data matched.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/sliceobject.c` | `.data` | `0x802D4960..0x802D4A59` (249 bytes) | `0x802D4A59..0x802D4A5C` (3 bytes) |
| `Objects/sliceobject.c` | `.sdata` | `0x803762F8..0x80376336` (62 bytes) | `0x80376336..0x80376338` (2 bytes) |

Current native objdiff credits `Objects/sliceobject.c`: 311 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
