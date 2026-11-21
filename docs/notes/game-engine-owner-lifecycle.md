# Owner lifecycle routines

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four complete ordinary C function extents are reconstructed in dedicated source units:

| Source | Original text | Bytes |
| --- | --- | ---: |
| `engine_owner_base_destroy.c` | `8020B774..8020B7DC` | 104 |
| `engine_owner_fixed_destroy.c` | `8020B7DC..8020B860` | 132 |
| `engine_owner_handles_destroy.c` | `8020B860..8020B904` | 164 |
| `engine_owner_object_destroy.c` | `8020CA08..8020CA80` | 120 |

The first resets its table and delegates to the retained array owner destructor `8020C5CC`. The fixed owner resets the table at `7C`, destroys 32 records of stride `1C` beginning at `80`, and calls the retained bitmap owner destructor `801F56A8`. Each record destroys its three wrapped handles in reverse order. Two inline destructor layers preserve the native address checks, including the duplicated test of the first member. The object destructor resets its table at `08`, inlines the root table reset, and delegates to the existing ObjectsOwner destructor. All four return the original object pointer and release the allocation only when the signed low halfword of the deletion argument is positive.

`include/Game/engine_owner_lifecycle.h` contains only these observed layouts and external declarations. Its table pointers describe the observed native stores; original class names beyond already identified external symbols remain unknown.

## Verification and ownership

The frozen evidence is `scratch/engine_owner_lifecycle_20261010ag/`. GC/1.3.2 uses the standard Game flags, with no extra per-unit flags. `freeze.py` and `verify.py` compile the current production source and apply all 29 actual relocations to versioned target addresses. All 520 text bytes compare exactly with the normalized original DOL. The verifier rejects extra emitted functions, mismatched ELF symbol binding or extent, and any additional allocated section. No relocation bits are masked.

`audit.py` checks the four complete original function extents against original assembly, all 3,141 original exception index records, 24 constructor entries, and eight destructor entries. None references these functions. The source owns text only: zero data, BSS, exception, constructor, or destructor bytes. The referenced vtables, allocator objects, base destructors, and all other code/data remain with their existing owners. These partial text units do not claim recovery of a complete original translation unit.

`final_integration.json`, `final_splits.txt`, `final_config.txt`, `scope_edits.txt`, and `ownership_audit.json` give precise central integration instructions. All four entry symbols require global scope. The parent integrator performs NonMatching registration, standard native build/hash acceptance, and regression checks; isolated proof alone is not credited as accepted project progress.

Private diagnostics for initializers `8021118C` and `8024CDCC` remain in the same frozen research directory. Neither is exact, neither has a production source, and neither appears in the integration manifest. Ordinary C and C++ forms lack the native retained pointer lifetimes; they remain uncredited.
