# MSL decimal conversion

`src/MSL/ansi_fp.c` reconstructs eleven retained functions at `0x801221EC..0x80123E58`, totaling 7,276 code bytes. The public entry points convert between binary doubles and the MSL 36-digit decimal representation. Private helpers implement decimal multiplication, subtraction, comparisons, powers of two, and rounding. The following two 16-byte absolute-value functions are a separate arithmetic unit.

The decimal arithmetic helpers follow the [pinned Wind Waker reconstruction](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Src/ansi_fp.c). Its reference lacks `__dec2num`; that function follows the [pinned Strikers reconstruction](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/ansi_fp.c), with target-specific behavior recovered from original instructions. The unmodified references and their upstream notices are preserved in `reference/tww-msl/` and `reference/strikers-msl/`. The TP floating-point header and MKDD decimal source were comparison references, with their existing notices retained.

The target calls `nextafter` toward positive or negative infinity when refining the first floating-point estimate. This differs from the newer Strikers reference's direct increment/decrement of the double's bit representation. The target also retains separate short-exponent arithmetic helpers, uses the TWW helper-local decimal temporaries, and inlines the normal MSL `isdigit`/`tolower` declarations. Preserving the inline `isdigit` function rather than spelling its expression as a macro reproduces the original register allocation in the NaN payload loop. The unused TWW string-seeding dummy is unnecessary because the retained `__dec2num` naturally contains that maximum-value string.

Owned data consists of 221 bytes of decimal strings at `0x802ABAF0`, the 64-byte powers-of-ten table at `0x802D00F8`, a 292-byte switch table at `0x802D0138`, and six doubles at `0x80379948`. Three string-pool alignment bytes and four data alignment bytes are zero. The original coarse `lbl_802ABAF0` symbol must shrink from `0xE0` to `0xDD` bytes so alignment stays separate. No BSS is owned.

`python3 scratch/msl_ansi_fp/verify.py` compiles with GC/1.3, `-O4,p`, deferred inlining, signed chars, pooled read-only strings, and `-use_lmw_stmw off`. It applies all 223 relocations and verifies every instruction and initialized data byte, including the switch-table targets and alignment. All comparisons pass without masking instructions or patching compiler output. The candidate manifest records the complete ranges, function mappings, data ownership, exact compiler flags, and hashes. Full-DOL integration is a separate parent build check.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `MSL/ansi_fp.c` | `.rodata` | `0x802ABAF0..0x802ABBCD` (221 bytes) | `0x802ABBCD..0x802ABBD0` (3 bytes) |
| `MSL/ansi_fp.c` | `.data` | `0x802D00F8..0x802D025C` (356 bytes) | `0x802D025C..0x802D0260` (4 bytes) |

Current native objdiff credits `MSL/ansi_fp.c`: 625 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
