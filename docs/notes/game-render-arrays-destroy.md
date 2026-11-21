# Render-array owner destruction

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/render_arrays_destroy.cpp` reconstructs `fn_80275990`, original `.text` range
`80275990..80275A44` (180 bytes). This is an isolated ordinary C++
match awaiting central integration and full-DOL acceptance.

The partial owner installs the original table at offset 0x278 and invokes virtual slot 0x10. It clears the pointer at offset 0x9D8, destroys 128 twelve-byte elements at offset 0x3D8 and three at offset 0x3B4, then calls base cleanup and optionally releases the owner. Ordinary explicit calls to the original __destroy_arr runtime helper preserve the externally owned element destructor without inventing a renamed C++ destructor symbol. The private virtual interface has declarations only and emits no vtable.

Run `python3 scratch/game_render_arrays_destroy/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 180 emitted text bytes, the original global symbol
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
