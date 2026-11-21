# Signal handling

`src/Modules/signalmodule.c` reconstructs the complete linked CPython 2.1 `Modules/signalmodule.c`. Although the game's built-in import table has no `signal` entry, `PyOS_InitInterrupts` directly calls `initsignal()` and `_PyImport_FixupExtension("signal", "signal")`. The interrupt APIs therefore belong to this module, not to the alternative implementation in `Parser/intrcheck.c`.

The eleven emitted functions span `0x801ABCA0..0x801AC730` (2,704 bytes). Owned data is `.data` `0x802E9710..0x802E9D98` (1,672 bytes), `.sdata` `0x80377490..0x803774EC` (92 bytes), `.bss` `0x8033E538..0x8033E738` (512 bytes), and `.sbss` `0x80377F68..0x80377F7C` (20 bytes). The BSS array contains 64 pairs of `tripped` flags and Python handler pointers.

The unchanged upstream algorithms match with target MSL signal definitions: `SIGABRT=1`, `SIGFPE=2`, `SIGILL=3`, `SIGINT=4`, `SIGSEGV=5`, `SIGTERM=6`, `SIG_DFL=0`, and `SIG_IGN=1`. The upstream fallback `NSIG=64` applies. Threading, alarm, pause, SIGCHLD, and siginterrupt support are absent. The unlinked `PyOS_AfterFork` and `PyErr_SetInterrupt` implementations remain as static inline source. The address-taken `checksignals_witharg` retains an inlined copy of `PyErr_CheckSignals`, as in the original object.

Compilation uses GC/2.0 with `-proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -pool off -Cpp_exceptions off`. `scratch/signalmodule/verify.py` resolves every compiled text and data relocation against original addresses and compares the resulting bytes directly with the DOL: `TEXT 2704 2704`, `.data 1672 EXACT`, `.sdata 92 EXACT`. The candidate includes all owned symbol scopes, preventing duplicate static names during integration. Whole-DOL SHA-1 is the integration check.

The reconstructed source records CPython provenance and the upstream license at `reference/cpython-2.1/LICENSE`.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Modules/signalmodule.c` | `.sdata` | `0x80377490..0x803774EA` (90 bytes) | `0x803774EA..0x803774EC` (2 bytes) |

Current native objdiff credits `Modules/signalmodule.c`: 2,294 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
