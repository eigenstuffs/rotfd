# Dolphin SDK reset-switch support

`src/dolphin/os/OSResetSW.c` recovers three C functions at `0x800F4B28..0x800F4ED4` (940 bytes): `__OSResetSWInterruptHandler` (244), `OSGetResetButtonState` (664), and its `OSGetResetSwitchState` compatibility wrapper (32).

The unchanged algorithms from the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSResetSW.c) debounce the reset input, preserve the release interval, invoke and clear the callback, and implement the low-memory game-choice timer. Time-conversion macros retain the target's integer operation order and signed 64-bit time comparisons. PI registers, the bus clock, and game-choice byte use their original absolute-address bindings.

Local small BSS occupies `0x80377940..0x80377960` (32 bytes including padding): `ResetCallback` at `0x80377940` (4), `Down` at `0x80377944` (4), `LastState` at `0x80377948` (4), four alignment bytes, `HoldUp` at `0x80377950` (8), and `HoldDown` at `0x80377958` (8). No initialized data or assembly is emitted.

GC/1.2.5n with the normal Gekko C flags and `-O4,p -inline auto -i src/dolphin/os` matches every instruction. The isolated verifier resolves all text and small-data relocations and reports `TEXT 940 940`. The candidate preserves all five local object sizes and scopes. Whole-DOL SHA-1 remains the integration check. The next unit begins at `0x800F4ED4`, with SRAM support.
