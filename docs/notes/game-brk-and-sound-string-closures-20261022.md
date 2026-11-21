# BRK movement name and GC sound header strings

Two adjacent original string gaps are now owned by existing matching C++ units.

| Source unit | Original `.rodata` extension | Evidence |
| --- | --- | --- |
| `movement_type_name_802AB058.cpp` | `802AB069..802AB078` (15 bytes) | Three bytes of internal alignment after `CSBPants_BRKMove`, then the global `SBPants_BRK\0` string used by the native type record at `80375B18`. |
| `platform_type_registry.cpp` | `802AD053..802AD060` (13 bytes) | One byte of internal alignment after the registry strings, then global `GCSound_Z.h\0` used by the sound resource factory. |

The compiler emits the exact 32- and 352-byte `.rodata` sections; objdiff
matches their bytes and symbols. The original DOL SHA-1 passes after linking
these source objects. `ninja changes` reports no match regressions, the source
extent audit and generated progress pass, and all 66 tests pass. Matched data
increases by 28 bytes, from 1,003,533 to 1,003,561 of the unchanged 1,030,936
bytes. Code remains 2,028,640 of 2,607,776 bytes.

The nearby `MENU_LOOP` string at `802AE90C` remains original-owned. A source
probe reproduced its ten bytes, but the following two-byte linker tail is
outside the compiler-emitted source section. Giving that tail a separate
linked object shifted the following strings; claiming it as source failed the
extent audit. Both bytes and the full original-data denominator are preserved.
