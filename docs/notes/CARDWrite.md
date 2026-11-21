# Dolphin CARDWrite

`src/dolphin/card/CARDWrite.c` recovers 3 linked C functions and 820 text bytes.

| Function | Address | Size |
| --- | --- | --- |
| WriteCallback | 0x8010CA00 | 0x170 |
| EraseCallback | 0x8010CB70 | 0xB0 |
| CARDWriteAsync | 0x8010CC20 | 0x114 |

The [public SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDWrite.c) supplies the matching source algorithms. The [Melee reference](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDWrite.c) provides the older access-policy evidence. The write callback chains erase and page-write operations, advances the allocation chain and updates the file timestamp/directory on completion. The game uses the older __CARDAccess policy in place of the newer __CARDIsWritable helper. Only the three linked functions are included; the synchronous CARDWrite wrapper is unlinked in this image.

No initialized data or BSS is owned. State belongs to CARDBios and the caller's file information structures. The shared CARD ABI and previously integrated sources are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 820 text bytes after relocation in `scratch/CARDWrite`. Reference files and SHA-256 hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
