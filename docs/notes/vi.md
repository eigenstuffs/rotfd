# Dolphin video interface

`src/dolphin/vi/vi.c` recovers all 15 linked C functions at `0x800FB4FC..0x800FCF94` (6,808 bytes). The unit handles timing selection, display configuration, interrupt-driven register updates, framebuffer addressing, and scan position. No assembly fallback is needed in this range.

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| __VIRetraceHandler | 0x800FB4FC | 0x230 | local |
| getTiming | 0x800FB72C | 0xA0 | local |
| __VIInit | 0x800FB7CC | 0x200 | global |
| VIInit | 0x800FB9CC | 0x4B0 | global |
| VIWaitForRetrace | 0x800FBE7C | 0x54 | global |
| setFbbRegs | 0x800FBED0 | 0x2D4 | local |
| setVerticalRegs | 0x800FC1A4 | 0x1A0 | local |
| VIConfigure | 0x800FC344 | 0x828 | global |
| VIFlush | 0x800FCB6C | 0x130 | global |
| VISetNextFrameBuffer | 0x800FCC9C | 0x6C | global |
| VISetBlack | 0x800FCD08 | 0x7C | global |
| getCurrentFieldEvenOdd | 0x800FCD84 | 0x68 | local |
| VIGetNextField | 0x800FCDEC | 0xA8 | global |
| VIGetCurrentLine | 0x800FCE94 | 0x98 | global |
| VIGetTvFormat | 0x800FCF2C | 0x68 | global |

The [Pikmin 2 VI reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/vi/vi.c) provides the ten timing modes, coefficient table, and retained algorithms. The target version string identifies the September 5, 2002 VI release; the later reference adds a position callback absent from this game. In the target, either position interrupt immediately restores the supplied context and returns. There is no `PositionCallback` state. The original panic source line is 1884.

The [Melee VI reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/vi/vi.c) provides the earlier direct `getCurrentHalfLine` implementation and the four-byte reserved local array in `VIGetNextField`. The latter reproduces the target's 0x20-byte stack frame; its original purpose is unknown. Retained helpers are explicitly inline where the final linked image contains only their call-site bodies. Unlinked public functions and incomplete reference placeholders are omitted.

The local ABI header preserves 38-byte timing entries (ten total), the 88-byte display state, the 60-byte GX render mode, signed SRAM display offset, and the absolute volatile VI register array. Constants are source-level register definitions. Compilation preserves all instruction ordering and hardware accesses.

`.data` is `0x802CA4B0..0x802CA880` (976 bytes), including the version literal, 380-byte timing table, 50-byte taps, two switch jump tables, six caution messages, and the panic message. `.sdata` is `0x80375D28..0x80375D34` (12 bytes), with a version pointer and five-byte filename plus padding; four following alignment bytes are outside this unit. `.bss` is `0x80319788..0x803198D0` (328 bytes): two 118-byte register arrays each followed by two padding bytes, then the 88-byte display state. `.sbss` is `0x80377A40..0x80377A98` (88 bytes), including the two eight-byte changed-register masks and the inline caution function's four-byte static flag. Four bytes at `0x80377A74` pad the second mask's alignment. All sections have alignment 8, and static linkage is recorded for every owned private symbol.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @3 | .data | 0x802CA4B0 | 0x44 |
| timing | .data | 0x802CA4F4 | 0x17C |
| taps | .data | 0x802CA670 | 0x32 |
| @76 | .data | 0x802CA6A4 | 0x6C |
| @429 | .data | 0x802CA710 | 0x29 |
| @430 | .data | 0x802CA73C | 0x29 |
| @431 | .data | 0x802CA768 | 0x29 |
| @432 | .data | 0x802CA794 | 0x29 |
| @433 | .data | 0x802CA7C0 | 0x29 |
| @434 | .data | 0x802CA7EC | 0x29 |
| @436 | .data | 0x802CA818 | 0x4B |
| @506 | .data | 0x802CA864 | 0x1C |
| regs | .bss | 0x80319788 | 0x76 |
| shdwRegs | .bss | 0x80319800 | 0x76 |
| HorVer | .bss | 0x80319878 | 0x58 |
| __VIVersion | .sdata | 0x80375D28 | 0x4 |
| @435 | .sdata | 0x80375D2C | 0x5 |
| IsInitialized | .sbss | 0x80377A40 | 0x4 |
| retraceCount | .sbss | 0x80377A44 | 0x4 |
| flushFlag | .sbss | 0x80377A48 | 0x4 |
| retraceQueue | .sbss | 0x80377A4C | 0x8 |
| PreCB | .sbss | 0x80377A54 | 0x4 |
| PostCB | .sbss | 0x80377A58 | 0x4 |
| encoderType | .sbss | 0x80377A5C | 0x4 |
| displayOffsetH | .sbss | 0x80377A60 | 0x2 |
| displayOffsetV | .sbss | 0x80377A62 | 0x2 |
| changeMode | .sbss | 0x80377A64 | 0x4 |
| changed | .sbss | 0x80377A68 | 0x8 |
| shdwChangeMode | .sbss | 0x80377A70 | 0x4 |
| shdwChanged | .sbss | 0x80377A78 | 0x8 |
| CurrTiming | .sbss | 0x80377A80 | 0x4 |
| CurrTvMode | .sbss | 0x80377A84 | 0x4 |
| NextBufAddr | .sbss | 0x80377A88 | 0x4 |
| CurrBufAddr | .sbss | 0x80377A8C | 0x4 |
| FBSet | .sbss | 0x80377A90 | 0x4 |
| message$245 | .sbss | 0x80377A94 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/vi -Cpp_exceptions off`, with peephole optimization enabled. `scratch/vi/compile.py` and `scratch/vi/verify.py` resolve calls, address loads, small-data references, and switch-table relocations before comparing every emitted code and initialized data byte against the original DOL. The isolated result is 6,808/6,808 code bytes and 988/988 initialized data bytes. The manifest records all literal and jump-table object sizes separately. Whole-DOL SHA-1 and native objdiff remain the integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/vi/vi.c` | `.sdata` | `0x80375D28..0x80375D31` (9 bytes) | `0x80375D31..0x80375D34` (3 bytes) |

Current native objdiff credits `dolphin/vi/vi.c`: 1,401 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
