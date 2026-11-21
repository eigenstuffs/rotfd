# Grid event updates and diagnostic report

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent source units recover two event guards and a grid report. Their manifest list is `scratch/game_grid_event_updates/manifest-list.json`.

| Source | Text range | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/grid_counter_event_80072684.cpp` | `80072684..800726EC` (104) | `8000C838..8000C840` | `8001926C..80019278` |
| `src/Game/grid_pending_events_800726ec.cpp` | `800726EC..80072754` (104) | `8000C840..8000C848` | `80019278..80019284` |
| `src/Game/grid_values_report_800729c8.cpp` | `800729C8..80072AF8` (304) | `8000C850..8000C858` | `80019290..8001929C` |

The counter callback increments owner word `0x38C`, dispatching event `0xAA` only when the new count is eight. It queries the current resource through global `lbl_803776B8`, virtual table offset `0x14`, and passes original external float `lbl_80378910`.

The pending-events routine checks event `0x9B` and dispatches `0x9C` back to itself using original external float `lbl_80378900`. It separately checks event `0x8F` and calls the diagnostic report.

The report reads the signed value at node offset `0x90` from each of nine twenty-byte inline cells beginning at owner offset `0x74`. It formats three rows into a 128-byte local buffer and sends the buffer and separator strings to the logger at context offset `0x110`. The original `0xA8`-byte shared string pool at `lbl_8029C8E0` contains a `0x24`-byte prefix followed by three `0x2C`-byte row formats. A typed view exposes those records, reproducing native shared-base reuse without claiming or allocating the external pool. The two-byte external separator is `lbl_80378914`.

The new frozen header is `include/Game/grid_event_update_views.h`; all three consumers are verified. GC 1.3.2 needs `['-Cpp_exceptions on']` for both guards and `['-O4,s', '-Cpp_exceptions on']` for the report's native `stmw/lmw` saves.

All strict per-function checks pass for 572 allocated bytes: 512 text and sixty exception/index bytes. The objects contain exactly one function, one extab record and one index record each. All 28 actual text relocations, six EH-index relocations and three nonallocated metadata relocations are audited, including actual SDA references to external constants. Original full DOL SHA1 and complete exception/constructor/destructor table ownership audits pass. No shared string or float, weak helper, BSS, padding or intervening original function is claimed. Each verifier imports the already frozen `scratch/game_resource_runtime_updates/verify_runtime.py`.
