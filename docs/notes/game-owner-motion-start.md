# Owner motion start

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_motion_start.cpp` reconstructs `fn_80224888`, `.text` range `80224888..80224A10` (392 retained bytes), as ordinary C++.

Constructs native four- and five-layer handle values, passes a retained three-layer copy to activation, calls two startup helpers, sets motion flag bits 0x01800000, clears position and state, resets the owned handle at 0x230 through a native two-layer temporary, and restores state bytes. Genuine full-expression temporaries preserve the original stack slots and cleanup order.

Run `python3 scratch/game_owner_motion_start/verify.py`. Standard GC/1.3.2 flags verify every retained byte, exact function extent and actual relocation sites/kinds/symbols/addends/targets directly against the protected DOL. All emitted allocations, function extents, raw hashes and relocation identities are verified. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range.

Only `.text` is emitted: 392 retained bytes followed by 6 unreferenced weak inline destructor backups totaling 556 bytes. Retained code references none. These helpers must be absent from the final ELF and earn no progress. No data/BSS/padding is emitted. Candidate, emission reference, actual relocation and original metadata JSON preserve hashes and evidence.

This partial text split leaves neighboring functions and data original. Central acceptance must pass the original DOL hash, native objdiff, source extents/regression and weak helper absence checks. No symbols, headers or special flags are needed. Source and evidence are frozen after handoff.
