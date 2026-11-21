# Owner primary property enabled

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_primary_property_enabled.cpp` reconstructs `fn_8021F23C`, original `.text` range `8021F23C..8021F2D0` (148 bytes), as ordinary C++.

Calls virtual handle lookup slot 0x9C with primary index zero, resolves the signed index/generation handle, and returns whether the object flags at 0x120 satisfy `(flags & 0x100400) == 0x400`. The native return type is `bool`; promoting its result to an `int` changes the final bit mask instruction.

Run `python3 scratch/game_owner_primary_property_enabled/verify.py`. Standard GC/1.3.2 Game flags reproduce every allocated byte, the exact function extent, and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly with the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, relocation and metadata JSON preserve hashes and dependencies.

This is an isolated verified text split; central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, shared headers or special flags are required. Source and evidence are frozen after handoff.
