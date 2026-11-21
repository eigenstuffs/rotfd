# Dolphin CARD consistency checks

`src/dolphin/card/CARDCheck.c` recovers seven linked C functions and 3,944 code bytes at `0x80109B4C..0x8010AAB4`.

| Function | Address | Size |
| --- | --- | --- |
| __CARDCheckSum | 0x80109B4C | 0x1B0 |
| VerifyID | 0x80109CFC | 0x284 |
| VerifyDir | 0x80109F80 | 0x240 |
| VerifyFAT | 0x8010A1C0 | 0x284 |
| __CARDVerify | 0x8010A444 | 0x8C |
| CARDCheckExAsync | 0x8010A4D0 | 0x590 |
| CARDCheck | 0x8010AA60 | 0x54 |

The [Pikmin 2 reference](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDCheck.c) supplies the exact checksum, card identification, duplicate-directory and allocation-table verification algorithms. The asynchronous consistency check validates directory chains, checks block ownership, repairs orphan allocation entries, recalculates checksums and writes the appropriate metadata copy. The identity check preserves the SRAM flash-ID comparison and signed 64-bit pseudo-random recurrence. The SRAM extension layout comes from the already recovered OSRtc unit. No algorithms are simplified or replaced with constant results.

No initialized data or BSS is owned. The shared CARD ABI and previously integrated sources are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 3,944 text bytes after relocation in `scratch/CARDCheck`. Reference hashes are recorded under `reference/pikmin2-sdk`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
