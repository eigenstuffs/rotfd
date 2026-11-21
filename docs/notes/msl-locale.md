# MSL C-locale data

`src/MSL/locale.c` recovers the data-only retained locale unit: the 56-byte `__lconv` object at `0x802D0560` and five pooled string bytes at `0x802ABBD0`. It contributes no matched code functions.

The structure and initializer are based on the [pinned Strikers locale source](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/locale.c) and its [locale header](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/include/PowerPC_EABI_Support/MSL_C/MSL_Common/locale.h). Both unmodified references and upstream notices are preserved in `reference/strikers-msl/`. The source uses the semantic structure fields from the header, with seven unspecified numeric-formatting fields set to 127 in each group.

The original string bytes are `'.', 0, 0, 'C', 0`, followed by three zero alignment bytes. The decimal-point pointer targets the first byte, and all nine remaining string pointers target the empty string at offset two. As in the reference, the source's embedded-NUL literal preserves both the empty string and following locale name; no extra unused string array is needed. The original coarse labels at `0x802ABBD0` and `0x802ABBD2` should become one five-byte pool with separate alignment.

`python3 scratch/msl_locale/verify.py` applies all ten relocations and verifies the entire 56-byte initializer, five string bytes, and three alignment bytes. GC/1.3 produces no code or BSS for this unit. The candidate manifest records exact flags and hashes; full-DOL integration remains a separate parent check.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `MSL/locale.c` | `.rodata` | `0x802ABBD0..0x802ABBD5` (5 bytes) | `0x802ABBD5..0x802ABBD8` (3 bytes) |

Current native objdiff credits `MSL/locale.c`: 61 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
