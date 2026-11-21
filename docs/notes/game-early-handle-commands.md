# Early handle commands and actor timer control

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five fresh ordinary C++ partial text units compile exactly under GC1.3.2 with
`-O4,s -Cpp_exceptions on`. Their retained code totals756 bytes and their
exception tables/indexes total100 bytes. Central integration is pending.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
| fn_80027ECC | 136 |800065AC..800065B4|80016614..80016620|4|
| fn_8008250C | 100 |8000DA7C..8000DA84|80019CC8..80019CD4|7|
| fn_800E3424 | 152 |8001496C..80014974|8001E84C..8001E858|7|
| fn_800E18B8 | 184 |800146E0..800146E8|8001E6B4..8001E6C0|4|
| fn_800E1970 | 184 |800146E8..800146F0|8001E6C0..8001E6CC|4|

The setter gets a Handle through virtualslot9C(selector), resolves its signed
24-bit index and signed8-bit generation, and stores its value at resource120.
The conditional dispatch checks event8F, starts the actor record318 and
completes the event. Two commands follow ownerC/Handle58 to another Handle20,
then call virtualslot40 or44 with-1. Distinct typed entry views preserve the
observed second manager-array reload. The timer routine clears borrowed global
80377768, sends event71 and notifies the existing monitor from actor record320.

`include/Game/early_handle_command_views.h` owns only partial observed layouts
and declaration-only virtual interfaces. The timer source reuses the unchanged
accepted motion-event header. Neither header defines virtual tables or helper
functions out of line. All external data remains borrowed under its original
identity; no data, BSS, padding, aliases, or caller migrations are claimed.

The frozen batch124 manifest list and hashes are under
`scratch/game_engine_batch124/`. Each source has a separate original contiguous
text extent,8-byte extab and12-byte extabindex. The fresh strict verifier checks
all allocated sections, every actual relocation (26total), raw compiler local
EH identities and symbol extents, the original DOL hash, complete3141entry
extabindex plus descriptor, all ctor/dtor slots, and unique overlapping function
ownership. No unused weak helpers are emitted. These are partial units rather
than an assertion about original translation-unit boundaries. Full native
link/hash, regression and progress acceptance remain the integrator's work.
