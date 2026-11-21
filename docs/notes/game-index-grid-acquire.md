# Grid record acquisition

`src/Game/index_grid_acquire.cpp` reconstructs `fn_80267400`, the 756-byte
function at `80267400..802676F4`. It removes the first free record. When that
exhausts the free chain, it grows the record array by 16 and links the new
records into a free chain, then returns the original index and decreases the
free count.

The dedicated layout view preserves the grid free head/count at `20/24` and
the record array's count/capacity/data at `34/38/3C`. Each 20-byte record has
previous/next links, a temporary/free chain, cell index and context pointer at
`00/04/08/0C/10`. These names describe observed behavior. The constructor
initializes only the context pointer; the destructor has no actions. The
ordinary generic resize still emits its empty destruction loop and both
storage allocation branches, as in the original function.

This view is layout-compatible with `index_grid_records_internal.h`, but it
uses a signed index accessor and defines the observed constructor/destructor.
Keeping it separate avoids changing already verified units. A temporary
record pointer at the initial load and final chain store reproduces their
direct field instructions. Remaining accesses use the array's index accessor.
No compiler-specific assembly or raw instruction emission is used.

GC/1.3.2 with the standard optimized Game flags emits exactly 756 text bytes,
one global function and 18 relocations: six allocator calls and twelve high/
low address halves for the original allocator object `lbl_8028F698`. The
strict verifier applies all actual relocations and compares every byte to the
verified original DOL. The complete emitted object contains no weak functions,
constants, data, BSS, constructor table, destructor table, exception table or
alignment padding. References to this function in generated original assembly
are its definition and the original call from `fn_802672CC`; there is no
constructor-table entry to transfer.

```
python3 scratch/game_index_grid_acquire/verify.py
```

The same scratch directory contains `candidate.json`, the applied relocation
inventory, and preserved intermediate probes. This split is integrated and passes the original DOL SHA-1 and native objdiff. It is a partial text split, not a claim to
have recovered an original translation-unit boundary. Neighboring functions
and all original data remain outside this unit.
