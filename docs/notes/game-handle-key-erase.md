# Handle key erase

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-handle-key-erase.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/handle_key_erase.cpp` reconstructs `fn_8026413C`, 208 bytes at
`8026413C..8026420C`.

It scans the handle-array descriptor at receiver offset0C, resolves each
entry with the original resolver, compares the first object word with the
supplied target word, then destroys and removes the first matching handle.
Removal shifts the remaining bytes with the native memcpy call, decrements
the count and returns 1. No match returns zero. Separate comparison locals
preserve the native comparison operand order.

The frozen handle headers supply the native four-byte handle and external
destructor. Two private inheritance layers retain the two observed nullable
subobject checks before the external destructor. These layers are an ABI
reconstruction, not a recovered original class name. The native memcpy call
is retained even when its ranges can overlap.

Run `python3 scratch/game_handle_key_erase/verify.py`. Standard optimized GC/1.3.2
Game flags reproduce all 208 emitted text bytes after 3 actual relocations.
The strict inventory requires the original global function and `.text` only,
without weak helpers, owned data, BSS or padding. Every allocated byte and
relocation matches the protected DOL. The original extabindex, `.ctors` and
`.dtors` audit finds no overlapping exception entry or reference into this
range. Candidate, actual relocation and original metadata JSON preserve the
complete isolated evidence.

This partial text split leaves original tables, manager storage, allocator,
external callees and neighboring functions under existing ownership. Full
DOL, native objdiff, source-extent and regression acceptance remain the
integrator's checks.
