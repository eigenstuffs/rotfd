# Named-world removal: preserved near-match

`src/Game/group_remove.cpp` reconstructs the removal routine at `0x801FF24C..0x801FF4F8` (684 bytes). It is **unregistered and credited with zero source bytes**. Strict relocation-aware comparison finds six remaining byte differences, all from the first search retaining its resolved object in r26 instead of original r25. Cleanup, native handle lifetime, container erase, and every later instruction are otherwise exact.

The routine finds the matching world's hierarchy, calls game/reset hooks, resets its hierarchy lists, unregisters its group handle, detaches members, retains the owner/world handle, destroys and erases the collection element, removes the retained world from the secondary collection, and finishes the dispatcher update. It assumes the search succeeds: the original has no negative-index guard before later array access. The caller at `0x802042EC` is registered as `RemoveGame`; this is removal, not selection.

`python3 scratch/game_group_remove/verify.py` deliberately fails at the remaining six bytes. Its complete allocated-section audit covers the 684-byte candidate and the two unreferenced weak destructor bodies (172 bytes/four relocations) excluded by ordinary dead stripping. No data or padding is owned. `scratch/game_group_remove_focused/strict-result.txt` records the failure and exact instructions. Its README preserves the bounded follow-up attempts, all of which left the best production source unchanged.

The separate `config/GSQE78/candidates/game-group-remove-near.json` records the source/header/object hashes and zero-credit status. It does not replace an accepted manifest. Original class/method names and the full translation-unit boundary remain unknown.
