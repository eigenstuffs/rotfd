# Txt resource factory

`src/Game/factory_8020A608.cpp` reconstructs the complete, integrated 132-byte factory at `0x8020A608..0x8020A68C`. The registration and eight-byte `Txt_Z.h` diagnostic identify the Txt resource; the class names with address suffixes are private reconstruction names.

The factory allocates 104 bytes with the existing engine allocator, `Anonymous New`, `Txt_Z.h`, line 21 and alignment 4. Its ordinary placement construction preserves the native allocation-failure check. Construction proceeds through the accepted Root constructor, the Resource virtual-table initialization, the Txt virtual-table initialization, and the embedded 92-byte file object's initializer at offset `0x0C`.

A native C++ constructor chain is necessary here. Replacing construction with explicit calls and virtual-table assignments produced 120 bytes, losing the second saved object pointer. Native virtual classes and an embedded member constructor naturally preserve the original `r31` allocation result and `r30` constructor `this`, giving the exact 132-byte sequence. No inline assembly, register bindings, forced moves or binary patches are used.

The base prefix and six virtual slots agree with the accepted `Root_80207414` declaration. The private Resource and Txt destructor declarations establish their distinct native virtual tables without defining the destructors or emitting tables. The factory references the existing external identities:

| Compiler symbol | Original identity | Address |
| --- | --- | --- |
| `__vt__17Resource_802E9E20` | `lbl_802E9E20` | `0x802E9E20` |
| `__vt__12Txt_802E9E50` | `lbl_802E9E50` | `0x802E9E50` |

These are ordinary undefined ELF symbol references, verified at their original addresses. Central integration reconciles those native names with the original identities; this unit claims no virtual-table, RTTI, string, allocator or other external storage. The complete original table definitions and destructors remain outside this source fragment.

The compiler is `GC/1.3.2` with the established Gekko `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` game flags. `python3 scratch/game_txt_factory/verify.py` verifies the original DOL SHA-1, every retained allocated byte, all 12 actual ELF relocations, the strong global function's exact extent, and the absence of any other allocated sections or generated helper bodies. Result: **132 code bytes, 12 relocations, zero differences**. The object emits no data, BSS, metadata, padding or weak tails. All relocations are recorded in `scratch/game_txt_factory/relocations.json`.

The candidate is `config/GSQE78/candidates/game_txt_factory.json`. Central
integration passes the original DOL SHA-1 and direct whole-file byte comparison.
Native objdiff records 132/132 code bytes and one exact function, with zero owned
data. The source-section extent guard and generated progress checks pass;
reconciled external names preserve the original addresses and linked bytes.
The documented baseline accounting corrections remain preserved.
