# Core Python object operations

The target's core object implementation follows CPython 2.1. The verified
reference is `reference/cpython-2.1/Objects/object.c`; its license is retained
in `reference/cpython-2.1/LICENSE`.

The complete candidate reconstructs 36 functions and all translation-unit data:

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x80156580–0x8015987C | 13,052 |
| `.data` | 0x802D4408–0x802D4730 | 808 |
| `.sdata` | 0x80376288–0x803762C8 | 64 |
| `.sdata2` | 0x80379FB0–0x80379FE8 | 56 |
| `.sbss` | 0x80377E18–0x80377E28 | 16 |

All 13,052 instruction bytes and 928 initialized data bytes matched an
isolated compile after resolving relocations to the original DOL addresses.
`config/GSQE78/candidates/object.json` records each function and symbol address.
The full linked DOL SHA-1 remains the acceptance check.

This includes trashcan destruction, repr recursion guards, the weak-reference
hook, memory wrappers, `None` and `NotImplemented`, callable checks, numeric
coercion, truth testing, attribute operations, pointer and floating-point
hashing, recursive comparisons, string representations, printing, and object
initialization.

`empty_clear_weak_refs` is the original empty callback used before the
weak-reference module installs its implementation. Its four-byte body is
verified against the original, rather than a placeholder for unfinished work.
Likewise `_Py_HashPointer` returns the input pointer as a `long`, requiring only
a return instruction on the target ABI.

Compile with CodeWarrior GC/2.0 and `-proc gekko -fp hardware -enum int -str
reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off`. These are the settings established for module objects.
The small comparison helpers are declared `static inline` to reproduce the
original inlining decisions. `try_3way_compare`, `do_cmp`, and
`check_recursion` retain standalone bodies.

The source keeps the verified 32-bit object layouts locally. String bytes
start at offset 0x14; type objects are 0x6C bytes and expose rich comparison
and weak-reference slots. The stdio declaration models the error byte read by
`ferror` at offset 0xA, while `clearerr` remains an external function. Internal
error diagnostics retain filename `object.c` and original line numbers 661
and 753.

The `.sbss` starts with `compare_nesting`, followed by the trashcan globals and
the static comparison dictionary key. This order matters: assigning only the
two trashcan globals to an object split starts at an address misaligned for
the compiler's section and shifts later globals by four bytes. The complete
translation unit reproduces the original alignment without padding workarounds.

Several unused upstream entry points, including standalone `PyObject_Not`,
`PyObject_Unicode`, debugging helpers, and extra allocation wrappers, do not
occur in this executable and are not emitted.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/object.c` | `.sdata` | `0x80376288..0x803762C6` (62 bytes) | `0x803762C6..0x803762C8` (2 bytes) |

Current native objdiff credits `Objects/object.c`: 942 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
