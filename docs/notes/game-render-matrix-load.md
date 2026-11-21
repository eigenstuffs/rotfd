# Render matrix loading

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-render-matrix-load.json`.

`src/Game/render_matrix_load.cpp` reconstructs `fn_80272EA0`, the 116 bytes at
`80272EA0..80272F14`. It copies the supplied 3-by-4 matrix into the receiver at
`2E0`, loads position matrix 0 and texture matrix 33, derives a local normal
matrix through `fn_800F6D6C`, loads normal matrix 0 and selects current matrix
0. The local matrix occupies 48 bytes.

GC/1.3.2 with standard optimized Game flags reproduces all 116 emitted bytes
after six actual call relocations. Run:

```
python3 scratch/game_render_matrix_load/verify.py
```

The complete emitted object has one global function and `.text` only, with no
extra weak functions, constants, data, BSS, constructor/destructor tables,
exception tables or owned padding. The original extabindex, `.ctors` and
`.dtors` audit finds no overlapping exception entry or startup/shutdown
reference. `candidate.json`, `actual_relocations.json` and
`original_metadata_audit.json` preserve the isolated evidence.

This partial text split leaves the adjacent aligned transpose loader,
neighboring engine functions and SDK routines under existing ownership. Full
DOL linking, native objdiff, source-extent auditing and regression checks
remain the integrator's acceptance step.
