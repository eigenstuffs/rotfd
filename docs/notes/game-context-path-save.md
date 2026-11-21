# Context path save wrapper

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/context_path_save.cpp` reconstructs `fn_80262428`, original `.text`
range `80262428..8026248C` (100 bytes), as ordinary C++.

The wrapper assembles a path in the original 128-byte local buffer: the existing
five-byte small-data prefix, context name at offset 0x868 and external suffix
`lbl_802AEF74`. It dispatches to `fn_80262AFC` using the existing path manager
at global offset 0x14C. Inferred load/save terminology distinguishes the two
wrappers; original file-format semantics remain unconfirmed.

Run `python3 scratch/game_context_path_save/verify.py`. Standard optimized GC/1.3.2 Game flags
reproduce every allocated byte, exact function extent and all actual relocations,
including SDA21 prefix ownership/base/displacement. Relocated instructions are
compared directly against the protected original DOL. No weak helpers, owned
data, BSS, padding or other allocated sections are emitted. All strings and
manager objects remain external. Original extabindex, `.ctors` and `.dtors`
audits find no overlap or reference into this range. Candidate, relocation and
original-metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external.
Central integration must pass full DOL hash, native objdiff, source-extent and
regression checks. No new symbols, shared headers or special flags are needed.
