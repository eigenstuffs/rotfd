# Reset-switch event loop

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/reset_switch_loop.cpp` reconstructs `fn_80279300`, original `.text`
range `80279300..80279368` (104 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The original infinite loop waits for retrace and samples the reset switch. A released switch following a previously recorded pressed state sends the original formatted event through the manager at global offset 0x110 and sets the external reset flag. It samples the switch again to store the next previous state. Both reads and the native no-return control flow are preserved.

Run `python3 scratch/game_reset_switch_loop/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 104 emitted text bytes, the original global symbol and
11 actual relocations. The verifier checks every allocated byte,
exact relocation site/kind/symbol/addend and original symbol target. SDA21
relocations select r2 or r13 from the original symbol's small-data section and
apply the verified anchors 0x803801C0 or 0x8037BE40 with a signed sixteen-bit
range check. The resulting instructions, not masked relocations, match the
protected original DOL.

No weak helpers, other allocated sections, initialized data, BSS or padding
are emitted. External constants and small-BSS storage retain original ownership.
Candidate, actual-relocation and original-metadata JSON preserve all exact
hashes, dependencies and evidence. The original extabindex, `.ctors` and
`.dtors` audit finds no overlapping exception entry or table reference into
the retained range. Other native functions, original tables and neighboring
code remain externally owned. This is a partial text-only split. Central
integration must still pass complete DOL hash, native objdiff, source-extent
and regression checks; no new symbols, owned data or special flags are needed.
