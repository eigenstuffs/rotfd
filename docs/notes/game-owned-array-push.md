# Owned array push

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owned_array_push.cpp` reconstructs `fn_8023F45C`, original `.text` range `8023F45C..8023F578` (284 bytes), as ordinary C++.

Grows the handle array capacity by 32 when needed through the original allocator, placement-initializes a newly appended handle, copies and retains it, and returns its index. Allocation, resize and release paths preserve original ownership and byte counts.

Run `python3 scratch/game_owned_array_push/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
