# Owner handle visit

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_handle_visit.cpp` reconstructs `fn_802431F8`, original `.text`
range `802431F8..802432A8` (176 bytes), as ordinary C++.

Iterates the handle array at offset 0xEC using the count at 0xE4, resolves each generation/index through the external manager, and calls the existing object visitor. The native resolver performs no index bounds check. The local layout views emit no storage. All tables, globals and called helpers retain their original ownership.

Run `python3 scratch/game_owner_handle_visit/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed.
