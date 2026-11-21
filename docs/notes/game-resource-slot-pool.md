# Resource slot-pool operations

`src/Game/resource_slot_pool.cpp` owns `801E5C1C..801E5FDC`, three
functions and 960 code bytes, with no data ownership. Names are provisional.

- `fn_801E5C1C` (348 bytes) searches the selected record's handles by resolved
  object identity, clears that slot's occupancy bit, and resets the input
  handle. It does not destroy the stored handle.
- `fn_801E5D78` (300 bytes) finds a free slot, marks it occupied, assigns its
  stored handle to the output and returns one. With no free slot, it resets
  the output and returns zero.
- `fn_801E5EA4` (312 bytes) decrements the record reference count. At zero,
  it destroys an occupied record, clears its manager occupancy bit, and
  decrements the live-record count.

The record is 36 bytes: name word, reference count, 16-byte bitset, and a
12-byte array of layered four-byte handles. The manager's 36-byte prefix
contains its record array, occupancy bitset, slot limit and live count.
Array accessors return references; native cleanup destroys the handles in
ascending order, frees their allocation, then invokes the existing native
bitset destructor. Partial layouts and allocator declarations reuse the
verified reset and curve-array interfaces. Later manager fields are outside
this partial declaration.

`scratch/game_resource_slot_pool/verify.py --production` verifies all retained
bytes with 22 actual relocations. All 1,132 allocated text bytes are accounted
for: 960 retained bytes plus 172 bytes of unused weak destructors. The latter
are absent from the final ELF and receive no credit. The final DOL is identical
to the immutable reference; all 652 source units remain exact. Source/object/
header hashes, extent and assembly audits, generated progress, and 23 tests
pass. Baseline data is unchanged. The documented fallback/native-padding
warnings in `ninja changes` remain; no source matches regressed.

See `scratch/resource_slot_pool_checkpoint.json` and the strict/link proofs.
The [larger acquisition/setup routine](game-resource-slot-acquire.md),
[pool growth](game-resource-slot-growth.md), and
[native slot-resource destructor](game-resource-slot-destructor.md) now also
have verified splits. The pool destructor remains original code. The adjacent
[callback dispatcher](game-resource-slot-callbacks.md) now has a separate
verified source split.
This is a partial text split, not a complete recovered original TU.
