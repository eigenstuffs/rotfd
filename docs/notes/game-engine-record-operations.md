# Record name selection and service operations

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eleven ordinary C entries preserve their existing names. They compile with GC 1.3.2 and the established container flags, including `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`.

| Function | Text bytes | Owned EH/index bytes | Actual relocations | Observed operation |
| --- | ---: | ---: | ---: | --- |
| `fn_800E8744` | 228 | 20 | 8 | Selects three record names or a default according to the three occupancy bytes. |
| `fn_800E8828` | 88 | 0 | 3 | Scans 31 sixteen-byte entries for two matching signed integer keys, returning the name at offset `04` or the original fallback string. |
| `fn_800E8880` | 108 | 20 | 8 | Logs, stores index `B2F8`, sets flag `B302`, and notifies the related object. |
| `fn_800E88EC` | 124 | 20 | 6 | Queries global service virtual slot `64` and sends notification 22 or 23. |
| `fn_800E8968` | 104 | 20 | 5 | Stores the index; when both existing checks succeed, sets flag `B301` and notifies. |
| `fn_800E89F4` | 172 | 20 | 4 | Sets flag `B303`, polls the service, and sends notification 13 for status 3/21/22, otherwise 5. |
| `fn_800E8AA0` | 76 | 20 | 2 | Stores and returns service slot `54` status. |
| `fn_800E8AEC` | 132 | 20 | 7 | Calls service slots `3C` and `4C`, logs the latter result, then returns it. |
| `fn_800E8B70` | 100 | 20 | 2 | Passes the name and record group to service slot `20`, stores the status, and returns whether it differs from 19. |
| `fn_800E8BD4` | 36 | 0 | 0 | Tests the signed byte selected by the stored index in the byte group at `CF`. |
| `fn_800E8BF8` | 164 | 20 | 2 | Queries a limit, count, and current position; returns a signed byte indicating positive count and current position at or below the limit. |

The existing native record constructor establishes the `3B5C` record stride. The first two words of each record form the lookup pair used here. Records start at owner offset `D4`, so the next two pairs occur at `3C30` and `778C`. The private `Record` declaration includes a stride assertion. The three occupancy bytes at `D0..D2` and preceding byte `CF` are viewed as a four-byte group, accessed by the observed stored index; no new index checks are invented. Names are written through the pointer at `B2FC`. The private service class places its virtual dispatch pointer at the observed `30` offset. These views describe observed fields only and do not claim original field names or a complete owner layout.

Three source details mattered to exact output:

- An if/else assignment chooses the default string. Initializing the pointer first and conditionally reassigning it added one move instruction.
- `fn_800E8B70` returns native `bool`, written as `!(status == 19)`. Writing `status != 19` kept the restore of `r31` after the comparison sequence; the negated-equality expression emits the original earlier restore. Signed-byte or integer return declarations also added conversions. A bounded ten-expression, two-optimization probe preserves the compiler evidence under `return_probes/`.
- `fn_800E8BF8` uses an integer result local and converts to its signed-byte return. A signed-byte local allowed the compiler to remove the final extension that exists in the original.

The final production sources match all 1,332 code bytes, all 180 original exception/index bytes, and all 47 actual relocations. No weak functions, new literals, helper code, or other allocated output are emitted. Only actual undefined ELF symbols are published as dependencies; local exception symbols stay local.

Complete original exception-index, ctor, and dtor scans use `80015F60..8001F2C0`, `80299920..80299980`, and `80299980..802999A0`. Nine entries have exactly their owned original exception records; the two leaf helpers have none. No startup pointers occur. Every initialized data word pointing into these function extents is recorded with original object/table ownership, and existing compiled consumers are inventoried without changes. Original tables, strings, globals, and all intervening source extents remain with their prior owners. Each reconstructed function has a separate bounded split.

The frozen handoff is `scratch/game_engine_record_operations_continuation/handoff.json`; `final_integration.json` supplies exact ranges and symbol inventories. Source hashes and recursive quoted-header hashes are frozen; production units expand private views and have no quoted headers. `verify.py` recompiles all eleven production units and strictly checks every allocation, original byte, symbol extent, and resolved relocation. Central full DOL hash and regression checks remain pending integration.
