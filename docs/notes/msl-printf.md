# MSL formatted output

`src/MSL/printf.c` reconstructs all fifteen retained functions at `0x80125B10..0x80127C6C`, totaling 8,540 code bytes. These include `sprintf`, `vsprintf`, `vfprintf`, `vprintf`, `fprintf`, `printf`, the file/string callbacks, and the integer, decimal, hexadecimal, and format-parsing helpers.

The formatter follows the [pinned Wind Waker reconstruction](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/printf.c). The missing file wrappers were recovered using the [pinned Strikers reference](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/printf.c) and original call sequences. Both references and their upstream notices remain unchanged in the respective `reference/` directories. The reconstructed source uses the previously verified FILE layout and CodeWarrior variadic ABI.

The target has no critical-region calls in these wrappers. Its retained `sprintf` and `vsprintf` bodies inline the bounded formatting helper using an unlimited count; the helper is ordinary inline C. Neither a standalone `vsnprintf` body nor `snprintf` is retained in this unit. The original write callbacks, decimal rounding, wide-string conversion, error behavior, and truncation expressions remain intact.

Owned data includes 37 bytes of pooled narrow strings at `0x802ABBD8`, four switch tables totaling 556 bytes at `0x802D0598`, a two-byte empty wide string at `0x80375E38`, and one double zero at `0x80379980`. Respectively, three, four, and six zero alignment bytes follow the first three blocks. The locale object immediately before the switch tables belongs to a separate unit. No BSS is owned.

`python3 scratch/msl_printf/verify.py` compiles with GC/1.3, `-O4,p`, deferred inlining, signed chars, pooled read-only strings, and `-use_lmw_stmw on`. All 276 relocations are applied at their recovered addresses before every instruction, table, and literal byte is compared. The complete allocated object matches without masking relocations or patching compiler output. The manifest records exact ranges, mappings, flags, and source/object/header hashes. Parent integration verifies the final DOL separately.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `MSL/printf.c` | `.rodata` | `0x802ABBD8..0x802ABBFD` (37 bytes) | `0x802ABBFD..0x802ABC00` (3 bytes) |
| `MSL/printf.c` | `.data` | `0x802D0598..0x802D07C4` (556 bytes) | `0x802D07C4..0x802D07C8` (4 bytes) |
| `MSL/printf.c` | `.sdata` | `0x80375E38..0x80375E3A` (2 bytes) | `0x80375E3A..0x80375E40` (6 bytes) |

Current native objdiff credits `MSL/printf.c`: 603 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
