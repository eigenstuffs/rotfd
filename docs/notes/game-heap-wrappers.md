# Game allocation shims

`src/Game/heap_wrappers.cpp` reconstructs `malloc`, `realloc`, and `free` at
`8001F2C0..8001F38C` (204 bytes). These game-specific shims use the original
allocator context at `lbl_8028F698`; the allocator implementation and context
storage remain outside this split.

Each user pointer follows a four-byte word containing the total allocation
size, including that word. Allocation requests four extra bytes, writes the
total, and returns the following address. Reallocation passes the header
address, recorded old size, and requested new total to `fn_8028FAF4`, then
updates the returned header. Release passes the header and its recorded size
to `fn_8028FD50`. The original functions add no null-pointer handling or
allocation-failure check, and the reconstruction preserves that behavior.

The post-increment header store preserves the native return-pointer lifetime.
Updating the reallocation parameter before the call reproduces its native
update-address load. These are ordinary sequenced C++ expressions; no assembly,
compiler barrier, or instruction patch is used.

GC/1.3.2 with `-O4,p`, automatic inlining and C++ exceptions enabled also
reproduces 24 exception-table bytes at `80005620..80005638` and 36 index bytes
at `80015F60..80015F84`. The compiler-local record names are recorded in the
versioned symbols. There is no other allocated data, helper, BSS, or padding.

`python3 scratch/game_malloc_continuation/verify.py` compiles production
source, audits every emitted allocated section and symbol, applies all 15
real relocations, and compares all 264 owned bytes against the supported DOL.
Three nonallocated compiler-metadata relocations are separately accounted
for. Full integration passes the original DOL hash, native objdiff, source
extent audit, and regression comparison. This is a partial text/exception
split, not a claim to the complete original allocator translation unit.
