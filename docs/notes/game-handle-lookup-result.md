# Handle lookup by record key

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/handle_lookup_result.cpp` reconstructs `fn_8026420C`, original `.text`
range `8026420C..802642C4` (184 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The routine scans the handle array descriptor at offset 0xC, resolves each handle through the original routine, and compares the resolved record key against the requested key. A match constructs the returned four-byte value from the record member at offset 4 and adds its original manager reference; a miss constructs a zero value. The partial value type supplies only the construction/copy behavior observed in this function and explicitly calls the original native initializer. Its user-defined copy constructor uses the native hidden-result-pointer ABI, without introducing an unobserved destructor or weak helper. Declaring the result pointer before the loop reproduces the native reuse of the offset register.

Run `python3 scratch/game_handle_lookup_result/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 184 emitted text bytes, the original global symbol and
6 actual relocations. Every allocated byte and exact relocation
site, kind, symbol and addend is verified against the protected original DOL.
No other allocated sections, weak helpers, initialized data, BSS or padding are
emitted. Candidate, actual-relocation and original-metadata JSON preserve the
source/header/object hashes, dependencies and evidence.

The original extabindex, `.ctors` and `.dtors` audit finds no overlapping
exception entry or table reference into the retained range. Referenced original
tables, element cleanup, allocators, native initializer, manager/global storage
and neighboring functions remain externally owned. This partial text-only
split does not claim the complete original translation unit. The integrator
must run the complete DOL hash, native objdiff, source-extent and regression
checks. No special flags, new symbol names or owned-data ranges are required.
