# Four-vector record reset

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-vector-record-reset.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/vector_record_reset.cpp` reconstructs `fn_8027C40C`, 204 bytes at
`8027C40C..8027C4D8`. It iterates the signed count at `A4`, copies the supplied
three-float vector into fields `20`, `2C`, `38`, `44` of each 144-byte record
in the array at `AC`, and writes `FFFF` into the first halfword of each
four-byte flag record in the array at `104`.

The partial layout in `vector_record_reset_internal.h` preserves explicit
float-member assignment and the four independent array accesses. These emit
the native repeated data-pointer loads, including possible aliasing with the
supplied vector. The loop retains the original record, flag and integer-index
induction variables. The second flag halfword and other record fields are not
modified.

Run `python3 scratch/game_vector_record_reset/verify.py`. Standard GC/1.3.2
Game flags emit only the original global function and exactly 204 text bytes,
which match the protected DOL without any relocations. No weak helper, other
allocated section, data, BSS or owned padding is emitted. All allocated bytes
are checked. The original extabindex, `.ctors` and `.dtors` audit finds no
overlapping exception entry or table reference into this range. The candidate,
actual relocation and original metadata JSON preserve the isolated evidence.

This partial text split leaves neighboring functions and all original data
under existing ownership. Full DOL, native objdiff, source-extent and regression
acceptance remain the integrator's checks.
