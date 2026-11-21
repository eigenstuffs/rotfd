# Grid triangle collision sweep (World285)

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801DF770` at `801DF770..801DF9B0` is an ordinary C++ reconstruction of a square-grid triangle collision sweep. It emits exactly576 text bytes with three actual relocations under GC1.3.2, gekko, O4,s, exceptions off. Production source is `src/Game/grid_triangle_sweep_801DF770.cpp`. Isolated byte/relocation and real MWLD checks pass; central full-DOL acceptance is pending.

The grid has `(n+1)^2` Vec4 vertices followed by two Vec4 planes per quad. Each row tests triangles `(topLeft,bottomLeft,topRight)` and `(topRight,bottomLeft,bottomRight)` when its plane W differs from the borrowed float `lbl_8037A4E0`. Successful queries append point, normal, distance and a uint64 token to the256-record hit buffer. At capacity the final slot is reconstructed and reused. Each40-byte hit has point0, distanceC, normal10, object1C reset to null, and token20. The high/low native token argument is one genuine uint64 value.

The query result is48 bytes, established independently from the original output stores: `fn_8027A180` forwards the result pointer to `fn_8027B140`, whose successful path writes fields through offset2C. Observed trailing field types are words at1C/28/2C and floats at20/24; their meanings remain unknown. These fields are native output storage. The original output chain and store addresses are preserved in `original-output-layout.json` and original function assembly copies. This true result extent explains the native0x80 frame without arbitrary padding.

The full original table audit covers extabindex80015F60..8001F2C0, ctors80299920..80299980, and dtors80299980..802999A0. None owns this function. The stable active-original census examined5655 objects,119086 real relocations and777360 initialized words: sole originalGLOBAL576 identity, two branch consumers, no initialized pointer consumers or aliases. No existing source consumers require migration. All query implementations, the float, adjacent functions and surrounding original data remain external.

Evidence: `scratch/game_grid_triangle_sweep_801df770/{final_integration.json,verify.py,native_proof.py,active-original-audit.json,ownership_audit.json}` and frozen handoff `scratch/game_engine_batch285/`. The real-link proof checks all three linked primary relocations, exact extent, and rejects a wrong primary extent. No compiler weak helpers, EH, data, BSS, startup allocation or padding is emitted. Root must still verify original placement, complete DOL hash, baseline and normal tests before credit.
