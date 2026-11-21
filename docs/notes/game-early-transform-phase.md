# Early transform phase updates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two isolated ordinary C++ routines match complete original allocations using GC1.3.2 with `-O4,s -Cpp_exceptions on -fp_contract on`:

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_80074560 | 216 | 8000CA2C..8000CA34 | 800193EC..800193F8 | 8 |
| fn_80074708 | 200 | 8000CA44..8000CA4C | 80019410..8001941C | 5 |

The first forms the original quaternion from the half-angle trig calls, reduces its angle with a contracted multiply/subtract, and dispatches the node transform virtual. The second computes the vertical sinusoidal offset, writes the output vector in the original x/y/z order, dispatches the node position virtual, advances its phase with a mutable local angular rate, and subtracts the original external period while above it. All original float symbols remain external; no literal allocations are introduced.

Sources are `src/Game/early_transform_phase_80074560.cpp` and `early_transform_phase_80074708.cpp`, with dedicated `include/Game/early_transform_phase_views.h`. Neither unit emits weak helpers or data beyond its original EH/index. Actual local compiler EH symbols, all allocated sections and all real PowerPC/SDA relocations are verified against the normalized original DOL. Complete original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 scans prove each retained EH owner and the absence of ctors/dtors references.

Frozen manifests: `scratch/game_engine_batch101/manifest-list.json`. Each per-function strict verifier recompiles production source and compares all relocated owned bytes. This is isolated evidence awaiting central original-DOL acceptance; it does not claim a complete original translation unit. No aliases, native identity migrations, BSS, padding or owned external data are proposed.

The adjacent combined updater fn800748B4 (324 bytes) remains private and uncredited. Ordinary vector storage recovered its entire first portion; eight or nine floating-register differences persist in the two rate updates and period loop. Bounded findings are preserved in `scratch/game_early_transform_phase/FINDINGS.md`.
