# Embedded font glyph pixels

The accepted `src/Game/font_glyph_pixels_802EDCD0.c` and shared declaration
`include/Game/font_glyph_pixels.h` reconstruct the complete original GLOBAL
array at `802EDCD0..802F1490`: 14,272 initialized data bytes. The source uses
eight editable row masks per glyph; a constant-expression macro expands each
mask to its eight byte-sized zero/one pixels. It emits no code, literal pool,
constructors, helper symbols or actual relocations.

The original constructor `fn_8027BB64` loads the base at `8027BD34/8027BD40`,
reads eight rows of eight bytes, advances the source by 64 bytes, and iterates
223 times. Its destination glyph index is the loop index plus 32, giving codes
32 through 254. The constructor packs the pixels into four-bit texture indices;
that original code is still outside this data-only source unit. Complete native
reference and initialized-data-pointer scans find no other direct address
consumer or interior pointer. The GLOBAL symbol retains its original 14,272-byte
extent and writable `.data` placement.

`scratch/continuation_20261012_b/font_pixels/freeze.py` reproduces the normal
GC/1.3.2 `-O4,p` object and verifies all allocations, symbols, actual relocations
and relocated bytes. The final `build-python-font-promote.log` passes the
unchanged DOL SHA-1; `ninja changes`, original address coverage, source extents
and all 66 tests pass. The shared native proof verifies the production object
and final linked GLOBAL identity. No alignment outside the compiler allocation
is claimed.
