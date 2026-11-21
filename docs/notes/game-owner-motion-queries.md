# Owner motion queries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent sources recover motion/position callbacks. The manifest list is `scratch/game_owner_motion_queries/manifest-list.json`; all three consumers of the new frozen `include/Game/owner_motion_query_views.h` are verified.

| Source | Text | extab | extabindex | Object extras |
| --- | --- | --- | --- | --- |
| `src/Game/owner_position_finish_80095c40.cpp` | `80095C40..80095CF0` (176) | `8000F2E0..8000F2E8` | `8001ABF8..8001AC04` | `['-O4,s','-Cpp_exceptions on']` |
| `src/Game/owner_motion_upper_800965bc.cpp` | `800965BC..80096668` (172) | `8000F3F0..8000F3F8` | `8001AC94..8001ACA0` | `['-Cpp_exceptions on']` |
| `src/Game/owner_motion_lower_800967a0.cpp` | `800967A0..80096830` (144) | `8000F408..8000F410` | `8001ACB8..8001ACC4` | `['-Cpp_exceptions on']` |

The position callback calls the agent's position query at virtual slot `0xB0`, with an ordinary three-float aggregate returned by value. The first result is discarded. If target event `0x39` is pending, or the second position's Y is at most agent `0x3C8`, it sets control five through agent subobject `0x318`. It then calls virtual slot `0x18C`. The inline height predicate preserves its agent across the aggregate-return call and reproduces the native saved registers and temporary locations.

The upper callback obtains two scalar outputs and compares them against agent limits `0x394` and `0x3D8`. An exceeded limit sets control eight; otherwise it obtains a vector and calls virtual slot `0x1A0` with the vector and incoming delta. The lower callback obtains a scalar and a second vector, calls the same virtual slot, and sets control five when the scalar is below agent `0x3DC`. Ordinary inline limit accessors reproduce the native floating register lifetimes. No helper body is emitted.

Strict GC1.3.2 verification proves all552allocated bytes: 492 text and60exception/index bytes. Each production source emits one contiguous function plus its own extab8 and index12, using actual local ELF names. All nine text relocations, six owned EH-index references and three nonallocated metadata references are audited against the original. The complete original DOL SHA1 and full exception/constructor/destructor table ownership audits pass. No extra code, data, BSS, weak helper, padding, or original gap is claimed. Full build acceptance remains centrally owned.
