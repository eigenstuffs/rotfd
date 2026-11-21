# Early actor completion controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ten ordinary C++ functions match1,492text bytes plus200original EH/index bytes usingGC1.3.2 and `-O4,s -Cpp_exceptions on`. Central full-DOL acceptance remains pending.

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_80087AB4 |144|8000DF58..8000DF60|8001A16C..8001A178|7|
| fn_80087B44 |152|8000DF60..8000DF68|8001A178..8001A184|9|
| fn_8008809C |176|8000E020..8000E028|8001A208..8001A214|7|
| fn_8008814C |172|8000E028..8000E030|8001A214..8001A220|6|
| fn_80088414 |192|8000E048..8000E050|8001A244..8001A250|7|
| fn_800884D4 |112|8000E050..8000E058|8001A250..8001A25C|5|
| fn_8008860C |156|8000E068..8000E070|8001A274..8001A280|6|
| fn_80088B08 |120|8000E160..8000E168|8001A2B0..8001A2BC|4|
| fn_80088EE0 |156|8000E1A8..8000E1B0|8001A2EC..8001A2F8|7|
| fn_800890E0 |112|8000E1D0..8000E1D8|8001A310..8001A31C|8|

87AB4 selects an event from related-handle validity.87B44 validates a selected0x4C record handle and conditionally updates the input state.8809C copies the resolved related actor's3ECword and sends event77.8814C maps state0/1/2 to phase3/2/1, updates the next record unless it is19, and forwards double delta.88414 and8860C select record transitions from the original flags/activity/velocity conditions, then forward phase9/12 and float/double delta.884D4,88B08 and88EE0 reset their activity gates, flags, feedback and speed before monitor notification.890E0 either dispatches the scene event or forwards the actor update.

Sources are the ten `src/Game/early_actor_completion_control_*.cpp` files; their sole dedicated header is `include/Game/early_actor_completion_control_views.h`. All original callees, globals and constants remain external. Integer word copying at3EC preserves native behavior; ordinary signed-char flag queries and native float/double signatures retain the original tests and save conventions. No weak code, data/BSS/padding, aliases, native identity migrations, assembly, volatile barriers or forced registers are introduced.

Frozen manifest list: `scratch/game_engine_batch113/manifest-list.json`. Production verification accounts for every allocated byte, real relocation and compiler-local EH symbol. Full original extabindex80015F60..8001F2C0,ctors80299920..80299980 anddtors80299980..802999A0 ownership scans retain each original EH owner and find no startup/shutdown references. Adjacent89150 remains assembly: private184-byte probes preserve three scratch-register differences, documented in `scratch/game_early_actor_completion_controls/FINDINGS.md`.
