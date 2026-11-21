# Owner motion preparation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ `fn_80228ECC` matches all 460 original bytes at `80228ECC..80229098`, including 17 actual relocations. Source: `src/Game/owner_motion_prepare.cpp`. Verifier: `python3 scratch/game_owner_motion_prepare/verify.py`; standard GC/1.3.2 Game flags, no new headers/symbols/flags.

The routine assigns input handle90 into owner180, retains a three-layer temporary copy of input handle8C and assigns it into owner184, then releases that copy. It transfers duration4, bounds28/2C, damping8 and movement5C into owner170/178/17C/174/144; sets velocity150 to external zero/input speed0/zero; and enables flag bit35. It passes a retained two-layer copy of owner184 to fn_80038098, clears the motion target through fn_80229728 with a four-layer empty temporary, then calls virtual slot118(1,0).

Named three-layer and two-layer temporaries reproduce stack10/C while the empty argument occupies8. An inline scalar velocity helper evaluates input speed before its destination stores and reproduces native float register allocation. The input pointer's mutable type is material: a const input moves its handle load before zero initialization and changes seven instructions; mutable input closes the full original extent. The source does not directly write input fields.

All 1,008 allocated text bytes are accounted: 460 retained plus six unreferenced weak destructor backups totaling 548. Their complete raw bytes and actual relocation identities are checked with no retained helper references; final ELF helper absence is required. No data/BSS/padding is emitted. Complete original extabindex 80015F60..8001F2C0, constructor 80299920..80299980 and destructor 80299980..802999A0 allocations and padding are audited directly with no ownership or retained references. Frozen evidence is in `scratch/game_owner_motion_prepare/`. Central full-DOL/native-objdiff, extent/regression and weak helper absence checks establish final acceptance.
