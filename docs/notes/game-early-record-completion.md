# Early record binding, initialization and readiness

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three isolated ordinary C++ functions match their complete original emitted allocations with GC1.3.2, `-O4,s -Cpp_exceptions on`:

| Function | Text | extab | extabindex | Retained relocations |
|---|---:|---|---|---:|
| fn_80072D74 | 152 | 8000C878..8000C890 | 800192CC..800192D8 | 11 |
| fn_800738D0 | 552 | 8000C948..8000C960 | 8001935C..80019368 | 16 |
| fn_80073B38 | 168 | 8000C968..8000C970 | 80019374..80019380 | 6 |

The first binds the original named resource through a genuine returned Handle temporary, initializes the agent, sets flag17 and clears flag24. The second resets and binds another named resource, invokes the original virtual reset callback, writes six controller float fields through the original generation-checked Handle resolutions, sets flag17 and dispatches the paired 0x87 operations. Its nested assignment writes field250 before field22C. The third gates on the original readiness query and invokes controller virtual slot5 when its Handle is valid.

Production sources are `src/Game/early_record_completion_80072d74.cpp`, `early_record_completion_800738d0.cpp`, and `early_record_completion_80073b38.cpp`; declarations are in dedicated `include/Game/early_record_completion_views.h`. Each unit emits precisely one function, one local compiler extab symbol and one local compiler extabindex symbol. The two genuine Handle-return expressions retain their original external destructor references in both text and EH24. No weak helpers, external literals, BSS, padding, aliases or identifier migration are owned here.

Frozen manifests: `scratch/game_engine_batch100/manifest-list.json`. Per-unit strict verifiers recompile production source, account for every allocated section and actual relocation, apply real SDA/PowerPC relocations, compare all bytes to the normalized original DOL, and audit complete original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0. Each function retains exactly its original EH entry and no constructor/destructor slot. This is isolated evidence pending central original-DOL acceptance, not a claim of a complete original translation unit.

The adjacent fn8007256C completion loop remains private and uncredited with four or five volatile register differences; see `scratch/game_early_record_completion/FINDINGS.md`. Its original text/EH ownership is unchanged.
