# Dolphin SDK error reporting

`src/dolphin/os/OSError.c` recovers four C functions from the original translation unit. The contiguous text range is `0x800F2F28..0x800F35D4` (1708 bytes).

| Function | Address | Size |
| --- | --- | --- |
| OSReport | 0x800F2F28 | 0x80 |
| OSPanic | 0x800F2FA8 | 0x12C |
| OSSetErrorHandler | 0x800F30D4 | 0x218 |
| __OSUnhandledException | 0x800F32EC | 0x2E8 |

The [Pikmin 2 SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/os/OSError.c) supplies the matching floating-point exception algorithms. The older Melee variant has a smaller error-handler setter and does not match this target. Melee's context, thread, and interrupt declarations supply ABI evidence. Retrieved reference files and hashes are recorded under `reference/pikmin2-sdk` and `reference/melee-sdk`.

The target has 17 handler entries: hardware exceptions 0–15 and floating-point exception 16. The source distinguishes `OS_ERROR_FPE` (16) from the table count `OS_ERROR_MAX` (17). Setting the floating-point handler updates the FPSCR/MSR state of active threads using the original thread queue at `0x800000DC`. Hardware DSP and DI registers use the compiler's original absolute-address declarations. Interrupt diagnostics are volatile, with a signed 16-bit interrupt number; these declarations reproduce both the signed load and its instruction scheduling.

The original initialized data is `.data` `0x802C9DE0..0x802CA0FC` (796 bytes), including 15 diagnostic strings and the 16-entry exception dispatch jump table, plus `.sdata` `0x80375CD8..0x80375CE0` (8 bytes including padding). The latter contains `__OSFpscrEnableBits = 0xF8` and the newline literal. `__OSErrorTable` owns `.bss` `0x80318AD0..0x80318B14` (68 bytes). The candidate manifest records every local literal and the jump table separately, including sizes and scope.

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off -i src/dolphin/os`. Peephole optimization is enabled for this unit. The source uses the compiler's C variadic ABI support; it contains no inline assembly or substituted instruction arrays.

`scratch/OSError/compile.py` performs an isolated compile. `verify.py` resolves text and data relocations, including SDA references and all jump-table entries, then compares against the original DOL. Results are `TEXT 1708 1708`, `.data 796 EXACT`, and `.sdata 8 EXACT`. `literal_manifest.py` adds individual compiler-local data objects to the candidate. The full linked-DOL SHA-1 remains the integration check.

The following function at `0x800F35D4..0x800F362C` queries font encoding using TV format and VI state; it belongs to a separate OSFont fragment. OSInterrupt begins at `0x800F362C`. Neither is included in this unit's coverage.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/os/OSError.c` | `.sdata` | `0x80375CD8..0x80375CDE` (6 bytes) | `0x80375CDE..0x80375CE0` (2 bytes) |

Current native objdiff credits `dolphin/os/OSError.c`: 870 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
