# Dolphin GX release range stub

`src/dolphin/gx/GXStubs.c` reconstructs the original empty release implementation of `__GXSetRange(float nearz, float fgSideX)` at `0x80116B28..0x80116B2C` (4 bytes). The [Melee GXStubs source](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXStubs.c) explicitly has this empty body; it is retained as original release behavior, not a replacement stub for an unknown algorithm. The neighboring GXTransform reference uses this helper in viewport-range setup, corroborating its position and purpose.

No data or BSS is owned. The isolated GC/1.2.5n probe reproduces the original `blr` exactly. No assembly source is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.

The central build now passes the original DOL SHA-1 and native objdiff code/data audit for these owned source fragments. All previously linked source units retain their matches.
