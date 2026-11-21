# Early camera target updates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three isolated ordinary C++ functions match every original allocation using GC1.3.2 with `-O4,s -Cpp_exceptions on`:

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_8007A864 | 284 | 8000D190..8000D198 | 8001971C..80019728 | 8 |
| fn_8007A980 | 284 | 8000D198..8000D1A0 | 80019728..80019734 | 8 |
| fn_8007AA9C | 204 | 8000D1A0..8000D1A8 | 80019734..80019740 | 4 |

The first two original routines have the same behavior: when state0, enabled175 and current/target vectors differ, query target clearance. On success, initialize the up vector and smooth the direction when still in state0, then copy target to desired/current. Otherwise invoke the original fallback with delta. Explicit scalar comparisons preserve the original short-circuit branches without an intermediate materialized vector predicate. The fallback accepts the original paired queries; success copies target to desired/current, failure copies current to target/desired. Ordinary vector assignment preserves every original scalar load/store.

Sources are `src/Game/early_camera_target_8007a864.cpp`, `early_camera_target_8007a980.cpp`, and `early_camera_target_8007aa9c.cpp`; dedicated declarations are in `include/Game/early_camera_target_views.h`. The called clearance, collision and smoothing functions and original float symbols remain external. No weak helpers, owned external literals, BSS, padding, aliases or native identity changes are introduced. Each isolated production unit emits one function and its actual local compiler EH/index symbols.

Frozen manifests: `scratch/game_engine_batch104/manifest-list.json`. Per-function verifiers recompile production source, account for every allocated section and real relocation, and compare all relocated bytes to the normalized original DOL. Complete original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 scans retain precisely each function's EH owner and find no startup/shutdown slots. This isolated evidence awaits central original-DOL acceptance; the broader original translation unit remains outside this claim.
