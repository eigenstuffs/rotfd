# Per-function query source replacements

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The grouped batch48, batch49, and batch50 source files and evidence remain preserved. Central integration requires one contiguous original extent for each emitted section in a source unit. Nine new per-function sources therefore replace those grouped handoffs for integration, retaining the same ordinary C++ bodies and their complete original exception metadata.

| Function | Production source | Text bytes | Required Object extras |
| --- | --- | ---: | --- |
| `80065A70` | `src/Game/owner_state_enable_80065a70.cpp` | 192 | `-Cpp_exceptions on` |
| `8006653C` | `src/Game/owner_state_compare_8006653c.cpp` | 156 | `-Cpp_exceptions on` |
| `80066AB0` | `src/Game/owner_state_value_80066ab0.cpp` | 152 | `-Cpp_exceptions on` |
| `800670B4` | `src/Game/owner_word_query_800670b4.cpp` | 124 | `-Cpp_exceptions on` |
| `8006727C` | `src/Game/owner_flag_test_8006727c.cpp` | 208 | `-Cpp_exceptions on` |
| `80067754` | `src/Game/resource_flag_test_80067754.cpp` | 180 | `-Cpp_exceptions on` |
| `80068FE4` | `src/Game/resource_state_forward_80068fe4.cpp` | 148 | `-O4,s`, `-Cpp_exceptions on` |
| `80069078` | `src/Game/resource_state_forward_80069078.cpp` | 148 | `-O4,s`, `-Cpp_exceptions on` |
| `80069218` | `src/Game/resource_state_forward_80069218.cpp` | 148 | `-O4,s`, `-Cpp_exceptions on` |

The first three sources share the new `include/Game/owner_state_query_views.h`, the next three share `include/Game/owner_flag_predicate_views.h`, and the last three share `include/Game/resource_state_forward_views.h`. Each header contains only the existing observed layouts, external declarations, and inline resolver; each has three verified consumers and is now frozen. No existing shared header was edited.

Every isolated source emits exactly its function, eight bytes of `extab`, and twelve bytes of `extabindex`, with no extra code, weak helpers, literals, BSS, or padding. The manifest list is `scratch/game_query_split_handoffs/manifest-list.json`; each manifest inventories the actual ELF local names and header hash. Its neighboring `verify.py` uses the frozen `scratch/game_query_split_handoffs/verify_common.py` to verify all allocated bytes, real relocation identities, original DOL SHA1, and complete original extabindex/ctors/dtors ownership. All nine strict verifications pass, covering 1,456 text bytes and 180 exception-table bytes. Central whole-DOL acceptance is pending.
