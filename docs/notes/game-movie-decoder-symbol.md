# Movie Huffman-symbol reader

`src/Game/movie_decoder_symbol.cpp` reconstructs the global 112-byte
`fn_80291774` at `80291774..802917E4`. The reader record's buffer points to
a tree whose root is at offset `04` and whose two 512-entry child arrays begin
at offset `08`. An internal symbol is at least 256. Each input bit selects
one child array, and the symbol selects the entry. Once the symbol is below
256, the first child array supplies the decoded integer value.

`include/Game/movie_decoder_symbol.h` declares that inferred 0x1008-byte tree
layout and verifies its size and child-array offset. The two-dimensional view
is needed to reproduce the original independently scaled bit and symbol
offsets. Flattening the lookup into a single integer index changes its
instruction order. The local inline bit helper retains the original
shift-before-position-store behavior, as in the separate single-bit reader.

GC/1.2.5 with the standard movie flags plus `-opt noprop` matches all 112
bytes. With propagation enabled, the tree pointer and bit position exchange
registers, leaving nine instruction-word differences. `-opt nocse` also
matches, but the unit uses the narrower propagation setting.

`python3 scratch/movie_worker_continuation/verify_symbol.py` compiles the
production source, checks the sole global function and all emitted allocated
sections, then compares all 112 bytes with the verified original DOL. There
are no allocated relocations, data, BSS, helper functions, padding or exception
sections. The single nonallocated compiler metadata reference is separately
accounted for. The candidate manifest is
`scratch/movie_worker_continuation/movie_decoder_symbol_candidate.json`.

This partial split owns only the symbol-reader text. The adjacent bit reader
has separate source ownership; the byte reader, plane unpacker, tree builder
and remaining decoder functions remain outside this split. Full integration
passes the original DOL SHA-1, native objdiff, source-extent audit and regression
comparison.
