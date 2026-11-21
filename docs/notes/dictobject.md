# Python dictionaries

The complete dictionary unit follows CPython 2.1 `Objects/dictobject.c`,
retaining its hash-table algorithms, APIs, methods, and documentation
strings. The upstream license is in `reference/cpython-2.1/LICENSE`.

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x8013E14C–0x801412C8 | 12,668 |
| `.data` | 0x802D2480–0x802D28D0 | 1,104 |
| `.sdata` | 0x80376048–0x803760B4 | 108 |
| `.sbss` | 0x80377DD8–0x80377DDC | 4 |

The isolated compile verifies 34 functions, 12,668 instruction bytes, and
1,212 initialized data bytes against the original DOL with every
relocation applied. `config/GSQE78/candidates/dictobject.json` records
function sizes, symbol visibility, section ownership, and external symbol
identities. Final acceptance requires the complete linked executable's
original SHA-1 to pass.

CodeWarrior GC/2.0 uses `-proc gekko -fp hardware -enum int -str reuse
-common off -opt level=4,nopeephole,speed -inline auto,deferred -pool off
-Cpp_exceptions off`. The configuration enables `CACHE_HASH` and
`INTERN_STRINGS`, including substitution of the canonical interned key
inside `PyDict_SetItem`. It disables cyclic GC while preserving the
original traverse and clear callbacks. The allocator's `PyMem_NEW` macro
adds one byte to the requested array size, as required by `_PyMem_EXTRA`
in this CPython configuration.

A dictionary is 32 bytes and each entry is 12 bytes. The table uses a
polynomial probe sequence; its polynomial table, mapping slots, ten method
documentation strings, method table, type object, error strings, and dummy
key pointer belong to this unit. Deallocation uses the shared trashcan
mechanism to avoid unbounded recursive destruction.

`insertdict` and `characterize` are declared `static inline`; their bodies
are fully inlined. The unused public key/value/item-list wrappers remain
as inline source, reproducing their absence as standalone entries. A
`#line` directive preserves `dictobject.c` and the upstream diagnostic
line numbers after the reconstructed local header declarations.

The original function inventory splits an unreachable return instruction
at 0x801406E0 from `PyDict_Next`. The verified compiler emits it within
`PyDict_Next`, whose full range is 0x80140620–0x801406E4 (0xC4 bytes).
Integration must remove that four-byte heuristic function symbol.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/dictobject.c` | `.sdata` | `0x80376048..0x803760B2` (106 bytes) | `0x803760B2..0x803760B4` (2 bytes) |

Current native objdiff credits `Objects/dictobject.c`: 1,214 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
