# Modules/getbuildinfo.c

The original build-information function matches CPython 2.1 with `BUILD=0`, `DATE="Oct 16 2002"`, and `TIME="20:28:05"`. Its 80 instruction bytes and all initialized data match the original GSQE78 DOL. Central integration passed: the linked unit has 100% objdiff code/data matching, and the rebuilt DOL retains SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5` (see the generated `PROGRESS.md` report).

| Section | Start | End, exclusive | Emitted bytes | Owned bytes |
| --- | --- | --- | ---: | ---: |
| `.text` | `0x801A9090` | `0x801A90E0` | 80 | 80 |
| `.data` | `0x802E8B78` | `0x802E8BA8` | 41 | 48 |
| `.bss` | `0x8033E500` | `0x8033E538` | 50 | 56 |

The original compile-time date and time are fixed in source for reproducibility. `Py_GetBuildInfo` writes into a shared 50-byte buffer using the original format string. Initialized linker padding is verified zero. BSS has no original file bytes to compare.

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/getbuildinfo/final.o src/Modules/getbuildinfo.c
python3 scratch/getbuildinfo/check_object.py
```

The verifier resolves 11 relocations and reports zero mismatching initialized bytes. `config/GSQE78/candidates/getbuildinfo.json` records section ranges, symbols, sizes, scopes, and the source hash. Original and generated machine-code bytes are unmodified.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Modules/getbuildinfo.c` | `.data` | `0x802E8B78..0x802E8BA1` (41 bytes) | `0x802E8BA1..0x802E8BA8` (7 bytes) |
| `Modules/getbuildinfo.c` | `.bss` | `0x8033E500..0x8033E532` (50 bytes) | `0x8033E532..0x8033E538` (6 bytes) |

Current native objdiff credits `Modules/getbuildinfo.c`: 91 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
