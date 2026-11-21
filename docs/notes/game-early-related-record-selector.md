# Related-record selector

The isolated ordinary C++ source `src/Game/early_related_record_selector_8004BE1C.cpp` matches1380 bytes at8004BE1C. It implements callback registration/query and, for the owner-specific action, resolves the current related record. When the owner enables a particular64-bit flag, it follows the system-related actor and optional virtual Handle to choose an alternate record. A byte-indexed search then clears and binds the owner when its record matches a selected Handle.

The source uses typed16-byte manager entries, genuine resource/owner virtual methods, the established12-byte member-pointer value ABI, and a pointer-return Handle getter with integer index. Ordinary early returns in the checked resolver preserve native result handling; a ternary form initially added three result moves. The getter's observed integer argument requires widening the byte loop index at the call, matching accepted definitions and callers. No assembly or register constraints are used.

GC1.3.2 processor750/O4,s/exceptions-on exactly matches1380 text bytes,28 switch-table bytes at802B3D2C, eight EH bytes at800095D4 and12 index bytes at80017B38. All38 actual allocated relocations and actual local object extents are verified. No helper, literal, BSS or padding is emitted. The original EH has no Elf Vector.

The complete current original-object scan covers5531 objects and119086 actual relocations: the switch table has one original definition and only this function's two references, no overlapping source split/alias and no initialized pointer into the table among777360 scanned DOL words. Its seven entries target verified internal branch offsets. The broader member-pointer pool borrowed through lbl802B3708 remains wholly external with unchanged identities and ownership.

Full original exception/startup and initialized-data scans pass. The unchanged160-byte original callback table lbl802B4568 references this function; its containing symbol, entry address and content hash are inventoried. No existing compiled source/header caller needs migration. Dependency names derive exclusively from actual undefined ELF symbols.

Frozen handoff: `scratch/game_engine_batch175/HANDOFF.md`. Repeat `python3 scratch/game_early_related_record_selector/verify.py`; original-data audit `audit_data.py` in the same directory. Central native DOL/hash/regression acceptance remains pending.
