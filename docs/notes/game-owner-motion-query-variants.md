# Owner motion query variants

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two separate source units recover ordinary motion callbacks that have the same behavior and native byte patterns as the accepted `800965BC` and `800967A0` callbacks, with address-dependent calls relocated to their own locations. They reuse the frozen `include/Game/owner_motion_query_views.h` without changes. Both new consumers are strictly verified; the previous three consumers retain their frozen proofs.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_motion_upper_800980d8.cpp` | `800980D8..80098184` (172) | `8000F6A0..8000F6A8` | `8001AE68..8001AE74` |
| `src/Game/owner_motion_lower_800982bc.cpp` | `800982BC..8009834C` (144) | `8000F6B8..8000F6C0` | `8001AE8C..8001AE98` |

The upper callback obtains two scalars, sets control eight if either exceeds its corresponding agent limit, and otherwise forwards a queried vector plus delta to virtual slot `0x1A0`. The lower callback forwards a second queried vector and delta first, then sets control five if the scalar is below its limit. The inline float limit accessors reproduce the native comparison registers.

Manifest list: `scratch/game_owner_motion_query_variants/manifest-list.json`. GC1.3.2 standard optimization with extra `['-Cpp_exceptions on']` for both. Strict verification proves all356allocated bytes: 316 text and40exception/index bytes. Actual ELF local object names, all seven text relocations, four owned EH-index references and two metadata references are audited. Original DOL SHA1 and full exception/constructor/destructor ownership table checks pass. No extra data/BSS, weak helper, padding or original gap is claimed. Full executable acceptance is centrally owned.
