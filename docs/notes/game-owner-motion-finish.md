# Owner motion finish

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_motion_finish.cpp` reconstructs `fn_8021E9F8` at
`0x8021E9F8..0x8021EBA4` (428 bytes) with standard GC 1.3.2 settings.

The function clears velocity at owner offset `0x150`, copies it to movement
at `0x144`, and forwards a default two-layer handle to `fn_8021EBA4`.
It dispatches event `0x2B` when any flag in mask `0x7E000000` is set and event
`0x36` when flag `0x800000000` is set, resolving owner handle `0x24` for each
event and passing the external scalar `lbl_8037B074`. It then clears both
masks from the 64-bit flags at offset `0x30`.

`python3 scratch/game_owner_motion_finish/verify.py` recompiles the frozen
source and compares all 428 retained bytes after checking all 13 actual
relocations, including the small-data relocation. The only allocated section
is 600 bytes of text: 428 retained bytes and two unreferenced destructor backup
functions totaling 172 bytes. The backups and their four relocations are fully
inventoried and must be absent from the final ELF. They are ordinary generated
C++ lifetime helpers; retained code does not reference them.

The complete original extabindex, constructor, and destructor tables contain
no entries belonging to the retained range. No data, BSS, or alignment padding
belongs to this text split. Other functions and data of the original engine
translation unit remain outside this partial split. Central integration and
final DOL hash acceptance are parent-owned.
