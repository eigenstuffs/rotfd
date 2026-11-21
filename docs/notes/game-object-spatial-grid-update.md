# Object spatial grid update

`src/Game/object_spatial_grid_update.cpp` reconstructs `fn_8023F90C`,
`0x8023F90C..0x8023FBE4` (728 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

With a resource, it initializes a sphere from the external zero vector and
radius scalar, then obtains bounds from the object's parent virtual `0x3C`
for resource type `0x12`, or transforms resource bounds `0x0C` by object matrix
`0x124` otherwise. Type `0x10` updates the special grid at owner offset
`0x4078`. Other types update the primary grid at `0x34` unless resource flag
`0x10` is set, and the secondary grid at `0x80BC` unless object flag `0x8000`
or resource flag `0x20` is set. Without a resource, transformed default bounds
update only the secondary grid. Each update tests the existing index and cell,
erases a prior nonnegative index when needed, then inserts the object and
stores its new index. The primary/special index and cell are object offsets
`0xC4`/`0xF0`; secondary offsets are `0xE4`/`0x100`.

Grid member reference accessors preserve the native subobject pointer
lifetimes. The default sphere is a full-expression temporary when passed to
the transform helper, reproducing the native sphere stack slots. Grid fields
are opaque spans between the verified member offsets; this split does not
recover their internal implementation or complete containing owner layout.

Run `python3 scratch/game_object_spatial_grid_update/verify.py` to reproduce
the frozen proof: 728 retained/allocated text bytes and 22 actual relocations.
There are no extra functions, data, BSS, or owned padding. Complete original
extabindex, constructor, and destructor tables contain no retained ownership.
This partial split does not recover the containing original translation unit.
