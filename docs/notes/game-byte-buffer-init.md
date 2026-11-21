# Byte-buffer initializer

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-byte-buffer-init.json`.

`src/Game/byte_buffer_init.cpp` reconstructs `fn_8026ED8C`, the 104 bytes at
`8026ED8C..8026EDF4`. The original constructor entry invokes `fn_80249B50`,
installs the original virtual-table address at `8`, zeroes its three-word
buffer descriptor at `3C`, sets capacity 160 and allocates that buffer. It
returns the receiver.

GC/1.3.2 with standard optimized Game flags reproduces all 104 emitted bytes
after six actual relocations. Run:

```
python3 scratch/game_byte_buffer_init/verify.py
```

The complete emitted object contains one global function and only `.text`.
There are no extra weak functions, constants, data, BSS, constructor/destructor
tables, exception tables or owned padding. The original extabindex, `.ctors`
and `.dtors` audit finds no overlapping exception entry or startup/shutdown
reference. `candidate.json`, `actual_relocations.json` and
`original_metadata_audit.json` preserve the isolated evidence.

This is a partial text split. The original virtual table at `802ED2F0`, base
constructor, neighboring reset/destructor and allocator data retain existing
ownership. Full DOL linking, native objdiff, source-extent auditing and
regression checks remain the integrator's acceptance step.
