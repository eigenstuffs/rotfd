# Base cleanup and secondary table entries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eight ordinary C++ fragments match 1,020 original text bytes and 416 original
exception/index bytes. Seven retain their existing C entry names. The eighth
implements the already established native `Agent_8002B5F4` destructor at
`8002B6EC`; its identity and all accepted callers remain unchanged.

Five 132-byte bodies update their observed table at offset eight before their
established base cleanup. `fn_80024ECC` also clears the word at offset `0x80`.
`fn_800656AC`, `fn_80065960`, and `fn_80065CB0` update the secondary table at
`0x94` to the primary table plus `0xB4`. `fn_8009A8AC` similarly updates offset
`0x318` to the primary table plus `0x170`. These offsets and pointer adjustments
are directly established by original instructions. No complete class size is
inferred from these private views.

The 112-byte `fn_8009009C` only updates its table at offset zero before optional
allocation release. The 100-byte `fn_80052454` only performs optional release.
They retain their established C entries, including the many accepted callers of
`fn_8009009C`. The 148-byte native Agent destructor updates the table at offset
eight, destroys the observed Handle storage at `0x80` through an ordinary inline
Handle layer, and calls preserved `dtor_80024E50(this, 0)`. The private Agent view
uses opaque bytes for the Handle storage and explicitly invokes its established
native lifetime operation; no automatic duplicate destruction is introduced.

All entries return the original pointer and release only for a positive signed
low-16-bit deletion flag. Ordinary `dispose(void*) throw()` or native custom
`operator delete` produces the original exception-specification action.
GC 1.3.2 uses the established container-base `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` flags. All eight initial probes and fresh
production compiles match every allocated byte with actual relocations. They
emit only the original text, 40-byte exception record, and 12-byte index pair;
there are no weak backup functions, added allocations, or assembly aliases.

The frozen source manifest, hashes, strict verifier, split/config suggestions,
and ownership audit are under
`scratch/game_engine_fn_cleanup_eh_continuation/`. The complete original
extabindex and constructor/destructor tables were audited: each body owns its
expected exception pair and has no ctor/dtor table references. Dependencies
contain only actually referenced undefined ELF symbols. Other original data
and neighboring functions remain outside these bounded partial source fragments.
Protected `fn_80020FE8` stays excluded. Root performs complete native acceptance.
