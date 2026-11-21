# Python arbitrary-precision integers

This complete unit follows CPython 2.1 `Objects/longobject.c`, retaining
its arithmetic, conversions, and comments. The upstream license is in
`reference/cpython-2.1/LICENSE`.

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x8014EC00–0x80155540 | 26,944 |
| `.data` | 0x802D3ED0–0x802D4148 | 632 |
| `.sbss` | 0x80377E08–0x80377E0C | 4 |
| `.sdata2` | 0x80379F80–0x80379FB0 | 48 |

The isolated compile verifies all 45 functions, 26,944 instruction bytes,
and 680 initialized data bytes after applying every relocation to the
original DOL addresses. The candidate manifest in
`config/GSQE78/candidates/longobject.json` records sections, symbol
visibility, function sizes, and external symbol identities. The complete
linked executable must pass its original SHA-1 before this is accepted as
linked source progress.

The compiler is CodeWarrior GC/2.0 with `-proc gekko -fp hardware -enum int
-str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred
-pool off -Cpp_exceptions off`. `long_normalize`, `mul1`, `muladd1`,
`divrem1`, `x_add`, and `long_repeat` are declared `static inline` to
reproduce their absence as standalone bodies. Unused upstream unsigned
and pointer-conversion entry points are also retained as inline source.
The standalone signed 64-bit conversions are present: the configuration
has 32-bit `long` and pointers, 64-bit `long long`, and `HAVE_LONG_LONG`.

The integer representation uses unsigned 16-bit digits carrying 15 bits
each. Digits begin at byte offset 0xC. The number table is 0x88 bytes, and
the type is 0x6C bytes. Variable-object allocation reads the type's actual
size fields, allocates memory, and calls `PyObject_InitVar`, as in the
original CPython allocation macro. The `ticker` global controls periodic
signal checks during lengthy arithmetic and conversion loops.

The MSL `abs` operation must use the compiler's `__abs` intrinsic. Its
branchless instruction sequence and register allocation differ from an
ordinary C conditional, even when the function's overall size is equal.
The source preserves `longobject.c` and upstream diagnostic line numbers
with a `#line` directive following the reconstructed header declarations.

The original function inventory incorrectly split the last unreachable
return instruction from `long_hash` into a separate four-byte function at
0x80152F90. The compiler emits it as part of `long_hash`, whose complete
range is 0x80152F24–0x80152F94 (0x70 bytes). That original heuristic symbol
must be removed when integrating the candidate; no extra function is
introduced to reproduce it.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/longobject.c` | `.data` | `0x802D3ED0..0x802D4146` (630 bytes) | `0x802D4146..0x802D4148` (2 bytes) |

Current native objdiff credits `Objects/longobject.c`: 682 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
