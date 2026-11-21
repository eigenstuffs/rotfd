# Bound curve owner stream and application

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Separate ordinary source units reconstruct fn801AEFF4..801AF078132-byte stream reader and fn801AF078..801AF18C276-byte application wrapper. The reader registers the original Handle, reads its two-byte identifier, and forwards one vector and two scalar member tracks to existing curve readers. The application resolves its argument Handle against typed16-byte entries, samples the two scalar properties@84/88, and forwards sampled vector output to virtual slot34.

Both probes match on first compilation. The resolver caches the typed Entry array and uses an int-return signed-byte tag accessor. Function-scope Vector, first scalar and second scalar declarations naturally place outputs at native stack10/C/8. No manual register assignment or artificial storage is used.

GC1.3.2 Gekko/O4,p production and fresh unchanged-core strict recompiles verify all408 allocated text bytes and12 actual relocations (7/5). No helpers/data/pools/BSS/padding/EH/startup allocations. Current identities/full1,673-canonical/43,775-body preflight passes. Stable5,591-object/119,086-actual-relocation/777,360-word original audit pins each input and verifies config/objects unchanged throughout; two original entryrefs/direct callers, no aliases/pointers. Full original table ownership checks have no references. No existing header/caller/identity migration.

Evidence scratch/game_bound_curve_owner_apply_801aeff4; frozen handoff scratch/game_engine_batch249. Central/native acceptance pending.
