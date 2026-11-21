# Handle-pair release loop

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/handle_pair_release_loop.cpp` reconstructs `fn_801B13C4`, `801B13C4..801B1440`, as an ordinary C++ loop. Each eight-byte array record has a key followed by a handle. The routine passes every handle by address to the global manager release function. It reloads the owner count on every iteration, preserving changes caused by release callbacks.

Standard GC/1.3.2 emits exactly124 bytes of `.text`, with three actual relocations: the context HA/LO pair and the release call. No inline helpers, constants, BSS, padding, or extra allocated sections are emitted. The original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`) contain no ownership for this range. The original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Run `python3 scratch/game_handle_pair_release_loop/verify.py` for complete allocated-byte, function-extent, actual-relocation identity, and original-table verification. The frozen manifest and evidence are in that directory. This partial text split claims no original neighboring functions or data. Central integration and whole-DOL acceptance are pending.
