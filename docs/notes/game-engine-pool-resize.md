# Engine nested pool resizing continuation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: eight ordinary C++ units, eight original functions,
5,084 retained text bytes, zero owned data bytes and 182 retained real
relocations. The compiler also emits nine trailing unused weak cleanup
destructors totaling 1,596 bytes with 31 relocations. These weak bytes receive no
source credit and must all be absent from the final linked ELF.

Sources are `src/Game/engine_pool_resize_*.cpp`. Exact integration is recorded in
`scratch/game_engine_pool_resize_continuation/final_integration.json`, with
`final_splits.txt`, `final_config.txt` and `ownership_audit.json`. Frozen source
SHA-256 and recursive quoted-header hashes are included; there are no quoted
headers. `unlinked_functions` freezes every unused function's weak binding,
section, offset, size and raw SHA-256. Both retained and unused relocation lists
and counts are explicit.

| Original function | Retained bytes | Retained relocations | Unused weak bytes | Observed element layout |
| --- | ---: | ---: | ---: | --- |
| fn_801B378C | 664 | 29 | 556 | 28-byte curve record: prefix C, native four-byte CurveBase, 16-byte-element pool at +10 |
| fn_801CAEE0 | 588 | 21 | 208 | 12-byte derived vector of two-byte elements |
| fn_801CEA38 | 588 | 21 | 208 | 12-byte derived vector of four-byte elements |
| fn_801CEC84 | 588 | 21 | 208 | 20-byte derived vector of two-byte elements; last eight bytes retain opaque ownership |
| fn_801D3088 | 580 | 21 | 0 | 12-byte pool of four-byte elements |
| fn_801D4734 | 744 | 24 | 208 | 28-byte record: opaque word, pools of eight-byte elements at +4/+10 |
| fn_801D58C4 | 580 | 21 | 0 | 12-byte pool of two-byte elements |
| fn_801D5B08 | 752 | 24 | 208 | 32-byte record: inherited two-byte pool, second pool at +C, two halfwords at +18/+1A, opaque tail |

## Reconstructed behavior

Each original array has signed count, capacity and data pointer at +0/+4/+8.
Growing reserves exactly the requested count when required, then placement
constructs the added elements and updates the count. Shrinking destroys elements
in reverse index order. A signed-byte keep flag selects whether capacity is
retained; otherwise the allocation is resized or freed to the new count. The
same original allocator functions implement allocate, resize and free.

The nested pool constructor clears its count, capacity and pointer. Its destructor
walks live elements, frees capacity times the established element stride, and
preserves the original duplicate pointer clears. Empty inline destructors emit
the original counted loops naturally, including the remaining counter increment
present in these specializations. The derived vector adds the second observed
null test before pool cleanup; direct pool variants have one test.

The curve record's original initialization first installs
`__vt__24CurveRecordBase_802E9E08`, clears word zero and sets halfword +4 to -1,
then installs `lbl_802E9E40` before calling the native curve base constructor at
+C. Two ordinary inline base layers reproduce this member initialization order;
the inline record destructor restores the record table before destroying the
curve and its pool. The four additional cleanup destructors it emits are unused
and separately frozen. The 28-byte pair variant leaves its first opaque word
untouched. The 32-byte pair variant clears halfword +1A before +18, preserving
the observed constructor order.

## Strict verification and integration

All units use GC/1.3.2, ordinary `-O4,p` flags, C++ exceptions off and
`-use_lmw_stmw on`. Existing external function names are unchanged. Every
production source was recompiled after formatting and private type naming.

The local verifier applies all real relocations, checks every retained original
byte and exact global symbol extent, and accounts for all emitted allocated
sections and function extents. The original DOL hash is checked by the copied
verification core. Unused weak functions have raw byte hashes and separately
checked real relocation counts. No retained relocation references an unused weak
function. There is no relocation masking and no credited code outside each
original function extent. `verify.py` passes all eight production sources.

The full original exception index and constructor table were audited. None of
the eight functions has an exception record or startup constructor reference.
Their original split units own only text; all other functions in those units
remain outside these partial text splits. Referenced allocator globals, native
curve base methods, vtables and remaining text keep their existing ownership.

The integrator must publish the exact original text splits, check that all nine
`unlinked_functions` symbols are absent from the linked ELF, then pass the full
original DOL hash and native match regression checks before accepting source
credit. No shared metadata edits or full link were performed by this agent.
