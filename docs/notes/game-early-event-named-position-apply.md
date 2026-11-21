# Event-driven named actor position apply

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80073E00` owns 600 text bytes at `80073E00..80074058`, eight exception bytes at `8000C9D4..8000C9DC`, and its twelve-byte index record at `80019398..800193A4`. The ordinary C++ source is `src/Game/early_event_named_position_apply_80073E00.cpp`. GC 1.3.2, Gekko, O4,s, exceptions enabled and use_lmw_stmw reproduce every retained byte and all 22 real relocations. Central original-DOL acceptance remains pending.

The routine checks actor event flags. Event51 invokes virtual slot34; eventA8 starts the resolved actor's control. Events3A,39,86 look up a named target, copy the source actor's related position to the target's related object, invoke slot38, set bit20000 in the target's 64-bit flags, and notify its state and controller.

The original helper returns a genuine Handle object. A private derived return wrapper with an inline empty destructor preserves the original normal cleanup. Sequential destination/source locals and distinct concrete source/target entry types preserve evaluation order and manager reloads. A by-value Vec3 constructor preserves the three original temporary stores; the existing signed-char lookup signature preserves argument setup. No caller or native identity changes are proposed.

The compiler also emits an unused private Return_80073E00 destructor76 with eight exception bytes and twelve index bytes. All three allocations and four discarded relocations are inventoried without credit. The existing production-defined-weak-eh-override-v1 route with no strong overrides verifies the full object; an actual isolated MWLD link discards all three backups. Full-game native placement and discard must be checked by the integrator.

The complete original EH records and final descriptor, ctor/dtor tables, initialized pointer words, and compiled-source consumer inventory were audited. The sole non-EH initialized pointer is802B7ED0 inside the original GLOBAL lbl802B7E38[A0] callback table, which retains original ownership. Borrowed Name string lbl8029CAA0 stays external. There is no owned literal, data pool, BSS or padding. Existing callers and shared metadata remain unchanged.

Frozen evidence is listed in scratch/game_engine_batch193, including strict fresh recompilation, all allocated sections and actual relocations, original ownership audit, and actual native backup discard proof. This is an isolated function plus its complete original metadata, not a claim that its original translation unit has been recovered.
