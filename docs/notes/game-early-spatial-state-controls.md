# Early spatial state controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary C++ partial text units exactly match GC1.3.2 production
compilation with `-O4,s -Cpp_exceptions on`. They retain 1,564 text bytes and
80 exception table/index bytes. Central native acceptance is pending.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
| fn_80024C00 | 428 | 80005F58..80005F60 | 80016374..80016380 | 8 |
| fn_8002AF3C | 364 | 800069DC..800069E4 | 800169BC..800169C8 | 5 |
| fn_800E1EB4 | 516 | 80014784..8001478C | 8001E714..8001E720 | 8 |
| fn_800E38F0 | 256 | 800149DC..800149E4 | 8001E894..8001E8A0 | 5 |

24C00 resets each active selection record, copies the resolved actor origin
and clears actor velocity through the original virtual getter. Its scalar
vector copy constructor preserves the three zero-vector components across
that getter. The record pointer array covers the full unsigned-byte index
range in the observed owner layout. 2AF3C copies a related transform position
into the resolved actor and clears the resource property bit. A const-reference
position followed by explicit component construction reproduces the native
pointer allocation and component load order.

E1EB4 captures a related handle by reference across validation, forwards its
transform position through a virtual call, and writes the original velocity
constants. The implicit vector copy reproduces its two original stack copies.
E38F0 runs the base setup and virtual command, then clears and sets the observed
actor flags. Two uniquely named partial view headers keep the observed inline
copy behaviors distinct across production translation units; each has two
consumers. The generation/index checks use ordinary signed C++ bitfields.

All context globals, floating constants and the zero vector retain their
borrowed original identities. There are no emitted weak helpers, data, BSS,
padding, aliases or native identity migrations. Each per-function verifier
checks every allocated byte, actual relocation target, compiler local EH name
and extent, original DOL hash, all 3,141 exception records plus descriptor, and
the complete original ctor/dtor tables. Frozen evidence and all header
consumers are inventoried in `scratch/game_engine_batch 128`.

The B409C lookup remains private and uncredited at 260 bytes with six initial
instruction differences after bounded ordinary variants. Its original table
remains borrowed. Full link/hash, regression and progress acceptance remain
with the central integrator.
