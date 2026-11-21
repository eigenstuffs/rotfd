# Decoder workspace initialization

`src/Game/movie_decoder_workspace.cpp` owns `8029506C..802954D0`: one function
of 1,124 bytes with no owned data. It stores the workspace pointer, initializes
the three 0x38-byte plane records and sets up working buffers and their borders.

Plane zero uses modes one/one; the other two use the decoder's byte modes.
The unsigned width-greater-than-or-equal-to-height flag is stored at workspace
offset `6260`. It selects halfword values `46`/`26` at `625C`/`625E`, reversing
those values for taller images. Equal dimensions take the first branch.

Six fixed buffer starts are `A8`, `10B0`, `20B8`, `30C0`, `40C8` and `50D0`.
The pointer slots initialized to them are retained by verified byte offsets;
the complete original workspace class remains unconfirmed. Each plane's
dynamic buffer begins after the `6CD8`-byte fixed prefix and spans twice its
padded-width times padded-height product. Plane offset `00` stores its beginning;
offset `04` stores the first interior element, one row and two bytes later.

Four ordinary loops write big-endian `7FFF` border values: across the first
row, backwards across the last row, and down the two side columns between
them. Decrementing counts reproduce the original compiler unrolling. Interior
buffer contents and unrelated workspace fields are preserved.

GC/1.2.5 matches every instruction. GC/1.2.5n changes two epilogue instructions;
GC/1.3 variants change the body and frame. The strict production verifier
applies all three real branches to the accepted record initializer and checks
the sole emitted function. One nonallocated compiler-metadata reference is
checked separately. There are no helpers, comparison masks or owned data.

The linked ELF proof, byte-identical DOL, unchanged baseline and protected
inputs, all previous source/header hashes and matches, source audits and all
23 tests pass. This partial text split adds one provisional native unit while
preserving code, function and data denominators. See
`scratch/movie_decoder_workspace_checkpoint.json`.
