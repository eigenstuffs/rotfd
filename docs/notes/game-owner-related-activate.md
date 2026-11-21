# Owner related activation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_related_activate.cpp` reconstructs `fn_80249BA8`, original
`.text` range `80249BA8..80249CDC` (308 bytes), as ordinary C++.

The function first invokes the existing root activation predicate and returns
false when it fails. It then walks the handle array at offset 0xB8, invokes the
virtual activation method at table slot 0x1C for each resolved object, looks up
its related world handle through the existing helper, and invokes that object's
same virtual method. It returns true after processing the complete array. The
native resolver performs the signed index/generation comparison without an
additional bounds or null check. The local base view places the vptr at offset
eight and emits no owned table.

Run `python3 scratch/game_owner_related_activate/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce every allocated byte, the exact global function
extent and all actual relocation sites, kinds, symbols, addends and targets.
Relocated instructions are compared directly against the protected original
DOL. No weak helpers, owned data, BSS, padding or other allocated sections are
emitted. Original globals and called helpers retain their original ownership.
Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference
into this range. Candidate, relocation and original metadata JSON preserve
hashes and dependencies.

This partial text-only split leaves neighboring functions and data external.
Central integration must pass full DOL hash, native objdiff, source-extent and
regression checks. No new symbols, shared headers or special flags are needed.
