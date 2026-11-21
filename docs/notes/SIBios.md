# Dolphin serial-interface controller

All 24 surviving C functions in `SIBios.c` compile exactly at `80297FB8..80299818`, totaling 6,240 bytes. Every instruction, original local branch and resolved external relocation matches the GSQE78 DOL. All 108 initialized bytes also match. The complete recovered text range is ordinary C.

The retained projectPiki/pikmin2 SDK reconstruction has the same function sizes and matching transfer, polling, wireless-controller identification, type decoding, and callback algorithms. The original literal identifies the older September 5, 2002 SI build. The private header preserves the reference control structures and register bitfields and reuses the already recovered DVD/OS alarm/time ABI without modifying it. Melee's SI definitions supply the device/error constants. URLs and hashes are recorded in the respective reference provenance files.

Compiler settings are GC/1.2.5n, `-O4,p -inline auto`, normal peephole optimization. Three helper bodies (`SIClearTCInterrupt`, `SITransferNext`, and `CallTypeAndStatusCallback`) are marked ordinary `static inline`: the original call sites already contain those bodies, while no separate functions survive. The source omits the original link-eliminated `SISync`, `SIGetCommand`, and `SIGetTypeString` routines. No target control flow was removed or replaced.

## Data and state

| Section | Original extent | Bytes | Alignment |
|---|---|---:|---:|
| `.data` | `802F3298..802F3300` | 104 | 8 |
| `.sdata` | `80377520..80377524` | 4 | 8 |
| `.bss` | `80373C40..80373E40` | 512 | 8 |
| `.sbss` | `803781A0..803781AC` | 12 | 8 |

Initialized data consists of the 68-byte version string, 20-byte `Si` control record, four cached type words, and a version-string pointer. BSS has four transfer packets, four 40-byte alarms, type/transfer times, callback arrays, input validity/data/scanline buffers, and the local wireless-device command array. The manifest lists all objects individually.

Small BSS contains two separate four-byte function-local type/status commands plus the four-byte `__PADFixBits` word. The original heuristic eight-byte extent of `__PADFixBits` includes four following linker alignment bytes; those bytes are excluded from the source-owned range. Four bytes after the small-data pointer are trailing DOL section padding beyond DTK’s logical `.sdata` end, not a separate split or object. The linker/DOL writer emits that padding naturally. It is recorded separately and is not an additional recovered variable.

The original unused device-name literal pool from `SIGetTypeString` follows `802F3300` and remains fallback. Its function is absent from this linked unit; no extra absent function is emitted to retain those strings. The integrated source passes whole-DOL byte equality, native objdiff code/data checks and the original-source regression audit. The isolated `scratch/si` compiler and verifier reproduce the candidate's exact function, data and relocation proof.
