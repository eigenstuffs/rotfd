# Small native method records beside runtime base lists

Two original-only `.data` intervals now extend their adjacent runtime-base-list source units:

| Source | Added interval | Bytes | Contents |
| --- | --- | ---: | --- |
| `src/Game/native_rtti_base_lists_802B6108.cpp` | `802B60F0..802B6108` | 24 | CKarate method record and ABC_Agent base list |
| `src/Game/native_rtti_base_lists_802B8470.cpp` | `802B8490..802B84A8` | 24 | Falling projectile state method record |

GC/1.3.2 builds the enclosing `.data` extents at exactly 80 and 56 bytes,
with 9 and 8 actual pointer relocations. The new records account for 8 of
those relocations. The three new global symbols retain their original sizes
and offsets. Private pre-integration objects and source are in
`scratch/native_small_records_20261020/`. Referenced functions and runtime
type descriptors retain their existing owners; these are partial data splits.

These transfers add 48 matched data bytes. The full DOL passes the expected
SHA-1 check, `ninja changes` is empty, the source extent audit passes, and
all 66 tests pass.

## Unpromoted neighboring switch table

The neighboring `802B4AB4..802B4C48` table group remains original. A private
candidate in `scratch/native_method_jump_records_20261020/` reproduced its
404 bytes, five global symbols, and all 86 relocations in the enclosing
object. Its switch table points inside `fn_80056144`. When promoted, the
linked DOL was 4,192 bytes shorter and failed the expected SHA-1 check.
Restoring the original split restored the hash. The exact object probe is
evidence for the data declarations, but not a linked source match; its link
layout failure needs diagnosis before promotion.
