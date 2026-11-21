# Service slot key registration

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_service_slot_registration_800bc8dc.cpp` reconstructs the 992-byte `fn_800BC8DC` setup routine. It obtains the context's service at offset164, creates nine record-array slots, stores their indices in the existing globals `lbl_803777AC..lbl_803777CC`, registers each slot's key mappings, and selects the configured default slot. The explicit registration calls preserve the original initialization order and external configuration storage.

The isolated GC1.3.2 production build matches all 992 code bytes, 8-byte original exception table at80012030, and 12-byte original exception index at8001C794. All 98 retained relocations are applied using actual PowerPC semantics, including SDA relocations to existing global slot indices. The compiler emits one nonallocated category relocation. No weak helpers, literal pool, BSS, padding or other data are emitted. Standard O4,s/exceptions flags apply.

The verifier audits the complete original exception index80015F60..8001F2C0 and complete constructor/destructor tables. An initialized-data scan finds only the original exception-index pointer to the retained code. The existing caller `engine_scene_owner_construct_800B79A4.cpp` remains unchanged, and the original `void(void*)` entry identity is preserved. All callees and nine index globals stay under their established owners.

The frozen handoff is `scratch/game_engine_batch149/HANDOFF.md`. Central production/native linking, original DOL SHA1 and regression checks remain required before matching credit.
