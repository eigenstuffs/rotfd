# Owner callback factory groups

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent source units reconstruct callback registration groups. The frozen manifest list is `scratch/game_owner_callback_factory_groups/manifest-list.json`. All three consumers of the new frozen `include/Game/owner_callback_factory_group_views.h` pass strict verification. GC1.3.2 standard optimization requires extra `['-Cpp_exceptions on']`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_callback_group_800a3004.cpp` | `800A3004..800A3628` (1,572) | `800102A8..800102B0` | `8001B750..8001B75C` |
| `src/Game/owner_callback_group_800aa838.cpp` | `800AA838..800AAA1C` (484) | `80010C58..80010C60` | `8001BC30..8001BC3C` |
| `src/Game/owner_callback_group_800af58c.cpp` | `800AF58C..800AF6A4` (280) | `80011158..80011160` | `8001BEAC..8001BEB8` |

Each function allocates callbacks with the existing allocator, original category/source strings, identifier sequence, and alignment four. A nonnull allocation is passed to its existing initializer with the owner; the result is stored in the owner's callback array. The array is bound to the embedded controller, whose virtual configuration method receives the callback count. Existing callback initializer identities and source units remain unchanged.

The 22-entry group uses 12-byte allocations and identifiers 0x4A through 0x5F, with its controller at 0x318 and callback array pointer at 0x3F8. The six-entry group uses sizes 28, 44, 36, 28, 24, and 20, identifiers 0x47 through 0x4C, controller at 0x168, and callback array pointer at 0x198. The three-entry group uses sizes 12, 12, and 16, identifiers 0x58 through 0x5A, controller at 0x1F8, and callback array pointer at 0x2CC. Callback declarations expose only the common prefix needed for these pointer transfers; concrete initializer bodies remain external.

Strict verification proves all 2,396 allocated bytes: 2,336 text and 60 exception/index bytes. Actual local ELF names, all 251 text relocations, six EH-index references, and three nonallocated metadata references are audited. The full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. Allocator globals and diagnostic strings remain external. No additional data/BSS, weak helper, padding, or gaps are claimed. Final executable acceptance remains centrally owned.
