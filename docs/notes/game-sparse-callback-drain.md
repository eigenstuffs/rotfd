# Sparse callback drain

`src/Game/sparse_callback_drain.cpp` reconstructs `fn_8026863C`, the 344-byte
function at `8026863C..80268794`. It visits occupied callback records, resolves
each record object's related handle, invokes virtual slot `44` with the
record's context pointer, and releases the occupied bit while decreasing the
used count.

The record array is at `C170`, its data pointer at `C178`, and the occupied
bitset at `C17C`. The iteration limit and used count are at `C18C/C190`.
Each 16-byte record contains its object pointer, context, elapsed float and
duration float at `00/04/08/0C`. The object has the established native vtable
pointer at `08` and its related handle at `20`. The source expresses these
virtual calls through ordinary C++ inheritance. Names remain inferred.

The first/next search helpers are expressed on the containing layout view to
preserve the original high-offset address formation and pointer lifetimes.
A const-reference word accessor preserves the original separate word load for
the test and subsequent clear. Each bit is tested before clearing, so the
used count changes only when the bit was set. The bit-search implementation
at `80207B94` remains external and under original ownership.

GC/1.3.2 with the standard optimized Game flags emits exactly 344 text bytes,
one global function and four actual relocations (two bit-search calls and
two address halves for the original manager global). The verifier applies
all relocations and checks the complete emitted allocation against the
verified original DOL:

```
python3 scratch/game_sparse_callback_drain/verify.py
```

No weak functions, constants, data, BSS, constructor/destructor entries,
exception tables or alignment padding are emitted. Generated original
assembly references are ordinary calls and definitions, with no constructor
entry to transfer. The candidate and applied relocation inventory are in the
same scratch directory, alongside preserved exploratory probes.

This source is integrated and accepted by the full executable build. It is a partial
text split and does not establish an original translation-unit boundary.
All neighboring functions and original data remain outside this unit.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
