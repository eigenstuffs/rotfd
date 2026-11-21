# Early actor token parsers

Five isolated ordinary C++ routines recover 1,684 text bytes and 100 bytes of exception metadata/index. Production source prefix is `early_actor_token_parser_`; the dedicated header is `include/Game/early_actor_token_parser_views.h`. All use standard GC1.3.2 Gekko `-O4,s` with exceptions on. Central integration and final DOL acceptance remain with the integrator.

| Address | Text bytes | Behavior |
| --- | ---: | --- |
| 800A59E0 | 524 | Skip opening tokens, collect byte-encoded named operations into a delimited output string until the closing token |
| 800A5BEC | 172 | Parse names into a caller-provided name-key array, incrementing an unsigned byte count |
| 800B1564 | 172 | Same name-key array parser with the second original delimiter pair |
| 800A1D44 | 356 | Query a related target, resolve behavior, compare its distance interval with the actor threshold, select controller states, then update the base owner |
| 800BE0E4 | 460 | Match six named screen kinds, update the selected kind and issue its corresponding log message |

Name hashing is expressed as an ordinary constructor and assignment; the temporary stack key, unsigned-byte postincrement, indexed store and next-token call match the original order. The distance query initializes its two floats individually, avoiding an unrelated compiler-generated aggregate template allocation.

Every original string/description/literal remains externally owned. The source retains original aggregate string-pool base references and constant offsets, including the existing global `agent_type_registry_CMsgBoxManipulator` base; it claims no data ownership and does not alter that symbol or its owner. These five objects each allocate only their sole function, eight-byte exception entry and twelve-byte index. No weak functions, owned literals/data/BSS/padding, aliases or native identity changes are emitted.

Strict verification passes every allocated byte, all 98 actual retained relocations, exact local exception symbols/extents and full original extabindex (`80015F60..8001F2C0`), constructor (`80299920..80299980`) and destructor (`80299980..802999A0`) ownership. Five additional compiler metadata relocations are nonallocated and inventoried. Header has five production consumers.

The adjacent 556-byte `800B1338` parser remains private and uncredited at 560 emitted bytes. Its offset-zero pool use introduces an extra pointer copy and changes an address-generation instruction; bounded pointer/reference/array/struct/getter variants did not close it. Its original code/EH/data remain outside all new source splits. Diagnostic history and full original assembly are preserved under `scratch/game_early_actor_token_parsers/`; the frozen inventory and handoff are under `scratch/game_engine_batch137/`.
