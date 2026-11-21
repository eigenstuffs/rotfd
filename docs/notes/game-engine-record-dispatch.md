# Record action and countdown dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C entries preserve their existing identifiers and compile with GC 1.3.2 and the established `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags. Both matched on their first probes, including actual relocations and their original exception/index records.

`fn_800E8FF4` occupies `800E8FF4..800E9240` (588 code bytes). It queries existing callback keys `C4`, `C5`, `DA` and `DB` in an if/else chain to select service mode 0–3. It then checks further keys, calls the original resource routine with the observed identifiers, and sets the corresponding record flags. The query for `C7` remains even though its result is unused, as do the final `C2` and `E2` queries. It owns its eight-byte exception record and twelve-byte index and has 41 actual relocations.

`fn_800EA1D8` occupies `800EA1D8..800EA364` (396 code bytes). It subtracts elapsed time from owner float `10`, and below the original threshold dispatches the record service status. Case zero uses the existing result query and original ordered flag tests to select notifications; case one selects notification 7 or 6. Cases 20, 23 and 3/21 send notifications 8, 9 and 12. All other statuses leave the function through its original default path.

Its ordinary switch emits the exact original 24-entry, 96-byte jump table at `802C91E8..802C9248`. The compiler-local object is `@39`; the provisional original table identifier is `jumptable_802C91E8`, local in the symbol table, with no compiled source consumer. All 24 real address relocations point to this function with exact original, bounded instruction offsets. `jump_table_audit.json` inventories every case/target/relocation and the original table hash. This table transfers to the source unit along with the function; the neighboring tables and literals retain their original owners. The function's other allocations are its eight-byte exception record and twelve-byte index, totaling 41 actual relocations across its four owned sections.

Private layout views continue the established record offset and `3B5C` stride evidence. The global context resource, record and service pointers occur at `15058`, `1505C` and `15060`. Notifications use owner pointer `08` plus offset `20`; the record pointer is `0C`. Signed-byte query declarations preserve the observed extensions at callers. In particular the existing `fn_800EA364` producer returns only zero or one; its frozen source and bytes remain unchanged.

All 984 code bytes, 40 exception/index bytes, 96 table bytes and 82 actual relocations match in final production objects and an independent strict recompile. No weak helpers, new strings, trailing alignment or other allocated output is emitted. The manifest accounts for every compiler allocation and publishes actual undefined symbols only. Production files expand their private declarations and have no quoted-header dependencies.

Full exception-index, ctor and dtor scans use `80015F60..8001F2C0`, `80299920..80299980` and `80299980..802999A0`. Each function owns exactly its original exception/index pair and neither has startup pointers. `ownership_audit.json` distinguishes the transferred jump-table references from original tables remaining in assembly and inventories unchanged compiled function consumers. Original data outside the explicit table range remains outside these bounded function units.

`scratch/game_engine_record_dispatch_continuation/handoff.json` freezes the sources, strict verifiers, objects and evidence. `final_integration.json` supplies exact code, data and EH/index ranges, symbols and flags; `verify.py` recompiles and strictly checks all allocations, original bytes, symbol extents and resolved relocation targets. Central original-DOL and regression acceptance remains pending integration.
