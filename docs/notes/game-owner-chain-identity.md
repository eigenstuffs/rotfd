# Owner chain identity

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_chain_identity.cpp` reconstructs `fn_80240F28`, original `.text`
range `80240F28..80240FC4` (156 bytes), as ordinary C++.

The function follows generation/index handles stored at offset 0x0C until the
existing object manager yields no parent, then returns the final object's
identity at offset four. It retains the native direct lookup and generation
comparison without adding a bounds check. Explicit ordinary if/return branches
in the inline resolver preserve the native parent-register assignment; a ternary
form generated redundant temporary copies. The local owner and 16-byte entry
views emit no storage.

Run `python3 scratch/game_owner_chain_identity/verify.py`. Standard optimized GC/1.3.2 Game flags
reproduce every allocated byte, the exact global function extent and all actual
relocation sites, kinds, symbols, addends and targets. Relocated instructions
are compared directly against the protected original DOL. No weak helpers,
owned data, BSS, padding or other allocated sections are emitted. External
objects and called helpers retain their original ownership. Original
extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this
range. Candidate, relocation and original-metadata JSON preserve hashes and
dependencies.

This partial text-only split leaves neighboring functions and data external.
Central integration must pass full DOL hash, native objdiff, source-extent and
regression checks. No new symbols, shared headers or special flags are needed.
