# MetroTRK target continuation

`src/MetroTRK/targcont.c` recovers the 52-byte TRKTargetContinue function at 0x8011E5F8..0x8011E62C. It marks the target running, unreserves the EXI2 port, invokes the original native swap-and-run routine, reserves the port on return, and reports success. The [Melee continuation source](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/targcont.c) provides the same complete control flow.

There is no initialized data or BSS. GC/1.3.2 with the ordinary MetroTRK `-inline auto,deferred` flags matches every instruction and relocation. The complete candidate is config/GSQE78/candidates/MetroTRK-targcont.json. TRKSwapAndGo remains original native assembly; this C wrapper adds no assembly coverage. The integrated source passes whole-DOL byte equality, native objdiff code/data checks, and the original-source regression audit.
