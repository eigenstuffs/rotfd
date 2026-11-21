# Resource runtime updates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five independent units recover runtime registration, resource flags and owner bytes. Each has one contiguous text function plus its original eight-byte exception table and twelve-byte exception index.

| Source | Function/text bytes | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/runtime_registration_8006c118.cpp` | `8006C118..8006C194` (124) | `8000C1B0..8000C1B8` | `80018E88..80018E94` |
| `src/Game/resource_inhibit_8006c78c.cpp` | `8006C78C..8006C808` (124) | `8000C20C..8000C214` | `80018EDC..80018EE8` |
| `src/Game/owner_option_8006c808.cpp` | `8006C808..8006C88C` (132) | `8000C214..8000C21C` | `80018EE8..80018EF4` |
| `src/Game/owner_byte_8006ec64.cpp` | `8006EC64..8006ECE8` (132) | `8000C3CC..8000C3D4` | `80018FF0..80018FFC` |
| `src/Game/runtime_sentinel_8006edcc.cpp` | `8006EDCC..8006EEB8` (236) | `8000C434..8000C43C` | `80019008..80019014` |

`fn_8006C118` activates on mode one through virtual table offset `0x5C`, then registers itself in the global owner's registration record at offset `0x88`. The global `lbl_803776B8` points to a base subobject at offset `0x60`; genuine C++ downcasting reproduces the native null-preserving adjustment. Mode two calls the deactivate slot at `0x60`. The function returns one.

`fn_8006C78C` clears resource flag `0x1000000` for nonzero input and sets it for zero. The virtual resource getter is at table offset `0x14`, and resource flags are at `0x38`.

The remaining three resolve the generation-tagged handle returned by virtual table offset `0x28`. The manager at context offset `0x118` contains sixteen-byte entries, with object pointer zero and signed generation byte `0xC`. `fn_8006C808` writes signed owner byte `0x3E8`. `fn_8006EC64` writes unsigned byte `0x3F4`. `fn_8006EDCC` first stores its input at query offset `0x153`, then sets signed owner byte `0x3F4` to zero or minus one. A union exposes the signed sentinel and unsigned raw byte at their shared address without adding storage.

The new frozen `include/Game/resource_runtime_update_views.h` contains only declarations and inline resolver logic. All five consumers are verified. GC 1.3.2 uses Object extra `['-Cpp_exceptions on']`; no optimization override is needed.

The per-source strict verifiers under `scratch/game_resource_runtime_updates/` reproduce all 848 allocated bytes: 748 text and 100 exception/index bytes. They audit actual symbol names, nine actual text relocations (including one SDA relocation), ten owned exception-index relocations and five nonallocated metadata relocations. The complete original extabindex, ctor and dtor table audits and original DOL SHA1 pass. No weak helper, literal, BSS, padding or intervening original range is claimed. Manifest list: `scratch/game_resource_runtime_updates/manifest-list.json`.
