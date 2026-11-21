# Record state transitions

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Thirteen ordinary C entries preserve their original identifiers and use GC 1.3.2 with the established `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` container flags.

| Function | Text bytes | EH/index bytes | Actual relocations | Observed behavior |
| --- | ---: | ---: | ---: | --- |
| `fn_800E863C` | 36 | 0 | 1 | Installs the same original small-data fallback string into all three name-pointer slots. |
| `fn_800E8700` | 56 | 20 | 3 | Sets flag B300 and sends notification 5. |
| `fn_800E96A4` | 148 | 20 | 10 | Loads the global record pointer, queries service status, and chooses which original name refresh path to call. |
| `fn_800E9ADC` | 56 | 20 | 7 | Logs the original fixed message. |
| `fn_800E9B70` | 60 | 20 | 5 | Loads the global record pointer and resets its three names through fn_800E863C. |
| `fn_800E9F00` | 56 | 20 | 7 | Logs another original fixed message. |
| `fn_800EA364` | 192 | 20 | 7 | Queries status and success/space checks, returning an integer result and sending notification 19 or 11 on the observed failure paths. |
| `fn_800EA848` | 200 | 20 | 10 | Queries the global service and selects flag cleanup and notifications from the original flag branches. |
| `fn_800EB058` | 124 | 20 | 7 | Selects flag cleanup and notification 0 or 5. |
| `fn_800EB520` | 124 | 20 | 7 | Repeats the same flag transition for another callback entry. |
| `fn_800EB8C4` | 152 | 20 | 8 | Subtracts elapsed time, queries the service, and sends notification 7 or 10 on the original conditions. |
| `fn_800EBBF8` | 200 | 20 | 11 | Handles the combined flag paths, then queries the service and may notify and refresh the record. |
| `fn_800EBF1C` | 140 | 20 | 7 | Combines an owner byte and record flags to select cleanup and notification 2 or 0. |

The private views reuse the record layout established by the construction, lifecycle, operation and data notes. Context field `1505C` points to the record owner. Callback objects hold their notification object at `08` and record pointer at `0C`. Their observed offset `10` is a float countdown in one callback and a signed flag byte in another; the private view records those separate observed uses without claiming a complete common original class. Flags `B300..B308` remain signed bytes. Service virtual slot `64` is a signed-byte query using the dispatch pointer at offset `30`. Existing scalar clearing helpers and notifications retain their names and original targets.

The caller instructions explicitly extend the low byte of `fn_800E8CA4` and `fn_800E8B70` before testing. These private caller declarations therefore use signed-byte returns. The separately frozen producer bodies use bool result expressions and return only zero or one in the same native register; their source, targets and bytes are untouched. Casting a bool-declared call to signed byte allowed CodeWarrior to use an unsigned byte clear instead of the original signed extension. The initial declarations and exact one-instruction discrepancy remain in `initial_probes/`. `fn_800EA364` queries status before initializing its result local, preserving the original scheduling of the call, comparison and constant assignment.

All 1,544 retained code bytes, 240 exception/index bytes and 90 actual relocations match in isolated final production objects and an independent strict production recompile. The small leaf `fn_800E863C` has no EH record; the other twelve functions each own their original eight-byte extab and twelve-byte index. No helper functions, weak code, new data, padding or extra allocations are emitted. Dependencies include actual undefined ELF symbols only; local EH symbols remain local. Production sources expand their private declarations, so there are no quoted-header dependencies.

Full original exception-index, ctor and dtor scans cover `80015F60..8001F2C0`, `80299920..80299980` and `80299980..802999A0`. No startup pointer targets these extents. `ownership_audit.json` inventories every initialized-data reference into each function, its original table/object owner, and unchanged source consumers. All strings, globals, vtables and intervening extents stay with their original owners. The handoff represents bounded function splits rather than recovered complete original translation units.

The frozen proposal is `scratch/game_engine_record_state_continuation/final_integration.json`, with exact split and flag proposals alongside it. `handoff.json` freezes sources, verifier, objects, evidence and note hashes; `verify.py` checks every emitted allocation, symbol extent, original byte and resolved relocation. Central full original-DOL, regression and progress checks remain pending integration.
