# Bézier control-point grid assembly

`fn_801D8068`, original text `801D8068..801D8458` (1,008 bytes), is private,
uncredited research in `scratch/engine_bezier_grid_control_points_20261011kn`.
Current original identity, progress, accepted canonical sections and existing
source/body artifacts were checked before reconstruction. The adjacent matched
forwarder remains unchanged. Full original exception-index, startup and
shutdown table scans find no references or metadata ownership for this leaf.

The function fills a four-by-four grid of twelve-byte vectors. The patch view
has four sixteen-bit edge indices at +58 and a flag word at +60; bits 1 through
4 choose each edge's orientation. The mesh's pointer at +B8 addresses
eight-byte edge records, each containing two endpoint indices and two control
indices. A separate vector array supplies the selected points.

Each edge contributes one corner and two boundary control points. The four
triples populate grid slots (0,1,2), (3,7,11), (15,14,13), and (12,8,4).
The remaining points are derived as `grid[5]=grid[4]+grid[1]-grid[0]`,
`grid[6]=grid[2]+grid[7]-grid[3]`,
`grid[10]=grid[11]+grid[14]-grid[15]`, and
`grid[9]=grid[13]+grid[8]-grid[12]`.

Caching each patch edge index once before its three copies eliminates repeated
index loads. Byte-addressed edge backing storage with an ordinary inline typed
accessor then reproduces the original 1,008-byte text extent, 64-byte frame and
two saved general registers. A named reference to the first edge improves the
initial pointer schedule. The best result still differs in 121 instruction
words: the initial flag/index allocation and the four vector add/subtract
floating-point and temporary-store schedules. All scalar choices and output
slots agree semantically, but this is not an exact object.

Bounded variants cover typed edge members, direct byte-address controls,
separate accessors, reference versus pointer setup, signed choice variables,
constructor and member-assignment vector returns, explicit copy construction,
compound operators, named sums, by-value operator arguments, GC 1.2.5, and
space/propagation/scheduling options. None closes the remaining words. Numeric
literals, estimate intrinsics and external calls are absent from this routine.
The first exception-enabled diagnostic emitted extra compiler exception/index
allocations; subsequent exception-disabled leaf probes emit only text, as in
the original ownership census. All outputs are preserved.

Seven representative fresh compiles reproduce every raw ELF byte, all
allocated section attributes, complete symbols and zero actual relocations.
They emit exactly one GLOBAL 1,008-byte function and no helper or data. This
proves reproducibility of the private near matches, not matching progress.
No production file, accepted source, shared header, central configuration,
original executable or strict verifier core changed.
