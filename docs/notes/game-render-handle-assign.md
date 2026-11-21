# Render-handle assignment and dispatch

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/render_handle_assign.cpp` reconstructs `fn_80272DE8`, original `.text`
range `80272DE8..80272EA0` (184 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The routine drops the previous manager reference for the handle at offset 0x220, copies the incoming handle bits and adds the incoming reference. It then resolves the stored handle with the frozen generation/index view and calls the original dispatch routine with argument 4. The source preserves the original manager lookup and failed-generation null result.

Run `python3 scratch/game_render_handle_assign/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 184 emitted text bytes, the original global symbol and
5 actual relocations. Every allocated byte and exact relocation
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
