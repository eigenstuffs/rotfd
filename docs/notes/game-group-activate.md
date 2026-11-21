# Hierarchy group activation

`src/Game/group_activate.cpp` reconstructs `fn_801FEF6C` at `0x801FEF6C..0x801FF18C`: one 544-byte retained function. Strict isolated verification passes with all ten retained relocations applied. Full-DOL and native objdiff verification pass as recorded below. The original complete translation-unit and class names are unknown.

The method activates the indexed hierarchy group. It computes the remaining capacity out of four and the total assigned width by scanning valid handles whose group offset is nonnegative. If the selected group is already assigned, its width is added back to capacity and subtracted from the assigned total. The new start is four minus the available capacity. The game is resized to start plus the group's width, then each assigned slot receives a retained copy of the group's owner handle. Finally it sets bit 1 of the game's flags at offset `0x234` and calls `fn_8020279C(group, start, width)` to distribute the range.

The source preserves the original unchecked indexed resolution and subsequent dereference. The two scans explicitly retain the manager pointer before their loops. An inline const width accessor reproduces the original width/owner-reference register allocation; direct field access left nine differing instructions. An inline const reference accessor for the owner preserves its address across the real native handle constructor. The scoped wrapper uses the native default constructor, one inherited zero store, a packed handle copy and reference increment; the by-value call is followed by native destruction with flag zero.

## Complete emitted-section proof

Run `python3 scratch/game_group_state/verify.py`. The verifier checks the protected original DOL SHA-1, applies actual ELF relocations and compares all retained bytes without masks. The compiler is GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`; all flags and source/object hashes are recorded in `config/GSQE78/candidates/game-group-activate.json`.

The compiler emits only `.text`: 716 allocated bytes. The retained routine owns the first 544. Two unreferenced weak destructor bodies occupy object offsets `0x220..0x278` (88 bytes) and `0x278..0x2CC` (84 bytes), with four relocations between them. The verifier checks both weak bindings, every extent, complete contiguous coverage and the absence of retained references to discarded code. Ordinary dead stripping excludes their 172 bytes from matching-source credit. No data, BSS, exception tables or padding are claimed.

The neighboring deactivation method remains a separately documented, unregistered near-match. It is not included in this exact candidate.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 544/544 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
