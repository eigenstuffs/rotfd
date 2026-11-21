# Nested record array owner destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801CEED0` reconstructs `801CEED0..801CF59C` as1,740 bytes of ordinary C++ source. It destroys ten arrays in the original order, including a two-layer wrapped Handle array and two arrays of nested array records. The nested word record has12 bytes; the nested short record has20 bytes. Genuine derived classes reproduce both nested destructor checks and the original counted inner loops. Trivial element widths are12,4,12,8,16,80 and36 bytes. It then restores the base virtual table, invokes the existing base destructor and conditionally frees the owner.

The first GC1.3.2 Gekko O4,p compile with exceptions disabled matches every allocated byte and all45 real relocation targets. Only the1,740-byte primary text is emitted: no helper, exception, literal, data, BSS or padding allocation is present.

The full original exception/startup table scan finds no owned entry. The active5569-object/119086-relocation census and all777360 initialized DOL words were scanned, distinguishing instruction values from data pointers. The sole initialized data pointer802EA390 remains owned by original `lbl_802EA388` (802EA388..802EA3E8,96 bytes); both original virtual tables and all callee identities remain external and unchanged. There is no existing source consumer or identifier migration.

The frozen manifest, production and independent compiler proof, actual relocation inventory, table/data ownership audit, active object snapshot and proposed split/configuration are in `scratch/game_nested_record_arrays_destroy_801ceed0`. Root full native placement, original DOL hash and regression acceptance remain pending.
