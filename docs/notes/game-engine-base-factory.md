# ObjectsBase factory

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_base_factory.cpp` reconstructs the complete ordinary C++ entry
`fn_8020A1E4`, owning only `8020A1E4..8020A324` (320 text bytes). Its genuine
placement construction invokes the existing ObjectsRoot and Handle
constructors, initializes nested handle layers and arrays, and references the
existing native ObjectsBase virtual table. The allocation metadata requests
0x168 bytes and records the original header line 221.

The constructor view follows the already matched ObjectsBase constructor
layout. Wrapper destructors are declared externally so construction alone
emits no unrelated weak destructor bodies. The allocator expression remains
inside the placement expression to preserve the original saved-pointer
lifetime. The object owns no data or original exception/startup table entries.
All original strings, virtual tables, external constructors, adjacent text,
and other original allocations retain their existing owners.

The frozen handoff is `scratch/engine_record_factory_20261010bb/`.
`verify.py` recompiles the production source with standard GC/1.3.2 game flags
and verifies all 320 bytes after applying all 15 actual relocations. It also
rejects additional functions or allocated sections. The full original
exception index, descriptor and padding, constructor table, and destructor
table endpoints are audited in `original_full_tables.json`. All checks pass.

Use `final_integration.json`, `final_config.txt`, `final_splits.txt`,
`scope_edits.txt`, and `ownership_audit.json` for integration. Register
NonMatching first and promote only after native comparison, the original DOL
hash, and regression checks pass. No shared metadata or original input was
changed by this handoff.
