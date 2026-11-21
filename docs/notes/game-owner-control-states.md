# Owner control states

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent sources recover control-state selection, clearing and motion gating. The manifest list is `scratch/game_owner_control_states/manifest-list.json`. All three consumers of the new frozen `include/Game/owner_control_state_views.h` are verified.

| Source | Text | extab | extabindex | Object extras |
| --- | --- | --- | --- | --- |
| `src/Game/owner_control_select_800944a0.cpp` | `800944A0..80094600` (352) | `8000F070..8000F078` | `8001AA3C..8001AA48` | `['-O4,s','-Cpp_exceptions on']` |
| `src/Game/owner_control_first_clear_80094600.cpp` | `80094600..800946FC` (252) | `8000F078..8000F080` | `8001AA48..8001AA54` | `['-Cpp_exceptions on']` |
| `src/Game/owner_motion_allowed_800946fc.cpp` | `800946FC..80094804` (264) | `8000F080..8000F088` | `8001AA54..8001AA60` | `['-Cpp_exceptions on']` |

The selector first calls the ordered clear function, then switches states zero through five to controls `0x1D/1E/1F/20/23/2A`. Its owner handle at `0x24` resolves through the existing signed generation/index manager. If the resolved object's state `0x84` equals one, it sets byte `0x9C` and control `0x22`. A nonzero screen field `0x2CC` adds control `0x37`; control `0x34` is always set. The ordinary six-case switch emits the native balanced comparisons without a jump table.

The clear function checks controls `0x1D/1E/1F/20/23/2A` in order and clears only the first active one. The motion predicate requires signed byte `0x405`, an active control among nine through twelve, and velocity Y at least the existing external threshold. If control eleven is active, it also requires no valid related handle at `0x1AC` and both angular/movement Y values at most the external scale times agent limit `0x3E4`.

Strict GC1.3.2 verification proves all928allocated bytes: 868 text and60exception/index bytes. Each source emits exactly one contiguous function with extab8/index12 and actual compiler local names. All34actual text relocations (including two SDA references), six EH-index references and three nonallocated metadata references are audited. The full original DOL SHA1 and complete exception/constructor/destructor ownership tables pass. Original context and floats remain external; no weak helper, extra data/BSS, padding or gaps are claimed. Full executable acceptance is centrally owned.
