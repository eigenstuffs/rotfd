# Fallback disc-screen text renderer investigation

The original `fn_8028E8E8` occupies 432 bytes at `8028E8E8..8028EA98`.
It remains original code and has no source credit. Private ordinary-C++ probes
are under `scratch/game_disc_text/`; none is registered as Matching.

The physical arguments are integer x/y/depth and a character pointer. The
routine clears the GX vertex descriptors, selects direct position and texture
coordinates, and configures both attributes as signed 16-bit values. It scans
runs of signed characters in the inclusive range 32 through 127. A delimiter
ends the current run; a newline advances y by eight and starts another run.
Any other delimiter ends the function. Each nonempty run begins one GX quad
batch with four vertices per character.

The x origin and depth are converted to signed halfwords before scanning. A
run's y origin is converted separately, and each glyph covers an eight by
eight rectangle. Glyph index is character minus 32. Texture coordinates use
sixteen units per cell: column is index modulo eight and row is index divided
by eight. The shared word at `80378178` is added to both coordinates. Position
and texture halfwords are interleaved through the volatile GX FIFO at
`CC008000`. Rendering uses a separate run-start pointer; the scanner advances
past the delimiter before drawing.

The first private probe was 420 bytes. Keeping the run start distinct from a
local render cursor restored four bytes; indexing the run as `text[i]` restored
the final eight bytes, including the native induction counter and derived
pointer increments. The current private body is 432 bytes. Its relocated
comparison still differs in 37 instruction words, predominantly register
allocation; it is not a byte match. Signed character, temporary types,
declaration order and FIFO parameter types have been tested. Sources, raw
comparison logs and variant results are preserved for further investigation.
No comparison masks, object patches, assembly or probe score earns credit.

Further register hints, swapped initial declarations, character-index-derived
positions, C versus C++ compilation and inline modes `auto`, `auto,deferred`,
`on` and `on,noauto` preserve the same best 37-word difference. These negative
results are recorded in the private variant JSON files; no probe was promoted.
The font atlas, texture object and five projection constants are now supplied
by the independently verified [font data unit](game-platform-disc-font.md).

All 120 argument orders for an ordinary inline run-drawing helper preserve the
same best 37-word difference. `scratch/game_disc_text/run_helper_results.json`
records these unsuccessful probes; the renderer remains original code.
