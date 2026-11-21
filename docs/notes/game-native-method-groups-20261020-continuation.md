# Seven native method and runtime-base groups

Seven original `.data` intervals now extend their preceding accepted
runtime-base-list source units:

| Existing source suffix | Added interval | Added bytes | Contents |
| --- | --- | ---: | --- |
| `802B8550` | `802B860C..802B87A0` | 404 | CProjectileMove method table |
| `802BB2E8` | `802BB3F4..802BB598` | 420 | CWildSnailMove method table |
| `802BCA18` | `802BCB24..802BCCC8` | 420 | CRBObjBaseMove method table |
| `802C17A8` | `802C1808..802C1850` | 72 | LoadingScreen method table |
| `802C8240` | `802C8260..802C82C8` | 104 | Helmet-state method and base records |
| `802C8698` | `802C872C..802C88B0` | 388 | CSBPants_BRKMove method table and five-entry base list |
| `802C8E28` | `802C8E88..802C8EE8` | 96 | CNoCamDraw method table and two numeric member-pointer descriptors |

The source paths are `src/Game/native_rtti_base_lists_<suffix>.cpp`.
All enclosing source intervals start and end on eight-byte boundaries, matching
the compiler section alignment. GC/1.3.2 emits exact enclosing extents of
592, 688, 688, 168, 136, 536, and 192 bytes. The production source objects
contain 119, 133, 132, 26, 23, 105, and 26 actual relocations respectively.

The new records preserve 13 original global objects and 444 new pointer
relocations with the same symbol identities, relocation kinds, and zero
addends. No function-interior addresses or adjusted-thunk aliases are used.
Private candidates, prior sources, exact verification results, and the
integration manifest are in `scratch/native_data_scout_20261020_parallel/`.

These partial data splits add 1,904 matched bytes. Referenced functions and
runtime descriptors retain their existing owners. The complete DOL passes
the expected SHA-1 check, `ninja changes` is empty, the source extent audit
passes, and all 66 tests pass.
