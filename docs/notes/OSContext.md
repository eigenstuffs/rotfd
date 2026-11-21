# Dolphin SDK context C fragments

Four production objects recover the C functions from the original `OSContext.c` translation unit while retaining interleaved assembly as original fallback:

| Source fragment | Function | Original text range | Bytes |
| --- | --- | --- | --- |
| `OSContext_current.c` | `OSGetCurrentContext` | `0x800F2968..0x800F2974` | 12 |
| `OSContext_clear.c` | `OSClearContext` | `0x800F2AD4..0x800F2AF8` | 36 |
| `OSContext_dump.c` | `OSDumpContext` | `0x800F2BB4..0x800F2E5C` | 680 |
| `OSContext_init.c` | `__OSContextInit` | `0x800F2EE0..0x800F2F28` | 72 |

These are repository fragments of one original translation unit, not claims that the original had four source files. The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSContext.c) supplies the function classifications and algorithms. Context save/load, `OSSetCurrentContext`, `OSInitContext`, FPU switching, and stack helpers remain assembly fallback; none are counted here as C.

The shared local `OSContext_abi.h` preserves the complete target context structure and the compiler's absolute-address context bindings at `0x800000D4` and `0x800000D8`. The dump fragment includes the original C getter/clear as static inline helpers, reproducing their original inlining without new standalone copies. The init fragment declares `OSSwitchFPUContext` externally to connect the original fallback function pointer; it originally had static translation-unit linkage.

The dump fragment owns all original diagnostic strings in `.data` `0x802C9C08..0x802C9DE0` (472 bytes). Its final string is exposed as `OSContextInitMessage` at `0x802C9DBC` (35 bytes plus one padding byte), and the init fragment references it externally. Keeping this shared data together preserves the original eight-byte section alignment; giving initialization a standalone data section would insert four bytes of padding before its original address. This named array replaces the original compiler-local literal only to connect the C fragments. Candidate manifests include individual literal names, sizes, addresses, and scopes to preserve accurate data comparisons.

GC/1.2.5n uses `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -opt nopeephole -inline auto -Cpp_exceptions off -i src/dolphin/os`. All four original C algorithms compile without behavioral edits. Separate verifiers under `scratch/OSContext` resolve every relocation and compare all 800 C instruction bytes and 472 initialized data bytes directly against the DOL: `TEXT 12 12`, `TEXT 36 36`, `TEXT 680 680`, `.data 472 EXACT`, `TEXT 72 72`. Whole-DOL SHA-1 remains the integration check.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/os/OSContext_dump.c` | `.data` | `0x802C9C08..0x802C9DDF` (471 bytes) | `0x802C9DDF..0x802C9DE0` (1 byte) |

Current native objdiff credits `dolphin/os/OSContext_dump.c`: 471 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
