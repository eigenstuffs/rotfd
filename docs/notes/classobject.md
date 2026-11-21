# Objects/classobject.c

The complete linked class-object unit is reconstructed from CPython 2.1. All 80 linked functions and every initialized byte match the original GSQE78 DOL in an isolated relocation-aware comparison. Central integration passed the full DOL SHA-1 check (`5da8295a79bf297ab62c620e6ac66210be1c6ef5`), with all retained code and data matching.

| Section | Start | End, exclusive | Emitted bytes | Owned bytes |
| --- | --- | --- | ---: | ---: |
| `.text` | `0x80135D2C` | `0x8013C798` | 27,244 | 27,244 |
| `.data` | `0x802D1558` | `0x802D1FE0` | 2,690 | 2,696 |
| `.sdata` | `0x80375EE0` | `0x80376018` | 309 | 312 |
| `.sbss` | `0x80377D50` | `0x80377DD8` | 132 | 136 |

The initialized section tails are zero-filled alignment padding. `.sbss` contains 33 retained pointer caches; its locations are verified through the instructions accessing them. Uninitialized storage itself has no original file bytes to compare.

## Matching details

The recovered unit includes class construction, lookup, mutation, subclass checks, instance construction and finalization, sequence/mapping operations, all linked arithmetic operators, rich comparisons, bound-method construction and access, method finalization, and the three type objects. The full callback tables, member list, operator-name arrays, strings, and pointer caches are owned by the source unit.

The source uses CPython 2.1's object, class, instance, method, and function layouts. Target GC bookkeeping and assertions are disabled. Reference counting and weak-reference callbacks remain active. `PyObject_ClearWeakRefs` is a function-pointer variable, as in the reference header.

Several helpers are emitted only inside callers: `half_richcompare`, `do_binop_inplace`, `do_binop`, `generic_binary_op`, `sliceobj_from_intint`, `instance_setattr1`, `set_name`, and `set_slot`. The three method accessors are also inline; retaining their bodies is necessary because the original includes their type checks and diagnostics inside `instance_getattr2`. Explicit `static inline` declarations suppress surplus standalone copies without changing the linked instructions.

Six method-name caches are declared together before the item-operation caches to reproduce the original `.sbss` layout. This preserves their internal static lifetime and lookup behavior. The original file's diagnostic line constants are retained explicitly: `449`, `459`, `1799`, `1827`, `1837`, and `1847`. They do not uniformly match upstream 2.1 line numbers, so the source does not pretend those diagnostic values refer to its present formatting.

This is a complete reconstruction of the linked translation unit. Source functions removed by the original link are not claimed as additional matched progress. The reference establishes source lineage and algorithms; byte comparison establishes the target implementation.

## Reproduce

Use the project's GC/2.0 compiler with the standard Python flags and `-inline auto,deferred -pool off`:

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/classobject/final.o src/Objects/classobject.c
python3 scratch/classobject/check_object.py
```

The isolated verifier resolves 1,429 relocations and reports zero mismatching initialized bytes. It uses the fixed section bases, symbol addresses recovered from corresponding original call/data references, and the original DOL; it never edits the original binary or candidate machine code to manufacture matches.

The integration manifest is `config/GSQE78/candidates/classobject.json`. It includes all 80 function names, type/table/cache symbols, symbol sizes and scopes, and 25 newly identified external API names. `scratch/classobject/verification.txt` preserves the isolated check. `scratch/classobject/candidate.c` and exploratory scripts are scratch history; `src/Objects/classobject.c` is authoritative.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/classobject.c` | `.data` | `0x802D1558..0x802D1FDA` (2,690 bytes) | `0x802D1FDA..0x802D1FE0` (6 bytes) |
| `Objects/classobject.c` | `.sdata` | `0x80375EE0..0x80376015` (309 bytes) | `0x80376015..0x80376018` (3 bytes) |

Current native objdiff credits `Objects/classobject.c`: 3,131 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
