# Native nested record and handle-array destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four genuine C++ destructors recover 860 original code bytes and all 208 associated exception metadata bytes. Production files are `src/Game/nested_lifetime_destructor_<suffix>.cpp`.

| Suffix | Native entry | Text bytes | Observed destruction |
| --- | --- | ---: | --- |
| `800218F8` | `__dt__15Record_800218F8Fv` | 176 | Three-layer handles at +90 and +8C |
| `80025634` | `__dt__14Array_80025634Fv` | 240 | 24-byte inherited records, each with a two-layer handle at +4 |
| `80036CB8` | `__dt__14Array_80036CB8Fv` | 224 | Three-layer native handle array, stride 4 |
| `80039AEC` | `__dt__14Array_80039AECFv` | 220 | Two-layer native handle array, stride 4 |

Array views use the observed signed count/capacity/data header, ordinary element destruction and capacity allocator, then zero their data pointer. The 24-byte inherited record emits both record/base null guards before its two handle-member checks; the three-layer handle array naturally preserves the extra branch using the same condition register. The separate record view claims observed handle offsets only, with unobserved fields and trailing size opaque. Original source type names and complete translation-unit boundaries remain unproven.

Native compiler lowering supplies null entry guards, member-address tests, signed-short delete flags, returned this pointers and custom allocator calls. Ordinary `operator delete throw()` generates each original unexpected-exception path and complete 40-byte exception table plus 12-byte index. These compile with the established GC/1.3.2 settings `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. No other allocated helper, literal, vtable, BSS or padding is emitted or credited.

Run `python3 scratch/game_nested_eh_lifetime/verify.py`; complete function/object extents, section addresses, frozen source hashes and actual relocations are recorded in `scratch/game_nested_eh_lifetime/final_integration.json`. Each original provisional `dtor_` name has no compiled source/header caller. Central registration replaces it with the native name while preserving the original address/attributes and regenerating fallback assembly. No alias, thunk, assembly, object patch or mismatch mask is introduced. Central production/full executable acceptance remains required.
