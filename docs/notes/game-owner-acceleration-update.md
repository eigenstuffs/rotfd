# Owner acceleration update

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The independent `src/Game/owner_acceleration_update_8009f9a4.cpp` reconstructs fn8009F9A4, text8009F9A4..8009FABC (280), extab8000FC88..8000FC90 (8), extabindex8001B2DC..8001B2E8 (12). GC1.3.2 standard optimization requires extra `['-Cpp_exceptions on']`. The frozen manifest list is `scratch/game_owner_acceleration/manifest-list.json`.

It resolves owner handle zero and skips inhibited resources. When high flag0x80 is absent it adds the scaled delta contribution to acceleration Y and adds the external zero to X/Z; otherwise it clears velocity Y. The ordinary signed-character flag query preserves both native flag-word mask operations.

This adds one verified consumer of the existing frozen `include/Game/owner_resource_action_views.h` (four total); the header and its prior consumer proofs remain unchanged. Strict verification proves all300 allocated bytes, actual local EH/index names, five text relocations (including SDA data), two EH-index and one nonallocated metadata reference. Full original DOL SHA1 and complete exception/constructor/destructor table ownership checks pass. The context and floats remain external; no data/BSS, weak helper, padding or gaps are claimed. Full executable acceptance remains centrally owned.
