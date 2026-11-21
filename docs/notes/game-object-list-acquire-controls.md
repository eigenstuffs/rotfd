# Object-list acquisition and Handle cleanup

Two independent ordinary C++ C entries match **220 retained code bytes and eight actual relocations**. Full production integration and original-DOL acceptance are pending.

| Source | Original extent | Behavior |
| --- | --- | --- |
| scene_list_handle_destroy.cpp | 80260F08..80260F64 (92 bytes) | Destroy the native Handle base when the receiver exists, release storage through the original allocator when the signed destruction flag is positive, and return the receiver. |
| object_list_node_acquire.cpp | 80285D34..80285DB4 (128 bytes) | Pop the pool's free node, assign a temporary empty native Handle, clear key and next, reset the two float fields from their original external constants, and return the node. |

GC1.3.2 standard `-O4,p`, exceptions off, matches every retained byte and actual relocation. Acquisition uses the existing accepted object-list declarations and `ObjectListEmptyHandle` lifetime. Advancing the list through `self->freeNodes->next`, then returning an inline reset helper's result, preserves the original temporary receiver alias and closes the earlier four-byte deficit. Direct local advancement and helper variants remain preserved as private probes.

Acquisition also emits one unreferenced 84-byte weak `ObjectListEmptyHandle` destructor and two backup-only relocations. Its complete raw allocation and symbols are inventoried separately and receive no credit. The current accepted node-release object has the same weak identity and identical raw backup bytes; its only reference is nonallocated compiler metadata. Neither retained function refers to that backup. Final integration must discard the new copy along with the existing unused copy. There is no emitted data, BSS, EH, startup allocation, or owned padding.

The original 80260F08 identity remains a C entry. Its four-byte receiver view describes only the native Handle base touched by the body. The accepted scene-owner destructor passes this entry as a cleanup callback for 14-byte records, with a void-return/int-flag partial declaration. That existing caller and declaration remain unchanged; the new source recovers the pointer return and signed-short flag from the original body. No complete record/class layout or native identity migration is claimed.

Original external pool storage, allocator context `lbl_801EF5C8`, and float constants `lbl_8037B890` / `lbl_8037B894` remain uncredited. Complete original exception-index, constructor/destructor and initialized-pointer audits find no retained entry ownership. Current address/canonical ownership and prior body censuses accompany the handoff. The old 80285E10 combined clear remains private at 196 versus 200 bytes; this batch makes no new claim there.

The frozen handoff is `scratch/engine_object_list_controls_20261011iu/final_integration.json`, with all source/header hashes, complete emitted allocations, actual relocations, original table proofs and fresh strict verification. Root owns central registration and full DOL acceptance.
