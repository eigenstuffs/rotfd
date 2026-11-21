# Early actor position and indexed state controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary C++ partial text units exactly match GC1.3.2 production
compilation with `-O4,s -Cpp_exceptions on`. They retain 1,364 text bytes and
80 exception table/index bytes. Central native acceptance is pending.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
| fn_800E517C | 216 | 80014A34..80014A3C | 8001E918..8001E924 | 6 |
| fn_8005C128 | 316 | 8000ACF0..8000ACF8 | 8001815C..80018168 | 6 |
| fn_80061064 | 416 | 8000B1DC..8000B1E4 | 800184B0..800184BC | 12 |
| fn_80061610 | 416 | 8000B244..8000B24C | 80018504..80018510 | 12 |

E517C resolves and resets handle-array entries 2 through 4 and entry 6. C128
runs base setup, invokes virtual slot AC, copies the related transform Y
component into actor field 3D4 and forwards the final call. The duplicate
61064/61610 routines reset the actor record, copy the related transform
position into fields 390..398 and replace Y with the original constant.

The position-copy pair had previously been released as a bounded near-match
with a missing manager entries reload. A fresh typed manager view and inline
entry generation getter reproduce that native alias/reload behavior. The
source position is held by const reference, then explicit component
construction produces the original float load order and inline target copy.
The historical probes in `scratch/game_early_owner_position` are unchanged.

The new `early_actor_position_state_control_views.h` has four inventoried
production consumers. All context globals, strings and constants retain their
borrowed original identities. No weak helpers, new data, BSS, padding, aliases
or native identity migrations are emitted. Each function has an independent
contiguous original section mapping and fresh strict production verifier.
Every allocated byte, actual relocation target, compiler local EH name and
extent, original DOL hash, all 3,141 exception entries plus descriptor, and the
complete ctor/dtor tables are checked. Frozen source/header/evidence hashes
are in `scratch/game_engine_batch130`.

E54DC remains private and uncredited at 308 bytes/four initial predicate words.
Its subsequent body and real mapped relocations match; bounded signed-char,
Boolean, cast, ternary and inline-predicate variants are preserved and released.
Full native link/hash, regression and progress acceptance remain with the
central integrator.
