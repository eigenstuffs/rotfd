# Dolphin CARDOpen

`src/dolphin/card/CARDOpen.c` recovers 7 linked C functions and 1,108 text bytes.

| Function | Address | Size |
| --- | --- | --- |
| __CARDCompareFileName | 0x8010BD9C | 0x68 |
| __CARDAccess | 0x8010BE04 | 0x98 |
| __CARDIsPublic | 0x8010BE9C | 0x30 |
| __CARDGetFileNo | 0x8010BECC | 0x150 |
| CARDOpen | 0x8010C01C | 0x178 |
| CARDClose | 0x8010C194 | 0x54 |
| __CARDIsOpened | 0x8010C1E8 | 0x8 |

The [public SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDOpen.c) supplies the matching source algorithms. The older SDK access policy compares the disc game/company identifiers and separately allows public files. The directory lookup and access check are inlined into CARDOpen, while each original standalone helper is also retained. The unlinked CARDFastOpen API is omitted. The linked __CARDIsOpened function really returns FALSE unconditionally in this release; this is the observed implementation, not an invented placeholder.

No initialized data or BSS is owned. State belongs to CARDBios and the caller's file information structures. The shared CARD ABI and previously integrated sources are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 1,108 text bytes after relocation in `scratch/CARDOpen`. Reference files and SHA-256 hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
