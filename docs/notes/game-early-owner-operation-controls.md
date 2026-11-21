# Early owner operation controls

Batch 96 frozen isolated exact handoff, pending central integration.

| Function | Text | Exception table | Exception index |
| --- | --- | --- | --- |
| fn_8006A874 | 8006A874..8006A924 (176) | 8000C06C..8000C074 (8) | 80018D68..80018D74 (12) |
| fn_8006A924 | 8006A924..8006A9E0 (188) | 8000C074..8000C07C (8) | 80018D74..80018D80 (12) |
| fn_8006B0E8 | 8006B0E8..8006B220 (312) | 8000C0EC..8000C0F4 (8) | 80018DBC..80018DC8 (12) |

The position pair resolves the owner's handle58 once, builds an ordinary three-coordinate vector from the input transform, and applies/updates that owner. The second preserves the resolved owner's Y coordinate. Both first probes matched exactly.

The operation end routine obtains existing operation data, clears its byte45 and resource flags38 bit18, then dispatches notification3 when the generation-resolved actor flags120 bit7 and operation data's signed byte158 are set. It optionally invokes resource virtual slot38 when signed byte1ED equals1 and always invokes the base virtual slot34. Separate actor-handle and resource-handle pool views preserve the native reloads of owner bits and entries. An ordinary local pointer to the observed base interface preserves the saved-register alias across the optional derived virtual call. The base has virtual slots through34; the resource extends it with38. These are observed interfaces, with no emitted vtable or native identity migration.

Sources use prefix `src/Game/early_owner_operation_control_`; their only shared header is `include/Game/early_owner_operation_control_views.h`. GC/1.3.2 with `-O4,s -Cpp_exceptions on` emits exactly one .text extent plus extab8/index12 per source. The strict verifiers resolve all6 retained ELF relocations per source and compare every allocated byte against the original DOL. One nonallocated compiler category reference each is accounted for. Actual local EH names/extents are frozen. No weak code, compiler-owned literals, BSS, padding, aliases, or original constructor/destructor references are introduced.

The complete original extabindex 80015F60..8001F2C0, .ctors 80299920..80299980 and .dtors 80299980..802999A0 tables were audited. Manifest list: `scratch/game_early_owner_operation_controls/manifest-list.json`. Original DOL SHA-1 remains 5da8295a79bf297ab62c620e6ac66210be1c6ef5. Source/header/evidence are frozen; matching credit requires central original-hash acceptance.
