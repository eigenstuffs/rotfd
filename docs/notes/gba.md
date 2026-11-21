# Game Boy Advance link library

Seven source-family units reproduce all retained code in `0x8012E588..0x80130084`: **32 functions and 6,908 code bytes**. Every retained instruction and initialized data byte matches after 212 relocations. The code also owns 1,028 bytes of BSS state. All seven units pass the full DOL SHA-1/direct-byte check and their owned code/data match 100% in the native objdiff report.

| Unit | Functions | Text bytes |
|---|---:|---:|
| `GBA.c` | 5 | 572 |
| `GBAGetProcessStatus.c` | 1 | 372 |
| `GBAJoyBoot.c` | 11 | 3,780 |
| `GBARead.c` | 3 | 352 |
| `GBAWrite.c` | 3 | 392 |
| `GBAXfer.c` | 6 | 824 |
| `GBAKey.c` | 3 | 616 |

These routines implement status/reset commands, JoyBoot downloads, read/write operations, serial-interface transport callbacks, and DSP-assisted boot-key generation. The 256-byte `GBAControl` layout is verified through all field accesses and the compiled array indexing. The private `GBA_abi.h` retains the SDK's signed/unsigned long integer types, callback signatures, DSP task layout, and timer conversions. It uses the already recovered OSContext declarations without editing them.

## Compiler and source scope

All units use **GC/1.2.5n** with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off -i src/dolphin/gba`. **Peephole optimization is enabled**, unlike the flags used for several earlier OS units. GC/1.2.5 changes epilogue scheduling in these functions; GC/1.2.5n reproduces them exactly.

The retained `GBA.c` portion excludes `GBAInit`, `OnReset`, `SecParams`, and `ResetFunctionInfo`, which are absent from the target link. Their complete reference definitions remain available. The other units preserve ordinary unreferenced helpers: JoyBoot's `F72`, `F95`, `F104`, and synchronous `GBAJoyBoot`, plus GBAKey's `F152`. Expected calls are inlined and ordinary linker dead stripping removes the unused out-of-line bodies. These helpers are not counted as retained functions.

The isolated checker maps retained functions individually, resolves their actual branch/data targets, and verifies all initialized sections. It also checks BSS symbol layout rather than treating zero-initialized state as bytes present in the DOL. The compiler's older SDA21 relocations point at the instruction halfword; the checker normalizes their patch position correctly.

## Data ownership

The JoyBoot unit owns `D54` at `.data:0x802D09A0..0x802D09D0`, consisting of 45 bytes and three tail padding bytes. The key unit owns `.data:0x802D09D0..0x802D0D78`: the original 896-byte DSP program `D35`, the `GBAKey.c` filename, and the unexpected-callback diagnostic, including alignment padding. These sections emit 979 initialized bytes and occupy 984 bytes with padding.

`D35` is preserved from the unchanged source reference as an embedded program asset. Its bytes match the original, but it is **data ownership, not a claim that the DSP instructions have been decompiled into C**. The PowerPC C callbacks that submit the program are independently matched. The filename diagnostic is explicit so builds in different source directories preserve the original string.

`__GBA[4]` owns `.bss:0x8033D6E0..0x8033DAE0` (1,024 bytes). `__GBAReset` owns four bytes at `.sbss:0x80377D40`, followed by four alignment bytes before the next unit.

## Evidence and provenance

`scratch/gba/handoff.json` lists the seven candidate manifests. The final objects and disassemblies are in `scratch/gba/`; `verification.txt` records every successful comparison. Run `python3 scratch/gba/verify.py GBAJoyBoot`, substituting another unit name as needed. `promote.py` records the final source compilation and manifest generation.

The direct references are the [PrimeDecomp GBA SDK reconstruction](https://github.com/PrimeDecomp/prime/tree/5d513da690931c7fb46206559e9dda8fe776dc46/extern/sdk/dolphin/GBA), pinned at `5d513da690931c7fb46206559e9dda8fe776dc46`. Unchanged files, exact paths, and SHA-256 hashes are preserved under `reference/prime-sdk/`, with `PROVENANCE.md`. These older routines reproduce the target's interrupt locking and DSP-assisted key path. The newer TWW source-family comparison uses a different software-key path and is not the final implementation reference.

No native instruction words, handwritten assembly, forced registers, or artificial compiler barriers are used to replace PowerPC C logic. The original DOL remains unchanged, SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/gba/GBA.c` | `.sbss` | `0x80377D40..0x80377D44` (4 bytes) | `0x80377D44..0x80377D48` (4 bytes) |
| `dolphin/gba/GBAJoyBoot.c` | `.data` | `0x802D09A0..0x802D09CD` (45 bytes) | `0x802D09CD..0x802D09D0` (3 bytes) |
| `dolphin/gba/GBAKey.c` | `.data` | `0x802D09D0..0x802D0D76` (934 bytes) | `0x802D0D76..0x802D0D78` (2 bytes) |

Current native objdiff credits `dolphin/gba/GBA.c`: 1,028 data bytes; `dolphin/gba/GBAJoyBoot.c`: 45 data bytes; `dolphin/gba/GBAKey.c`: 934 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
