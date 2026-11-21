# Sparse action owner destruction

Isolated ordinary C++ proof: fn80263B08 at 80263B08..80263DDC, 724 text bytes. Source and declarations are src/Game/engine_sparse_action_owner_destructor.cpp and include/Game/engine_sparse_action_owner_destructor.h. This frozen handoff awaits central full-DOL acceptance.

The recovered entry destroys four trailing scalar Handles, a 144-Handle fixed array, occupied 12-byte records, the BitSet, another scalar Handle, and two dynamic Handle arrays. Positive deleting flags release the owner; the original entry returns its owner pointer. Empty Handle-derived layers reproduce the observed member null checks. The sparse-record loop requires an unsigned record subscript while its signed loop counter controls BitSet indexing; ordinary signed array subscripts reproduce the other two array loops. A const word-reference getter retains the original explicit Boolean normalization.

GC/1.3.2 O4,p with exceptions off and -use_lmw_stmw on emits exactly one global 724-byte C entry, no weak helpers, and no other allocated sections. The unchanged strict ELF verifier reproduces all 22 real relocations and all allocated bytes. Complete original exception-index/descriptor/padding, constructor and destructor scans find no owned metadata. All original data, BSS, tables and adjacent functions remain external.

The fixed-array declaration is a same-size 576-byte storage view of the accepted WorldHandleArray type; no field of that view is accessed. The Handle and BitSet declarations likewise expose only the storage used here and their existing native destruction identities. All three native destructors have their accepted strong owners inventoried, including both target/source objects and canonical/source/header digests. This source emits no backup definitions and requires no identity migration. The existing engine_controller_shutdown declaration is left unchanged; its caller ignores the known returned pointer.

The active census scanned 9,755 ELFs and inventoried 1,368 object records referring to the entry or its three native destruction dependencies. It found no original initialized-data pointers into fn80263B08 and no interior branch targets. No accepted source/header, central symbol/split/configuration or existing consumer changed. Original global C identity is preserved.

Frozen proposal: scratch/engine_sparse_action_owner_destructor_20261011hh/final_integration.json. Complete allocated-byte, dependency, consumer, table and failed-probe evidence is preserved in that directory.
