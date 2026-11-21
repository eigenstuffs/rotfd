# Record owner cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_record_owner_destroy.cpp` reconstructs the complete ordinary
C++ entry `fn_80210FD4`, owning only `80210FD4..8021118C` (440 text bytes).
It unregisters an active owner with a retained handle local, destroys the tail
handle and every 212-byte record, releases record storage, performs the
original base cleanup, and frees the owner for a positive deleting flag.

The retained handle uses the frozen group-membership construction view. Its
scope ends before the owner-state call, matching the original lifetime. A
signed-char getter preserves the repeated original sign-extension checks.
Typed array members and nested cleanup helpers reproduce the original
pointer checks, record loop and base-table stores.

The frozen handoff is `scratch/engine_record_owner_destroy_20261010bh/`.
`verify.py` recompiles production source with GC/1.3.2 and standard game flags
plus `-use_lmw_stmw on`, then verifies every retained byte after 24 actual
relocations. Three normal trailing weak destructors, totaling 264 bytes, are
inventoried by names, bindings, extents, raw byte hashes and all six
relocations. Retained code has no reference to those discarded bodies, which
receive no original addresses or matching credit. No additional allocated
sections pass. All checks pass.

The complete original exception index, descriptor and padding, constructor
table, and destructor table endpoints are audited in
`original_full_tables.json`; none references this function. The source owns
no data. Original virtual tables, context/allocator objects, external
lifecycle routines, adjacent text and other original allocations retain their
existing owners. There is no symbol identity migration.

Use `final_integration.json`, `final_config.txt`, `final_splits.txt`,
`scope_edits.txt`, and `ownership_audit.json` for integration. Register
NonMatching first and promote only after native comparison, the complete
original DOL hash, and regression checks pass. No shared metadata or original
input was changed by this handoff.
