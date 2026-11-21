# Memory-card label copy

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-memory-card-labels.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/memory_card_labels.cpp` reconstructs `fn_80278E50`, 116 bytes at
`80278E50..80278EC4`. For a nonnull incoming string it logs the original
message, copies into the label at `3C4`, then copies up to 32 bytes from that
label into the buffer at `488`. The native unchecked first copy and potentially
unterminated 32-byte second copy are preserved. Field-array expressions avoid
an extra saved address register emitted by the compiler for raw pointer casts.

`include/Game/memory_card_init_internal.h` is a partial object view shared
with the initializer. Labels at `3C4`, `3E4`, `488`, zeroed storage at `428`,
the table at `30` and state words at `4CC..4D4` are supported by the initializer
and these operations. The view is not evidence of complete original class
ownership or a complete original translation unit.

Run `python3 scratch/game_memory_card_labels/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all 116 emitted bytes after seven actual
relocations. The object emits only the original global function and text,
without weak helpers, data, BSS or padding. Every allocated byte and relocation
is checked against the protected DOL. The original extabindex, `.ctors` and
`.dtors` audit finds no overlapping exception entry or reference into this
range; its table hashes and complete isolated evidence are in the three JSON
files alongside the verifier.

The message at `802AF308`, manager at `801E9D24`, copy routines and neighboring
functions remain external. Full DOL, native objdiff, source-extent and regression
acceptance remain the integrator's checks for this partial text split.
