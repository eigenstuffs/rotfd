# CodeWarrior exception unwinder

`src/Runtime/Gecko_ExceptionPPC.cpp` reconstructs twelve retained C++ functions at `0x8011FD88..0x80120FB0`, totaling 4,648 code bytes. They locate exception records, walk frames and cleanup actions, dispatch catches, implement `unexpected`, and register the single linked fragment. The implementation follows the [pinned Xenoblade runtime](https://github.com/xbret/xenoblade/blob/ea25691b2029394ab777bda7060139e517a13cba/libs/PowerPC_EABI_Support/src/Runtime/Gecko_ExceptionPPC.cp), with the target's one-fragment capacity and recovered inlining. The reference and its upstream CC0 license are retained under `reference/xenoblade-runtime/`.

The two adjacent primitives `ExPPC_LongJump` (`0x8011FB40..0x8011FC44`) and `__throw` (`0x8011FC44..0x8011FD88`) are explicitly native assembly in the reference. They remain original assembly dependencies and are not counted as newly recovered C++ source. Existing initialization and destructor-chain units remain separate.

GC/1.3 with `-O4,p -inline deferred -pool on -str reuse,readonly`, RTTI, exceptions, and `lmw/stmw` enabled emits every retained instruction exactly. GC/1.3.2 produces one different move instruction in `__unexpected`. Data pooling and string pooling are separate compiler options here: data pooling supplies the shared base used by `__unexpected`, while independent string symbols preserve the original literals and weak virtual methods.

The earlier allocation unit owns the weak `std::exception` destructor, `what`, and vtable. This source naturally emits duplicates; normal weak resolution discards their bodies and the duplicate destructor's exception records. `scratch/runtime_gecko/verify.py` explicitly accounts for those ranges and resolves their references to the earlier original addresses. It verifies all 137 retained relocations without masking instructions. All retained data, including local RTTI, type names, switch tables, fragment state, and generated exception records, is covered.

Two bytes require an explicit compiler-padding normalization. The large catch record in `__unexpected` contains unused alignment between the one-byte `unused` field and `catch_type`. At original addresses `0x80015F1E..0x80015F20`, the original stores `25 00`; this compiler run emits `FF 7D`. The standard build framework already supports `dtk extab clean --padding 2500` through the object option `extab_padding=[0x25, 0x00]`. This cleanup reads the candidate ELF and writes a separate candidate ELF. The verifier asserts that it changes only those two allocated bytes; all instructions and semantic exception fields remain the compiler's output. Raw and normalized object hashes are recorded separately. This is a match with compiler-padding normalization, not a claim that every raw emitted data byte matches.

Run `python3 scratch/runtime_gecko/verify.py` for the isolated proof. It reads the original DOL without modifying it and checks SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. The proof covers 4,648 code bytes, 594 initialized data bytes, 12 BSS bytes, and 26 alignment bytes. Full-DOL integration remains a separate check, including natural weak resolution and the zero interval after the retained vtable.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Runtime/Gecko_ExceptionPPC.cpp` | `.rodata` | `0x802ABA40..0x802ABAD2` (146 bytes) | `0x802ABAD2..0x802ABAD8` (6 bytes) |
| `Runtime/Gecko_ExceptionPPC.cpp` | `.bss` | `0x8033D240..0x8033D24C` (12 bytes) | `0x8033D24C..0x8033D250` (4 bytes) |

Current native objdiff credits `Runtime/Gecko_ExceptionPPC.cpp`: 622 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
