# Paired buffer destruction

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-paired-buffer-destroy.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/paired_buffer_destroy.cpp` reconstructs `fn_8027BAD4`, 144 bytes at
`8027BAD4..8027BB64`. For a nonnull receiver it frees nonnull pointers at
`1C38` and `1C3C` through the original allocator, clears both pointers, and
releases the receiver when the signed low half of the deletion flag is
positive. It returns the receiver, preserving the native deleting-destructor
entry behavior. The partial view records only these two pointer offsets.

Run `python3 scratch/game_paired_buffer_destroy/verify.py`. Standard GC/1.3.2
Game flags reproduce all 144 emitted bytes after nine actual relocations.
The strict inventory requires one original global function and `.text` only,
with no weak functions, data, BSS or owned padding. All allocated bytes and
relocations match the protected original DOL. The original extabindex,
constructor and destructor table audit finds no overlapping exception entry or
reference into the range. Complete isolated evidence is saved in the three
JSON files alongside the verifier.

The allocator at `801EF5C8`, release routine and neighboring functions remain
external. Full DOL, native objdiff, source-extent and regression acceptance
remain the integrator's checks for this partial text split.
