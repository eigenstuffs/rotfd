# Callback owner lifetime

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-callback-owner-lifetime.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/callback_owner_lifetime.cpp` reconstructs the two complete adjacent
native lifetime entry points at `8025F0D8..8025F240`: the destructor (208 bytes)
and constructor (152 bytes). The private field views expose only offsets used
by these functions. They do not claim the complete original class declaration.
The source uses ordinary C++ statements and calls the original native ABI
entry points for its base and handle members.

The destructor restores the table pointer at `+08`. While the global handle
manager at `lbl_801E9D24+124` exists, it unlinks the neighboring list pointers,
calls both observed cleanup helpers, and removes its handle at `+04` from the
manager. It then destroys its member at `+28`, destroys its base, and frees
storage when the native signed-short deletion flag is positive.

The constructor calls the base constructor, installs the original table, and
constructs the handle member. It assigns an empty packed handle through the
original reference update function and destroys the temporary. The signed
8-bit generation and signed 24-bit index reproduce the verified packed handle
layout used by other recovered handle functions. Finally, it clears the
observed list and state fields in their original order.

`python3 scratch/game_callback_owner_destructor/verify.py` checks every emitted
allocated byte, complete function bounds and global bindings, and all **18
actual relocations** against the normalized original DOL. There are zero byte
differences and no emitted data, constants, vtables, exception sections or weak
helpers. The original table, global manager storage and dependencies retain
their existing owners. Full-DOL acceptance and the original table ownership
audit remain the central integration gate; isolated match alone is uncredited.
