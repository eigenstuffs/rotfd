# Scene record dispatch and timed state

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two partial original translation units reconstruct `fn_800C3D44` (164 code
bytes) and `fn_800C4404` (252 code bytes). Each owns its complete 44-byte
exception record and 12-byte index. Fresh production objects match all retained
allocated bytes and actual relocation targets under the existing strict weak-EH
gate. Full original-placement native acceptance passes for the corrected sources.

`800C3D44` checks the signed enable byte at `18`, copies the Handle at `04`
into a scoped typed Handle and forwards it to the indexed 0x4C-byte record.
It releases the temporary before calling the existing completion operation.
`800C4404` initializes values at `20/24`, replaces Handle `2C` with correct
reference release/retain order, stores both state bytes at `28/29`, notifies
the logger through its observed vptr at `B10`, and dispatches the copied
Handle to record 6 with selector zero before the existing completion call.

The observed nested Handle construction uses two zero-initializing layers.
Its BASE and LOCAL exception actions select the existing accepted strong
`Handle_80021BCC` and `Handle_8002F6B0` destructors. Both strong owners are
freshly recompiled and verified in full; no aliases, original entry renames,
object payload edits or new verifier adapter are used. Each object emits
348 backup code bytes and 156 backup exception/index bytes. Those allocations
are uncredited and must all be discarded by the complete native-link gate.

`scratch/game_scene_record_dispatch_more/` preserves original ranges, complete
exception/startup table scans, initialized-pointer and existing source-consumer
inventories, exact strong-owner proofs and strict object reports. External
context, logger, records, floats and callback owners remain unchanged. Earlier
research artifacts and every previously accepted source/header are preserved.

The first native-map attempt rejected the shared private helper name across
the two new inputs: MWLD emitted one UNUSED allocation and coalesced the other
copy, leaving no independent per-input UNUSED row. The corrected sources use
distinct private helper identities in each unit. The original attempt remains
in `scratch/game_scene_record_dispatch_more/`; corrected frozen objects and
registration evidence are in `scratch/game_scene_record_dispatch_unique/`.
All strict verifier and native-map checks remain unchanged.
