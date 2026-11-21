# Repeated ordinary destructor layers around 8008EE20

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Thirty-two ordinary C++ destructors have exact isolated production objects:
4,480 text bytes plus 1,664 original exception/index bytes and 352 actual
relocations. The handoff is
`scratch/game_engine_fn_layers_continuation/final_integration.json`; strict
verification, exact split/config suggestions, source hashes, and complete
ownership audits are alongside. Root performs central acceptance.

The functions lie from `8008EE20` through `8008FFD4`, each 140 bytes. Their
observed behavior is a two-level native destructor hierarchy: the derived
destructor updates the table at offset zero; its inline base destructor updates
the base table and calls preserved `fn_8009009C(this, 0)`. A positive signed
16-bit deletion flag releases the allocation through `fn_801EF610`. A native
class-specific `operator delete(void*) throw()` emits the exact original
specification handler, 40-byte EH record, and 12-byte exception index.

Each source uses ordinary private base/derived C++ declarations, not manually
encoded null checks or assembly. The private one-pointer view is the minimum
layout observed by destruction; no full object size or gameplay role is claimed.
Table identities come directly from each original relocation. Distinct
functions remain separate bounded source fragments, including the unmatched
intervening `8008F4B0` function, which is outside this handoff.

All 32 objects matched on the first structural probe with GC 1.3.2, established
container-base flags and `-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on`. No weak backup helper, extra allocated section, or output
padding is emitted. All original text/EH/index bytes compare after applying
real relocations. Each unit has exactly eleven allocated-section relocations.

Original `fn_*` names have no compiled source/header/assembly caller. The frozen
manifest proposes guarded `original_symbol` renames to genuine native
`Object_<address>` destructor symbols, with original addresses and global
binding retained. The shared base `fn_8009009C` keeps its established C symbol.
No assembly alias, thunk, or shared-header change is needed.

The complete original extabindex, constructors, and destructors tables were
audited. Every function owns exactly its original 40+12 exception bytes; no
constructor/destructor-table pointer targets these bodies. Original instruction
extents are exact. Original data and neighboring functions retain their owners;
these source fragments do not claim complete original translation units.
