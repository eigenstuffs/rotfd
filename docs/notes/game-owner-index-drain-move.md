# Owner index drain move

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_index_drain_move.cpp` reconstructs `fn_802279A0`, `.text` range `802279A0..80227A14` (116 bytes), as ordinary C++.

Repeatedly gets the first index through virtual slot 0x90, removes it through slot 0x12C, and restarts until the first index is negative.

Run `python3 scratch/game_owner_index_drain_move/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only the retained `.text` bytes are emitted; no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
