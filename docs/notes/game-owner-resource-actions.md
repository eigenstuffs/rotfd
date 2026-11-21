# Owner resource actions

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent units reconstruct the cached owner resource and two key callbacks. `scratch/game_owner_resource_actions/manifest-list.json` is the frozen manifest list; all three consumers of the new frozen `include/Game/owner_resource_action_views.h` pass strict verification.

| Source | Text | extab | extabindex | Extra flags |
| --- | --- | --- | --- | --- |
| `src/Game/owner_resource_cache_8009f170.cpp` | `8009F170..8009F278` (264) | `8000FC48..8000FC50` | `8001B27C..8001B288` | `-Cpp_exceptions on` |
| `src/Game/owner_resource_key_notify_8009fabc.cpp` | `8009FABC..8009FB80` (196) | `8000FC90..8000FC98` | `8001B2E8..8001B2F4` | `-O4,s -Cpp_exceptions on` |
| `src/Game/owner_resource_key_query_8009fb80.cpp` | `8009FB80..8009FC1C` (156) | `8000FC98..8000FCA0` | `8001B2F4..8001B300` | `-O4,s -Cpp_exceptions on` |

The cache function initializes sentinel pointer -1 from the current global owner's handle, marks it active, refreshes an active nonnull cache, clears the activity byte when the cache is null, and returns the pointer. The notify callback checks the enabled byte, changed key or state14, and existing key predicate before notifying code0x8D and recording the key; it always returns one. The query callback runs the same key predicate and notifies code0x8D, returning one on that path and zero otherwise. The enabled byte's signed character type reproduces the native signed comparison without an extra sign extension.

GC1.3.2 produces exactly 616 text and 60 exception/index bytes, 676 allocated bytes total. Actual ELF local names, all 14 text relocations, six EH-index references and three nonallocated metadata references are audited. Full original DOL SHA1 and complete original extabindex/constructor/destructor ownership checks pass. No extra data/BSS, weak helper, padding or gaps are claimed. Final full executable acceptance remains centrally owned.

The adjacent velocity blend8009F058 remains a bounded private 280-byte near match with13 arithmetic register/scheduling differences; no credit is claimed. Its evidence is preserved in `scratch/game_owner_resource_actions/FINDINGS.md`.
