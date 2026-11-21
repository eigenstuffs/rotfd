# Dolphin CARDDir

`src/dolphin/card/CARDDir.c` recovers 4 linked C functions and 612 text bytes.

| Function | Address | Size |
| --- | --- | --- |
| __CARDGetDirBlock | 0x801098E8 | 0x8 |
| WriteCallback | 0x801098F0 | 0xD0 |
| EraseCallback | 0x801099C0 | 0xC8 |
| __CARDUpdateDir | 0x80109A88 | 0xC4 |

The [Pikmin 2 reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDDir.c) supplies the exact algorithms; the [Melee reference](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDDir.c) corroborates their private callback linkage. The directory writer alternates the active and backup blocks, copies their 8 KiB contents and completes the erase/write callback chain. Directory update increments the check code, recalculates checksums, stores the CPU cache and erases the correct card sector before writing. The original reserved stack words are preserved for their observed callback frame sizes.

No data or BSS is owned; card state belongs to CARDBios. The shared ABI and already integrated source units are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches every text byte after relocation in the isolated `scratch/CARDDir` scripts. Reference files and hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
