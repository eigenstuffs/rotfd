# Early callback factory groups

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent source units reconstruct callback registration groups. The frozen manifest list is `scratch/game_early_callback_factory_groups/manifest-list.json`. All three consumers of the new frozen `include/Game/early_callback_factory_group_views.h` pass strict verification. GC1.3.2 standard optimization requires extra `['-Cpp_exceptions on']`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/early_callback_group_80074e98.cpp` | `80074E98..80074FB0` (280) | `8000CBF0..8000CBF8` | `80019488..80019494` |
| `src/Game/early_callback_group_80075748.cpp` | `80075748..8007581C` (212) | `8000CDAC..8000CDB4` | `80019518..80019524` |
| `src/Game/early_callback_group_8007f704.cpp` | `8007F704..8007F860` (348) | `8000D7C0..8000D7C8` | `80019A70..80019A7C` |

Each function allocates callbacks with the existing allocator, original category/source strings, identifier sequence, and alignment four. A nonnull allocation is passed to its existing initializer with the owner; the result is stored in the owner's callback array. The array is bound to the embedded controller, whose virtual configuration method receives the callback count. The initializers retain their existing external C identities.

The three-entry group uses sizes 20, 28, and 36 and identifiers 0x4C through 0x4E, with its controller at 0x168 and callback array pointer at 0x1B0. The two-entry group uses 12-byte allocations and identifiers 0x3C and 0x3D, controller at 0x168, and callback array pointer at 0x198. The four-entry group uses 12-byte allocations and identifiers 0x4A through 0x4D, controller at 0x318, and callback array pointer at 0x3E8. Callback declarations expose only the common prefix needed for these pointer transfers; concrete initializer bodies remain external.

Strict verification proves all 900 allocated bytes: 840 text and 60 exception/index bytes. Actual local ELF names, all 75 text relocations, six EH-index references, and three nonallocated metadata references are audited. The full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. Allocator globals and diagnostic strings remain external. No additional data/BSS, weak helper, padding, or gaps are claimed. Final executable acceptance remains centrally owned.
