# Early camera state and paired handles

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three isolated ordinary C++ functions match every original emitted allocation with GC1.3.2 and `-O4,s -Cpp_exceptions on`:

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_80075EC0 | 144 | 8000CF10..8000CF18 | 8001956C..80019578 | 8 |
| fn_8007682C | 148 | 8000CF9C..8000CFA4 | 8001959C..800195A8 | 5 |
| fn_80076F60 | 252 | 8000CFBC..8000CFC4 | 800195CC..800195D8 | 13 |

The first assigns the two retained Handle members at230/234 with the original manager decrement/copy/increment operations and sets ready238. The second switches state1 to2 when the timer is at most20; in state2 it queries a position, applies the original vertical offset, and copies the desired/current vectors. The vector constructor preserves x/y/z storage while adding the vertical offset through a mutable local height. The third queries/scales an orientation vector in state2; otherwise it evaluates the original three trig calls from angles1C0/1C8, scales the result, and adds its vertical offset.

Production sources are `src/Game/early_camera_state_80075ec0.cpp`, `early_camera_state_8007682c.cpp`, and `early_camera_state_80076f60.cpp`; their dedicated header is `include/Game/early_camera_state_views.h`. All original floats, manager and called functions remain external. The explicit observed views do not claim complete original class identities. Each source emits one function and its actual local compiler EH/index symbols, with no weak helper or other allocation.

Frozen manifests: `scratch/game_engine_batch102/manifest-list.json`. Per-unit strict verifiers recompile production source, verify all real relocations and allocated bytes against the normalized original DOL, and scan the complete original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0. Each function retains precisely its original EH entry and no startup/shutdown slot. No aliases, native identity changes, BSS, padding or external data ownership are proposed. This isolated proof awaits central original-DOL acceptance and does not imply a complete original translation unit.

The nearby nested Handle shutdown fn800751F4 remains private and uncredited at428 bytes with five register differences in its initial resolution. Its byte-backed resource manager view recovers the complete later nested chain; bounded results are preserved in `scratch/game_early_camera_state/FINDINGS.md`.
