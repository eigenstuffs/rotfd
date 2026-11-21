# Early actor input controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six ordinary C++ functions match1,204 text bytes plus120 original EH/index bytes usingGC1.3.2 and `-O4,s -Cpp_exceptions on`. Central full-DOL acceptance remains pending.

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_8008478C |164|8000DC48..8000DC50|80019F14..80019F20|6|
| fn_800850D0 |212|8000DD50..8000DD58|80019F80..80019F8C|8|
| fn_800851A4 |244|8000DD58..8000DD60|80019F8C..80019F98|10|
| fn_800853EC |260|8000DD70..8000DD78|80019FB0..80019FBC|10|
| fn_800857A8 |180|8000DD88..8000DD90|80019FD4..80019FE0|6|
| fn_8008585C |144|8000DD90..8000DD98|80019FE0..80019FEC|7|

8478C chooses the input event from the actor flag and notifies the monitor.850D0 binds the resolved resource to the controller, resets activity and initializes feedback parameters.851A4 runs the original input threshold routine, resolves a nested handle and sends the activity event.853EC stops activity, resets feedback and unbinds the resource.857A8 either sends the flag event or scales horizontal input into acceleration and forwards double delta.8585C restores actor speed and changes the original controller event gates.

Distinct ordinary manager-entry views retain the two original entry-array loads in851A4. Ordinary vector compound scaling retains the exact floating-point allocation in857A8. No assembly, forced registers, volatile barriers, aliases or native identity migrations are used. Dedicated declarations are in `include/Game/early_actor_input_control_views.h`, consumed by the six `src/Game/early_actor_input_control_*.cpp` sources. All globals, original constants/vector allocations and callees remain external. No weak functions, owned data/BSS or padding are introduced.

Frozen manifests: `scratch/game_engine_batch109/manifest-list.json`. Per-source verification accounts for all allocated bytes, actual relocations and actual local compiler EH names. Complete extabindex80015F60..8001F2C0,ctors80299920..80299980 anddtors80299980..802999A0 scans retain the original EH owner and find no constructor/destructor slots. Excluded fn80085298 remains assembly: the best private ordinary probe is284bytes with four FPR operands different. Its preserved evidence is in `scratch/game_early_actor_input_controls/FINDINGS.md`; it earns no matching credit.
