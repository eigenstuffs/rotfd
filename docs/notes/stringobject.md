# Objects/stringobject.c

The complete linked string-object unit is reconstructed from CPython 2.1. All 64 functions and all initialized bytes pass isolated relocation-aware comparison with GSQE78. Central integration passed the full DOL SHA-1 check (`5da8295a79bf297ab62c620e6ac66210be1c6ef5`), and objdiff reports all retained code and data matching.

| Section | Start | End, exclusive | Emitted bytes | Owned bytes |
| --- | --- | --- | ---: | ---: |
| `.text` | `0x8015AC30` | `0x80163D7C` | 37,196 | 37,196 |
| `.data` | `0x802D4A60` | `0x802D67B0` | 7,501 | 7,504 |
| `.sdata` | `0x80376338` | `0x80376468` | 299 | 304 |
| `.sdata2` | `0x80379FE8` | `0x80379FF0` | 8 | 8 |
| `.bss` | `0x8033DC78` | `0x8033E078` | 1,024 | 1,024 |
| `.sbss` | `0x80377E28` | `0x80377E30` | 8 | 8 |

The initialized section tails are verified zero-filled alignment padding. BSS stores the 256 single-character string pointers; small BSS stores the intern dictionary and empty-string cache. Their locations are proven by the original instructions accessing them. Uninitialized storage has no file bytes to compare.

## Recovery details

The unit includes string allocation, resizing, comparison, hashing, sequence and buffer interfaces, searching, splitting, joining, replacing, classification, case conversion, alignment, formatting, interning, and finalization. The sequence/buffer tables, method table, all linked documentation and other strings, and the floating-point formatting constant are reproduced.

`CACHE_HASH` and `INTERN_STRINGS` reproduce a 24-byte `PyStringObject` allocation header, with character storage starting at offset `0x14`. Reference counting and Unicode dispatch are retained. Object allocation initializes the fields inline, matching the original compiler output.

The original emits no standalone copies of the formatting helpers, padding helper, search/count helpers, strip helper, and checked string buffer/length helpers. Explicit `static inline` declarations preserve those functions inside callers. `PyString_AsEncodedString` is also inline in `string_encode`. `PyString_Encode`, `PyString_Decode`, and `_Py_ReleaseInternedStrings` have no retained linked bodies in this unit and do not contribute matching progress.

The standard-library declarations reproduce the target's MSL behavior: `UCHAR_MAX` has unsigned type, character classification uses the original lookup table, case conversion preserves the EOF check, and `fabs` maps to the compiler's `__fabs` intrinsic. `PyArg_NoArgs` expands to `PyArg_Parse(args, "")`. String repetition writes its equivalent overflow comparison with the original operand order. Diagnostic source filenames and line constants are retained explicitly so source formatting cannot change generated error paths.

The recovered source has no dependency on the reference checkout at build time. Its local ABI declarations derive from the original headers and use the project's shared basic object definition.

## Reproduce

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/stringobject/final.o src/Objects/stringobject.c
python3 scratch/stringobject/check_object.py
```

The check resolves all 1,607 relocations, including the floating-point constant through r2, and reports zero mismatching initialized bytes. It compares relocated compiler output directly against the original DOL. No original or generated machine-code bytes are edited to produce the result.

`config/GSQE78/candidates/stringobject.json` records section ranges, function/table/cache names, sizes, linkage scopes, and 18 newly identified external APIs. `scratch/stringobject/verification.txt` preserves the isolated result. The source under `src/Objects` is authoritative; scratch candidates and scripts retain the recovery history.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/stringobject.c` | `.data` | `0x802D4A60..0x802D67AD` (7,501 bytes) | `0x802D67AD..0x802D67B0` (3 bytes) |
| `Objects/stringobject.c` | `.sdata` | `0x80376338..0x80376463` (299 bytes) | `0x80376463..0x80376468` (5 bytes) |

Current native objdiff credits `Objects/stringobject.c`: 8,840 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
