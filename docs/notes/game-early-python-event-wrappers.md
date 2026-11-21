# Early Python event wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Fifteen independent source units reconstruct owner-to-Python event dispatch. The frozen manifest list is `scratch/game_early_python_event_wrappers/manifest-list.json`. All 15 consumers of the new frozen `include/Game/early_python_event_views.h` pass strict verification. Every unit uses GC1.3.2 with extra `['-O4,s', '-Cpp_exceptions on']`.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/python_event_wrapper_80067808.cpp` | `80067808..80067904` (252) | `8000BC14..8000BC1C` | `80018B64..80018B70` |
| `src/Game/python_event_wrapper_80067904.cpp` | `80067904..80067A0C` (264) | `8000BC1C..8000BC24` | `80018B70..80018B7C` |
| `src/Game/python_event_wrapper_80067a0c.cpp` | `80067A0C..80067B0C` (256) | `8000BC24..8000BC2C` | `80018B7C..80018B88` |
| `src/Game/python_event_wrapper_80067b0c.cpp` | `80067B0C..80067C0C` (256) | `8000BC2C..8000BC34` | `80018B88..80018B94` |
| `src/Game/python_event_wrapper_80067c0c.cpp` | `80067C0C..80067D0C` (256) | `8000BC34..8000BC3C` | `80018B94..80018BA0` |
| `src/Game/python_event_wrapper_80067d0c.cpp` | `80067D0C..80067E18` (268) | `8000BC3C..8000BC44` | `80018BA0..80018BAC` |
| `src/Game/python_event_wrapper_80067e18.cpp` | `80067E18..80067F1C` (260) | `8000BC44..8000BC4C` | `80018BAC..80018BB8` |
| `src/Game/python_event_wrapper_80067f1c.cpp` | `80067F1C..8006803C` (288) | `8000BC4C..8000BC54` | `80018BB8..80018BC4` |
| `src/Game/python_event_wrapper_80068158.cpp` | `80068158..80068254` (252) | `8000BC5C..8000BC64` | `80018BD0..80018BDC` |
| `src/Game/python_event_wrapper_80068254.cpp` | `80068254..80068358` (260) | `8000BC64..8000BC6C` | `80018BDC..80018BE8` |
| `src/Game/python_event_wrapper_80068358.cpp` | `80068358..8006845C` (260) | `8000BC6C..8000BC74` | `80018BE8..80018BF4` |
| `src/Game/python_event_wrapper_8006845c.cpp` | `8006845C..8006855C` (256) | `8000BC74..8000BC7C` | `80018BF4..80018C00` |
| `src/Game/python_event_wrapper_8006855c.cpp` | `8006855C..80068658` (252) | `8000BC7C..8000BC84` | `80018C00..80018C0C` |
| `src/Game/python_event_wrapper_80068658.cpp` | `80068658..80068754` (252) | `8000BC84..8000BC8C` | `80018C0C..80018C18` |
| `src/Game/python_event_wrapper_80068754.cpp` | `80068754..80068854` (256) | `8000BC8C..8000BC94` | `80018C18..80018C24` |

Each wrapper sets its event-active byte within 0x74..0x84, writes the original external event argument globals where applicable, and looks up a named handler on the Python object at owner offset 0x40. A found handler is passed to the existing no-argument call helper with its original additional zero argument. Call failure prints the Python error and reports through the diagnostics object at context offset 0x110; missing handlers use the original alternate report. Handler/result references are decremented with the native deallocation callback at type offset 0x18, then the active byte is cleared. Wrapper 80067F1C preserves its additional missing-handler diagnostic and abort call.

The partial Python object/type views expose only reference count, type pointer, and deallocation callback; no shared Python headers or source are modified. Existing native code leaves the result pointer uninitialized on a missing-handler path before its cleanup, assuming that required handlers exist (80067F1C additionally asserts this). These sources retain that original assumption and machine behavior; they do not add a result initialization absent from the executable. The existing call helper consumes only its first argument, while these callers retain their original second zero argument in the C ABI.

All method/error strings and event argument globals remain external. A local pointer to the original 8029BF50 string pool preserves its common-base addressing in six wrappers; no strings or other data are allocated by these units. Static inline reference cleanup emits no extra functions or sections.

Strict verification proves all 4,188 allocated bytes: 3,888 text and 300 exception/index bytes. Actual local ELF names, all 215 text relocations, 30 EH-index references, and 15 nonallocated metadata references are audited. The full original DOL SHA1 and complete extabindex/constructor/destructor ownership checks pass. No additional data/BSS, weak helper, padding, or gaps are claimed. Final executable acceptance remains centrally owned.

The adjacent 8006803C wrapper remains private and uncredited. Its ordinary source is four bytes short because the compiler reuses the current-owner global value, whereas native code reloads that global before the second comparison. Bounded ordinary getter, predicate, store-reference, comparison, and pointer-type variants did not resolve this difference; no volatile or other instruction-forcing workaround was used. See `scratch/game_early_python_event_wrappers/FINDINGS.md`.
