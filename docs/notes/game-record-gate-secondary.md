# Record gate secondary

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/record_gate_secondary.cpp` reconstructs `fn_80248FEC`, original `.text`
range `80248FEC..8024906C` (128 bytes), as ordinary C++.

This function is an exact second instance of the conditional delegation at
80248590: check flags bit 19 at 0x120, require a target, invoke native virtual
slot 0x3C, then delegate record views at 0x20/0x1C/0xA0 to `fn_8026C094`.
Its local class view preserves the vptr at offset eight without emitting any
vtable, constructor or destructor storage. The false paths return 0.

Run `python3 scratch/game_record_gate_secondary/verify.py`. Standard optimized GC/1.3.2 Game flags
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
