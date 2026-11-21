# Render transform and matrix copy

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/render_transform_copy.cpp` reconstructs `fn_8027B2E4`, original
`.text` range `8027B2E4..8027B508` (548 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The partial transform owner generates its matrix through the original helper,
saves its unscaled upper 3-by-3 block, applies the three scale values across
all four matrix columns, inserts translation and the original homogeneous
constant, copies the complete 64-byte matrix to its output, then restores the
saved 3-by-3 values into the owner's rotation member. The recovered field
offsets are rotation 0x30, matrix 0x78, translation 0xB8, transform 0xC8,
scale 0xD8 and output pointer 0x124.

Run `python3 scratch/game_render_transform_copy/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all 548 emitted text bytes and both actual
relocations. The verifier checks every allocated byte, exact original global
function extent, relocation site/kind/symbol/addend/target, and SDA21 base
selection and signed displacement. It applies real relocations before comparing
instructions against the protected original DOL.

No weak helpers, initialized data, BSS, padding or other allocated sections are
emitted. The helper and constant retain external ownership. Candidate,
actual-relocation and original-metadata JSON preserve hashes and dependencies.
The original extabindex, `.ctors` and `.dtors` audit finds no overlapping
exception entry or table reference into this range. This is a partial text-only
split; neighboring original functions and data remain external. Central
integration must still pass the full DOL hash, native objdiff, source-extent and
regression checks. No new symbols, headers, owned data or special flags are needed.
