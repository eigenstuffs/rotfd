# Memory-card mount result wrapper

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/card_mount_result.cpp` reconstructs `fn_80277B8C`, original `.text` range
`80277B8C..80277CB4` (296 bytes). This is an isolated ordinary C++
match awaiting central integration and full-DOL acceptance.

The wrapper resumes the original worker thread and locks the owner mutex. It prepares with argument 0 and retries CARDProbeEx while the SDK reports -1, then unmounts and releases any work area. A zero result unlocks, suspends the worker and returns 1. The other path prepares with argument 1, unmounts/releases again, unlocks, suspends and returns that second result. A separate local for the second result preserves the native temporary register move. The frozen memory-card owner view supplies only verified offsets.

Run `python3 scratch/game_card_mount_result/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 296 emitted text bytes, the original global symbol
and 23 actual relocations. The verifier checks every allocated
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
