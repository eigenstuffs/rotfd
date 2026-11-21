# Early actor and indexed-handle controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six ordinary C++ partial text units exactly match isolated production compilation
with GC1.3.2, `-O4,s -Cpp_exceptions on`. Central native acceptance is pending.
They retain676 text bytes plus120 exception table/index bytes and31 actual
retained relocations. No weak helpers or data allocations are emitted.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
|fn_8007517C|120|8000CC38..8000CC40|800194C4..800194D0|5|
|fn_800832E4|120|8000DAF4..8000DAFC|80019D7C..80019D88|5|
|fn_800E1DA4|120|80014754..8001475C|8001E6FC..8001E708|7|
|fn_80074E30|100|8000CBE8..8000CBF0|8001947C..80019488|3|
|fn_8007484C|104|8000CA54..8000CA5C|80019428..80019434|5|
|fn_800B6374|112|80011A0C..80011A14|8001C0F8..8001C104|6|

7517C resolves owner8/Handle24 and forwards events83/8D. 832E4 sets the wide
actor flag1000000000, initializes scalar350, clears bytes420/40D and notifies
the existing monitor. E1DA4 preserves the existing C entry and observed base
initializer, borrowed tables, enabled state and actor pointer copy; no new
native constructor identity is proposed. 74E30 runs the owner reset, virtual
slot138 and masks the wide actor flags withFFFFFFFF7E0001FF. 7484C initializes
three numeric components and a scaled query; caching the actor for the initial
store/query removes the extra reload. B6374 replaces one handle in an indexed
row/column array, decrementing the old reference and incrementing the input
reference through the original manager callback.

The new `early_actor_index_control_views.h` contains partial layouts and
external declaration-only virtual interfaces. All six consumers are frozen in
batch125's header inventory. All tables, strings, constants and globals retain
their external original identities. There are no aliases, BSS, owned padding,
caller migrations or shared metadata changes.

`scratch/game_engine_batch125/manifest-list.json` lists six independent
contiguous section mappings. Each fresh verifier compiles the production
source and checks all allocated bytes, actual relocations, symbol extents and
real local EH names against the original DOL. The full3141-entry extabindex,
its descriptor,19 ctor and3 dtor entries plus terminating slots establish that
all original table ownership for these functions is retained. Frozen source,
headers and evidence hashes are in `frozen-sha256.json`. Full native link/hash,
regression tests and progress acceptance remain with the central integrator.
