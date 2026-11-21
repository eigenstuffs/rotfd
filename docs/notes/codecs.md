# Codec registry

`src/Python/codecs.c` recovers the complete emitted codec-registry unit in GSQE78 from official CPython 2.1 `Python/codecs.c`. The source retains Marc-Andre Lemburg's authorship and the CNRI copyright notice. The upstream license is `reference/cpython-2.1/LICENSE`.

All six functions and all initialized data bytes match the original DOL after resolving the compiler relocations. Full executable integration and SHA-1 verification remain the final acceptance check.

| Section | Start | End | Bytes |
| --- | --- | --- | ---: |
| `.text` | `0x8017BB98` | `0x8017C5F8` | 2,656 |
| `.data` | `0x802DBF70` | `0x802DC0D0` | 352 |
| `.sbss` | `0x80377E68` | `0x80377E74` | 12 |

The emitted functions are `_PyCodecRegistry_Fini`, `_PyCodecRegistry_Init`, `PyCodec_Decode`, `PyCodec_Encode`, `_PyCodec_Lookup`, and `PyCodec_Register`. The unit preserves the lazy import of the `encodings` package, normalization of encoding names, registry search/cache behavior, and encoder/decoder tuple validation.

It matches with `GC/2.0/mwcceppc.exe` and:

```
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off
```

The internal helpers and unused convenience wrappers remain in source as `static inline` implementations. `tolower` uses the MSL lower-case mapping table with its EOF check. `size_t` is `unsigned long`, and the recovered CPython tuple and string layouts supply the direct-access macros.

The three `.sbss` objects are `import_encodings_called` at `0x80377E68`, `_PyCodec_SearchCache` at `0x80377E6C`, and `_PyCodec_SearchPath` at `0x80377E70`. Each occupies four bytes. The original heuristic eight-byte size for the last symbol includes four bytes of inter-unit padding and must be reduced when integrating this candidate.

`scratch/codecs/make_source.py` reproduces the source from the local reference. `original.s` and `original_functions.json` preserve original instructions and ranges. `verify.py` compares the relocated machine code and initialized data before writing `config/GSQE78/candidates/codecs.json`, including symbol scopes.

```
TEXT 2656 2656
.data 352 EXACT
```

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/codecs.c` | `.data` | `0x802DBF70..0x802DC0CE` (350 bytes) | `0x802DC0CE..0x802DC0D0` (2 bytes) |

Current native objdiff credits `Python/codecs.c`: 362 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
