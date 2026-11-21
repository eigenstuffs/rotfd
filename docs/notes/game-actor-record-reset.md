# Actor record reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80072F98` at 80072F98..800732B8 reconstructs 800 bytes of ordinary C++ with GC1.3.2, proc750, O4,s and exceptions enabled. It clears the actor selection, enables its reset flag, masks one related object's 64-bit state, clears bit0x40000 on a first related object and every record in a copied Array25634, invokes the actor event0, and selects -1 on a nested related object.

The private actor layout has a vptr at8, Handle fields58/64/70, signed-short selection90 and byte98. Resolved objects expose related Handle20, flags30, array4C, stateFlags120 and related-array Handle1F0. Record stride is24 with Handle at4. A distinct concrete ArrayResource entry object type preserves the original two manager-entry reloads; returning its unrelated concrete pointer also preserves native argument evaluation and register allocation. The short loop assigns its narrowed index to an ordinary int before indexing. Two record/Handle destructor layers naturally reproduce the original null checks.

Production `src/Game/actor_record_reset_80072F98.cpp` retains only the primary800, extab8000C8A0..C8B8 (24) and extabindex800192F0..192FC (12). All10 retained actual relocations match. The compiler also emits an uncredited weak Array25634 destructor240 plus40EH/12index with10 relocations. Fresh source-bound `scratch/game_actor_record_reset_80072f98/aggregate_owner_gate.py` selects only the already accepted GLOBAL240 destructor from `game-nested-lifetime-destructors.json`. It strictly pins the full original list, unique source/function, strong production/recompile and source/object/manifest contracts; all original strict ELF/EH/native cores remain unchanged. An actual isolated MWLD link selects that strong destructor and discards all3 backup allocations. Root must repeat the exact source route and original GLOBAL800/240 placement/discard checks on both full native ELF/map pairs before credit.

Full original extabindex records80015F60..8001F29C, final descriptor through1F2C0, ctor99920..99980 and dtor99980..999A0 ownership scans pass. The sole initialized DOL pointer into this function is its original extabindex record. Existing early_misc_event_control caller/header identifiers remain unchanged. No data, literals, BSS, padding, external identities or shared headers migrate.

Frozen batch212 preserves the exact source, all compiler evidence, full ownership audit, source-bound owner gate, positive/negative guards and isolated native proof. Full-DOL acceptance remains the integrator's responsibility.
