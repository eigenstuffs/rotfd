# Callback registration startup lifetimes

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The separately frozen proposal in
`scratch/game_engine_callback_registration_continuation/handoff.json` recovers
seven original C entries at 80048470, 80048EF4, 80049B90, 8004AA48, 8004D9D4,
8004F164, and 8005039C. Each owns 344 text bytes, its original 40-byte exception
record and 12-byte index, and 31 actual retained relocations. The total proposed
credit is 2,408 code bytes and 364 exception bytes. Central integration and the
full original-placement DOL acceptance remain the integrator's responsibility.

Each entry clears its per-object global and 80377648, initializes the registration
manager, constructs a scoped Agent_80044118 and registers its original member
pointer, destroys that temporary, and then constructs/registers/destroys a second
scoped object. The genuine C++ lifetime supplies the original exception cleanup.
Two function-scope MemberPointer copies preserve the established stack order;
the 48470 and F164 cases use an ordinary inline registration helper for the first
temporary. All original entry names and existing callers remain unchanged.

The first Agent view has the established 0x70 factory extent. Its field at 0x68
is set to one; opaque regions preserve the remaining storage. The second object
views use the established factory extents 0x70, 0x88, 0xA0, 0xA8, 0xA8, 0x78,
and 0x88 respectively. Their opaque storage is a size declaration, not a claim
to recovered field semantics. Constructors and destructors retain their current
original identities. All member-pointer records remain owned by original
assembly, including the first 12 bytes of the 72-byte symbol at 802B3708 and the
individual second records at 802B3AE4, 3B48, 3BAC, 3C10, 3ECC, 3F94, and 405C.
`original_data_reference_audit.json` includes all seven second records; it
supplements the earlier ownership audit's narrower 802B3 prefix filter.

The emitted retained exception cleanup refers to the compiler's weak
Agent_80044118 destructor. The already accepted global strong definition at
8004426C is independently recompiled, verified against every original owned
section and actual relocation, and compared byte-for-byte with its production
object. Its canonical manifest is a list: selection must be bounded by both
`src/Game/engine_container_agents_8004426C.cpp` and the exact native destructor
name. The read-only normalization in owner_proof.py demonstrates this selection.
No canonical data is changed. The retained ELF/EH strong authorization is solely
this Agent definition.

The compiler also emits an unreferenced weak ContainerBase destructor. Its
accepted strong owner is at 8002DF20, source container_base_destructor.cpp. The
new native-only adapter permits the unchanged native map/ELF checker to account
for this collision. It excludes every retained relocation by symbol name,
symbol index, and defined-section offset plus addend, including alias and
section-anchor targets. It independently checks the frozen owner source,
recursive headers, canonical identity, production object, fresh compilation,
all owned original bytes, and actual relocations. It appends that owner solely
to a deep copy of the native proposal; the retained ELF/EH authorization and all
original allocation/relocation inventories remain unchanged. The adapter is
limited to these seven frozen sources and the exact 244-byte weak extent at
object offset 880. All prior verifier cores and gates retain their raw hashes.

The independent pure-guard suite passes 371 cases: 49 rejections and four
accepted boundary/control cases for each source. The seven complete production
probes pass the separate source-specific gate. Seven isolated actual MWLD links
prove that all nine backup text/exception/index allocations per input are
discarded, both original strong definitions are selected, and retained exception
relocations resolve exactly. Wrong fixture basenames reject in every case.
These private links explicitly retain both strong owners to exercise the real
duplicate path; this is not a requested central FORCEACTIVE change. The full
game must independently retain both strong definitions at their original
addresses and repeat complete backup-discard and original DOL hash checks.

Each compiler object emits 780 uncredited weak text bytes and 156 uncredited
exception/index bytes, with 45 backup relocations. Across seven objects that is
5,460 text plus 1,092 metadata bytes and 315 relocations, all inventoried and
requiring final absence. None earns matching credit. Full original exception,
constructor and destructor table scans find exactly the owned exception entry
and no constructor/destructor table pointer for these functions. The entries
are registration routines reached by the existing type registry, not new
static startup hooks.

All earlier failed source variants and the first private native link without
explicitly retained strong owners remain preserved. That initial link omitted
the unused base owner and could not establish the requested duplicate-map
proof; only the separately named successful links are acceptance evidence.

The root adoption is frozen in `scratch/continuation_20261010/registration-root-adoption.json`, with independent review evidence in `registration-root-review.json`. Fresh `load_registration_verifier.py`, `audit_registration_link.py`, `integrate_registration_candidates.py` and `accept_registration_checkpoint.py` wrap the earlier routing/checkpoint paths. Every prior verifier/core/gate and native orchestrator retains its pinned hash. Aggregate canonical selection is bounded to the exact Agent native symbol, source and canonical hash. The frozen native checkpoint bytecode runs with a source-bound routing proxy that preserves the existing C40 handling and extends only these seven native proposals; its existing complete native map/ELF checks still prove original strong ownership and complete backup discard. Later checkpoints must use the registration-aware loader and acceptance runner so these checks repeat for all accepted sources.
