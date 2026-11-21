# Early callback controller operations

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six independent source units reconstruct callback state management. The frozen manifest list is `scratch/game_early_callback_controller/manifest-list.json`. The new frozen `include/Game/early_callback_controller_views.h` has six verified consumers; the static inline operations in `include/Game/early_callback_controller_operations.h` have two (reset and drain). All units use GC1.3.2 with extra `['-O4,s', '-Cpp_exceptions on']`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/callback_control_query_8007d604.cpp` | `8007D604..8007D6A0` (156) | `8000D578..8000D580` | `800197DC..800197E8` |
| `src/Game/callback_control_start_8007d6a0.cpp` | `8007D6A0..8007D7EC` (332) | `8000D580..8000D588` | `800197E8..800197F4` |
| `src/Game/callback_control_stop_8007d7f4.cpp` | `8007D7F4..8007D8EC` (248) | `8000D588..8000D590` | `800197F4..80019800` |
| `src/Game/callback_control_reset_8007d954.cpp` | `8007D954..8007DA74` (288) | `8000D598..8000D5A0` | `8001980C..80019818` |
| `src/Game/callback_control_update_8007da74.cpp` | `8007DA74..8007DB74` (256) | `8000D5A0..8000D5A8` | `80019818..80019824` |
| `src/Game/callback_control_drain_8007db78.cpp` | `8007DB78..8007DCDC` (356) | `8000D5A8..8000D5B0` | `80019824..80019830` |

The controller records an exclusive current callback at 0x08, previous selection at 0x0C, pending selection at 0x10, a 64-bit active mask at 0x18, 64-bit active count at 0x20, callback count at 0x28, and callback pointer array at 0x2C. Each callback has a signed exclusive byte at 0x04 and virtual start, update, and stop operations. The existing index hook 8007DCF4 remains external.

Query checks the current selection for exclusive callbacks and the mask for others. Start changes exclusive selection while exposing the pending index during its stop callback, or sets a mask bit and increments the active count. Stop clears the current selection or active mask/count, then calls the callback only when state changed. Update processes the exclusive selection and active mask entries, stopping once the stored active count has been visited. Drain removes active entries through the same ordinary inline stop operation. Reset selects the reserved callback at array index -1, drains active entries, and clears the enabled byte. Its inline start helper explicitly gives the negative sentinel a zero mask, avoiding a negative shift while preserving all emitted native bytes.

The update loop declares its index before the counters to reproduce the original allocation. The drain loop shifts with an unsigned index conversion, preserving separate ordinary mask calculations around the index hook. These are ordinary C++ source forms; no assembly or register assignments are used. Static inline helpers emit no extra functions or sections.

Strict verification proves all 1,756 allocated bytes: 1,636 text and 120 exception/index bytes. Actual local ELF names, all 12 text relocations, 12 EH-index references, and six nonallocated metadata references are audited. The full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. No additional data/BSS, weak helper, padding, or gaps are claimed. Final executable acceptance remains centrally owned.
