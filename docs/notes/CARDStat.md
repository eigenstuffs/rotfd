# Dolphin CARDStat

`src/dolphin/card/CARDStat.c` recovers 4 linked C functions and 1,248 text bytes.

| Function | Address | Size |
| --- | --- | --- |
| UpdateIconOffsets | 0x8010CF30 | 0x1F8 |
| CARDGetStatus | 0x8010D128 | 0x12C |
| CARDSetStatusAsync | 0x8010D254 | 0x174 |
| CARDSetStatus | 0x8010D3C8 | 0x48 |

The [public SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDStat.c) supplies the matching source algorithms. The icon helper computes banner, per-icon, shared palette and data offsets from the stored formats. The get API uses the older access/public policy; the set API checks icon and comment bounds, copies metadata, updates the timestamp and persists the directory. The icon-offset helper remains private.

No initialized data or BSS is owned. State belongs to CARDBios and the caller's file information structures. The shared CARD ABI and previously integrated sources are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 1,248 text bytes after relocation in `scratch/CARDStat`. Reference files and SHA-256 hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
