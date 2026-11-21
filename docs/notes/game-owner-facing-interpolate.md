# Owner facing interpolation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_facing_interpolate.cpp` reconstructs `fn_8022993C`,
`0x8022993C..0x80229A78` (316 bytes), with standard GC 1.3.2 settings.

The function forwards the second input point to virtual position slot `0xBC`
with selector zero. It derives an interpolation fraction from the phase at
owner offset `0x1A8`, `fn_800AA53C`, and external period `lbl_8037B17C`.
When the fraction is below `lbl_8037B144`, `fn_8008D420` interpolates the
quaternions at `0x188` and `0x198`. The resulting 16-byte quaternion replaces
the first field and the selected primary object's quaternion at `0xC8`, then
the phase advances by the supplied delta. Virtual slot `0x9C` provides the
selected handle. The first and third point inputs are unused in this method.

The quaternion helper returns a 16-byte value through its ordinary hidden
output pointer, while the interpolation fraction occupies f1. Scalar member
assignment reproduces the observed four loads and stores for each copy.

`python3 scratch/game_owner_facing_interpolate/verify.py` recompiles frozen
production source, validates all seven actual relocations including external
small-data constants, and compares the complete 316-byte function to the
hash-verified original DOL. The sole allocated section is exactly 316 bytes
of text. There are no weak helpers, data, BSS, or owned padding. Complete
original extabindex, constructor, and destructor table scans contain no retained
ownership. This partial split does not recover the original engine translation
unit. Central integration and final DOL hash acceptance are parent-owned.
