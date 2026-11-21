# Handle-dependent status query

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/handle_status.cpp` reconstructs `fn_80270F78`, original `.text`
range `80270F78..80271060` (232 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The routine immediately accepts selector 1. Otherwise it checks the selected handle at owner offset 0x74 with the original native lookup, resolves its generation/index and accepts object kind 2. The fallback accepts a value below the external float threshold or returns bit 3 of the owner flags at offset 0x68. It preserves the original separate lookup and resolution calls.

Run `python3 scratch/game_handle_status/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 232 emitted text bytes, the original global symbol and
4 actual relocations. The verifier checks every allocated byte,
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
