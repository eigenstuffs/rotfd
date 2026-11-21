# Modules/_codecsmodule.c

The builtin `_codecs` module is reconstructed from CPython 2.1. All 26 retained functions and every initialized byte match the original GSQE78 DOL in an isolated relocation-aware comparison. Central integration passed: the linked unit has 100% objdiff code/data matching, and the rebuilt DOL retains SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5` (see the generated `PROGRESS.md` report).

| Section | Start | End, exclusive | Emitted bytes | Owned bytes |
| --- | --- | --- | ---: | ---: |
| `.text` | `0x801A96F4` | `0x801AB66C` | 8,056 | 8,056 |
| `.data` | `0x802E9020` | `0x802E95D0` | 1,451 | 1,456 |
| `.sdata` | `0x80377450` | `0x80377468` | 20 | 24 |

The initialized section tails are verified zero-filled linker padding. The module owns no BSS. `_codecs_functions` contains the builtin method bindings; the initializer is independently referenced by `_PyImport_Inittab`.

The source preserves codec registration and lookup, the UTF-8/UTF-16 codecs, Unicode escape/internal codecs, Latin-1, ASCII, character maps, and buffer encoders. The Windows-only MBCS methods are absent, matching the target configuration. Unicode code units are unsigned 16-bit values. Module initialization uses Python API version 1010.

`codec_tuple` is fully inlined in the original and is declared `static inline` in the reconstruction. This removes its otherwise unreferenced standalone body while preserving its complete algorithm. The normal Python compiler flags plus `-inline auto,deferred` and `-pool off` reproduce the complete object. No per-unit enum override is needed.

The source's recovered ABI declarations and macros are local; the reference checkout is not a build dependency. The original Marc-Andre Lemburg/CNRI notice remains in the source. Original and generated machine-code bytes are unmodified.

## Reproduce

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/codecsmodule/final.o src/Modules/_codecsmodule.c
python3 scratch/codecsmodule/check_object.py
```

The verifier resolves all 225 relocations and reports zero mismatching initialized bytes. `config/GSQE78/candidates/codecsmodule.json` contains the section ranges, function and method-table names, sizes, linkage scopes, and source hash. `scratch/codecsmodule/verification.txt` records the result; `src/Modules/_codecsmodule.c` is authoritative.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Modules/_codecsmodule.c` | `.data` | `0x802E9020..0x802E95CB` (1,451 bytes) | `0x802E95CB..0x802E95D0` (5 bytes) |
| `Modules/_codecsmodule.c` | `.sdata` | `0x80377450..0x80377464` (20 bytes) | `0x80377464..0x80377468` (4 bytes) |

Current native objdiff credits `Modules/_codecsmodule.c`: 1,471 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
