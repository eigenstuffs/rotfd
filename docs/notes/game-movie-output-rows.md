# Movie output block, row and plane wrappers

`src/Game/movie_output_rows.cpp` reconstructs the contiguous range
`80292648..80292950`, totaling 776 bytes:

| Function | Size | Operation |
| --- | ---: | --- |
| `fn_80292648` | 324 | Select a four-by-four output-block reconstruction mode and advance neighbor cursors. |
| `fn_8029278C` | 212 | Decode one row of blocks, retaining the current and following packed symbols. |
| `fn_80292860` | 240 | Decode a plane, clamping first and last row neighbor cursors at the boundaries. |

The dedicated header represents the 24-byte stack state: plane index, three
symbol-row cursors, next/current packed symbol pairs, and the last output
value. Mode zero reads the previous/next row symbols and following symbol,
substituting the current value for neighbors whose flags intersect `77`, and
calls the original smooth-block routine. Mode eight fills the block with the
current value. Other modes call the original specialized decoder with the
plane index. Those two decoder functions remain outside the new source split.

The row wrapper caches the advanced symbol pointer before its packed load,
matching the original single pointer update without an alias reload. The plane
wrapper caches the initial source pointer for all three cursor fields, then
orders its width, row advance, block count, and row count variables to preserve
the native allocation and schedule. The explicit four fill rows in mode eight
preserve the original full expansion and `20`-byte frame.

The compiler is GC/1.2.5 with ordinary movie flags plus `-opt noprop`. Run
`python3 scratch/movie_worker_continuation/verify_output_rows.py` for the strict
isolated check. It verifies every emitted allocated section, the three global
function symbols, and all seven actual call relocations (five internal and
two external), then compares every byte with the normalized original DOL.
There is only aligned-four `.text`: no data, BSS, exceptions, padding or emitted
helpers. Three ordinary function relocations appear in nonallocated compiler
metadata.

Integration owns only `.text 80292648..80292950`, alignment four. Register the
unit NonMatching with GC/1.2.5 movie flags plus `-opt noprop`, validate it, then
promote it. Set `fn_80292648`, `fn_8029278C`, `fn_80292860` explicitly global,
and also expose external dependencies `fn_80291B88` and `fn_80291D20` globally.
The surrounding movie functions and original data remain outside this partial
text split.

## Accepted integration

Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
