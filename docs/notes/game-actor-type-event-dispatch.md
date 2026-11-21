# Actor type event dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_800C3778` reconstructs `800C3778..800C3934` (444 text bytes) as an ordinary sparse switch over actor type and action. Enabled actors dispatch events C6/C8/C9/CB/CC through the existing scene event service; type2 additionally toggles its state between0 and1 for actions2/3. The related object pointer remains at24, enabled signed byte28, type2C, state574.

GC1.3.2 Gekko O4,s with exceptions enabled reproduces the entire production object:444 text +8 extab (`80012950..80012958`) +12 extabindex (`8001CCBC..8001CCC8`), actual local symbols @47/@48,30 actual relocations, no backups or additional allocations. The750 processor setting matches text but emits00080000 instead of native000A0000 in the exception descriptor; Gekko restores the original descriptor without source tricks.

Full original extabindex/startup tables, all initialized executable words and5,565 active object inputs were audited. The sole initialized pointer into this function is its owned extabindex entry. Four active object references and two existing compiled-source consumers retain the original C identifier/address; no identity migration is required. Original context, event function and float literal stay external. No jump table, pool, BSS, padding or startup ownership transfers.

Frozen isolated handoff: `scratch/game_engine_batch219/HANDOFF.md`. Root owns central integration and final original-DOL acceptance; this note is updated after acceptance.
