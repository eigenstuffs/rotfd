# Dolphin AX profile accessor

`src/dolphin/ax/AXProf.c` recovers 1 linked C functions and 72 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __AXGetCurrentProfile | 0x80103FA0 | 0x48 |

The TTYD reconstruction supplies the exact circular-buffer profile accessor. The original linked function checks the initialization flag, advances the current index modulo the configured capacity and returns the current 56-byte profile slot. The initializer and profile-reset API are not linked in this image. Their absence does not justify replacing the retained getter with a constant return; all observed accesses remain in the C implementation.

Four private values occupy `.sbss` `0x80377BF8..0x80377C08` (16 bytes), alignment 8: profile buffer, capacity, current index and initialization flag. No initialized data or large BSS is owned.

References are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged source files, hashes and license information are recorded under `reference/`. Differences above are derived from the original instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __AXProfile | .sbss | 0x80377BF8 | 0x4 |
| __AXMaxProfiles | .sbss | 0x80377BFC | 0x4 |
| __AXCurrentProfile | .sbss | 0x80377C00 | 0x4 |
| __AXProfileInitialized | .sbss | 0x80377C04 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off` and ordinary peephole optimization. The isolated scripts in `scratch/AXProf` resolve applicable relocations and verify all 72 text bytes and 0 initialized data bytes exactly. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.
