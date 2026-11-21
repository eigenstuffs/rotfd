# Built-in method objects

`src/Objects/methodobject.c` reconstructs the complete identified built-in
method-object TU. The source is adapted from the attributed CPython 1.5.2
reference, with behavior checked against the executable. CPython 2.1 also
contains the observed pointer hashing and `%p` representation changes.

## Identification

No `methodobject.c` filename string survives in the DOL. The string
`builtin_function_or_method` at `0x802D4148` identifies the type object at
`0x802D4164`. Its callback pointers identify the private methods. Their code,
references to the same free list and strings, and reverse source order place
the TU immediately before `Objects/moduleobject.c`.

| Section | Start | End (exclusive) | Ownership |
| --- | --- | --- | --- |
| `.text` | `0x80155540` | `0x80155C0C` | Nine emitted functions |
| `.data` | `0x802D4148` | `0x802D4280` | Type name, `PyCFunction_Type`, and strings |
| `.sdata` | `0x80376260` | `0x80376270` | `__doc__`, `[sss]`, and two alignment bytes |
| `.sbss` | `0x80377E10` | `0x80377E14` | Static `free_list` |

| Function | Address | Bytes |
| --- | --- | ---: |
| `PyCFunction_Fini` | `0x80155540` | 56 |
| `Py_FindMethod` | `0x80155578` | 416 |
| `listmethodchain` | `0x80155718` | 284 |
| `meth_hash` | `0x80155834` | 140 |
| `meth_compare` | `0x801558C0` | 128 |
| `meth_repr` | `0x80155940` | 120 |
| `meth_getattr` | `0x801559B8` | 324 |
| `meth_dealloc` | `0x80155AFC` | 104 |
| `PyCFunction_New` | `0x80155B64` | 168 |

`PyCFunction_GetFunction`, `PyCFunction_GetSelf`, and `PyCFunction_GetFlags`
have no emitted functions in this TU. They are omitted from this reconstruction.
`Py_FindMethodInChain` is a `static inline` source helper: its body and
`PyCFunction_New` are inlined into `Py_FindMethod`. Without the explicit inline
declaration, the compiler emits an additional unused helper.

## Matching details

Use CodeWarrior `GC/2.0` with the interpreter flags and these TU requirements:

```text
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off
```

Deferred inlining emits functions in reverse source order; pool-off preserves
the original string placement. The recovered type size is `0x6C`, and each
method object is `0x10` bytes. Allocation uses `malloc(tp_basicsize)` followed
by `PyObject_Init`. Decrement-to-zero invokes the type's destructor directly.

Compared with the 1.5.2 reference, `meth_hash` hashes the function pointer with
`_Py_HashPointer`, propagates `-1`, XORs the result with the receiver hash, and
maps a final `-1` to `-2`. `_Py_HashPointer` at `0x801576A8` is a four-byte
identity function in this executable. `meth_repr` uses `%p`, not `%lx`.

## Verification

The standalone compiler output matched all 1,740 text bytes, 312 data bytes,
and 14 initialized small-data bytes after applying all 88 ELF relocations to
their original addresses. The verifier handled `ADDR32`, `ADDR16_LO`,
`ADDR16_HA`, `REL24`, and `EMB_SDA21`; small-data relocation used the observed
`r13` base `0x8037BE40`. It compared every resulting byte, rather than masking
branch or address instructions. The four-byte free-list storage is zero BSS.

[`methodobject.json`](../../config/GSQE78/candidates/methodobject.json) records
the ranges, symbol mappings, compiler options, and source/object hashes for
that candidate. Generated probe files live in `build/methodobject/` and are
disposable. The integrated matching build subsequently passed the complete
DOL SHA-1 check. The current [progress snapshot](../../PROGRESS.md) is
authoritative for linked-source status after further changes.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/methodobject.c` | `.sdata` | `0x80376260..0x8037626E` (14 bytes) | `0x8037626E..0x80376270` (2 bytes) |

Current native objdiff credits `Objects/methodobject.c`: 330 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
