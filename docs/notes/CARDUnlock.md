# Dolphin CARD unlock handshake

`src/dolphin/card/CARDUnlock.c` recovers six linked C functions and 4,704 PowerPC code bytes at `0x80108004..0x80109264`.

| Function | Address | Size |
| --- | --- | --- |
| bitrev | 0x80108004 | 0x16C |
| ReadArrayUnlock | 0x80108170 | 0x144 |
| DummyLen | 0x801082B4 | 0xC4 |
| __CARDUnlock | 0x80108378 | 0xB58 |
| InitCallback | 0x80108ED0 | 0x70 |
| DoneCallback | 0x80108F40 | 0x324 |

[Pikmin 2's reference](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDUnlock.c) provides the exact bit reversal, serial read, random-length generation, card challenge/response and DSP callback algorithms. [Melee's reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDUnlock.c) independently corroborates private helper linkage and the DSP program bytes. Random generation, seeding and the feedback-shift helpers inline. The seeding argument is `unsigned int`, preserving the reference compiler behavior. Original EXI traffic, cache operations, tick-based seed and DSP task configuration all remain in C.

The private `CardData` array at `.data` `0x802CF220..0x802CF380` is 352 bytes with **32-byte alignment**. It contains the original DSP program image copied unchanged from the public reference, and is verified as initialized data. These bytes are not counted as recovered PowerPC functions or C instruction coverage; the DSP instruction stream itself is not decompiled here. The private generator state `next` is initialized to one at `.sdata` `0x80375D90..0x80375D94`, alignment 8, followed by four external padding bytes. No BSS is owned.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 4,704 text bytes and 356 initialized data bytes after applicable relocations. The isolated scripts are in `scratch/CARDUnlock`; unchanged reference files and hashes are recorded under `reference/`. Full-DOL SHA-1 and native objdiff remain integration checks. The previously handed-off CARD BIOS and shared ABI were not changed.
