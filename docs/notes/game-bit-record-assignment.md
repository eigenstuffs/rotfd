# Bit record assignment

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/bit_record_assignment.cpp` reconstructs `fn_80225A50`, `.text` range `80225A50..80225C58` (520 bytes), as ordinary C++.

Copies the concrete 0xA8-byte bit record field by field: four initial float/vector groups, a 64-bit token, four owned handles through release/copy/retain assignment, four further float-vector groups, and scalar/token fields. The alignment gaps at 0x34 and 0xA4 are not copied. Native handle assignment and ordinary component assignment preserve alias and load/store ordering.

Run `python3 scratch/game_bit_record_assignment/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only the retained `.text` bytes are emitted; no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
