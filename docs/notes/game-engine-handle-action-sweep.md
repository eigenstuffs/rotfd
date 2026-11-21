# Handle action sweep

Isolated ordinary C++ proof: fn80263764 at 80263764..80263B08, 932 text bytes. Production source is src/Game/engine_handle_action_sweep.cpp with the partial storage/virtual-slot declarations in include/Game/engine_handle_action_sweep.h. Integration remains with the central integrator; no full-DOL acceptance is claimed by this isolated handoff.

The entry visits both Handle arrays and five scalar Handles. Each valid Handle resolves its signed 24-bit index and signed 8-bit generation through the global manager, then invokes virtual slot1C. It finally finds occupied BitSet entries and applies fn80262180 to the corresponding 12-byte record. The original uses a full-word validity return; narrowing that declaration adds unnecessary result extraction. Sharing the integer loop index with the final BitSet cursor reproduces the original saved-register allocation.

GC/1.3.2 with the standard O4,p/exceptions-off flags emits one global 932-byte function and no other allocated sections, weak helpers, literal pools or metadata ownership. Strict unchanged ELF verification resolves all twelve real relocations and compares the complete text. Complete original exception-index/descriptor/padding, constructor and destructor scans find no references to this entry. All data, BSS, adjacent functions and original tables stay outside this handoff.

The full active-object census scanned 9,751 distinct ELFs, including target and compiled objects. It found the two original object references to fn80263764, no original initialized-data pointers into the function, and no interior branch targets. The new production object has been separately recompiled, checked and inventoried. No accepted source/header, central symbol/split/configuration or existing consumer is changed. Original C identity and global scope are retained.

Frozen proposal: scratch/engine_handle_action_sweep_20261011hg/final_integration.json. The allocation inventory, original full-table proof, source/consumer digests and all failed ordinary-source variants are preserved alongside it.
