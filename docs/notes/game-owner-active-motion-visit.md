# Owner active motion visit

`src/Game/owner_active_motion_visit.cpp` reconstructs `fn_8022A560`,
`0x8022A560..0x8022A830` (720 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

The function caches the owner count at `0x2C` and visits entries whose flag
array `0x40` lacks bit `0x2` and whose corresponding bit in word array `0x4C`
is set. Handle array `0x34` supplies each owner, and virtual `0x9C` at index
zero supplies its primary object. Position comes from virtual `0xB0`. Virtual
`0x44` prepares two motion vectors, using external scalar `lbl_8037B180` when
owner flag `0x800000000000` is set and the input delta otherwise. Their sum is
formed through ordinary point addition. The function then calls virtual slots
`0x48`, `0x4C`, and `0x40`, refreshes the primary object through `fn_8023DE28`,
and calls virtual slots `0x58` and `0x50`. Each virtual callback uses index zero.
The loop's explicit byte offset mirrors both original parallel four-byte
arrays, while the point copy constructor preserves the returned position's
native temporary and local lifetime.

Run `python3 scratch/game_owner_active_motion_visit/verify.py` to reproduce the
frozen proof: 720 retained/allocated text bytes and four actual relocations.
There are no extra functions, data, BSS, or owned padding. Complete original
extabindex, constructor, and destructor tables contain no retained ownership.
This partial split does not recover the containing original translation unit.
