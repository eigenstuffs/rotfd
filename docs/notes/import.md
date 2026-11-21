# Import machinery

`src/Python/import.c` recovers the complete CPython import translation unit in GSQE78. The implementation is adapted from official CPython 2.1 `Python/import.c`, with local declarations for the recovered runtime ABI. The upstream license is `reference/cpython-2.1/LICENSE`.

The isolated candidate contains 36 functions and compares every instruction and initialized data byte against the original DOL after resolving compiler relocations. Its final acceptance requires integration and the complete executable SHA-1 check.

| Section | Start | End | Bytes |
| --- | --- | --- | ---: |
| `.text` | `0x80195338` | `0x801996D4` | 17,308 |
| `.rodata` | `0x802AC798` | `0x802AC7BC` | 36 |
| `.data` | `0x802E1E90` | `0x802E2C34` | 3,492 |
| `.sdata` | `0x80376EA0` | `0x80376F6C` | 204 |
| `.sbss` | `0x80377F10` | `0x80377F2C` | 28 |

The unit includes the `imp` module, imports and reloads, frozen-module handling, source/bytecode loading, the extension cache, and import initialization and cleanup. Its initialized data consists of the standard suffix table, cleanup names, frozen/builtin descriptors, method documentation and table, compiler strings, the bytecode magic, and the initialization-table pointer.

## Compiler and platform evidence

The exact compiler is `GC/2.0/mwcceppc.exe` with:

```
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off
```

`size_t` is an unsigned 32-bit `long`, and `time_t` is a signed 32-bit `long`. Paths use the default slash separator and 1,024-character bound. Threading, dynamic library loading, platform-specific resource imports, and stat-based directory detection are disabled. The unused package-directory descriptor is consequently excluded.

The recovered `filedescr` structure stores its `type` as an unsigned byte at offset eight, with a total structure stride of 12 bytes. This is demonstrated by the original byte loads and descriptor bytes; upstream's integer enum field produces different instructions and initialized data.

The cached import-name pointers are zero initialized. `get_parent`'s declarations are ordered to reproduce the original cache addresses, and `_PyImport_Filetab` is a tentative definition that follows the static cache objects in `.sbss`. These changes preserve the initialization behavior while matching the original section layout.

The original `PyImport_Inittab` initializer points to `_PyImport_Inittab` at `0x802E95F4`, outside this unit. The verifier reads that original pointer to resolve the data-only relocation. `_PyImport_DynLoadFiletab` is also an external table, beginning at `0x802AC7C0`.

Inlined helper implementations remain in the source with `static inline` declarations. The two extension-table mutation APIs at the end of the reference file were not linked into GSQE78 and are retained under a disabled preprocessor block; otherwise the compiler emits their unused static cache as an extra `.sbss` object. No replacement stubs are used. Source parsing calls the original three-argument `PyParser_SimpleParseFile` interface.

## Isolated verification

`scratch/import/make_source.py` reproduces the adapted source from the local CPython reference. `original.s` and `original_functions.json` preserve the original instructions and 36 function ranges. `verify.py` reconstructs linked instruction/data values using actual compiler relocations and emits `config/GSQE78/candidates/import.json` only when all comparisons pass. The manifest includes linkage scopes for static functions, static descriptors, and cached names.

```
TEXT 17308 17308
.rodata 36 EXACT
.data 3492 EXACT
.sdata 204 EXACT
```

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/import.c` | `.data` | `0x802E1E90..0x802E2C33` (3,491 bytes) | `0x802E2C33..0x802E2C34` (1 byte) |
| `Python/import.c` | `.sdata` | `0x80376EA0..0x80376F69` (201 bytes) | `0x80376F69..0x80376F6C` (3 bytes) |

Current native objdiff credits `Python/import.c`: 3,756 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
