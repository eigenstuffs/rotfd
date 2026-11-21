# Fixed-size pool record release

`src/Game/platform_heap_record_release.cpp` reconstructs `fn_8029091C` at
`8029091C..80290B50` (564 bytes). The function returns a slot to its record's
byte-indexed free list, increments the free count, and retains or compacts
empty backing records while keeping more than one record available.

A completely free selected record at the end is removed only when its
predecessor is also completely free. If the selected record is elsewhere and
the last record is completely free, the function removes the last record.
Otherwise it swaps the selected and last record's defined fields and updates
the current-record pointer. Resizing the metadata array delegates to the
original arena functions with the original diagnostic arguments and line
numbers. This split owns no allocator context, strings, or other functions.

The eight-byte private record has a memory pointer at zero and first-free and
free-count bytes at offsets four and five. Assignment copies these defined
fields; the native temporary copy preserves the full eight-byte record.
Two trailing bytes remain unknown. Field and type names describe observed
behavior and do not identify the original class.

GC/1.3.2 and standard Game `-O4,p`, automatic inlining, exceptions disabled
and `-use_lmw_stmw on` reproduce all instructions. The native shared load for
resetting both record cursors is expressed as ordinary chained assignment.
The count-minus-one expression is formed before indexing the eight-byte array.
No assembly, instruction patches or relocation masking is used.

`python3 scratch/game_heap_record_release/verify.py` audits the complete
production object, its sole global function, all 26 actual relocations and
all 564 bytes against the supported DOL. One nonallocated compiler-metadata
relocation is checked separately. No data, BSS, helper, exception record, or
padding is emitted. Full link acceptance is recorded after integration in the
continuation evidence.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
