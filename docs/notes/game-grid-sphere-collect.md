# Grid sphere result collection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/grid_sphere_collect.cpp` reconstructs `fn_80268918`,
`0x80268918..0x80268B80` (616 bytes), using ordinary C++ and standard
GC 1.3.2 settings. The isolated production compilation matches every original
byte after applying all five actual relocations. Central integration and
full executable acceptance are pending.

The function clears the output record pool, queries the spatial grid using
the input sphere's X/Z bounds, then visits candidate pointers at `0x80FC`.
Candidates must have flag `0x40000` and lack `0x10000`. Generation-checked
handles at candidate offsets `0x1C` and `0x20` resolve the receiver and peer
object. The receiver's virtual method at table offset `0x44` appends to a
local pool of `0x28`-byte records. Two unsigned 64-bit masks are forwarded;
mask bit `0x0002000000000000` selects the final pool-combine operation.
The return value reports whether the output pool is nonempty.

The fixed record pool uses raw aligned storage and an explicit count at
`0x2800`. Its unsigned indexing operator preserves the original byte-offset
placement-construction loop when increasing the count. Shrinking and local
pool cleanup retain the original loops over empty record destructors. A
reference to the peer's manager entry reproduces the native generation-load
and 64-bit stack-argument scheduling. No assembly or linker aliases are used.

Run `python3 scratch/game_grid_sphere_collect/verify.py` for the frozen proof.
It audits every allocated section and symbol, the complete actual relocation
identity table, original DOL SHA1, and complete original extabindex,
constructor and destructor tables. No original table entry refers into the
retained range, and no data, BSS or alignment padding belongs to this partial
text split.

The compiler emits 756 text bytes: 616 retained bytes and a unique,
unreferenced weak `SphereCollectPool` destructor of 140 bytes. Its bytes and
single delete relocation are inventoried separately. The retained function
has no references to it; central acceptance must verify that it is absent
from the final ELF. No shared headers or metadata are changed.
