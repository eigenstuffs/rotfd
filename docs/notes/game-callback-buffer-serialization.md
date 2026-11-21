# Callback buffer serialization

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`fn_80252FD4` reconstructs the complete 244-byte function at
`0x80252FD4..0x802530C8`. It runs the native base serializer, reads the
four-byte length, copies the payload into owned storage, and advances the
input cursor. The inline buffer-assignment operation preserves length -1 as
`strlen(source)`, releases prior storage, and allocates/copies when length is
nonzero. The original post-copy helper runs inside that nonzero branch;
it does not run for an empty payload.

The partial owner records only data at `0xC` and signed length at `0x10`.
Original allocation metadata, strings, allocator and neighboring operations
retain external ownership. No additional source functions or data are emitted.

`scratch/game_callback_buffer_serialization/verify.py` recompiles the frozen
source and verifies every allocated byte, global function extent and actual
relocation against the original DOL. Central integration also audits the full
exception/startup tables and requires the complete original executable hash,
source extents, baseline changes, generated progress and test-suite checks.
