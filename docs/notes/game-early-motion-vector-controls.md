# Early motion vector controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Batch 133 recovers two separate text-only original units as ordinary C++:

| Entry | Text | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
| `fn_800AA440` | 236 | `80010B34..80010B3C` | `8001BBF4..8001BC00` | 4 |
| `fn_800AB2FC` | 324 | `80010CB8..80010CC0` | `8001BC90..8001BC9C` | 6 |

The first function resolves virtual slot 0x9C's generation-checked resource handle and, unless resource property 0x10000 inhibits motion, saves the input vector and adds input times actor scale 0x36C to acceleration 0x358. Scalar vector assignment and ordinary `operator*`/`operator+=` reproduce the original load and arithmetic sequence.

The timed control obtains a vector returned by value from `fn_800AB440`, updates elapsed time by rate times delta, copies the velocity to the actor, and marks its group's status active. After its duration expires it sets the actor's origin flag, starts controller state zero and copies the resolved resource transform position into the actor. The native vector return uses the ordinary hidden result pointer ABI. Explicit component construction preserves the native reverse component loads when copying the final transform position.

Production sources are `src/Game/early_motion_vector_control_800aa440.cpp` and `src/Game/early_motion_vector_control_800ab2fc.cpp`, with a dedicated header `include/Game/early_motion_vector_control_views.h`. Both use GC1.3.2, `-O4,s`, and C++ exceptions. Only the timed function requires `-fp_contract on` to emit the original fused elapsed-time multiply-add. No data allocation, BSS, padding, weak function, identifier migration or link alias is introduced. All other original neighboring functions and data remain outside these two units.

Each strict verifier rebuilds the production source, checks its exact function and local EH symbol names/extents, applies every actual relocation and compares all allocated bytes to the supported original DOL. Full original extabindex, constructor and destructor tables are audited; each function retains its sole EH record and has no constructor/destructor pointer ownership. All 560 text bytes and 40 EH/index bytes pass in isolation. Central integration and full executable acceptance remain with the root integrator; these isolated results alone do not establish source progress.

Private research in `scratch/game_early_motion_vector_controls` also preserves uncredited probes for `fn_800AAADC` (284 bytes, five FPR operands), `fn_800ABB3C` (200 bytes, five FPR operands), and `fn_8009AB94` (276 emitted versus 296 original). Clamp expression/helper/declaration variants and vector expression/constructor forms did not close the first two; the last function additionally commons five handle index/tag reload instructions that the original retains. No assembly or register forcing was used. Those scopes are released, their artifacts remain intact, and no matching credit is claimed for them.
