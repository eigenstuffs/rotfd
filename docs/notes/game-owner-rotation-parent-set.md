# Owner rotation and parent setup

`src/Game/owner_rotation_parent_set.cpp` reconstructs `fn_80229CA4`,
`0x80229CA4..0x80229EE0` (572 bytes), using standard GC 1.3.2 settings.
The isolated production compilation matches every original byte and actual
relocation. Central integration and full-DOL acceptance are pending.

It forwards the supplied handle to the base parent setter, resolves virtual
slot `0x9C` at index zero, and copies that object's quaternion at `0xC8` into
both owner quaternions at `0x188` and `0x198`. It initializes phase `0x1A8`
with the external zero and then period scalar, preserving both stores. The
input object supplies retained handle `0x1C` for owner field `0x168`. If its
flag `0x800` is set, its parent `0x20` supplies the first array handle at `0x28`
for owner field `0x16C`. Each copy has the native two-zero handle lifetime.
The resolver returns a raw object pointer before the caller applies its
concrete layout, preserving native object/source register allocation.

Run `python3 scratch/game_owner_rotation_parent_set/verify.py` for the frozen
source proof: all 572 retained bytes, 15 actual relocations, and 836 allocated
text bytes are checked. Three unused weak destructor backups total 264 bytes;
their six relocations are inventoried, no retained reference targets them,
and they must be absent from the final ELF. Complete original extabindex,
constructor and destructor table scans show no retained ownership. No data,
BSS, or padding is owned. This partial text split leaves the containing
original translation unit outside its scope.
