# Python buffer objects

`src/Objects/bufferobject.c` reconstructs the complete linked buffer unit using
CPython 2.1's function bodies and type tables. The reference license remains in
`reference/cpython-2.1/LICENSE`. The target enables `CACHE_HASH`, giving each
buffer a 0x1C-byte layout and a cached hash field at offset 0x18.

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x80134E70–0x801359FC | 2,956 |
| `.data` | 0x802D1230–0x802D14A0 | 624 |
| `.sdata` | 0x80375ED0–0x80375ED8 | 8 including final padding |

| Function | Address | Bytes |
| --- | --- | ---: |
| `buffer_getcharbuf` | 0x80134E70 | 72 |
| `buffer_getsegcount` | 0x80134EB8 | 24 |
| `buffer_getwritebuf` | 0x80134ED0 | 108 |
| `buffer_getreadbuf` | 0x80134F3C | 72 |
| `buffer_ass_slice` | 0x80134F84 | 380 |
| `buffer_ass_item` | 0x80135100 | 360 |
| `buffer_slice` | 0x80135268 | 128 |
| `buffer_item` | 0x801352E8 | 88 |
| `buffer_repeat` | 0x80135340 | 152 |
| `buffer_concat` | 0x801353D8 | 348 |
| `buffer_length` | 0x80135534 | 8 |
| `buffer_str` | 0x8013553C | 44 |
| `buffer_hash` | 0x80135568 | 172 |
| `buffer_repr` | 0x80135614 | 148 |
| `buffer_compare` | 0x801356A8 | 136 |
| `buffer_dealloc` | 0x80135730 | 100 |
| `PyBuffer_FromMemory` | 0x80135794 | 160 |
| `PyBuffer_FromObject` | 0x80135834 | 456 |

The sequence table occupies 0x28 bytes at 0x802D1230, the buffer protocol table
0x10 bytes at 0x802D1258, and `PyBuffer_Type` 0x6C bytes at 0x802D1268. The only
public constructors present in this linked unit are `PyBuffer_FromMemory` and
`PyBuffer_FromObject`. The shared `_PyBuffer_FromMemory` and
`_PyBuffer_FromObject` helpers are inlined. The upstream `PyBuffer_New` and
read-write constructors have no corresponding linked bodies and are omitted
from the reconstruction.

## Compiler and validation

Use CodeWarrior GC/2.0 with shared Python flags and per-object additions
`-inline auto,deferred -pool off`. The source retains upstream function order;
deferred emission reverses the surviving bodies into the original binary order.
The allocation macro calls `malloc(PyBuffer_Type.tp_basicsize)` followed by
`PyObject_Init`, as established in other interpreter units.

`scratch/bufferobject/check_object.py` resolves all 139 ELF relocations and
compares the resulting initialized sections to the original DOL. It matched
all 2,956 text bytes, 624 data bytes, and seven emitted small-data bytes. One
final small-data byte is linker padding. The complete integration manifest is
`config/GSQE78/candidates/bufferobject.json`; full-DOL SHA-1 remains the
acceptance check.

## Recovered behavior

Buffers retain an optional base object and describe a pointer, byte count, and
read-only flag. Object construction requires a single-segment buffer provider,
clamps offset and length, and unwraps nested buffers to their retained base.
The sequence operations support reading, slicing, concatenation, repetition,
and checked assignment. Read-only buffers reject mutation and writable buffers
reject hashing; the first successful hash of a read-only buffer is cached.
The buffer protocol exposes a single segment and validates segment zero.
All observed historical behavior is retained without correctness changes.

## Integrated result

The central build integrated this complete unit and verified the rebuilt DOL SHA-1 as `5da8295a79bf297ab62c620e6ac66210be1c6ef5`, identical to the original GSQE78 executable.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/bufferobject.c` | `.sdata` | `0x80375ED0..0x80375ED7` (7 bytes) | `0x80375ED7..0x80375ED8` (1 byte) |

Current native objdiff credits `Objects/bufferobject.c`: 631 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
