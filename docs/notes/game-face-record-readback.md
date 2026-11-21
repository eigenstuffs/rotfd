# Face record readback

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The complete ordinary C++ entry `fn_80242C70` matches all 468 original bytes at `80242C70..80242E44`, including each actual relocation. After the original query succeeds, it accepts face records with at most four indices, copies each unsigned short index and corresponding 68-byte record into the output, then copies and retains the owner handle into that output. A negative face count follows the original empty-loop behavior.

The record contains eleven floats, four unsigned shorts and four final floats; explicit assignment preserves the original scalar load/store operations. Typed array accessors reproduce the original index-loop register lifetimes. The owner handle is copied through four zeroing layers into a temporary, assigned with release/copy/retain, and destroyed. A source-member reference preserves the original address across construction. These private partial layouts express observed fields and do not establish complete original class identities.

Source: `src/Game/face_record_readback.cpp`; standard GC/1.3.2 Game flags. Only this complete text range is owned. No data, BSS or padding is emitted. All unused trailing weak cleanup backups are separately inventoried by full extent, binding, raw hashes and actual relocations; retained code has no references to them, and they must be absent from the final ELF. Original query code, shared manager, allocator data and adjacent text remain externally owned.

Frozen isolated evidence is in `scratch/game_face_record_readback/final_integration.json` and `verify.py`. The strict verifier compares every allocated retained byte after actual relocation application and accounts for all emitted functions. Full-table ownership, executable hash, baseline, generated progress and repository tests are central acceptance requirements.
