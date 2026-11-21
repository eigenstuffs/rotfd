# Owner base motion reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ `fn_80220608` matches all 332 original bytes at `80220608..80220754`, including 13 actual relocations. Source: `src/Game/owner_base_motion_reset.cpp`. Isolated verifier: `python3 scratch/game_owner_base_motion_reset/verify.py`; standard GC/1.3.2 Game flags, no new header/symbol/flag requirements.

The routine calls virtual reset slot D4 with index zero, clears movement144 and velocity150 using the external zero vector, then assigns a two-layer empty handle to 68 and a three-layer empty handle to 28. It masks the 64-bit flags30 with 3F, overwrites the field with C000, and stores the external default value at D0. Genuine nested handle lifetimes and the 64-bit flag type reproduce all native operations, including redundant flag stores retained by the original compiler.

All 596 allocated text bytes are accounted: 332 retained plus three unreferenced weak destructor backups totaling 264. The verifier checks complete emitted bytes and actual relocation identities, verifies no retained references to the backups, and requires final ELF helper absence. No data/BSS/padding is emitted. Original extabindex/ctors/dtors ownership audits pass. The manifest/evidence are frozen in `scratch/game_owner_base_motion_reset/`. Final acceptance requires central full DOL hash/native objdiff, extent/regression and weak helper absence checks.
