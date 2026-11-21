# Renderer rectangle controls

Three ordinary C++ entries match the contiguous `8027F178..8027F994`
text range: gradient rectangle `fn_8027F178` (744 bytes), textured rectangle
`fn_8027F460` (688 bytes), and solid strip `fn_8027F710` (644 bytes). The
complete 2,076-byte allocation and all 62 actual ELF relocation targets match.
This is an isolated production-source proof awaiting root integration and
full original-DOL acceptance.

The routines install the screen projection, configure direct GX attributes
and emit four FIFO vertices with negative input depth. The gradient rectangle
uses top and bottom RGBA colors; the solid rectangle emits a strip with one
RGBA color; the textured rectangle emits UVs and opaque RGB. Each restores
the original projection afterward. The textured routine additionally brackets
its draw with `GXSetZCompLoc(0)` and `GXSetZCompLoc(1)`.

A shared ordinary inline setup takes the TEV color scale as a parameter:
the gradient uses zero, while the solid strip uses one. This observed state
difference accounts for the single instruction mismatch in the first
gradient probe. All FIFO writes are ordinary volatile C++ stores. No inline
assembly, custom sections, fixed registers, object rewriting or aliases are
used. The dedicated header retains offset-based partial renderer views.

The Game compiler is `GC/1.3.2 -O4,p`, exceptions off, with
`-use_lmw_stmw on`. Its object emits only the three original global C
functions in `.text`; no extra helpers, literals, BSS, exception metadata,
constructors or destructors are emitted. Complete original extabindex, ctor
and dtor ranges contain no records for these entries. Existing scale
`lbl_8037B7C8` (255.0f) remains external. The shared conversion pool
`8037B7B8..8037B7C8` and all adjacent code/data remain original and uncredited.

The complete active ELF census finds the original defining text object and
the original renderer table referencing the three entries. A bytewise scan
of all original initialized data finds exactly three entry pointers and no
interior pointer; an all-original-text REL24/absolute branch scan finds no
external direct branch into this range. Current source/header references
are limited to this new source and its dedicated header. All original
function identities remain unchanged, so no consumer migration is needed.

Frozen source/header/object digests, complete allocation/symbol inventory,
actual relocations, active consumers, full original table and pointer/branch
audits are under `scratch/engine_renderer_rectangle_controls_20261011ha`.
`verify.py` recompiles production source and checks exact allocated bytes,
relocation targets, original ownership tables and all frozen hashes. Failed
private probes remain preserved without credit.
