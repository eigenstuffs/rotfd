# Grid X-boundary clip and outcode

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/grid_x_clip.cpp` reconstructs `fn_802665F4`,
`0x802665F4..0x80266758` (356 bytes), using ordinary C++ and standard
GC 1.3.2 settings. The isolated production object matches every original
byte after its four actual SDA relocations. Central integration and full
executable acceptance are pending.

The input outcode selects an X boundary. Bit 1 interpolates the start point
against X=0; otherwise bit 2 interpolates it against the maximum X at receiver
offset `0x78`. The function then recomputes the six-bit outcode from all three
coordinates, using extents at `0x78..0x80` and the existing small-data lower
threshold at `0x8037B604` (approximately `0.000001`). The zero boundary comes
from existing `0x8037B608`.

Constructing the endpoint difference before calculating the fraction
reproduces the native floating-point evaluation and fused multiply-add
sequence. The read-only constant declarations permit the original threshold
load to precede the outcode store. No assembly, aliases or new literals are
used.

Run `python3 scratch/game_grid_x_clip/verify.py` for the frozen proof.
The object emits exactly 356 allocated text bytes, with no unused helpers,
data, BSS or padding. The verifier checks the original DOL SHA1, all actual
relocation identities and complete extabindex, constructor and destructor
tables; no original table refers into the range. No shared headers or
metadata are changed. This is a partial text split of its original unit.
