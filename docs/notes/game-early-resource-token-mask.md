# Resource property token decoding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_resource_token_mask_800b7ffc.cpp` reconstructs the 780-byte method at 800B7FFC. It maps resource property names to encoded unsigned flags using the original ordered `strcmp` chain. The first argument is an unused object pointer. The step-sound names return encoded field values rather than independent bits; an unrecognized name returns zero.

All strings retain their existing external allocation and identities: the registry pool `agent_type_registry_CMsgBoxManipulator` at 802A06D8 and the two small strings `lbl_803793A0`/`lbl_803793A8`. The source emits no string or other non-EH data. Its final conditional compiles to the original integer mask sequence.

The isolated GC1.3.2 O4,s/exceptions-on production object exactly matches 780 code bytes, eight EH bytes at 80011B70 and 12 index bytes at 8001C1AC, including all 32 actual allocated relocations. Every emitted allocation is accounted for; no helper code, BSS or padding is emitted. The two compiler-local metadata objects are `@59` and `@60`. The dependency inventory selects undefined ELF symbols by section index before resolving their names, so those local objects cannot be confused with original global symbols with the same spelling.

Full original exception-index and startup-table scans pass. The complete initialized-data word scan finds only the owned index and an original callback entry at 802BEFB8 within the external 88-byte `lbl_802BEF98` table. That original table and its global identity remain unchanged. No compiled source caller or shared declaration requires migration. Matching credit waits for root integration, original DOL hash and regression acceptance.

Frozen handoff: `scratch/game_engine_batch157/HANDOFF.md`. Repeat proof: `python3 scratch/game_early_input_token_mask/verify.py`.
