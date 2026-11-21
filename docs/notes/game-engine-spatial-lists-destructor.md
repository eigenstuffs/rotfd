# Spatial binding list destructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ source in `src/Game/engine_spatial_lists_destructor.cpp` matches fn8024C8CC at `8024C8CC..8024CDCC`, all 1,280 retained text bytes. GC 1.3.2 uses the default Game flags plus `-use_lmw_stmw on`, reproducing the original register save and restore group. The compiler emits one strong function, no other allocation or helper, and 44 actual relocations. Production executable acceptance remains with the root integrator.

The entry installs the existing SpatialBinding table and unregisters the signed index at3C when the context manager at144 exists and the index is nonnegative. It destroys the nested number arrays at70, the three-layer handle array at64, three arrays of twenty-four-byte records at58,4C and40, the two-layer handle array at30, the two-layer handle at2C, and the two-layer handle array at20. Each twenty-four-byte record has a two-layer handle at04, unknown remaining storage, and one additional derived record layer. Those ordinary member and base lifetimes preserve every original repeated null check. The nested arrays also preserve the compiler's empty-element loop and its remainder induction update.

The entry then installs the existing SpatialBase and Resource tables, invokes the existing Root destructor with flag zero, conditionally frees the object for a positive signed-short flag, and returns its original pointer. The dedicated header is a partial destruction view. Broader record meanings and original derived class names remain uncertain. Existing entry and native dependency identities remain unchanged, so the accepted external consumer in `base_destructor_8026f010.cpp` needs no edits.

The frozen manifest is `scratch/engine_spatial_lists_destructor_20261011eh/final_integration.json`. Its verifier recompiles production source and checks all allocated bytes, exact symbol extents, actual relocation targets and frozen hashes. Complete original extabindex `80015F60..8001F2C0`, ctors `80299920..80299980` and dtors `80299980..802999A0` audits include descriptors, padding and terminators and find no reference into this retained range. No data, BSS, padding, exception table, startup allocation or weak backup is emitted.

This is a partial text split. Original globals, native functions, vtables, adjacent code and translation-unit data retain their existing owners. Central registration starts NonMatching with the stated extra option; promotion requires the original DOL hash and standard acceptance checks.
