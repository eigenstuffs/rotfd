# Owner resource callbacks

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent source units recover owner-resource notifications. The manifest list is `scratch/game_owner_resource_callbacks/manifest-list.json`; all three consumers of the new frozen `include/Game/owner_resource_callback_views.h` are strictly verified. GC1.3.2 uses standard optimization and extra `['-Cpp_exceptions on']` for each.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_resource_notify_8009c694.cpp` | `8009C694..8009C708` (116) | `8000F9F4..8000F9FC` | `8001B108..8001B114` |
| `src/Game/owner_resource_inhibit_8009c7b0.cpp` | `8009C7B0..8009C834` (132) | `8000FA0C..8000FA14` | `8001B12C..8001B138` |
| `src/Game/owner_resource_inhibit_8009cbd0.cpp` | `8009CBD0..8009CC54` (132) | `8000FA24..8000FA2C` | `8001B150..8001B15C` |

All three resolve the action's agent owner handle at `0x24` through the existing signed generation/index manager and call `fn_8025795C(resource,0xC,0)`. The latter two first set flag `0x20000` in the resolved resource's 64-bit flags at `0x38`. The correct 64-bit type emits the native lis/or sequence while the unused high load disappears; a32bit low-word view had produced a shorter ori sequence and was not accepted.

Strict verification proves all440allocated bytes: 380 text and60exception/index bytes. Every source emits exactly one function, its extab8 and index12, with actual local ELF names and contiguous section extents. All nine text relocations, six EH-index references and three nonallocated metadata references are audited. Full original DOL SHA1 and complete exception/constructor/destructor ownership table checks pass. No external data/BSS, weak helper, padding or original gap is claimed. Full executable acceptance remains centrally owned.
