# Memory-card file existence probe

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/card_file_exists.cpp` reconstructs `fn_80277EC8`, original `.text`
range `80277EC8..802780BC` (500 bytes). This ordinary C++ reconstruction is
an isolated exact match awaiting central integration.

The function resumes the card worker, locks the owner's mutex, probes and
releases any work area, then mounts for a file-open test. It retries a busy
CARDOpen at most 1,000 times while sampling and reporting reset-switch changes.
It closes a successful open, returns status 5 for failure, and releases the card,
work area, mutex and worker on exit. The native no-card path returns 1.
The original pooled diagnostic string base is retained explicitly; its three
message offsets are 0xF4, 0x114 and 0x134. The existing frozen owner header is
reused; its original fields retain the accepted layout.

Run `python3 scratch/game_card_file_exists/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all 500 emitted text bytes and every actual
relocation. The verifier checks the complete allocated object, exact global
function extent and relocation site/kind/symbol/addend/target, including SDA21
small-BSS base selection and displacement. It applies real relocations before
comparing bytes against the protected original DOL.

No weak helpers, initialized data, BSS, padding or other allocated sections are
emitted. Original pooled strings, worker storage, reset flags and all called
helpers retain external ownership. Candidate, actual-relocation and original
metadata JSON preserve hashes and dependencies. Original extabindex, `.ctors`
and `.dtors` audits find no overlapping exception entry or table reference into
this range. This partial text-only split leaves adjacent code and data external.
Central integration must still pass full DOL hash, native objdiff, source-extent
and regression checks. No new symbols, owned data or special flags are needed.
