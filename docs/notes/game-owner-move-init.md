# Owner move initialization

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ `fn_80227A14` matches all 244 original bytes at `80227A14..80227B08`, including 11 actual relocations. Source: `src/Game/owner_move_init.cpp`. Verifier: `python3 scratch/game_owner_move_init/verify.py`; standard GC/1.3.2 Game flags, no new headers/symbols/flags.

After base initialization fn_80220754, it assigns a one-zero-layer empty temporary to handle168 and a two-layer empty temporary to handle174. It sets key170 to -1 and states178/17C to zero, then enables low flag masks 2E00 and 2. Genuine temporary lifetimes reproduce release/copy/retain and cleanup. The flags field is 64 bits at 30; the compiler emits only the changed low-word operations. Describing flags as a 32-bit word produces three differing epilogue restore instructions even though the body matches.

All 416 allocated text bytes are accounted: 244 retained plus two unreferenced weak destructor backups totaling 172. Full raw bytes and actual relocation identities are checked, no retained references to helpers exist, and final ELF helper absence is required. No data/BSS/padding is emitted. Complete original exception/constructor/destructor table allocations and padding are audited with no ownership or retained references. Frozen evidence is in `scratch/game_owner_move_init/`. Central full-DOL/native-objdiff, extent/regression and helper absence checks establish final acceptance.
