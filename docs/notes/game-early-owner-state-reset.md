# Early owner state reset

Batch 94 frozen isolated exact handoff, pending central integration. `src/Game/early_owner_state_reset_800699a8.cpp` reconstructs fn_800699A8, text800699A8..80069AEC (324 bytes), extab8000BE40..8000BE48 (8), index80018D14..80018D20 (12). Its only shared header consumer is `include/Game/early_owner_state_reset_views.h`.

The source repeatedly calls the original virtual resource getter at14, resolves its owner handle58 for fn_80069CA8 with value0, sets flags38 bit18 and clears bit17, invokes the two existing resource reset routines, and calls the resource's virtual slot30. It returns signed-byte1. The first ordinary source matched all324 code bytes. The header describes only observed storage and virtual interfaces, with no native identity migration.

GC/1.3.2 with `-O4,s -Cpp_exceptions on` emits exactly .text324, extab8 and extabindex12. The strict verifier resolves all7 retained ELF relocations and compares every allocated byte against the original DOL. One nonallocated compiler category reference is accounted for. Actual local EH names/extents are frozen. No weak code, compiler-owned literals, BSS, padding, aliases, or original constructor/destructor references are introduced.

The complete original extabindex 80015F60..8001F2C0, .ctors 80299920..80299980 and .dtors 80299980..802999A0 tables were audited. Run `scratch/game_early_owner_state_reset/early_owner_state_reset_800699a8/verify.py`. Original DOL SHA-1 remains5da8295a79bf297ab62c620e6ac66210be1c6ef5. Source/header/evidence are frozen; matching credit requires central original-hash acceptance.
