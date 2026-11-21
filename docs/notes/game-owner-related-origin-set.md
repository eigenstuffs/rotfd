# Related owner origin setter

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_related_origin_set.cpp` reconstructs `fn_80224038`,
`0x80224038..0x80224294` (604 bytes), with standard GC 1.3.2 settings.

The function releases and replaces owner handle `0x1F8`, retaining its input.
If the new handle is valid, it resolves the related owner and obtains its
primary handle through virtual slot `0x9C` with index zero. It temporarily
retains the primary object's parent handle at `0x20`, resolves that parent,
and releases the temporary before obtaining the first handle in the parent's
array at `0x28`. A second retained temporary protects that handle while
`fn_8024BFB4` fills a 4x4 matrix for selector six. The matrix translation at
`0x30`, `0x34`, and `0x38` becomes the owner's origin at `0x208`. An invalid
related handle sets that origin to the external zero vector.

The parent-handle reference accessor preserves the native alias lifetime
across construction. Named y, z, and x matrix components reproduce the native
float loads while preserving ordinary scalar semantics. The first copied
handle is a full-expression temporary and the second has lexical lifetime;
this accounts for their separate stack slots and cleanup order.

`python3 scratch/game_owner_related_origin_set/verify.py` recompiles frozen
production source, checks all 604 retained bytes and 14 actual relocations,
and accounts for the only allocated section: 868 bytes of text. Three unused
weak destructor backups total 264 bytes and have six inventoried relocations;
they must be absent from the final ELF. Retained code does not reference them.
Complete original extabindex, constructor, and destructor table scans show no
owned records. Initialized data, BSS, and owned alignment padding are zero.
The original containing engine translation unit remains incomplete. Central
integration and final DOL hash acceptance are parent-owned.
