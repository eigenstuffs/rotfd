# Early native array destructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary C++ destructors recover 772 original code bytes and all 208 associated exception metadata bytes. Each models the observed 12-byte array header (signed count/capacity and data pointer), invokes ordinary element destruction, frees the allocated capacity through the existing allocator and zeroes the pointer. The compiler preserves the original empty element loops and repeated null stores.

| Source suffix | Native destructor | Code bytes | Element lifetime/stride | Exception table | Exception index |
| --- | --- | ---: | --- | --- | --- |
| `80027688` | `__dt__14Array_80027688Fv` | 184 | Trivial 40-byte record | `80006460..80006488` | `80016560..8001656C` |
| `80027740` | `__dt__14Array_80027740Fv` | 220 | Two-layer native handle, 4 bytes | `80006488..800064B0` | `8001656C..80016578` |
| `8002781C` | `__dt__14Array_8002781CFv` | 184 | Trivial 16-byte record | `800064B0..800064D8` | `80016578..80016584` |
| `800278D4` | `__dt__14Array_800278D4Fv` | 184 | Trivial 12-byte record | `800064D8..80006500` | `80016584..80016590` |

Production files are `src/Game/array_destructor_<suffix>.cpp`. The address-qualified class spellings and opaque record views establish only observed lifetime behavior, not original template names or record fields. The handle array naturally emits two element-address null tests before the existing native handle destructor. No vtable or complete original translation-unit boundary is claimed.

Native destructor lowering supplies each entry null guard, signed-short delete flag, returned this and custom allocator call. The allocator's ordinary `throw()` specification generates each original unexpected-exception path and complete 40-byte exception table plus 12-byte index. These compile with the established GC/1.3.2 destructor settings `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. No extra helper, literal, BSS, padding, assembly or object patch is emitted.

Run `python3 scratch/game_array_eh_destructors/verify.py` for complete allocated-byte/function/object extents, frozen source hashes and actual relocation verification. Manifests are frozen in `scratch/game_array_eh_destructors/final_integration.json`. The four original provisional `dtor_` spellings have no compiled source/header callers; central registration replaces them with native identities while preserving addresses/attributes and regenerating fallback assembly. No alias, thunk or relocation mask is introduced. Central production/full executable acceptance remains required.
