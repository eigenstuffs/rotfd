# Menu member constructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary constructor sources recover296 original bytes:
`engine_menu_pair_ctor.cpp` at `8021B5F4..8021B688` and
`engine_menu_array_ctor.cpp` at `8021C760..8021C7F4`, each148 bytes. Their shared
new private header describes only the external4C-byte MenuBase construction
interface, two empty typed handle layers and observed member offsets. It does
not claim a complete native virtual interface or original derived class names.

Both constructors call accepted `MenuBase_8021D7E4(0,0xFF)` and build two handles
with two repeated zero stores each. The first clears a three-word member at4C
before handles58/5C. The second builds handles4C/50 before clearing a three-word
member at78 and flag59. Both first source probes match every retained byte.
Opaque gaps stay untouched; class sizes60 and84 are checked at compile time.

`scratch/engine_menu_member_ctors_20261010ch/verify.py` recompiles both independent
objects with standard GC/1.3.2 flags and strictly verifies all296 retained bytes
and ten real relocations. Each object emits172 inventoried unused weak handle
destructor bytes with four additional relocations and no retained reference.
Neither emits data, BSS, padding, vtable or exception/startup allocations.
Complete original raw extabindex/ctors/dtors audits, including descriptors and
zero tails, contain no references to either function.

The native constructor/table identities are MenuPair_802EB2F0 and
MenuArray_802EB348. Each external table retains its original88-byte allocation
and data owner. Exact old-name consumer inventories include initial-snapshot
`src/Game/factories_80209554.cpp`, continuation-added flat/nested menu cleanup
sources, and `include/Game/engine_menu_array_cleanup.h`. Root owns original
snapshots and file copies, the identifier-only migration transaction and proof
of unchanged allocated bytes/extents/resolved targets. This agent changes no
existing consumer or central metadata. Both manifests keep original_symbol
guards, with no aliases or thunks. Central NonMatching registration and full
DOL hash/regression/native allocation acceptance remain the final gate.
