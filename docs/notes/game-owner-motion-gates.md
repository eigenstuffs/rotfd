# Owner motion gates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two independent callbacks recover guarded vector motion. The manifest list is `scratch/game_owner_motion_gates/manifest-list.json`; both consumers of the new frozen `include/Game/owner_motion_gate_views.h` are verified. GC1.3.2 uses standard optimization and extra `['-Cpp_exceptions on']` for each.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_motion_reverse_gate_800975bc.cpp` | `800975BC..8009769C` (224) | `8000F5A8..8000F5B0` | `8001ADC0..8001ADCC` |
| `src/Game/owner_motion_lower_gate_80097724.cpp` | `80097724..800977B4` (144) | `8000F5B8..8000F5C0` | `8001ADD8..8001ADE4` |

The reverse callback queries a scalar and sets control five when above agent limit `0x394`. Otherwise it queries a second scalar and sets control eight when above `0x3D8`. Passing both gates obtains a vector, negates it with an ordinary vector return-by-value operator, then calls agent virtual slot `0x1A0` with the vector and incoming delta. The constructor, unary operator and component assignment reproduce the native three reverse loads and floating negations without emitted helper bodies.

The lower callback obtains a scalar and vector. It sets control five when below limit `0x3DC`; otherwise it forwards the vector and delta to virtual slot `0x1A0`. Ordinary inline float accessors reproduce the native comparison registers.

Strict verification proves all408allocated bytes: 368 text and40exception/index bytes. Each emits exactly one contiguous function and its extab8/index12, with actual local ELF object names. All eight text relocations, four owned EH-index references and two nonallocated metadata references are audited. Full original DOL SHA1 and complete exception/constructor/destructor ownership checks pass. No external data, BSS, weak helper, padding or original gaps are claimed. Full executable acceptance remains centrally owned.

The target action at `80097188` remains private and excluded from production. `scratch/game_owner_motion_gates/FINDINGS.md` preserves its bounded register-only comparison.
