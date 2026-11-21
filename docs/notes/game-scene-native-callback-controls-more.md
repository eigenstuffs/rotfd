# Further scene callback setup and nested Handle controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five isolated production units match all original allocated sections and actual relocations; integrated production acceptance has passed.

| Entry | Text bytes | Behavior |
| --- | ---: | --- |
| `800C0874` | 148 | Checks the current record, clears a rejected selection and updates all four records. |
| `800C47EC` | 408 | Gets the selected mode index, updates the nested parent callback and scene actor, and records the resulting state. |
| `800E05B4` | 320 | Resolves a nested owner Handle chain, checks a retained Handle and selects the owner controller when the related state is active. |
| `800E111C` | 264 | Allocates two callback records, sets component count and state, then applies the original 64-bit flag mask. |
| `800E2C3C` | 228 | Allocates two callback records and sets component count and state. |

The five entries own 1,368 text bytes and 100 exception table/index bytes. All strings, original record arrays, global indices, allocator and original callback-table pointers remain externally owned. No additional code, weak definitions, local data, padding or startup allocations are emitted.

The two nested lookup routines use a byte-backed entry-storage view for one lookup. This preserves the original second load of the manager entry pointer. The typed entry and four-byte signed generation/index Handle retain their observed layouts. `800C47EC` obtains the mode pointer before initializing its output index, preserving the native evaluation order. Neither view changes an external identity or consumer.

The original exception records select `-proc 750` for four entries; `800C47EC` uses Gekko. Each source keeps the exact compiler flags in its frozen manifest. Original full extabindex and startup-table scans, initialized-data references, all symbol extents, actual relocations and unchanged compiled consumers are recorded in `scratch/game_scene_callback_controls_more/ownership_audit.json`. `verify.py` recompiles production sources and verifies their frozen hashes and every original allocated byte.
