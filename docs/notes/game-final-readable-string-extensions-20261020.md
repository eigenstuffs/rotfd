# Nine trailing strings in eight existing pools

Eight accepted source pools now include nine following strings and their natural
internal alignment. The change adds 151 matching data bytes: 134 string bytes
and 17 alignment bytes. The original prefixes and all caller relocations remain
unchanged. Seven explicit original residuals retain 23 bytes outside source
ownership; those bytes receive no source credit.

| Source pool start | New exclusive end | Added bytes |
| --- | --- | ---: |
| 8029C998 | 8029C9B2 | 16 |
| 802A28A8 | 802A28F8 | 30 |
| 802A4A38 | 802A4A9F | 21 |
| 802ACAD8 | 802ACCBF | 13 |
| 802ACD08 | 802ACECB | 17 |
| 802AD4F8 | 802AD50E | 12 |
| 802AD510 | 802AD579 | 30 |
| 802AD8F8 | 802AD90F | 12 |

The added arrays are `VolumeAgent_Z`, `BaseObject_Z`, `Activable_Z`,
`OO:Agent_Z_UseNode`, ` MovieName`, `Viewport_Z.cpp`, `SHOW_%02d`,
`Unable to load script %s ...`, and `LodAgent_Z`. The leading space in
` MovieName` is intentional. Each complete array retains its native GLOBAL
identity and is force-active. The compiler emits only readonly data in these
eight objects, with no code, relocations, weak definitions, or undefined symbols.

The input census records 159 relevant relocations in 28 consumer objects,
including 15 direct references to the new strings. Three original RTTI name
pointers also agree with the actual relocations and reference DOL. All 28
consumer objects remain unchanged after integration.

The immutable private evidence is in
`scratch/readable_final_strings_20261020_parallel/`.
`scratch/final_strings151_integration_20261020/verify_production.py --linked`
checks all eight complete production objects, GLOBAL extents, original residuals,
unique active ownership and the full DOL hash. The standard build,
`ninja changes`, source extent audit and all 66 tests pass.
