# Resource flag updates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent source units reconstruct adjacent resource/owner operations:

- `src/Game/resource_flag_update_800692b4.cpp`, `800692B4..80069330` (124 bytes), calls the virtual resource getter at slot `14`, then clears bit `20000` in its 64-bit flags at `38` for input zero, or sets it for nonzero input.
- `src/Game/owner_byte_update_80069464.cpp`, `80069464..800694E8` (132 bytes), obtains a handle through slot `28`, resolves its generation tag, and stores the signed-byte input at owner offset `3D2`.
- `src/Game/owner_short_forward_80069770.cpp`, `80069770..800697F8` (136 bytes), obtains and resolves that handle, explicitly converts its short input, and forwards it to `fn_8009FABC`, preserving the signed-byte return. The signature matches the existing Python caller declaration.

The three units share the new frozen `include/Game/resource_flag_update_views.h`; all consumers pass exact production compilation. No prior shared header was edited. Each source uses standard GC/1.3.2 with `-Cpp_exceptions on` and emits only its function plus eight bytes of `extab` and twelve bytes of `extabindex`.

Exception allocations are `8000BD98..8000BDA0`, `8000BDB0..8000BDB8`, and `8000BDC8..8000BDD0`; their original entries are `80018CB4..80018CC0`, `80018CD8..80018CE4`, and `80018CFC..80018D08`. All 392 text bytes and 60 EH/index bytes match. No weak helpers, literals, BSS, padding, or intervening original bytes are emitted or claimed.

`scratch/game_resource_flag_updates/manifest-list.json` lists the three manifests; each neighboring `verify.py` verifies its complete contiguous allocations, actual ELF local symbol identities, real relocations, header hash, and full original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`). All original EH owners are reconstructed and no ctors/dtors ownership exists. The DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Central whole-DOL acceptance is pending.
