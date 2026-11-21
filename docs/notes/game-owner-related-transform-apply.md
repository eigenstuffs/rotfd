# Owner related transform application

`src/Game/owner_related_transform_apply.cpp` reconstructs `fn_8022DC80`,
`0x8022DC80..0x8022DEB0` (560 bytes), with standard GC 1.3.2 settings and
source `fp_contract on`. Every original byte and actual relocation matches
in the isolated production compilation; central integration is pending.

The indexed primary object comes from virtual `0x9C`. Owner handle `0x1A8`
identifies the related owner and its index-zero primary object. If flag `0x40`
is set on that object, its basis at `0x54` is refreshed from rotation at `0x30`
and the flag is cleared. The basis is converted to a quaternion and composed
with the input quaternion. If flag `0x20` is set, inverse matrix pointer
`0x128` is obtained from the active context pool page and signed short index
`0x12E`, refreshed from matrix `0x124`, and the flag is cleared. The input
point is transformed through that inverse and forwarded with the quaternion
to `fn_8023D120` on the indexed primary object. Named result scalars preserve
the native floating point evaluation order; multiplication and addition are
ordinary contracted C++ expressions.

Run `python3 scratch/game_owner_related_transform_apply/verify.py` to reproduce
the frozen proof: 560 retained/allocated text bytes and nine actual relocations.
There are no extra functions, data, BSS, or owned padding. Complete original
extabindex, constructor, and destructor tables contain no retained ownership.
This partial split does not recover the containing original translation unit.
