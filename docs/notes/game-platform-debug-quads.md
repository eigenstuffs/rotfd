# Platform flagged-quad renderer — uncredited

`fn_80283EB8`, `.text 0x80283EB8..0x8028437C`, has **1,220 native
bytes**. It remains original code in the matching build. Private C++ probes
and assembly are preserved in `scratch/game_platform_debug_quads/`.

The owner stores unsigned-short per-item flags at `2C`, count at `30`, a
28-byte item array at `38`, and a display-list triple at `3C/40/44`.
Each item contains a three-float position, a three-float rotation-direction
argument and radius at `18`. The input resource node must have flag `80000`;
items with flag `8` are skipped and flag `20` is required. The renderer copies
the resource matrix, updates/copies the transform inverse, transforms each
position, derives scale from the squared length of the first matrix column,
and multiplies that scale by item radius.

The native scale estimate uses `frsqrte` followed directly by `fres`; the current
compiler's correctly typed ordinary intrinsic expression inserts a rounding
instruction between them. This also affects earlier scalar-math research;
no assembly was added to force a match. The routine calls `fn_801F27BC` with
unit Y and the item's second vector, uses the returned quaternion to build a
rotation matrix, fills its translated position, combines it with the inverse,
and updates draw state. It binds a copied handle at offset `280` of the global
asset owner at `14C`, sets state flag `2000`, emits a four-vertex quad at height
`0.01f` with color word `127` and 0/1 texture coordinates, closes/stores the
list, and submits it at zero sort depth.

`direct_handle.cpp` emits **1,208 bytes**, with **300 differing instruction
positions** and no extra allocated code or data. It is not a match. Earlier
variants emit an unused 84-byte weak handle destructor, also uncredited.
Remaining issues include intrinsic rounding, scalar/column math emission,
quaternion copying, matrix stack placement, handle-temporary address lifetime,
register allocation and repeated native scalar loads across GX writes.
A separate exact draw-dispatch wrapper at `0x80284D80` is documented in
[its unit note](game-platform-draw-dispatch.md); it does not credit this routine
or the following 2,564-byte renderer at `0x8028437C`.
