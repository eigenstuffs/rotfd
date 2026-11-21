# Remaining movie-platform probes

These probes remain private research with no matching-source credit. The
accepted initialization, display worker and storage units have separate notes.

The 168-byte audio DMA worker at `8028D814..8028D8BC` waits on the semaphore at
pool offset `4648`, saves the current audio address, and conditionally submits
DMA. Its byte count subtracts that address from record word `04` in the two
`30`-byte records at offset `4660`. It masks the DMA length down to 32-byte
alignment, stores the cache range, starts DMA, clears the pending flag and
polls until completion. If the second shared audio address equals the saved
one, it signals the semaphore at `4654`, then clears the saved address.

The best ordinary C++ probe is 164 bytes. Its record address folds into an
indexed base plus immediate `4664`; the original separately adds record-base
offset `4660` and field offset `04`. Struct/array views, inline lookup helpers,
pool settings, separate BSS declarations and compiler versions have not solved
this difference. A typed C storage-view probe instead emits 184 bytes and
hoists semaphore addresses into extra saved registers. The production storage
match does not turn any worker probe into matching code.

The 480-byte converter at `8028DB38..8028DD18` consumes planar luma and two
chroma planes and writes packed YCbCr framebuffer words. It processes two rows
at a time, with an output pitch of `500` bytes and a pair-row advance of `A00`
bytes. Each inner iteration packs eight pixels from each row into four words;
both output rows are flushed separately. The chroma plane lengths use half
width times half height; the inner end uses twice the width with its low bit
cleared. No new bounds checks or altered rounding are inferred.

Four word temporaries per row and an inline row helper reproduce the native
load/store scheduling. The best full 480-byte probe still differs in 32
instruction words: chiefly the luma/second-chroma saved registers and initial
plane-size scheduling. All 24 row-helper argument orders preserve that result;
read-only views and compiler versions do not resolve it. Moving the entire
row-pair loop into a helper grows the object and is a recorded unsuccessful
probe. No masks, patched objects, assembly or fuzzy scores earn credit.

Sources, real-relocation comparisons and probe results remain in
`scratch/game_movie_platform/`. Recompile the restored source before trusting
an object left by a variant script. The shared table builder, plane records,
workspace initializer and first frame decoder now have accepted source units.
The second frame decoder at `80295A04` now has an accepted source unit. A generic inline
bit-reading helper reproduces the 100-byte reader at `802912D0` in size, but
19 instruction words differ in register allocation. Value types, declarations,
register hints and position lifetime variants do not yield a complete match.
The current byte-reader source is restored to that private 19-word probe.

The audio decoder at `80295FAC..802963C0` reads signed DPCM deltas from the
accepted 89-step table, saturates each predictor to -32768..32767 and updates
its step index. Stereo mode two decodes one channel from each nibble and writes
samples in reverse channel order. Other channel modes duplicate mono output;
an odd final mono count processes only the high nibble. Output wraps at the
first channel's recorded end pointer. Initializer modes one and three use
packed predictor/index bytes or a full signed sample with a separate index.

The first ordinary C++ probe emitted 1,060 bytes. Caching packed seed bytes
reduces it to 1,048; reference cursor helpers initially emit 1,040. Returning
an explicitly narrowed signed sample through an integer helper restores the
full-seed conversions. Caching the mono seed sample across both output stores
removes two alias reloads. A temporary byte cursor for index-table lookup and
the original per-channel store order then reproduce the complete decoder body.

The preserved private source emits 1,044 bytes. Its eight remaining instruction
differences were subsequently resolved by expanding the seed helpers and
reusing their temporaries. The [accepted decoder](game-movie-dpcm-decode.md)
now reproduces the native `38`-byte frame and all saved-register offsets and
passes full integration. The original private probe remains preserved.
Compiler versions, optimization flags, register hints and expanded seed helpers
have not solved the frame. Earlier sources and logs remain private. Recompile
`movie_dpcm_decode.cpp` before trusting an object left by a variant script.
The delta/index tables are independently accepted source data.
