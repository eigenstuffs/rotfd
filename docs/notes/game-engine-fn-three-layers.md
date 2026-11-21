# Three ordinary destructor layers around 800A2100

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Thirty native C++ destructor fragments match in strict isolated production
objects: 4,680 text bytes, 1,560 original exception/index bytes, and 390 actual
relocations. The frozen handoff is
`scratch/game_engine_fn_three_layers_continuation/final_integration.json` with
hashes, exact split/config suggestions, complete ownership audit, and verifier.
Root alone performs central metadata changes and full-DOL acceptance.

The functions are 156-byte bodies within `800A2100..800A48D4`. Each destructor
updates its primary table at offset zero. Two inline base destructor levels
then update their own directly observed table identities before the preserved
external C call `fn_8009009C(this, 0)`. Positive signed-short deletion flags use
the existing custom allocator. Ordinary class-specific `operator delete(void*)
throw()` generates the original specification handler and exact 40-byte EH plus
12-byte index. The private classes describe the minimum one-pointer destruction
view; they do not assert complete object sizes or recovered gameplay names.

All functions matched on the first structural probe and after production-source
recompilation with GC 1.3.2 and established `-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on` flags. Every unit emits exactly thirteen real allocated-section
relocations, its original text/EH/index extent, and no additional helper,
allocated section, or padding. Each address remains a separate bounded fragment;
the intervening original functions and data remain outside this work.

The complete original extabindex, constructors, and destructors tables were
audited. Every retained function owns one exact original exception pair and has
no ctor/dtor-table pointer. Full original assembly extents are recorded. Prior
provisional fn_* names have no compiled source/header/assembly callers; guarded
native `Object_<address>` destructor naming is proposed through original_symbol
without aliases or thunks. The established external C base name remains intact.
