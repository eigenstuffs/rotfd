# Queue owner native construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_queue_array_ctor.cpp` recovers the complete172-byte constructor
at `80231140..802311EC` as `QueueArray_802EBD60::QueueArray_802EBD60()`. The
existing factory allocates60 bytes before installing its more-derived table;
the address-based class name identifies this observed intermediate ABI view.

Genuine Root construction and two typed handle members reproduce self/member
aliases that the old raw probe could not retain. The first handle at0C has two
zeroing layers and the second at10 has one. Eight native handle array elements
at14 use `__construct_array` with the original root constructor/destructor.
The body clears words54/58 and sets the flag at5E; the opaque gap is untouched.
The first genuine source probe is exact. Prior private probes remain unchanged.

`scratch/engine_queue_array_ctor_20261010cf/verify.py` checks all172 retained
bytes and10 actual relocations with standard GC/1.3.2 flags. Two inventoried
unused weak destructor backups are172 bytes with four relocations and have no
retained callers. There is no data, BSS, padding, vtable, exception or startup
emission. Complete raw original extabindex/ctors/dtors audits include descriptor
and zero-tail words and have no references to this function.

The guarded function/table migrations retain original addresses, extents and
attributes. The external EBD60 table remains64 bytes with its current data
owner. Consumers are `src/Game/owner_base_array_destroy.cpp` for the table and
initial-snapshot `src/Game/derived_factories_8020A43C.cpp` for the function.
Root owns preserved original copies, identifier-only replacements and unchanged
allocated-byte/resolved-target recompilation proofs. No existing consumer or
central metadata was edited by this agent; no alias or thunk. The frozen
manifest and ownership evidence await central NonMatching registration and
original-hash/regression/native allocation acceptance.
