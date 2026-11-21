# Memory-card file deletion

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/card_file_delete.cpp` reconstructs `fn_8027857C`, original `.text`
range `8027857C..80278788` (524 bytes). This ordinary C++ reconstruction is
an isolated exact match awaiting central integration.

The function resumes the card worker, locks the existing owner mutex, probes
and releases any work area, then mounts to delete the requested file. It retries
busy CARDDelete results up to 1,000 times, preserving the original reset-switch
sampling and diagnostic calls. Its ordinary inline switch accepts native results
0 and -4 as successful deletion, mapping other results to 17. It releases the
card, work area, mutex and worker on exit; the no-card path returns 1.
The original pooled diagnostic base is retained explicitly. The existing frozen
MemoryCardOwnerView header is reused without modification.

Run `python3 scratch/game_card_file_delete/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all 524 emitted text bytes and all actual
relocations. The verifier checks every allocated byte, exact global function
extent, relocation site/kind/symbol/addend/target, and SDA21 small-BSS base
selection and signed displacement. It applies real relocations before comparing
instructions with the protected original DOL.

No weak helpers, initialized data, BSS, padding or other allocated sections are
emitted. Strings, reset flags, worker storage and all called helpers retain
external ownership. Candidate, actual-relocation and original-metadata JSON
preserve hashes and dependencies. Original extabindex, `.ctors` and `.dtors`
audits find no overlapping exception entry or table reference into this range.
This partial text-only split leaves neighboring functions and data external.
Central integration must still pass complete DOL hash, native objdiff,
source-extent and regression checks. No new symbols, owned data or special flags
are needed.
