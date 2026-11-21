# Callback virtual-control completion

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary C++ functions match in isolated production-object checks:
`fn_80044CCC`, `fn_80045BE8`, `fn_80046C94`, and `fn_8004B8A4` are each
112 bytes. All 448 code bytes, 32 exception-header bytes, 48 exception-index
bytes, and sixteen actual relocations match. Each object emits exactly those
three retained sections and no weak functions, switch tables, data globals,
or other allocations. Full native target acceptance remains the integrator's
check.

Each function calls virtual slot `8C(0,0)` through the object's table at offset
eight. The first three then call `98(0,0)`; `8004B8A4` calls `9C(0,0)`.
All four send event zero through `fn_802073E8(self,0,self,originalFloat)`,
using the existing constant at `80378560`. The private two-word prefix
establishes the observed vtable placement without proposing a complete
shared object layout. Original C entry names and table references remain
unchanged.

The ownership audit scans the full original exception-index table
`80015F60..8001F2C0` and startup/shutdown pointer tables
`80299920..80299980` and `80299980..802999A0`. Each function owns exactly
one corresponding exception record and has no startup/shutdown pointer.
All original initialized-data references and current compiled source consumers
are inventoried. No identifier migration, alias, symbol change, pool
partition, data retention rule, or shared-header edit is requested.

`scratch/game_engine_callback_control_completion_continuation/handoff.json`
freezes the production sources, raw compiler objects, allocated section and
symbol inventories, ownership audit, complete actual relocations, exact
split/config proposals, strict verifier, and source/header hashes.
`verify.py` recompiles all four production files and checks every emitted
allocation and relocation. Previous frozen handoffs and central metadata
are unchanged.
