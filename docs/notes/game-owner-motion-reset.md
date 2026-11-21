# Owner motion reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_motion_reset.cpp` reconstructs `fn_80224A10`, `.text` range `80224A10..80224B2C` (284 retained bytes), as ordinary C++.

Calls the prior cleanup helper, sets low-word motion flag bits 0x01800001 in the 64-bit field at 0x30, clears and propagates four position history vectors, resets the owned handle at 0x230 through a two-layer native handle temporary, and restores the state bytes at 0x250/0x258/0x22C/0x22D.

Run `python3 scratch/game_owner_motion_reset/verify.py`. Standard GC/1.3.2 flags verify every retained byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. All emitted allocations, function extents, raw hashes and relocation identities are verified. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range.

Only `.text` is emitted: 284 retained bytes followed by 2 unreferenced weak inline destructor backups totaling 172 bytes. Retained code references none. These helpers must be absent from the final ELF and earn no progress. No data/BSS/padding is emitted. Candidate, emission reference, actual relocation and original metadata JSON preserve hashes and evidence.

This partial text split leaves neighboring functions and data original. Central acceptance must pass the original DOL hash, native objdiff, source extents/regression and weak helper absence checks. No symbols, headers or special flags are needed. Source and evidence are frozen after handoff.
