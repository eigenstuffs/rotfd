# Render-state initializer

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-render-state-init.json`.

`src/Game/render_state_init.cpp` reconstructs `fn_80275280`, the 416 bytes at
`80275280..80275420`. It establishes the observed culling, clipping, depth,
texture-coordinate and color-write settings, then installs the five original
vertex-format layouts. Finally it clears the receiver's flags at `2D0` and
sets the mask at `2D2` to `FFFF`.

The source retains the explicit SDK call sequence and argument values. Byte
SDK booleans and fractional-bit arguments retain their native widths. No
local lookup table or generated command stream substitutes for the calls.

GC/1.3.2 with standard optimized Game flags reproduces all 416 emitted bytes
after seventeen actual call relocations. Run:

```
python3 scratch/game_render_state_init/verify.py
```

The complete emitted object contains one global function and `.text` only.
There are no extra weak functions, constants, data, BSS, startup/shutdown
tables, exception tables or owned padding. The protected-DOL original
extabindex, `.ctors` and `.dtors` audit finds no exception entry overlapping
this range and no startup/shutdown reference into it. `candidate.json`,
`actual_relocations.json` and `original_metadata_audit.json` preserve all
isolated checks.

This partial text split leaves the SDK functions and neighboring engine
routines under existing ownership. Full DOL linking, native objdiff,
Source-extent and regression acceptance has passed.
