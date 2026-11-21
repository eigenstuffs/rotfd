# Base owner arrays resize

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_base_arrays_resize.cpp` reconstructs original C entry `fn_80226AEC`, the full `.text` range `80226AEC..802271C0` (1,748 bytes), as ordinary C++. Its dedicated declaration is `include/Game/engine_base_arrays_resize.h`.

The routine first resizes the existing subarray at owner offset `180` through `fn_802271C0`. It then resizes five arrays whose count fields begin at `38`, `44`, `50`, `5C` and `6C`, with elements of 12, 16, 12, 4 and 40 bytes respectively. Each changed count obtains exact-size storage through the original allocator. Growth constructs added elements; shrinkage destroys removed elements before resizing. Empty plain-element lifetimes retain the native counted loops. The four-byte elements have two ordinary zero-initializing Handle layers around the existing native `Handle_801F7F10` constructor/destructor. The 40-byte element initializes fields at `14` and `10` to zero. Reusing the logical loop index across both branches preserves the native register allocation.

Production GC/1.3.2 compilation with default Game options plus `-use_lmw_stmw on` strictly matches all 1,748 retained bytes and all 93 actual retained relocations. The complete allocation contains the strong entry plus one ordinary unused weak `BaseResizeZeroHandle` destructor backup (84 bytes, two actual relocations). Every emitted function and byte is inventoried; no retained ELF relocation references the defined local backup, and it has no exception, startup or allocated-data reference. `default_discard_audit.json` records the ordinary default-discard proof. The external call to the next original function `fn_802271C0` retains its original target and is independent of the unlinked backup. No native override, alias, thunk, fixed-address object, assembly or payload transformation is used.

The complete frozen proposal is `scratch/engine_base_arrays_resize_20261011en/final_integration.json`. Run `python3 scratch/engine_base_arrays_resize_20261011en/verify.py` to rebuild and verify all retained bytes, actual relocation targets, the full allocated symbol inventory and frozen hashes. The original full `extabindex` range `80015F60..8001F2C0`, `ctors` range `80299920..80299980`, and `dtors` range `80299980..802999A0` have no reference into this function. Data, BSS, exception/startup records and padding ownership are zero. All original C/native Handle identities, allocator data, subarray routine and neighboring code retain their owners. No consumer migration is needed.

This frozen isolated handoff awaits central NonMatching registration, full native linking and original-DOL/regression acceptance before credit.
