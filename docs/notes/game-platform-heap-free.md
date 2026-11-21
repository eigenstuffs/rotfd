# Size-pool allocation release

`src/Game/platform_heap_free.cpp` reconstructs `fn_8028FD50` at
`8028FD50..8028FF24` (468 bytes). Large allocations go to the arena release
routine. Smaller allocations use the cached size pool when its block size
matches, or search the heap's linked size pools. The pool searches in both
directions through its records, updates its selected record, and calls the
original record-release routine.

The observed metadata and inline search are shared with the
[resize reconstruction](game-platform-heap-resize.md) through the new private
`include/Game/platform_heap_pools_internal.h`. No previously matched header
was changed. This text-only fragment leaves the allocator context, pool
creation, record release, allocation body, and original literals outside it.

GC/1.3.2 with the usual `-O4,p`, automatic inlining and exceptions disabled
matches with `-opt noprop`. This compiler option preserves the original
cached-pool and search-span register allocation. It applies to this fragment;
the independently verified resize fragment keeps its standard optimization
settings. All source is ordinary C++.

`python3 scratch/game_heap_resize/verify_free.py` verifies the complete emitted
object: 468 text bytes, one global function, five actual relocations, and one
nonallocated compiler-metadata relocation. There is no data, BSS, exception
record, helper, or padding. Full integration passes the original DOL SHA-1, native objdiff, source-extent
audit and regression comparison.
