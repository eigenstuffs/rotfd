# Memory-card owner wrappers

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-memory-card-owner-ops.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/memory_card_owner_ops.cpp` reconstructs two consecutive routines:

| Function | Original range | Bytes |
| --- | --- | ---: |
| `fn_802780BC` | `802780BC..80278138` | 124 |
| `fn_80278138` | `80278138..802781AC` | 116 |

The probe wrapper resumes the original worker thread, locks the owner mutex,
converts `CARDProbe` to a signed byte, unlocks, clears word `4D4` when that byte
is zero, suspends the thread and returns the byte. The name wrapper compares
the incoming string with the buffer at `378`, copies only when different under
the mutex, saves word `370`, wakes the queue at `350` and returns the saved word.
The copy preserves the native unchecked `strcpy` call.

`include/Game/memory_card_owner_internal.h` describes a partial owner view.
The queue is at `350`, mutex at `358`, status at `370`, name at `378`, sector
size at `3B8`, memory size at `3BC`, channel at `3C0`, work-area pointer at
`408`, free-byte count at `40C` and status words at `4CC`, `4D0`, `4D4`.
Names describe observed use; the structure is not a complete recovered class.

Run `python3 scratch/game_memory_card_owner_ops/verify.py`. GC/1.3.2 with the
standard Game flags emits exactly 240 text bytes and the two original global
symbols. Every byte matches the protected original DOL after all fourteen
actual relocations. The object has no other allocated sections, weak helpers,
initialized data, BSS or padding. The original extabindex, constructor and
destructor table audit finds no overlapping exception entry or table reference
into this range. The three JSON evidence files record bytes, relocations and
original table hashes.

This is a partial text split. The worker-thread storage at `80341038`, SDK
functions and neighboring owner routines remain externally owned. Full DOL,
objdiff, source-extent and regression acceptance belong to integration.
