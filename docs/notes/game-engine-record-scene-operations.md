# Record scene operation family

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated handoff is `scratch/game_engine_record_scene_operations_continuation/final_integration.json`. It freezes 15 original C-entry functions, their complete extab/index records, and source/recursive-header digests. Central native linking and backup discard proof remain required.

Total retained output is 6,908 text bytes plus 840 exception/index bytes, with 329 actual retained relocations. Compiler is GC 1.3.2 with the established container-base flags, including `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. No native identity migration, source alias, assembly body, static data transfer, or compiled consumer edit is proposed.

| Original entry | Text bytes | Actual retained relocations | Observed operation |
| --- | ---: | ---: | --- |
| `fn_800EE684` | 520 | 25 | notify 6, then lbl_802AB478 operation 11 |
| `fn_800EF060` | 520 | 25 | notify 6, then lbl_802AB5E0 operation 3 |
| `fn_800EF514` | 520 | 25 | notify 6, then lbl_802AB5F8 operation 2 |
| `fn_800EA910` | 440 | 22 | notify 0; stop; restore Handle/key |
| `fn_800EB0D4` | 448 | 20 | refresh scene record; notify 0; stop; restore Handle/key |
| `fn_800EB59C` | 448 | 23 | notify 0; stop; restore Handle/key; record reset |
| `fn_800ECC18` | 448 | 20 | refresh scene record; notify 0; stop; restore Handle/key |
| `fn_800ED0F4` | 448 | 20 | refresh scene record; notify 0; stop; restore Handle/key |
| `fn_800ED59C` | 448 | 20 | refresh scene record; notify 0; stop; restore Handle/key |
| `fn_800EDA78` | 448 | 20 | refresh scene record; notify 0; stop; restore Handle/key |
| `fn_800EDFE4` | 448 | 20 | refresh scene record; notify 0; stop; restore Handle/key |
| `fn_800EE468` | 440 | 22 | notify 0; stop; restore Handle/key |
| `fn_800EE944` | 440 | 22 | notify 0; stop; restore Handle/key |
| `fn_800EEE38` | 452 | 23 | notify 0; stop; restore Handle/key; record reset |
| `fn_800EF2F8` | 440 | 22 | notify 0; stop; restore Handle/key |

The three setup functions select the scene record, save the current service key, apply a genuine full-expression Handle copy, conditionally notify the related object with message 6, and then perform a named scene operation. The `Name` view holds one interned string word: an actual constructor call creates the first temporary, and an inline copy constructs the argument object in a second stack slot. The observed operation IDs are 11, 3, and 2 respectively.

The cleanup functions optionally refresh their current scene record, conditionally notify message 0, stop the scene operation, pass a copied Handle by pointer in a full expression, and restore the saved service key. EB59C additionally calls the record cancellation routine E88EC; EEE38 additionally disables E8744 with argument zero. These are distinct original function extents, not source-generated aliases.

Private layouts and native Handle identities follow the verified notification pair (`game-engine-record-handle-notify.md`). Accessed record/scene/context fields use opaque gaps; these views do not claim full class extents. The inline nested resolver uses the established signed 8/24-bit Handle union, 16-byte entry stride, object offset 0, generation byte C, and manager entries offset 8. Its second lookup uses a distinct byte-backed manager view to preserve the native repeated array load. The third Handle resides at offset 70 of the resolved child and dispatches through receiver offset 318. All retained bytes and actual relocation targets, including inline Handle cleanup references in EH, match the original.

Each input object additionally emits one weak native `__dt__15Handle_80020478Fv` backup (112 text bytes, 40-byte extab, 12-byte index, seven actual backup relocations). The retained exception record references that native destructor once. The guarded opt-in verifier independently recompiles and verifies the already accepted strong original owner at 80020478, checking canonical/source/recursive-header hashes, production digest, every allocation, and actual relocation targets. Across the 15 inputs, 1,680 backup text bytes and 780 backup metadata bytes with 105 relocations are inventoried and uncredited. Every weak binding, raw extent/hash, backup metadata group, and real retained strong resolution appears in `weak_override_audit`. Central native ELF/map acceptance must prove all these input backups and their EH/index groups discarded while the original strong owner remains at its original address.

The complete original extabindex table (`80015F60..8001F2C0`, stride 12), constructors (`80299920..80299980`, stride 4), destructors (`80299980..802999A0`, stride 4), and all initialized data words were scanned. Each function has exactly one owned 44-byte exception record and 12-byte index, and no constructor/destructor table entry. Original function lengths were independently checked against the complete native assembly body. Original assembly-owned callable tables remain unchanged. EA910 is referenced by two such tables, lbl_802C959C and lbl_802C95B4; the other units each have one original table entry. `ownership_audit.json` lists every table owner/address/extent/entry and all unchanged compiled source consumers with hashes. The initial freeze assumed one callable entry per function, stopped before emitting a final manifest on EA910's second entry, and is preserved as `freeze-first-attempt.py`; the completed audit explicitly accounts for both original references.

Six related operation-before-notification setup probes (EA640, EAE50, EC93C, ECE3C, ED318, ED7C0) remain private and uncredited. Their 520-byte bodies and actual relocated text differ in four saved-register operands for the final Handle pointer. `initial_probes`, `report.json`, and `scope_variants/results.json` preserve the bounded evidence. Twelve ordinary pointer/reference/local/helper/Name-copy variants did not resolve this allocation choice. No production source or ownership transfer for these six is included.

`verify.py` independently recompiles all 15 expanded production sources and checks their frozen hashes, complete emitted symbol/section inventories, raw backup hashes, every retained original byte, actual relocations, original strong-owner proof, and exact EH/index pointer types and addends. All passed. Shared symbols/splits/configure/headers, expected hash, original inputs, progress, full builds, and all previous accepted/frozen artifacts were untouched by this isolated tranche.
