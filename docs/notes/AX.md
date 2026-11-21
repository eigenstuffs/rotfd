# Dolphin AX initialization

`src/dolphin/ax/AX.c` recovers 2 linked C functions and 112 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| AXInit | 0x80101264 | 0x3C |
| AXQuit | 0x801012A0 | 0x34 |

The Melee reconstruction supplies the initializer and shutdown sequence. The original initializer first registers its version string, identifying the September 5, 2002 release, then initializes allocation, voice parameter blocks, studio parameters, auxiliary buffers, command lists, and output. Shutdown calls each corresponding termination function in the same order.

`.data` is `0x802CA9B0..0x802CA9F4` (68 bytes), the version literal. `.sdata` is `0x80375D70..0x80375D74` (four bytes), its pointer. Both sections have alignment 8; each is followed by a four-byte gap outside this source split. No BSS is owned.

The direct references are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged reference files, file hashes and license information are preserved under `reference/`. Source differences described above are verified against the original game instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @1 | .data | 0x802CA9B0 | 0x44 |
| __AXVersion | .sdata | 0x80375D70 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/AX` resolve all applicable relocations and verify 112/112 code bytes and 72/72 initialized data bytes exactly against the original DOL. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.
