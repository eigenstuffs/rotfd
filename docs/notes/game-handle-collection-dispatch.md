# Handle collection dispatch

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-handle-collection-dispatch.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/handle_collection_dispatch.cpp` reconstructs `fn_8026464C`, 160 bytes at
`8026464C..802646EC`.

It calls the original base slot1C implementation and returns zero when its
signed byte is zero. Otherwise it iterates the handle-array descriptor at
receiver offset0C, calls the original resolver as a guard, calls it again
for virtual dispatch through slot1C (vptr08), and returns 1.

The frozen handle layout supplies the exact generation/index resolution.
The new handle_member_dispatch_internal.h declares a virtual interface with
a nonpolymorphic eight-byte base and no method bodies. It emits no new
virtual table or helper functions.

Run `python3 scratch/game_handle_collection_dispatch/verify.py`. Standard optimized GC/1.3.2
Game flags reproduce all 160 emitted text bytes after 3 actual relocations.
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
