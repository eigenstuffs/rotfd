# Unicode character classification

`src/Objects/unicodectype.c` recovers the complete CPython Unicode character-classification unit, immediately before `unicodeobject.c`. Both the implementation and its generated character database come from official CPython 2.1, `Objects/unicodectype.c` and `Objects/unicodetype_db.h`. The source retains the upstream authorship and CNRI copyright notice; the upstream license is `reference/cpython-2.1/LICENSE`.

All 14 emitted functions and all initialized tables/constants compare exactly against the original DOL after applying compiler relocations. The isolated candidate awaits the complete executable link and SHA-1 acceptance check.

| Section | Start | End | Bytes |
| --- | --- | --- | ---: |
| `.text` | `0x80165010` | `0x80165BE4` | 3,028 |
| `.rodata` | `0x802AC2F0` | `0x802AC798` | 1,192 |
| `.data` | `0x802D6990` | `0x802D8C30` | 8,864 |
| `.sdata2` | `0x80379FF0` | `0x8037A178` | 392 |

The read-only data contains 119 ten-byte character-property records, followed by two alignment bytes. The two mutable-section index arrays occupy 2,048 and 6,816 bytes. The exact original generated table values are retained. The small read-only section contains the floating-point constants used by the numeric-character conversion switch.

The compiler configuration is `GC/2.0/mwcceppc.exe` with:

```
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off
```

`Py_UNICODE` is an unsigned 16-bit integer. `gettyperecord` and `_PyUnicode_ToDigit` are declared `static inline`: their implementations are present and inlined into callers, while unused standalone copies are omitted, as in the original executable. `_PyUnicode_ToDecimalDigit` remains emitted because it is used externally. The platform-wide-character alternatives are disabled.

`scratch/unicodectype/make_source.py` reproducibly combines the reference implementation and database. `original.s` snapshots the original instruction range. `verify.py` compares every relocated instruction and all initialized section bytes, writing `config/GSQE78/candidates/unicodectype.json` only on success. The manifest includes symbol scopes for the generated arrays and public functions.

The isolated verification result is:

```
TEXT 3028 3028
.rodata 1192 EXACT
.data 8864 EXACT
.sdata2 392 EXACT
```

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/unicodectype.c` | `.rodata` | `0x802AC2F0..0x802AC796` (1,190 bytes) | `0x802AC796..0x802AC798` (2 bytes) |

Current native objdiff credits `Objects/unicodectype.c`: 10,446 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
