# Early actor event controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six isolated ordinary C++ functions match1,376 text bytes plus120 original EH/index bytes withGC1.3.2 and `-O4,s -Cpp_exceptions on`.

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_8008093C |268|8000D8C8..8000D8D0|80019B00..80019B0C|6|
| fn_8008154C |228|8000D998..8000D9A0|80019BA8..80019BB4|7|
| fn_800820E8 |232|8000DA4C..8000DA54|80019C80..80019C8C|6|
| fn_80082F20 |212|8000DACC..8000DAD4|80019D40..80019D4C|8|
| fn_80083574 |192|8000DB24..8000DB2C|80019DC4..80019DD0|8|
| fn_800839B8 |244|8000DB58..8000DB60|80019DDC..80019DE8|6|

8093C clears a resolved node flag, then forwards the actor value to an existing second component when valid and nonzero.8154C sets an actor flag, chooses an event according to a64-bit flag query and record test, enables two bytes, and notifies the global monitor.820E8 and839B8 clear the observed activity bytes, copy the first component value to the second, and notify the monitor;839B8 also clears the owner's local byte.82F20 conditionally sends an event and updates the record, then invokes both original phase routines with delta.83574 sends the paired event, resets the second component value, and notifies the monitor.

The signed-char flag accessor uses explicit conditional returns, retaining the original64-bit test and materialized signed-char result. The existing matching handle-access source establishes the lookup's pointer return. Paired component queries use ordinary typed manager views for the full resource and first-component view; this preserves both original entry-array reads while retaining the shared manager pointer. All original generation checks, short-circuit branches, scalar stores and event call identities remain intact.

Sources are `src/Game/early_actor_event_control_8008093c.cpp`, `early_actor_event_control_8008154c.cpp`, `early_actor_event_control_800820e8.cpp`, `early_actor_event_control_80082f20.cpp`, `early_actor_event_control_80083574.cpp` and `early_actor_event_control_800839b8.cpp`. The dedicated header is `include/Game/early_actor_event_control_views.h`, consumed only by these six sources. External floats, globals and callees remain under their original ownership. No weak functions, data/BSS allocations, padding, aliases or identity migrations are introduced.

Frozen manifests: `scratch/game_engine_batch106/manifest-list.json`. Each production verifier checks every allocated byte, actual relocation and compiler-local EH symbol, then scans full original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0. Each source retains its original EH/index owner; there are no startup/shutdown slots. Central full-DOL acceptance is pending; neighboring routines and shared original data remain outside this partial reconstruction.
