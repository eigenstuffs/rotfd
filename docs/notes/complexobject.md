# Python complex-number objects

This complete unit follows CPython 2.1 `Objects/complexobject.c`, retaining
its algorithms and comments. The upstream license is in
`reference/cpython-2.1/LICENSE`.

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x8013C86C–0x8013E14C | 6,368 |
| `.data` | 0x802D21E8–0x802D2480 | 664 |
| `.sdata` | 0x80376018–0x80376048 | 48 |
| `.sdata2` | 0x80379F28–0x80379F40 | 24 |

The isolated compile verifies all 29 functions, 6,368 instruction bytes,
and 736 initialized data bytes against the original DOL with all
relocations applied. The candidate manifest in
`config/GSQE78/candidates/complexobject.json` records section ownership,
function sizes, external identities, and symbol visibility. Acceptance
still requires the complete linked executable to pass its original SHA-1.

CodeWarrior GC/2.0 uses the established flags: `-proc gekko -fp hardware
-enum int -str reuse -common off -opt level=4,nopeephole,speed -inline
auto,deferred -pool off -Cpp_exceptions off`. The elementary `c_sum`,
`c_diff`, `c_neg`, `c_prod`, `c_quot`, `c_pow`, `c_powu`, and formatting
helper `complex_to_buf` are declared `static inline`, matching the absence
of independent bodies in the target. The integer-power dispatcher
`c_powi` retains its standalone 0x454-byte body at 0x8013DCF8.

The unit includes arithmetic, powers, real and imaginary accessors,
conjugation, conversion and coercion, rich comparison, hashing, formatting,
and allocation. `Py_complex` contains two doubles and uses the target
compiler's struct-return convention. `PyComplexObject` is 24 bytes, with
its real and imaginary values at offsets eight and sixteen. The type flags
are 0x6B, the CPython 2.1 defaults with cyclic GC disabled. The module's
identity value, method table, number table, type object, strings, and
floating-point constants are all owned by this split.

The data extent includes final padding to four bytes; the next original
unit starts directly at 0x802D2480. No writable uninitialized data belongs
to this translation unit.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/complexobject.c` | `.data` | `0x802D21E8..0x802D247D` (661 bytes) | `0x802D247D..0x802D2480` (3 bytes) |
| `Objects/complexobject.c` | `.sdata` | `0x80376018..0x80376046` (46 bytes) | `0x80376046..0x80376048` (2 bytes) |

Current native objdiff credits `Objects/complexobject.c`: 731 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
