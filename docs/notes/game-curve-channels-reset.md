# Curve channels reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/curve_channels_reset.cpp` reconstructs `fn_80239A7C`, original `.text` range `80239A7C..80239C80` (516 bytes), as ordinary C++.

Resolves the owner handle and applies each of ten populated curve channels at the original constant time to the associated object fields. Invokes virtual slot 0x24, resets elapsed time, masks the owner flags and conditionally reactivates a nonzero-duration animation. The root storage and virtual-method declarations preserve the original vptr location and indirect call sequence.

Run `python3 scratch/game_curve_channels_reset/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
