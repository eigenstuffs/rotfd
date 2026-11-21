# Memory-card file replacement

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/card_file_replace.cpp` reconstructs `fn_80278BE4`, original `.text`
range `80278BE4..80278E1C` (568 bytes), as ordinary C++.

The operation resumes the card worker, locks the existing mutex and probes the
card. After releasing any probe work area, it sets the existing operation flag,
prepares the card, retries busy deletion up to 1,000 times and retains the
original reset-switch diagnostics. The native inline switch treats deletion
results 0 and -4 as success; it then delegates to `fn_80276F9C` with the original
name and two additional arguments. Other deletion results map to 6. It clears
the operation flag and releases the card, work area, mutex and worker on exit.
The no-card path returns 1. The frozen owner header is reused without changes.

Run `python3 scratch/game_card_file_replace/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce every allocated byte, exact function extent and
all actual relocations. The verifier checks relocation site, kind, symbol,
addend and target, including SDA21 section/base/displacement, then compares the
relocated instructions against the protected original DOL.

No weak helpers, initialized data, BSS, padding or other allocated sections are
emitted. Diagnostic strings, worker storage, operation/reset flags and all
called helpers retain external ownership. Original extabindex, `.ctors` and
`.dtors` audits find no overlap or reference into the range. The candidate,
actual-relocation and original-metadata JSON preserve hashes and dependencies.
This partial text-only split leaves neighboring functions and data external.
Central integration must pass the full DOL hash, native objdiff, source-extent
and regression checks. No new symbols, owned data or special flags are needed.
