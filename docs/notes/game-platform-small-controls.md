# Controller, timer and buffer controls

Five independent ordinary C++ units match **300 code bytes and nine actual relocations**. Production integration and full original-DOL acceptance are pending. All original C entries and borrowed dependency identities remain unchanged.

| Source | Original extent | Bytes / relocations | Behavior |
| --- | --- | ---: | --- |
| platform_pad_reset_all.cpp | 80275B54..80275B94 | 64 / 2 | Reset all four controller channels, then stop all motors using a local command array. |
| platform_pad_reset_port.cpp | 8027639C..802763D0 | 52 / 3 | Reset the controller channel selected by a signed-short index into the original mask table. |
| platform_timer_list_clear.cpp | 80260180..802601C8 | 72 / 1 | Remove each timer node from the head before returning it to the existing node pool. |
| platform_six_buffer_activate.cpp | 80271944..80271980 | 60 / 2 | Refresh the six base handles, clear byte 88, then rebuild the buffers. |
| platform_six_buffer_ready.cpp | 802719CC..80271A00 | 52 / 1 | Convert the base resource's signed-byte readiness result to signed-byte zero or one. |

All first isolated probes matched. Fresh production compiles retain the complete function extents, symbol inventories and resolved relocation targets. GC1.3.2 uses ordinary Game `-O4,p`, exceptions off, with the existing source-header directory added to the include search path. The buffer wrappers use the accepted native `SixHandleResource_802EA840` member declarations and qualified base calls. That class is a prefix view of the larger buffer object; byte 88 remains unnamed. The timer helper uses the accepted `TimerList`/`TimerNode` declarations. No existing source or header changes are required.

Each object emits only its complete retained `.text` function. There are no weak backups, initialized data, BSS, exception allocations, constructor/destructor entries or owned padding. The original 16-byte controller mask table `lbl_802ED6E8`, also used by the accepted controller poller, remains external and uncredited. All other neighboring functions and data remain outside these partial units.

The complete original exception index, including its descriptor and trailing padding, and the complete constructor/destructor tables contain no references to these extents. Four initialized-data function pointers retain their existing external owners. The current canonical/split census finds no prior source ownership; the scratch body census finds only this new investigation's probes. Existing C entry identities remain unchanged, so consumer migration is unnecessary.

The frozen batch is `scratch/engine_small_platform_controls_20261011iq/final_integration.json`, a list of five complete candidate records. Its allocation inventory, original table/pointer audits, current consumer census and fresh strict verification preserve the evidence. Root owns central registration, promotion, linking and original-DOL/regression acceptance.
