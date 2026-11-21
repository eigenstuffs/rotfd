# Python built-in functions

`src/Python/bltinmodule.c` reconstructs the complete linked CPython 2.1 built-in module. All 60 functions match 15,788 original text bytes after relocation: 55 built-in callbacks, `filterstring`, `filtertuple`, `min_max`, `complex_from_string`, and `_PyBuiltin_Init`.

The implementation and documentation strings derive from the official source retained in `reference/cpython-2.1/Python/bltinmodule.c`, with its license in `reference/cpython-2.1/LICENSE`. The recovered implementation includes imports, compilation and execution, numeric conversion and rounding, collection construction and filtering, attribute operations, input, file opening, and the complete built-in registration table.

| Section | Original range | Verified content |
| --- | --- | --- |
| `.text` | `0x801A387C..0x801A7628` | 15,788 bytes, 60 functions |
| `.data` | `0x802E51D8..0x802E8938` | 14,173 bytes plus 3 zero padding bytes |
| `.sdata` | `0x803770E8..0x80377310` | 550 bytes plus 2 zero padding bytes |
| `.sdata2` | `0x8037A190..0x8037A1C0` | 48 bytes |
| `.sbss` | `0x80377F60..0x80377F64` | 4 bytes for the cached `__complex__` attribute name |

`get_len_of_range` is inline-only, matching its absence as a standalone original function. The MSL `abs` macro resolves to the compiler's `__abs` intrinsic; this is necessary to reproduce the three integer absolute-value instructions in `round()`. Type-oriented allocation retains `_PyMem_EXTRA = 1`, Unicode uses 16-bit code units, and native-thread, FPE-trap, and assertion macros are disabled. The MSL character table and the recovered object, sequence, numeric, and file layouts reproduce the original calling conventions.

The 55-entry method table plus its sentinel, every documentation string, all floating constants, and the three function-local static objects are included in the comparison. `attrlist`, `errmsg`, and `complexstr` have compiler-generated symbol suffixes recorded separately in the manifest. No raw assembly, object rewriting, or artificial literal tables are used.

Run the independent check from the repository root:

```sh
python3 scratch/bltinmodule/verify.py
```

It compiles with the recovered GC/2.0 flags, applies all 862 relocations, and compares every allocated initialized section against the SHA-verified original DOL. It also verifies complete section extents, zero alignment padding, and the SBSS range. No instruction or relocation differences are masked. Exact function and data mappings, imported symbols, source/object/header hashes, and section ranges are in `config/GSQE78/candidates/bltinmodule.json`.

Integration must shrink the original eight-byte `lbl_80377F60` symbol to the four-byte `complexstr` object and preserve `0x80377F64..0x80377F68` separately. The isolated source is ready; the normal project build and full-DOL SHA check remain the integration gate. Current totals belong in the generated `PROGRESS.md`.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/bltinmodule.c` | `.data` | `0x802E51D8..0x802E8935` (14,173 bytes) | `0x802E8935..0x802E8938` (3 bytes) |
| `Python/bltinmodule.c` | `.sdata` | `0x803770E8..0x8037730E` (550 bytes) | `0x8037730E..0x80377310` (2 bytes) |

Current native objdiff credits `Python/bltinmodule.c`: 14,775 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
