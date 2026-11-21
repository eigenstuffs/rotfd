# Early actor motion events

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six ordinary C++ functions match1,432 text bytes plus120 original EH/index bytes usingGC1.3.2 and `-O4,s -Cpp_exceptions on`.

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_80081CCC |188|8000DA18..8000DA20|80019C68..80019C74|8|
| fn_80082910 |364|8000DAA4..8000DAAC|80019D04..80019D10|12|
| fn_80082A7C |192|8000DAAC..8000DAB4|80019D10..80019D1C|7|
| fn_800830D0 |356|8000DAE4..8000DAEC|80019D64..80019D70|11|
| fn_80083234 |176|8000DAEC..8000DAF4|80019D70..80019D7C|7|
| fn_80083424 |156|8000DB0C..8000DB14|80019DA0..80019DAC|6|

81CCC resets the resolved second component and sends the original event/monitor notification.82910 clears vertical position/velocity, resets acceleration, adds the actor height, clears two64-bit flags and chooses an event from the original scene mode.830D0 resets acceleration and vertical motion, adds a snapshot of the actor offset, clears the same flags, and chooses its paired event from handle validity.82A7C,83234 and83424 conditionally update the record according to their original flag/activity/height tests, then invoke phase9,10 or12 and forward delta. Their float/double signatures retain the original paired versus stfd-only floating saves.

The vector constructor accepting an existing vector plus replacement Y retains native X/Z reads while assigning only the changed Y field. The offset routine takes an ordinary vector snapshot before compound addition, preserving all original source-component reads before destination writes. Inline64-bit flag clear methods retain both original word stores. No assembly, volatile barriers or forced registers are used.

Sources are `src/Game/early_actor_motion_event_80081ccc.cpp`, `early_actor_motion_event_80082910.cpp`, `early_actor_motion_event_80082a7c.cpp`, `early_actor_motion_event_800830d0.cpp`, `early_actor_motion_event_80083234.cpp` and `early_actor_motion_event_80083424.cpp`. Dedicated declarations are in `include/Game/early_actor_motion_event_views.h`, consumed by those six sources. Original zero-vector data, floats, scene/monitor globals and all callees remain external and unchanged. No weak functions, owned data/BSS/padding, aliases or native identity migrations are introduced.

Frozen manifests: `scratch/game_engine_batch108/manifest-list.json`. Per-source production verification accounts for every allocated byte, real relocation and compiler-local EH symbol. Complete extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 scans preserve each original EH owner and find no constructor/destructor slots. Central full-DOL acceptance remains pending. Nearby normalization routines and shared original data remain outside this partial source reconstruction.
