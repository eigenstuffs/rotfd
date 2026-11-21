# Native destruction with observed fields at 8 and C

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-two ordinary C++ destructor fragments match in isolated production
objects: 3,280 text bytes plus 1,144 original exception/index bytes and 234
actual relocations. The frozen handoff is
`scratch/game_engine_fn_reset_layers_continuation/final_integration.json` with
source hashes, ownership audit, exact splits/config suggestions, and verifier.
Root performs central original-DOL acceptance; these results are isolated.

Four 136-byte native root destructors update the primary table at offset zero,
clear observed word fields at 8 and C, and call preserved C function
`fn_8009009C(this, 0)`. Eighteen 152-byte derived destructors update their own
table first, then automatically destroy an inline base that performs the same
reset and external base call. The native positive signed-short deletion flag
and class-specific `operator delete(void*) throw()` reproduce the existing
custom release and specification handler. Opaque word4 is never accessed.
The 16-byte private view is a minimum observed destruction layout, not an
assertion of full class size or semantics for the cleared words.

Original tables and both zero stores are established directly by each function's
assembly and relocations. Every unit matched on the first ordinary C++ probe and
again from its frozen production source, with GC 1.3.2 and established
`-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags. Roots have nine
actual allocated-section relocations; derived bodies have eleven. Each object
emits only original text, 40 EH bytes, and one 12-byte index; no weak helper,
padding, or additional allocated section is present.

The complete original exception-index, constructor, and destructor tables were
audited. Every function has exactly the expected exception pair, no ctor/dtor
table reference, and exact instruction extents. Existing source/header/assembly
callers do not use the prior provisional fn_* names, allowing guarded
original_symbol publication of native `Object_<address>` destructor symbols.
No aliases, thunks, or shared declaration changes are introduced. Neighboring
functions and original data retain their owners; each source is a bounded
partial text/EH fragment rather than a complete recovered original TU.
