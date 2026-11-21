# Table and base destruction

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-table-base-destroy.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/table_base_destroy.cpp` reconstructs `fn_8027937C`, 104 bytes at
`8027937C..802793E4`. For a nonnull receiver it installs the original table at
`802EDCA8` into offset `08`, invokes `fn_801C9C00` with deletion disabled,
and releases the receiver if the signed low half of its own deletion flag is
positive. It returns the receiver. The private view records only the observed
table offset and does not claim a complete class layout.

Run `python3 scratch/game_table_base_destroy/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all 104 emitted text bytes after six actual
relocations. Only the original global function and `.text` are allocated;
there are no weak helpers, owned data, BSS or padding. Every allocated byte and
relocation matches the protected original DOL. The original extabindex,
`.ctors` and `.dtors` audit finds no overlapping exception entry or reference
into this range. Candidate, relocation and original metadata JSON preserve
all isolated evidence.

The original table, base destructor, allocator and neighboring functions
remain externally owned. Full DOL, native objdiff, source-extent and regression
acceptance remain the integrator's checks for this partial text split.
