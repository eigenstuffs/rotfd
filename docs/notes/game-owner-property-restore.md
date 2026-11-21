# Owner property restore

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_property_restore.cpp` reconstructs `fn_80220260`, `.text` range `80220260..802203A8` (328 bytes), as ordinary C++.

Zeros movement at owner offset 0x144 from the external vector constant, calls virtual slot 0xD0 with the index, resolves its handle through slot 0x9C, restores saved position/rotation/scale from arrays at 0x40/0x4C/0x58 to resolved object offsets 0xB8/0xC8/0xD8, then refreshes and applies the object through native helpers.

Run `python3 scratch/game_owner_property_restore/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only the retained `.text` bytes are emitted; no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
