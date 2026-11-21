# Owner callback array setup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six independent source units reconstruct callback allocation into an existing owner array. The frozen manifest list is `scratch/game_owner_callback_array_setup/manifest-list.json`. All six consumers of the new frozen `include/Game/owner_callback_array_setup_views.h` pass strict verification. The controller is at 0x318 and callback array pointer at 0x344.

| Source | Text | extab | extabindex | Extra compiler flags |
| --- | --- | --- | --- | --- |
| `src/Game/owner_callback_array_80096078.cpp` | `80096078..800961E0` (360) | `8000F3C8..8000F3D0` | `8001AC58..8001AC64` | `['-O4,s', '-Cpp_exceptions on']` |
| `src/Game/owner_callback_array_80096b30.cpp` | `80096B30..80096C98` (360) | `8000F4C8..8000F4D0` | `8001AD0C..8001AD18` | `['-O4,s', '-Cpp_exceptions on']` |
| `src/Game/owner_callback_array_80097ab8.cpp` | `80097AB8..80097C20` (360) | `8000F678..8000F680` | `8001AE2C..8001AE38` | `['-O4,s', '-Cpp_exceptions on']` |
| `src/Game/owner_callback_array_80098644.cpp` | `80098644..800987AC` (360) | `8000F778..8000F780` | `8001AEE0..8001AEEC` | `['-O4,s', '-Cpp_exceptions on']` |
| `src/Game/owner_callback_array_80098b18.cpp` | `80098B18..80098CB0` (408) | `8000F7D0..8000F7D8` | `8001AF34..8001AF40` | `['-O4,s', '-Cpp_exceptions on']` |
| `src/Game/owner_callback_array_8009d2dc.cpp` | `8009D2DC..8009D42C` (336) | `8000FB3C..8000FB44` | `8001B1C8..8001B1D4` | `['-Cpp_exceptions on']` |

The common 80098B18 routine allocates five 16-byte callbacks in slots 0 through 4, passing the owner and caller context to their existing initializers. The four specialized routines first call this common setup, then allocate four further 16-byte callbacks in slots 5 through 8, preserving their original order and identifier gaps; the controller is configured for nine callbacks. The independent 8009D2DC routine allocates four 12-byte callbacks in slots 0 through 3, passes only the owner to the existing initializers, and configures the controller for four. No array binding call is added.

All allocations retain the existing allocator, original category/source strings, original identifiers, alignment four, and null checks. Existing callback initializer identities and bodies remain external. The five context-taking routines require `-O4,s` for the native multi-register save/restore form; all six require `-Cpp_exceptions on` under GC1.3.2.

Strict verification proves all 2,304 allocated bytes: 2,184 text and 120 exception/index bytes. Actual local ELF names, all 204 text relocations, 12 EH-index references, and six nonallocated metadata references are audited. The full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. No additional data/BSS, weak helper, padding, or gaps are claimed. Final executable acceptance remains centrally owned.
