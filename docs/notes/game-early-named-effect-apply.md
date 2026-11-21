# Named effect apply

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8005C52C` resolves two related Handles, finds the named resource, and releases the returned temporary. If the existing global effect is present and valid, it calls virtual prepare38, virtual apply78 with the resolved target and named resource, then the existing finish operation.

Ordinary source `src/Game/early_named_effect_apply_8005C52C.cpp` matches420 text bytes plus8 original exception bytes8000ADBC and12 index bytes80018174. GC1.3.2 processor750/O4,s/exceptions on preserve the original noElfVector EH. A genuine private derived Handle return gives base cleanup0. Declaring the virtual target argument as an opaque resource pointer preserves original call argument order; a generic void pointer gave eleven scheduler/register differences. No register forcing is used.

All14 retained actual relocations and allocated ranges are verified. One unique unused weak return-wrapper destructor emits76 text bytes plus20 metadata bytes/four relocations; these remain uncredited and must be discarded in the final native link under the unchanged standard empty-strong weak EH route. No non-EH data/BSS/padding is emitted. The six-byte SDA Name80378608 and original global storage80377694 remain external and unchanged.

Full original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 scans pass. The complete initialized-word scan finds only the owned index. No existing source/header consumer uses this entry and no symbol migration is needed.

Frozen handoff `scratch/game_engine_batch170/HANDOFF.md`; repeat `python3 scratch/game_early_named_effect_apply/verify.py`. Fresh production hash and strict allocated-byte/actual-relocation checks pass. Central original-DOL hash, native helper discard and no-regression acceptance remain pending; no credit before integration.
