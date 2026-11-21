# Object game list destructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ source in `src/Game/engine_game_lists_destructor.cpp` matches fn8022A1A0 at `8022A1A0..8022A560`, all 960 retained text bytes. GC 1.3.2 with the default Game flags emits one strong function, no other allocation or helper, and 38 actual relocations. Production executable acceptance remains with the root integrator.

After installing the existing ObjectsGame table, the entry frees three raw buffers at90,84 and78, then destroys handle arrays at6C,60 and54. Their three, three and two derived handle layers preserve the original repeated null checks. It destroys the native BitSet at44, the empty-element array at38, the three-layer handle array at2C, and the one-layer handle at28. Each array performs the original count loop, capacity-scaled allocator call and repeated null store. The entry then installs the existing ObjectsRoot table, calls the existing ObjectsOwner destructor with flag zero, conditionally frees the outer object for a positive signed-short flag, and returns the original pointer.

The dedicated header is a partial storage view, with observed destruction depth represented by ordinary inline derived handles. The original class identities of those layers and broader array meanings remain uncertain. Existing entry, native vtable and destructor identities remain unchanged; no consumer or declaration migration is proposed.

The frozen manifest is `scratch/engine_game_lists_destructor_20261011eg/final_integration.json`. Its verifier recompiles production source and checks all allocated bytes, exact symbol extents, actual relocation targets and frozen hashes. It audits the complete original extabindex `80015F60..8001F2C0`, ctors `80299920..80299980` and dtors `80299980..802999A0`, including descriptors, padding and terminators; none refers into this retained range. No data, BSS, owned padding, exception table, startup allocation or weak backup is emitted.

This is a partial text split. All referenced globals, native functions and tables, adjacent routines and original translation-unit data retain their existing owners. Central registration starts NonMatching and promotion requires the original DOL hash and standard acceptance checks.
