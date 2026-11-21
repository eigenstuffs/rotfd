# Fallback disc font and projection data

`src/Game/platform_disc_font.cpp` reconstructs the fallback font's 3,072 I4
pixel bytes at `802F1700..802F2300`, the 32-byte GX texture-object BSS at
`80373120..80373140`, and five float constants at `8037B968..8037B97C`
(20 bytes). This partial data-only split adds 3,124 data bytes and no code or
functions. Its original TU boundary remains provisional.

The display routine selects a 64 by 96 I4 texture. Every nibble is either zero
or fifteen; the native image consists of 96 consecutive 8 by 8 GX tiles.
The text routine maps character minus 32 to eight columns and twelve rows.
The reconstructed source retains eight bit-pattern rows per glyph, annotated
with character codes 32 through 127. `GLYPH`, `I4_ROW` and `I4_PAIR` expand the
editable rows into the original 32-byte I4 tile layout at compile time. The
font image is writable data as in the original executable. The semantic row
re-encoding is verified independently against the emitted native bytes.
A private decoded atlas preview is saved at `scratch/game_disc_font/font_atlas.png`.

The GX object is zero-initialized 32-byte BSS; its original SDK initialization
runs in the matched display routine. Projection constants are zero, 1/64,
1/96, one and -100, with exact target single-precision encodings. The separate
conversion bias, trademark text, shared coordinate/status storage and renderer
retain their existing ownership. No declarations add credit for those bytes.

GC/1.3.2 emits exactly 3,092 initialized bytes and 32 BSS bytes, with no code,
relocations, helpers or source-owned padding. The four original zero alignment
bytes at `8037B97C..8037B980` have explicit ownership in
`original/platform_disc_projection_padding.s`; the raw objdiff report counts
them as unclassified, unmatched data. They cannot disappear from the data
denominator or be credited to the font source.

`scratch/game_disc_font/verify.py --production` validates the whole emitted
unit, each object identity/extent, the I4 row expansion and the original BSS
range. `scratch/platform_disc_font_link_proof.py` verifies every owned symbol
in the linked ELF and the full byte-identical DOL. The original hash and
baseline, all earlier source/header hashes, all 739 source matches, extent
and assembly audits, and all 23 tooling tests pass. See
`scratch/platform_disc_font_checkpoint.json`. The native code/function/data
denominators are unchanged; provisional build units increase by three.
