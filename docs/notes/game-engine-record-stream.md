# Record stream token loop

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_record_stream.cpp` reconstructs the complete ordinary C++
entry `fn_8021020C`, owning only `8021020C..80210370` (356 text bytes).
It obtains a handle through manager virtual slot 28, constructs a retained
copy, checks validity, reads tokens from the resolved object's stream, invokes
the record reader for the selected token, and finishes by setting state 6.

The native Handle return type has a nontrivial destructor, preserving the
original hidden return pointer and temporary lifetime. A default-constructed
zeroing base keeps the copied handle's address live through its native
construction. The five-byte external string declaration reproduces the
original SDA21 reference. The token buffer occupies 128 stack bytes.

The frozen handoff is `scratch/engine_record_stream_20261010bg/`.
`verify.py` recompiles production source with standard GC/1.3.2 game flags and
verifies every retained byte after applying 15 actual relocations. Two normal
trailing weak destructors, totaling 172 bytes, are inventoried by names,
bindings, extents, raw byte hashes, and all four relocations. Retained code has
no reference to those discarded bodies, which receive no original addresses
or matching credit. No additional allocated sections pass. All checks pass.

The complete original exception index, descriptor and padding, constructor
table, and destructor table endpoints are audited in
`original_full_tables.json`; none references this function. The source owns
no data. All original context/string objects, manager interfaces, external
lifecycle and stream routines, adjacent text and other original allocations
retain their existing owners.

Use `final_integration.json`, `final_config.txt`, `final_splits.txt`,
`scope_edits.txt`, and `ownership_audit.json` for integration. Register
NonMatching first and promote only after native comparison, the complete
original DOL hash, and regression checks pass. No shared metadata or original
input was changed by this handoff.
