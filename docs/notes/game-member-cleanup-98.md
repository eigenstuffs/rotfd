# Member cleanup at offset 0x98

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/member_cleanup_98.cpp` reconstructs `fn_8026F0B4`, original `.text` range
`8026F0B4..8026F12C` (120 bytes). This is an isolated ordinary C++
match awaiting central integration and full-DOL acceptance.

The partial owner installs its original table at offset 8, passes the member at offset 0x98 to the original cleanup with deleting argument -1, calls base cleanup with argument 0, and releases the owner only for a positive signed low half of its deleting argument. The one-byte member marker establishes its address only and makes no claim about the member extent.

Run `python3 scratch/game_member_cleanup_98/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 120 emitted text bytes, the original global symbol
and 7 actual relocations. The verifier checks every allocated
byte and exact relocation site, kind, symbol and addend against the protected
original DOL. There are no other allocated sections, weak helpers, initialized
data, BSS or owned padding. Candidate, actual-relocation and original-metadata
JSON files preserve source/header/object hashes and the evidence.

The original extabindex, `.ctors` and `.dtors` audit finds no overlapping
exception entry or table reference into the retained range. Referenced tables,
allocators, base/member cleanup routines, global storage and neighboring
functions remain externally owned. This is a partial text-only split, not a
claim that the complete original translation unit has been recovered. The
integrator must still run the complete DOL hash, native objdiff, source-extent
and regression checks. No special flags, new symbol names or owned-data ranges
are needed.
