# Callback indexed matrix lookup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80257220` reconstructs the complete 280-byte function at
`0x80257220..0x80257338`. It resolves the owner's handle at `0x64`, reads
the index remap through the global records object, resolves the first
object's handle at `0x1F0`, and resolves the remapped entry in its handle
array at `0x28`. A valid final object supplies the matrix at `0x30` to
the original copy routine and returns one; an invalid final handle returns
zero.

Each lookup preserves the signed 24-bit index and signed eight-bit
generation comparison against the manager's original entry layout. Reading
the remap before the second lookup reproduces the native instruction
scheduling. Earlier expression-order probes remain private in scratch.

The partial declarations describe only the accessed fields. The manager,
index records, matrix-copy routine, original data and neighboring methods
remain external. No extra functions, allocated data or padding are emitted.
`scratch/game_callback_indexed_matrix/verify.py` checks every allocated byte,
the exact function extent and five actual relocations without masking.
Central acceptance also requires the complete exception/startup table audit,
original DOL hash, no baseline regressions, source extents, generated progress
verification and the repository tests.
