# Four additional native table groups

Four original-only `.data` intervals now extend the immediately preceding
accepted runtime-base-list sources:

| Source | Added interval | Added bytes | Contents |
| --- | --- | ---: | --- |
| `src/Game/native_rtti_base_lists_802B57B0.cpp` | `802B5990..802B5A48` | 184 | Native method record |
| `src/Game/native_rtti_base_lists_802B9710.cpp` | `802B9730..802B97B0` | 128 | Three small method records and two runtime-base lists |
| `src/Game/native_rtti_base_lists_802BEFF0.cpp` | `802BF0EC..802BF170` | 132 | Native method record |
| `src/Game/native_rtti_base_lists_802BFD80.cpp` | `802BFDBC..802BFE70` | 180 | LoadingScreen method table and six 12-byte member-pointer descriptors |

The respective compiler-owned extents are 664, 160, 384, and 240 bytes.
Each source preserves named function and runtime-type references and native
symbol identities. The numeric descriptor words are retained as the repeated
12-byte records observed at native consumer sites. These are partial data
splits; referenced methods, runtime descriptors, and other original
translation-unit material retain their separate owners.

GC/1.3.2 reproduces every original byte and all 99, 25, 60, and 32 actual
relocations in the four production objects. The added intervals contribute
125 of those pointer relocations. All nine new global objects retain their
original addresses and sizes in the final ELF. The bounded probes and
pre-extension sources are preserved in
`scratch/native_method_member_records_20261020/`.

Together these changes add 624 matched data bytes without changing the
1,030,936-byte denominator. The DOL passes the original SHA-1 check,
`ninja changes` shows no match regressions, the source extent audit passes,
and all 66 tests pass.
