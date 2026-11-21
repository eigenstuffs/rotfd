# Owner motion controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four independent units reconstruct target-following and wandering callbacks, continued motion and ordered key selection. The frozen manifest list is `scratch/game_owner_motion_controls/manifest-list.json`. All four consumers of the new frozen `include/Game/owner_motion_control_views.h` pass strict verification. GC1.3.2 standard optimization requires extra `['-Cpp_exceptions on']`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_target_follow_800a06c0.cpp` | `800A06C0..800A0810` (336) | `8000FD28..8000FD30` | `8001B39C..8001B3A8` |
| `src/Game/owner_target_wander_800a08d0.cpp` | `800A08D0..800A09C4` (244) | `8000FD48..8000FD50` | `8001B3CC..8001B3D8` |
| `src/Game/owner_target_continue_800a0e1c.cpp` | `800A0E1C..800A0EDC` (192) | `8000FD98..8000FDA0` | `8001B444..8001B450` |
| `src/Game/owner_key_priority_800a1298.cpp` | `800A1298..800A1360` (200) | `8000FDE0..8000FDE8` | `8001B4B0..8001B4BC` |

Following marks the forward byte, diagnoses a missing cached target, queries direction, compares distance and bearing thresholds, then selects control six or zero or applies the reversed horizontal direction. Wandering periodically regenerates its direction, copies the existing direction, optionally replaces it with the queried direction when distance exceeds the limit, and applies it. Continued motion switches to control six beyond the distance limit and otherwise reapplies a copied direction. Key selection chooses the first available key in order0x1B,0x10,0xC,1, sends the existing callback, records the selector and finishes the action.

The ordinary inline application helper accepts a const vector reference, copies it to the agent direction, calls the existing motion projection and finishes the action. An explicit vector-copy temporary in the continued-motion caller preserves its native stack object; the wandering caller passes its existing local by reference. Passing all vectors by value emitted an unnecessary second copy in wandering. All diagnostic strings, floats and context remain external.

Strict verification proves all1,052 allocated bytes: 972 text and80 exception/index bytes. Each object emits only its function and extab8/index12 with actual local ELF names. All34 text relocations, eight EH-index references and four nonallocated metadata references are audited. Full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. No data/BSS, weak helper, padding or gaps are claimed. Final full executable acceptance remains centrally owned.
