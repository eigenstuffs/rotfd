# Dolphin AX studio parameter block

`src/dolphin/ax/AXSPB.c` recovers 5 linked C functions and 1,224 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __AXGetStudio | 0x80102A14 | 0xC |
| __AXPrintStudio | 0x80102A20 | 0x3F8 |
| __AXSPBInit | 0x80102E18 | 0x2C |
| __AXSPBQuit | 0x80102E44 | 0x4 |
| __AXDepopVoice | 0x80102E48 | 0x94 |

The newer TTYD reconstruction supplies the exact studio parameter initialization, printing and voice depopulation algorithms. The depopulation fade helper inlines into the studio writer. The real release shutdown function returns without work, as in the original image.

The 54-byte studio parameter block begins at `0x80321540`, with **32-byte alignment**. The ELF section has size 54; the original split extends to `0x80321578` (56 bytes), including two zero padding bytes. Eight more padding bytes precede the next unit and are not owned here. Nine private signed accumulation values occupy `.sbss` `0x80377BC0..0x80377BE4` (36 bytes), alignment 8, followed by four bytes outside the split. There is no initialized data.

References are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged source files, hashes and license information are recorded under `reference/`. Differences above are derived from the original instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __AXStudio | .bss | 0x80321540 | 0x36 |
| __AXSpbAL | .sbss | 0x80377BC0 | 0x4 |
| __AXSpbAR | .sbss | 0x80377BC4 | 0x4 |
| __AXSpbAS | .sbss | 0x80377BC8 | 0x4 |
| __AXSpbAAL | .sbss | 0x80377BCC | 0x4 |
| __AXSpbAAR | .sbss | 0x80377BD0 | 0x4 |
| __AXSpbAAS | .sbss | 0x80377BD4 | 0x4 |
| __AXSpbABL | .sbss | 0x80377BD8 | 0x4 |
| __AXSpbABR | .sbss | 0x80377BDC | 0x4 |
| __AXSpbABS | .sbss | 0x80377BE0 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off` and ordinary peephole optimization. The isolated scripts in `scratch/AXSPB` resolve applicable relocations and verify all 1,224 text bytes and 0 initialized data bytes exactly. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/ax/AXSPB.c` | `.bss` | `0x80321540..0x80321576` (54 bytes) | `0x80321576..0x80321578` (2 bytes) |

Current native objdiff credits `dolphin/ax/AXSPB.c`: 90 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
