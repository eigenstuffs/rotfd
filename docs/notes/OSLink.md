# Dolphin SDK module-list initialization

`src/dolphin/os/OSLink.c` recovers `__OSModuleInit` at `0x800F3E98..0x800F3EB0` (24 bytes). This is the linked initialization fragment of the SDK module loader; other reference OSLink functions are not included in this coverage.

The unchanged algorithm from the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSLink.c) clears the module queue and string-table pointer. The compiler's absolute-address declarations bind the queue at `0x800030C8` and the string-table pointer at `0x800030D0`. Those reserved low-memory fields require no emitted data section.

GC/1.2.5n with the normal Gekko C flags, `-O4,p -inline auto`, produces all 24 original instruction bytes. The isolated verifier reports `TEXT 24 24`. The candidate includes no owned initialized or BSS data. Whole-DOL SHA-1 is the final integration check.
