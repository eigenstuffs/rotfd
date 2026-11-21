# Python type objects

`src/Objects/typeobject.c` reconstructs the complete linked Python type-object
unit using CPython 2.1's implementation. Its two function bodies and type-object
initializer are unchanged from the reference; local ABI declarations supply
the game's 32-bit object layout. The reference license is preserved at
`reference/cpython-2.1/LICENSE`.

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x80164EF8–0x80165010 | 280 |
| `.data` | 0x802D68C8–0x802D6990 | 200 |
| `.sdata` | 0x80376480–0x80376498 | 24 including final padding |

| Function | Address | Bytes |
| --- | --- | ---: |
| `type_repr` | 0x80164EF8 | 64 |
| `type_getattr` | 0x80164F38 | 216 |

`PyType_Type` occupies 0x6C bytes at 0x802D68FC. It is its own metatype, has
basic size 0x6C, and supplies the representation and old-style attribute lookup
callbacks. Attribute lookup implements `__name__`, `__doc__`, and `__members__`;
a type without documentation returns `None`. Other names raise `AttributeError`.

## Build and verification

Use CodeWarrior GC/2.0 with the shared Python flags and per-object additions
`-inline auto,deferred -pool off`. Deferred emission preserves the source order
from CPython while producing `type_repr` before `type_getattr` in the object.
Disabling data pooling preserves the original individual string addresses.

The isolated verifier `scratch/typeobject/check_object.py` resolved all 29 ELF
relocations and matched every initialized byte: 280 text, 200 data, and 21
emitted small-data bytes. Three final small-data bytes are linker padding.
The section ranges and exact symbols are recorded in
`config/GSQE78/candidates/typeobject.json`. The full-project linked DOL SHA-1
check remains the authoritative integration check.

## Integrated result

The central build integrated this complete unit and verified the rebuilt DOL SHA-1 as `5da8295a79bf297ab62c620e6ac66210be1c6ef5`, identical to the original GSQE78 executable.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/typeobject.c` | `.sdata` | `0x80376480..0x80376495` (21 bytes) | `0x80376495..0x80376498` (3 bytes) |

Current native objdiff credits `Objects/typeobject.c`: 221 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
