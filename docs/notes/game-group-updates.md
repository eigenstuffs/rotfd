# Nested group queries and update traversal

Three routines are recovered in two bounded source fragments sharing `src/Game/group_runtime_internal.h`:

- `group_find_device.cpp`: `0x801FF834..0x801FF9C8`, 404 bytes and four relocations.
- `group_updates.cpp`: `0x801FFA58..0x801FFC94`, 572 bytes and eleven relocations.

The isolated verifiers `scratch/game_group_updates/verify_group_find_device.py` and `verify_group_updates.py` confirm every allocated code byte and emitted section alignment with GC/1.3.2 and `-O4,p -inline deferred -use_lmw_stmw on`. Neither fragment owns data. Whole-DOL byte equality, native objdiff checks and the original-source regression audit pass.

The nested query validates each group member's related handle, scans its list at `+0x90` using the count at `+0xDC`, and validates those handles. It calls the resolved child's virtual method at table offset `+0x78` with `-1`, resolves the returned handle, and compares that object's identifier at `+0x20`. The first matching outer index is returned, otherwise `-1`. The filename's device terminology is provisional; original object identities and the identifier's exact meaning are unestablished.

The first update method calls the main game object's virtual slot at `+0x50`, then invokes slot `+0x1C` for each resolved dynamic-list object and each of four validated fixed handles. The second skips its work when the group's byte at `+0x20` is nonzero, calls the context helper at `0x8023AAAC`, and forwards a floating-point argument to `0x8020349C` for every resolved list object. A caller at `0x8020C344..0x8020C350` loads that argument with `lfs` from `0x80377FF4`, supporting the reconstructed `float` parameter.

The private C++ inheritance layouts place object vtables at `+8` and the main game's vtable at `+0x278`; virtual dispatch uses ordinary C++ calls. The shared loop index across dynamic and fixed traversal preserves the original register lifetimes. Source names describe observed roles without claiming original declarations. No raw assembly, volatile workaround, patched instruction, or masked comparison is used.

The intervening 144-byte capacity query at `0x801FF9C8` remains uncredited. `scratch/game_group_updates/near-match.cpp` preserves an exact-size version with seven differing register bytes; its source subtracts active objects' counts from four. The later constructor at `0x801FFC94` is outside both candidates. The protected original DOL SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
