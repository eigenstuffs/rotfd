# Owner conditional notify

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_conditional_notify.cpp` reconstructs `fn_8022EBAC`, original `.text` range `8022EBAC..8022EC14` (104 bytes), as ordinary C++.

Invokes the existing three-pointer owner operation, calls virtual slot 0x12C with the caller index only when that operation succeeds, and returns its signed-byte result. Local declarations emit no storage; original globals, tables and called helpers retain their ownership.

Run `python3 scratch/game_owner_conditional_notify/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
