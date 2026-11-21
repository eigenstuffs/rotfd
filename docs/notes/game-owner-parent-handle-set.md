# Owner parent handle set

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_parent_handle_set.cpp` reconstructs `fn_8022051C`, `.text` range `8022051C..80220608` (236 bytes), as ordinary C++.

Assigns and retains the input handle into owner offset 0x20, resolves that input, assigns and retains the resolved parent handle at 0x130 into owner offset 0x24, then calls virtual reset slot 0xD8 with zero. A local parent pointer preserves the original alias lifetime.

Run `python3 scratch/game_owner_parent_handle_set/verify.py`. Standard GC/1.3.2 Game flags verify every allocated byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. Only the retained `.text` bytes are emitted; no data/BSS/weak helpers/padding. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, actual-relocation and metadata JSON preserve evidence and hashes.

This isolated text split leaves neighboring functions and data external. Central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, headers or flags are needed. Source and evidence are frozen after handoff.
