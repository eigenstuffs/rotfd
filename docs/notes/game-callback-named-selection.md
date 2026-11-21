# Callback named-handle selection

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`fn_802597A4` reconstructs 232 text bytes at `0x802597A4..0x8025988C`.
After the native initialization it checks flag 8 through an ordinary signed
byte predicate. Flag `0x10` chooses between the original pooled name and the
original eight-byte small-data string. Each branch obtains a raw handle,
passes it to the existing typed assignment operation, and performs the
native cleanup with flag -1.

The small-data declaration has its verified eight-byte extent; this lets
the compiler emit the original SDA21 address rather than a high/low address
pair. All actual relocations are applied and compared without masking.
The frozen typed-assignment declarations are reused without edits. No
extra helpers, data, exception records or padding are emitted.

`scratch/game_callback_named_selection/verify.py` checks the complete frozen
production object and exact function extent. Original pooled data, tables
and neighboring functions remain external. Central integration audits the
full original exception and startup tables and checks the whole executable
hash, baseline changes, source extents, progress exports and test suite.
