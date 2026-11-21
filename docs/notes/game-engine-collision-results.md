# Engine nearest collision-result forwarding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: two ordinary C++ functions, 384 text bytes, zero data
and two real call relocations. Sources are
`src/Game/engine_collision_results_801E04DC.cpp` and
`src/Game/engine_collision_results_801E09E8.cpp`. No extra code, weak functions,
allocated data or padding are emitted. Exact integration, production SHA-256,
quoted-header hashes (none), emitted allocations and real relocations are in
`scratch/game_engine_collision_results_continuation/final_integration.json`,
with adjacent split/configuration proposals and `ownership_audit.json`.

Each routine calls the original geometric query (`fn_801B99DC` or
`fn_801B9D1C`) into a local result. A successful query replaces the destination
when its signed-byte valid flag at +3C is clear or the new distance is smaller.
The replacement sets that flag, copies point floats +0/+4/+8, distance +C and
normal floats +10/+14/+18, then copies the 64-bit token to +28/+2C. The first
routine copies distance after the two vectors and returns zero without a
replacement. The second copies distance first and returns one on every path.
These original order and return differences are preserved.

The token is a genuine 64-bit argument in r7/r8. Its assignment emits the
original low-word then high-word stores at +2C/+28 and reproduces the original
saved register allocation. Two separate 32-bit argument declarations swap that
allocation and do not match. Point and normal assignment use ordinary inline
component copies to retain the observed floating loads and stores.

## Layout limits and verification

The query callees directly establish only the local result's first 28 bytes.
The original wrapper stack frames reserve more storage. The private local view
therefore has a 20-byte opaque tail, making a 48-byte query record and reproducing
the original 0x50-byte frames. Its exact trailing field types and exact extent
within compiler alignment are not established. No semantic meaning is assigned
to those bytes, and no extra accesses or side effects were added. This local
view is provisional; a later recovered shared result declaration may refine it.
Destination offsets used by the routines are directly established by assembly.

Root reviewed both complete query callees before integration. They make no
calls and write the result through `r5` only at offsets `0x00`, `0x04`,
`0x08`, `0x0C`, `0x10`, `0x14` and `0x18`. The opaque local tail is accepted
as a provisional storage view reproducing the original frame, without claiming
recovery of the complete original result type. It adds no output access or
semantic field. The known layout limitation remains documented for later
shared-type recovery.

GC/1.3.2 uses ordinary `-O4,p` flags with C++ exceptions off. Production sources
were recompiled after private naming and formatting. The copied strict verifier
applies both real branch targets and checks every original byte, exact symbol
extent and emitted allocated section. There is no relocation masking or credit
outside the retained functions. The full original exception index and constructor
table were audited; neither function has an exception record or startup entry.
Original split ownership is text only. Other original functions and the queried
geometry functions retain their existing ownership.

`verify.py` passes both units. Root must review the provisional local view and
pass the full DOL hash, native match regression and extent checks before source
promotion. No shared metadata or full build was changed by this agent.
