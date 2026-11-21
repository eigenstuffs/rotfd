# Further native array destructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary native array destructors recover 920 original code bytes and all 260 associated exception metadata bytes. Each uses the observed 12-byte count/capacity/data header, invokes trivial opaque element destruction, frees capacity through the existing array allocator, and zeroes the pointer. These follow the independently verified early array lifetime pattern without copying original instructions or metadata into source.

| Source suffix | Original text range | Element stride |
| --- | --- | ---: |
| `800B5E10` | `800B5E10..800B5EC8` | 4 |
| `800B57F0` | `800B57F0..800B58A8` | 4 |
| `800B58A8` | `800B58A8..800B5960` | 4 |
| `800B5D58` | `800B5D58..800B5E10` | 4 |
| `800AC098` | `800AC098..800AC150` | 88 |

Files are `src/Game/array_more_destructor_<suffix>.cpp`; native names are `__dt__14Array_<suffix>Fv`. The address-qualified class spellings and opaque element views establish lifetime behavior and observed stride only. The record fields, original template names and full original translation-unit boundaries remain unproven. No vtable or unrelated data is claimed.

The compiler supplies each original null guard, short delete-flag test, returned this pointer, custom allocator and unexpected-exception path. The ordinary allocator `throw()` specification generates each complete 40-byte exception table and 12-byte index. All use the established GC/1.3.2 destructor flags `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`, with no emitted helper, literal, BSS or padding.

Exact section addresses, native function/object extents, frozen source hashes and every actual ELF relocation are in `scratch/game_array_eh_more/final_integration.json`. Run `python3 scratch/game_array_eh_more/verify.py`. The five old `dtor_` names have no compiled source/header callers. Central registration replaces them with native identities while preserving addresses/attributes and regenerating fallback assembly. No alias, thunk, assembly, object patch or mismatch mask is introduced. Central production/full executable acceptance remains required.
