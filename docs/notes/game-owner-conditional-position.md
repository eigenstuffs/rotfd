# Owner conditional position

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_conditional_position.cpp` reconstructs `fn_80223448`, `.text` range `80223448..8022352C` (228 bytes), as ordinary C++.

Returns a position by value. If the handle at owner offset 0x1F8 is valid, resolves it and calls virtual position slot 0xB0 with zero; otherwise calls the primary position helper. Genuine conditional temporary values and component copy construction reproduce the hidden output-pointer ABI and both stack temporaries.

Run `python3 scratch/game_owner_conditional_position/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only the retained `.text` bytes are emitted; no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
