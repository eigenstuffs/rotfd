# Owner target motion steps

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four independent units reconstruct immediate target motion, distance-gated motion, optional target motion and ground-state control. The frozen manifest list is `scratch/game_owner_target_motion_steps/manifest-list.json`. All use GC1.3.2 standard optimization with extra `['-Cpp_exceptions on']`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_target_instant_800a0d3c.cpp` | `800A0D3C..800A0E1C` (224) | `8000FD90..8000FD98` | `8001B438..8001B444` |
| `src/Game/owner_target_distant_800a0f54.cpp` | `800A0F54..800A1068` (276) | `8000FDB0..8000FDB8` | `8001B468..8001B474` |
| `src/Game/owner_target_optional_800a1bd8.cpp` | `800A1BD8..800A1CCC` (244) | `8000FE88..8000FE90` | `8001B5AC..8001B5B8` |
| `src/Game/owner_ground_control_800a11a0.cpp` | `800A11A0..800A1228` (136) | `8000FDC8..8000FDD0` | `8001B48C..8001B498` |

Immediate motion diagnoses a missing target, notifies key0x8F, queries direction, applies its reversed horizontal vector with the existing global timing ratio, then finishes. Distance-gated motion diagnoses a missing target and chooses control six beyond the limit; otherwise it applies reversed target direction. Optional motion runs the same direction/limit path only when a target exists, without a diagnostic. Ground control chooses control zero when high flag0x80 is set, control0x10 for negative vertical velocity, and otherwise continues the action.

These sources add four verified consumers of the unchanged frozen `include/Game/owner_motion_control_views.h` (eight total). The ground source declares a separate prefix view for the observed flags and velocity fields. Its ordinary flag helper returns `mask ? 1 : 0`, preserving the native byte result and sign test. Replacing that expression with `mask != 0` removed twelve bytes.

Strict verification proves all960 allocated bytes: 880 text and80 exception/index bytes. Actual local ELF names, all40 text relocations, eight EH-index references and four nonallocated metadata references are audited. Full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. Existing strings, floats and context remain external. No data/BSS, weak helper, padding or gaps are claimed. Full executable acceptance remains centrally owned.
