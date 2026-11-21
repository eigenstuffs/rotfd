# Owner property snapshot

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_property_snapshot.cpp` reconstructs `fn_80220124`, `.text` range `80220124..80220260` (316 bytes), as ordinary C++.

Resolves the indexed handle through virtual slot 0x9C, copies position at resolved 0xB8, rotation at 0xC8 and scale at 0xD8 into owner arrays at 0x40/0x4C/0x58, then releases/replaces/retains the associated handle in the array at 0x64. Component assignment operators preserve the original float loads/stores; handle references preserve alias and retention order.

Run `python3 scratch/game_owner_property_snapshot/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only the retained `.text` bytes are emitted; no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
