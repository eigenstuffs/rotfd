# Transform owner update

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/transform_owner_update.cpp` reconstructs `fn_80243FA8`, original
`.text` range `80243FA8..8024405C` (180 bytes), as ordinary C++.

It converts the supplied basis at offset 0x30 to a quaternion, combines the
owner rotation at offset 0x74, rotates the default forward direction, then
updates the owner's position from its offset plus the rotated direction. A
normal three-component vector constructor preserves the native simultaneous
component evaluation and subsequent stores. The explicit temporary quaternion
and vector retain the native calling ABI and stack layout.

Run `python3 scratch/game_transform_owner_update/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce every allocated byte, the exact global function
extent and all actual relocation sites, kinds, symbols, addends and targets.
Relocated instructions are compared directly against the protected original
DOL. No weak helpers, owned data, BSS, padding or other allocated sections are
emitted. External constants and helpers retain their original ownership.
Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference
into this range. Candidate, relocation and original metadata JSON preserve
hashes and dependencies.

This partial text-only split leaves neighboring functions and data external.
Central integration must pass full DOL hash, native objdiff, source-extent and
regression checks. No new symbols, shared headers or special flags are needed.
