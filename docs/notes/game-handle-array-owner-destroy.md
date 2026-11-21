# Handle-array owner destruction

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/handle_array_owner_destroy.cpp` reconstructs `fn_802646EC`, original `.text`
range `802646EC..802647FC` (272 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The partial owner installs its original table at offset 8 and clears the twelve-byte handle array at offset 0xC. Each four-byte element passes through two ordinary empty destructor layers before its original native handle cleanup; both nullable checks remain in the generated loop. The array storage is released by its capacity in bytes and its pointer cleared as observed. The owner then installs the original resource table, calls native root cleanup and optionally releases itself.

Run `python3 scratch/game_handle_array_owner_destroy/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 272 emitted text bytes, the original global symbol and
12 actual relocations. Every allocated byte and exact relocation
site, kind, symbol and addend is verified against the protected original DOL.
No other allocated sections, weak helpers, initialized data, BSS or padding are
emitted. Candidate, actual-relocation and original-metadata JSON preserve the
source/header/object hashes, dependencies and evidence.

The original extabindex, `.ctors` and `.dtors` audit finds no overlapping
exception entry or table reference into the retained range. Referenced original
tables, element cleanup, allocators, native initializer, manager/global storage
and neighboring functions remain externally owned. This partial text-only
split does not claim the complete original translation unit. The integrator
must run the complete DOL hash, native objdiff, source-extent and regression
checks. No special flags, new symbol names or owned-data ranges are required.
