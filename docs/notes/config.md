# Modules/config.c

The target builtin-module configuration is recovered as a separate data-only unit from CPython 2.1's `Modules/config.c.in` template. Its complete initialized data matches the original GSQE78 DOL. Central integration passed: the linked unit has 100% objdiff code/data matching, and the rebuilt DOL retains SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5` (see the generated `PROGRESS.md` report).

| Section | Start | End, exclusive | Emitted bytes | Owned bytes |
| --- | --- | --- | ---: | ---: |
| `.data` | `0x802E95D0` | `0x802E9648` | 116 | 120 |
| `.sdata` | `0x80377468` | `0x80377490` | 36 | 40 |

`_PyImport_Inittab` begins at `0x802E95F4` and contains ten 8-byte records, including the final null record. Its size is 80 bytes; the following four zero bytes are linker padding. The unit owns the associated name strings and no code or BSS.

The table registers `errno`, `new`, `_codecs`, `marshal`, and `imp`. It also lists `__main__`, `__builtin__`, `sys`, and `exceptions` with null initializer pointers. The exceptions entry differs from the upstream template: the matching `Python/pythonrun.c` initializes exceptions explicitly. Other initialization paths can also install modules, so absence from this table alone does not prove absence from the executable.

The original template's copyright and permission notice remains in source. No reference-checkout headers are needed to build it.

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/config/final.o src/Modules/config.c
python3 scratch/config/check_object.py
```

The verifier resolves 14 relocations and reports zero mismatching initialized bytes. Both initialized section tails are verified zero-filled padding. `config/GSQE78/candidates/config.json` records the exact ranges, table size, linkage scope, and source hash. Original and generated data bytes are unmodified.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Modules/config.c` | `.data` | `0x802E95D0..0x802E9644` (116 bytes) | `0x802E9644..0x802E9648` (4 bytes) |
| `Modules/config.c` | `.sdata` | `0x80377468..0x8037748C` (36 bytes) | `0x8037748C..0x80377490` (4 bytes) |

Current native objdiff credits `Modules/config.c`: 152 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
