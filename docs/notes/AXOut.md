# Dolphin AX output scheduling

`src/dolphin/ax/AXOut.c` recovers 9 linked C functions and 1,728 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __AXOutNewFrame | 0x80102354 | 0x188 |
| __AXOutAiCallback | 0x801024DC | 0x68 |
| __AXDSPInitCallback | 0x80102544 | 0xC |
| __AXDSPResumeCallback | 0x80102550 | 0x58 |
| __AXDSPDoneCallback | 0x801025A8 | 0xC |
| __AXOutInitDSP | 0x801025B4 | 0xC4 |
| __AXOutInit | 0x80102678 | 0x340 |
| __AXOutQuit | 0x801029B8 | 0x54 |
| AXRegisterCallback | 0x80102A0C | 0x8 |

The Melee reconstruction supplies the target's two-buffer output scheduling, DMA callbacks and DSP startup/shutdown flow. The newer TTYD implementation uses three buffers and a different threaded shutdown path; those are absent here. A private volatile debug-stepping value and its zero initialization are present in the original and corroborated by the newer reference. `DSPCheckInit` returns a signed Boolean, as confirmed by the target comparison instruction. The DSP task and DRAM image retain their original global linkage but use specific names `__AXDSPTask` and `__AXDramImage` to avoid generic symbol collisions.

The BSS section is `0x8031CD20..0x80321528` (18,440 bytes), alignment 8. The next studio buffer begins at `0x80321540`; its preceding 24 bytes are outside this source split. Small BSS is `0x80377BA0..0x80377BC0` (32 bytes), alignment 8. There is no initialized data. The DSP program at `0x802CC520` and its halfword byte-length at `0x80375D78` remain external data; this unit does not claim their instruction stream as recovered C.

References are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged source files, hashes and license information are recorded under `reference/`. Differences above are derived from the original instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __AXOutBuffer | .bss | 0x8031CD20 | 0x500 |
| __AXOutSBuffer | .bss | 0x8031D220 | 0x280 |
| __AXLocalProfile | .bss | 0x8031D4A0 | 0x38 |
| __AXDSPTask | .bss | 0x8031D4D8 | 0x50 |
| __AXDramImage | .bss | 0x8031D528 | 0x4000 |
| __AXOutFrame | .sbss | 0x80377BA0 | 0x4 |
| __AXOutDspReady | .sbss | 0x80377BA4 | 0x4 |
| __AXOsTime | .sbss | 0x80377BA8 | 0x8 |
| __AXUserFrameCallback | .sbss | 0x80377BB0 | 0x4 |
| __AXDSPInitFlag | .sbss | 0x80377BB4 | 0x4 |
| __AXDSPDoneFlag | .sbss | 0x80377BB8 | 0x4 |
| __AXDebugSteppingMode | .sbss | 0x80377BBC | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off` and ordinary peephole optimization. The isolated scripts in `scratch/AXOut` resolve applicable relocations and verify all 1,728 text bytes and 0 initialized data bytes exactly. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.
