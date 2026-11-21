# Owner composed orientation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_composed_orientation.cpp` reconstructs `fn_8022E158`, `.text` range `8022E158..8022E2AC` (340 bytes), as ordinary C++.

Resolves the indexed object and related owner, obtains the related primary handle through virtual slot 0x9C, combines the related and indexed orientations at object offset 0x30 into a local matrix through native multiplication, and copies the result to the output. Binding the last returned handle to a reference before resolving it as the multiplication argument preserves native output-pointer evaluation order.

Run `python3 scratch/game_owner_composed_orientation/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only the retained `.text` bytes are emitted; no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
