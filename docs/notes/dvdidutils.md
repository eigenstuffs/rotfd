# Dolphin DVD disc-ID comparison

`src/dolphin/dvd/dvdidutils.c` recovers all 1 linked C functions at `0x800FB194..0x800FB28C` (248 bytes).

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| DVDCompareDiskID | 0x800FB194 | 0xF8 | global |

The [Pikmin 2 SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/dvd/dvdidutils.c) supplies the exact comparison. A zero first game-name byte acts as a wildcard, while either empty company code fails. Disk number and game version each support 0xFF as a wildcard. Bounded name comparisons call the original `strncmp` implementation; the game/company bytes retain signed-character promotion. Unlinked reference placeholders for ID generation and string length are omitted entirely.

This unit owns no data or BSS.

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dvd -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/dvdidutils` resolve all call, address, and small-data relocations, then compare every emitted byte against the original DOL. They verify 248 code bytes and 0 initialized data bytes exactly. No assembly is introduced or counted by this unit. Whole-DOL SHA-1 and native objdiff verification remain the integration checks.
