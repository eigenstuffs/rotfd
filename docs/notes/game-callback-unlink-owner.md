# Callback unlink owner

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/callback_unlink_owner.cpp` reconstructs `fn_802601C8`, original `.text`
range `802601C8..802602B8` (240 bytes), as ordinary C++.

The function walks a callback linked list, resolving each node's generation/index
handle through the existing object manager. It unlinks and releases nodes whose
resolved owner matches and whose key matches when a nonzero key is requested.
It preserves the native direct handle lookup without introducing a new bounds
check, and resumes traversal from the previous node or list head after release.
The local partial layouts record 16-byte manager entries and 12-byte callback
nodes; they emit no storage.

Run `python3 scratch/game_callback_unlink_owner/verify.py`. Standard optimized GC/1.3.2 Game flags
reproduce every allocated byte, the exact global function extent and all actual
relocation sites, kinds, symbols, addends and targets. SDA21 relocations, where
present, include section/base/displacement checks. Relocated instructions are
compared directly against the protected original DOL. No weak helpers, owned
data, BSS, padding or other allocated sections are emitted. External strings,
globals, allocator storage and called helpers retain their original ownership.
Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference
into this range. Candidate, relocation and original-metadata JSON preserve
hashes and dependencies.

This partial text-only split leaves neighboring functions and data external.
Central integration must pass full DOL hash, native objdiff, source-extent and
regression checks. No new symbols, shared headers or special flags are needed.
