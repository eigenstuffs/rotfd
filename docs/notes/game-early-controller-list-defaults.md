# Early controller list defaults constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen batch145 recovers the genuine constructor at original fn800B53EC (1,028 bytes). It initializes five arrays, appends18 defaults to two word arrays and one default entry to the nested Handle array, Handle array and float array, then assigns its scalar. Ordinary member construction reproduces the full original cleanup table while retaining existing native destructor identities externally.

GC1.3.2 standard Gekko -O4,s -Cpp_exceptions on strictly matches1,028text+88EH/index bytes with57actual retained relocations and no weak code, non-EH data, BSS or padding. Full original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 ownership is verified.

Production uses native __ct__22ControllerListDefaultsFv. The original function and the sole accepted factory caller/header use the verified native identifier migration. Full active original ELF and initialized-word inventories and before/after caller allocated-byte/actual-relocation equivalence are frozen separately; the caller retains identical allocated bytes and resolved relocation targets. No alias or extra code allocation is proposed.

Frozen proof and migration inventory: scratch/game_engine_batch145/HANDOFF.md. Matching credit awaits complete-DOL acceptance by root.
