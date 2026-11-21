# Callback key-state updates at 8025F3C8 and 8025F4F4

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-callback-key-update.json`. The full normalized DOL
passes its original SHA-1, `ninja changes` shows no regressions, source extents
and generated progress checks pass, and all 26 unit tests pass.

`src/Game/callback_key_update.cpp` reconstructs two complete 300-byte functions
in `8025F3C8..8025F620`. They search eight-byte key records and set the matching
record's byte state to zero or one. If no key matches, they grow capacity by
three when needed and placement-construct a new record with the supplied key
and state. Existing storage is resized through `fn_8028FAF4`, new storage is
allocated through `fn_8028FF24`, and a zero resulting capacity follows the
original release path. Capacity is read again after allocator calls before its
increment, preserving the native alias-sensitive ordering.

The state field is accessed through a byte view at its verified offset four;
this reproduces the original indexed byte store without assembly or volatile
access. Record stride, key offset zero and state offset four agree with the
neighboring lookup and array initialization/destruction routines. Private type
names remain provisional. External allocator objects retain their owners.

`python3 scratch/game_callback_key_update/verify.py` checks all 600 allocated
text bytes, both complete function symbols and every actual relocation using
GC/1.3.2. No weak helpers or nontext data are emitted or claimed. Full original
table ownership and executable acceptance await central integration.
