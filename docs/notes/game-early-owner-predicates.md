# Early owner predicates and selector

Three frozen isolated ordinary C++ reconstructions, 2026-10-11; central integration pending. New header `include/Game/early_owner_predicate_views.h` has exactly three consumers. Standard GC1.3.2 plus `-O4,s` and `-Cpp_exceptions on` for every unit.

| Source | Function | Text extent | Bytes | extab | extabindex |
| --- | --- | --- | ---: | --- | --- |
| early_owner_active_equals_80065ed4.cpp | fn_80065ED4 | 80065ED4..80065F8C | 184 | 8000BA04..8000BA0C | 800189C0..800189CC |
| early_owner_active_target_80065f8c.cpp | fn_80065F8C | 80065F8C..800660E0 | 340 | 8000BA0C..8000BA14 | 800189CC..800189D8 |
| early_owner_selector_800660e8.cpp | fn_800660E8 | 800660E8..800661B8 | 208 | 8000BA14..8000BA1C | 800189D8..800189E4 |

The first two share a short-circuit active condition: current selection handle at 0x1AC is valid, or self has any of states 0x18..0x1B according to fn_800665D8. The equality predicate compares the supplied signed byte with one when active, otherwise zero. The target predicate resolves the selected resource; a non-null resource supplies a handle through genuine native virtual slot 0x9C with argument zero, and its generation-checked resolved pointer is compared with the supplied target. No retained temporary is introduced.

The selector tests states 0x1D,0x1E,0x1F,0x20,0x23,0x2A in order and returns 0,1,2,3,4,5 respectively (zero also when none apply). Its 32-bit unsigned return avoids an extra compiler byte-normalization instruction. The previously accepted Python wrapper declares this external as unsigned byte; all native results are 0..5, and its actual call/return behavior remains identical without changing that caller.

Combined ownership: **732 text +60 EH/index =792 allocated bytes**. Actual relocation checks cover 21 text references, six EH/index references, and three nonallocated compiler metadata references. No helper functions, data, BSS or padding are emitted/claimed. The eight-byte gap 800660E0..800660E8 remains original ownership.

Manifest list `scratch/game_early_owner_predicates/manifest-list.json` contains three independent units. Per-function strict verification recompiles source and checks all allocated original bytes, actual local object names/extents, and complete original extabindex/ctors/dtors tables. Only each function's original retained EH entry is owned. Original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Sources/header/evidence are frozen for root integration.

The adjacent fn800669D0 (208-byte flag/controller query) remains private/uncredited. Direct boolean forms optimize away native first-flag materialization; explicit signed-byte condition variants preserve that branch but retain scheduling/register differences. Private probes are preserved unchanged after this handoff.
