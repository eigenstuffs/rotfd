# MSL/mbstring.c

The full retained output-conversion unit consists of `wcstombs` and `unicode_to_UTF8` at `0x8012555C–0x801256A0` (324 bytes). The source follows the pinned [Wind Waker reconstruction](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mbstring.c). Only retained output conversion is included; no unimplemented input-conversion reference body is copied or counted. The normal inline `wctomb` wrapper emits no separate body.

The conversion preserves the original one-, two-, and three-byte UTF-8 output for 16-bit wide characters, including the original loop bounds. The four-byte local initializer `{0, 0, 0xC0, 0xE0}` occupies `.sdata2` at `0x80379978–0x8037997C`, followed by four zero alignment bytes through `0x80379980`. The preceding file-position unit and following memory unit establish the text boundaries.

`python3 scratch/msl_mbstring/verify.py` verifies all 324 instruction bytes and four initialized bytes after three relocations, plus four padding bytes, with GC/1.3 and the manifest flags. No fields are masked. Unchanged reference files and upstream notices are preserved under `reference/tww-msl/` and `reference/strikers-msl/`; these are community reconstructions, not official SDK releases.

Mappings and hashes are in `config/GSQE78/candidates/msl-mbstring.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project totals remain in [PROGRESS.md](../../PROGRESS.md).

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `MSL/mbstring.c` | `.sdata2` | `0x80379978..0x8037997C` (4 bytes) | `0x8037997C..0x80379980` (4 bytes) |

Current native objdiff credits `MSL/mbstring.c`: 4 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
