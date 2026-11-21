# Owner handle start16c

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_handle_start16c.cpp` reconstructs `fn_80229BBC`, original `.text` range `80229BBC..80229C30` (116 bytes), as ordinary C++.

Resolves the owner handle at offset 0x16C and forwards the caller argument plus the original enabled flag to the existing start helper when the object exists. Signed generation and 24-bit index checks reproduce the native lookup. Local layout declarations emit no storage. Existing helpers, manager global and original tables retain their ownership.

Run `python3 scratch/game_owner_handle_start16c/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
