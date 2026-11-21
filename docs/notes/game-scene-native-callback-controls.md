# Scene native callback and Handle controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six isolated production objects match all original allocated sections and actual relocations; integrated production acceptance has passed.

| Entry | Text bytes | Behavior |
| --- | ---: | --- |
| `800C0FF8` | 196 | Logs the callback, resolves the scene actor, updates two vector components and selects controller state. |
| `800CC7D0` | 360 | Allocates and initializes four callback records, stores the results and sets the component count. |
| `800E1248` | 164 | Forwards four opaque arguments and a float to the selected virtual controller or the original fallback. |
| `800E295C` | 168 | Advances phase, calculates the original trigonometric vector and calls the actor virtual method. |
| `800E3308` | 160 | Clears flag bit 0, binds an original named Handle, runs setup and clears the virtual selection. |
| `800E3850` | 160 | Clears flag bit 2, binds its original named Handle, runs setup and clears the virtual selection. |

The six entries own 1,208 text bytes and 152 exception table/index bytes, with 82 actual retained relocations. They emit no additional allocated code, data, padding, weak definitions or startup tables. All strings, floating-point constants, global context and original callback tables remain externally owned. The native four-byte Handle return and destructor preserve the existing identities and calling convention.

The original exception metadata selects ordinary `-proc 750` saves for `800CC7D0`, `800E1248`, `800E3308` and `800E3850`; the other two use Gekko. `800E295C` uses the native contraction setting to reproduce its fused phase update. Each private production unit keeps its exact compiler flags in the manifest.

`ownership_audit.json` in `scratch/game_scene_callback_controls/` records complete original extabindex/startup-table scans, initialized-data references and unchanged compiled consumers. `freeze.py` inventories every allocation and symbol; `verify.py` recompiles each production source and requires the frozen object hash and strict relocated bytes. No identity migrations or source consumer changes are required.
