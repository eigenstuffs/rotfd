# Python function objects

`src/Objects/funcobject.c` reconstructs the complete identified function-object
TU from CPython 2.1. The original reference and its license remain in
`reference/cpython-2.1/`. The source records attribution and the changes needed
for this executable's ABI.

## Boundaries and identities

The `function` type name at `0x802D32A8` and the callback pointers in
`PyFunction_Type` at `0x802D32B4` identify the private functions. References to
the `funcobject.c` filename at `0x802D343C` identify the defaults and closure
setters independently. These agree with the filemap and the original function
ordering.

| Section | Start | End (exclusive) | Contents |
| --- | --- | --- | --- |
| `.text` | `0x801467C8` | `0x80147184` | Eight functions, 2,492 bytes |
| `.data` | `0x802D3180` | `0x802D3478` | Member names/table, type object, strings, one alignment byte |
| `.sdata` | `0x803761A0` | `0x803761A8` | `__doc__` string |

| Function | Address | Bytes |
| --- | --- | ---: |
| `func_traverse` | `0x801467C8` | 348 |
| `func_repr` | `0x80146924` | 124 |
| `func_dealloc` | `0x801469A0` | 400 |
| `func_setattro` | `0x80146B30` | 596 |
| `func_getattro` | `0x80146D84` | 244 |
| `PyFunction_SetClosure` | `0x80146E78` | 244 |
| `PyFunction_SetDefaults` | `0x80146F6C` | 244 |
| `PyFunction_New` | `0x80147060` | 292 |

The four public getters in the upstream source have no emitted functions in
this TU and are omitted. `func_memberlist` is the 176-byte private member table
at `0x802D31F8`; its field offsets and read-only flags match the executable.

## ABI and compilation

`PyFunctionObject` is 40 bytes. The weak-reference list is at offset `0x24`.
`PyCodeObject.co_consts` and `co_name` are at offsets `0x1C` and `0x34`, matching
the 2.1 structure. The type object is 108 bytes with flags `0x6B` and a
weak-list offset of `0x24`.

The build has cyclic-GC macros disabled: no GC header is allocated and the
GC init/fini macros emit nothing. Traversal callbacks remain present.
`PyObject_ClearWeakRefs` is a function-pointer variable at `0x803762A0`, called
indirectly. Allocation uses `malloc(tp_basicsize)` and `PyObject_Init`;
reference-count zero dispatches directly to the type's destructor.

The bad-internal-call paths retain filename `funcobject.c` and original line
numbers 77 for defaults and 108 for closure. Other function bodies, including
attribute-dictionary fallback and error translation, follow the 2.1 reference.

Use CodeWarrior `GC/2.0` with:

```text
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off
```

Deferred inlining preserves the observed reverse function order. Pool-off
keeps all strings and the member table at their original offsets.

## Reproduce the isolated check

From the repository root:

```sh
python3 scratch/funcobject/verify.py
```

The script recompiles the source, validates the original DOL hash, resolves
all 136 ELF relocations, and compares every byte of text, initialized data,
small data, and trailing data alignment. Result: 2,492 code bytes, 759 data
bytes, eight small-data bytes, and one padding byte match exactly. No branch
or address instructions are masked.

[`funcobject.json`](../../config/GSQE78/candidates/funcobject.json) contains the
integration ranges, function/data/dependency mappings, flags, and validation
hashes. Root integration must also pass `ninja`'s complete DOL hash check; see
the current [progress snapshot](../../PROGRESS.md) for linked-source status.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/funcobject.c` | `.data` | `0x802D3180..0x802D3477` (759 bytes) | `0x802D3477..0x802D3478` (1 byte) |

Current native objdiff credits `Objects/funcobject.c`: 767 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
