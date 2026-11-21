# Related-object replacement research

`fn_80229098` remains original assembly at `80229098..80229728` (1,680 bytes). This is bounded ordinary C++ research, with no source registration, source credit, identity migration, or changes to accepted source. The isolated directory is `scratch/engine_related_object_replace_20261011kh`.

The best preserved probe, `byte_tagonly.cpp`, emits a 1,680-byte primary function with 31 differing words, all at `80229458..802294F0`. Every other primary word matches after resolving actual ELF relocations. The remaining region contains the nested lookup of the incoming object's virtual handle, its parent, the parent's flag test, and a repeated child lookup. Original code retains the signed index and generation separately; the probe allocates different scratch registers and schedules the loads differently. This is not an exact match.

The inferred operation first disconnects an existing related object and translates its low flag bits 8/20/10 to 2000/1000/8000. It clears related handles using genuine full-expression temporaries and native Handle construction/destruction. For a valid incoming object, it queries virtual slot 9C, handles an eligible parent, reverses that flag mapping, passes a copied self handle to `fn_80229728`, resets a scalar, and finally replaces the stored related handle with reference-count updates.

Ordinary source findings:

- Four nested zero-initializing Handle layers reproduce the repeated native stores. Three layers reproduce the other empty-handle arguments. A derived return view gives the original base-destructor argument zero for the returned `fn_801BE46C` temporary.
- A named const reference to `self->handle04` before the copy expression preserves the original saved source address and final temporary alias.
- A signed-byte validity helper with explicit result assignment in both branches retains the original neg/or/shift/sign-extension sequence. Returning the comparison directly folds that sequence into a direct branch.
- A distinct byte-backed manager view restores both original manager-entry reloads. Using that view for the later repeated child lookup restores the original total extent. Ordinary named locals, parent/owner helpers, getter forms, typed child views, and extracted index/generation variants did not close the remaining scratch allocation.
- Both full 64-bit flag mapping blocks otherwise match, including their high-word operations and ternary ordering.

Flags are GC 1.3.2, `-O4,p`, `-proc gekko`, exceptions off, LMW/STMW on, FP contraction on. The private object contains 2,220 allocated text bytes: 1,680 primary plus six unused weak destructor backups totaling 540 bytes. All 47 actual relocations are inventoried: 35 retained and 12 backup relocations. The retained code has no references to those backups. They are neither proposed for production nor credited.

`verify_private.py` recompiles the best source and requires complete object byte identity, exact allocation and symbol extents, the 31 preserved primary differences, all actual relocation targets, the original fixture bytes, and a full original exception/constructor/destructor table audit. The original routine has no entries in those tables. `lbl_801E9D24`, `lbl_8037B174`, and `lbl_8037B178` remain borrowed original globals; no storage or literal ownership is claimed. The class, manager, and handle layer names are partial source views rather than recovered complete original class declarations.

The frozen private hash inventory seals all source variants, headers, objects, diagnostics, original ownership proof, verification, and this note. Prior artifacts and production consumers remain unchanged.
