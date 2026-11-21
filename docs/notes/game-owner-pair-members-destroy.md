# Owner pair members destroy

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_pair_members_destroy.cpp` reconstructs `fn_80231ABC`, original `.text`
range `80231ABC..80231B28` (108 bytes), as ordinary C++.

Destroys the second member at offset 0x4C and the first member at offset 0x14, in that order with deleting flag -1, then conditionally releases owner storage. The local layout views emit no storage. All original tables, globals and called helpers retain their original ownership.

Run `python3 scratch/game_owner_pair_members_destroy/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
