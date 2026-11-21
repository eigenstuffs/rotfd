# Remaining ordinary two-level destructor family

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Seventy-two further native C++ destructor fragments match the previously
verified two-level family: 10,080 text bytes, 3,744 original exception/index
bytes, and 792 actual relocations. Frozen manifests, source hashes, strict
verifier, split/config suggestions, and full original ownership audits are in
`scratch/game_engine_fn_layers_more_continuation`. Root performs central
full-DOL acceptance; no shared metadata or progress was edited here.

Each 140-byte destructor updates a table at offset zero. Its ordinary inline
base destructor updates the observed base table and calls the existing C
entry `fn_8009009C(this, 0)`. Signed-short positive deletion flags use the
original allocator. Class-specific `operator delete(void*) throw()` produces
the exact specification handler and 40-byte EH record with a 12-byte index.
The private one-pointer view is the minimum established destruction layout.
Table identities come from real original relocations; neither full class sizes
nor gameplay roles are inferred from repeated instruction shape alone.

Every fragment has an independent, bounded text/EH/index split. The address
range spans `800749F8..800F044C`, with intervening functions and data outside
this handoff. The first 32 frozen table-layer bodies around `8008EE20` are
excluded, as are all other call patterns and root/other-agent reservations.

Every function matched on its first C++ probe and on production-source
recompilation using GC 1.3.2 and established `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` flags. Each object has exactly eleven
actual allocated-section relocations and emits only original text/EH/index
bytes, with no additional helper, weak backup, section, or padding.

Full original exception-index, constructor, and destructor tables were audited;
each body owns exactly its original exception pair and no ctor/dtor-table
entry. Original assembly instruction extents are exact. No compiled
source/header/assembly caller refers to the previous fn_* names, so genuine
compiler-native destructor names are proposed with guarded original_symbol
mappings at the same global addresses. No alias, thunk, or shared declaration
change is introduced. The established C base function keeps its name.
