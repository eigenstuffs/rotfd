# Resource registry path startup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801B480C`, at `801B480C..801B4AAC`, builds three128-byte paths, creates a16-byte hash registry, inserts each populated16-byte owner record, selects a related service resource by Name with a fallback, resolves its Handle and loads the derived configuration path. A local92-byte File follows the original constructor/destructor calls.

The isolated production source is `src/Game/resource_registry_paths_801B480C.cpp`. GC1.3.2 with `-proc gekko -O4,p -Cpp_exceptions off -use_lmw_stmw on` emits exactly672 bytes and43 actual relocations, with no other allocated sections or helpers. The exact ordinary source uses a Name member comparison, signed24-bit Handle index/high8-bit generation, and a pointer to the original string-array object. The latter keeps the original shared pool address live through both allocator arguments instead of recomputing it.

Full extabindex/startup-table scans show no original EH, ctor or dtor ownership. The stable original-input census covers5,625 objects,119,086 actual relocations and777,360 initialized words. Its only original consumer is a vtable word at802E9E8C, inside original lbl_802E9E70; that data remains external. There are no compiled source consumers, aliases or overlapping text symbols. All strings, allocator state, tables and called functions retain their existing external ownership.

Frozen batch273 evidence: `scratch/game_engine_batch273/manifest-list.json` and `scratch/game_resource_registry_paths_801b480c/`. Production and an independent fresh compile pass the unchanged strict all-allocation/actual-relocation verifier. Root full native placement, original DOL hash, regression and test acceptance remain pending; this isolated result does not itself change reported progress.
