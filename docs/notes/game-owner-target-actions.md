# Owner target actions

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent units recover target direction application, cached target dispatch and a target flag lookup. The frozen manifest list is `scratch/game_owner_target_actions/manifest-list.json`. The new frozen `include/Game/owner_target_action_views.h` has three verified consumers. All use GC1.3.2 with extra `['-O4,s', '-Cpp_exceptions on']`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_target_direction_8009f754.cpp` | `8009F754..8009F834` (224) | `8000FC78..8000FC80` | `8001B2C4..8001B2D0` |
| `src/Game/owner_target_dispatch_8009f834.cpp` | `8009F834..8009F9A4` (368) | `8000FC80..8000FC88` | `8001B2D0..8001B2DC` |
| `src/Game/owner_target_flag_lookup_8009fc1c.cpp` | `8009FC1C..8009FD38` (284) | `8000FCA0..8000FCA8` | `8001B300..8001B30C` |

Direction application skips inhibited resources, queries a two-component target direction, optionally reverses it, then assigns the three-component direction with zero Y. A normal inline helper returning the selected vector reproduces the native branch merge and common stores. Direct assignments within the two branches emitted duplicate stores.

Target dispatch checks inhibition, runs the ordinary inline cache refresh (the same behavior as the independently recovered cache function), then applies direction to a nonnull target. The flag lookup first checks eligibility, resolves the first collection entry through a generic object-entry view, resolves the typed owner handle, performs the existing lookup, resolves its handle result, and stores/returns bit zero of the 16-bit flag at0xBC. Separate generic and typed manager-entry views reproduce the native manager loads; one uniform typed view reused a load and remained four bytes short.

Strict verification proves all 936 allocated bytes: 876 text and 60 exception/index bytes. Each object emits only its function plus extab8/index12 with actual ELF local names. All14 text relocations, six EH-index references and three nonallocated metadata references are audited. Full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. No data/BSS, weak helper, padding or gaps are claimed. Final full executable acceptance remains centrally owned.
