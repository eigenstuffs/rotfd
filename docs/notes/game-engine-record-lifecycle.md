# Record resource lifecycle

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six ordinary C entries retain their original external names and compile exactly with GC 1.3.2 and the established container flags (`-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`). Each emits only its original function, eight-byte exception object, and twelve-byte exception index. There are no weak functions, new literals, startup entries, or extra allocated sections.

| Function | Text extent | Actual relocations | Observed behavior |
| --- | --- | ---: | --- |
| `fn_800E7668` | `800E7668..800E76B0`, 72 | 3 | Calls `fn_80044380`, then virtual slot `98` with two zero arguments. |
| `fn_800E76B0` | `800E76B0..800E76F8`, 72 | 3 | Calls `fn_80044428`, then the same virtual slot. |
| `fn_800E770C` | `800E770C..800E7784`, 120 | 6 | Gets scalar parameters 1 and 2, stores signed byte `60` and zero-extended byte in word `64`, then copies global service member `15058` to member `70`. |
| `fn_800E8418` | `800E8418..800E85C8`, 432 | 11 | Configures the service and string fields established by the record/string constructor, supplies the `B220` record-group size, then resolves a newly obtained Handle into member `B2EC`. |
| `fn_800E85E4` | `800E85E4..800E863C`, 88 | 3 | Requires the inherited slot `1C` query, calls related object slot `1C`, and returns signed byte one; otherwise returns zero. |
| `fn_800E8660` | `800E8660..800E86C4`, 100 | 2 | Calls service slots `3C` and `40`, stores and returns the latter result through member `B2F4`. |

The private ordinary virtual classes place their dispatch pointers at the observed `08` or `30` offsets. Unused slots are declarations only. Private opaque views establish the fields accessed here and do not claim a complete original class layout or original method names.

`fn_800E8418` uses `self->objectB2EC = resolve(fn_801B52EC(...))`. The full-expression Handle temporary gives the original single cleanup lifetime and stack slot. Naming a local Handle first caused an extra copy and second destructor call, increasing text by twenty bytes and exception metadata by sixteen bytes. That earlier probe remains preserved separately. The final source matches every instruction, all original exception bytes, and all eleven actual relocations. The signed 24-bit index and eight-bit generation lookup matches the original sixteen-byte entry layout.

The original global storage and the original tables `lbl_802C9024` (156 bytes) and `lbl_802C9160` (136 bytes) retain assembly ownership. Complete initialized-data pointer scans record each callable reference, its object/table owner, and table offset. Full original exception-index (`80015F60..8001F2C0`), ctor (`80299920..80299980`), and dtor (`80299980..802999A0`) scans find exactly the six owned exception records and no startup entries. Existing compiled consumer identities are preserved.

The frozen handoff is `scratch/game_engine_record_lifecycle_continuation/handoff.json`. It accounts for 884 text bytes and 120 exception/index bytes with 28 actual relocations. `verify.py` recompiles the production sources and checks every allocated byte, symbol extent, and resolved relocation. Central original-DOL linking and regression checks are pending integration.

## Preserved startup near-match, not credited

Private `800E8130.cpp` expresses a `B310`-byte stack object, constructed through the accepted native constructor at `800E81C8`, used with the original twelve-byte member-pointer value, and destroyed through the accepted native destructor at `800E82C4`. All 152 code bytes and all actual code relocations match. One exception word at `80014FB4` remains different: original `91003701`, compiler `9100186C`. DTK does not decode this action-17 record. The difference is preserved without patching, masks, section omission, or matching credit. There is no production source or proposed split for this function in the handoff; any metadata-format investigation needs separate evidence and acceptance.
