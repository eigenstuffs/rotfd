# Parent-composed render transform

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/render_transform_parent.cpp` reconstructs `fn_8027B508`, original
`.text` range `8027B508..8027B790` (648 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The recovered owner layout matches the neighboring independent transform
routine: rotation 0x30, matrix 0x78, translation 0xB8, transform 0xC8, scale
0xD8 and output pointer 0x124. The function generates and scales its local
matrix, adds translation and the original homogeneous constant, then composes
it with the parent's output matrix. It composes the unscaled 3-by-3 rotation
with the parent's rotation into its own rotation member. The 4-by-4 product
returns a local value; the 3-by-3 product constructs its return value directly,
which reproduces the original distinct temporary and copy behavior.

Run `python3 scratch/game_render_transform_parent/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all 648 text bytes and four actual relocations.
The verifier checks every allocated byte, exact original global function extent,
relocation site/kind/symbol/addend/target, and SDA21 base and displacement. Real
relocations are applied before comparison against the protected original DOL.

No weak helpers, initialized data, BSS, padding or other allocated sections are
emitted. All three matrix helpers and the constant retain external ownership.
Candidate, actual-relocation and original-metadata JSON preserve hashes and
dependencies. Original extabindex, `.ctors` and `.dtors` audits find no overlapping
exception entry or table reference. This partial text-only split leaves adjacent
functions and data externally owned. Central integration must still pass full
DOL hash, native objdiff, source-extent and regression checks. No new symbols,
headers, owned data or special flags are needed.
