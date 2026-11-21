# Spatial binding constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_spatial_binding_ctor.cpp` reconstructs the complete272-byte
constructor at `8024CDCC..8024CEDC` as
`SpatialBinding_802EC2C0::SpatialBinding_802EC2C0()`. The private header includes
the newly recovered common spatial base declaration from
`engine_spatial_handle_ctor.h`. Original names beyond established Root and
Resource identities are not claimed.

The base copies the first three floats of mutable `game_vec4_zero`, stores its
own original radius literal and clears its flags. Three words at20..28 and a
two-zero native handle at2C are constructed before the body clears the observed
word fields and assigns minus one at3C. Genuine virtual construction preserves
the original base and member aliases and solves the older raw-table probe.
All older lifecycle diagnostics remain frozen and unchanged.

`scratch/engine_spatial_binding_ctor_20261010ce/verify.py` verifies all272 retained
bytes and11 actual relocations with standard GC/1.3.2 flags. Two unused weak
handle destructor backups are fully inventoried as172 bytes and four real
relocations; retained code does not reference them. No owned data, BSS, padding,
vtable, exception or startup allocation is emitted. The complete original raw
extabindex, ctors and dtors audits include descriptors and zero tails and have
no references to this extent.

The constructor identity migration retains the original function address and
size. The external native spatial base table uses the same guarded76-byte
identity migration as its sibling. `lbl_802EC2C0` becomes the derived native
table identity, preserving its80-byte allocation and existing data owner. No
existing compiled source or header references the old derived table or entry
identity. Root alone integrates symbol/configuration changes and the shared
base table consumer migration. No alias or thunk.

The isolated manifest, complete raw table audit and dependency inventory are
frozen in the scratch directory. Central NonMatching registration, original
DOL hash, regression and native allocation checks remain the final gate.
