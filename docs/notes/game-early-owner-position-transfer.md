# Early owner position transfers

Batch 95 frozen isolated exact handoff, pending central integration.

| Function | Text | Exception table | Exception index |
| --- | --- | --- | --- |
| fn_8006A9E0 | 8006A9E0..8006AB3C (348) | 8000C07C..8000C084 (8) | 80018D80..80018D8C (12) |
| fn_8006AB3C | 8006AB3C..8006AC98 (348) | 8000C084..8000C08C (8) | 80018D8C..80018D98 (12) |
| fn_8006AC98 | 8006AC98..8006AE5C (452) | 8000C08C..8000C094 (8) | 80018D98..80018DA4 (12) |

The first pair copies the input resource transform position, replaces Z or X with the generation-resolved owner's current coordinate, applies the position, and updates the owner transform. A normal three-coordinate vector constructor preserves the original reverse argument loads followed by XYZ stores; sequential copy-constructor source differed in six instructions. The restore routine uses ordinary vector assignment to copy the actor's saved position398, applies it to the resolved owner, invokes fn_80069CA8 with value1, updates the transform, and dispatches fn_80067808 when its pending pointer10C is set. Repeated native virtual resource/handle getters remain explicit.

Sources use prefix `src/Game/early_owner_position_transfer_`; their only shared header is `include/Game/early_owner_position_transfer_views.h`. The header describes observed storage, normal vector constructors/assignment, and virtual interfaces, with no native identity migration.

GC/1.3.2 with `-O4,s -Cpp_exceptions on` emits exactly one .text extent plus extab8/index12 per source. The strict verifiers resolve all 6/6/8 retained ELF relocations and compare every allocated byte against the original DOL. One nonallocated compiler category reference each is accounted for. Actual local EH names/extents are frozen. No weak code, compiler-owned literals, BSS, padding, aliases, or original constructor/destructor references are introduced.

The complete original extabindex 80015F60..8001F2C0, .ctors 80299920..80299980 and .dtors 80299980..802999A0 tables were audited. Manifest list: `scratch/game_early_owner_position_transfer/manifest-list.json`. Original DOL SHA-1 remains 5da8295a79bf297ab62c620e6ac66210be1c6ef5. Source/header/evidence are frozen; matching credit requires central original-hash acceptance. Text after8006AE5C and all original data outside the stated ranges remain unowned by this handoff.
