# Dolphin DSP mailbox and task API

`src/dolphin/dsp/dsp.c` recovers 11 linked C functions and 744 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| DSPCheckMailToDSP | 0x80106110 | 0x10 |
| DSPCheckMailFromDSP | 0x80106120 | 0x10 |
| DSPReadMailFromDSP | 0x80106130 | 0x18 |
| DSPSendMailToDSP | 0x80106148 | 0x14 |
| DSPInit | 0x8010615C | 0xC4 |
| DSPCheckInit | 0x80106220 | 0x8 |
| DSPReset | 0x80106228 | 0x48 |
| DSPHalt | 0x80106270 | 0x40 |
| DSPGetDMAStatus | 0x801062B0 | 0x10 |
| DSPAddTask | 0x801062C0 | 0x70 |
| DSPAssertTask | 0x80106330 | 0xC8 |

The Melee DSP reconstruction supplies the mailbox, interrupt, reset, halt and task-priority algorithms. The later Pikmin 2 source confirms the added version registration in initialization. The original reports September 5, 2002 at 05:35:13 and retains its build-date diagnostic call before checking the initialization flag. Initial task pointers are reset in the original observed order. The hardware register bank uses an absolute volatile array at `0xCC005000`; a cast pointer expression changes register addressing and misses several original instructions. Task-state and priority fields are volatile, matching the reference layout and original repeated reads. `DSPAssertInt` inlines in the task assertion API; other unlinked public APIs are omitted.

The four string literals occupy `.data` `0x802CF000..0x802CF080` (128 bytes including padding). The version pointer occupies `.sdata` `0x80375D80..0x80375D84` (four bytes), followed by four external padding bytes. The private initialization flag occupies `.sbss` `0x80377C18..0x80377C1C` (four bytes), also followed by four external padding bytes. All three sections have alignment 8.

References are [Melee's DSP family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/dsp) and [Pikmin 2's DSP family](https://github.com/projectPiki/pikmin2/tree/main/src/Dolphin/dsp). Unchanged reference files and hashes are retained under `reference/`; these are public community reconstructions and no original SDK source archive provenance is claimed.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @1 | .data | 0x802CF000 | 0x45 |
| @13 | .data | 0x802CF048 | 0x1E |
| @14 | .data | 0x802CF068 | 0xC |
| @15 | .data | 0x802CF074 | 0x9 |
| __DSPVersion | .sdata | 0x80375D80 | 0x4 |
| __DSP_init_flag | .sbss | 0x80377C18 | 0x4 |

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dsp -Cpp_exceptions off` and ordinary peephole optimization matches all 744 text bytes and 132 initialized data bytes after relocations are resolved. The reproducible isolated probes are in `scratch/dsp`. No native assembly is counted. Full-DOL SHA-1 and native objdiff remain integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/dsp/dsp.c` | `.data` | `0x802CF000..0x802CF07D` (125 bytes) | `0x802CF07D..0x802CF080` (3 bytes) |

Current native objdiff credits `dolphin/dsp/dsp.c`: 133 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
