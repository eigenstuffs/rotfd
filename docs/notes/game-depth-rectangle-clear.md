# Depth rectangle clear

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-depth-rectangle-clear.json`.

`src/Game/depth_rectangle_clear.cpp` reconstructs `fn_80273448`, the 244 bytes
at `80273448..8027353C`. It enables depth writes with comparison mode 7, then
writes `00FFFFFF` across the requested rectangle through the `C8400000`
memory-mapped depth aperture. Rows have a 1,024-word pitch. The receiver
argument is unused.

The nested loops and volatile word writes reproduce the compiler's eight-word
unrolling. Declaring the running row before the cached column and row bounds
recovers the native register allocation. The pointer, dimensions and stride
remain ordinary C++ operations; there is no inline assembly.

GC/1.3.2 with standard optimized Game flags reproduces all 244 emitted bytes
after the actual `GXPokeZMode` call relocation. Run:

```
python3 scratch/game_depth_rectangle_clear/verify.py
```

The complete emitted object contains one global function and `.text` only,
with no weak functions, constants, data, BSS, startup/shutdown tables,
exception tables or owned padding. The protected-DOL original extabindex,
`.ctors` and `.dtors` audit reports no entry covering or targeting the retained
range. `candidate.json`, `actual_relocations.json` and
`original_metadata_audit.json` preserve all checks.

This partial text split leaves neighboring routines and original metadata in
existing ownership. Full DOL linking, native objdiff, Source-extent and regression acceptance has passed.
