# Size-pool allocation resize

`src/Game/platform_heap_resize.cpp` reconstructs `fn_8028FAF4` at
`8028FAF4..8028FD50` (604 bytes). If both old and new sizes exceed the heap's
limit at offset `1C`, it delegates directly to the arena resize routine.
Otherwise it allocates new storage, copies the smaller size, and returns the
old allocation to its arena or fixed-size pool.

The private header `include/Game/platform_heap_pools_internal.h` describes
only observed metadata. The heap caches a size-pool pointer at offset `04`
and keeps its pool list at `08`. A size pool has its next link at `00`, block
size at `08`, byte capacity at `0C`, record array at `10`, record count at
`14`, and selected record at `1C`. Each eight-byte record starts with a memory
pointer and has first-free/free-count bytes at `04`/`05`. Field and type names
are inferred. Original context storage remains outside this text split.

Release selects the matching size pool and searches backward and forward
from its selected record. The search compares the original pointer against
each record's capacity-times-block-size memory interval, updates the selected
record, and calls the original record release routine. It preserves the
native preconditions and lack of allocation-failure checks.

GC/1.3.2 with `-O4,p`, automatic inlining, exceptions disabled, and
`-use_lmw_stmw on` reproduces every instruction. Returning the found record
from the inline search preserves the native control flow. Declaring the
selected-record pointer before its byte span preserves the register lifetimes.
No assembly, barriers, instruction patches, or relocation masking is used.

`python3 scratch/game_heap_resize/verify.py` recompiles production source and
checks all allocated sections, the sole global function, all 14 actual
relocations, and every owned byte against the supported DOL. One nonallocated
compiler-metadata relocation is checked separately. No data, BSS, exception
record, helper, or padding is emitted. Full integration passes the original DOL SHA-1, native objdiff, source-extent
audit and regression comparison.
