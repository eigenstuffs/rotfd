# Movie smooth-block research

`fn_80291B88` at `80291B88..80291D20` remains private research with no matching
source credit. It writes a four-by-four block through the accepted 512-byte
clamp table `lbl_80373140`, centered at table offset 128. The five value
arguments behave as unsigned bytes: center, above, below, left and right.

The reconstructed arithmetic uses `base = 8*center + 4`,
`vertical = above-below`, `horizontal = left-right`, and corner terms equal to
the corresponding two neighbors minus twice the center. Each output index is
an arithmetic right shift by three. Rows combine the signed vertical and
horizontal differences with the corner terms or individual neighbor
differences; the exact formulas are preserved in the ordinary C++ probes.

The best candidate is
`scratch/movie_worker_continuation/smooth_inline_1_perm_0.cpp`. It emits the
native 408 bytes with the native `40`-byte frame and resolves the two actual
clamp-table relocations. Twenty-three instruction words remain different,
principally the early horizontal-difference/sum/difference temporaries and
subsequent scheduling. No masks or patched instructions were used. Probe
results, type/declaration/expression variants and compiler-option comparisons
remain in the same scratch directory.

Using byte parameters eliminates the extra 24 stack bytes from explicit
narrowed local variables; direct table indexing eliminates a saved clamp
cursor. Those observations are structural findings, not matching-source
credit. The independently accepted output wrapper currently declares this
external function with integer parameters; any later typed-byte declaration
must be coordinated and reverified across the wrapper's declaration and calls.
