# Owner control guards

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two independent sources reconstruct owner controls and input guards. `scratch/game_owner_control_guards/manifest-list.json` lists the production manifests. The new `include/Game/owner_control_guard_views.h` is frozen and both consumers are verified.

| Source | Text | extab | extabindex | Object extras |
| --- | --- | --- | --- | --- |
| `src/Game/owner_control_guard_800942b0.cpp` | `800942B0..80094378` (200) | `8000F060..8000F068` | `8001AA24..8001AA30` | `['-Cpp_exceptions on']` |
| `src/Game/owner_input_guard_80094378.cpp` | `80094378..800944A0` (296) | `8000F068..8000F070` | `8001AA30..8001AA3C` | `['-O4,s','-Cpp_exceptions on']` |

The first function removes key `0x71` from its second argument, then checks controls zero, `0x35`, `0x38`, one and two in order. Any active control sets control `0xD`; otherwise an active control three sets control four. The control subobject lies at agent `0x318`.

The second function uses the existing context's input pointer at `0x164` and an ordinary local bool output. With control `0xD` or four active, it queries input `0xD` and sets agent byte `0x40A` when inactive. An inactive input three plus active controls `0x20` and `0x12` sets control zero. Inactive input `0xC` clears the signed byte at `0x404` if previously nonzero. Three assignments to the same bool local reproduce the original stack byte and global-context reuse.

Strict GC1.3.2 checks prove all536allocated bytes: 496 text and40exception/index bytes. Each source emits one contiguous function plus extab8/index12, with actual compiler ELF local names. All21text relocations, four EH-index references and two nonallocated metadata references are audited. The complete original DOL SHA1 and full exception/constructor/destructor ownership table audits pass. No original external allocation, weak function, BSS, padding or gap is claimed. Global build acceptance remains centrally owned.

The adjacent `800966D8` triple-vector reset was subsequently accepted on 2026-10-15 as `src/Game/actor_three_vector_reset_800966D8.cpp`: 200 code bytes and 20 exception/index bytes. Enclosing agent member setters preserve the native source-address folding and register allocation. Its separate frozen contract and full native acceptance are in `scratch/continuation_20261012_b/actor-three-reset-acceptance.json`. All 66 current tests and prior ownership checks pass. The earlier near probes in `scratch/game_owner_control_guards/FINDINGS.md` remain preserved.
