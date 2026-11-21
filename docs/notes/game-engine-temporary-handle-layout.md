# Full native extent for temporary Handle constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This corrected isolated handoff supersedes the unintegrated temporary Handle
constructor proposal while preserving every older source, probe and frozen hash.
The earlier private construction view ended after the last observed Handle7C
and established only a minimum0x80-byte extent. The accepted factory8020A324
allocates0xC4 bytes (CameraEngineZone_Z.h:76), and the derived constructor758B0
begins its own fields at0xC4. This corrected private class includes the explicit
opaque80..C4 tail and checks sizeof==0xC4. No interpretation of the opaque tail
is claimed. All code, cleanup metadata, real targets and compiler backups remain
identical to the prior proposal.

The isolated native C++ constructor reproduces all 312 original code bytes,
112 extab bytes, 12 extabindex bytes and 24 retained relocation targets.
Production recompilation verifies every emitted allocation and real relocation.
No central source credit is claimed before the full original link and backup
discard checks pass.

The base uses the established 0x20-byte ObjectsRoot layout, derived index20,
five-store Handle24, one-store Handle28 and opaque2C..6C. Its inline constructor
installs table802EBE28, initializes both Handles, sets index20=-1 and creates an
empty five-store Handle temporary. Ordinary release/copy/retain statements
assign that temporary to member24, after which its native destructor is called.
The derived constructor installs table802EBE80, copies the first three mutable
zero-vector elements to6C/70/74, loads scalar78 and constructs Handle7C.
The exact original cleanup metadata references the existing native Root,
Handle80025B74, Handle8002B67C and Object80075DE4 destructors.

Five genuine inline Handle destructor bodies are emitted as weak backups:
Handle80025B74 size128 and private ZeroHandle4/3/2/1 sizes124/120/116/112. Their
600 text bytes and 260 bytes of backup EH/index metadata receive no credit.
All raw bytes, weak bindings, offsets, extents, relocation counts and exception
group associations are frozen. There are 35 backup relocations. Two retained
EH pointers reference the defined weak Handle80025B74 symbol; the accepted
bounded override verifier resolves them to the independently verified existing
strong definition at80025B74. Its canonical source, recursive headers, raw
production object hashes, allocated bytes and actual targets are recompiled and
verified independently. Unused private backup symbols have no strong owner and
must be absent from the final linked ELF.

Central acceptance must prove the entire 600-byte backup text and 260-byte
backup metadata are discarded from this object while the original strong
Handle definition remains at its original place. The retained extent remains
312 bytes; no compiler backup bytes count toward progress. No assembly aliases,
adapters, masked comparisons or replacement original bodies are used.

The proposed native constructor symbol carries original_symbol=fn80075C2C.
The sole accepted source consumer is factories8020A324.cpp, with exactly one
extern-C declaration and one call. Current source and canonical hashes are
frozen in the pending consumer migration record. Root's accepted identifier-only
migration gate must preserve original/current snapshots and prove unchanged
consumer allocated bytes and resolved relocation targets before staging.
This handoff changes no consumer, shared header or central metadata.

The full original extabindex and constructor/destructor startup tables were
scanned. The true function extent owns exactly one complete EH/index record and
has no startup table reference. Every initialized data section was scanned for
word pointers to this function: only its owned extabindex function pointer is
present. Original external data and all base/destructor definitions remain
outside this partial unit. Source, recursive header, verifier and manifest
hashes are frozen; the source has no quoted includes.
