# Handle group update

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/handle_group_update.cpp` reconstructs `fn_8023AAAC`, original `.text`
range `8023AAAC..8023AB78` (204 bytes), as ordinary C++.

When the signed disabled byte at offset 0x0C is zero, walks the generation/index handle array and forwards the double parameter to the existing updater. The recovered double ABI preserves the native full-width f31 save without a single-precision conversion. The local layout views emit no storage. All original tables, globals and called helpers retain their original ownership.

Run `python3 scratch/game_handle_group_update/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
