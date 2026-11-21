# Movie plane unpacker continuation

These candidates remain private research and earn no matching-source credit.

The unpacker `fn_80291334` at `80291334..802915F8` writes odd bytes of two-byte
plane elements. It uses one value/run reader pair for luma (`618C`, `61B4`) and
one pair for the shared chroma symbols (`61A0`, `61C8`). Zero values introduce a
run length; nonzero chroma values split into low and high nibbles. Every row
advances the output cursor by four extra bytes.

The tree is the same `int child[2][512]` layout verified by the accepted symbol
reader. A direct inline bit helper, with the shift before the position store
and the bit mask after it, reproduces the native instruction sequence. Nested
inlining requires `-inline auto,level=2` with GC/1.2.5. Reusing one short value
across both plane loops restores the native value register; chroma reader,
row-count and output declarations then restore their native register choices.

The best candidate is `scratch/movie_worker_continuation/plane_order_235014.cpp`.
It emits all 708 bytes and the native `48`-byte stack frame, with no allocated
relocations or helper functions. Forty instruction words remain different:
36 are one tree-pointer/bit-position register swap repeated in the four inline
symbol traversals, and four are the chroma initializer load schedule. The
entire remaining loop body, branches, increments, shifts and stores match.
Declaration, source-expression, helper-reference, parameter, type, compiler
version and optimization probes are retained in the same scratch directory;
none earns source credit.

The adjacent predictor `fn_802915F8` at `802915F8..80291734` was reconstructed
in `predictor.cpp`. It uses three planes, signed value symbols accumulated until
a non-boundary symbol, zero runs, and an average of the current output byte and
next byte from the preceding row as the next predictor. The two external
reader call relocations resolve to their real original addresses. The 316-byte
candidate remains different in register allocation, frame size and a few
structural choices; it is not ready for integration.
