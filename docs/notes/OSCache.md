# Dolphin SDK cache management C routines

`src/dolphin/os/OSCache.c` reconstructs three linked C functions at `0x800F23CC..0x800F26B8` (748 bytes): `L2GlobalInvalidate` (152 bytes), `DMAErrorHandler` (352 bytes), and `__OSCacheInit` (244 bytes). The preceding native cache-instruction routines at `0x800F2228..0x800F23CC` remain original assembly fallback objects and contribute no recovered C progress.

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSCache.c) distinguishes these C functions from the assembly primitives. `L2Init`, `L2Enable`, and `L2Disable` are inlined C helpers; synchronization uses the compiler's `__sync` intrinsic. The unit also owns `.data` `0x802C99D8..0x802C9C04` (556 bytes), containing the cache and machine-check diagnostics. No BSS is owned.

All algorithms and strings match without behavioral changes. GC/1.2.5n uses `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -opt nopeephole -inline auto -Cpp_exceptions off`. Unlike adjacent SDK units, this translation unit retains the compiler's pre-peephole branches and mask comparisons. `-O4,p` still enables instruction scheduling; replacing it with optimization-level flags alone disabled scheduling and misplaced seven instructions. The compiler's help output and isolated variants are retained in `scratch/OSCache` as evidence.

`scratch/OSCache/verify.py` resolves every text/data relocation, including the compiler's shared data-pool base, and compares with the original DOL: `TEXT 748 748`, `.data 556 EXACT`. The candidate covers only the three C functions and their data. Whole-DOL SHA-1 remains the integration check.

The assembly fallback attribution includes `DCStoreRange` at `0x800F2298`, `DCStoreRangeNoSync` at `0x800F22F4`, and `DCZeroRange` at `0x800F2320`, identifiable from their respective `dcbst`/`dcbz` loops in the original executable. These names do not imply C reconstruction or remove their bytes from the denominator.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/os/OSCache.c` | `.data` | `0x802C99D8..0x802C9C02` (554 bytes) | `0x802C9C02..0x802C9C04` (2 bytes) |

Current native objdiff credits `dolphin/os/OSCache.c`: 554 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
