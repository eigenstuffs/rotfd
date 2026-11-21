# Callback related-handle dispatch

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Eleven complete functions in eight bounded text units reconstruct 1,764
bytes. Partial native prefix types cover the observed flag field at `+38`,
handles at `+48`, `+60`, `+64`, and `+70`, and declaration-only virtual slots.
Original tables, global manager and handle-entry storage remain external.

The four 168-byte wrappers at `802537A8`, `802551F4`, `80257C78`, and
`80259F0C` preserve the signed-char base status, check a related handle with
the original out-of-line resolver, resolve its native signed generation/index
again, invoke slot `1C` when present, and return one after successful base
status. Their native repeated lookup is preserved rather than coalesced.

`802556CC` (132) performs original flag/key setup then related slot `34`.
The adjacent `80257338`/`802573E4` (172 each) dispatch original related-object
helpers only when their respective 64-bit state bits `40000`/`20000` are clear
and the original handle lookup succeeds. `80257490` (152) and `80257528` (164)
invoke related slot `20` with an index and mode one; the first supplies index
minus one, and the second forwards its incoming index. `80257AE8` (136) clears
the related object's byte at `+5E`. `8025A324` (164) calls original setup and
forwards its incoming pointer to related slot `84` when the handle is present.

`scratch/game_callback_related_dispatch/verify.py` recompiles final source,
applies actual relocations and verifies every allocated byte and all complete
global function extents. The objects emit no data, BSS, weak helpers,
exception records or padding. Central production verification, original-table
ownership audit, original DOL hash and baseline regression checks remain
required before matching acceptance.
