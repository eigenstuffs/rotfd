# Early camera state queries and displacement

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two isolated ordinary C++ functions match complete original allocations using GC1.3.2 and `-O4,s -Cpp_exceptions on`:

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_80077540 | 312 | 8000CFFC..8000D004 | 800195F0..800195FC | 7 |
| fn_80078550 | 144 | 8000D04C..8000D054 | 80019668..80019674 | 3 |

The first performs the original generation-checked target lookup separately for state0,6,24 and returns one if any query succeeds. Its short-circuit expression preserves all repeated manager resolutions and signed-byte result tests. The second snapshots the current vector before querying another position and outputs their difference using ordinary value arithmetic; the three saved scalar values and all output stores match.

Sources are `src/Game/early_camera_query_80077540.cpp` and `early_camera_query_80078550.cpp`; declarations are in dedicated `include/Game/early_camera_query_views.h`. Each emits one function and its actual local compiler EH/index symbols. No weak helpers, external data ownership, aliases, native identity migrations, BSS or padding are proposed.

Frozen manifests are listed in `scratch/game_engine_batch103/manifest-list.json`. Each strict verifier recompiles production source, applies every actual PowerPC/SDA relocation and compares every allocated byte to the normalized original DOL. Complete original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 audits prove the retained function's one EH owner and no startup/shutdown references. This is isolated evidence awaiting central original-DOL acceptance, not a complete original translation-unit claim.

Private neighboring queries remain uncredited: fn800784A8 is168/4 FPR differences; fn80077BDC/fn80077D28 are332/16 FPR differences after complete Handle/virtual prefixes match. Their bounded probes and original ownership remain preserved; see `scratch/game_early_camera_queries/FINDINGS.md`. The known fres/frsqrte near functions80078194/80078414 were skipped.
