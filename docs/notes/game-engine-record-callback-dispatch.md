# Record callback dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary C entry `fn_800E9240` matches its complete `800E9240..800E94A8` extent (616 code bytes) on the first probe. It uses GC 1.3.2 and the established `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags. The reconstructed entry retains its existing name.

Events 0–2 pass observed twelve-byte member-pointer values to the existing registration/removal controls. Events 3 and 4 query callback flag bits 2 and 0, using the supplied callback when nonnull or the existing lookup control otherwise. Event 5 returns one. Event 6 returns the callback's signed short at `2A`, or -9999 for a null callback. Other events reset the original three global scratch fields, preserve the event-11/index-minus-one early return, clear the supplied callback through its original control, and dispatch the observed index-adjusted event. The final callback update and integer return remain in their original order. No additional null or range checks are introduced.

The private callback view establishes only unsigned short flags at `28` and signed short index at `2A`. `MemberPointer` is the observed three-word, twelve-byte aggregate. Passing those ordinary aggregate values reproduces the original separate stack temporaries and calls without helper code. The six-entry pool `802C90C0..802C9108` is an external original data dependency; entries 1–5 are read here, while all pool bytes and function-table references remain assembly-owned.

The native switch emits exactly the original seven-entry jump table at `802C9108..802C9124`. Compiler-local object `@51` corresponds to provisional original `jumptable_802C9108`; no compiled source consumes that old table identifier. All seven actual table relocations target the retained function at bounded original instruction offsets. `data_audit.json` freezes the table cases/targets, whole-table hash and external member-pointer pool hash. Only the seven-entry switch table transfers into the new source unit; surrounding original data remains outside it.

Final production compilation and an independent strict recompile match all 616 code bytes, 28 jump-table bytes, 20 original exception/index bytes and 27 actual relocations. There is no weak code, helper emission, new literal or other allocated output. All compiler sections, local objects, function extents and real relocation targets are inventoried. Dependencies include actual undefined ELF symbols only. The production source expands the private view and has no quoted-header dependencies.

Complete original exception-index, ctor and dtor scans cover `80015F60..8001F2C0`, `80299920..80299980` and `80299980..802999A0`. The function has exactly its owned original exception/index pair and no startup pointers. `ownership_audit.json` inventories all initialized-data references into the function, distinguishing its transferred compiler jump table from unchanged original function tables, and records current compiled consumers without editing them.

The frozen handoff is `scratch/game_engine_record_callback_dispatch_continuation/handoff.json`. Exact code, data and EH/index ranges, flags and symbol extents are in `final_integration.json`; `verify.py` recompiles and checks every emitted allocation, original byte and resolved relocation. Central full original-DOL and regression checks remain pending integration.
