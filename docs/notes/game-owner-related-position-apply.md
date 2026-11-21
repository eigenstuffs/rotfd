# Owner related position application

`src/Game/owner_related_position_apply.cpp` reconstructs `fn_8022DEB0`,
`0x8022DEB0..0x8022E158` (680 bytes), with standard GC 1.3.2 settings and
source `fp_contract on`. Every original byte and actual relocation matches
in the isolated production compilation; central integration is pending.

The indexed primary object comes from virtual `0x9C`. Owner handle `0x1A8`
identifies the related owner and its index-zero primary object. If the indexed
object's owner handle `0x0C` is valid and its target has flag `0x4`, that flag
is cleared through a second resolution of the same handle. A reference
accessor preserves the native repeated resolution and alias behavior. If the
related primary has flag `0x20`, inverse matrix pointer `0x128` is obtained
from the active context pool page and signed short index `0x12E`, refreshed
from matrix `0x124`, and the flag is cleared. The supplied point is transformed
through that inverse and passed to `fn_8023D100` on the indexed primary.
Named result scalars preserve the native floating point evaluation order;
multiplication and addition are ordinary contracted C++ expressions.

Run `python3 scratch/game_owner_related_position_apply/verify.py` to reproduce
the frozen proof: 680 retained/allocated text bytes and seven actual relocations.
There are no extra functions, data, BSS, or owned padding. Complete original
extabindex, constructor, and destructor tables contain no retained ownership.
This partial split does not recover the containing original translation unit.
