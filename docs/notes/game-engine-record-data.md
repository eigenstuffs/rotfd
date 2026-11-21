# Record transfer and occupancy routines

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six ordinary C entries preserve their original names and compile with GC 1.3.2 using the established container flags: `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`.

| Function | Text bytes | EH/index bytes | Actual relocations | Observed behavior |
| --- | ---: | ---: | ---: | --- |
| `fn_800E8CA4` | 180 | 20 | 9 | Calls service slot `20` with the owner name and record group, stores its status, logs the result and the corresponding success/failure message, and returns native bool success for status zero. |
| `fn_800E8D58` | 144 | 20 | 10 | Clears three occupancy bytes, passes the selected record to `fn_80054E1C`, and logs. |
| `fn_800E8DE8` | 108 | 20 | 2 | Calls service slot `20`, stores the status, and returns native bool for the selected occupancy byte. |
| `fn_800E8E54` | 100 | 20 | 2 | Calls the same service slot, stores its status, and returns a signed-byte success value for status zero. |
| `fn_800E8EB8` | 192 | 20 | 5 | Passes the selected record to `fn_800541F0`, sets its occupancy, calls service slot `1C`, clears all three occupancy bytes, and returns the stored status. |
| `fn_800E8F78` | 116 | 20 | 2 | Calls service slot `24` with the name, stores its status, clears all three occupancy bytes, and returns the status. |

The private owner view continues the verified layout from the record construction and record operations notes. Three `3B5C`-byte records start at `D4`; selection uses stored index `B2F8 - 1`. Occupancy is the three signed bytes `D0..D2`, also accessed through the observed four-byte group beginning at `CF`. Resource context lookup follows global offset `124`, context offset `15058`; service dispatch uses the virtual pointer at service offset `30`. The name, group, byte count, service and status fields occur at `60`, `C8`, `B2F0`, `B2E8` and `B2F4`. These are inferred private views of observed offsets, with no invented validation or complete-layout claim.

`fn_800E8CA4` addresses the original packed literal region `802AB250..802AB364` through a const array reference. It uses format offsets `B0`, `D0` and `F0`. The array is only an address view over existing original data; no literal definitions, new ownership or copied strings are emitted. `literal_pool_audit.json` records the original objects and whole-region hash. A const pointer local rematerialized the first format address and added eight code bytes despite keeping the base live across the service call. The array reference preserves the original base reuse. Bounded ordinary pointer/reference alternatives and optimizer probes are retained under `pool_probes/`; the mutable-pointer and disabled-propagation alternatives were exact too, but the frozen production source uses the const view and normal established flags.

`fn_800E8E54` uses an explicit success branch with signed-byte return. A direct equality expression left the saved-register restore after the comparison sequence; the branch reproduces the original earlier restore. All tested expressions remain under `near_probes/`.

All 840 retained code bytes, 120 original exception/index bytes and 30 actual relocations match in the final production objects. No weak functions, helper code, new literals, padding or other allocated output are emitted. Dependencies contain actual undefined ELF symbols only. Recursive quoted-header hashes are frozen; each production source expands its private view and has no quoted headers.

Complete exception-index, ctor and dtor scans cover `80015F60..8001F2C0`, `80299920..80299980` and `80299980..802999A0`. Every function has exactly its owned original exception/index pair, and none has startup pointers. All initialized data words into the function extents and current source consumers are inventoried in `ownership_audit.json`. Original tables, strings and globals retain their prior owners. These are six bounded function splits, not a claim to have reconstructed a complete original translation unit.

The frozen handoff is `scratch/game_engine_record_data_continuation/handoff.json`. `final_integration.json`, `final_splits.txt` and `final_config.txt` provide the exact integration proposal. `verify.py` independently recompiles all six production sources and strictly checks all allocations, symbols, original bytes and resolved relocations. Central full-DOL and regression checks remain pending integration.
