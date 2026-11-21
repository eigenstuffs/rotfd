# Range object

`src/Objects/rangeobject.c` reconstructs all 12 linked functions from CPython
v2.1 `Objects/rangeobject.c`, including cached total length, overflow handling,
range slicing, repetition, containment, and list conversion.

| Section | Start | End, exclusive | Bytes |
| --- | --- | --- | ---: |
| .text | 0x8015987C | 0x8015A80C | 3,984 |
| .data | 0x802D4730 | 0x802D4960 | 560 |
| .sdata | 0x803762C8 | 0x803762F8 | 48 |

GC/2.0 uses `-opt level=4,nopeephole,speed`, `-inline auto,deferred`,
`-pool off`, and disabled C++ exceptions. `long_mul` is a static inline helper;
the original executable has no separate emitted helper. Allocation uses the
observed malloc-backed `PyObject_NEW` macro. The type is 0x6C bytes and its
sequence table includes the CPython 2.1 slots.

Every instruction and initialized data byte was compared after resolving
relocations. The integrated full DOL passes SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`; objdiff reports all 12 functions and
all owned data matched. See the versioned candidate manifest for symbol names.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/rangeobject.c` | `.data` | `0x802D4730..0x802D495D` (557 bytes) | `0x802D495D..0x802D4960` (3 bytes) |

Current native objdiff credits `Objects/rangeobject.c`: 605 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
