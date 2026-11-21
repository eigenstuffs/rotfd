# Early related record controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary C++ partial text units exactly match GC1.3.2 production
compilation with `-O4,s -Cpp_exceptions on`. They retain 1,500 text bytes and
100 exception table/index bytes. Central native acceptance is pending.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
| fn_80056A0C | 312 | 80009FB4..80009FBC | 80017FF4..80018000 | 7 |
| fn_80057908 | 408 | 8000A070..8000A078 | 80018030..8001803C | 6 |
| fn_80072E2C | 364 | 8000C898..8000C8A0 | 800192E4..800192F0 | 6 |
| fn_800AF084 | 204 | 800110B8..800110C0 | 8001BE64..8001BE70 | 8 |
| fn_800AF4B8 | 212 | 80011150..80011158 | 8001BEA0..8001BEAC | 6 |

56A0C initializes the five-item pool if needed, returns the first actor whose
record has bit 0, and otherwise retains the first actor whose record has bit 2.
The ordinary loop index is declared before its fallback pointer to reproduce
the native saved-register allocation. 57908 maps six pending state values to
record events, resolves the nested system/group handle, validates the related
actor and sends its record event, then resets the pending state. Its ordinary
switch emits the original comparison tree and no jump table.

72E2C runs base setup, copies the related transform position into actor fields
1AC..1B4 and sets its record. Typed manager-entry views preserve the native
reload through nested handle resolution, and explicit component construction
preserves the float argument order. AF084 accumulates time and clears the
owner record after either event query or the original time bound. AF4B8 calls
native Root readiness, validates the virtually returned handle, then invokes
the related readiness callback.

The new `early_related_record_control_views.h` has five inventoried production
consumers. All context globals, strings and floating constants retain their
borrowed original identities. No weak helpers, data, BSS, padding, aliases or
native identity migrations are emitted. Every allocated byte and actual
relocation target, compiler local EH name/extent, original DOL hash, all 3,141
exception records plus descriptor, and complete ctor/dtor tables are checked
by fresh per-function production verifiers. Frozen hashes and manifests are
in `scratch/game_engine_batch131`.

The older 7256C and 6BA70 near-matches were only inspected and remain unchanged
and uncredited. Full native link/hash, regression and progress acceptance
remain with the central integrator.
