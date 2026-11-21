# Owner state, menu dispatch, and record copy

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Seven complete ordinary C functions match 608 bytes of original GSQE78 text in isolated production-source compilation. These partial text-only units own no original data, startup entries, or exception records. Full executable integration remains the integrator's acceptance step.

| Source suffix | Original function | Text range | Bytes |
| --- | --- | --- | ---: |
| `8020CE5C` | `fn_8020CE5C` | `8020CE5C..8020CEA8` | 76 |
| `8020ED58` | `fn_8020ED58` | `8020ED58..8020EDB0` | 88 |
| `8020EE10` | `fn_8020EE10` | `8020EE10..8020EE70` | 96 |
| `8021B800` | `fn_8021B800` | `8021B800..8021B860` | 96 |
| `8021C504` | `fn_8021C504` | `8021C504..8021C558` | 84 |
| `8021F518` | `fn_8021F518` | `8021F518..8021F568` | 80 |
| `80224C1C` | `fn_80224C1C` | `80224C1C..80224C74` | 88 |

Each source is `src/Game/engine_owner_small_<suffix>.c`; declarations and observed layouts are in `include/Game/engine_owner_small.h`. Compile with GC/1.3.2 and standard game flags, with no extra compiler options. All seven symbols retain global scope.

`8020CE5C` calls the existing owner reset, clears two words, and copies the mutable `game_vec2_zero` components. Declaring that global const incorrectly permits load scheduling that differs from the original; the declaration now agrees with its existing mutable definition. `8020ED58` clears an active byte and the resolved object's `0x10000` flag. `8020EE10` additionally sets an enabled byte. Both resolve signed 24-bit handle indices and signed 8-bit generations against 16-byte entries without adding bounds or null checks absent from the original.

`8021B800` forwards the selected 0x90-byte menu record with operation 2 or 1 according to its signed byte input. `8021C504` dispatches two explicit selected states while active, or the existing fallback while inactive. A C switch produces different control flow; ordinary if/else expressions match. `8021F518` copies the observed position, 64-bit flags, and trailing float triple into a 0x28-byte record, preserving the untouched padding fields. `80224C1C` invokes the existing owner operation and snapshots its 64-bit flags into offset 0x38 of the selected 0xA8-byte record.

The frozen handoff lives in `scratch/engine_owner_small_20261010at`: `final_integration.json`, `final_splits.txt`, `final_config.txt`, `scope_edits.txt`, `ownership_audit.json`, and `original_full_tables.json`. The strict verifier recompiles the current production source, requires complete allocated-section and function extents, preserves binding, applies all 13 real REL24/HA/LO/SDA21 relocations, and compares every text byte with the original DOL. No relocation bits are masked and no extra allocated bytes pass.

The ownership audit scans original extabindex `80015F60..8001F2C0` at stride 12, including all 3,141 records plus the descriptor and trailing zeros; ctors `80299920..80299980` at stride 4 (24 slots); and dtors `80299980..802999A0` at stride 4 (8 slots). None references these retained text ranges. Original neighboring functions and all existing data, external tables, global context, and exception/startup metadata stay with their existing owners. Complete original unit ranges are preserved in the audit.

Validation: production recompilation and strict relocation/extent/allocation comparison passed for seven functions, 608 text bytes, zero data bytes. Full original table audits passed. These isolated results do not claim central hash acceptance or increase progress before integration.
