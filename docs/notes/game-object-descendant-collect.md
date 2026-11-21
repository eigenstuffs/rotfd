# Object descendant collection

`src/Game/object_descendant_collect.cpp` reconstructs `fn_8023F744`,
`0x8023F744..0x8023F90C` (456 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

The function resolves the first link at object offset `0x10`, then walks
successive links at `0x18` until null. Each linked object's handle at `0x04`
is copied and retained through a one-zero temporary, then appended to the
output array using placement construction and a second retained copy. Array
capacity grows by 32 through the original heap allocate/resize/free APIs.
The temporary is cleaned up before advancing to the next link. Explicit copy
constructors preserve both native handle lifetimes; array storage relocation
uses the original raw heap resize operation.

Run `python3 scratch/game_object_descendant_collect/verify.py` to reproduce
the frozen proof: 456 retained bytes, 16 actual relocations, and all 628
allocated text bytes. Two unused weak destructor backups total 172 bytes;
their four relocations are inventoried, no retained reference targets them,
and they must be absent from the final ELF. Complete original extabindex,
constructor, and destructor tables show no retained ownership. No data, BSS,
or padding is owned. This partial split leaves the containing original
translation unit outside its scope.
