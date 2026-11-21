# Movie weighted prediction block (private nonmatching research)

`fn_80293574` occupies `80293574..80293FA0` (2,604 bytes). It remains
**private, nonmatching and uncredited**. Evidence is preserved under
`scratch/movie_motion_block_20261011ke/`. No production source, accepted
header, central symbols, splits or configuration were changed.

The recovered ordinary algorithm accumulates one or more weighted 4-by-4
sample blocks, computes their mean, and obtains a 4-by-4 prediction through
the existing horizontal/vertical interpolation entries. It normalizes the
prediction around its rounded mean and measures its minimum and maximum.
Two bounded Huffman residuals determine an offset and amplitude. The routine
combines those corrections and writes a clipped output block.

The best extent-complete probe is `row_samples.cpp`, compiled with GC 1.2.5,
`-O4,p`, `-use_lmw_stmw on` and `-inline auto,level=2`. Its sole allocation is
2,604 bytes of `.text`, with the original GLOBAL C entry and ten actual
relocations: eight REL24 calls and one original clipping-table HA/LO pair.
The fresh object is byte-identical to the probe. **484 complete instruction
words differ** from the original; no masking is used. The original frame is
`0x140`, saving `r16..r31`; this probe uses `0x170`, saving `r18..r31`.

Explicit fixed-size sample operations reproduce the original fully expanded
fast multiply and prediction-normalization work. An unsigned accumulation
index avoids the extensive preload schedule of fully expanded addition.
Using a row pointer for prediction bytes closes the final nested-loop extent.
A named table pointer produces the original single global base, preserving
its clipping and reciprocal displacements. Bounded loop, pointer, helper,
scope, compiler-version, propagation, CSE, pooling and size variants remain
preserved. They do not close the frame, reader addressing and allocation.

The private table view spans the physically contiguous accepted clipping,
sample-scale and reciprocal arrays at `80373140..80373B80`. The last array
is read at original base displacement `0x240`. This is explicitly a partial
storage view, not a new allocation or an assertion that the accepted first
array's symbol owns the entire aggregate. The table producer, its three
symbols and all existing consumers remain unchanged. No data credit is
claimed. `borrowed_table_provenance.json` pins the accepted source, header and
canonical producer evidence.

The complete original exception-index, constructor and destructor tables have
no references to this function. `bounded_verification.json` records all
emitted allocations, symbols, actual relocations and the fresh compilation.
`frozen_private_sha256.json` seals the investigation and this note.
