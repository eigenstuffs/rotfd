# Puzzletile and QSnail15 native records

Two original-only `.data` groups now extend their preceding accepted
runtime-base-list sources:

| Source | Added interval | Contents |
| --- | --- | --- |
| `src/Game/native_rtti_base_lists_802B7A98.cpp` | `802B7C24..802B7D20` (252 bytes) | Puzzletile method record and six 12-byte member-pointer descriptors |
| `src/Game/native_rtti_base_lists_802BEDB8.cpp` | `802BEE14..802BEEE0` (204 bytes) | QSnail15 method record and two-base runtime list |

The corresponding compiler-owned extents are `802B7A98..802B7D20` (648
bytes) and `802BEDB8..802BEEE0` (296 bytes). These are partial data splits:
referenced functions and type descriptors, the following switch table, and
other original translation-unit material retain their separate owners. The
member-pointer descriptors are the six repeated `(0, 0x94, 8)` records
copied as 12-byte values by their native consumers.

GC/1.3.2 emits the exact original bytes. The two production objects have 89
and 58 matching actual relocations respectively, including 91 newly
transferred pointer relocations. All four new global objects retain their
original addresses and sizes in the final ELF. The bounded private probes
and pre-extension sources are preserved in
`scratch/native_method_member_records_20261020/`.

Together these changes add 456 matched data bytes without changing the
1,030,936-byte denominator. The DOL passes the original SHA-1 check,
`ninja changes` reports no match regressions, the source extent audit passes,
and all 66 tests pass.
