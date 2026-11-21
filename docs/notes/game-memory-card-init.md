# Memory-card owner initializer

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-memory-card-init.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/memory_card_init.cpp` reconstructs `fn_80279044`, 188 bytes at
`80279044..80279100`. It installs the original table at `802EDC48`, writes
words `00=2, 04=0`, then installs the table at `802EDB80`. It clears the observed
work-area, channel, capacity and status words in their native order, zeros
96 bytes at `428`, copies the original default label to `488`, clears the
first bytes at `3C4`, `3E4`, `378` and returns the receiver. Both original
table stores remain emitted. No new virtual interface or table is generated.

The shared `memory_card_init_internal.h` records the partial field layout
used here and by the label wrapper. Its 0x4D8 size is the extent of this view,
not a claim about complete class ownership.

Run `python3 scratch/game_memory_card_init/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all 188 emitted text bytes after eight actual
relocations. The strict object inventory has one original global function,
no other allocated sections, weak helpers, owned data, BSS or padding. All
allocated bytes and relocations match the protected original DOL. The original
extabindex, constructor and destructor table audit finds no overlapping
exception entry or reference into the retained range. Candidate, relocation
and original metadata JSON preserve the isolated verification evidence.

The original two tables, default string at `802AF32C`, `memset`, `strcpy` and
neighboring routines remain externally owned. Full DOL, native objdiff,
source-extent and regression acceptance remain the integrator's checks for
this partial text split.
