# Memory-card available-space query

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-memory-card-query.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/memory_card_query.cpp` reconstructs `fn_802781E4`, 340 bytes at
`802781E4..80278338`, using the partial owner view shared with its wrappers.
It resumes the worker and locks the mutex, runs the original preparation
routine with argument 0, and retries `CARDProbeEx` while its result is -1.
It then unmounts and releases any work-area storage. A zero result returns 1
through the original unlock/suspend path. Otherwise it prepares with argument
1, runs the original capacity check, aligns free bytes down to the sector
size, unmounts/releases storage again and returns through unlock/suspend.
The native result values and branch behavior are preserved, including retaining
zero when the second capacity check returns a value other than 1.

The explicit `probe ? 0 : 1` expression reproduces the native count-leading-
zeros/right-shift Boolean conversion; equality and logical-negation variants
produce a different equivalent mask instruction in this compiler.

Run `python3 scratch/game_memory_card_query/verify.py`. GC/1.3.2 with the
standard Game flags emits exactly 340 text bytes and the original global
symbol. All bytes match the protected original DOL after twenty-four actual
relocations. No extra allocated section, weak function, owned data, BSS or
padding is emitted. The original extabindex, `.ctors` and `.dtors` audit finds
no overlapping exception entry or table reference into the retained range.
`candidate.json`, `actual_relocations.json` and `original_metadata_audit.json`
preserve the complete isolated evidence.

The worker at `80341038`, release allocator at `801EF5C8`, preparation and
capacity routines, SDK calls and neighboring functions remain externally owned.
This is a partial text split; full DOL, native objdiff, source-extent and
regression acceptance remain the integrator's checks.
