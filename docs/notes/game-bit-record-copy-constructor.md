# Bit record copy constructor

`src/Game/bit_record_copy_constructor.cpp` and dedicated `include/Game/bit_record_native_lifetime.h` reconstruct original `fn_80225D44`, `.text` range `80225D44..80225F74` (560 bytes), as a genuine C++ copy constructor. Its emitted symbol is `__ct__19BitNativeCopyRecordFRC19BitNativeCopyRecord`.

The concrete 0xA8-byte record has vector/rotation fields, two 64-bit tokens, four layered owned handles and scalar fields. Initializer-list construction preserves first-field ordering, native handle constructor aliases and reference retention. The first handle has one external zero-initializing layer and the later three have two. Ordinary float component copy constructors preserve every original load and store.

Run `python3 scratch/game_bit_record_copy_constructor/verify.py`. Standard GC/1.3.2 flags verify all 560 retained bytes and ten real relocation sites/kinds/symbols/addends/targets directly against the protected DOL, exact symbol extent, and all emitted allocations/relocations. Source and header hashes are frozen. The original extabindex, `.ctors` and `.dtors` audit finds no ownership or references into this range.

Only `.text` is emitted: 560 retained bytes and four unreferenced weak inline destructor backups totaling 352 bytes (92/88/88/84). All bytes and relocation identities are audited; retained code references none. These helpers must be absent from the final ELF and earn no progress. No data/BSS/padding is emitted.

Central integration renamed the provisional symbol to its native C++ spelling
and migrated the declaration in `engine_array_growth.h` and the call in
`engine_array_append_168.c`. All three shared-header consumers passed isolated
and production allocated-byte/extent/actual-relocation checks with unchanged
machine code. The earlier source, header, manifests and SHA256 history are
preserved in `scratch/continuation_20261010/record-copy-fixed-vectors-caller-history/`.
The final DOL hash, no-regression report, generated progress and all 26 tests
pass. This partial text split leaves other original record functions and data
external. No linker alias or thunk was introduced.
