# Early owner pointer selection and paired flag operations

Frozen isolated ordinary C++ reconstruction, pending central integration. Batch97 retains 1,060 text bytes and 60 original exception metadata bytes.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| `fn_8006C324` | 412 | `8000C1C8..8000C1D0` | `80018EAC..80018EB8` | 14 |
| `fn_8006C508` | 280 | `8000C1D0..8000C1D8` | `80018EB8..80018EC4` | 6 |
| `fn_8006CB18` | 368 | `8000C234..8000C23C` | `80018F18..80018F24` | 6 |

`fn_8006C324` resolves the currently selected registration's owner, falls back to the global owner, saves it in the caller actor at3C4, computes the390 selection byte against the original external hashed name, and sets3D2 when the owner exists. `fn_8006CB18` sets or clears resource flag48 and resolved actor flag12 through the observed virtual getters. Both matched on the first ordinary probe.

`fn_8006C508` queries the resolved caller actor state, conditionally forwards its resource owner to the existing operation helper, then invokes the primary object's virtual completion slot. The native nullable adjustment of the secondary query pointer by-90 is reproduced by a genuine C++ multiple-inheritance downcast; the primary observed vptr is at8 and the secondary query subobject begins at90. No constructor, destructor, or vtable definition is emitted.

The dedicated header is only consumed by these three new production units. Its storage and virtual declarations reflect observed offsets and call sites; no native symbol identity changes are required. External context, string, and global query ownership remain with their existing units.

The verifier independently recompiles each frozen production source with GC1.3.2 `-O4,s -Cpp_exceptions on`, compares every emitted allocated byte after actual ELF relocation application, checks local EH object names/extents, and scans the full original extabindex80015F60..8001F2C0, ctors80299920..80299980, and dtors80299980..802999A0. Only the exact function's original EH/index records refer to each retained extent; no ctor/dtor slot points into them. Each object emits exactly its text plus extab8/index12. There are no weak helpers, owned literals, BSS, padding, aliases, or discarded allocated sections. One nonallocated compiler category relocation per function is separately accounted.

Manifests: `scratch/game_early_owner_pointer_flags/manifest-list.json`. Handoff: `scratch/game_engine_batch97/HANDOFF.md`. Baseline/configure/full linking remain root-owned.
