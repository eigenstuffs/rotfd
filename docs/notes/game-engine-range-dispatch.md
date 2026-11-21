# Range dispatch and callback state

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The frozen handoff under `scratch/engine_range_dispatch_20261010ab/` contains
five complete ordinary C/C++ functions, totaling 1,096 text bytes and no
owned data. All use GC/1.3.2 and the standard game flags. The activation,
handle replacement, and reset units add `-opt nocse` to preserve their original
entry-pointer reloads.

| Source | Original text | Bytes | Behavior |
| --- | --- | ---: | --- |
| `engine_range_activate.c` | `8020E394..8020E46C` | 216 | Reset callback state and float values, then handle a flag on its resolved related object. |
| `engine_range_query.c` | `8020E46C..8020E558` | 236 | Validate a record index and state, optionally update its ranges, and stamp the returned record. |
| `engine_range_dispatch.cpp` | `8020E8B0..8020E938` | 136 | Select and release records until the requested short count is consumed or selection fails. |
| `engine_range_handle_replace.c` | `8020EB54..8020EC48` | 244 | Replace a retained handle when its resolved related object has type two. |
| `engine_range_reset.c` | `8020EE70..8020EF78` | 264 | Reset callback state, clear object flag `0x10000`, and notify a resolved secondary object. |

The selected-index token has a nontrivial C++ copy constructor. Declaring it
as such reproduces the original hidden return pointer to the stack temporary,
without substituting an output-parameter API. Range counts remain signed
shorts, and record-update predicates return signed chars. The two manager
counter calls in handle replacement retain their original decrement/copy/
increment order, including the fresh manager load after the first call.
Uncertain view fields remain labeled by their offsets.

Fresh production compilation and strict verification passed for every byte
after applying all 16 actual relocations. Extra functions, unexpected allocated
sections, and incorrect extents are rejected. Original ownership auditing
checked all 3,141 extabindex entries, 24 constructor entries, and eight destructor
entries; none references these functions. The handoff owns only the listed
text ranges. All external context, float constants, other functions, and
original data retain existing ownership. This is a partial text split, not
a claim to recover a complete original translation unit.

Use `final_integration.json`, `final_splits.txt`, `final_config.txt`,
`scope_edits.txt`, and `ownership_audit.json` to register the units NonMatching.
Promote only after native comparison, the full original DOL hash, and
regression checks pass. This handoff does not modify central configuration,
original inputs, expected hashes, or generated progress.
