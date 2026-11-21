# Movie plane flag and sample decode research

The isolated KB investigation covers the original C entries `fn_80293158`
(`80293158..80293574`, 1,052 bytes) and `fn_80293FA0`
(`80293FA0..802943D0`, 1,072 bytes). Both remain original assembly and earn no
source credit. Root separately owns the adjacent `802943D0` and `80294748`
investigations.

Current native identities, progress ownership, canonical sections, source-body
definitions and the complete original exception, constructor and destructor
tables were checked before the probes. Neither entry has table ownership or an
existing source split. This is private, partial-view reconstruction; no source,
header, central symbol, split or configuration replacement is proposed.

The first routine combines mode and option flag bits, then updates odd bytes in
three output planes selected by short index arrays. Mode one writes uniform
flags. Other modes use two Huffman readers and two run readers: the first plane
has its own symbol stream, while the second and third share the low and high
nibbles of one decoded symbol. The accepted `movie_decoder_symbol.cpp` bit and
tree reader structure supplies the ordinary inline implementation. A byte flag
local closes the original 1,052-byte instruction extent. The best bounded
declaration-scope probe still differs in 61 full words, including physical
register allocation and a 64-byte frame instead of the original 96-byte frame.
It has no allocated data, helper code, calls or actual relocations.

The second routine reads a packed two-byte block descriptor, chooses axes and
sample steps according to decoder orientation, and copies a four-by-four block
of high nibbles while tracking its minimum and maximum. It decodes one Huffman
delta into an accumulator and uses the original external BSS lookup table
`lbl_80373340` to scale the result. The ordinary sample helper and byte-backed
reader address probe emits the full 1,072-byte extent and all four actual HA/LO
relocations to that table. It still differs in 117 instruction words; the
compiler's reader field-address formation, pointer addition order, physical
registers and 48-byte frame differ from the original 56-byte frame. The initial
typed reader-array probe is eight bytes shorter because its pointer arithmetic
is folded. The BSS lookup remains borrowed and uncredited.

GC 1.2.5, `-O4,p`, normal individual saves and inline level two provide these
diagnostics. Bounded ordinary declaration scopes, separate tree/bit helpers,
reference-output and return-value forms, native member methods, unsigned flag
types, pointer accessors, deferred inlining and compiler optimizer options are
preserved. GC 1.3.2 is worse for the sample routine. No instruction replacement,
register constraints, aliases or object-payload changes were used. Instruction
comparisons resolve all actual relocations, rather than masking them.

Evidence is frozen under
`scratch/movie_plane_flag_decode_20261011kb/`: complete original bodies, current
ownership and body census, full original table audit, compiler logs, each
numeric diagnostic, `private_findings.json` and `frozen_private_sha256.json`.
Global build and acceptance remain with root; these near matches are not ready
for registration or promotion.
