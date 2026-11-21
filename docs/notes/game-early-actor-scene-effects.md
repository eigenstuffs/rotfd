# Early actor scene effects

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ routines match 1,520 text bytes plus 40 original exception-table/index bytes with GC/1.3.2 and `-O4,s -Cpp_exceptions on`. The complete original DOL and central acceptance checks pass.

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_80089B74 | 984 | 8000E290..8000E298 | 8001A364..8001A370 | 34 |
| fn_80089904 | 536 | 8000E280..8000E288 | 8001A34C..8001A358 | 21 |

89B74 copies the resolved actor resource's translation, adds actor height, and checks vertical velocity against two thresholds. It finds named scene effects, destroys each returned Handle temporary, activates and positions successful results, and sends the corresponding controller event. The four strings remain in their original external pool beginning at 8029D680. An ordinary local pointer to that pool explains the shared address register.

The scene lookup at 80058778 returns the existing two-layer native Handle_80020834 type. Its empty inline typed destructors invoke Handle_801F7F10 cleanup with flag zero. The final lookup argument is a signed char: the original callee explicitly sign-extends its saved argument at 80058814. That signature also preserves the original caller argument scheduling. All C entry identities remain unchanged.

89904 updates two effect objects after a service-state check. It either copies the actor position directly or builds a yaw quaternion from the actor direction and the existing scalar trigonometric routines. A separate angle local followed by compound scaling preserves the original multiplication operand order. All three float constants remain external; this source owns no literal pool.

Sources are `src/Game/early_actor_scene_effect_80089b74.cpp` and `src/Game/early_actor_scene_effect_80089904.cpp`; the dedicated header is `include/Game/early_actor_scene_effect_views.h`, with exactly these two production consumers. No assembly, forced registers, volatile barriers, aliases, native identity migrations, BSS or padding allocations are introduced.

89B74 also emits one unreferenced weak native Handle_80020834 destructor backup: 116 text bytes, 40 extab bytes and 12 index bytes. These bytes receive no matching credit and must be discarded at the final native link. Its existing original strong owner is `src/Game/typed_handle_80020834.cpp`, recorded in `config/GSQE78/candidates/game_typed_handle_80020834.json`. Fresh independent recompilation and original-byte verification of that strong owner are preserved in `scratch/game_early_actor_scene_effects/known_strong_unreferenced_backup.json`. This is a supplemental native duplicate inventory; no retained-EH weak override annotation is added. The uncredited backup's 116 text bytes independently match the original destructor using actual relocations. 89904 emits no backup code.

Frozen manifest list: `scratch/game_engine_batch114/manifest-list.json`. Strict production verifiers account for all emitted allocated bytes, actual relocations and compiler-local exception symbols. Full original extabindex 80015F60..8001F2C0, ctors 80299920..80299980 and dtors 80299980..802999A0 ownership scans retain the two original EH owners and find no startup/shutdown references. Each production source maps to one contiguous text extent. All adjacent original routines and borrowed data remain outside these partial source units.
