# Owner gated operation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_gated_operation.cpp` reconstructs `fn_80231600`, original `.text` range `80231600..802316F8` (248 bytes), as ordinary C++.

Checks a per-index active byte, count and key, validates the owner handle, dispatches the existing keyed operation with a resolved object and scalar, then sets the active byte. The local layout describes the original offset-indexed arrays without emitting storage.

Run `python3 scratch/game_owner_gated_operation/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
