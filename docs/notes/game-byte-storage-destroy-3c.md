# Byte-storage owner destruction at offset 0x3C

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/byte_storage_destroy_3c.cpp` reconstructs `fn_8026ECC0`, original `.text` range
`8026ECC0..8026ED8C` (204 bytes). This is an isolated ordinary C++
match awaiting central integration and full-DOL acceptance.

The partial owner installs its original table at offset 8 and clears its pointer/capacity/count descriptor at offset 0x3C. It then performs the original nullable member cleanup again before base cleanup and optional deletion. The second cleanup remains in the generated code even after the descriptor is cleared. The allocator call uses the observed capacity as its byte count; no wider owner layout is inferred.

Run `python3 scratch/game_byte_storage_destroy_3c/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 204 emitted text bytes, the original global symbol
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
