# Hierarchy group deactivation: historical near-match

The preserved probe below has been superseded by the exact source in
[`game-group-deactivate.md`](game-group-deactivate.md). Its historical near-match
source and failing verification remain reproducible; they receive no separate credit.

`scratch/game_group_state/deactivate_near.cpp` reconstructs the behavior of `fn_801FEE10` at `0x801FEE10..0x801FEF6C` but is not registered or credited as matching source. The candidate emits the correct 348-byte routine with 55 differing bytes after all ten actual retained relocations are applied. `config/GSQE78/candidates/game-group-deactivate-near.json` and `scratch/game_group_state/deactivate_verification.json` record the exact failure and source/object hashes.

The method resolves the indexed hierarchy group, calls `fn_80202464`, resets the game size to one, and assigns an empty native handle to game slot zero. It then scans the collection and reactivates each valid group whose assigned offset is nonnegative. The default handle construction performs the native constructor plus two zero stores, followed by by-value assignment and native destruction with flag zero.

The remaining differences concern the first manager/entry lookup schedule and nonvolatile register assignment: the original retains `self` in r29, the loop index in r30 and its scaled offset in r28; the candidate uses r28, r29 and r30 respectively. Control flow, native temporary cleanup and routine size agree. Const getters, manager capture, explicit-if resolution, manager/group lookup members, subscript accessors and loop variants were explored in the private scratch directory without improving this allocation. The normalized instruction-text probe is diagnostic only.

Run `python3 scratch/game_group_state/verify_deactivate.py`; its expected exit status is failure. It compares every retained byte without masks and checks the protected original DOL hash. The compiler emits 520 allocated text bytes: this 348-byte routine plus two unreferenced weak destructor bodies totaling 172 bytes/four relocations. Their weak bindings, exact extents, complete coverage and lack of retained references are checked. There is no owned data or padding, and all source credit remains zero. The adjacent exact activation routine has a separate source and manifest.
