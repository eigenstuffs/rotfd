# Owner primary property position scale

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_primary_property_position_scale.cpp` reconstructs `fn_8021F858`, original `.text` range `8021F858..8021F8F4` (156 bytes), as ordinary C++.

Obtains the primary handle with constant index zero through virtual slot 0x9C and resolves its signed index/generation pair. Forwards a position pointer and scalar through the original combined helper using the native double scalar ABI. Local declarations emit no storage; original globals, tables and called helpers retain their ownership.

Run `python3 scratch/game_owner_primary_property_position_scale/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
