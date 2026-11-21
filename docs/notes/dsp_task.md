# Dolphin DSP task scheduler

`src/dolphin/dsp/dsp_task.c` recovers 5 linked C functions and 2,180 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __DSPHandler | 0x80106448 | 0x424 |
| __DSP_exec_task | 0x8010686C | 0x1A0 |
| __DSP_boot_task | 0x80106A0C | 0x18C |
| __DSP_insert_task | 0x80106B98 | 0xA0 |
| __DSP_remove_task | 0x80106C38 | 0x94 |

The Melee task scheduler reconstruction matches the original interrupt-message dispatcher, task context transfer, boot handshake, priority-ordered insertion and removal algorithms. It preserves mailbox waiting, callbacks, rude-task preemption, volatile task fields and the volatile received boot-mail local. The interrupt handler creates a local OS context and restores the interrupted context. Six original boot diagnostic calls remain and resolve to the recovered release diagnostic hook.

The unused timer variables in the reference are not linked in this image and are omitted, as is the unused add-task API. Six boot strings occupy `.data` `0x802CF080..0x802CF190` (272 bytes including padding), alignment 8. Six shared scheduler words occupy `.sbss` `0x80377C20..0x80377C38` (24 bytes), alignment 8, with their compiler-produced reversed global declaration order preserved. No large BSS or native assembly is owned.

References are [Melee's DSP family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/dsp) and [Pikmin 2's DSP family](https://github.com/projectPiki/pikmin2/tree/main/src/Dolphin/dsp). Unchanged reference files and hashes are retained under `reference/`; these are public community reconstructions and no original SDK source archive provenance is claimed.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @266 | .data | 0x802CF080 | 0x1D |
| @267 | .data | 0x802CF0A0 | 0x2D |
| @268 | .data | 0x802CF0D0 | 0x2D |
| @269 | .data | 0x802CF100 | 0x2D |
| @270 | .data | 0x802CF130 | 0x2D |
| @271 | .data | 0x802CF160 | 0x2D |
| __DSP_rude_task_pending | .sbss | 0x80377C20 | 0x4 |
| __DSP_rude_task | .sbss | 0x80377C24 | 0x4 |
| __DSP_tmp_task | .sbss | 0x80377C28 | 0x4 |
| __DSP_last_task | .sbss | 0x80377C2C | 0x4 |
| __DSP_first_task | .sbss | 0x80377C30 | 0x4 |
| __DSP_curr_task | .sbss | 0x80377C34 | 0x4 |

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dsp -Cpp_exceptions off` and ordinary peephole optimization matches all 2,180 text bytes and 272 initialized data bytes after relocations are resolved. The reproducible isolated probes are in `scratch/dsp_task`. No native assembly is counted. Full-DOL SHA-1 and native objdiff remain integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/dsp/dsp_task.c` | `.data` | `0x802CF080..0x802CF18D` (269 bytes) | `0x802CF18D..0x802CF190` (3 bytes) |

Current native objdiff credits `dolphin/dsp/dsp_task.c`: 293 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
