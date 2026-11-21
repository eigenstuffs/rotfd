# Callback deep typed-handle assignment

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`fn_80259258` reconstructs 252 text bytes at `0x80259258..0x80259354`.
It calls the existing callback initializer, tests the 64-bit flag `0x40`,
looks up the original pooled name, and replaces the handle at owner offset
`0x80` through release/copy/retain operations. The raw lookup result and the
typed copy retain their distinct native destructor flags, -1 and 0.

The typed copy uses five ordinary inline initialization layers. These
reproduce all five native zero stores, including the transition from direct
stack accesses to the retained subobject pointer. The private views describe
only these observed operations and fields; the original class identities and
complete hierarchy remain unknown. Existing frozen handle declarations are
reused without modification.

The GC/1.3.2 compiler emits the exact 252-byte strong entry followed by seven
unused weak destructors totaling 672 bytes. The manifest records each weak
function's complete extent, binding and raw SHA-256, separately from the
retained original entry. No retained relocation references these helpers.
Only the 252 original bytes are claimed, and full-link acceptance must prove
that all seven unused helper symbols are absent from the final executable.

`scratch/game_callback_deep_handle/verify.py` recompiles the frozen source and
checks every allocated byte, complete function extents and actual relocations
without masks. The central integrator audits the complete original exception
and startup tables before registration. Original vtables, pooled strings,
neighboring functions and all non-text data keep their existing ownership.
