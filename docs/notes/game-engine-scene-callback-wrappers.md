# Scene callback registration and lookup wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twelve ordinary C++ wrappers are strict isolated byte matches in fresh
production recompiles. Full original DOL acceptance remains the parent
integrator's responsibility.

| Entry | Text | Exception table + index | Actual relocations |
| --- | ---: | ---: | ---: |
| `fn_8004084C` | 32 | 8 + 12 | 3 |
| `fn_800438F4` | 64 | 8 + 12 | 5 |
| `fn_800439D8` | 76 | 8 + 12 | 5 |
| `fn_80043C20` | 64 | 8 + 12 | 5 |
| `fn_80043C60` | 76 | 8 + 12 | 5 |
| `fn_80043D48` | 64 | 8 + 12 | 5 |
| `fn_80043D88` | 76 | 8 + 12 | 5 |
| `fn_80043E70` | 64 | 8 + 12 | 5 |
| `fn_80043EB0` | 76 | 8 + 12 | 5 |
| `fn_80043F98` | 64 | 8 + 12 | 5 |
| `fn_80043FD8` | 76 | 8 + 12 | 5 |
| `fn_80044448` | 76 | 8 + 12 | 3 |

Total: 808 original code bytes, 240 original exception bytes and 56 actual
relocations. The GC 1.3.2 compiler and established `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` profile are unchanged. All emitted allocated
bytes, symbols, compiler categories and actual resolved relocations are
accounted. There are no extras, weak helpers, pools, padding or new gates.

Five 64-byte registration wrappers call the existing callback operation with
an original SDA pointer, then invoke the accepted common registration chain
fn_80043934 with the unchanged owner and value. Their five adjacent 76-byte
lookup wrappers query the same original SDA pointer and return its integer
result if it is not -1, otherwise return the accepted fn_80043A24 fallback
chain. This genuine integer return preserves the observed redundant early
return branch and live result ABI. Source identities, call signatures and
external SDA data ownership remain unchanged. Every pair has a physically
bounded source unit for each original function, without spanning text gaps.

8004084C forwards the owner pointer to existing fn_8025A324. 80044448 tests bit
17 in the observed 64-bit owner flags at +38. If clear it resets the signed
active byte at +68 and invokes existing fn_8025ECB4. The private view leaves
all other fields opaque. Every ordinary source matched its first probe.

`ownership_audit.json` scans complete original extabindex
80015F60..8001F2C0, ctor table 80299920..80299980 and dtor table
80299980..802999A0. Each wrapper owns exactly its original exception record;
none has startup or termination references. All initialized-data references
and unchanged compiled source/header callers are inventoried. Original callback
tables, SDA pointer objects and other translation-unit data retain assembly
ownership. Dependencies are restricted to actual undefined ELF symbols.

The fresh namespace is `scratch/game_engine_scene_callback_wrappers_continuation`.
`final_integration.json` pins source hashes, flags, sections, symbols and actual
relocations; `allocated_inventory.json` records every emitted allocation and
defined symbol. `verify.py` recompiles the exact production sources and checks
all code/metadata without relocation masking. No central metadata, shared
header, accepted source, frozen handoff or verifier core was modified.
Split/config files are integration proposals only.
