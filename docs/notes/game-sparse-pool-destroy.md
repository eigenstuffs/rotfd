# Sparse handle pool destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/sparse_pool_destroy.cpp` reconstructs `fn_8026BD48`,
`0x8026BD48..0x8026BE78` (304 bytes), with standard GC 1.3.2 settings.
The isolated production compilation matches every original byte and actual
relocation. Central integration and the complete executable checks are pending.

The function writes the pool's native table pointer at `0x24`, then destroys
its storage base. The base scans each occupied index below `limit` at `0x1C`,
destroys the two-layer handle in its raw storage, clears the occupancy bit and
decrements the live count at `0x20`. Automatic C++ member destruction calls
the bitset destructor, followed by raw storage release using capacity times
four. A positive signed 16-bit deleting argument releases the pool itself.
The raw storage does not perform a second element destruction pass.

Ordinary base and member destruction reproduce the native redundant null
checks. The word reference accessor preserves the native occupancy test's
registers. An unsigned element index in the handle destruction expression
prevents reuse of the earlier signed byte-offset expression; this closes the
remaining register allocation and increment-order differences at the original
304-byte extent. No assembly or symbol aliases are used.

Run `python3 scratch/game_sparse_pool_destroy/verify.py` for the frozen proof:
304 retained text bytes, 10 actual relocations, and every allocated emission
accounted. The object emits no unused weak functions, owned data, BSS, or
padding. The unchanged `include/Game/bitset_internal.h` is inventoried by hash.
The verifier checks the original DOL SHA1 and all entries in the complete
extabindex, constructor and destructor tables; none refers into this function.
This is a partial text split of the containing original translation unit.
