# Callback nested target flags

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two complete 300-byte functions reconstruct ordinary related-handle state
operations. `fn_8025529C` at `0x8025529C..0x802553C8` skips the operation
when flag `0x40000` is set; otherwise it activates owner handle `0x64` and
clears bit 0 in the nested target's word at `0xC`. `fn_802553C8` at
`0x802553C8..0x802554F4` skips when flag `0x20000` is set; otherwise it
deactivates handle `0x64` and sets the same nested flag.

The nested target is reached by resolving owner handle `0x58`, reading its
handle at `0x20`, and resolving that handle. Each generation/index lookup
retains the exact signed comparisons and original registry addressing. The
frozen transfer and related-target declarations are reused without edits;
additional local views describe only the `0x20` handle and `0xC` flag word.
Original full class identities, tables and non-text data remain external.

The manifests in `scratch/game_callback_nested_flags/final_integration.json`
account for all 600 allocated bytes and both complete global extents. The
individual verifiers in its `5529c` and `553c8` subdirectories recompile each
frozen source and apply every actual relocation without masks. No extra
helpers, functions, data, exception records or padding are emitted. Central
acceptance audits complete original exception/startup tables and checks the
full executable hash, source extents, baseline changes, progress and tests.
