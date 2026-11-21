# Dolphin SDK reset C fragments

Two source fragments recover four C functions from the original reset translation unit, preserving its interleaved hardware-reset assembly as original fallback.

| Fragment | Function | Address | Size |
| --- | --- | --- | --- |
| OSReset_register.c | OSRegisterResetFunction | 0x800F4744 | 0x84 |
| OSReset_system.c | __OSDoHotReset | 0x800F4838 | 0x48 |
| OSReset_system.c | OSResetSystem | 0x800F4880 | 0x278 |
| OSReset_system.c | OSGetResetCode | 0x800F4AF8 | 0x30 |

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSReset.c) provides the matching reset queue, callbacks, SRAM synchronization, thread cancellation, memory clearing, and reset-code algorithms. The target additionally clears the reboot flag at `0x800030E2` when clearing low-memory state; this matches the corresponding behavior in the [Pikmin 2 reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/os/OSReset.c). Other later SDK changes in that reference are absent here.

The reset-callback and thread-cancellation helpers inline as in the original. The complete thread layout and SRAM flags offset preserve the observed accesses. The reference's reserved eight-byte local area reproduces the original reset-system stack frame; its original source-level purpose is unknown. The linked target does not include `OSUnregisterResetFunction`, so it is omitted.

The original static `Reset` assembly at `0x800F47C8..0x800F4838` remains 112 bytes of fallback and contributes no recovered C progress. It is exposed as `OSResetHardware` for C linkage. The shared queue originally had static TU linkage; the registration fragment now defines global `OSResetFunctionQueue`, and the system fragment references it externally. The queue owns `.sbss` `0x80377938..0x80377940` (eight bytes). No initialized data is emitted.

GC/1.2.5n matches registration using `-O4,p -inline auto` and system using `-O4,p -opt nopeephole -inline auto`, with the normal Gekko C flags and `-i src/dolphin/os`. This records the settings that reproduce the split fragments, without claiming the original command-line or pragma history. Isolated relocation verification reports `TEXT 132 132` and `TEXT 752 752`, covering all 884 recovered C bytes. Whole-DOL SHA-1 remains the integration check. The next unit starts with reset-switch support at `0x800F4B28` and is outside these manifests.
