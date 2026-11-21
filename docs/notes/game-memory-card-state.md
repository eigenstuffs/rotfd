# Memory-card state updates

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-memory-card-state.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/memory_card_state.cpp` reconstructs two consecutive routines:

| Function | Original range | Bytes |
| --- | --- | ---: |
| `fn_80276A6C` | `80276A6C..80276B48` | 220 |
| `fn_80276B48` | `80276B48..80276BF0` | 168 |

The first checks word `4D0`, calls the original preparation routine and retries
`CARDProbeEx` while it returns -1. It unmounts and releases work-area storage,
then writes `4CC=1, 4D0=0, 4D4=0` and logs the original message when the result
is zero. The second logs, prepares with argument 1, writes `4D0=1` when the
result differs from 1 (zero otherwise), clears `4CC` and `4D4`, then unmounts
and releases the work area. The partial owner layout is shared with the frozen
memory-card wrappers and query through `memory_card_owner_internal.h`.

Run `python3 scratch/game_memory_card_state/verify.py`. Standard GC/1.3.2 Game
flags emit exactly 388 bytes and the two original global functions. All bytes
match the protected original DOL after twenty-one actual relocations. The complete
allocated-section and symbol inventory contains only that text, with no weak
helpers, initialized data, BSS or owned padding. The original extabindex,
`.ctors` and `.dtors` audit finds no overlapping exception entry or table
reference into either function. The candidate, actual relocation and original
metadata JSON files preserve the isolated evidence.

This partial text split leaves the original messages at `802AF158` and
`802AF178`, manager at `801E9D24`, release allocator at `801EF5C8`, virtual
tables, SDK calls and neighboring owner functions under existing ownership.
Full DOL, native objdiff, source-extent and regression checks remain the
integrator's acceptance step.
