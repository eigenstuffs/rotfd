# Actor offset completion

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_actor_offset_finalize_800a10a4.cpp` reconstructs the 252-byte `fn_800A10A4`. It saves the actor state, adds the configured height to the pending offset, combines that offset with the current position, clears two wide actor flags, emits notification22, and completes the owner update. Ordinary vector addition methods preserve the original evaluation and reload ordering.

The isolated GC1.3.2 production build matches all252 code bytes, original8-byte exception table8000FDC0 and12-byte exception index8001B480. All5 retained actual relocations match. No weak helper, compiler literal pool, BSS, padding or other allocated data is emitted. The existing zero literal80378E40 and both external callees retain their owners and identities.

The verifier audits the complete original exception index80015F60..8001F2C0 and complete constructor/destructor tables, all initialized DOL data pointer words, current source consumers, and the sole new header consumer. The unchanged original callback table `lbl_802BBB2C` has its function pointer at802BBB38; its assembly ownership is preserved. No compiled source caller requires migration.

The adjacent136-byte A11A0 probe is private and uncredited: the final current source inventory found its accepted owner `owner_ground_control_800a11a0.cpp`. Existing source/header/configuration were untouched. Its initial diagnostic object and manifest remain in `scratch/game_early_actor_offset_finalize/private_already_owned_800a11a0/` and are excluded from the production manifest list.

The frozen handoff is `scratch/game_engine_batch150/HANDOFF.md`. Central production/native linking, original DOL SHA1 and regression checks remain required before matching credit.
