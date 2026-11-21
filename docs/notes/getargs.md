# Argument parsing

`src/Python/getargs.c` recovers the complete emitted CPython argument-parsing translation unit in GSQE78. The implementation is adapted from official CPython 2.1 `Python/getargs.c`, with local PowerPC ABI declarations and the original retained error strings. The upstream license is `reference/cpython-2.1/LICENSE`.

Every instruction and initialized data byte in the isolated candidate matches the original DOL after applying compiler relocations. The complete executable link and SHA-1 comparison remain the final acceptance check.

| Section | Start | End | Bytes |
| --- | --- | --- | ---: |
| `.text` | `0x8019376C` | `0x801952BC` | 6,992 |
| `.data` | `0x802DE958` | `0x802DF118` | 1,984 |
| `.sdata` | `0x803767D0` | `0x80376820` | 80 |

The five emitted functions are:

| Function | Address | Size |
| --- | --- | ---: |
| `convertsimple1` | `0x8019376C` | `0x1008` |
| `converttuple` | `0x80194774` | `0x2D0` |
| `vgetargs1` | `0x80194A44` | `0x770` |
| `PyArg_ParseTuple` | `0x801951B4` | `0x84` |
| `PyArg_Parse` | `0x80195238` | `0x84` |

The exact compiler is `GC/2.0/mwcceppc.exe`, using:

```
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off
```

The variadic argument representation is the original PowerPC array containing register indices, the input argument area, and the register-save area. `va_start` uses `__builtin_va_info`; typed reads use `__va_arg` with the compiler's `_var_arg_typeof`. Long-long and complex argument formats are enabled. `UCHAR_MAX` and `USHRT_MAX` are unsigned constants, which reproduce the unsigned compare instructions in the byte/short range checks.

The reference file's smaller conversion/error helpers are inlined. Its keyword parsing and `PyArg_VaParse` implementations remain present as `static inline` source but have no standalone functions in the original executable. Shared literals appear in the order produced by compiling the full reference file, including first appearances in those omitted APIs. This ordering is consistent with function elimination during the original link while retained string references survive. Explicit named static string arrays preserve the observed pool order without adding code or unreferenced data. A separate full-source probe in `scratch/getargs/full.c` documents this ordering evidence.

The candidate's mutable-section data includes the conversion switch jump table. Its relocation entries are resolved and compared individually; error-message strings and small literals are compared byte for byte. No BSS or floating-point constant section belongs to this unit.

`scratch/getargs/make_source.py` reproduces the adapted source. `original.s` snapshots the original machine code, `original_functions.json` records the function ranges, and `verify.py` applies relocations and compares all owned initialized sections. It writes `config/GSQE78/candidates/getargs.json` only after all comparisons succeed. The manifest includes symbol linkage scopes.

```
TEXT 6992 6992
.data 1984 EXACT
.sdata 80 EXACT
```

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/getargs.c` | `.data` | `0x802DE958..0x802DF116` (1,982 bytes) | `0x802DF116..0x802DF118` (2 bytes) |

Current native objdiff credits `Python/getargs.c`: 2,062 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
