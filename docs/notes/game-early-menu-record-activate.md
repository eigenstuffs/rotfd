# Menu record activation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_menu_record_activate_800ac70c.cpp` reconstructs the1072-byte `fn_800AC70C`. It finds a selected88-byte menu record, checks the active/timing/forced-selection gates, saves the record timer, updates the current device and logs the selection. It follows an optional next record, resets the current scene actor when requested, updates the service slot, conditionally notifies a related actor, destroys its related resource, and resets the scene/input state.

The ordinary source recovers the native helper boundaries: selected-key validation wraps a separate linear record search; service slot lookup returns a reference to the stored key; the actor notification captures the computed key before calling the record controller. Generation validation uses signed8-bit tags and signed24-bit indices. The source preserves all existing C entry identities and emits no native helper definitions.

The isolated GC1.3.2 production build matches1072 text bytes, original8-byte exception table80010E94 and12-byte index8001BD8C, with38 retained actual relocations including SDA slot globals. No weak helpers, compiler data pools, BSS, padding or other allocations are emitted. The diagnostic string8029EFF8, shared context, slot globals and zero vector remain external under their original owners.

The verifier audits the complete original exception index80015F60..8001F2C0 and complete constructor/destructor tables, all initialized DOL data pointer words, current source callers, and the sole new header consumer. Only the owned exception-index pointer refers to the recovered function; no compiled caller or external callback table needs migration.

The frozen handoff is `scratch/game_engine_batch151/HANDOFF.md`. Central production/native linking, original DOL SHA1 and regression checks remain required before matching credit.
