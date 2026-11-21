# State initialization and collision dispatch

Two independent ordinary C++ units match **120 code bytes and four actual relocations**. Production integration and original-DOL acceptance are pending.

| Source | Original extent | Behavior |
| --- | --- | --- |
| state_pair_initialize.cpp | 802358AC..802358E8 (60 bytes) | Initialize the state members at offsets 14 and 4C, then return the receiver. |
| collision_mesh_dispatch.cpp | 80242C34..80242C70 (60 bytes) | Select the short collision routine when signed count A0 is at most two; otherwise forward all five arguments to the full routine. Forward the selected routine's integer result. |

GC1.3.2 with standard `-O4,p`, exceptions off, emits only the two complete retained text functions. There is no data, BSS, EH, startup, weak helper, or padding allocation. The complete original exception-index, constructor/destructor and initialized-pointer scans find no ownership references to either entry. All current original identities remain unchanged, and every actual branch relocation resolves to its original target.

The 74-byte state layout exposes only the two initialized members. The accepted array constructor in `engine_buffer_record_8023576C.c` declares this callback with a void return and ignores the returned register. That existing declaration and source remain unchanged; the new definition records the receiver return visible in the original epilogue. The collision receiver is a partial field view. Neither reconstruction claims a full original class or translation unit.

Private probes for pool initializer 8020BE78 remain eight bytes short because ordinary base/member construction folds two original receiver aliases. The returned-Handle getter 80237BC8 reaches its original 120-byte primary extent using a genuine nontrivial native Handle and named source reference, but seven address-calculation words differ. Its unused weak destructor allocations are inventoried only as research. Earlier manual getter probes and the two-alias card initializer 8027696C are preserved unchanged. These functions receive no source credit here.

The frozen handoff is `scratch/engine_state_collision_controls_20261011it/final_integration.json`, with complete allocations, source/header hashes, original tables, current consumers and fresh strict verification. Root owns central registration and full build acceptance.
