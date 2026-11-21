# List objects (`Objects/listobject.c`)

`src/Objects/listobject.c` reconstructs the complete original list translation
unit: 41 functions and 20,272 code bytes. All initialized sections match the
original DOL after applying all 580 ELF relocations, and the four-byte BSS
allocation falls inside the original DOL zero-initialized range. Whole-program
integration remains a separate check owned by the main build.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | `80149CD0..8014EC00` | 20,272 |
| `.data` | `802D37D0..802D3ED0` | 1,792 |
| `.sdata` | `803761D8..80376260` | 134 + 2 alignment |
| `.sbss` | `80377E00..80377E04` | 4 |

The source follows `reference/cpython-2.1/Objects/listobject.c`, with the
official license retained at `reference/cpython-2.1/LICENSE`. Both normal
and temporarily immutable list types, their sequence and method tables,
documentation strings, comparison, slicing, and allocation paths match.
The complete `samplesortslice` algorithm occupies `0x1640` bytes, including
its inlined binary insertion sort and comparison helper; its cutoff table
is also exact.

Recovered settings are GC/2.0, `-opt level=4,nopeephole,speed`,
`-inline auto,deferred`, and `-pool off`. Six helpers are explicitly inline
because the original has no standalone emission for them: `roundupsize`,
`ins1`, `ins`, `docompare`, `binarysort`, and `_listreverse`. The un-emitted
public `PyList_Reverse` definition is omitted. Error source locations retain
their original CPython 2.1 line numbers.

The ABI has 16-byte list objects and disabled cyclic-GC headers, while the
trashcan recursion guard remains enabled. The type-oriented allocation
macros use `_PyMem_EXTRA = 1`; this adds one byte to the requested pointer
array allocation or resize, as the original instructions confirm. Raw
`PyMem_MALLOC` calls retain their requested sizes.

The old generated `indexerr` symbol covered eight SBSS bytes; the actual
pointer owns four. Preserve `80377E04..80377E08` separately as padding.
The `.sdata` payload ends at `8037625E`; its two zero alignment bytes before
the following method-object unit are included and explicitly verified.
`config/GSQE78/candidates/listobject.json` records all function, data, and
dependency mappings and the source/object hashes.

Reproduce the isolated check with:

```sh
python3 scratch/listobject/verify.py
```

The verifier recompiles the source, validates the original DOL hash, applies
every relocation, and compares every initialized section byte and alignment
byte. Section-size changes fail. No address or branch differences are masked.
Source matching credit requires the registered full DOL build to pass.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/listobject.c` | `.sdata` | `0x803761D8..0x8037625E` (134 bytes) | `0x8037625E..0x80376260` (2 bytes) |

Current native objdiff credits `Objects/listobject.c`: 1,930 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
