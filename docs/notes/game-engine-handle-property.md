# Engine handle float property

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/engine_handle_property.c` reconstructs the complete 116-byte ordinary C
routine `fn_80248CAC`, at `80248CAC..80248D20`, with global scope. It uses standard
Game GC/1.3.2 flags without additions and the new dedicated
`include/Game/engine_handle_property.h`; no existing declarations change.

The owner stores signed count at 0xB0 and packed-handle pointer at 0xB8. For each
handle, the routine resolves through the original context manager at 0x118 and
stores the supplied float at object offset 0x18. Handles contain signed eight-bit
generation and signed 24-bit index fields. The manager's pointer at 8 addresses
16-byte entries with object at zero and signed generation byte at 0xC. The inline
resolver compares generations and yields object or null; the subsequent store
preserves the original unconditional behavior. No extra functions are emitted.

`scratch/engine_handle_properties_20261010t/final_integration.json` records full
extent, binding, flags and both actual HA/LO relocations. Fresh production
compilation and strict verification pass: every relocated byte equals the
protected original DOL without masking, and additional functions or unexpected
allocated sections are rejected. The original whole-function extent and entire
3,141-entry extabindex, 24-entry ctor and 8-entry dtor scans pass without records
referencing this text. Source data, BSS, exception and startup ownership are zero.
Original context data, neighboring text and other original sections retain their
current owners. Central NonMatching registration and final DOL/native regression
acceptance remain the integrator's promotion steps. The related 240-byte
8024CEDC dispatch probes remain private and uncredited; all artifacts are preserved.
