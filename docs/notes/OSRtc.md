# Dolphin SDK SRAM services

`src/dolphin/os/OSRtc.c` recovers all 13 linked C functions in the SRAM unit at `0x800F4ED4..0x800F57EC` (2328 bytes).

| Function | Address | Size |
| --- | --- | --- |
| WriteSramCallback | 0x800F4ED4 | 0x60 |
| WriteSram | 0x800F4F34 | 0x118 |
| __OSInitSram | 0x800F504C | 0x134 |
| __OSLockSram | 0x800F5180 | 0x5C |
| __OSLockSramEx | 0x800F51DC | 0x5C |
| UnlockSram | 0x800F5238 | 0x308 |
| __OSUnlockSram | 0x800F5540 | 0x24 |
| __OSUnlockSramEx | 0x800F5564 | 0x24 |
| __OSSyncSram | 0x800F5588 | 0x10 |
| OSGetSoundMode | 0x800F5598 | 0x80 |
| OSSetSoundMode | 0x800F5618 | 0xA4 |
| OSGetWirelessID | 0x800F56BC | 0x84 |
| OSSetWirelessID | 0x800F5740 | 0xAC |

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSRtc.c) supplies the matching algorithms, SRAM structure layout, EXI transactions, and checksum handling. `ReadSram` and `LockSram` inline into the linked functions. Unlinked RTC, ROM, progressive-mode, language, and other reference APIs are omitted. The legacy callback's unspecified parameter list is preserved. The two unlock wrappers explicitly return `UnlockSram`'s result, reproducing the target return register. The reference's four reserved bytes in `OSGetWirelessID` reproduce its original frame; their source-level purpose is unknown.

The only owned data is local `Scb`, a 32-byte-aligned 84-byte control structure at `.bss` `0x80318B40..0x80318B94`: a 64-byte SRAM image followed by offset, saved interrupt state, lock state, synchronization result, and callback pointer. Its actual size is 84, not the following alignment gap. No initialized data or assembly is emitted.

GC/1.2.5n matches with the normal Gekko C flags and `-O4,p -inline auto -i src/dolphin/os`. The isolated verifier resolves every call and BSS relocation and reports `TEXT 2328 2328`. The candidate records all function scopes, the complete control-block size, and external EXI mappings. Whole-DOL SHA-1 remains the integration check.
