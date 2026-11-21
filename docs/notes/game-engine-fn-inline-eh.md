# Inline destruction layers with preserved external entries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-two ordinary C++ fragments preserve their original C entry names and
match 3,112 original text bytes plus 1,144 exception/index bytes. Nineteen
140-byte bodies update two observed table pointers at offset eight before
calling the established Agent or `fn_8002AE0C` base cleanup. Two 156-byte bodies
update three observed table pointers at offset zero before `fn_8009009C`.
The remaining 140-byte `fn_8005C01C` updates its table at offset eight, clears
the two observed words of external `lbl_80377694`, and calls the Agent base.
No ownership of that external global is transferred.

The inline-layer bodies use a private ordinary C++ destructor expression,
`self->~InlineBase()`, inside the original C entry. This preserves the original
compiler null checks at each destruction layer while leaving accepted callers
and original ABI names intact. The two three-table bodies use a nested inline
base destructor. Every external base receives deletion flag zero. The outer
entry releases the allocation only when the signed low 16 bits of its observed
deletion flag are positive, using ordinary `dispose(void*) throw()` to produce
the original exception-specification handler. The table views claim only the
observed fields, not a complete object layout or size.

All 22 first probes match instructions and compiler-emitted metadata without
assembly, aliases, masked scoring, extra weak functions, or extra allocated
sections. GC 1.3.2 uses the established container-base flags, including `-O4,s
-inline auto -Cpp_exceptions on -use_lmw_stmw on`. Every emitted allocated byte,
function/object extent, and actual relocation is verified from fresh production
compilation. Existing C names, including `fn_8005C01C`, are preserved. Protected
`fn_80020FE8` remains excluded.

The frozen handoff is
`scratch/game_engine_fn_inline_eh_continuation/final_integration.json`, with
production source hashes, exact splits/config suggestions, strict verifier,
and ownership audit. The full original extabindex and constructor/destructor
tables establish one 40-byte EH record and one 12-byte index for each body,
with no ctor/dtor table references. Dependency symbols contain only actually
referenced undefined ELF symbols. Each address remains a separate partial
source fragment; other original data and functions keep their original owners.
Root performs central integration and complete native executable acceptance.
