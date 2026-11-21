# Owner bounds reduction

`src/Game/owner_bounds_reduce.cpp` reconstructs `fn_802276C8`,
`0x802276C8..0x802279A0` (728 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

Virtual `0x90` finds the first active index. An empty traversal returns zero.
The first primary object's resource handle at `0x1C` supplies a sphere at
resource offset `0x0C`. Each active index from virtual `0x94` supplies a
primary object through virtual `0x9C`; its matrix `0x124` transforms that
same resource sphere. The first transformed sphere initializes the output;
subsequent spheres are merged with it through `fn_801F0A20`. If owner flag
`0x2000` is set and the primary object's parent `0x20` accepts it through
virtual `0x38`, the parent's virtual `0x3C` sphere is also transformed and
merged. The completed traversal returns one. Ordinary structure-return
calls and scalar sphere assignment preserve all native stack temporaries.

Run `python3 scratch/game_owner_bounds_reduce/verify.py` to reproduce the
frozen proof: 728 retained/allocated text bytes and seven actual relocations.
There are no extra functions, data, BSS, or owned padding. Complete original
extabindex, constructor, and destructor tables contain no retained ownership.
This partial split does not recover the containing original translation unit.
