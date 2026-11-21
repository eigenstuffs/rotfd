# ObjectsGame factory

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_game_factory.cpp` reconstructs the complete ordinary C++ entry
`fn_80209814`, owning only `80209814..80209910` (252 text bytes). Genuine
placement construction calls the existing ObjectsRoot, Handle and BitSet
constructors, initializes eight array members, and returns the original
allocated pointer. Allocation metadata requests 0x9C bytes and records the
original header line 96.

The compiler references the native external virtual-table identity
`__vt__20ObjectsGame_802EB900`. Integration must rename the existing
`lbl_802EB900` symbol at `802EB900` to that identity, keeping its `.data`
section, 64-byte extent, original object attributes and global scope. No alias,
thunk, table definition, or additional data is emitted. The reference inventory
checks current configured assembly only, excluding stale generated units;
there are no old-spelling production source/header references. The remaining
original assembly references can use the renamed identity.

The frozen handoff is `scratch/engine_game_factory_20261010bc/`.
`verify.py` checks the guarded dependency identity, recompiles production
source with standard GC/1.3.2 flags, and verifies every retained byte after
applying 12 actual relocations. It inventories the normal trailing 84-byte
weak `GameFactoryHandle` destructor by name, binding, extent, raw byte hash,
and both relocations. Retained code has no reference to that discarded weak
body, which receives no original address or matching credit. No additional
allocated sections pass. All checks pass.

`original_full_tables.json` audits the complete original exception index,
descriptor and padding, constructor table, and destructor table endpoints;
none references the retained function. All original strings, tables, external
constructors, adjacent text and other original allocations retain their
existing owners. Only the guarded external vtable spelling changes.

Use `final_integration.json`, `final_config.txt`, `final_splits.txt`,
`scope_edits.txt`, and `ownership_audit.json` for integration. Register
NonMatching first and promote only after native comparison, the full original
DOL hash, and regression checks pass. No shared metadata or original input was
modified by this handoff.
