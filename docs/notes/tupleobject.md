# Python tuple objects

`src/Objects/tupleobject.c` reconstructs all 18 linked functions identified as
`tupleobject.c`, together with the original type and sequence tables, strings,
and tuple free-list storage. The binary behavior and the exact historical
rich-comparison typo identify CPython 2.1 as a strong source reference. The
implementation also retains the copyright and permission notice from the
previously used CPython 1.5.2 reference; CPython 2.1's license is preserved in
`reference/cpython-2.1/LICENSE`.

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x80163D7C–0x80164EF8 | 4,476 |
| `.data` | 0x802D67B0–0x802D68C8 | 280 |
| `.sdata` | 0x80376468–0x8037647E | 22 |
| `.bss` | 0x8033E078–0x8033E118 | 160 |

The preceding function at 0x80163C18 constructs Python strings. The following
`.data` begins with the type-object documentation string at 0x802D68C8. These
boundaries, the tuple API error-file references, the type-table callbacks, and
the contiguous exact matches establish this linked unit's extent. The upstream
`PyTuple_GetSlice` wrapper has no body in this linked unit; no unobserved code
was added for it. Methods retain global linkage in the reconstruction, while
the source's explicit string objects preserve the linked data layout.

| Function | Address | Bytes |
| --- | --- | ---: |
| `PyTuple_Fini` | 0x80163D7C | 192 |
| `_PyTuple_Resize` | 0x80163E3C | 484 |
| `tuplerichcompare` | 0x80164020 | 624 |
| `tupletraverse` | 0x80164290 | 148 |
| `tuplerepeat` | 0x80164324 | 228 |
| `tupleconcat` | 0x80164408 | 264 |
| `tupleslice` | 0x80164510 | 412 |
| `tupleitem` | 0x801646AC | 100 |
| `tuplecontains` | 0x80164710 | 148 |
| `tuplelength` | 0x801647A4 | 8 |
| `tuplehash` | 0x801647AC | 148 |
| `tuplerepr` | 0x80164840 | 268 |
| `tupleprint` | 0x8016494C | 216 |
| `tupledealloc` | 0x80164A24 | 280 |
| `PyTuple_SetItem` | 0x80164B3C | 292 |
| `PyTuple_GetItem` | 0x80164C60 | 128 |
| `PyTuple_Size` | 0x80164CE0 | 76 |
| `PyTuple_New` | 0x80164D2C | 460 |

## Compiler and verification

The matched compiler configuration is CodeWarrior GC/2.0 with:

```text
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto -Cpp_exceptions off -pool off
```

Explicit `speed` matters. Without it, GC/2.0 uses different loop induction
registers and out-of-line saves for four callee-saved registers. GC/3.x's default
optimization preference initially appeared to improve these functions, but
GC/2.0 with `speed` also reproduces the original register choices in
`tuplehash`. Hash alone is therefore insufficient to establish all flags.
`-pool off` retains individual addresses for the owned data instead of creating
a shared pool register. The uninitialized arrays must be defined as
`free_tuples` followed by `numfree`: the compiler emits tentative definitions
in reverse order, reproducing the original BSS layout.

The original 15-function incremental split passed the complete DOL SHA-1 check
on 2026-09-07. The expanded object was then verified with
`scratch/tuple/check_object.py`, which resolves its 146 PowerPC ELF relocations
in memory and compares every initialized byte to the original DOL. All 4,476
text bytes, 280 data bytes, and 22 emitted small-data bytes match; the final two
small-data alignment bytes are linker padding with a separate NonMatching owner
following the [section-extent audit](source-section-padding.md). The two BSS arrays have their
original addresses and sizes. Integration details are retained in
`scratch/tuple/integration.json`. The complete linked DOL SHA-1 is the
final acceptance check, independent of raw object similarity percentages.

Full-unit integration passed on 2026-09-07: the linked executable with all 18
tuple functions and the owned data/BSS is byte-identical to the original DOL
(SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`).

## Recovered behavior

- `tupleitem`, the sequence slot, increments the returned element's reference
  count. `PyTuple_GetItem`, the public API, returns a borrowed reference without
  incrementing it. An earlier README attribution of the increment to the public
  API was incorrect.
- The sequence table includes `tuplecontains`, using
  `PyObject_RichCompareBool(element, item, Py_EQ)` and preserving comparison
  errors. Its ten slots include two unused in-place operation slots.
- `tuplerichcompare` preserves the upstream CPython 2.1 typo
  `case Py_LE: cmp = ws <= ws`. When the equal-prefix comparison falls back to
  comparing lengths, this operation returns true. The original executable
  contains `li r0, 1` at 0x80164188. Correcting the typo would change the game.
- Repetition returns the same tuple with an additional reference for empty
  tuples or a repeat count of one. It checks multiplication overflow before
  allocating other results.
- Concatenation reports the other object's type name in a formatted type error.
- Destruction includes trashcan recursion limiting at depth 50. Tuple free
  lists cover sizes 1–19 and retain at most 2,000 tuples per size. The zero-length
  tuple is cached separately and receives an extra reference.
- Allocation validates byte-count overflow, sets the object header, and zeros
  each element pointer. Internal errors preserve the target's original
  `tupleobject.c` line numbers: 32, 95, 106, 123, and 506.
- `_PyTuple_Resize` rejects nonzero `last_is_sticky`, drops truncated elements,
  reallocates using the original size expression, and clears the caller's
  pointer on failure. `PyTuple_Fini` releases the cached empty tuple and all
  cached free-list nodes.

## Owned data and external runtime state

| Symbol | Address | Ownership |
| --- | --- | --- |
| `tuple_as_sequence` | 0x802D67B0 | Tuple unit |
| `PyTuple_Type` | 0x802D67D8 | Tuple unit |
| `tuple_filename` | 0x802D6844 | Tuple unit |
| `tuple_concat_error` | 0x802D6854 | Tuple unit |
| `tuple_index_error` | 0x802D6888 | Tuple unit |
| `tuple_ass_index_error` | 0x802D68A4 | Tuple unit |
| `tuple_name` | 0x80376468 | Tuple unit |
| Representation punctuation | 0x80376470–0x8037647E | Tuple unit |
| `numfree[20]` | 0x8033E078 | Tuple unit |
| `free_tuples[20]` | 0x8033E0C8 | Tuple unit |
| `_PyTrash_delete_nesting` | 0x80377E1C | Shared object runtime |
| `_PyTrash_delete_later` | 0x80377E20 | Shared object runtime |

`PyTuple_Type` is 0x6C bytes, has flags 0x6B, a traversal callback at offset
0x5C, and a rich-comparison callback at offset 0x64. The target does not include
a garbage-collector prefix in tuple allocations. Singleton booleans and
`NotImplemented` remain owned by their respective original runtime units.
