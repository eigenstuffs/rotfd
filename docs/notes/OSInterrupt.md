# Dolphin SDK interrupt C functions

`src/dolphin/os/OSInterrupt.c` recovers seven contiguous C functions from the original SDK interrupt translation unit. The text range `0x800F3678..0x800F3E48` contains 2000 bytes.

| Function | Address | Size |
| --- | --- | --- |
| __OSSetInterruptHandler | 0x800F3678 | 0x1C |
| __OSGetInterruptHandler | 0x800F3694 | 0x14 |
| __OSInterruptInit | 0x800F36A8 | 0x74 |
| SetInterruptMask | 0x800F371C | 0x2D8 |
| __OSMaskInterrupts | 0x800F39F4 | 0x88 |
| __OSUnmaskInterrupts | 0x800F3A7C | 0x88 |
| __OSDispatchInterrupt | 0x800F3B04 | 0x344 |

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSInterrupt.c) supplies the matching C algorithms and identifies the assembly functions. The original `OSDisableInterrupts`, `OSEnableInterrupts`, and `OSRestoreInterrupts` at `0x800F362C..0x800F3678`, and `ExternalInterruptHandler` at `0x800F3E48..0x800F3E98`, remain original assembly fallback. They contribute no recovered C progress. The handler entry retains its original calling convention and branches to recovered C dispatch. Its symbol must be global solely to connect the split C initializer's function pointer; it originally had static translation-unit linkage. `OSGetInterruptMask` and `OSSetInterruptMask` from the reference are absent from this linked target region and are omitted.

The source retains the signed 16-bit interrupt identifiers, volatile last-interrupt diagnostics, complete context layout, and the compiler's absolute hardware register bindings. Priority selection uses the compiler's C `__cntlzw` intrinsic. Normal release assertions emit no code. No C algorithm changes were needed.

Owned initialized data is the 11-entry local `InterruptPrioTable` at `0x802CA100..0x802CA12C` (44 bytes). The compiler emits no jump table for this unit. Small BSS `0x80377910..0x80377928` (24 bytes including padding) contains local `InterruptHandlerTable`, global `__OSLastInterruptSrr0`, signed volatile `__OSLastInterrupt`, and volatile 64-bit `__OSLastInterruptTime`. The handler array itself is the fixed low-memory area at `0x80003040`, not an allocated BSS object. The candidate records exact sizes and scopes.

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -opt nopeephole -inline auto -Cpp_exceptions off -i src/dolphin/os`. Scheduling remains enabled and peephole optimization is disabled. `scratch/OSInterrupt/compile.py` builds the isolated source; `verify.py` resolves every relocation and compares against the original DOL, reporting `TEXT 2000 2000` and `.data 44 EXACT`. The full linked-DOL SHA-1 remains the integration check.
