# Owner motion target assignment

Ordinary C++ `fn_80229728` matches all 532 original bytes at `80229728..8022993C`, including 20 actual relocations. Source: `src/Game/owner_motion_target_set.cpp`. Verifier: `python3 scratch/game_owner_motion_target_set/verify.py`; standard GC/1.3.2 Game flags, no new headers/symbols/flags.

When the previous target handle at owner1B0 is valid, the routine retains a three-zero-layer temporary copy, assigns a four-zero-layer empty temporary to the stored handle, and calls fn_80229098 on the resolved old target with a separate four-layer empty handle. Both temporaries are released at their original scope boundaries. A valid new input clears velocity150, copies that into movement144, and clears flags bit35. It always clears bit34, then assigns the input handle with release/copy/retain. The flags field is 64 bits at30.

Genuine nested handle lifetime, const-reference temporary arguments and component assignments reproduce all stack slots, aliases, retain/release operations and redundant 64-bit stores. No assembly or register directives are used.

All 988 allocated text bytes are accounted: 532 retained plus five unreferenced weak destructor backups totaling 456. The verifier checks complete raw emitted bytes and all actual relocation identities, verifies no retained helper references, and requires final ELF helper absence. No data/BSS/padding is emitted. Complete original extabindex 80015F60..8001F2C0, constructor 80299920..80299980 and destructor 80299980..802999A0 allocations and padding are audited directly with no ownership or references to retained ranges. Frozen evidence is in `scratch/game_owner_motion_target_set/`. Central full-DOL/native-objdiff, source extent, regression and helper absence checks establish final acceptance.
