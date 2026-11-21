# Dolphin SDK system-time helper

`src/dolphin/os/OSTime.c` recovers `__OSGetSystemTime` at `0x800F6C14..0x800F6C78` (100 C bytes). The unchanged algorithm from the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSTime.c) disables interrupts, adds the signed 64-bit adjustment stored at `0x800030D8` to the hardware time, restores interrupt state, and returns the adjusted value.

`OSGetTime` at `0x800F6BF4..0x800F6C0C` and `OSGetTick` at `0x800F6C0C..0x800F6C14` remain original assembly fallback; neither contributes to C progress. Other reference calendar and time-setting routines are not in this linked group and are omitted. The adjustment is reserved low-memory state, so this C fragment emits no data objects.

GC/1.2.5n with the normal Gekko C flags and `-O4,p -opt nopeephole -inline auto` produces all original instructions and call relocations. The isolated verifier reports `TEXT 100 100`. Whole-DOL SHA-1 remains the integration check.
