# Callback list facade continuation

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-callback-list-facades.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

The 24 new `src/Game/callback_lists_*.c` partial text fragments reconstruct
**24 complete functions and 2,860 text bytes**. Their canonical isolated
handoff is `scratch/game_callback_list_facades/integration.json`.

Each forwarding wrapper invokes original `fn_8025ED38` for its observed
sequence of one to six global lists. Each paired query invokes original
`fn_8025E70C` in the same list order and returns the first result other than
minus one, falling back to minus one after the final query. Opaque parameters
preserve the native argument registers. Global list pointers remain external.
The source expands the observed calls explicitly; it does not substitute a
loop or copy original machine instructions.

The pairs start at `8025348C`, `80254A3C`, `80255A34`, `80256590`,
`80258B0C`, `8025963C`, `80259B54`, `80259DFC`, `8025A9F0`, `8025B30C`,
`8025BD74`, and `8025CDC0`. Each function is a separate exact text fragment,
without claiming a complete original translation unit. Function names, bounds,
and call targets come from the original symbol inventory and instruction
analysis. Actual source compilation supplies the matching evidence.

`python3 scratch/game_callback_list_facades/verify.py` recompiles all frozen
production files and verifies all allocated bytes, all complete global
function extents, and **164 actual relocations**. All bytes match after
applying real target addresses. No data, padding, weak functions or exception
sections are emitted. Full original-table ownership audit, DOL hash and
regression checks remain the central integration gate before progress credit.
