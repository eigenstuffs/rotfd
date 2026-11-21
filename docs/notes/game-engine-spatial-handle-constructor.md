# Spatial owner with native handle members

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_spatial_handle_ctor.cpp` reconstructs the complete 304-byte
constructor at `802461E0..80246310` as
`SpatialHandles_802EA2E0::SpatialHandles_802EA2E0()`. Address-based class names
identify recovered ABI views, not original source names. The common observed
base is Root, Resource and a 20-byte spatial resource prefix. The private
header supplies its external destructor and observed virtual slots without
emitting a vtable or destructor definition.

The spatial base copies the first three floats of mutable `game_vec4_zero`,
stores the supplied radius and clears its flags. A three-word member clears
20..28, an opaque B8-byte member at 4C delegates to retained `fn_8024405C`, and
three native handle members at104/108/10C use two, three and three empty typed
constructor layers. The body clears six words and initializes the four-float
tail. A named per-float point copy and sequential assignments recover the
native float operations, store order and member aliases. The common spatial
base accepts the radius as a parameter so sibling constructors reuse one
consistent declaration.

`scratch/engine_spatial_handle_ctor_20261010ca/verify.py` checks every retained
byte and all16 real relocations with standard GC/1.3.2 engine flags. All264
additional bytes are three inventoried unused weak destructor backups with six
real relocations; no retained reference reaches them. There are no emitted
vtable, literal, BSS, padding, exception or startup allocations. The full raw
original extabindex/ctors/dtors audits, including descriptors and zero tails,
have no references to this extent.

The production proposal migrates `fn_802461E0` to the genuine native constructor
identity and the external tables `lbl_802EC118` (76 bytes) and `lbl_802EA2E0`
(80 bytes) to their native class identities. Original addresses, extents and
data owners remain. Six compiled consumer sources and their canonical proof
records are inventoried in the scratch directory; no existing header references
those old table names. The root integrator audited these as continuation-added
files and owns preserved originals, identifier-only consumer changes,
unchanged-address byte proofs and refreshed canonical inventories. This agent
has not edited consumers or central metadata. No alias or thunk is proposed.

The frozen manifest, split/configuration instructions, dependency declarations,
consumer inventory and complete ownership audit are in the same scratch
namespace. Central NonMatching registration, original DOL hash acceptance,
regression and native allocation checks remain the final gate.
