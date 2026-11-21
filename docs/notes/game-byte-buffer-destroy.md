# Byte-buffer destruction entry

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-byte-buffer-destroy.json`.

`src/Game/byte_buffer_destroy.cpp` reconstructs `fn_8026EE90`, the 212 bytes
at `8026EE90..8026EF64`. For a nonnull receiver it installs the original
virtual table at `8`, resets the buffer at `C0` when capacity is nonzero, then
runs the member's pointer-guarded release. Both paths clear data, capacity and
count. It invokes the base destructor with flag 0 and frees the receiver when
the signed low half of the deletion argument is positive. The original
nullable member-address check is retained.

GC/1.3.2 with standard optimized Game flags reproduces all 212 emitted bytes
after twelve actual relocations. Run:

```
python3 scratch/game_byte_buffer_destroy/verify.py
```

The complete emitted object contains one global function and only `.text`,
with no extra weak functions, constants, data, BSS, constructor/destructor
tables, exception tables or owned padding. The protected-DOL original
extabindex, `.ctors` and `.dtors` audit finds no overlapping exception entry or
startup/shutdown reference. `candidate.json`, `actual_relocations.json` and
`original_metadata_audit.json` preserve all isolated checks.

This partial text split leaves the virtual table at `802ED348`, allocator
storage, base destructor and neighboring engine functions under existing
ownership. Full DOL linking, native objdiff, source-extent auditing and
regression checks remain the integrator's acceptance step.
