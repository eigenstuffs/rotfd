# Callback flag constructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Three complete 104-byte functions at `8025988C..802598F4`,
`80259968..802599D0`, and `8025AC88..8025ACF0` reconstruct ordinary
callback construction and 64-bit flag updates. Each calls its original base
initializer, installs its original table pointer at `+08`, updates the
observed state field at `+38`, and returns the receiver. The prefix declaration
covers observed fields and does not claim the original complete class layout.

`8025988C` clears flag 4 and sets flag 8; `80259968` sets flag `20` and
clears flag `200`; `8025AC88` sets flag 2 and clears flag `200`. Native
64-bit C++ expressions reproduce the original high/low word accesses and
constant-mask operations. Original base functions and table data retain
external ownership.

`scratch/game_callback_flag_setup/verify.py` recompiles each frozen source
and checks all allocated bytes, three complete global function extents and
nine actual relocations. All 312 text bytes match with no extra helpers,
initialized data, BSS, exception records, or padding. Central integration
also audits the full original exception and startup tables before acceptance.

The base setup probe at `8025A58C` still has register-allocation differences
and remains uncredited. The earlier startup probe at `802598F4` had ten
differing words; its exact reconstruction is now accepted separately in
[callback startup wrappers](game-callback-startup.md). Historical probes are
preserved alongside the successful constructors.
