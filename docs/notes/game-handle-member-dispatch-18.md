# Handle member dispatch 18

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-handle-member-dispatch-18.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/handle_member_dispatch_18.cpp` reconstructs `fn_80260F64`, 144 bytes at
`80260F64..80260FF4`.

For the handle at receiver offset18, it calls the original resolver as a
nonnull guard, independently resolves the handle through the generation-checked
manager table, then dispatches virtual slot1C through the resolved object
(vptr08). The independent second resolution and absence of a second null
guard are preserved.

The frozen handle layout supplies the exact generation/index resolution.
The new handle_member_dispatch_internal.h declares a virtual interface with
a nonpolymorphic eight-byte base and no method bodies. It emits no new
virtual table or helper functions.

Run `python3 scratch/game_handle_member_dispatch_18/verify.py`. Standard optimized GC/1.3.2
Game flags reproduce all 144 emitted text bytes after 3 actual relocations.
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
