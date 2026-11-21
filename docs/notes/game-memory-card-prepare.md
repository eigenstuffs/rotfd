# Memory-card preparation wrappers

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-memory-card-prepare.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/memory_card_prepare.cpp` reconstructs two consecutive routines:

| Function | Original range | Bytes |
| --- | --- | ---: |
| `fn_80278338` | `80278338..80278454` | 284 |
| `fn_80278454` | `80278454..8027857C` | 296 |

Both resume the worker, lock the owner mutex, call the preparation routine
with argument 0, retry `CARDProbeEx` while it returns -1, then unmount and
release any work area. When the resulting value is zero, the first unlocks
and returns 1 without suspending the worker; this native asymmetry is
preserved. Otherwise it prepares with argument 1, unmounts/releases again,
unlocks, suspends and returns that second result. A separate local for the
second result reproduces the native temporary register move.

The second wrapper has no return value. Its zero-result path unlocks and
suspends; the other path prepares with argument 1, calls the original capacity
check only when preparation returns zero, then unmounts/releases, unlocks and
suspends. Both reuse the frozen partial owner view.

Run `python3 scratch/game_memory_card_prepare/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all 580 emitted text bytes and the two original
global symbols after forty-four actual relocations. All allocated bytes are
verified, with no other allocated sections, weak helpers, initialized data,
BSS or owned padding. The original extabindex, `.ctors` and `.dtors` audit
finds no overlapping exception entry or table reference into the retained
range. Candidate, actual relocation and original metadata JSON preserve the
isolated evidence.

The original worker storage, release allocator, preparation/capacity routines,
SDK calls and neighboring functions remain externally owned. This partial text
split still requires the integrator's full DOL, native objdiff, source-extent
and regression checks.
