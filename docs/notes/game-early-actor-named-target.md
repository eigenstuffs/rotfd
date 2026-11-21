# Actor named target

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8008BB40` resolves the record's Handle at64 and the related object's Handle at1F0, looks up a resource by the existing Name, writes the returned object pointer to the actor at428, then resolves the actor's Handle at24 and writes state88=5.

Ordinary source `src/Game/early_actor_named_target_8008BB40.cpp` matches368 text bytes,8-byte exception record8000E48C and12-byte index8001A4C0. GC1.3.2 processor750/O4,s/C++ exceptions on reproduce the original noElfVector exception flag. A genuine private derived Handle return object preserves base destructor argument0 and the full-expression cleanup after the pointer assignment. The eight retained actual relocations are verified in their allocated sections.

One unique unused weak return-wrapper destructor emits76 text bytes plus20 metadata bytes/four relocations. The unchanged standard empty-strong weak-EH verifier accounts for these uncredited allocations; final native linking must discard them. No extra data/BSS/padding or shared identity migration is introduced. The original seven-byte SDA Name string80378B64 remains external.

Complete original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 were audited. The initialized-word scan finds only the owned index and unchanged pointer802B89DC in original32-byte tablelbl802B89D0. No existing source/header consumer uses this entry; its original C identity remains.

Frozen handoff `scratch/game_engine_batch169/HANDOFF.md`; repeat `python3 scratch/game_early_actor_named_target/verify.py`. Isolated fresh production/allocation/relocation verification passes. Central original-DOL hash, native helper discard and no-regression acceptance remain pending; no credit is claimed before integration.
