# Native enum function retention

The isolated scene enum-map object matches both original functions `80031CB0`
and `80031D0C` and their complete 56-byte pair of natural compiler switch
tables at `802B1960..802B1998`. The native full link initially discarded both
unreferenced functions and their tables. The failed DOL, ELF, configuration
and build log remain in `scratch/continuation_20261010/enum-function-retention/`.

The existing native `FORCEACTIVE` configuration now retains these two original
public entries by their unchanged names. Their real local table relocations
retain the tables naturally. No source, object payload, table contents, entry
identity or expected hash was changed. Both functions and both complete tables
are present at their exact original addresses in the restored full DOL.

A separately frozen adoption pins the source, canonical owner, original
handoff and ownership audit. The repeating outer native audit recompiles the
source, checks exact production/frozen-object equality, runs the unchanged
strict allocated-byte and relocation verifier, checks all four final ELF
symbols and original bytes, validates the native retention directive and
requires the original complete DOL SHA1. Its acceptance wrapper preserves all
previous collector, Name-pointer, native weak-discard, ownership and regression
checks. Two guard tests include ten independent metadata rejection cases.

Full native acceptance passed for `motion-enum-container-startup`. This adds
184 matching code bytes and 56 original table bytes while preserving the full
progress denominator.
