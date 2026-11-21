# Second movie frame decoder

`src/Game/movie_decoder_interframe.cpp` owns the 1,448-byte function at
`80295A04..80295FAC`. It initializes the interframe reader state and forwards
the decoder and three image pointers to the still-original `fn_80294B78`.
This partial unit owns no data or complete original workspace class.

Six header bytes populate workspace fields `6CD0..6CD5` in the verified order
`1, 0, 2, 4, 3, 5`. Seventeen segment offsets begin at packet offset `08`;
their payload starts at `4C`. Compared with the first frame decoder, the final
four readers begin at `620C`, `6220`, `6248` and `6234`. The preceding thirteen
reader offsets and initialization behavior agree with the first decoder.

Six working buffers receive the 256 sentinel and an initial decoded token or
zero for an empty segment. Their reader offsets are `618C`, `61B4`, `60D8`,
`6150`, `620C` and `6248`. The additional readers use mode/scale one/zero and
zero/zero, respectively. The scale byte also initializes the same workspace
limits as the first decoder. Decoding and image reconstruction still use the
original callee; no recovered algorithm is claimed for it here.

GC/1.2.5 matches all emitted text. The strict verifier applies seven real
branches and twelve small-data relocations, checks the sole function and checks
one nonallocated metadata reference separately. No helpers or owned data are
emitted. The header has compile-time packet size and segment-offset checks.

The linked ELF proof, byte-identical DOL, unchanged protected inputs/baseline,
all previous source/header hashes and matches, source audits and all 23 tests
pass. One provisional unit is added and all byte/function denominators remain
unchanged. See `scratch/movie_decoder_interframe_checkpoint.json`.
