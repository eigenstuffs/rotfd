# EXI2 debugger support

Three source-family units reproduce the retained debugger range `0x8012DAD0..0x8012E588`: 23 functions and 2,744 code bytes. All retained text and initialized data match after relocation. All three units pass the full DOL SHA-1 and direct byte comparison, and their owned code/data match 100% in the native objdiff report.

| Unit | Text range | Functions | Code bytes |
|---|---|---:|---:|
| `amcstubs/AmcExi2Stubs.c` | `0x8012DAD0..0x8012DB00` | 8 | 48 |
| `odenotstub/odenotstub.c` | `0x8012DB00..0x8012DB08` | 1 | 8 |
| `OdemuExi2/DebuggerDriver.c` | `0x8012DB08..0x8012E588` | 14 | 2,688 |

The AMC implementation provides disabled EXI2 entry points and returns true from `AMC_IsStub`. The separate weak `Hu_IsStub` returns false for the active Odemu driver. The transport manages EXI channel 2, mailbox commands, two alternating transfer buffers, and interrupt callbacks.

## Compiler and validation

All three units use **GC/1.2.5**, `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off`. Peephole optimization remains enabled. GC/1.2.5n changes several driver epilogues and does not reproduce this unit.

Two source declarations are essential. Hardware registers use the SDK's CodeWarrior absolute-address array syntax, rather than pointer-cast macros or unresolved external arrays. `s32` and `u32` are signed and unsigned **long**; the copy-loop counter remains **int**. Both integer types are 32 bits on this target, but the compiler preserves distinct initial loop comparisons for that combination. These declarations follow the pinned SDK type and hardware headers; no instruction injection or artificial optimization barrier is used.

The driver owns one initialized `SendCount` byte at `.sdata:0x80375E78` (value `0x80`) and seven following zero padding bytes before the next unit. Its `.sbss` state occupies `0x80377D28..0x80377D40`: two callback pointers, mailbox data, receive length, input-flag pointer, and a byte flag, including three trailing padding bytes. These BSS addresses and extents are verified as uninitialized layout, not counted as initialized DOL contents. Absolute MMIO symbols own no DOL storage.

The compiler also emits six ordinary helper bodies: `DBGEXIInit`, `DBGEXISelect`, `DBGEXIDeselect`, `DBGEXISync`, `DBGWriteMailbox`, and `CheckMailBox`. The retained callers contain the expected inlined implementations; ordinary linker dead stripping removes the unreferenced bodies. The candidate verifier maps the 14 retained functions individually and resolves all 57 relocations. No discarded helper is counted as matched code.

Run `python3 scratch/debugger_driver/verify.py` to verify the final driver object; successful output is saved in `scratch/debugger_driver/verification.txt`. `scratch/debugger_driver/promote.py` records compilation and direct byte comparison for the two smaller units. Candidate manifests are `config/GSQE78/candidates/{AmcExi2Stubs,odenotstub,DebuggerDriver}.json`.

`DBQueryData` preserves the original placement of `OSRestoreInterrupts` outside its conditional, including the uninitialized local on the nonzero receive-length path. The later TP driver moves that call inside the conditional, which differs from the target. This decompilation preserves the original behavior rather than applying an unrelated fix.

## Provenance

The main implementation follows the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/ae5898ee0dfda41b34fdf846f7d680a33e14779d/extern/dolphin/src/dolphin/odenotstub/odenotstub.c), pinned at `ae5898ee0dfda41b34fdf846f7d680a33e14779d`. Its combined file is separated here into the driver and marker source families, confirmed by the [TP marker unit](https://github.com/zeldaret/tp/blob/c8fa8c9e2aab72cf4e5db0e5d1c84a9ea6ee6eb0/libs/dolphin/src/odenotstub/odenotstub.c). The [MKDD AMC unit](https://github.com/doldecomp/mkdd/blob/2a9eb75fefd75c649c0488742db931571cbd7812/libs/dolphin/amcstubs/AmcExi2Stubs.c) supplies the stub definitions.

Unchanged references, pinned URLs, and SHA-256 hashes are listed in `reference/melee-sdk/DEBUGGER_PROVENANCE.md`. The source uses an opaque `OSContext`, since this unit never accesses its fields. `DBInitInterrupts` is declared void, consistent with its behavior and the alternate SDK reference. These are community reconstructions and verified source-family boundaries; they are not a claim that the original source files have been recovered verbatim.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/OdemuExi2/DebuggerDriver.c` | `.sdata` | `0x80375E78..0x80375E79` (1 byte) | `0x80375E79..0x80375E80` (7 bytes) |
| `dolphin/OdemuExi2/DebuggerDriver.c` | `.sbss` | `0x80377D28..0x80377D3D` (21 bytes) | `0x80377D3D..0x80377D40` (3 bytes) |

Current native objdiff credits `dolphin/OdemuExi2/DebuggerDriver.c`: 22 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
