# Owner handle index find

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_handle_index_find.cpp` reconstructs `fn_802256BC`, `.text` range `802256BC..802257EC` (304 bytes), as ordinary C++.

Iterates indexes through virtual first/next slots 0x90/0x94, obtains each handle through slot 0x9C, and compares resolved object identity with the requested handle. Returns the first matching index or -1. Resolving keeps the manager separately from its entries pointer so the second handle reloads entries, matching the original alias behavior.

Run `python3 scratch/game_owner_handle_index_find/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and both actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only 304 bytes of `.text` are emitted, with no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
