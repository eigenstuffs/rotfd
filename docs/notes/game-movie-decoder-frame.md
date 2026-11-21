# First movie frame decoder

`src/Game/movie_decoder_frame.cpp` owns the 1,296-byte function at
`802954D0..802959E0`, with no data. The fourth incoming argument is unused.
The function preserves the shared decoder workspace, initializes frame bit
readers and calls the original decoding routines for three output planes.

The frame header has mode/scale bytes, unsigned halfword dimensions at `04`
and `06`, and sixteen word offsets at `08..47`. Those offsets locate segments
relative to the payload beginning at `48`. Each reader receives its segment's
first word at reader offset `04`, a pointer to the next word at `00` when that
first word is nonzero (otherwise null), and -1 at `0C`. Reader word `08` is
preserved. Reader offsets in initialization order are:

`618C, 61B4, 61A0, 61C8, 60D8, 6150, 61DC, 60EC,
6164, 61EC, 6100, 6178, 61FC, 6114, 6128, 613C`.

The overlapping offsets in the final records retain the original access
pattern; no complete original workspace class is asserted. Four reader buffers
receive a 256 sentinel, then a signed-short conversion of the original token
decoder's result or zero for an empty segment. Their shared mode/scale globals
remain original data. The scale byte also sets the observed positive and
negative limits at workspace offsets `6CC8` and `6CCC`.

Three original routines prepare the workspace and frame dimensions. A final
three-iteration loop decodes each plane into the output, advancing by the
record's pixel count. Those callees remain unfinished original source work.

GC/1.2.5 matches all instructions. The inline initialization helper uses byte
offsets to preserve overlapping storage. Explicit buffer/reader lifetimes and
declaring the plane cursor before the loop index restore the native register
allocation and schedule. Private typed-field and helper variants remain as
research evidence.

The strict verifier checks eight real branch relocations and eight small-data
stores. This compiler records each small-data relocation at the instruction's
low halfword; verification applies it to the complete owning instruction.
One nonallocated metadata reference is checked separately. There are no emitted
helpers, owned data or comparison masks.

The linked ELF proof, byte-identical DOL, unchanged baseline/protected inputs,
all earlier source/header hashes and matches, source audits and all 23 tests
pass. The partial split adds one provisional native unit and preserves all
byte/function denominators. See `scratch/movie_decoder_frame_checkpoint.json`.
