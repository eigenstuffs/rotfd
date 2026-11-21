# Dolphin audio RAM request queues

`src/dolphin/ar/arq.c` recovers all 6 linked C functions at `0x80100E90..0x80101264` (980 bytes).

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| __ARQServiceQueueLo | 0x80100E90 | 0x100 | global |
| __ARQCallbackHack | 0x80100F90 | 0x4 | global |
| __ARQInterruptServiceRoutine | 0x80100F94 | 0xCC | global |
| ARQInit | 0x80101060 | 0x70 | global |
| ARQPostRequest | 0x801010D0 | 0x15C | global |
| ARQFlushQueue | 0x8010122C | 0x38 | global |

The [Pikmin 2 ARQ reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/ar/arq.c) supplies the exact two-priority DMA request queue algorithms. The target's version string identifies September 5, 2002. High-priority requests run as a whole; low-priority requests advance in configured chunks while preserving their original source, destination, and length updates. The interrupt service routine finishes active callbacks and schedules waiting work. The high-priority pop helper is inline, as in the original image.

`__ARQCallbackHack` is the reference's real no-operation default completion callback: `ARQPostRequest` installs its address when the caller supplies no callback. It is a retained source function and is not a placeholder added for progress. Declarations for unrelated unlinked helpers are omitted. `ARQFlushQueue` follows the Melee reference's queue clearing under interrupt protection; the target omits its conditional cancellation of the pending low-priority request. The four queue-pointer stores and the untouched pending request match the original instructions.

`.data` is `0x802CA968..0x802CA9B0` (72 bytes), the 69-byte version literal plus three bytes of padding. `.sdata` is `0x80375D68..0x80375D6C` (four bytes), the version pointer, followed by four external alignment bytes. `.sbss` is `0x80377B20..0x80377B48` (40 bytes), ten private four-byte values. No ordinary BSS is owned. All sections have alignment 8. Literal and state sizes are recorded individually in the candidate manifest.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @1 | .data | 0x802CA968 | 0x45 |
| __ARQVersion | .sdata | 0x80375D68 | 0x4 |
| __ARQRequestQueueHi | .sbss | 0x80377B20 | 0x4 |
| __ARQRequestTailHi | .sbss | 0x80377B24 | 0x4 |
| __ARQRequestQueueLo | .sbss | 0x80377B28 | 0x4 |
| __ARQRequestTailLo | .sbss | 0x80377B2C | 0x4 |
| __ARQRequestPendingHi | .sbss | 0x80377B30 | 0x4 |
| __ARQRequestPendingLo | .sbss | 0x80377B34 | 0x4 |
| __ARQCallbackHi | .sbss | 0x80377B38 | 0x4 |
| __ARQCallbackLo | .sbss | 0x80377B3C | 0x4 |
| __ARQChunkSize | .sbss | 0x80377B40 | 0x4 |
| __ARQ_init_flag | .sbss | 0x80377B44 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ar -Cpp_exceptions off` and peephole optimization enabled. The isolated scripts in `scratch/arq` resolve every call, pointer, and small-data relocation, then compare all 980 code bytes and 76 initialized data bytes against the original DOL. No assembly fallback is needed within this unit; existing external hardware helper routines remain outside its source coverage. Whole-DOL SHA-1 and native objdiff remain the integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/ar/arq.c` | `.data` | `0x802CA968..0x802CA9AD` (69 bytes) | `0x802CA9AD..0x802CA9B0` (3 bytes) |

Current native objdiff credits `dolphin/ar/arq.c`: 113 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
