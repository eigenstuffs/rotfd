# Six-buffer owner initialization

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/six_buffer_init.cpp` reconstructs `fn_80271B04`, original `.text`
range `80271B04..80271B84` (128 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The partial owner calls the original six-handle resource constructor and installs its derived table. It invokes the original __construct_array helper for four eight-byte vectors at offset 0x8C and six twelve-byte buffer descriptors at offset 0xAC, then sets the active byte at offset 0x88. Vector/buffer initializer and destructor bodies remain externally owned; explicit ordinary calls preserve the original runtime-helper ABI.

Run `python3 scratch/game_six_buffer_init/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 128 emitted text bytes, the original global symbol and
11 actual relocations. Every allocated byte and exact relocation
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
