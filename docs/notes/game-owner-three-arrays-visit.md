# Owner three arrays visit

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_three_arrays_visit.cpp` reconstructs `fn_8022AFE8`, original `.text` range `8022AFE8..8022B168` (384 bytes), as ordinary C++.

Visits the three owner handle arrays at offsets 0x34, 0x68 and 0x74, resolving each handle and invoking the original object helper. Reusing one index variable between the loops reproduces the native reset moves and stride allocation. Local layout and virtual declarations emit no storage; the manager global, original tables and called helpers retain their ownership.

Run `python3 scratch/game_owner_three_arrays_visit/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
