# Bit record insert

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/bit_record_insert.cpp` reconstructs `fn_802257EC`, original `.text` range `802257EC..80225A50` (612 bytes), as ordinary C++.

Finds an unused bit in the existing record pool, increments the used count and either assigns the reused 0xA8-byte record or appends through the existing helper. The append path extends the word vector and initialized count; both paths set the corresponding bit and return the index. The inline unused-index helper uses explicit if/else returns, preserving the original branch layout. Local declarations emit no storage; original globals, tables and called helpers retain their ownership.

Run `python3 scratch/game_bit_record_insert/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
