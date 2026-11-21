# Callback registration group

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/callback_registration_group.cpp` reconstructs `fn_80260BFC`, original `.text`
range `80260BFC..80260C7C` (128 bytes), as ordinary C++.

The function registers three existing callback names and small-data keys through
`fn_8025FD04`, passing the owner member at 0x20 and two existing global manager
pointers at 0x144/0x158. The external pooled message array is addressed as an
array object before casting to a character pointer, preserving its native common
base. The small-data strings retain their original 5/6/5-byte declarations.

Run `python3 scratch/game_callback_registration_group/verify.py`. Standard optimized GC/1.3.2 Game flags
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
