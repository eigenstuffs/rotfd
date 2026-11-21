# C-object wrapper

The linked CPython v2.1 C-object TU contains `PyCObject_dealloc` and
`PyCObject_AsVoidPtr`: 212 code bytes at 0x8013C798..0x8013C86C. Its data
occupies 0x802D1FE0..0x802D21E8, including three trailing alignment bytes.
The type contains the original documentation and uses a 20-byte object
layout with pointer, description, and destructor fields.

The upstream constructors, description accessor, and import helper are not
linked here. The following function at 0x8013C86C is `complex_getattr`; the
unlinked APIs' error strings are also absent. This unit therefore reconstructs
all C-object code actually present in the target executable.

GC/2.0, speed optimization, deferred inlining, and disabled data pooling and
C++ exceptions give an exact match. Isolated verification resolved 16
relocations and compared all text/data and alignment padding. Integration
passes the full original DOL SHA-1; both functions and all owned data match.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/cobject.c` | `.data` | `0x802D1FE0..0x802D21E5` (517 bytes) | `0x802D21E5..0x802D21E8` (3 bytes) |

Current native objdiff credits `Objects/cobject.c`: 517 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
