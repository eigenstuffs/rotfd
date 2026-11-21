# Timed scene record control

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_800C4570` is reconstructed in `scene_timed_record_800C4570.cpp`: 340 code
bytes, the complete 44-byte exception record and 12-byte index, with 21 real
retained relocations. Fresh production compilation matches all original owned
allocations and relocation targets under the established weak-EH gate.

The routine accumulates elapsed time at `24`. The flag at `28` holds elapsed
time at zero until input query 11 succeeds. Otherwise, when elapsed time exceeds
the threshold at `20`, it finishes logger operation 2, dispatches a scoped copy
of Handle `04` to record 6 and completes the owner operation. Before timeout,
flag `29` permits input query 2 to reset the threshold. Native float constants,
external context and both observed virtual-call slots keep their original owners.

The original BASE and LOCAL cleanup actions retain the accepted strong native
Handle `80021BCC` and `8002F6B0` owners. Both are freshly recompiled and verified
in full. A unique private zero-initialization layer avoids COMDAT ambiguity with
other partial units. The 348 backup text and 156 backup exception/index bytes
receive no credit; native selection and discard must pass in the full target.

`scratch/game_scene_timed_record/` preserves strict allocation reports, complete
original exception/startup table scans, initialized-pointer references, compiled
consumers and strong-owner proofs. This is a partial original translation unit.
Full original-placement native acceptance is pending.
