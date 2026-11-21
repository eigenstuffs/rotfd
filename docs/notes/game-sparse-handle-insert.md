# Sparse handle insert

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/sparse_handle_insert.cpp` reconstructs `fn_8026B908`,
`0x8026B908..0x8026BC50` (840 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending. The first ordinary C++ probe was exact.

The pool's count/capacity/data occupy `0/4/8`; its occupancy word array occupies
`0xC/0x10/0x14`, followed by bit count/limit/live counts at `0x18/0x1C/0x20`.
It searches for a clear occupancy bit and increments the live count. When no
free slot exists, it grows handle capacity by eight if necessary, placement
constructs a retained one-zero handle copy, extends the bit count and word
array, marks the old limit occupied, and returns/increments that limit.
Otherwise it releases the free slot's old handle, copies/retains the input,
marks the slot occupied, and returns its index. The inline scalar word-array
resize has empty construction/destruction loops, preserving the native count
loops without initializing new words. Those observed semantics are retained.

Run `python3 scratch/game_sparse_handle_insert/verify.py` to reproduce the
frozen proof: 840 retained bytes and 36 actual relocations. All 924 allocated
text bytes are accounted, including one unused 84-byte weak destructor backup
with two inventoried relocations. It has no retained reference and must be
absent from the final ELF. Original DOL SHA1 and complete original
extabindex/constructor/destructor table bounds are verified. No data, BSS,
padding, or original table ownership is retained.
This is a partial text split of its containing original translation unit.
