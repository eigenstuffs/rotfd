# Dolphin AX command-list generation

`src/dolphin/ax/AXCL.c` recovers 6 linked C functions and 1,840 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __AXGetCommandListCycles | 0x80101C24 | 0x8 |
| __AXGetCommandListAddress | 0x80101C2C | 0x3C |
| __AXNextFrame | 0x80101C68 | 0x6B0 |
| __AXClInit | 0x80102318 | 0x24 |
| __AXClQuit | 0x8010233C | 0x4 |
| AXSetMode | 0x80102340 | 0x14 |

The newer TTYD reconstruction supplies the exact command-list builder, including Dolby channel routing, compressor commands and cycle budgeting. The source emits source-level DSP command words, buffer addresses and cycle totals; it is not generated PowerPC assembly. The command-list write helper inlines into callers. The real release-build shutdown function returns without work and is retained as present in the original image. Unlinked mode getter and compressor setter functions are omitted.

`.bss` is `0x8031C720..0x8031CD20` (1,536 bytes), two arrays of 384 command words, alignment 8. `.sbss` is `0x80377B88..0x80377B9C` (20 bytes), five four-byte values, alignment 8; the four following bytes remain external padding. The mode value is global and the other state private. The compressor coefficient table is externally referenced and owned by the separate AXComp data unit.

The direct references are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged reference files, file hashes and license information are preserved under `reference/`. Source differences described above are verified against the original game instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __AXCommandList | .bss | 0x8031C720 | 0x600 |
| __AXCommandListPosition | .sbss | 0x80377B88 | 0x4 |
| __AXClWrite | .sbss | 0x80377B8C | 0x4 |
| __AXCommandListCycles | .sbss | 0x80377B90 | 0x4 |
| __AXCompressor | .sbss | 0x80377B94 | 0x4 |
| __AXClMode | .sbss | 0x80377B98 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/AXCL` resolve all applicable relocations and verify 1,840/1,840 code bytes and 0/0 initialized data bytes exactly against the original DOL. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.
