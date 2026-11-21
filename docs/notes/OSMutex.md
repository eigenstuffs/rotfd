# Dolphin SDK mutex support

`src/dolphin/os/OSMutex.c` recovers the four linked C functions at `0x800F4190..0x800F43DC` (588 bytes).

| Function | Address | Size |
| --- | --- | --- |
| OSInitMutex | 0x800F4190 | 0x38 |
| OSLockMutex | 0x800F41C8 | 0xDC |
| OSUnlockMutex | 0x800F42A4 | 0xC8 |
| __OSUnlockAllMutex | 0x800F436C | 0x70 |

The unchanged release algorithms and queue macros come from the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSMutex.c). The complete thread structure prefix and mutex layout preserve the original ownership, recursive count, sleep queue, and priority-inheritance accesses. Reference condition-variable, try-lock, and debug-check routines are not present in this linked region and are omitted.

GC/1.2.5n matches with the normal Gekko C flags and `-O4,p -inline auto -i src/dolphin/os`. No data sections or assembly are emitted. The isolated verifier resolves every call and compares all instructions against the original DOL, reporting `TEXT 588 588`. The candidate includes the recovered thread API symbol mappings. Whole-DOL SHA-1 remains the integration check.
