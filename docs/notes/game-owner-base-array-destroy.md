# Owner base array destroy

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_base_array_destroy.cpp` reconstructs `fn_8023106C`, original `.text` range `8023106C..80231140` (212 bytes), as ordinary C++.

Sets the owner table, invokes the slot-0x20 drain operation with (-1, 0), clears the capacity, destroys eight inline handles, releases the two layered member handles, calls the root destructor and applies the deleting-destructor flag. The virtual-call declaration reproduces the original indirect call registers.

Run `python3 scratch/game_owner_base_array_destroy/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce every allocated byte, the exact global function extent and all actual relocation sites, kinds, symbols, addends and targets. Relocated instructions are compared directly against the protected original DOL. No weak helpers, owned data, BSS, padding or other allocated sections are emitted. Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference into this range. Candidate, relocation and original metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external. Central integration must pass full DOL hash, native objdiff, source-extent and regression checks. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
