# Plane bounds test and transformed sphere wrappers

`src/Game/plane_bounds_test.cpp` reconstructs three consecutive functions:

| Function | Address range | Bytes |
| --- | --- | ---: |
| `fn_8026BED4` | `8026BED4..8026C028` | 340 |
| `fn_8026C028` | `8026C028..8026C094` | 108 |
| `fn_8026C094` | `8026C094..8026C10C` | 120 |

The first routine checks a sphere against vertical minimum/maximum values and
four plane expressions. It reports overlap flags through an integer pointer
and returns a signed-byte acceptance result. The plane coefficients occupy
three groups of four floats; vertical bounds occupy offsets `40` and `44`.
The four plane expressions retain the original separate multiply/add stages.
A local radius read after those calculations reproduces the original floating
register allocation; no contraction or assembly is used.

The wrappers transform the input sphere through `fn_80099A00` before invoking
the first routine. The first wrapper constructs a local sphere from the
transform helper's value return. The second writes the transformed sphere to
the caller's output and tests that output. Explicit float copy construction
and assignment reproduce the original loads and stores.

GC/1.3.2 with standard optimized Game flags reproduces all 568 allocated text
bytes. Four actual relocations include two calls to the external transform
routine and two calls to the locally defined bounds test. Run:

```
python3 scratch/game_plane_bounds_test/verify.py
```

The strict verifier checks the entire allocation inventory, all three global
symbols, internal and external relocation targets, and original DOL hash.
There are no weak functions, constants, data, BSS, constructor/destructor
tables, exception tables or padding. Original references are calls, with no
constructor entry to transfer. The partial text split leaves adjacent functions
and original data in their existing ownership and does not claim an original
translation-unit boundary.

`candidate.json` and `actual_relocations.json` preserve the isolated evidence.
Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
