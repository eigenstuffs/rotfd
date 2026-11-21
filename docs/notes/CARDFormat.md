# Dolphin CARD formatting

`src/dolphin/card/CARDFormat.c` recovers three linked C functions and 2,032 code bytes at `0x8010B5AC..0x8010BD9C`.

| Function | Address | Size |
| --- | --- | --- |
| FormatCallback | 0x8010B5AC | 0x144 |
| __CARDFormatRegionAsync | 0x8010B6F0 | 0x658 |
| CARDFormat | 0x8010BD48 | 0x54 |

The [Pikmin 2 reference](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDFormat.c) supplies the exact formatting state machine and metadata initialization. The code constructs the serial/checksum fields from SRAM, VI status and the original signed 64-bit clock recurrence, builds both directory and allocation-table copies, flushes them, and erases/writes the five system blocks through callbacks. Original error propagation and synchronous waiting remain intact. This recovery compiles the game's code; it does not operate on a memory card during verification.

No initialized data or BSS is owned, and the shared CARD ABI is unchanged. SRAM structure layouts are copied from the already recovered OSRtc declarations. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 2,032 text bytes after relocation in `scratch/CARDFormat`. Unchanged reference files and hashes are recorded under `reference/pikmin2-sdk`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
