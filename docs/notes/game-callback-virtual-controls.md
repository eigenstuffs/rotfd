# Callback virtual control wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/callback_virtual_controls.cpp` reconstructs **four complete adjacent
functions and 432 bytes** at `8025BB14..8025BCC4`. Private C++ prefix types
place the virtual pointer at `+08` and the observed 64-bit state field at `+38`.
Only virtual declarations are emitted; original tables retain their owners.

`fn_8025BB14` (84 bytes) invokes virtual slots `5C` and `60` with zero.
`fn_8025BB68` (64 bytes) calls original `fn_80258654`, then virtual slot `80`.
`fn_8025BBA8` (180 bytes) calls original setup, slots `80` and `28`, then
conditionally looks up and assigns a handle when state bit four is set.
It destroys the resulting temporary through the original native ABI.
`fn_8025BC5C` (104 bytes) invokes original base setup, installs the observed
table pointer, clears state bit one, sets state bit four, and returns the
receiver. Ordinary unsigned 64-bit operations reproduce both word halves,
including the original constant-mask operations.

`scratch/game_callback_virtual_controls/verify.py` recompiles the frozen
production source and checks all allocated bytes, all four global function
extents, and actual relocation targets. All 432 bytes match, with no emitted
data, exception sections, weak methods or padding. The original table,
manager, string and dependency functions remain external. Central original
ownership audit, full-DOL hash and regression checks remain required.

The initial neighboring startup probe at `8025BCC4` had five register
differences and remains preserved. Its exact 160-byte reconstruction is now
accepted separately in [callback startup wrappers](game-callback-startup.md);
it is outside this source and manifest.
