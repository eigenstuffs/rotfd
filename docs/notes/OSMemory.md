# Dolphin SDK memory protection C fragments

Two production fragments recover three C functions from the original `OSMemory.c` translation unit while preserving the interleaved processor-mode assembly as original fallback.

| Fragment | Function | Address | Size |
| --- | --- | --- | --- |
| OSMemory_handlers.c | OSMemoryOnReset (original static OnReset) | 0x800F3EB0 | 0x3C |
| OSMemory_handlers.c | MEMIntrruptHandler | 0x800F3EEC | 0x6C |
| OSMemory_init.c | __OSInitMemoryProtection | 0x800F4070 | 0x120 |

These are repository fragments of one original unit. The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSMemory.c) provides the matching algorithms. `Config24MB` (`0x800F3F58..0x800F3FD8`), `Config48MB` (`0x800F3FD8..0x800F4058`), and `RealMode` (`0x800F4058..0x800F4070`) remain 280 bytes of assembly fallback and do not count as recovered C. Their symbols are exposed for the C initializer's calls and function pointers; all originally had static translation-unit linkage.

The reset and memory interrupt handlers are also exposed solely to connect the C fragments. `OnReset` is named `OSMemoryOnReset` to avoid collisions with reset callbacks from other SDK units. The original `MEMIntrruptHandler` spelling is retained. Low-memory physical and simulated memory-size fields remain bound at `0x80000028` and `0x800000F0`; their simple C getters inline into initialization. The source preserves the reference's 40-byte reserved local stack area, which reproduces the original initializer frame size. Its original source-level purpose is not known.

The init fragment owns the local 16-byte `ResetFunctionInfo` at `0x802CA130..0x802CA140`. Its entries are the reset callback pointer, priority `0x7F`, and initially null next/previous links. No other initialized or BSS objects are emitted. The candidate records its size and local scope, along with every external function address.

GC/1.2.5n reproduces the handler fragment with `-O4,p -inline auto`. The initializer requires `-O4,p -opt nopeephole -inline auto`, preserving scheduling while disabling peephole transformations. Both use the usual Gekko C flags and `-i src/dolphin/os`. The two settings reproduce the original instructions on their respective sides of the assembly block; this does not establish the original command-line or pragma history.

The isolated verifiers under `scratch/OSMemory` resolve every text and data relocation and compare directly with the original DOL: `TEXT 168 168`, `TEXT 288 288`, and `.data 16 EXACT`. All 456 recovered instruction bytes are compiled C. Whole-DOL SHA-1 remains the integration check.
