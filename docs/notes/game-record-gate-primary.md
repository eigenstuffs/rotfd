# Record gate primary

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/record_gate_primary.cpp` reconstructs `fn_80248590`, original `.text`
range `80248590..80248610` (128 bytes), as ordinary C++.

The function checks bit 19 of the supplied flags word at offset 0x120, then
requires a nonnull target. It invokes native virtual slot 0x3C on the source and
passes the resulting pointer plus record views at 0x20/0x1C/0xA0 to the existing
`fn_8026C094` helper, returning that helper's result. The false paths return 0.
Its local class view preserves the native vptr at offset eight and emits no
vtable, constructor or destructor storage.

Run `python3 scratch/game_record_gate_primary/verify.py`. Standard optimized GC/1.3.2 Game flags
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
