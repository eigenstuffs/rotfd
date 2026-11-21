# Later engine scalar operations

The `src/Game/leaf_late_*.c` fragments recover observed scalar behavior in
the original engine range `801E0000..80290000`. Every fragment owns one
contiguous text range and retains the versioned provisional symbols. The
fragments do not claim complete class or translation-unit recovery.

The first group contains 133 functions and 752 bytes in 65 fragments:
78 empty operations, 17 integer constant returns, 29 global scalar reads or
writes, four subobject address accessors, and five scalar field accessors.
All 29 real SDA relocations resolve to their versioned data symbols. These
fragments are integrated and pass the original DOL hash and native objdiff.

A second group contains 17 functions and 248 bytes in 13 fragments. It adds
float accumulation/copying, fixed-stride record access, signed packed-handle
index/generation queries, flag setting/clearing, paired scalar resets, and a
global value/ready-flag update. The 24-bit signed index is expressed as a
native bitfield, which reproduces the compiler's rotate-mask/sign-extension
sequence. Uncertain fields use explicit byte offsets. The original mode,
record identities and semantics beyond these operations remain provisional.

Both groups compile with the existing GC/1.3.2 Game flags. Strict verifiers
audit the complete text extent, function symbols and every actual relocation,
and reject unexpected owned data, BSS or exception sections. Compiler-only
nonallocated metadata is excluded from DOL ownership. No instruction or
relocation bits are masked. There is no data or padding credit.

The sources, integration manifests, rejected earlier expressions and
verification scripts are preserved under `scratch/game_leaf_late_continuation/`
and `scratch/game_leaf_late_extended/`. Adjacent larger routines and original
shared data retain their existing ownership. Full integration checks remain
required for any new fragment added to these groups.
