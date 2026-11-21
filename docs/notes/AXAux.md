# Dolphin AX auxiliary mixing buffers

`src/dolphin/ax/AXAux.c` recovers 13 linked C functions and 1,160 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __AXAuxInit | 0x8010179C | 0xE4 |
| __AXAuxQuit | 0x80101880 | 0x10 |
| __AXGetAuxAInput | 0x80101890 | 0x34 |
| __AXGetAuxAInputDpl2 | 0x801018C4 | 0x20 |
| __AXGetAuxAOutput | 0x801018E4 | 0x1C |
| __AXGetAuxAOutputDpl2R | 0x80101900 | 0x20 |
| __AXGetAuxAOutputDpl2Ls | 0x80101920 | 0x20 |
| __AXGetAuxAOutputDpl2Rs | 0x80101940 | 0x20 |
| __AXGetAuxBInput | 0x80101960 | 0x34 |
| __AXGetAuxBOutput | 0x80101994 | 0x1C |
| __AXGetAuxBForDPL2 | 0x801019B0 | 0x1C |
| __AXGetAuxBOutputDPL2 | 0x801019CC | 0x1C |
| __AXProcessAux | 0x801019E8 | 0x23C |

The newer TTYD reconstruction supplies the exact auxiliary-buffer algorithms, including Dolby Pro Logic II channel routing and separate two-slot and three-slot buffer positions. Unlike the older Melee reconstruction, the target has all six extra Dolby buffer-address helpers and tests the correct auxiliary-B callback. The callback registration functions are not linked and are omitted. All active audio-buffer invalidation and flush calls are preserved.

`.bss` is `0x80319A20..0x8031C720` (11,520 bytes), two arrays of 3 x 480 signed 32-bit samples. This section requires **32-byte alignment**, matching the source attributes. `.sbss` is `0x80377B50..0x80377B84` (52 bytes), thirteen private four-byte pointers/counters, alignment 8; the four bytes following it are external padding. No initialized data is owned.

The direct references are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged reference files, file hashes and license information are preserved under `reference/`. Source differences described above are verified against the original game instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __AXBufferAuxA | .bss | 0x80319A20 | 0x1680 |
| __AXBufferAuxB | .bss | 0x8031B0A0 | 0x1680 |
| __AXCallbackAuxA | .sbss | 0x80377B50 | 0x4 |
| __AXCallbackAuxB | .sbss | 0x80377B54 | 0x4 |
| __AXContextAuxA | .sbss | 0x80377B58 | 0x4 |
| __AXContextAuxB | .sbss | 0x80377B5C | 0x4 |
| __AXAuxADspWrite | .sbss | 0x80377B60 | 0x4 |
| __AXAuxADspRead | .sbss | 0x80377B64 | 0x4 |
| __AXAuxBDspWrite | .sbss | 0x80377B68 | 0x4 |
| __AXAuxBDspRead | .sbss | 0x80377B6C | 0x4 |
| __AXAuxDspWritePosition | .sbss | 0x80377B70 | 0x4 |
| __AXAuxDspReadPosition | .sbss | 0x80377B74 | 0x4 |
| __AXAuxDspWritePositionDpl2 | .sbss | 0x80377B78 | 0x4 |
| __AXAuxDspReadPositionDpl2 | .sbss | 0x80377B7C | 0x4 |
| __AXAuxCpuReadWritePosition | .sbss | 0x80377B80 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/AXAux` resolve all applicable relocations and verify 1,160/1,160 code bytes and 0/0 initialized data bytes exactly against the original DOL. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.
