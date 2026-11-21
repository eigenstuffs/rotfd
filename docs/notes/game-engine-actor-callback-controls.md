# Actor callback control family

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary C++ functions are exact in isolated production-source recompiles.
Full DOL linking and promotion remain integrator checks. No existing matching
source, central metadata, shared declarations or frozen verifier was changed.

| Entry | Text bytes | Exception table + index bytes |
| --- | ---: | ---: |
| `fn_8008A284` | 380 | 8 + 12 |
| `fn_8008A5A8` | 432 | 8 + 12 |
| `fn_8008B1AC` | 356 | 8 + 12 |
| `fn_8008B8D0` | 380 | 8 + 12 |
| `fn_8008BD0C` | 352 | 8 + 12 |

The total is 1,900 original text bytes, 100 original exception metadata bytes
and 69 actual relocations. Every first ordinary probe and fresh production
recompile matches all emitted allocations, using GC 1.3.2 with the established
`-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags. Each object emits
only `.text`, `extab` and `extabindex`. There are no extra weak functions, data,
literal pools, BSS, padding, identifier migrations or verifier adapters.

The private observed owner view holds actor and control pointers at +8/+C.
The actor callback controller is embedded at +318. The control object has an
8-byte nonvirtual prefix, followed by its native vptr; slot +68 dispatch uses
ordinary virtual declarations. Event-selected callback queries consume signed
byte results, preserving the original `extsb` tests. The accepted controller
query/start bodies at 8007D604/8007D6A0 establish their signed-char return values.
The event lookup at 8025E9FC returns only 0/1; the signed-byte declaration here
preserves its original caller consumption and current external identity.

A284 selects control 81, then starts actor callback E when any original listed
callback is active. A5A8 selects controls 82/84 and starts callback 10 or the
original actor query result. B1AC selects controls 83/84 and starts callback
11 or 30. BD0C selects control 84 and starts callback 2C, 2D or 2E. Their
short-circuit query order is preserved directly in ordinary conditions.

B8D0 selects control 81/84 and handles actor signed byte +411. Its callback-6
branch clears owner state +40, phase +44, byte +49 and scalar fields +50/+54,
then clears bit 31 of the actor's 64-bit flags at +30. Other branches start
callbacks 24/25 and update the pending byte/phase. All other storage remains
opaque; these views establish only observed offsets, not full class sizes.
The original scalar constant at 80378AD0 stays externally owned.

The complete original exception-index table 80015F60..8001F2C0 was scanned at
stride 12; each routine owns exactly its listed 8-byte exception table and
12-byte index. Full ctor 80299920..80299980 and dtor 80299980..802999A0 scans
found no startup or termination pointers. Original assembly function extents
were independently checked. Each entry also appears at +1C in an original
32-byte external callback table: respectively 802B8AF0, 802B8AA0, 802B8A6C,
802B8A04 and 802B89D0. Those original table owners remain unchanged. No compiled
source/header consumer of these five entry names was found. Dependencies list
only actual undefined ELF symbols, excluding local exception metadata.

`scratch/game_engine_actor_callback_controls_continuation/final_integration.json`
contains exact owned ranges, local exception symbols, source/header hashes,
flags and real relocation records. `final_splits.txt` and `final_config.txt`
are proposals only. `ownership_audit.json` records all original table references
and scans; `allocated_inventory.json` inventories every allocated section,
raw hash and defined symbol. `verify.py` performs a fresh strict recompile.
`handoff.json` freezes this note, sources and all isolated evidence.
