# ObjectsBreak, ObjectsBounce, and ObjectsMove construction

Three reconstructed source fragments cover the contiguous four-function range
`0x80209A70..0x80209D30`: **704 text bytes**, with no owned data or metadata.
The accepted factories identify `ObjectsBreak_Z.h` (allocation `0x1F0`),
`ObjectsBounce_Z.h` (`0x1A8`), and `ObjectsMove_Z.h` (`0x1A8`). The shorter C++
names and intermediate-base names are reconstructed; complete original class
interfaces and translation-unit boundaries remain unknown.

| Source | Original function | Native symbol | Bytes |
| --- | --- | --- | ---: |
| `objects_break_constructor.cpp` | `fn_80209A70` | `__ct__12ObjectsBreakFv` | 160 |
| `objects_bounce_destructor.cpp` | `fn_80209B10` | `__dt__13ObjectsBounceFv` | 104 |
| `objects_move_constructors.cpp` | `fn_80209B78` | `__ct__13ObjectsBounceFv` | 60 |
| `objects_move_constructors.cpp` | `fn_80209BB4` | `__ct__11ObjectsMoveFv` | 380 |

The factory evidence is retained in `src/Game/factories_80209910.cpp`
(`fn_80209A18`) and `src/Game/factories_8020A134.cpp` (`fn_8020A134` and
`fn_8020A18C`). Central integration updates their constructor references to the
native spellings above; all three factory callers retain their exact original
linked bytes.

## Layout and source evidence

The constructor-only private header models the vptr at `+8` through native
inheritance from an eight-byte prefix. Its undefined virtual destructors keep
all vtables external. The lower base constructor is called at `0x80213EBC`;
its original class name is not established. The intermediate base extent is
`0x168`. It constructs handles at `+0x20`, `+0x24`, `+0x28`, `+0x68`, and
`+0x12C`, using two, two, three, two, and two zeroing layers respectively.
Zero-initialized triples are represented as private empty-array views, with a
separate zero word at `+0x78`. Array element types and the uninitialized gaps
remain unknown.

ObjectsMove constructs a one-layer handle at `+0x168`, a zero word at
`+0x16C`, a two-layer handle at `+0x174`, an empty array at `+0x180`, and the
already recovered 16-byte hash table at `+0x18C`. The inline hash constructor
calls the existing `fn_80207FC4` symbol directly. It zeroes `+0x19C` and
`+0x1A0`, then sets the word at `+0x170` to `-1`. ObjectsBounce adds no fields;
its constructor calls ObjectsMove and installs its own external vtable.
ObjectsBreak adds a four-layer handle at `+0x1A8` and five empty-array views
through `+0x1E4`. The trailing words `+0x1E8/+0x1EC` stay uninitialized.
Compile-time size checks preserve the factory allocation sizes.

Ordinary inline base construction reproduces the larger constructor's
otherwise unusual `this` copies (`r31` to `r0` to `r30`) before the lower-base
call. Each independent native constructor matches on its first structural
probe. No extra compiler pragma, artificial dependency, volatile access,
assembly, fixed-address alias, or instruction substitution is used.

The destructor uses the existing project's explicit-vptr ABI-view convention
in a separate source: it writes the ObjectsBounce vtable, calls the external
ObjectsMove native destructor at `0x80227B08`, and uses the established custom
allocator only for a positive native delete flag. Native C++ destructor
lowering emits its null guard, short delete-flag test, base call, and returned
`this`. This private destruction view does not claim a recovered full virtual
interface or emit a synthetic partial vtable.

## External objects and names

All four actual vtable references remain external original data:

| Native external symbol | Original symbol/address |
| --- | --- |
| `__vt__20ObjectsBase_802EB3F8` | `lbl_802EB3F8`, `0x802EB3F8` |
| `__vt__11ObjectsMove` | `lbl_802EB688`, `0x802EB688` |
| `__vt__12ObjectsBreak` | `lbl_802EBAB0`, `0x802EBAB0` |
| `__vt__13ObjectsBounce` | `lbl_802EBBE8`, `0x802EBBE8` |

The two other native external identities are
`__ct__20ObjectsRoot_80213EBCFv` at `0x80213EBC` and
`__dt__11ObjectsMoveFv` at `0x80227B08`. No vtable extent, table entry, string,
constant, BSS, or padding is credited. Exact alias mappings, including the
four recovered functions, are in
`scratch/game_objects_constructors/aliases.json` and each candidate manifest.

## Verification and handoff

The three manifests are
`config/GSQE78/candidates/game_objects_break_constructor.json`,
`game_objects_bounce_destructor.json`, and
`game_objects_move_constructors.json`. All use GC/1.3.2 with the established
`-O4,p -inline auto` game flags and C++ exceptions disabled.

Run the strict verifier separately with each unit name:

```sh
python3 scratch/game_objects_constructors/verify.py objects_break_constructor
python3 scratch/game_objects_constructors/verify.py objects_bounce_destructor
python3 scratch/game_objects_constructors/verify.py objects_move_constructors
```

All **704 retained text bytes match after 26 actual ELF relocations**: 4 for
ObjectsBreak, 6 for the destructor, and 16 for the two base constructors.
The verifier checks source/header/object hashes, physical retained-function
order, complete allocated-section/function coverage, alignment, and the
original DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Relocations are
applied to their real operands and targets; differences are not masked.

ObjectsBreak emits four unused weak handle destructors (360 bytes, 8
relocations); the base constructor source emits three (264 bytes, 6
relocations). Their complete extents are declared and excluded, with no
retained relocation targeting them. They are left to normal linker dead
stripping and receive no progress credit. The destructor source has no weak
tails. No allocated sections other than `.text` are emitted by these sources.

Strict output is saved as `scratch/game_objects_constructors/*.verification.txt`.
Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records all 704 code bytes and four functions as
exact across the three source units, with zero owned data. The source-section
extent guard and generated progress checks pass. Native-symbol reconciliation
preserves the original addresses and the existing factory callers' linked bytes;
the documented baseline accounting corrections remain preserved. The adjacent
record-pool routines are separately recovered and counted in their own units.
