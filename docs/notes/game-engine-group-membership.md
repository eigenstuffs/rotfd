# Group membership wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ functions reconstruct 336 bytes of complete original text:

| Source | Original text | Bytes |
| --- | --- | ---: |
| `engine_group_detach.cpp` | `8021AB88..8021AC2C` | 164 |
| `engine_group_attach.cpp` | `8021AC2C..8021ACD8` | 172 |

Both update the owner's state, construct a retained copy of its handle, invoke
the selected 76-byte group record, and destroy the copy. Attach first records
the supplied group byte. Naming the original handle reference before local
construction preserves its native saved-pointer lifetime. Two nested default
constructors reproduce the original zero stores before the derived copy
constructor assigns and retains the handle.

The frozen evidence is `scratch/engine_group_membership_20261010bd/`.
`verify.py` recompiles both production sources with standard GC/1.3.2 game
flags, verifies every retained byte after 18 actual relocations, and rejects
unaccounted functions or allocated sections. Each object also emits three
normal unreferenced weak destructors, totaling 264 bytes per object; their
bindings, extents, raw byte hashes, and 12 total relocations are inventoried.
Retained code does not reference those discarded bodies, which receive no
original address or matching credit. All checks pass.

The complete original exception index, descriptor and padding, constructor
table, and destructor table endpoints are audited in
`original_full_tables.json`. None references either retained function. The
sources own no data. All external state, handle lifecycle routines, group
operations, adjacent functions, and other original allocations retain their
existing owners.

Use `final_integration.json`, `final_config.txt`, `final_splits.txt`,
`scope_edits.txt`, and `ownership_audit.json` for integration. Register both
sources as NonMatching and promote only after native comparison, the full
original DOL hash, and regression checks pass. No shared metadata or original
input was changed by this handoff.
