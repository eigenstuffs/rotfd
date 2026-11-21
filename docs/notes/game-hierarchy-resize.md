# Hierarchy handle-array resizing

The two adjacent methods at `0x802030C4..0x8020349C` are specializations of the
same array resize algorithm. They operate on the verified three-field layout:
signed count, signed capacity, and an element pointer. The storage helper uses
the existing allocator at `0x8028F698` and its realloc, allocate, and free methods.

`src/Game/hierarchy_resize7.cpp` recovers the 500-byte method at `0x802030C4`;
`hierarchy_resize5.cpp` recovers the 484-byte method at `0x802032B8`. The private
`hierarchy_resize_internal.h` expresses seven or five observed handle type
layers over the native base handle. Those depths reproduce the repeated
constructor initialization and destructor null guards visible in the original
code, using ordinary placement construction and explicit C++ destruction.
Original template and class names remain unknown.

Growth reallocates when the requested count exceeds capacity or capacity
retention is disabled, then constructs the newly exposed elements. Shrinkage
destroys elements in reverse order and either retains capacity or resizes the
allocation. Equal counts leave the array unchanged. A single signed loop
variable is declared before the growth/shrinkage branches. Separate loop-local
variables change seven register bytes in each method; the shared variable
reproduces every original instruction.

`scratch/game_hierarchy_resize/verify.py` compiles both with GC/1.3.2, `-O4,p`,
`-inline auto`, and `-use_lmw_stmw on`. All 984 retained code bytes and all 40
retained ELF relocations match the SHA-1-checked original DOL. Neither source
owns data, BSS, exception records, or padding. Existing shared source and
headers were not modified.

Each source also emits unused weak destructors for its intermediate template
layers: 564 bytes in the seven-layer unit and 360 bytes in the five-layer unit.
The verifier checks every helper's symbol extent and binding, all 20 helper
relocations combined, and the absence of retained references into those bodies.
Ordinary linker dead stripping removes them; they receive no progress credit.
Separate source fragments preserve original function order without placing
these unreferenced bodies between the two retained methods.

Both sources are integrated. The candidate records
`config/GSQE78/candidates/game_hierarchy_resize7.json` and
`game_hierarchy_resize5.json` record successful full-DOL and native objdiff
verification, and their recorded source hashes match the current files.
`build/GSQE78/report.json` reports 100% code matching for
`main/Game/hierarchy_resize7` (500 bytes, one function) and
`main/Game/hierarchy_resize5` (484 bytes, one function), with no owned data.
The rebuilt and untouched original DOL both have SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
