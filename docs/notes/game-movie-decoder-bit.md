# Movie single-bit reader

`src/Game/movie_decoder_bit.cpp` reconstructs the global 64-byte
`fn_80291734` at `80291734..80291774`. It consumes one bit, most significant
first, from the previously recovered `MovieDecoderBitReader` record. A
negative position advances the input word pointer and reloads the cached word
with position 31. The function then decrements the position and returns the
selected bit. It owns no data or remaining decoder functions.

The ordinary direct-return probe produced a 72-byte function with GC/1.2.5,
or a 64-byte function with four scheduling/register differences under newer
compilers. An inline helper with an output reference preserves the original
shift-before-position-store sequence under GC/1.2.5. Keeping the mask within
that helper and explicitly narrowing the public return to `unsigned char`
eliminates the extra return-register copy and matches every instruction.
No assembly, object patches or relocation masking are used.

`python3 scratch/movie_worker_continuation/verify_bit.py` compiles the
production source with the standard GC/1.2.5 movie flags and verifies its
single global function, all emitted allocated sections and all 64 original
DOL bytes. There are no allocated relocations, helper functions, data, BSS,
padding or exception sections. The single nonallocated `.mwcats.text`
metadata reference is accounted for separately. The candidate manifest is
`scratch/movie_worker_continuation/movie_decoder_bit_candidate.json`.

The adjacent [112-byte tree-symbol reader](game-movie-decoder-symbol.md)
also matches in its separate source split. The 708-byte plane unpacker at
`80291334` remains private research with register-allocation and initialization
scheduling differences; it earns no progress.

This bit-reader split is integrated and passes the original DOL SHA-1,
native objdiff, source-extent audit and regression comparison.
