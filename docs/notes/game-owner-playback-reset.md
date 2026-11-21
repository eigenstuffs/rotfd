# Owner playback reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_playback_reset.cpp` reconstructs `fn_8022EC40`, `.text` range `8022EC40..8022ED80` (320 bytes), as ordinary C++.

Obtains and resolves the indexed handle, clears bit 0x80000 of its flags at 0x120, resolves the related handle at owner 0x1A8 and its player handle at 0x16C, calls playback seek/reset with the resolved object, invokes virtual slot 0xD4, and updates state at owner 0x180. Entry generation access preserves native manager-entry reloads.

Run `python3 scratch/game_owner_playback_reset/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only the retained `.text` bytes are emitted; no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
