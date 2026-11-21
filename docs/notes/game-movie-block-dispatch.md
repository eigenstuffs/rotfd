# Movie motion-block dispatch

`src/Game/movie_block_dispatch.cpp` reconstructs `fn_802929DC`, the 236-byte
function at `802929DC..80292AC8`. For each of three planes it applies that
plane's horizontal and vertical shifts to the motion coordinates, retains
the low bits to select interpolation, and halves the resulting integer
coordinates. The source cursor starts at record word `18` plus that row and
column displacement. It dispatches each block offset from the plane's
four-word offset region at `18` to the accepted copy or interpolation helper,
using record word `14` as the destination base and the plane width as both
row strides. The number of blocks comes from plane byte `34`.

The two buffer words remain accessed through the output record's represented
unknown region; no unrelated layout declarations were changed. The source
keeps the block counter, horizontal/vertical flags, and offset pointer in
separate locals. Declaring the offset cursor after the flags reproduces the
native saved-register order. Halving the coordinate variables before forming
the source pointer reproduces the original expression schedule.

The compiler is GC/1.2.5 with ordinary movie flags plus `-opt noprop`.
Explicit input and output stride locals preserve the original shared load and
argument copies across the four dispatch branches.

Run `python3 scratch/movie_worker_continuation/verify_block_dispatch.py` for
the strict isolated check. The verifier accounts for every allocated section,
function symbol and relocation, resolves all four call relocations to the real
original function addresses, and compares every emitted byte to the normalized
DOL. The unit owns only the aligned-four `.text` range `802929DC..80292AC8`,
with one global function, no data, BSS, exceptions, padding or emitted helpers.
There is one ordinary relocation in nonallocated compiler metadata.

Integration should register the unit NonMatching with GC/1.2.5 movie flags
plus `-opt noprop`, set `fn_802929DC` explicitly global, validate, then promote.
The four external helper symbols at `80292AC8`, `80292B64`, `80292D00`, and
`80292EAC` also require global scope. The neighboring initializer and block
helpers are independently reconstructed units; original data remains outside
this partial text split.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
