# Byte-buffer reset

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/byte_buffer_reset.cpp` reconstructs `fn_8026EDF4`, the 124 bytes at
`8026EDF4..8026EE70`. After invoking the base reset, it releases the old buffer
when its capacity is nonzero, clears that descriptor, and allocates a fresh
160-byte buffer. The descriptor is at `C0`, with data, capacity and count in
that order. A zero prior capacity deliberately skips the clearing branch.

GC/1.3.2 with standard optimized Game flags reproduces all 124 emitted bytes
after seven actual relocations. Run:

```
python3 scratch/game_byte_buffer_reset/verify.py
```

The verifier requires one global function and only `.text`, with every byte
and relocation checked. There are no extra weak functions, initialized data,
BSS, constants, constructor/destructor or exception tables, or owned padding.
`candidate.json` and `actual_relocations.json` preserve the isolated evidence.
`original_metadata_audit.json` records complete original extabindex, `.ctors`
and `.dtors` hashes and bounds from the protected DOL: no exception entry
covers the retained range and no constructor/destructor entry targets it.

This is a partial text split. The neighboring constructor/destructor and the
original allocator storage remain under existing ownership. Full DOL linking,
native objdiff, source-extent auditing and regression checks remain the
integrator's acceptance step.

## Accepted integration

The production units were strictly verified before Matching promotion. The
full DOL passes the original SHA-1, `ninja changes` reports no regressions,
source-extent/progress audits pass, and all 26 unit tests pass. Referenced
external data and adjacent original functions remain with their existing owners.
