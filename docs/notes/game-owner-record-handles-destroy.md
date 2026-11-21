# Owner record handles destroy

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_record_handles_destroy.cpp` reconstructs `fn_802319AC`, original `.text` range `802319AC..80231ABC` (272 bytes), as ordinary C++.

Sets the owner table, destroys four layered handles at offsets 0x1F0..0x1FC and four 0x74-byte records at offset 0x20, then invokes the original objects-owner destructor and optional deallocation. Nested member checks preserve the native inline destructor layers.

Run `python3 scratch/game_owner_record_handles_destroy/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
