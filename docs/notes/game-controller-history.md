# Controller input history

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-controller-history.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/controller_history.cpp` reconstructs two consecutive routines:

| Function | Original range | Bytes |
| --- | --- | ---: |
| `fn_80275BA4` | `80275BA4..80275C08` | 100 |
| `fn_80275C08` | `80275C08..80275EA8` | 672 |

The comparison routine walks backward through the 25-word history at `7C`
starting immediately before index `E4`, compares against the supplied sequence
in reverse, wraps a negative index by adding 25 and returns a signed-byte
Boolean. It returns 1 for a zero count. The loop counter declaration precedes
the ring index to reproduce the compiler's native register assignment.

The update routine requires flag40 at halfword20, then chooses the first
asserted input differing from wordE8 in this native priority order:
`8,4,1,2,1000,800,400,100,200,20,10`. It records the selected value at indexE4,
saves it to E8, increments/wraps E4 modulo25, and increments E0 when the new
E4 equals E0. The native E0 increment has no modulo operation; this behavior
is preserved. Flags exactly40 clear E8 when nonzero. The partial layout in
`controller_history_internal.h` records the observed offsets only.

Run `python3 scratch/game_controller_history/verify.py`. Standard optimized
GC/1.3.2 Game flags emit exactly 772 text bytes and the two original global
functions, all matching the protected DOL. The object has no relocations,
other allocated section, weak helper, data, BSS or owned padding. Every allocated
byte is checked. The original extabindex, `.ctors` and `.dtors` audit finds no
overlapping exception entry or table reference into either function. Candidate,
actual relocation and original metadata JSON preserve the isolated evidence.

This partial text split leaves neighboring controller functions and all
original data under existing ownership. Full DOL, native objdiff, source-extent
and regression acceptance remain the integrator's checks.
