# Resource-slot reset at 801E5724

`src/Game/resource_slot_reset.cpp` owns the partial text split
`801E5724..801E5C1C`: one function, 1,272 bytes, no data.
Names describe observed behavior and are provisional original-class identities.

The function searches occupied slots by resolved object identity, toggles the
found occupancy bit, invokes `fn_80240120` with zero, clears retained references
at target offsets 10, 1C, 20, 24, 28 and 130, and resets the input handle.
Setters for 1C and 20 also invoke `fn_8023D648`. The 130 setter makes a retained
copy before assignment; construction and cleanup order matter for matching.
The original assumes the requested handle is present: there is no negative
index guard after the search. This reconstruction preserves that behavior.

The partial target and manager layouts include opaque fields. Existing native
handle construction, destruction, retain/release and generation-checked lookup
are reused. Different derived handle layers reproduce the observed zero writes
and temporary cleanup, without source assembly.

`scratch/game_resource_slot_reset/verify.py --production` verifies all 1,272
retained bytes after applying all 38 actual relocations. It accounts for all
1,624 emitted text bytes: four unreferenced weak helpers total 352 bytes and
receive no credit. The final ELF proof confirms their absence and the exact
retained function. The full DOL is byte-identical to the immutable reference.

All 651 linked source units remain exact; source/header/object hashes, extent
and assembly audits, progress exports and 23 tests pass. The initial baseline
is unchanged. Existing `ninja changes` fallback/native-padding accounting
warnings remain; the source-unit comparison shows no source regressions.
Evidence: `scratch/resource_slot_reset_checkpoint.json`.

Adjacent pool routines at 801E5C1C, 801E5D78 and 801E5EA4 now also match;
see [pool evidence](game-resource-slot-pool.md) for their separate split. All other functions and original data remain outside
this partial source split.
