# Early actor phase controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five isolated ordinary C++ functions match552 text bytes plus100 original EH/index bytes usingGC1.3.2 and `-O4,s -Cpp_exceptions on`.

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_800817E4 |112|8000D9B8..8000D9C0|80019BD8..80019BE4|5|
| fn_80081854 |108|8000D9C0..8000D9C8|80019BE4..80019BF0|6|
| fn_80081970 |112|8000D9D8..8000D9E0|80019C08..80019C14|5|
| fn_800819E0 |108|8000D9E0..8000D9E8|80019C14..80019C20|6|
| fn_80081B04 |112|8000D9F8..8000DA00|80019C38..80019C44|5|

The three entry routines send events12,15 or16, enable actor bytes405/406, and notify the original monitor when its callback is present. The two updates invoke phase1 or2, query the current phase, update the actor record on a difference, then forward delta to the original update routine. Their double argument preserves the native stfd-only floating save without a paired-single spill. Record layout and monitor fields are the same observed offsets as the adjacent accepted actor-event routines, expressed in a dedicated partial view.

Production sources are `src/Game/early_actor_phase_control_800817e4.cpp`, `early_actor_phase_control_80081854.cpp`, `early_actor_phase_control_80081970.cpp`, `early_actor_phase_control_800819e0.cpp` and `early_actor_phase_control_80081b04.cpp`. Dedicated declarations are in `include/Game/early_actor_phase_control_views.h`, consumed by these five sources. Original globals/callees remain external. No weak functions, data/BSS allocations, padding, aliases or native identity migrations are introduced.

Frozen manifests: `scratch/game_engine_batch107/manifest-list.json`. Production verifiers match every allocated section, real relocation and actual local compiler EH symbol against the original DOL. Full extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 scans preserve all original EH owners and find no constructor/destructor slots. Central full-DOL acceptance remains pending. Originalfn80081B74 is excluded: bounded ordinary variants eliminate its retained fixed sentinel comparison and emit144 rather than160 bytes. Those private findings and neighboring original data remain outside this partial reconstruction.
