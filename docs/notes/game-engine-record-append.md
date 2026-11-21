# Retained-handle record append

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_record_append.cpp` reconstructs the complete ordinary C++
entry `fn_80210014`, owning only `80210014..8021020C` (504 text bytes).
The function grows a 212-byte record array by eight when full, constructs a
copy in the appended slot, and returns its index.

The typed record's implicit copy constructor retains its first handle through
the existing native lifecycle routines. Its remaining members reproduce the
original 32-word copy loop, scalar stores, paired word stores, byte stores and
float stores. Ordinary member layout leaves the observed alignment padding
uncopied. Genuine placement construction preserves the original null guard
for the destination slot.

The frozen handoff is `scratch/engine_record_append_20261010be/`.
`verify.py` recompiles production source with standard GC/1.3.2 game flags and
verifies all 504 bytes after applying 13 actual relocations. The normal
trailing 84-byte weak AppendHandle destructor is inventoried by name, binding,
extent, raw hash and both relocations. Retained code has no reference to that
discarded body, which receives no original address or matching credit. No
additional allocated sections pass. All checks pass.

The complete original exception index, descriptor and padding, constructor
table, and destructor table endpoints are audited in
`original_full_tables.json`; none references this function. The source owns
no data. All original allocator/context objects, external lifecycle routines,
adjacent text and other original allocations retain their existing owners.

Use `final_integration.json`, `final_config.txt`, `final_splits.txt`,
`scope_edits.txt`, and `ownership_audit.json` for integration. Register
NonMatching first and promote only after native comparison, the complete
original DOL hash, and regression checks pass. No shared metadata or original
input was changed by this handoff.
