# Early scene member event dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80059340` is reconstructed as ordinary C++ with its existing C entry and two arguments preserved. The seven sparse cases `26..2B` and `99` dispatch the corresponding four-byte member at owner offsets `2F8..310` through the global service at context `+158`. Its virtual table is observed at `+7C`; dispatch uses slot `54`, zero, and two default-constructed typed Handles. Every other input returns without dispatch. The private views describe these observed fields and virtual offsets only.

The exact retained ownership is text `80059340..800596BC` (892 bytes), extab `8000A4D4..8000A5F4` (288 bytes), and index `800180A8..800180B4` (12 bytes). The first production probe is exact with GC1.3.2 `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` and the established container base flags. There are 58 actual retained relocations and 11 discarded backup relocations. No string pool, other data, startup entry, native function rename, or shared declaration changes are needed.

The compiler emits backup `Handle_80020B90` destruction (116 bytes) and private `DispatchZero_59340` destruction (76 bytes), plus 72 bytes of backup EH/index. These 264 bytes receive no source credit. The accepted global strong destructor at `80020B90` was independently recompiled with its canonical flags, source and recursive header hashes, and all original allocated bytes and actual relocations verified against its production object. The unchanged strict weak/EH checker proves retained EH resolves to this strong owner. An actual isolated MWLD link proves selection of that original strong owner and complete discard of all six backup text/EH/index allocations; an incorrect fixture basename is rejected.

The complete original extabindex, ctors and dtors tables were scanned. Only the owned original index points into this function; no startup entries transfer. All initialized original data words were scanned, and the existing C identity and its compiled source/header consumers were recorded unchanged. The unit remains a documented partial original translation unit; all other original code and data ownership remains external.

Frozen evidence and proposed integration are in `scratch/game_early_scene_member_dispatch_continuation/`. `verify.py`, `native.py`, and `audit_tables.py` pass independently. This note records isolated acceptance only; the parent integrator must still perform the full DOL hash, baseline/regression, extent/progress, and repeated complete native audits before awarding source progress. All prior handoffs and verifier cores remain unchanged.
