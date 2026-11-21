# Owner index record copy

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_index_record_copy.cpp` reconstructs `fn_80232158`, original `.text` range `80232158..80232290` (312 bytes), as ordinary C++.

Resizes the output record buffer to the input count, copies each signed index in an 80-byte record, resolves valid owner indices and forwards their record conversion to the existing helper. Sets the output scalar at offset 0x44 after the loop. All globals, original tables and called helpers keep their existing ownership.

Run `python3 scratch/game_owner_index_record_copy/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
