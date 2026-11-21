# Type-registry diagnostic strings at 802AE024

`src/Game/type_registry.cpp` now owns its two following diagnostic strings:
`Anonymous New` at 802AE024 and `ConsoleInterp_Z.h` at 802AE034. The complete
readonly pool grows from 770 to 806 bytes. The 32 string bytes and four bytes
of natural compiler alignment add 36 matching data bytes. The final two bytes
at 802AE046 retain explicit original ownership and receive no source credit.

The original 1,668 code bytes, 770 pool bytes, 225 actual relocations, three
compiler category entries and every previous symbol extent are unchanged.
All undefined symbols remain GLOBAL; no weak functions or exception data are
emitted. The input census found 112 relevant references in 31 consumers.
The original allocator at 8020B908 also uses the unchanged registry base plus
0x304 at 14 allocation sites. The appended arrays therefore remain force-active.

The immutable evidence is in
`scratch/type_registry_string_append_20261020_parallel/`.
`scratch/type_registry36_integration_20261020/verify_production.py --linked`
verifies the complete production object, unchanged consumers, native symbol
extents, original residual and DOL hash. The standard build, `ninja changes`,
source extent audit and all 66 tests pass.
