# Actor event forwarding and sentinel selection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ routines match all original allocated code and exception
metadata in fresh isolated production recompiles. Full-DOL linking and
promotion remain integrator checks.

| Entry | Text bytes | Exception table + index bytes |
| --- | ---: | ---: |
| `fn_80081630` | 248 | 8 + 12 |
| `fn_80081B74` | 160 | 8 + 12 |
| `fn_80083D1C` | 120 | 8 + 12 |

Total: 528 text bytes, 60 exception metadata bytes and 26 actual relocations.
Objects emit only `.text`, `extab` and `extabindex`; no extras, weak helpers,
initializer data, literals, padding, renames or verifier adapters are involved.

81630 accumulates float delta at owner +40 and periodically starts actor
callback38. Event8D dispatches the original control helper. The original actor
query starts callbackC directly or another nonzero callback when service byte
+2E is enabled, then forwards actor/delta to motion. 83D1C responds to event6E
through its original three-argument control helper, otherwise starts the actor
query callback when signed actor byte+40C is set. Both are first-probe exact.
Private owner views observe actor8,controlC,time40; actor callback storage is
+318. The service at global+164 and all constants remain externally owned.

81B74 forwards float delta to the actor phase/motion routines, accumulates
owner time40, initializes selector=-1, calls the existing callback-3 query for
its side effects, retains the original selector!=7 condition, and then starts
the selected callback unless it is3. Normal `-O4,s` propagation folds that
constant condition and emits144 bytes. The documented genuine compiler option
`-opt noprop` disables constant/copy propagation and emits exactly the original
160 bytes, including its sentinel initialization/test and r30/r31 allocation.
Every original instruction, metadata byte and actual relocation then matches.
The default probe and three inline-helper alternatives remain preserved as
uncredited research. `compiler_flag_evidence.json`, the primary compiler help
excerpt and bounded flag results document this finding. No statement, volatile
qualifier or assembly was added to force an instruction.

All units use GC1.3.2 with established `-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on` flags; only81B74 additionally uses `-opt noprop`. The proposed
configuration explicitly records that per-function partial split profile.
Original entry/dependency identities are preserved.

Original function extents and complete exception-index80015F60..8001F2C0,
ctor80299920..80299980 and dtor80299980..802999A0 tables were audited. Each
routine owns exactly one original exception record and no registration entry.
Existing external callback tables retain their assembly ownership. All
initialized data references and source/header consumer findings are recorded
in `ownership_audit.json`; dependencies include actual undefined ELF symbols
only. Other original functions/data from these translation units remain outside
these bounded partial splits.

`scratch/game_engine_actor_event_forwarding_continuation/final_integration.json`
contains exact ranges, symbols, flags, actual relocation and source/header hashes.
`final_splits.txt` and `final_config.txt` are proposals only. Every raw allocated
section and defined symbol is inventoried in `allocated_inventory.json`.
`verify.py` recompiles and strictly checks all original allocations; `handoff.json`
freezes sources, this note and isolated evidence. Central metadata, shared
headers, prior matching sources and frozen verifier cores remain untouched.
