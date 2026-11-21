# Python/future.c

The future-statement parser is reconstructed from CPython 2.1. Both retained functions and every initialized byte match the original GSQE78 DOL in an isolated relocation-aware comparison. Central integration passed: the linked unit has 100% objdiff code/data matching, and the rebuilt DOL retains SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5` (see the generated `PROGRESS.md` report).

| Section | Start | End, exclusive | Emitted bytes | Owned bytes |
| --- | --- | --- | ---: | ---: |
| `.text` | `0x80193318` | `0x8019376C` | 1,108 | 1,108 |
| `.data` | `0x802DE7B0` | `0x802DE958` | 420 | 424 |
| `.sdata` | `0x803767C8` | `0x803767D0` | 7 | 8 |

Both section tails contain verified zero-filled linker padding. There is no owned BSS. `PyNode_Future` allocates the 12-byte future-feature state and invokes `future_parse`. Parsing preserves the original handling of nested scopes, docstrings, import placement, unsupported features, and the `braces` diagnostic. The two error/feature helpers are fully inlined; their C algorithms remain present.

The source builds with the standard Python flags plus `-inline auto,deferred` and `-pool off`. It contains local recovered declarations and constants and does not include the reference checkout.

## Reproduce

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/future/final.o src/Python/future.c
python3 scratch/future/check_object.py
```

The verifier resolves all 94 relocations and reports zero mismatching initialized bytes against the original DOL. `config/GSQE78/candidates/future.json` contains section ranges, names, sizes, scopes, and the source hash. `scratch/future/verification.txt` preserves the successful result. Original and generated machine-code bytes remain unmodified.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/future.c` | `.data` | `0x802DE7B0..0x802DE954` (420 bytes) | `0x802DE954..0x802DE958` (4 bytes) |
| `Python/future.c` | `.sdata` | `0x803767C8..0x803767CF` (7 bytes) | `0x803767CF..0x803767D0` (1 byte) |

Current native objdiff credits `Python/future.c`: 427 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
