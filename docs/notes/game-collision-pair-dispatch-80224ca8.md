# Collision-pair event dispatcher at 80224CA8

`src/Game/collision_pair_dispatch_80224CA8.cpp` reconstructs the complete
2,476-byte function at 80224CA8..80225654. It resolves the participating nodes
and their agents, constructs event values, and sends begin/end callbacks using
the observed Handle copy and destruction lifetimes. The reconstructed raw
resolver and typed accessor preserve the native pointer evaluation order.

The function owns the complete 16-byte scalar pool at 8037B120..8037B130:
-1612.0f, four natural alignment bytes and a signed integer conversion bias.
Four bytes were already matched, so the new credit is 2,476 code bytes and
12 data bytes. All eleven old scalar references belong to this function.
The following eight bytes remain in an explicit original unit. The original
data-pointer and exception-index scans found no external roots into the new
owned ranges.

The compiler emits three additional weak destructors totaling 232 bytes and
a 32-byte nonallocated category table. Their complete output is preserved and
inventoried. The native linker marks all three weak functions unused; they
receive no source credit. The retained sections have 57 actual relocations,
with seven uniquely selected external providers and no allocated exception data.

The shared callback wrapper `fn_802073E8` in `root_base.cpp` now declares and
forwards its fourth float parameter explicitly. The native wrapper already
forwards that argument in f1. The audit covers 159 active source views; only
the three corrected root-base locations lacked the fourth argument. The
complete 3,040-byte root-base ELF remains byte-identical.
The earlier source and canonical receipts are preserved with the new ABI proof.

The frozen package is
`scratch/collision_pair_dispatch_80224CA8_20261020/`.
`scratch/collision_pair_integration_20261020/verify_production.py --linked`
checks the complete production object, native local identities, seven providers,
weak discard, original scalar tail and DOL hash. The standard and mapped ELF
outputs are identical. `ninja changes`, the source extent audit and all 66 tests
pass. Adjacent functions and data remain outside this partial source unit.
