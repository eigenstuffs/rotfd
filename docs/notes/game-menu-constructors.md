# Menu base, Menu2D and Menu3D construction

Integrated and verified on 2026-09-27. These three partial text-only units add
832 code bytes and three functions, with no data credit:

| Source | Original range | Bytes | Actual relocations |
| --- | --- | ---: | ---: |
| `src/Game/menu_base_constructor.cpp` | `8021D968..8021DA0C` | 164 | 7 |
| `src/Game/menu2d_constructor.cpp` | `80216C9C..80216DE8` | 332 | 16 |
| `src/Game/menu3d_constructor.cpp` | `802193C0..80219510` | 336 | 17 |

The native base constructor initializes two derived handles, the type and
selector, an empty word array, a short count and a byte flag. The two derived
constructors pass type zero and selector six, initialize their handle members
and empty element storage, then replace the bitmap handle through the observed
release/copy/retain operation. Menu2D's scale is 1.0; Menu3D's is 1.1. Both set
the pulse to 0.7 and install the same default color groups. Menu2D has an
additional 12-byte color group that this constructor leaves untouched.
Field names are inferred working names, not recovered original identifiers.

`menu_base_native_internal.h` now supplies the native constructor declaration,
empty-array initialization, the observed short at offset 0x2C, and handle
assignment. `menu_constructor_internal.h` uses genuine native inheritance so
the compiler installs each derived table before constructing its members.
The previously integrated lifecycle units retain their documented flat ABI
views; their code still passes strict relocation checks after the table symbol
renames. The shared Menu destructor also retains its exact 388-byte match.

All virtual tables, RTTI, float constants and surrounding functions remain in
their existing owners. The base probe emits 604 bytes of weak helper code and
a 68-byte weak ManipulatorDraw table. Each derived probe emits 172 bytes of
weak helper code. None earns credit. The unreferenced helpers disappear through
normal dead stripping; the original strong ManipulatorDraw table/destructor
and ObjectsRoot destructor override the compiler's weak duplicates.

The factory calls and lifecycle table references now use the same native
symbol identities as the constructors. These are ABI identity changes only;
all previous source units remain exact. The complete rebuilt DOL is identical
to the original, the baseline is preserved, all 625 source units match, all
23 tests pass, and source extent and assembly-token audits pass.

Evidence: `scratch/game_menu_constructors/verify.py --production` verifies
all retained instructions with actual relocations and accounts for every
emitted allocated byte. Per-unit candidate and relocation records live beside
it. `scratch/menu_constructors_link_proof.json` confirms the final strong
symbols, discarded weak helpers and retained original table ownership.
`scratch/menu_constructors_checkpoint.json` records the full acceptance checks.
