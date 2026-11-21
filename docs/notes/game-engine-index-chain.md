# Engine index-linked range builder

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_index_chain.c` reconstructs the complete ordinary C entry
`fn_8020C8CC`, owning only `8020C8CC..8020CA08` (316 text bytes). It has no
relocations, allocated data, exception entries, or constructor/destructor table
entries. The original adjacent functions and all other original allocations
retain their existing owners.

The routine links consecutive 140-byte records by storing the preceding and
following indices in their final two shorts. It then terminates both ends with
`-1` and returns the six-byte `{first, last, count}` descriptor in r3/r4. Ordinary
C aggregate return and assignment order reproduce the native loop unrolling
and stack stores. The byte-backed record view preserves indexed stores.

The frozen evidence is `scratch/engine_index_chain_20261010ba/`.
`verify.py` recompiles the production source with GC/1.3.2 and standard game
flags, compares every byte without masking, and rejects additional functions
or allocated sections. `original_full_tables.json` checks the complete original
exception index, descriptor and padding, constructor table, and destructor
table endpoints. All checks pass. This supersedes the private near-match
described in the older array-growth note; those research artifacts remain
untouched.

Integration inputs are `final_integration.json`, `final_config.txt`,
`final_splits.txt`, `scope_edits.txt`, and `ownership_audit.json`. Register the
source as NonMatching, then promote only after native comparison, the complete
original DOL hash, and regression checks pass. No central metadata or original
input was modified by this handoff.
