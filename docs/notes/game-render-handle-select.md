# Render-handle selection

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/render_handle_select.cpp` reconstructs `fn_80272854`, original `.text`
range `80272854..80272968` (276 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The routine replaces the manager reference for the handle at offset 0x224 and resolves the new stored value. For a valid object it sets flag bit 8 at owner offset 0x2D0, sets bit 2 for object kind 1 or bit 1 for kind 2, then calls the original manager at global offset 0x184 with arguments 1,1,0. The object kind is the observed unsigned byte at offset 0x3F; the private views make no wider type claim.

Run `python3 scratch/game_render_handle_select/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 276 emitted text bytes, the original global symbol and
7 actual relocations. Every allocated byte and exact relocation
site, kind, symbol and addend is checked against the protected original DOL.
No weak helpers, other allocated sections, initialized data, BSS or padding
are emitted. Candidate, actual-relocation and original-metadata JSON preserve
source/header/object hashes, external dependencies and the evidence.

The original extabindex, `.ctors` and `.dtors` audit finds no overlapping
exception entry or table reference into the retained range. Original tables,
global storage, runtime helpers, native initialization/reference operations and
neighboring functions remain externally owned. This partial text-only split
does not claim a complete original translation unit. Central integration must
still pass the complete DOL hash, native objdiff, source-extent and regression
checks. No special flags, new symbols or owned-data ranges are required.
