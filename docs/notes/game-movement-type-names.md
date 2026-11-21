# Movement-class name data

Six original GLOBAL NUL-terminated strings are reconstructed with ordinary
`extern "C" const char[]` initializers in separate partial data-only units:

| Original object | Bytes | Value |
| --- | ---: | --- |
| `lbl_8029A4D8` | 16 | `CProjectileMove` |
| `lbl_80299F58` | 17 | `CCollectableMove` |
| `lbl_80299E58` | 19 | `CTreasureChestMove` |
| `lbl_8029B5B8` | 17 | `CYellowJfishMove` |
| `lbl_802AB058` | 17 | `CSBPants_BRKMove` |
| `lbl_8029B670` | 16 | `CGreenJfishMove` |

All six native object identities, symbol extents, alignment, and 102 original
data bytes are verified before integration. Each isolated compiler object
contains exactly the declared `.rodata` allocation with native alignment 8;
there are no functions, helper code, exception metadata, relocations, aliases,
or claimed alignment gaps. Other original data and functions remain with their
existing owners. Existing accepted callers continue to use the same GLOBAL
names and original addresses.

The producer evidence in `scratch/game_movement_type_names_20261011/` records
the native and canonical ownership preflight, complete original/current-active
relocation and initialized-data census, and full original exception index,
constructor, and destructor tables. `verify.py` freshly recompiles all six
sources and checks every allocated byte using the unchanged strict verifier.
The producer handoff is isolated evidence; full-game acceptance is recorded
separately after integration. This permanently frozen producer note must not
be changed to record later progress.
