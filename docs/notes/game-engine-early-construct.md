# Small early construction and setup entries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-seven ordinary C++ fragments match 2,220 original text bytes and 540
original exception/index bytes. They call one established base/Handle constructor
or `fn_80090084`, then perform the directly observed table, word, or byte
assignments and return the original object where the entry does so. Existing C
names remain unchanged. The already native `Agent_80044118` and `Agent_800E75B0`
constructors are implemented with actual C++ constructor definitions under their
existing identities. No original-symbol rename is proposed.

Five ContainerBase-derived setups update the table at eight and directly
observed bytes/words near `0x65` through `0x72`. The fn_80090084 family updates
its table at zero and optionally clears or assigns incoming opaque 32-bit words
at eight and twelve. Repeated intermediate assignments and zeroing remain in
the source and compile into the original stores. Additional small Agent/Root
setups expose only observed tables and fields through `0x9C`. Handle wrappers
perform the original one, two, or three word-zero assignments after the existing
native Handle constructor. `fn_800C07DC` is a void wrapper, matching its original
body without adding an explicit returned-object move.

Private views use opaque gaps and fields named by observed offset. Incoming
stored words remain opaque 32-bit values; no wider ownership or pointer meaning
is claimed. These are minimum construction views, not complete recovered
classes. Actual native constructor declarations are kept local and used only to
emit these established original entries. All calls retain established native/C
symbols and calling conventions; no assembly aliases or ABI thunks are used.

GC 1.3.2 uses established container-base `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` flags. All 27 final private probes and fresh
production compilations match every allocated byte, function/object extent, and
actual relocation. Each owns its original eight-byte exception record and
twelve-byte index, with no extra helper, vtable, or other allocation. The
separate `8005BFC4` global-reset candidate is excluded from this handoff.

The frozen manifest, source hashes, strict verifier, exact split/config
suggestions, and ownership audit are under
`scratch/game_engine_early_construct_continuation/`. Full original extabindex
and constructor/destructor table scans confirm the expected EH pair and no
ctor/dtor table references for each included body. Only actually referenced
undefined ELF symbols appear as dependencies. External table/global storage,
neighboring code, and other original data keep their owners. Each address is a
bounded partial source fragment. Root performs full native executable acceptance.
