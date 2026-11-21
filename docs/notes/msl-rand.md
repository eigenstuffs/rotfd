# MSL/rand.c

The retained random-number unit contains `rand` at `0x80127C6C–0x80127C8C` (32 bytes). It advances a 32-bit state using multiplier 1103515245 and increment 12345, then returns 15 bits from the upper half. The initial state is 1. No standalone `srand` routine is linked.

The source follows the pinned [Melee reconstruction](https://github.com/doldecomp/melee/blob/ae5898ee0dfda41b34fdf846f7d680a33e14779d/src/MSL/rand.c), retained unchanged in `reference/melee-msl/rand.c` with provenance recorded alongside it. The target's `next` state occupies four initialized bytes at `0x80375E40`, followed by four zero alignment bytes. The state symbol is already correctly sized. The corrected source split ends at `0x80375E44` and owns four data bytes; `0x80375E44..0x80375E48` remains separate original padding with no source credit. Preserve its existing `gap_09_80375E44_sdata` identity with explicit symbol and split alignment of one byte.

Run `python3 scratch/msl_rand/verify.py` to compile with GC/1.3, apply both relocations, and compare all 32 instruction bytes, four state bytes, and four alignment bytes. Result: zero differences. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The manifest is `config/GSQE78/candidates/msl-rand.json`. The unchanged source previously passed full-DOL and native objdiff integration. The shortened source extent and explicit external-padding checks pass in isolation; central integration of the four-byte attribution correction passes the original DOL hash and native objdiff. Source and headers are unchanged; project totals are in [PROGRESS.md](../../PROGRESS.md).
