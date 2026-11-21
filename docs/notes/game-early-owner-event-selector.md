# Owner event selector

The isolated ordinary C++ source `src/Game/early_owner_event_selector_8002264C.cpp` matches the1064-byte function at8002264C. It implements the shared callback registration/query protocol, initializes event outputs, dispatches owner actions, and completes the callback. Its owner-specific action checks a nested related resource before stopping its controller and updating position; other actions query an owner flag or clear callback/owner bits.

The source uses the established12-byte member-pointer value ABI, typed16-byte checked Handle manager entries, and genuine resource virtual methods. The callback flag clear uses the observed16-bit mask0xFFFB, preserving the native andi. instruction. All operations are ordinary C++, with no assembly or register constraints.

GC1.3.2 processor750/O4,s/exceptions-on exactly matches1064 text bytes,28 switch-table bytes at802AFC4C, eight EH bytes at80005BB8 and12 index bytes at80016170. All31 actual allocated relocations and real local object identities @123/@124/@125 are verified. No helper, literal, BSS or padding is emitted. The original EH has no Elf Vector.

The complete current original-object scan covers5530 objects and119086 actual relocations: the28-byte jump table has one original definition and only this function's two text references, no overlapping source split or alias. The777360-word initialized DOL scan finds no pointers into the table. Its seven entries point to verified branch offsets within this function. The member-pointer pool borrowed through external lbl802AFBA0 remains wholly external; the source adds no allocation or alias for it.

Full original exception/startup and initialized-data scans pass. Seven unchanged160-byte original callback tables also reference this function; all containing symbols, entry addresses, targets and content hashes are inventoried. No existing source/header caller requires migration. Dependency names derive only from actual undefined ELF symbol indices.

Frozen handoff: `scratch/game_engine_batch174/HANDOFF.md`. Repeat `python3 scratch/game_early_owner_event_selector/verify.py`; the original-data exclusivity audit is `audit_data.py` in the same directory. Central native DOL/hash/regression acceptance remains pending.
