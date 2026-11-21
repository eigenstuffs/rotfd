# Owned array compact

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owned_array_compact.cpp` reconstructs `fn_8023AB78`, original `.text` range `8023AB78..8023AC94` (284 bytes), as ordinary C++.

Compacts the handle array in place, removing unresolved handles and handles rejected by the original manager predicate. Each removal releases the layered handle and copies the remaining suffix; retained entries advance the index. The removal helper computes the suffix pointer before decrementing the count, preserving native load order and avoiding an alias-induced count reload.

Run `python3 scratch/game_owned_array_compact/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
