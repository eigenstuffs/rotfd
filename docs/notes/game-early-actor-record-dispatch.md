# Early actor record dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ partial text units exactly match GC1.3.2 production
compilation with `-O4,s -Cpp_exceptions on`. They retain 776 text bytes and
60 exception table/index bytes. Central native acceptance is pending.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
| fn_8003B270 | 332 | 80008020..80008028 | 800171C0..800171CC | 12 |
| fn_8003CE44 | 232 | 80008180..80008188 | 80017358..80017364 | 12 |
| fn_800B3B94 | 212 | 80011710..80011718 | 8001BFC0..8001BFCC | 5 |

B270 logs and forwards base setup, validates the resolved actor's related
handle and scales the related optional scalar using the original double.
CE44 removes its handle through the service virtual call, clears only its
generation byte, resets each handle-array item and sends the scene event and
base command. Both routines match the first complete probes.

B3B94 resolves an actor and queries the indexed record handles into the
original 40-byte local workspace, then forwards the record and workspace. The
current record pointer is assigned during each loop condition and retained
through the body/final call. This reproduces the original reload and address
lifetime with ordinary source. The observed record stride is C4, key offset 80,
handle-array offset 90 and count byte B2.

The new `early_actor_record_dispatch_views.h` has three inventoried consumers.
All globals, strings and floating constants retain their borrowed original
identities. No weak helpers, data, BSS, padding, aliases or native identity
migrations are emitted. Fresh strict production verifiers check every
allocated byte, actual relocation target, compiler local EH name/extent,
original DOL hash, the complete 3,141 exception records plus descriptor and all
ctor/dtor entries. All source/header/evidence hashes are frozen in
`scratch/game_engine_batch132`.

A new 3543C structural retry matches the formerly differing position copy but
retains a final optional-lookup reload difference at 620 versus 640 bytes. Its
bounded variants remain private/uncredited; the older SDK research is unchanged.
Full native link/hash, regression and progress acceptance remain with the
central integrator.
