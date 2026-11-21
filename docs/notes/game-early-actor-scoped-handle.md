# Early actor scoped handle update

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ reconstructs fn_80084830 at80084830..8008494C,284text bytes plus original extab8000DC50..8000DC78(40) andextabindex80019F20..80019F2C(12). GC1.3.2 with `-O4,s -Cpp_exceptions on` passes strict production checks for every allocated byte and all17 actual retained relocations. Central full-DOL acceptance remains pending.

The routine updates the actor record when activity40C is enabled. If controller event98 is active, it copies the controller's nested handle into a full-expression temporary and then a named handle, resolves that handle, binds the resulting resource handle70 to the actor, and updates record16. It forwards double delta to the actor update after the scoped cleanup. Automatic native Handle destruction preserves the original stack8/C lifetime order and both original EH actions.

The inline Handle copy constructor calls the existing fixed fn_801F7CB4 C entry, preserving its original symbol identity as established by accepted registry and stream consumers. A pointer-returning accessor for the nested source handle retains the native argument setup; a const-reference accessor retains the separate temporary. No linker aliases, assembly, volatile barriers or forced registers are used. Source is `src/Game/early_actor_scoped_handle_80084830.cpp`; its sole dedicated header is `include/Game/early_actor_scoped_handle_views.h`. All callees and globals remain external, with no weak code, data/BSS/padding or native identity migrations.

Frozen manifest list: `scratch/game_engine_batch110/manifest-list.json`. The verifier preserves actual compiler-local EH names and scans full original extabindex80015F60..8001F2C0,ctors80299920..80299980 anddtors80299980..802999A0. It retains the original single EH owner and finds no startup/shutdown slots. Adjacent fn80084DCC remains assembly with five preserved private scratch-register differences, documented in `scratch/game_early_actor_scoped_handles/FINDINGS.md`.
