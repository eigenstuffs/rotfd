# Basis resource and array handle constructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_basis_resource_ctor.cpp` reconstructs two complete adjacent
constructor extents, 272 bytes at `802396D0..802397E0`. The resource constructor
is212 bytes; the native `Handle_8003F47C` element constructor is60 bytes. Both
retain their original addresses under genuine C++ constructor identities.
Address-based class names document observed ABI views.

Root/Resource virtual construction preserves the original base aliases. Two
native handle array elements at74 use `__construct_array`, with the recovered
native element constructor and already accepted typed-handle destructor.
The body initializes status words, clears a nine-float basis and sets its
diagonal, then initializes the flag and position/rotation floats. The native
element constructor calls the root handle constructor and applies two zero
stores through an empty derived layer. This genuine construction solves the
older raw-entry probe's missing base alias and vtable store; that prior research
remains untouched.

`scratch/engine_basis_resource_ctor_20261010cb/verify.py` applies all14 retained
real relocations and verifies the exact272 retained bytes, bindings and extents
with standard GC/1.3.2 flags. One unused weak destructor backup accounts for84
additional bytes and two real relocations, with no retained reference to it.
No data, BSS, padding, vtable, exception or startup allocation is emitted.
Complete raw extabindex/ctors/dtors audits include descriptors and zero tails;
none references these extents.

The guarded external table migration is `lbl_802EBFD8` to
`__vt__22BasisResource_802EBFD8`, retaining its40-byte original allocation and
owner. Only `src/Game/engine_vector_ops_80239458.cpp` and its shared header
reference that old identity. Their canonical manifest is inventoried. Root
owns preserved originals, identifier-only changes, unchanged-address byte
proofs and refreshed canonical evidence; this agent has not edited those
consumers or central configuration. There is no alias or thunk.

The frozen isolated manifest and integration instructions live beside the
verifier. Register NonMatching before central original-hash, regression and
native allocation acceptance. Adjacent flag refresh72 is a separate frozen
unit and is not counted here.
