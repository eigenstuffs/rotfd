# Grid sphere candidate traversal

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/grid_sphere_visit.cpp` reconstructs `fn_80268794`,
`0x80268794..0x80268918` (388 bytes), with standard GC 1.3.2 settings.
The isolated production compilation matches every original byte and actual
relocation. Central integration and full executable checks are pending.

The function queries the grid with the X/Z bounds of the input sphere, then
visits the resulting candidate pointer array at `0x80FC`. It excludes objects
with flag `0x10000`, and requires `0x40000` unless the optional byte flag is
set. A generation-checked handle at candidate offset `0x1C` resolves the
receiver for a virtual query at table offset `0x50`. Results occupy `0x48`
bytes each; the function advances the destination by the accumulated count
and passes the remaining capacity. A zero capacity requests an early stop
after the first valid virtual call. The return is the integer boolean of the
accumulated hit count.

The virtual query forwards two unsigned 64-bit masks. Their register pairs
and stack word order explain the initial probe's reversed parameter registers.
A handle reference reproduces the native resolver register reuse. The grid
is a nested object at `0x80BC`; accessing it through a reference getter closes
the last three address-calculation differences. Its candidate array has 4096
pointer slots, ending at `0xC0FC`, before the later reverse-lookup fields.
No assembly or aliases are used.

Run `python3 scratch/game_grid_sphere_visit/verify.py` for the frozen proof:
388 retained bytes and three actual relocations, with all allocated emissions
accounted. No unused weak functions, data, BSS, padding or shared headers are
emitted. The verifier checks the original DOL SHA1 and complete extabindex,
constructor and destructor tables; none refers into this function. This is a
partial text split of its original translation unit.
