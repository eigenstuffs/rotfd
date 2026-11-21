# Dolphin EXI bus controller

All 23 surviving C functions from `EXIBios.c` are reconstructed at `802963C0..80297D2C`: 6,508 bytes. Isolated verification compares every instruction after resolving its relocations against the original GSQE78 DOL. The 69-byte version string and four-byte version pointer also match exactly. There are no native assembly routines inside this recovered text range.

The retained MKDD SDK reconstruction supplies the matching control layout, transfers, interrupt handling, probing, device locking, and ID acquisition algorithms. Its newer initialization was adjusted using the original instructions: the target checks the development-console bit before resetting probe state, initializes the serial-port ID afterward, and has no later Barnacle discovery branch. The version literal identifies the November 11, 2002 build. Reference URLs and hashes are saved in `reference/mkdd-sdk/PROVENANCE.md`.

GC/1.2.5n with `-O4,p -inline auto`, normal peephole optimization, and the source's `#pragma scheduling off` produces every original function size and instruction. `CompleteTransfer` and `__EXIAttach` are ordinary inline helpers: all target call sites already contain their inline bodies, and explicit `inline` suppresses unnecessary out-of-line copies absent from the linked original. No source branch or transfer operation is omitted to obtain the match.

## Owned state and initialized data

| Section | Original extent | Bytes | Alignment |
|---|---|---:|---:|
| `.data` | `802F3188..802F31CD` | 69 | 8 |
| `.sdata` | `80377518..8037751C` | 4 | 8 |
| `.bss` | `80373B80..80373C40` | 192 | 8 |
| `.sbss` | `80378188..8037818C` | 4 | 8 |

The three 64-byte `EXIControl` entries reproduce their callback pointers, volatile state, immediate-transfer buffer, selected device, cached ID/time, and three-entry unlock queue. The four-byte small-BSS object is `IDSerialPort1`. Probe times bind to the original two-word low-memory area at `800030C0`. The initialized small-data pointer refers to the owned version string.

The original three alignment bytes after the version string, four after its small-data pointer, and four after the ID state are outside source-owned extents. The manifest records these boundaries so they receive no independent C-object credit.

## Remaining literal pool

The data following the version string retains twelve device-name literals also present in the reference's `EXIGetTypeString` function. That function and `EXIGetType` have no surviving code in this original linked unit. Their unused original literal pool remains fallback, and the source does not emit extra absent functions or claim that pool as recovered data. `scratch/exi/unlinked_literals.json` records each string and its original address/size as research evidence. The following SI version string starts at `802F3298`.

`EXIBios.json` contains the 23 function ranges, every owned initialized object, exact source extents and local symbol scopes. The production source passes full-DOL byte equality, native objdiff code/data checks and the original-source regression audit.
