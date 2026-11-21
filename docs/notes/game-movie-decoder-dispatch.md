# Movie decoder dispatch wrapper

`src/Game/movie_decoder_dispatch.cpp` owns the 36-byte wrapper at
`802959E0..80295A04`. It forwards its four inputs to the independently accepted
[five-argument frame decoder](game-movie-decoder-interframe.md) at `80295A04`, repeating the output pointer as
the fifth argument. No data is owned and no original class or TU boundary is
inferred from this partial split.

GC/1.2.5 matches the sole emitted function. The strict verifier applies the
one real branch relocation and checks the nonallocated compiler-metadata
reference separately. There are no helper bodies or comparison masks.

The linked ELF proof, byte-identical DOL, preserved prior matches and
source/header hashes, immutable baseline, protected input checks, source audits
and all 23 tests pass. One provisional native unit is added, without changing
code, function or data denominators. See
`scratch/movie_decoder_dispatch_checkpoint.json`.
