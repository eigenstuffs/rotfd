# Range joins and handle ancestry

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The frozen handoff in `scratch/engine_range_join_20261010aa/` reconstructs
five complete ordinary C functions, totaling 1,184 text bytes and no owned
data. All use GC/1.3.2 and the standard game flags; only the ancestor traversal
adds `-opt nocse` to preserve its original manager-entry reloads.

| Source | Original text | Bytes | Behavior |
| --- | --- | ---: | --- |
| `engine_range_join.c` | `8020E814..8020E8B0` | 156 | Join two nonempty linked ranges, returning a three-short range aggregate. |
| `engine_range_release.c` | `8020E938..8020EADC` | 420 | Join a record's two pending ranges into the owner's range when its state is zero, then update the state and clear its value. |
| `engine_record_copy_64.c` | `8023E910..8023E994` | 132 | Copy a 64-byte aggregate. |
| `engine_handle_ancestor.c` | `8023D8D8..8023D9B8` | 224 | Follow resolved parent handles and set bit eight in the highest ancestor's resolved owner. |
| `engine_handle_related_find.c` | `8023A5DC..8023A6D8` | 252 | Find a handle whose resolved object's related handle resolves to the requested object, returning the array base when no match exists. |

The range functions use the ordinary six-byte structure return ABI. Returning
the range by value through an inline join and assigning its three fields
reproduces the original temporaries. Links are shorts at offsets 136 and 138
of each 140-byte array entry. Handle generation and index are signed eight-bit
and 24-bit fields. The related-handle comparison explicitly resolves its
first operand before the second; the loop preserves its per-iteration backing
pointer. No instruction encodings or extracted assembly are used as source.

Fresh production compilation, complete byte comparison, and strict allocation
checks passed. All four actual relocations target the original context object;
no relocation bits are masked. The verifier rejects extra functions, allocated
sections, or incorrect extents. Original ownership auditing checked all
3,141 extabindex entries, 24 constructor entries, and eight destructor entries.
None references these functions. The handoff owns only the listed text; the
context object, adjacent functions, and all original data retain their owners.
These are partial text splits, not recovered complete original translation
units.

Integration inputs are `final_integration.json`, `final_splits.txt`,
`final_config.txt`, `scope_edits.txt`, and `ownership_audit.json`. Register
NonMatching, verify native comparison, and promote after the full original
DOL hash and regression checks. No central configuration, original input,
expected hash, or generated progress was changed by this handoff.
