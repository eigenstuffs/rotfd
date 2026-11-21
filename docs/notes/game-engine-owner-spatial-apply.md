# Owner spatial application

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_owner_spatial_apply.cpp` reconstructs the complete ordinary
C++ entry `fn_80248D20`, at `80248D20..80248FEC` (716 text bytes), under the
standard Game compiler flags with floating-point contraction enabled in source.

The entry resolves the object's resource handle by generation, computes a
clamped height-dependent factor, refreshes the cached inverse matrix when flag
`0x20` is set, and transforms the incoming record position. It copies the
record's second vector to the output, builds three points from the resource
position and two bounds vectors, and updates the owner's virtual sphere through
`fn_801F0C68`. It clamps the output scalar using the resulting sphere radius,
sets the pointed-to status bit `0x20`, and sets object flag `0x80000`. These field
names describe observed operations; their full gameplay roles remain unknown.

The matrix helper uses separate ordinary X/Y/Z result locals before returning
a vector. This reproduces the original fused arithmetic and float allocation.
The resolver is written directly in the entry: the equivalent returning inline
helper left 41 saved-pointer register differences. Entry-local index, manager,
generation and resource variables reproduce all original pointer registers.
A named output pointer before the three virtual radius queries preserves the
original destination-pointer lifetime. No assembly, forced register operations
or object modification is used.

## Verification and ownership

`scratch/engine_owner_spatial_apply_20261011dp/final_integration.json` is the
frozen strict handoff. Its verifier recompiles the production source and checks
all allocated sections, symbols, complete retained bytes and actual relocation
targets against the verified original DOL. All 716 bytes and 13 relocations
match. The object emits only retained `.text`, with no weak backups, initialized
data, BSS, padding, exception tables or compiler startup allocations.

The full original exception-index, constructor and destructor allocations have
no references to this entry. The shared context and original float symbols
`lbl_8037B418`, `lbl_8037B41C`, `lbl_8037B420` and `lbl_8037B424` retain their
existing external identities and ownership. Adjacent routines and original data
remain outside this partial translation unit. No shared symbols, consumers,
headers or build metadata require migration.

The dedicated scratch directory preserves source variants, resolved comparison
results, strict scripts, complete original-table audits and frozen file hashes.
The direct and nested entry-local resolver probes both match; the production
source uses the direct form. Native member, reference, declaration-order,
return-constructor and compiler-option variants were bounded research probes.
The isolated match remains subject to root's central registration, executable
hash and regression acceptance before it contributes progress.
