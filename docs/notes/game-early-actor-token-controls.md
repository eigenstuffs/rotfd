# Early actor token controls

Six isolated ordinary C++ routines recover 808 text bytes and 120 bytes of exception metadata/index. The dedicated source prefix is `early_actor_token_control_`, with header `include/Game/early_actor_token_control_views.h`. All use GC1.3.2, standard Gekko target, `-O4,s` and exceptions on. Central integration and complete DOL acceptance remain with the integrator.

| Address | Text bytes | Behavior |
| --- | ---: | --- |
| 800A5CF8 | 112 | Format an unsigned byte into a 128-byte stack token, then copy or append it to the output |
| 800B1670 | 112 | Same token append shape with its own original format and separator globals |
| 800B0CB0 | 152 | Parse a token and select one of three integer kinds from the original string comparisons |
| 800ABA70 | 136 | Resolve the actor handle and initialize a random scaled scalar |
| 800A8520 | 140 | Set a named counter, store setup state/variant/kind, select a scalar default and run followup initialization |
| 800AEFE8 | 156 | Set actor flag bits, query its related handle through virtual slot 0x9C, resolve it, and set its related flag |

The formatter signatures retain the unused first parameter and unsigned-byte third parameter, including the native variadic promotion. Verified fixed extents on the small external strings reproduce SDA addressing without introducing new storage. Original large string labels and all literal/description globals remain externally owned. Setup uses ordinary nested name-key construction and copy construction, matching both original stack stores.

The typed handle resolver extracts the signed 24-bit index before loading its manager and uses the existing signed generation byte getter. This source shape reproduces native resolution register allocation in both callers; no register forcing is used.

Each production object passes complete allocated-section comparison, actual relocation resolution, exact local exception symbol/extents, and full original extabindex (`80015F60..8001F2C0`), constructor (`80299920..80299980`) and destructor (`80299980..802999A0`) ownership scans. Each object contains its sole function, eight-byte exception entry and twelve-byte index. The batch accounts for 45 retained relocations and six nonallocated compiler metadata relocations, with no weak functions, owned data/literals/BSS/padding, aliases, or native identity migration.

Frozen evidence, original assembly snapshots, header consumer inventory and SHA256 hashes are under `scratch/game_engine_batch136/`. Private diagnostic probes remain preserved under `scratch/game_early_actor_token_controls/`.
