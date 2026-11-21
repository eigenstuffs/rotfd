# Six-buffer resource destruction

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/six_buffer_destroy.cpp` reconstructs `fn_80271A00`, original `.text`
range `80271A00..80271B04` (260 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The partial owner installs its original table at offset 8 and clears six twelve-byte buffer descriptors beginning at offset 0xAC. It then calls the original __destroy_arr runtime helper for those six descriptors, installs the original six-handle resource table, destroys six four-byte handles beginning at offset 0x10, and performs the original resource/root cleanup before optional deletion. Ordinary explicit calls to the original array destruction helper preserve original externally owned element destructors. The nested nullable checks remain as observed.

Run `python3 scratch/game_six_buffer_destroy/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 260 emitted text bytes, the original global symbol and
19 actual relocations. Every allocated byte and exact relocation
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
