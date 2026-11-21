# Render-record array clearing

`src/Game/render_record_clear.cpp` owns `fn_801E81AC` at
`801E81AC..801E8274`, 200 matching code bytes. The partial owner view locates
an array of 40-byte records at offset DA00; other owner fields and record
semantics remain opaque.

This is an inlined resize-to-zero operation. A grow branch handles a negative
count, including capacity replacement if capacity is also negative, then
constructs the newly included entries. A shrink branch destroys the old
entries. The record has trivial lifetime, so both loops retain only their
original CTR instructions. Ordinary placement construction and explicit
C++ destruction reproduce these loops without inline assembly. Resizing does
not free storage on the ordinary nonnegative-count shrink path.

`scratch/game_render_record_clear/verify.py --production` checks all 200 bytes
and three actual relocations, with no emitted weak helpers, data or alignment
credit. Final ELF proof and the full DOL hash pass. All 661 source units were
exact at acceptance, all 23 tests passed, and progress/extent/assembly audits
passed. The initial baseline is unchanged; existing fallback/native-padding
accounting warnings remain without source regressions. Evidence:
`scratch/render_record_clear_checkpoint.json`.
