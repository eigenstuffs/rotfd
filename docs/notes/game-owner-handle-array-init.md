# Owner handle array init

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_handle_array_init.cpp` reconstructs `fn_802435AC`, original `.text`
range `802435AC..80243640` (148 bytes), as ordinary C++.

Calls the existing base initializer, installs the external table, zeros the three fields at 0x74, constructs ten four-byte handles at offset 0x88 through the original runtime array helper, clears seven owner fields at 0xD8, and sets type 14. The local layout views emit no storage. All tables, globals and called helpers retain their original ownership.

Run `python3 scratch/game_owner_handle_array_init/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed.
