# Early native object destructor chain

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three genuine C++ destructors reconstruct 684 original code bytes and all 156 associated exception metadata bytes. The address-qualified class spellings describe observed private destruction views; original runtime/source names and complete class layouts remain unproven.

| Source | Native destructor | Original code | Exception table | Exception index |
| --- | --- | --- | --- | --- |
| `src/Game/objects_destructor_80026DB8.cpp` | `__dt__16Objects_802EB7C0Fv` | `80026DB8..80026F28` (368) | `80006218..80006240` | `800164F4..80016500` |
| `src/Game/objects_destructor_80026CF8.cpp` | `__dt__16Objects_802EB518Fv` | `80026CF8..80026DB8` (192) | `800061F0..80006218` | `800164E8..800164F4` |
| `src/Game/objects_destructor_80026C7C.cpp` | `__dt__16Objects_802EB940Fv` | `80026C7C..80026CF8` (124) | `800061C8..800061F0` | `800164DC..800164E8` |

The lower entry installs external table `lbl_802EB7C0`, destroys four-layer handles at +1B0/+1AC/+184 and three-layer handles at +180/+16C/+168, then calls the accepted ObjectsBase destructor. The middle installs `lbl_802EB518`, destroys a two-layer handle at +230 and a three-layer handle at +1F8, and calls the lower destructor. The upper installs `lbl_802EB940` and calls the middle destructor. Opaque gaps preserve observed offsets; the views do not claim unobserved trailing size or class members.

The compiler supplies each null guard, native signed-short delete flag, returned this pointer, ordinary automatic base/member destruction, and custom allocator call. The allocator's `throw()` specification generates each original unexpected-exception path and complete 40-byte exception table plus 12-byte index. Settings are the established GC/1.3.2 destructor flags `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. No extra allocated helpers, vtables, constants, BSS or padding are emitted or credited.

Strict verification covers every allocated byte and resolves all actual ELF relocations, including local metadata identities. Run `python3 scratch/game_objects_eh_chain/verify.py`. Complete frozen manifests and source hashes are in `scratch/game_objects_eh_chain/final_integration.json`. The three old `dtor_` spellings have no compiled source/header callers; central registration replaces those provisional labels while preserving original addresses/attributes and regenerating fallback assembly. No alias, thunk, assembly, object patch or relocation masking is introduced. Central production/full executable acceptance remains required.
