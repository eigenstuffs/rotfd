# Additional early lookup binders

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three isolated100-byte routines8005CDE4,8005D55C and8005DB28 look up the
original named Handle, bind it to the owner and initialize the owner. They reuse
the unchanged accepted early_lookup_bind_views.h and differ only in borrowed
original name strings8029B5B8,8029B670 and8029B728.

Fresh GC1.3.2,-O4,s,C++ exception production verification matches300text bytes,
72extab and36extabindex, all33actual retained relocations and complete original
exception/constructor/destructor table ownership. No weak/data/BSS/padding or
native identity migration. Frozen handoff: scratch/game_engine_batch123/HANDOFF.md;
full native acceptance remains central.
