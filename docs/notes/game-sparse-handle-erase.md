# Sparse handle erase

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/sparse_handle_erase.cpp` reconstructs `fn_8026B560`,
`0x8026B560..0x8026B768` (520 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

The pool's count/capacity/data occupy `0/4/8`; its bitset occupies `0xC..0x1C`,
followed by limit/live counts at `0x1C/0x20`. It iterates occupied indices with
`fn_80207B94` until an entry resolves to the same object as the input handle.
A valid matching object has its states at `0xD9F8/0xD9FC` cleared. If the slot
is still occupied, the function destroys its two-layer handle, clears its
occupancy bit, and decrements the live count. It then exits the scan. A virtual
manager call at table slot `8` runs after either a match or exhaustion.

The reference word accessor and signed-char ternary preserve the original
normalized bit test. The destruction accessor uses an unsigned element index,
while bit arithmetic and traversal remain signed, preserving a fresh element
offset calculation. Direct `words[index >> 5] &= ~mask` reproduces native
register reuse; separately named word/mask locals leave seven register-only
differences. Layered helper types describe the observed cleanup sequence
rather than asserting original class identities. No assembly or aliases are used.

Run `python3 scratch/game_sparse_handle_erase/verify.py` to reproduce the
frozen proof: 520 retained and emitted bytes and six actual relocations.
There are no weak tails or additional allocated sections. Original DOL SHA1
and full original extabindex/constructor/destructor table bounds are verified.
No data, BSS, padding, or original table ownership is retained. This is a
partial text split of its containing original translation unit.
