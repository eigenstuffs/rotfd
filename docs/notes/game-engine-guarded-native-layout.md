# C42D8 native construction with established base extent

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This corrected isolated handoff supersedes the unintegrated
engine_guarded_native_construct C42D8 candidate. The earlier source and all
frozen hashes remain preserved as probe history. Its2C opaque base view placed
the observed Handle correctly but did not distinguish the actual20-byte native
Root from a derived opaque tail. Accepted manipulator_callbacks_internal.h
establishes sizeof(ObjectsRoot80213EBC)==20. This source uses that native base
extent and places the unknown20..2C bytes in the derived object instead.

The corrected private declaration compiles to exactly the same92 original code
bytes,28 extab bytes,12 index bytes and7 actual relocations. The isolated
production object is strictly verified under the established GC1.3.2 flags.
No helper, alias, adapter, assembly or extra allocation is emitted. The derived
constructor installs table802BF7DC, constructs the Handle at2C with two zeroing
layers and clears bytes30/31. Existing native Root constructor/destructor
identities and exact compiler DESTROYBASE metadata remain unchanged.

The original C name fn800C42D8 is proposed to become
__ct__15Object_800C42D8Fv at the same original address. Root has already proven
and applied the accepted identifier-only consumer migration to the sole factory
consumer, factories_8007E160.cpp, while this constructor remains unintegrated.
The new manifest records the exact migration proof SHA256 and current source
and canonical hashes, and preserves the earlier pending inventory as history.
That proof preserves original/current snapshots and establishes unchanged
allocated bytes and actual relocation targets. No consumer source or shared
metadata was modified by this handoff.

Full original extabindex80015F60..8001F2C0 and ctor/dtor scans audit true function
extent and exact owned metadata. There is one EH record and no startup table
reference. Source, recursive header, manifest and verifier hashes are frozen.
The corrected handoff requires full central original DOL acceptance; the older
oversized private view receives no independent credit.
