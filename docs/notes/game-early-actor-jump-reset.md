# Early actor jump reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_800882A8` matches 364 text bytes, 8 bytes of extab, and 12 bytes of
extabindex using GC1.3.2, `-O4,s`, and C++ exceptions. The source reuses the
unchanged accepted `early_actor_motion_event_views.h` declarations. It zeros
the vertical position and velocity, resets acceleration and adds the actor's
height, clears two wide state flags, emits event 0x78/0x77, chooses the scene
mode event, and notifies the first monitor. The same ordinary vector-member
shapes reproduce the native intentionally retained X/Z loads.

Strict production validation verifies every allocated byte, all 12 actual
retained relocations, actual compiler local EH symbols, complete original
extabindex/constructor/destructor table ownership, and zero extra weak helpers,
data, BSS or padding. No identifiers or original consumers need migration.
The isolated handoff is `scratch/game_engine_batch120/HANDOFF.md`; final native
link/hash/regression acceptance remains with the central integrator.

Private direction/setup probes at 80084A14 and 80084C50 remain uncredited;
their bounded register/order findings are preserved in the batch120 snapshot.
