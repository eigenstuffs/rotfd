# Platform resource initializers

Five independent ordinary C++ units match **364 code bytes and 18 actual relocations**. Full production linking and original-DOL acceptance are pending. These are C-entry reconstructions retaining the original function names and external vtable identities; they do not propose native derived-class identity migrations.

| Source | Original extent | Bytes / relocations | Behavior |
| --- | --- | ---: | --- |
| platform_sparse_pool_init.cpp | 8026BE78..8026BED4 | 92 / 3 | Set the pool table, clear its storage fields, construct the native bitset, and clear its counters. |
| platform_spatial_resource_init.cpp | 8026C174..8026C1C0 | 76 / 6 | Construct the accepted spatial-handle base, set the resource table, then initialize the global renderer resource. |
| platform_basis_resource_init.cpp | 8026D944..8026D980 | 60 / 3 | Construct the accepted basis-resource base and set the derived table. |
| platform_byte_buffer_init.cpp | 8026EF64..8026EFB0 | 76 / 3 | Run the existing base setup, set the derived table, and clear the byte buffer fields. |
| platform_spatial_binding_init.cpp | 8026F078..8026F0B4 | 60 / 3 | Construct the accepted spatial-binding base and set the derived table. |

Every first isolated probe and fresh production compile matches with GC1.3.2 standard `-O4,p`, exceptions off. All five entries return the original receiver. Their partial receiver layouts expose only fields used by these C-entry implementations; they do not instantiate truncated objects or redefine the accepted native base classes. The sparse pool uses the existing native bitset header and constructor declaration. Existing base constructor names, source owners, headers and consumers remain unchanged.

Each compiler object emits only its complete retained `.text` function. There is no data, BSS, EH, weak backup, startup allocation or owned padding. Original tables `lbl_802ED168` (16 bytes), `lbl_802ED178` (76), `lbl_802ED218` (40), `lbl_802ED348` (104) and `lbl_802ED3B0` (80) remain external and uncredited. Their accepted destructor consumers preserve their existing identities. These partial text units do not claim complete original translation-unit or class recovery.

The current symbol-address and canonical-range census finds no prior source ownership, and the C/C++ body census finds no earlier probes. Complete original exception-index, constructor/destructor and initialized-pointer audits preserve original table ownership. Generated assembly can contain older copies with historical base constructor spellings; their original instruction bytes are identical. The strict object verifier resolves the current actual native constructor symbols to their accepted original addresses and compares every retained byte without masking.

The frozen list of five complete candidate records is `scratch/engine_resource_initializers_20261011is/final_integration.json`. Its allocation inventory, current consumers, whole borrowed-table inventory, original table audits and strict fresh verification accompany the production source/header hashes. Root owns central registration, final linking and original-DOL/regression acceptance.
