# MetroTRK main entry

`src/MetroTRK/main_TRK.c` recovers both linked C functions at 0x8011E120..0x8011E16C (76 bytes). TRKTargetCPUMinorType returns the original 0x54 processor subtype. TRK_main initializes the nub, emits its greeting and enters the event loop on success, then always terminates the nub and returns its final result through the original static error variable.

The [Melee main source](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/main_TRK.c) matches the complete control flow and source order. Unlike neighboring target code, this small unit uses `-inline on` with GC/1.3.2; deferred function order would differ. Other compiler options are the ordinary MetroTRK settings recorded in the candidate.

The source owns static TRK_mainError, four BSS bytes at 0x8033B008..0x8033B00C with section alignment 8. The following four bytes to 0x8033B010 are original external alignment padding. There is no initialized data. The isolated compilation and relocation check reproduce all 76 code bytes exactly. The complete function and symbol manifest is config/GSQE78/candidates/MetroTRK-main_TRK.json. The integrated source passes whole-DOL byte equality, native objdiff code/data checks, and the original-source regression audit.
