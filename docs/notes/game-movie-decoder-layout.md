# Movie decoder dimensions and workspace size

`src/Game/movie_decoder_layout.cpp` owns three functions totaling 184 bytes at
`80294FB4..8029506C`: a 32-byte table-initialization wrapper, a 36-byte dimension
copy, and a 116-byte workspace-size calculation. This partial text split owns
no data. Original library names and TU boundaries remain provisional.

The wrapper calls the independently accepted `fn_80290B88`, which constructs
[shared decoder tables](game-movie-decoder-tables.md) and does not consume
incoming arguments. The copy routine moves
two unsigned halfword dimensions and two byte mode fields from a six-byte
input prefix to decoder offsets `04`, `06`, `08` and `09`. The workspace pointer
at decoder offset `00` is preserved. The checked decoder view is a twelve-byte
prefix of the larger storage, not a recovered complete class.

The size routine computes quarter dimensions `w` and `h`. Mode value two halves
the corresponding quarter dimension for the chroma calculation, producing
`cw` and `ch`. The returned size is
`2 * ((w+2)*(h+2) + 2*((cw+2)*(ch+2))) + 0x6CD8`.
The caller uses this value for its workspace allocation. Multiplying the chroma
dimensions before doubling the product preserves the original instructions;
left-associating that multiplication produced a different probe.

GC/1.2.5n reproduces all 184 code bytes. The Game build registration explicitly
selects that compiler version without assigning the unit to the SDK category.
`scratch/game_movie_platform/verify_decoder_layout.py --production` applies the
one real branch relocation to the table initializer. Its three nonallocated
compiler-metadata references are checked separately and receive no code/data
credit. There are no emitted helper bodies or owned data.

The linked ELF proof, byte-identical DOL, unchanged prior matches and source/
header hashes, immutable baseline, source audits and all 23 tests pass. The
split adds two provisional units while preserving all byte/function
denominators. See `scratch/movie_decoder_layout_checkpoint.json`.
