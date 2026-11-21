# Random record grid reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_random_record_grid_800a85ac.cpp` reconstructs the 640-byte entry at800A85AC. It clears the owner state, resets a retained Handle, fills20 rows of20 four-float records using the original random generator and row parameters, then acquires a named resource and performs its two setup calls. Direct array indexing preserves the original shared record address calculation; the explicit local record reference probe instead added an address instruction.

The isolated GC1.3.2 production object exactly matches640 text bytes,40 bytes of exception data at800109C8 and12 bytes of exception index at8001BB70. All34 retained actual relocations match. Floating contraction is enabled for the original fused multiply/add and subtract instructions. All eight float constants and the resource name remain external; no literal pool, BSS or padding is claimed.

The existing standard weak-EH gate verifies the retained exception references against accepted strong destructors `__dt__15Handle_80020834Fv` and `__dt__15Handle_800723F4Fv`. Both116-byte strong production owners were independently recompiled and strictly checked, including their allocated metadata and real relocations. The compiler emits two116-byte weak backups and a unique112-byte `GridZero154` backup, each with40EH/12index. All344 backup text bytes,156 metadata bytes and21 backup actual relocations are separately inventoried and uncredited. The final native link must retain the two original strong owners, discard both source backups, and remove the unique helper and all three backup metadata groups.

Full original exception-index and constructor/destructor table scans pass. The initialized-data word scan finds only the owned exception index pointer. The accepted caller at800A8520 and its header are unchanged. The new header has one production consumer. No shared metadata, existing source, compiler core, configure step or global link was changed. Acceptance remains pending root's original-placement link, original DOL hash and regression checks.

Frozen handoff: `scratch/game_engine_batch154/HANDOFF.md`. Repeat the strict proof with `python3 scratch/game_early_random_record_grid/verify.py`.
