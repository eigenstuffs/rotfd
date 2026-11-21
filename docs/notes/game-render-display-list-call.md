# Render display-list call

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated exact source; central full-DOL acceptance pending.

`src/Game/render_display_list_call.cpp` reconstructs all 144 bytes of
`fn_802828FC`, at `802828FC..8028298C`. It saves 28 vertex-descriptor records,
clears descriptors, selects indexed position attribute 9/type 3, synchronizes
and invalidates the vertex cache, and binds the owner's position array with
stride 12. It calls the receiver's display list only when both original fields
at offsets `0x110` and `0x114` are nonzero, using the byte count at `0x118`.
It then waits for drawing and restores the saved descriptors. The position
array remains at owner offset `0xBDC`.

GC/1.3.2 with the recorded standard Game flags reproduces every original byte
and all nine actual call relocations. The emitted object owns only its single
global text function. It has no data, BSS, literals, weak helpers, padding,
exception records or startup/shutdown pointers. Full original exception-index,
ctor and dtor scans find no references to the function range.

`scratch/game_render_display_list_call/final_integration.json` preserves the
complete callable inventory, source/object hashes, actual relocation targets
and ownership audit. `freeze.py` independently recompiles the production source
through the unchanged strict verifier. This bounded source split leaves the
neighboring renderer, vertex storage and original data under existing owners.
