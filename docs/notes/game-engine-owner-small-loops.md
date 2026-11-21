# Segment lookup and empty owner iteration

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two independent ordinary C++ entries are frozen under
`scratch/engine_owner_small_loops_20261011ds`:

| Source | Original range | Text | Extra flags |
| --- | --- | ---: | --- |
| `engine_curve_segment_find.cpp` | `8024D9FC..8024DA4C` | 80 | none |
| `engine_owner_empty_scan.cpp` | `8024A040..8024A094` | 84 | `-opt nopropagation` |

`fn_8024D9FC` scales its float input by owner field `0x9C`, then accumulates
lengths at offset `0x14` of 248-byte entries. It stops when the accumulated sum
strictly exceeds the target or reaches the entry count, and returns the visited
count minus one. The initial accumulator remains the original external float
`lbl_8037B44C`. A separate target local preserves the original floating-point
allocation; overwriting the incoming parameter produced four register differences.

`fn_8024A040` performs the original empty signed-count iteration over owner field
`0x64`, then returns zero. The original loop has no retained element operation;
its higher-level purpose is unknown. The ordinary empty loop reproduces the
original eight-way unrolling. Disabling propagation preserves the initial
register comparison rather than replacing it with an immediate comparison.
No extra source operation is inserted to produce that comparison.

## Verification and ownership

Each subdirectory (`curve` and `empty`) contains an independent
`final_integration.json`, strict verifier, original table audit and frozen hashes.
The production sources and dedicated shared header reproduce complete retained
text extents and the sole actual relocation in the curve entry. Both objects
emit only their retained text, with no weak code, data, BSS, padding, exception
or startup allocations. Full original exception-index, constructor and
destructor tables have no references to either entry. The external literal
retains its existing identity and owner; adjacent functions remain outside
these partial units.

No existing source, consumer, header, symbol or central metadata was changed.
All private probes and compiler-option results remain preserved in the parent
scratch directory. Root performs central registration, promotion, full DOL hash
and regression acceptance before this handoff contributes progress.
