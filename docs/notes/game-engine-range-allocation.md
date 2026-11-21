# Range allocation, selection, and setup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The frozen handoff in `scratch/engine_range_allocate_20261010ac/` contains
four complete ordinary C/C++ functions: 1,028 text bytes, no owned data,
and 24 actual relocations. All use GC/1.3.2 with the standard game flags;
the 700-byte allocator additionally uses `-use_lmw_stmw on`.

| Source | Original text | Bytes | Behavior |
| --- | --- | ---: | --- |
| `engine_range_allocate.c` | `8020E558..8020E814` | 700 | Reclaim or grow available linked entries, then detach the requested range into a record. |
| `engine_range_select.cpp` | `8020EADC..8020EB54` | 120 | Select a zero-state record by its elapsed stamp and return a nontrivial index token. |
| `engine_range_state_flag.c` | `8020EDB0..8020EE10` | 96 | Mark callback state and set flag `0x10000` on its resolved object. |
| `engine_range_setup.c` | `8020BFA8..8020C018` | 112 | Initialize storage, set size three, and configure its derived square-based capacity. |

The allocator preserves the original limit of 32,000 entries, growth by the
requested count plus sixteen, signed short counts, and trivial entry lifecycle
loops. Reusing the `old + growth` expression allows ordinary CSE to retain
the original value lifetimes. The selector's negated `age <= threshold`
condition preserves the original unordered floating-point behavior. Its
token has a nontrivial C++ copy constructor, reproducing the hidden return
pointer. The state helper reuses the frozen `engine_range_dispatch.h` view;
that header was not modified.

Fresh production compilation and strict byte/allocation verification passed.
All relocations were applied to actual versioned targets without masking.
The verifier rejects extra functions, unexpected allocated sections, and
incorrect extents. Original ownership auditing checked every selected
function extent, all 3,141 extabindex entries, 24 constructor entries, and
eight destructor entries. No startup or exception record references the
selected text. The handoff owns only the listed text; original allocator
data, context, external range functions, and all other ranges retain their
existing ownership. These are partial text splits rather than complete
original translation units.

Integration inputs are `final_integration.json`, `final_splits.txt`,
`final_config.txt`, `scope_edits.txt`, and `ownership_audit.json`. Register
NonMatching, verify native comparison, and promote after full original DOL
hash and regression checks. No central configuration, original input,
expected hash, or generated progress was changed by this handoff.
