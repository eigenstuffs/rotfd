# Hierarchy group deactivation

`src/Game/group_deactivate.cpp` recovers `fn_801FEE10` at
`0x801FEE10..0x801FEF6C`: 348 code bytes, one function, and no owned data.
Strict isolated verification passes; complete-build acceptance is recorded below.

The method resolves the indexed group, calls `fn_80202464`, resets the game
size to one, and assigns an empty native handle to slot zero. It then scans
the collection and reactivates every valid group whose assigned offset is
nonnegative. The incoming index and first resolved pointer have no additional
bounds or null guard. The reconstructed source preserves those original checks.

The default argument handle calls the native constructor, performs two zero
stores through ordinary inherited constructors, and is passed by value. Native
cleanup uses flag zero. The source has no manual destructor flags or assembly.

The earlier probe had the correct control flow but different manager-lookup
scheduling and nonvolatile register assignments. A const accessor returning the
entry's signed generation byte, promoted into an ordinary `int` local before
comparison with the handle generation, reproduces both lookups and the loop.
The struct remains the established 16-byte manager record; no layout changes
were needed. These source details recover the compiler's output without
claiming the original class or accessor names.

Run `python3 scratch/game_group_deactivate_refine/verify.py`. It compiles the
production source with GC/1.3.2 and standard `-O4,p -inline auto` Gekko flags,
checks the protected DOL SHA-1, verifies the strong function identity and full
emitted-section coverage, applies all ten actual retained relocations, and
compares every retained byte. Two unreferenced weak destructors account for the
other 172 allocated text bytes and four native-destructor/operator-delete
relocations. They are checked explicitly, dead stripped normally, and receive
no source credit. No data, BSS, exception records, or alignment tails are owned.

The manifest is `config/GSQE78/candidates/game-group-deactivate.json`.
Probe history is in `scratch/game_group_deactivate_refine/`; the older
[near-match record](game-group-deactivate-near.md) remains reproducible.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 348/348 code bytes and one exact function,
with zero owned data. The source-section extent guard and generated progress
checks pass. The old near probe remains historical evidence and receives no
separate credit; the documented baseline accounting corrections are preserved.
