# Mesh weight transform research

`fn_802802C8` (`802802C8..802808D0`, 1,544 bytes) remains private and
uncredited. Fresh ordinary probes are preserved under
`scratch/engine_mesh_weight_transform_20261011hb`; no production source,
central registration or existing consumer was changed. The function has no
records in the complete original extabindex/ctor/dtor ranges.

The original resolves a part handle, selects a 20-byte related record, then
visits 16-byte groups. It finds the input part index among 28-byte links,
resolves two nodes, refreshes a flagged cached inverse matrix, multiplies the
two matrices, and applies linked vertex weights into the external scratch
buffer. The first count of weighted vertices assigns output; the remaining
weights accumulate. Their source coordinates are 12-byte vectors and their
weight records are eight bytes (index and float). Concrete part/node manager
views establish the observed field offsets; no runtime behavior is claimed
from the diagnostic probes alone.

The original retains three 64-byte matrix stack allocations at 0x20, 0x60
and 0xA0. Direct initialization plus a by-value inline application helper
emits two; separate matrix declaration/assignment plus a by-value helper
emits four; assignment plus a const-reference helper emits three. These
ordinary lifetime forms are preserved separately. The latter probe is 1,532
bytes but differs substantially in register allocation, lookup reloads,
vector scheduling and spills. Naming scalar transform results reduces it
to 1,516 bytes and gives the original 0x190 frame, while substantial
instruction differences remain. Explicit vector member assignments remove
original temporary stores and change loop unrolling. Increasing the inline
size limit permits an otherwise out-of-line ordinary application helper;
it does not establish an exact compiler configuration.

All probe sources, compiler logs, complete emitted allocations, actual
relocation diagnostics and original assembly are retained. None is a
matching-source claim. The shared global, matrix pool and scratch BSS remain
external and wholly uncredited. Further attempts should begin from genuine
matrix/vector class structure rather than repeating these bounded forms.
