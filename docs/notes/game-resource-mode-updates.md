# Resource mode updates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two independent source units recover the mode-controlled resource flag updates:

| Source | Function | Text | extab | extabindex |
| --- | --- | --- | --- | --- |
| `src/Game/resource_mode_set_8006b968.cpp` | `fn_8006B968` | `8006B968..8006B9D4` (108) | `8000C148..8000C150` | `80018DEC..80018DF8` |
| `src/Game/resource_mode_clear_8006b9d4.cpp` | `fn_8006B9D4` | `8006B9D4..8006BA68` (148) | `8000C150..8000C158` | `80018DF8..80018E04` |

The genuine virtual resource getter occupies table offset `0x14`, with the compiler-generated vptr at query offset four. Resource flags are at offset `0x38`. Mode zero updates mask `0x100000000000`; mode one updates `0x1000000`; other values make no change. The set and clear routines preserve the original branch structure and 64-bit read/modify/write order.

Both use the new frozen `include/Game/resource_mode_update_views.h`. GC 1.3.2 requires Object extras `['-O4,s', '-Cpp_exceptions on']`. Each source emits only its one function, eight exception-table bytes and twelve exception-index bytes. The two actual retained relocations per unit are the exception-index references; the virtual calls need no external relocation.

The strict per-unit verifiers in `scratch/game_resource_mode_updates/` confirm all 296 allocated bytes, actual ELF local object names, actual relocations, original DOL SHA1, and full original exception/constructor/destructor table ownership. The eight-byte intervening text at `8006BA68..8006BA70` remains outside the split. No literals, BSS, weak helpers, padding, or additional original functions are claimed.

The adjacent selected-name update `fn_8006BA70` remains private and uncredited: the best ordinary C++ probe has the correct 212-byte extent, actual relocation identities and instruction sequence except for one independent load/store scheduling swap. Further constructor, accessor and integer-type variants did not solve it; preserved findings are `scratch/game_resource_mode_updates/FINDINGS.md`.
