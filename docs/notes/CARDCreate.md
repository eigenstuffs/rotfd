# Dolphin CARDCreate

`src/dolphin/card/CARDCreate.c` recovers 3 linked C functions and 920 text bytes.

| Function | Address | Size |
| --- | --- | --- |
| CreateCallbackFat | 0x8010C1F0 | 0x130 |
| CARDCreateAsync | 0x8010C320 | 0x220 |
| CARDCreate | 0x8010C540 | 0x48 |

The [public SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDCreate.c) supplies the matching source algorithms. The callback initializes the directory entry after block allocation, copies game/company identifiers, sets the public flag and initial banner/icon fields, records the timestamp, and persists the directory. The API scans for duplicate names and free entries, checks available blocks, and starts allocation. Synchronous waiting and the original error paths are preserved.

No initialized data or BSS is owned. State belongs to CARDBios and the caller's file information structures. The shared CARD ABI and previously integrated sources are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 920 text bytes after relocation in `scratch/CARDCreate`. Reference files and SHA-256 hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
