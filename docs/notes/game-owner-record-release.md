# Owner indexed record release

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ `fn_802269F4` matches all 248 original bytes at `802269F4..80226AEC`, including 10 actual relocations. Source: `src/Game/owner_record_release.cpp`. Verifier: `python3 scratch/game_owner_record_release/verify.py`; standard GC/1.3.2 Game flags, no new headers/symbols/flags.

When owner key170 is nonnegative, the routine indexes its 0xA8-byte records at 188 and resolves the record's handle40. It retains a one-zero-layer temporary copy of the resolved object's handle20, calls service150 fn_801E5724 on the record handle, calls fn_801E5C1C with the key and temporary, then releases the record pool slot through fn_80209DF8(state180,index). The temporary is released at scope exit. Concrete record extent, nested handle lifetime and manager/service layout reproduce the original exactly.

All 420 allocated text bytes are accounted: 248 retained plus two unreferenced weak destructor backups totaling 172. Full raw bytes and actual relocation identities are checked with no retained helper references; final ELF helper absence is required. No data/BSS/padding is emitted. Complete original exception/constructor/destructor table allocations and padding are audited with no ownership or retained references. Frozen evidence is in `scratch/game_owner_record_release/`. Central full-DOL/native-objdiff, extent/regression and helper absence checks establish final acceptance.
