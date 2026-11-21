# Unicode objects

`src/Objects/unicodeobject.c` recovers the complete CPython Unicode object translation unit in GSQE78. Its implementation comes from the official CPython 2.1 `Objects/unicodeobject.c`, with the relevant public header declarations supplied locally. The original CNRI, Secret Labs AB, and Fredrik Lundh notices and permission terms are retained. The full upstream license is in `reference/cpython-2.1/LICENSE`.

The isolated candidate matches every instruction and initialized data byte after applying the original addresses to actual compiler relocations. Integration into the complete game and its SHA-1 check remain the final acceptance step; the candidate itself does not grant matching progress.

| Section | Start | End | Bytes |
| --- | --- | --- | ---: |
| `.text` | `0x80165BE4` | `0x801707CC` | 44,008 |
| `.data` | `0x802D8C30` | `0x802DAFDC` | 9,132 |
| `.bss` | `0x8033E118` | `0x8033E17C` | 100 |
| `.sdata` | `0x80376498` | `0x803765C0` | 296 |
| `.sbss` | `0x80377E30` | `0x80377E40` | 16 |
| `.sdata2` | `0x8037A178` | `0x8037A188` | 16 |

There are 95 emitted functions and 9,444 initialized data bytes. The preceding text from `0x80165010` belongs to `unicodectype.c`, whose Unicode character classification tables are separate from this unit. Here `.data` begins with the 256-byte UTF-8 code-length table. The method documentation, method table, type descriptor, compiler strings, and formatting jump table follow it.

## Compiler configuration

The unit matches with `GC/2.0/mwcceppc.exe` and:

```
-proc gekko -fp hardware -enum int -str reuse -common off
-opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off
```

The deferred compilation mode emits functions in reverse source order. Functions inlined or discarded in the original executable are declared `static inline` in the recovered source. Their actual implementations remain present. This includes private allocation/formatting/search helpers and unused public conversion wrappers; `_PyUnicode_New`, `_PyUnicode_Free`, `usprintf`, and the used public conversion APIs retain their original emitted bodies.

## Recovered platform details

- `Py_UNICODE` is an unsigned 16-bit integer, `Py_UCS4` is an unsigned 32-bit integer, and the Unicode object occupies 24 bytes.
- `size_t` is `unsigned long`. Although `unsigned int` has the same width, the compiler generates a different overflow-check sequence in `unicode_repeat` with that typedef.
- MSL's `isxdigit` behavior is represented by an inline function taking `int` and indexing `__ctype_map` through an `unsigned char` cast. Its promotion boundary is needed to reproduce the exact register and instruction sequence in both Unicode escape decoders.
- The original build leaves `WORDS_BIGENDIAN` undefined. Consequently the UTF-16 routines compile CPython's default `BYTEORDER_IS_LITTLE_ENDIAN` branch, even though the processor is PowerPC. The reconstruction preserves this observed behavior.
- Wide-character platform interfaces and Windows-only encodings are disabled. Unicode character properties use the separate `_PyUnicode_*` classification routines.
- `PyMem_NEW` and `PyMem_RESIZE` preserve the upstream extra-byte allocation convention. The Unicode free list holds up to 1,024 objects, retaining character buffers shorter than nine characters.
- `usprintf` uses the original PowerPC variadic argument layout and `__builtin_va_info` before calling `vsprintf`.
- Diagnostic calls preserve upstream source lines explicitly, so local declarations and inline adaptations do not alter the compiled line numbers: the emitted calls reference `unicodeobject.c:339` and `unicodeobject.c:4753`.

## Verification artifacts

`scratch/unicodeobject/make_source.py` reproducibly builds the adapted source from the local CPython 2.1 reference. `scratch/unicodeobject/original.s` snapshots the original instructions, while `original_functions.json` records the 95 original function ranges. `verify.py` resolves compiler relocations, including formatting jump-table entries, against the original DOL and writes `config/GSQE78/candidates/unicodeobject.json` only if all text and initialized data comparisons pass. `symbol_scopes` records static/global linkage for integration, including the two compiler-local `hexdigit` pointers, `ucnhash_CAPI`, and the Unicode free-list state.

The isolated verification result is:

```
TEXT 44008 44008
.data 9132 EXACT
.sdata 296 EXACT
.sdata2 16 EXACT
```
