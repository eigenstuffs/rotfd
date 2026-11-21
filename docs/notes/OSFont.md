# Dolphin SDK font encoding query

`src/dolphin/os/OSFont.c` recovers the linked `OSGetFontEncode` function at `0x800F35D4..0x800F362C` (88 bytes) from the SDK font translation unit. Other functions in the reference OSFont source are not claimed as recovered or present here.

The unchanged C algorithm from the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSFont.c) caches the encoding after inspecting the low-memory TV format and the VI digital-TV status bit. Its local `fontEncode$1` is a two-byte value initialized to `0xFFFF` at `0x80375CE0`. The candidate owns four initialized section bytes through `0x80375CE4`, including two padding bytes; the remaining alignment gap before the following unit is not part of the cached value.

GC/1.2.5n with `-O4,p -inline auto` and the normal Gekko C flags matches exactly. The local isolated verifier resolves the small-data references and reports `TEXT 88 88`, `.sdata 4 EXACT`. Hardware accesses use the compiler's absolute VI register declaration. The source contains no assembly, and its manifest preserves the static cached variable's local scope. Whole-DOL SHA-1 is the final integration check.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/os/OSFont.c` | `.sdata` | `0x80375CE0..0x80375CE2` (2 bytes) | `0x80375CE2..0x80375CE4` (2 bytes) |

Current native objdiff credits `dolphin/os/OSFont.c`: 2 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
