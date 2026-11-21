# Twelve-word owner initialization

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/twelve_word_init.cpp` reconstructs `fn_8026E7C4`, original `.text`
range `8026E7C4..8026E834` (112 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The partial owner calls its original base initializer, installs the original table at offset 8, and zeros twelve consecutive words at offsets 0xEC..0x118. Explicit ordinary field stores reproduce the native scheduling; a counted source loop was four instruction positions away despite equal text size. No broader meaning is assigned to the initialized words.

Run `python3 scratch/game_twelve_word_init/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 112 emitted text bytes, the original global symbol and
3 actual relocations. Every allocated byte and exact relocation
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
