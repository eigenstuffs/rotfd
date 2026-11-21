# Game arena allocator

The retained group at `0x801EF5F4..0x801EFC24` implements word copying, block release/coalescing, resizing, allocation, checked allocation, a deleting-destructor ABI entry, and heap initialization. Names and field names are inferred from the original instructions and `decomp/all_functions.c`; the original source/class/translation-unit names are not known. This reconstruction preserves observed behavior, including error paths and fixed alignment.

`src/Game/allocator.c` currently covers six verified methods at `0x801EF6E0..0x801EFC24`, totaling 1,348 code bytes. It also owns the five original diagnostic literals at `0x802AD3D0..0x802AD480`: 175 emitted `.rodata` bytes plus one final alignment byte. The checked-allocation message has three integer fields, so its call supplies requested size, alignment, and available heap bytes. The ABI's allocation alignment argument is present, but this executable always aligns allocations to 32 bytes.

The private `allocator_internal.h` describes the recovered twelve-byte allocated-block header, sixteen-byte free-block header, and 44-byte heap manager. The manager contains allocated/free list sentinels, arena bounds, usable limit, and four counters. Its existing storage at `0x801EF5C8` lies in the original `.text` segment and remains unchanged. The already-verified backing hooks in `src/Game/memory_hooks.c` remain separate.

GC/1.3.2 with `-O4,p -inline deferred -use_lmw_stmw on` reproduces these six methods exactly. The explicit header-size variable preserves the allocation loop's original register lifetimes. Expressing a block's payload as `block + 1` preserves the original header-relative address arithmetic. No instruction patches or assembly substitutes are used.

Run `python3 scratch/game_allocator/verify_core.py` to compile and apply all 31 relocations, then compare every allocated section with the original DOL. The verifier checks the protected original SHA-1 without modifying the reference. The six-method group and separate copy helper also passed full-DOL and native objdiff integration. Release/coalescing remains outside the matching-source claim.

`src/Game/allocator_copy.c` separately matches the 28-byte helper at `0x801EF5F4..0x801EF610` with GC/1.3.2 `-O2,p -schedule on`. It copies four-byte words using an increasing byte offset, including the original do/while behavior. Level4 converts this loop to pointer increments and differs from the executable. This independently configured source portion does not assert an original translation-unit boundary. `python3 scratch/game_allocator_copy/verify.py` verifies its complete text; it owns no data or relocations.

Call sites establish the checked-allocation ABI as `(Heap *, int requested, const char *label, const char *filename, int line, int alignment)`. The latter four arguments are unused by this executable; preserving their typed parameters leaves all 1,348 text bytes and all literals exactly matching in the isolated check.

The remaining release/coalescing implementation is preserved in `src/Game/allocator_free.c` as **nonmatching**. Its strict verifier intentionally fails on three bytes at `0x801EF619..0x801EF61C`: the compiler emits `lwz r4,0(r6)` instead of `lwz r4,-12(r4)`. Both addresses identify the same header, and the remaining 204 bytes match, but this is not an accepted binary match. Enabling peephole optimization produces the original load address and changes the order of two instruction pairs instead. The candidate manifest records this unresolved result; the original assembly remains the linked fallback. The final attempts included separate payload-prefix types, source load/store forms, initializer orders, inline accessors, compiler versions, and scheduling settings. No volatile accesses, instruction patches, or masked comparisons were introduced.

A later revisit applied the logger parser's const-accessor insight to allocation metadata. A const payload getter emits the payload-relative size load, but its scheduling and register lifetimes differ. Const views, ordinary read-order permutations, small metadata helpers, and C/C++ compiler modes did not improve the three-byte candidate. Those experiments remain under `scratch/game_allocator_free/`; they are not credited as matching source.

## Source ownership correction (2026-09-08)

The current emitted `.rodata` extent is `0x802AD3D0..0x802AD47F`, 175 bytes.
The following byte through `0x802AD480` now has a separate NonMatching original
padding owner. This supersedes any padding-inclusive extent above; all six
functions and 1,348 code bytes remain exact in the full matching DOL. See the
[section-extent audit](source-section-padding.md).
