# Early actor state transitions

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eight ordinary C++ functions match1,328text bytes plus160original EH/index bytes usingGC1.3.2 and `-O4,s -Cpp_exceptions on`. Central full-DOL acceptance remains pending.

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_800861A0 |180|8000DDF8..8000DE00|8001A04C..8001A058|9|
| fn_800865A4 |176|8000DE48..8000DE50|8001A07C..8001A088|10|
| fn_80086BB0 |204|8000DEB0..8000DEB8|8001A0B8..8001A0C4|11|
| fn_800876DC |220|8000DF20..8000DF28|8001A118..8001A124|10|
| fn_800877B8 |124|8000DF28..8000DF30|8001A124..8001A130|7|
| fn_800878A0 |188|8000DF38..8000DF40|8001A13C..8001A148|7|
| fn_8008795C |120|8000DF40..8000DF48|8001A148..8001A154|6|
| fn_800879D4 |116|8000DF48..8000DF50|8001A154..8001A160|6|

861A0 resets feedback, releases the optional action and disables the selected controller gate.865A4 and86BB0 forward actor updates, query an unsigned-byte state output and choose the next actor record using the signed-char controller query and system flag.876DC accumulates float delta, selects a record from the actor flag or timer threshold and forwards phase5.877B8 resets the timer/speed/activity gate.878A0 selects the controller event from the actor state and resets activity408.8795C completes activity408 and forwards double delta.879D4 resets feedback and notifies the monitor.

Dedicated declarations are in `include/Game/early_actor_state_transition_views.h`, consumed by the eight `src/Game/early_actor_state_transition_*.cpp` sources. Native float versus double signatures preserve the original paired versus stfd-only floating saves. Original globals/constants and callees remain external. No weak functions, owned data/BSS/padding, aliases, native identity migrations, assembly, volatile barriers or forced registers are introduced.

Frozen manifest list: `scratch/game_engine_batch112/manifest-list.json`. Strict per-function production verification accounts for every allocated byte, actual relocation and compiler-local EH name. Full original extabindex80015F60..8001F2C0,ctors80299920..80299980 anddtors80299980..802999A0 scans retain each original exception owner and find no startup/shutdown references.

Excluded85A04 and8761C match their168/192text bytes only when each owns a literal zero at original80378AD0. That shared literal has no coordinated new owner; these complete ownership claims are therefore excluded. Private literal and external-symbol probes remain in `scratch/game_early_actor_state_transitions/FINDINGS.md`, with no matching credit.
