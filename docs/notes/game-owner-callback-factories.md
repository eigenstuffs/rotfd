# Owner callback factories

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two independent units reconstruct four-callback registration groups. The frozen manifest list is `scratch/game_owner_callback_factories/manifest-list.json`. Both consumers of the new frozen `include/Game/owner_callback_factory_views.h` pass strict verification. GC1.3.2 standard optimization requires extra `['-Cpp_exceptions on']`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_callback_group_800a4150.cpp` | `800A4150..800A42AC` (348) | `80010478..80010480` | `8001B87C..8001B888` |
| `src/Game/owner_callback_group_800a4b0c.cpp` | `800A4B0C..800A4C68` (348) | `80010600..80010608` | `8001B96C..8001B978` |

Each function allocates four 12-byte callback objects with the existing allocator, original category/source strings, identifiers0x48 through0x4B and alignment four. A nonnull allocation is passed to its existing initializer with the owner; its result is stored in the callback array at0x3F8. The array is bound to the controller at0x318, then the controller's virtual configuration method receives four. Existing callback initializer identities and source units remain unchanged.

Strict verification proves all736 allocated bytes: 696 text and40 exception/index bytes. Actual local ELF names, all66 text relocations, four EH-index references and two nonallocated metadata references are audited. Full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. Allocator globals and diagnostic strings remain external. No data/BSS, weak helper, padding or gaps are claimed. Final full executable acceptance remains centrally owned.

The independently investigated height-follow routine800A1830 remains private/uncredited at696 bytes with two independent-load scheduling differences. Its bounded source and actual-relocation diagnostics are preserved under `scratch/game_owner_height_follow/FINDINGS.md`.
