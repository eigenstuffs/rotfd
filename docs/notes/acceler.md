# Parser accelerators

`src/Parser/acceler.c` reconstructs CPython 2.1 `Parser/acceler.c`, using the shared verified target declarations in `include/parser_abi.h`. The translation unit precomputes and frees the parser's token-to-state accelerator tables.

All three emitted functions match their original ranges: `fixstate` at `0x80172F28` (896 bytes), `PyGrammar_RemoveAccelerators` at `0x801732A8` (132 bytes), and `PyGrammar_AddAccelerators` at `0x8017332C` (128 bytes). The complete 1,156-byte text range ends at `0x801733AC`, where traceback begins. Owned `.data` is `0x802DB290..0x802DB300` (112 bytes), containing the original accelerator diagnostics.

The upstream algorithms compile unchanged. `fixdfa` is declared `static inline`, matching its inclusion in `PyGrammar_AddAccelerators` without a standalone function. The recovered ABI includes 24-byte states/DFAs, 4-byte arcs with signed 16-bit fields, the CPython bitset macros, and the original allocation macros. No parser debug configuration is enabled.

The compiler is GC/2.0 with `-proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -pool off -Cpp_exceptions off`. `scratch/acceler/verify.py` resolves all compiled relocation targets to their original addresses, then compares every text instruction and owned initialized data byte directly against the DOL. The result is `TEXT 1156 1156`, `.data 112 EXACT`. `config/GSQE78/candidates/acceler.json` records ranges and symbol scopes for integration; whole-DOL SHA-1 remains the integration check.

Source provenance and the CPython 2.1 license location are recorded in the reconstructed source.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Parser/acceler.c` | `.data` | `0x802DB290..0x802DB2FF` (111 bytes) | `0x802DB2FF..0x802DB300` (1 byte) |

Current native objdiff credits `Parser/acceler.c`: 111 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
