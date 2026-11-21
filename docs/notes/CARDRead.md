# Dolphin CARDRead

`src/dolphin/card/CARDRead.c` recovers 4 linked C functions and 1,144 text bytes.

| Function | Address | Size |
| --- | --- | --- |
| __CARDSeek | 0x8010C588 | 0x1B8 |
| ReadCallback | 0x8010C740 | 0x130 |
| CARDReadAsync | 0x8010C870 | 0x148 |
| CARDRead | 0x8010C9B8 | 0x48 |

The [public SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDRead.c) supplies the matching source algorithms. The [Melee reference](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDRead.c) provides the older access-policy evidence. The seek helper follows allocation-table chains, validates bounds and updates the file cursor. The callbacks advance the buffer and block chain until completion or cancellation. The game uses the older Melee access check followed by __CARDIsPublic on permission denial, rather than the newer __CARDIsReadable helper. The rest follows the Pikmin 2 reconstruction, including the explicit signed truncation of the next sector boundary.

No initialized data or BSS is owned. State belongs to CARDBios and the caller's file information structures. The shared CARD ABI and previously integrated sources are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 1,144 text bytes after relocation in `scratch/CARDRead`. Reference files and SHA-256 hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
