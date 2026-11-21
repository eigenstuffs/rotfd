# Word-array owner destruction at offset 0xFC

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/word_array_destroy_fc.cpp` reconstructs `fn_80271064`, original `.text` range
`80271064..802711E8` (388 bytes). This is an isolated ordinary C++
match awaiting central integration and full-DOL acceptance.

The partial owner installs its original table at offset 8, clears the word arrays at offsets 0x108 and 0xFC in reverse order, calls the original base cleanup, and releases the owner when the signed low half of the deleting argument is positive. The shared twelve-byte word-array descriptor and ordinary primitive pseudo-destructor loop reproduce the native counter loops. Nullable member checks and repeated pointer clearing remain as observed.

Run `python3 scratch/game_word_array_destroy_fc/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 388 emitted text bytes, the original global symbol
and 12 actual relocations. The verifier checks every allocated
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
