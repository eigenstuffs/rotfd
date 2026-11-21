# Owner handle assign1c

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_handle_assign1c.cpp` reconstructs `fn_8023EE7C`, original `.text`
range `8023EE7C..8023EEF0` (116 bytes), as ordinary C++.

Releases the existing handle at owner offset 0x1C, copies the caller handle, retains it and invokes the existing owner refresh helper. Both manager operations preserve their original order and reference-count deltas. The local layout views emit no storage. All original tables, globals and called helpers retain their original ownership.

Run `python3 scratch/game_owner_handle_assign1c/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
