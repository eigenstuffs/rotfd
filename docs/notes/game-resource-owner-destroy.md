# Resource owner destroy

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/resource_owner_destroy.cpp` reconstructs `fn_80243E90`, original `.text`
range `80243E90..80243F28` (152 bytes), as ordinary C++.

Restores the resource owner table, conditionally frees the buffer at offset 0x70, performs the resource and root destruction sequence, and conditionally releases the owner storage. The local layout view emits no storage. External tables, storage manager and called helpers retain their original ownership.

Run `python3 scratch/game_resource_owner_destroy/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed.
