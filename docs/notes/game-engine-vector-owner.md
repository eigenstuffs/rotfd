# Vector storage and handle-owner cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three complete ordinary C functions have exact isolated production-source verification:

| Source | Original extent | Text bytes |
| --- | --- | ---: |
| `src/Game/vector3_storage_setup.c` | `8020BECC..8020BF78` | 172 |
| `src/Game/vector4_storage_setup.c` | `8020C018..8020C0C4` | 172 |
| `src/Game/vector_handle_owner_destroy.c` | `8020CEA8..8020CF70` | 200 |

The setup routines store width at `0C`, call the retained setup entry `fn_801EAC8C`, free previous array storage at `10` through the original allocator with the 16-byte array header adjustment, and allocate `rows * width` elements. They call the genuine `__construct_new_array` runtime with 12- or 16-byte strides and the retained vector constructor; the destructor callback is null. The allocation metadata strings, allocator and constructor functions retain their original ownership. The inline array-free helper preserves both observed null tests.

The owner destructor restores the tables at `08` through `lbl_802EB040`, `lbl_802EB090` and the retained ObjectsRoot table. Wrapped handles at `28` and `20` are destroyed in reverse order; the original nested wrapper and handle null checks are reproduced by ordinary inline helpers. It then calls the retained ObjectsOwner destructor and frees the object when the signed low halfword of the delete argument is positive. The field names and grouping in `include/Game/engine_vector_owner.h` describe observed layout, not a recovered original class name.

Frozen evidence is in `scratch/engine_vector_owner_20261010an/`. GC/1.3.2 uses the standard Game flags with no extra flags. `freeze.py` and `verify.py` compile the current production sources, verify every function binding and complete extent, reject additional functions or allocated sections, apply all 40 real REL24/HA/LO relocations, and compare every byte with the normalized original DOL. No comparison bits are masked.

The sources own 544 text bytes and zero data, BSS, exception, constructor or destructor-table bytes. `audit.py` verifies all original function extents and checks 3,141 exception index entries, 24 constructor entries and eight destructor entries; none references the selected text. All remaining code and data in the original units retain their existing ownership. These are partial text-only splits.

`final_integration.json`, `final_splits.txt`, `final_config.txt`, `scope_edits.txt` and `ownership_audit.json` provide central integration instructions. Each entry requires global function scope. Register NonMatching, verify through the native build, and promote only after original DOL hash and regression acceptance. Isolated verification alone earns no project progress.
