# Bicubic grid sampling

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/bicubic_grid_sample_801D9304.cpp` reconstructs the 1,632-byte sampler at `801D9304..801D9964` with ordinary C++. Isolated production and fresh strict recompilation match every allocated byte and all16 actual relocations; full-game integration is pending.

The routine builds a sixteen-vector control grid through the existing native vector constructor and record-grid loader. It samples the four columns and rows to produce a point and the two parametric tangents. Explicit output parameters and ordinary local vectors reproduce the original stack lifetimes and final float stores; a value-return declaration instead emitted word copies.

Only text is owned. The interpolation functions, constructor, array runtime and original caller keep their current identities. Complete original EH/startup tables, active actual relocations and initialized pointer words were audited; no data, BSS, literal, helper or metadata ownership transfers. Frozen evidence and exact integration instructions are under `scratch/game_bicubic_grid_sample_801d9304` and `scratch/game_engine_batch267`.
