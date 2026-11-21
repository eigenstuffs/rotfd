# Owner state queries

`src/Game/owner_state_queries.cpp` reconstructs three functions:

- `fn_80065A70`, `80065A70..80065B30` (192 bytes), resolves the handle at `70` twice, sets bits `400` and `1000000000` in the resolved object's 64-bit flags at `30`, then forwards its original arguments to `fn_80063290`.
- `fn_8006653C`, `8006653C..800665D8` (156 bytes), obtains a handle through the virtual getter at table offset `28`, resolves it, and compares the integer at `320` to the unsigned-byte input.
- `fn_80066AB0`, `80066AB0..80066B48` (152 bytes), obtains and resolves the same virtual handle, calls `fn_8009F170`, and compares its scalar result with the supplied value.

The query type view uses a four-byte prefix followed by its compiler-managed virtual table pointer. Only the observed getter is called; preceding virtual declarations establish its table slot without defining or owning the original table. Typed 64-bit flag expressions preserve the native pointer allocation in the first routine. A named returned scalar preserves the comparison operand order in the last routine.

Standard GC/1.3.2 with the per-file option `-Cpp_exceptions on` emits exactly 500 bytes of `.text`, 24 bytes of `extab`, and 36 bytes of `extabindex`. The three disjoint exception allocations are `8000B95C..8000B964`, `8000BA6C..8000BA74`, and `8000BB60..8000BB68`; their index entries are `8001890C..80018918`, `80018A5C..80018A68`, and `80018A98..80018AA4`. No intervening original bytes are claimed.

`python3 scratch/game_owner_state_queries/verify.py` verifies every emitted allocated byte in all nine original ranges, all three function and six local-object extents, eight actual text relocations, six actual EH-index relocations, and three nonallocated metadata relocations. No weak helpers, literal pools, BSS, padding, or headers are emitted. The complete original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`) are audited: all three original EH owners are reconstructed and there is no ctors/dtors ownership. The DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Central whole-DOL acceptance is pending.
