# Neighbor grid query

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/neighbor_grid_query.cpp` reconstructs `fn_80072468`, `80072468..8007256C`. It rejects an already active input node, clears the grid's selected neighbor, then checks left, right, up, and down in order. A successful check stores the adjacent index and returns one; otherwise it returns zero. Horizontal checks preserve the native row-boundary modulo tests.

The observed layout has signed-short grid width at `60`, count at `66`, selected neighbor at `68`, and inline records starting at `74`. Each record is `14` bytes with a node pointer at `04`. Nodes hold a signed-short index at `92` and a signed-byte active flag at `98`. A normal inline node index accessor preserves the original register allocation; raw field-access variants remain private diagnostics in `scratch/game_neighbor_grid_query`.

Standard GC/1.3.2 emits exactly 260 bytes of `.text`, no actual code relocations, and no extra functions, initialized data, BSS, padding, or headers. The full original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`) have no ownership for this function. The original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Run `python3 scratch/game_neighbor_grid_query/verify.py` to reproduce complete allocated-byte, extent, relocation identity and original-table verification. The partial text split claims no neighboring functions or data. Central whole-DOL acceptance is pending.
