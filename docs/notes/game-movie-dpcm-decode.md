# Movie DPCM decoder

`fn_80295FAC` at `80295FAC..802963C0` is a 1,044-byte text-only reconstruction
in `src/Game/movie_dpcm_decode.cpp`. Its only dependency is the independently
accepted 89-row delta/index table at `lbl_802F23A0`. The function is global and
keeps its observed C linkage. Its inferred channel record is declared in
`include/Game/movie_dpcm_decode.h` and is 24 bytes.

The decoder reads signed DPCM deltas, saturates each predictor to
`-32768..32767`, and advances its step index. Stereo mode two decodes one
channel per nibble and writes output in reverse channel order. Other channel
modes duplicate the mono sample; an odd mono sample count consumes only the
high nibble of its final byte. Output wraps at the first channel's recorded
end pointer. Modes one and three seed the predictors from packed bytes or a
full signed sample plus a separate index. The count includes an initialized
sample when either initializer runs. No added bounds or mode validation is
inferred.

The preceding probe reproduced every body instruction but reserved a
`0x58`-byte frame, compared with the original `0x38`. Completely expanding
the seed helpers removed reference-parameter slots and reduced this to
`0x48`. Reusing the seed `high`, `low`, and signed `value` variables across
branches then reproduced the native frame and all three saved-register
offsets. Their declaration placement is part of the match. The mono seed
sample remains cached across its two stores, and each index-table access
retains a temporary byte cursor to preserve the original instruction order.

`python3 scratch/movie_dpcm_continuation/verify.py` compiles the production
source with GC/1.2.5 and the existing movie flags. It verifies all emitted
allocated sections and the global function symbol, applies both real table
relocations (`ADDR16_HA` and `ADDR16_LO`), then compares all 1,044 code bytes
with the verified original DOL. There are no emitted data, BSS, helper
functions, padding, or exception sections. The compiler's single
nonallocated `.mwcats.text` metadata relocation is accounted for separately.
The candidate and relocation manifests remain in the same scratch directory.

This split covers only the decoder text, not a complete original translation
unit. The earlier frame decoders have separate source ownership, the DPCM
tables have separate data ownership, and code after `802963C0` remains
outside this split. The dedicated split is now linked from Matching source;
the standard build passes the original DOL hash, native objdiff reports every
function byte matched, and the source-extent and regression checks pass.
