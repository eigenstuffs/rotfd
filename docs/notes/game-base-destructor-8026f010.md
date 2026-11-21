# Deleting destructor at 8026F010

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/base_destructor_8026f010.cpp` reconstructs `fn_8026F010`, 104 bytes at
`8026F010..8026F078`. For a nonnull receiver it installs original table
`lbl_802ED3B0` into offset08, calls `fn_8024C8CC` with deletion disabled,
then releases the receiver through the original allocator when the signed low
half of the deletion flag is positive. It returns the receiver. The shared
`base_destructor_internal.h` records only the observed table offset; no new
virtual interface, table or complete class layout is claimed.

Run `python3 scratch/game_base_destructor_8026f010/verify.py`. Standard optimized GC/1.3.2
Game flags reproduce all 104 emitted bytes after six actual relocations.
The strict inventory requires the original global function and `.text` only,
without weak helpers, data, BSS or owned padding. Every allocated byte and
relocation matches the protected DOL. The original extabindex, `.ctors` and
`.dtors` audit finds no overlapping exception entry or table reference into
this range. The candidate, actual relocation and original metadata JSON files
preserve the isolated evidence.

The original table, base destructor, allocator and neighboring routines
remain externally owned. Full DOL, native objdiff, source-extent and regression
acceptance remain the integrator's checks for this partial text split.
