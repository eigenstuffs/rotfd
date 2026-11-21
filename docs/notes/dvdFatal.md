# Dolphin DVD fatal-message dispatch

`src/dolphin/dvd/dvdFatal.c` recovers all 1 linked C functions at `0x800FB28C..0x800FB2BC` (48 bytes).

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| __DVDPrintFatalMessage | 0x800FB28C | 0x30 | global |

The [Pikmin 2 SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/dvd/dvdFatal.c) supplies the exact optional callback dispatch. The linked function calls `FatalFunc` when the pointer is non-null. Message display and automatic-message configuration APIs are not linked here, so no replacement bodies or message tables are introduced.

The only owned object is local `FatalFunc`, four bytes at `.sbss` `0x80377A28..0x80377A2C`, alignment 8. The next four bytes are an alignment gap outside this unit. There is no initialized data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| FatalFunc | .sbss | 0x80377A28 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dvd -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/dvdFatal` resolve all call, address, and small-data relocations, then compare every emitted byte against the original DOL. They verify 48 code bytes and 0 initialized data bytes exactly. No assembly is introduced or counted by this unit. Whole-DOL SHA-1 and native objdiff verification remain the integration checks.
