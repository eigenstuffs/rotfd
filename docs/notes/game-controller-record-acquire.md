# Controller record acquisition

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-controller-record-acquire.json`. The full normalized DOL
passes its original SHA-1, `ninja changes` shows no regressions, source extents
and generated progress checks pass, and all 26 unit tests pass.

`src/Game/controller_record_acquire.cpp` reconstructs `fn_80276590`, the 448
bytes at `80276590..80276750`. It saves the next record index, grows 64-byte
controller storage by eight slots when needed, increments the count, examines
the four PAD error bytes and records the selected physical-pad index in the
mapping area beginning at `50`. The existing logging and record-reset paths
retain the native signed-byte condition, including both observed assignments
of zero to that condition; this reconstruction does not alter that behavior.

The source reuses the frozen controller record and reset operation. A private
status view exposes the error byte at `2A` while advancing the receiver view
by twelve bytes per PAD status. A direct status-array pointer was two
instructions away because its induction pointer started at `20`; the receiver
view exactly preserves the original pointer and load offset. The private
mapping declaration is a partial view, not evidence for full object extent.

GC/1.3.2 with standard optimized Game flags reproduces every emitted byte
after fourteen actual relocations. Run:

```
python3 scratch/game_controller_record_acquire/verify.py
```

The complete emitted object contains one global function and `.text` only,
with no weak helpers, constants, data, BSS, startup/shutdown or exception
tables, or owned padding. The protected-DOL original extabindex, `.ctors`
and `.dtors` audit finds no overlapping exception entry or reference into
this range. `candidate.json`, `actual_relocations.json` and
`original_metadata_audit.json` preserve all isolated checks.

This partial text split leaves the original logging string at `802AF100`,
global manager, allocator storage and neighboring engine functions under
existing ownership. Full DOL linking, native objdiff, source-extent auditing
and regression checks remain the integrator's acceptance step.
