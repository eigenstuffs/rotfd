# Dolphin SDK system-call setup

`src/dolphin/os/OSSync.c` recovers `__OSInitSystemCall` at `0x800F5934..0x800F5998` (100 C bytes). The unchanged algorithm from the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSSync.c) copies the system-call vector to `0x80000C00`, flushes the data cache, synchronizes using the C compiler intrinsic, and invalidates the instruction cache.

The vector itself at `0x800F5914..0x800F5934` remains original assembly fallback and does not count as recovered C. Its exported start label is `0x800F5914`; its end label is `0x800F5930`, before the trailing no-op. The C copy length is computed from these two original labels, preserving the 28-byte handler body. No emitted data objects are owned by the C fragment.

GC/1.2.5n with the normal Gekko C flags and `-O4,p -opt nopeephole -inline auto` matches all 100 instruction bytes after relocation. The isolated verifier reports `TEXT 100 100`. Whole-DOL SHA-1 remains the integration check.
