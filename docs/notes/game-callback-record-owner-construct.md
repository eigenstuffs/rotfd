# Callback record-owner construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The genuine C++ constructor `CallbackRecordOwner::CallbackRecordOwner()`
reconstructs the complete 552-byte function originally labeled
`fn_802527C0` at `0x802527C0..0x802529E8`. It constructs the native Root,
installs the Resource and intermediate tables, initializes the vector and
scalar prefix, then installs the final table. It clears the record pool,
sets the index to minus one and the short key at `0x30` to zero, and resizes
the pool to eight 20-byte records.

The ordinary resize method retains the original growth and shrink branches,
allocator calls, placement construction and empty destruction loop. New
records copy the original zero vector, set their fourth float from the
original constant and set their signed tag to minus one. An inline index
update releases a valid old index and stores the registry result, using the
nontrivial value-return ABI. Its local lifetime boundary reproduces the
native two temporary stack slots.

Class names and surrounding views remain provisional; only accessed fields
and observed lifetime layers are established. The original zero vector,
constant, registry, tables and allocators retain their owners. The existing
registered-key initialization caller must use the compiler's genuine
constructor spelling and retain its exact allocated bytes and relocations.

`scratch/game_callback_record_owner_construct/verify.py` checks the complete
retained extent and every actual relocation without masks. Three trailing
unused weak destructors occupy 432 bytes; they are separately inventoried
by name, offset, extent, binding, raw hash and relocations, receive no
matching credit, and must be absent from the linked executable. Full
executable and baseline acceptance is required before credit.
