# Python runtime identification units

Four adjacent CPython 2.1 files are reconstructed as separate original-source build units. Each function and every initialized byte match the original GSQE78 DOL in isolated relocation-aware comparisons. Central integration passed: the linked unit has 100% objdiff code/data matching, and the rebuilt DOL retains SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5` (see the generated `PROGRESS.md` report).

| Source | Text range, end exclusive | Text bytes | Initialized data | Other storage |
| --- | --- | ---: | --- | --- |
| `Python/getcompiler.c` | `0x801952BC..0x801952C4` | 8 | `.sdata 0x80376820..0x80376828`, 4 emitted bytes | none |
| `Python/getcopyright.c` | `0x801952C4..0x801952D0` | 12 | `.data 0x802DF118..0x802DF248`, 303 emitted bytes | none |
| `Python/getplatform.c` | `0x801952D0..0x801952DC` | 12 | `.data 0x802DF248..0x802DF258`, 9 emitted bytes | none |
| `Python/getversion.c` | `0x801952DC..0x80195338` | 92 | `.data 0x802DF258..0x802DF270`, 20 emitted bytes; `.sdata 0x80376828..0x80376830`, 4 emitted bytes | `.bss 0x8033E380..0x8033E480`, 250 emitted bytes |

The compiler identification is `[C]`, the platform macro is `GAMECUBE`, and the version macro is `2.1`. The complete upstream copyright text matches unchanged. `Py_GetVersion` preserves the shared 250-byte version buffer and formats the version, build information, and compiler identification. Its call confirms `Py_GetBuildInfo` at `0x801A9090`, which belongs to a separate unit.

All initialized linker padding is verified zero. The six unused bytes following the version buffer are owned BSS padding; there are no original file bytes for uninitialized storage. The sources retain the original function boundaries and have no reference-checkout header dependency.

Each source uses the normal Python build flags. Reproduce a unit, substituting its name for `getversion`:

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/getversion/final.o src/Python/getversion.c
python3 scratch/getversion/check_object.py
```

The four verifiers resolve 1, 2, 2, and 10 relocations respectively and report zero mismatching initialized bytes. Separate manifests live in `config/GSQE78/candidates/`; each scratch directory records its successful verification. Original and generated machine-code bytes are unmodified.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/getcompiler.c` | `.sdata` | `0x80376820..0x80376824` (4 bytes) | `0x80376824..0x80376828` (4 bytes) |
| `Python/getcopyright.c` | `.data` | `0x802DF118..0x802DF247` (303 bytes) | `0x802DF247..0x802DF248` (1 byte) |
| `Python/getplatform.c` | `.data` | `0x802DF248..0x802DF251` (9 bytes) | `0x802DF251..0x802DF258` (7 bytes) |
| `Python/getversion.c` | `.data` | `0x802DF258..0x802DF26C` (20 bytes) | `0x802DF26C..0x802DF270` (4 bytes) |
| `Python/getversion.c` | `.bss` | `0x8033E380..0x8033E47A` (250 bytes) | `0x8033E47A..0x8033E480` (6 bytes) |
| `Python/getversion.c` | `.sdata` | `0x80376828..0x8037682C` (4 bytes) | `0x8037682C..0x80376830` (4 bytes) |

Current native objdiff credits `Python/getcompiler.c`: 4 data bytes; `Python/getcopyright.c`: 303 data bytes; `Python/getplatform.c`: 9 data bytes; `Python/getversion.c`: 274 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
