# Resource action queries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent source units recover a float-driven event, a position snapshot and registration. The manifest list is `scratch/game_resource_action_queries/manifest-list.json`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/resource_float_event_8006bbd4.cpp` | `8006BBD4..8006BCC8` (244) | `8000C170..8000C178` | `80018E28..80018E34` |
| `src/Game/resource_position_snapshot_8006bff8.cpp` | `8006BFF8..8006C118` (288) | `8000C1A8..8000C1B0` | `80018E7C..80018E88` |
| `src/Game/resource_registration_8006c194.cpp` | `8006C194..8006C230` (156) | `8000C1B8..8000C1C0` | `80018E94..80018EA0` |

The float event forwards both inputs through `fn_8007D074`/`fn_8007622C`, calls the context speaker's virtual update with an integer-scaled first input, and dispatches event `0xCF` with the second input when it meets the original external threshold. All four referenced float constants remain external. The speaker is at context offset `0x154`, its vptr at `0x1C` and its update slot at `0x38`.

The snapshot gets a resource through virtual table offset `0x14`, resolves the resource's handle at `0x58`, and copies model position `0x30/34/38` through the pointer at resolved-owner offset `0x124`. It constructs a three-component vector before resolving the query's own handle through table offset `0x28`, then assigns the result to owner `0x398/39C/3A0`. The explicit component constructor reproduces all native saved floating registers and the original component load order.

The registration routine ensures the global resource has a registration pointer at `0x1F8`, using global virtual slot `0x58` when absent. It names the query's resource before retrieving the global registration and forwarding both to `fn_80024A5C`. Its unused signed-byte argument is preserved for the accepted Python caller.

The new frozen header is `include/Game/resource_action_query_views.h`; all three consumers are verified. GC 1.3.2 uses Object extras `['-O4,s', '-Cpp_exceptions on']` for this batch. Every source emits only one contiguous function and its original extab8/index12 records.

Strict checks pass for all 748 allocated bytes: 688 text and sixty exception/index bytes. Actual local ELF names, fifteen text relocations, six owned index relocations and three nonallocated metadata relocations are verified, including real SDA constants and global references. Original DOL SHA1 and full original exception/constructor/destructor ownership audits pass. No weak helper, literal, BSS, padding or intervening original range is claimed.

`fn_8006C230` remains private and uncredited at 244 bytes with ten register-identity differences. `scratch/game_resource_action_queries/FINDINGS.md` preserves that bounded result.
