# Render sorted-record links at 80271BD8

`src/Game/render_sorted_record_links_80271BD8.cpp` reproduces all 412 bytes at `80271BD8..80271D74` as ordinary C++. GC 1.3.2, Gekko, O4,p, C++ exceptions off, RTTI off and use_lmw_stmw on produce only 412 bytes of text aligned to four, with one actual REL24 to the already accepted `fn_80271D74`. A fresh compile passes the strict whole-allocated verifier. No helper, literal, data, BSS, exception metadata, ctor, weak code or padding is emitted.

The function initializes a local array of 512 unsigned-short indices, calls the existing index quicksort, links each sorted A8-byte record to its predecessor, sets the first record's next field to FFFF, and returns the final sorted index. The native count is at owner+3B0, record pointer at +3AC, and the unsigned-short next field at record+2. The existing accepted text-display dispatcher already declares its C return type as unsigned short.

The preserved older private candidate had 30 register and scheduling differences. An ordinary cursor class whose dereference and indexing operators return values places the descending cursor in native r6 and the remaining count in native r7, fixing 25 instruction words. An ordinary inline last-index accessor with pointer and count parameters reproduces the final sentinel and epilogue schedule, closing the last five words. These helpers are fully inlined; the only positive emitted symbol is the original GLOBAL function.

The fresh census in `audit_render_sorted_record_links.py` scans 3,109,410 aligned and unaligned original byte positions across all initialized DOL segments. There are no initialized pointers into the owned text extent and no absolute-address materializations. Two original direct branches call the exact entry; no external branch enters its interior. No extabindex, ctor or dtor record refers to it. The stable active-input audit covers 6,205 inputs and 133,510 actual RELAs; source and all central/object hashes remain stable. All existing code, record storage, and the following quicksort retain their original ownership and ABI.

Frozen source, object, fresh object and complete manifest are in `scratch/game_frontier_20261012_b/render_sorted_record_links_80271BD8.cpp`, `.o`, `_fresh.o` and `.owned.json`. Integration is root-owned and remains subject to the unchanged full DOL hash and match-regression checks.

Production acceptance: this routine is now Matching. The unchanged full DOL
SHA-1, baseline comparison, exact native allocations/symbols/actual RELAs,
complete original section coverage, source extents and all 66 tests pass.
Evidence: `scratch/continuation_20261012_b/build-screen-property-sort-promote.log`
and `changes-screen-property-sort-promote.log`.
