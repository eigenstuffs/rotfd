# Handle resolved erase

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-handle-resolved-erase.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/handle_resolved_erase.cpp` reconstructs `fn_80263524`, 300 bytes at
`80263524..80263650`.

It scans a count/capacity/data handle descriptor, compares independently
resolved objects using the original signed generation and 24-bit index fields,
then destroys and removes the first matching handle. Removal decrements the
count and shifts the remaining bytes with the native memcpy call. It returns
no value and stops after the first removal.

The frozen handle headers supply the native four-byte handle and external
destructor. Two private inheritance layers retain the two observed nullable
subobject checks before the external destructor. These layers are an ABI
reconstruction, not a recovered original class name. The native memcpy call
is retained even when its ranges can overlap.

Run `python3 scratch/game_handle_resolved_erase/verify.py`. Standard optimized GC/1.3.2
Game flags reproduce all 300 emitted text bytes after 4 actual relocations.
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
