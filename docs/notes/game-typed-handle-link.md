# Typed handle link

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/typed_handle_link.cpp` reconstructs `fn_8023EEF0`, original `.text` range `8023EEF0..8023EFAC` (188 bytes), as ordinary C++.

Resolves the owner handles at offsets 0x1C and 0x20 using the signed generation/index fields. If the first object exists and has type 3 at offset 0x6C, invokes the existing link helper with both objects. The inline generation getter preserves the native manager-entry reload between resolutions.

Run `python3 scratch/game_typed_handle_link/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
