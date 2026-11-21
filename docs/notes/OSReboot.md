# Dolphin SDK reboot C functions

`src/dolphin/os/OSReboot.c` recovers three C functions at `0x800F43EC..0x800F4744` (856 bytes).

| Function | Address | Size |
| --- | --- | --- |
| Callback (local) | 0x800F43EC | 0xC |
| __OSReboot | 0x800F43F8 | 0x340 |
| OSSetSaveRegion | 0x800F4738 | 0xC |

The [Pikmin 2 SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/os/OSReboot.c) supplies the matching DVD preparation, stream shutdown, timed reads, and apploader algorithm. Its helper checks and streaming test inline into reboot. The earlier Melee reference follows a different boot procedure and does not match. Exact DVD command-block and disk-ID layouts come from the same Pikmin 2 reference.

The target clears the two legacy boot words at `0x817FFFFC` and `0x817FFFF8`; the first is subsequently read as the fallback hot-reset code. It does not store the incoming reset-code parameter at `0x800030F0`. This observed target behavior is preserved explicitly. The reboot flag at `0x800030E2`, saved-region fields, and bus-clock timeout remain bound to their original fixed addresses. The complete context and three DVD command blocks reproduce the original `0x380`-byte stack frame without a padding array.

The 16-byte processor entry at `0x800F43DC..0x800F43EC` remains original assembly fallback. It synchronizes and branches to the loaded entry point. Its original static `Run` symbol is exposed as `OSRebootRun` solely to connect the recovered C call; it contributes no C progress.

Owned BSS is the 32-byte, 32-byte-aligned local `Header` at `0x80318B20..0x80318B40`. Small BSS contains local `SaveStart`, `SaveEnd`, and `Prepared` at `0x80377928..0x80377934`, each four bytes. The additional four-byte gap before the next unit is alignment padding, not part of `Prepared`. No initialized data is emitted.

GC/1.2.5n matches with the normal Gekko C flags and `-O4,p -opt nopeephole -inline auto -i src/dolphin/os`. Every relocation and all 856 instruction bytes are checked against the original DOL by `scratch/OSReboot/verify.py`, which reports `TEXT 856 856`. Whole-DOL SHA-1 remains the integration check.
