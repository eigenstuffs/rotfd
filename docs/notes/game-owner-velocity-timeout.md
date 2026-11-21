# Owner velocity timeout

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_velocity_timeout.cpp` reconstructs `fn_80229A78`, original `.text` range `80229A78..80229B4C` (212 bytes), as ordinary C++.

Tests flag bit 35 in the 64-bit field at 0x30. If enabled and remaining time at 0x174 is positive, subtracts the delta and calls virtual slot 0x124 when it falls below zero. Then advances position at 0x144 by velocity at 0x150 times the delta. A temporary three-float vector preserves the original separate multiply/add order. The zero constant stays external at `lbl_8037B138`; virtual declarations emit no vtable.

Run `python3 scratch/game_owner_velocity_timeout/verify.py`. Standard GC/1.3.2 Game flags reproduce every allocated byte, the exact function extent, and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly with the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no ownership or references into this range. Candidate, relocation and metadata JSON preserve hashes and dependencies.

This is an isolated verified text split; central integration must pass the original DOL hash, native objdiff and regression checks. No new symbols, shared headers or special flags are required. Source and evidence are frozen after handoff.
