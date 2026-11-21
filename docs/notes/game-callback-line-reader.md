# Callback line reader

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two complete 196-byte functions at `802530C8..8025318C` and
`8025318C..80253250` reconstruct 392 text bytes. The observed prefix contains
an external signed-byte buffer at `+0C`, length at `+10`, and cursor at `+14`.
The full original class and backing storage remain unknown and external.

`802530C8` clears the output length, returns null at end of input, scans to
line feed or buffer end, advances by the reported length, then skips following
carriage returns, line feeds and spaces. It returns the original line start
without adding termination or modifying buffer data. `8025318C` resets the
cursor and performs the same operation through an ordinary inline helper.

The functions need separate bounded compilation units: compiling the first
through another inline wrapper coalesces its early null return and changes
code generation. The combined 388-byte probe remains private and uncredited.
Final production sources retain the native 196-byte extents exactly.

`scratch/game_callback_line_reader/verify.py` recompiles both frozen sources
and checks all allocated bytes and the two complete global function extents.
There are no relocations, helpers, data, BSS, exception sections or padding.
Central original-table ownership, production, full-DOL hash and regression
checks remain required before matching acceptance.
