# Marshal serialization

`src/Python/marshal.c` recovers the complete emitted CPython marshal translation unit in GSQE78. It is adapted from official CPython 2.1 `Python/marshal.c` and the corresponding object declarations. The upstream license is `reference/cpython-2.1/LICENSE`.

The isolated candidate matches all 16 functions and every initialized data byte against the original DOL with compiler relocations resolved. Integration and the complete executable SHA-1 check remain the final acceptance step.

| Section | Start | End | Bytes |
| --- | --- | --- | ---: |
| `.text` | `0x801996D4` | `0x8019E6A4` | 20,432 |
| `.data` | `0x802E2C38` | `0x802E2DD0` | 408 |
| `.sdata` | `0x80376F70` | `0x80376FB8` | 72 |

The unit serializes and reads Python integers, long integers, floats, complex numbers, strings, Unicode, tuples, lists, dictionaries, and code objects. It also supplies the public marshal API and the `marshal` module's four methods. The code preserves CPython's 5,000-level write-depth limit and byte-oriented serialized representation.

The compiler configuration is `GC/2.0/mwcceppc.exe` with:

```
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off
```

The platform has 32-bit `long` and `size_t`, 16-bit unsigned Unicode characters, and CPython's 15-bit long-integer digits. Complex serialization is enabled. FSTAT-based read buffering is disabled, so `PyMarshal_ReadLastObjectFromFile` uses the original file-reading path. The code-object layout includes free-variable and cell-variable fields from CPython 2.1.

MSL's `FILE` structure and inline `getc`/`putc` macros are necessary for exact code generation. Both check byte orientation through `fwide`, use the buffer length at offset `0x28`, advance the buffer pointer at offset `0x24`, and call `__getc`/`__putc` when needed. These macros account for much of the expanded machine code in the integer and object readers/writers.

`r_long`, `r_short`, `r_string`, `w_string`, and `w_more` retain their actual implementations as `static inline` helpers. `r_long64` and `w_short` remain standalone functions. The unused `PyMarshal_ReadObjectFromFile` API remains in source as `static inline`; its equivalent read implementation is inlined into the used callers. No replacement stubs or fabricated serialized data are present.

`scratch/marshal/make_source.py` reproduces the adapted source. `original.s` and `original_functions.json` record original instructions and ranges. `verify.py` compares each relocated instruction, all method-table pointers, and all initialized strings, then writes `config/GSQE78/candidates/marshal.json` only on complete success. The manifest records local and global symbol scopes. There is no owned BSS or separate floating-point constant section.

```
TEXT 20432 20432
.data 408 EXACT
.sdata 72 EXACT
```

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/marshal.c` | `.data` | `0x802E2C38..0x802E2DCF` (407 bytes) | `0x802E2DCF..0x802E2DD0` (1 byte) |
| `Python/marshal.c` | `.sdata` | `0x80376F70..0x80376FB7` (71 bytes) | `0x80376FB7..0x80376FB8` (1 byte) |

Current native objdiff credits `Python/marshal.c`: 478 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
