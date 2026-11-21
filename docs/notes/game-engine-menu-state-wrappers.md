# Menu state wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

**Isolated exact handoff, awaiting central acceptance.** Two ordinary C++ units reproduce three complete original functions, 120 text bytes and three real relocations with standard GC1.3.2 Game flags. `engine_menu_root_enabled.cpp` owns `fn_8021B47C`, `8021B47C..8021B4B0`,52bytes. `engine_menu_flag_refresh.cpp` owns `fn_8021B7BC`, `8021B7BC..8021B7E0`,36bytes and `fn_8021B7E0`, `8021B7E0..8021B800`,32bytes. Dedicated partial declarations are in `include/Game/engine_menu_state_wrappers.h`.

The first function calls the existing native Root slot1C and normalizes the signed-char result to signed-char0/1. The second stores the incoming flag at offset34 then calls the existing owner refresh operation80213A18. The third forwards directly to the existing owner operation802139D8. Ordinary comparisons, stores and calls reproduce all original bytes without assembly or register directives.

Only the120 text bytes are emitted. No weak backups, data, BSS, exception, startup or padding allocation is present. The complete original extabindex `80015F60..8001F2C0`, constructors `80299920..80299980` and destructors `80299980..802999A0` are audited, including descriptors, padding and trailing zeros; none refers to the retained ranges. Existing native function and table ownership is unchanged. No identity or consumer migration is required.

The complete manifest list is `scratch/engine_menu_state_wrappers_20261011dh/final_integration.json`. `verify.py` recompiles both production sources, verifies every allocated section and symbol, compares all retained bytes with actual relocation targets, repeats the full original-table audit and verifies frozen source/header/evidence hashes. Root registration begins NonMatching; original DOL hash and regression acceptance remain required before crediting these units.
