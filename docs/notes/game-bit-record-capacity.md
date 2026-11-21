# Bit record capacity

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/bit_record_capacity.cpp` reconstructs `fn_802271C0`, original `.text` range `802271C0..80227380` (448 bytes), as ordinary C++.

Resizes the owner record capacity through the existing helper, updates the requested bit count and grows the word vector when required. The inline vector reserve/resize methods preserve original allocation paths, capacities and native empty construction/destruction loops. Initializes the newly covered bit range through the original bit helper and updates the initialized count. Local declarations emit no storage; original globals, tables and called helpers retain their ownership.

Run `python3 scratch/game_bit_record_capacity/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
