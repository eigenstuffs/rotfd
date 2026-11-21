# Audio resource stream loading

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/audio_resource_stream.cpp` reconstructs `fn_802793E4`, original
`.text` range `802793E4..80279558` (372 bytes), as ordinary C++.

The loader invokes the existing base stream reader, consumes the owner's
16-byte fixed record and a separately allocated 76-byte native audio header,
then reserves ARAM from the existing audio manager. It fills the header's
16-bit start/end/loop halves using the native nibble-address arithmetic and
32-byte-aligned payload size. A local header pointer preserves the original
aliasing behavior while the owner size is reread between the two end halves.
It allocates a 32-byte-aligned temporary payload, advances the source cursor,
flushes the CPU cache, transfers the payload to ARAM and frees the temporary.
The owner retains its ARAM address and header allocation.

The local partial owner/header layouts emit no storage; existing shared headers
are unchanged. All pooled strings, allocator storage and the audio manager
retain external ownership. The base-reader's existing linker name is retained
with its two-argument native ABI.

Run `python3 scratch/game_audio_resource_stream/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce every allocated byte, exact function extent and
all actual relocations. The verifier checks relocation site, kind, symbol,
addend and target before comparing relocated instructions against the protected
original DOL. No weak helpers, initialized data, BSS, padding or other allocated
sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no
overlap or reference into the range. Candidate, relocation and original-metadata
JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external.
Central integration must pass the full DOL hash, native objdiff, source-extent
and regression checks. No new symbols, owned data or special flags are needed.
