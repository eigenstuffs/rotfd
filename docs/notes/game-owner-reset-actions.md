# Owner reset actions

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five independent source units reconstruct owner name transitions and reset actions. The manifest list is `scratch/game_owner_reset_actions/manifest-list.json`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_names_enter_80094804.cpp` | `80094804..8009486C` (104) | `8000F088..8000F090` | `8001AA60..8001AA6C` |
| `src/Game/owner_names_leave_8009486c.cpp` | `8009486C..800948D4` (104) | `8000F090..8000F098` | `8001AA6C..8001AA78` |
| `src/Game/owner_controls_reset_80094b14.cpp` | `80094B14..80094BA4` (144) | `8000F0FC..8000F104` | `8001AAA8..8001AAB4` |
| `src/Game/owner_counter_reset_80094ef0.cpp` | `80094EF0..80094F58` (104) | `8000F14C..8000F154` | `8001AB20..8001AB2C` |
| `src/Game/owner_velocity_reset_800957f4.cpp` | `800957F4..8009587C` (136) | `8000F2B0..8000F2B8` | `8001ABB0..8001ABBC` |

The paired name transitions construct two trivial hashed-name objects from original external strings `lbl_8029DC78` and `lbl_8029DC84`, forwarding them to `fn_80229C30` and `fn_80229BBC` in opposite order. The compiler places the two full-expression temporaries at stack `0xC` and eight as native.

The controls reset clears three control bits through the agent's `0x318` subobject, clears target flag `0x20000` at `0x38`, and calls `fn_8025795C(target,1,0)`. The counter action adds one through the screen counter function and clears agent flag `0x200` at `0x30`. The velocity action performs the same three controls resets and target callback, then assigns the existing external zero vector to agent `0x144/148/14C`. The explicit componentwise vector assignment reproduces the native floating loads and stores.

All share the new frozen `include/Game/owner_reset_action_views.h`; all five consumers are verified. GC1.3.2 uses standard optimization and Object extra `['-Cpp_exceptions on']`.

The strict per-source checks prove all692allocated bytes: 592 text and100exception/index bytes. Every source emits exactly one function, its own extab8 and index12, with actual ELF local names and contiguous per-section extents. All29actual text relocations, ten EH-index relocations and five nonallocated metadata relocations are audited. Original DOL SHA1 and complete original exception/constructor/destructor ownership checks pass. No external string/zero-vector allocation, weak helper, BSS, padding or original gap is claimed.
