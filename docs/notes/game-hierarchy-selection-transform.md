# Hierarchy scalar and vector selection commands

Two adjacent methods at `0x802047B8..0x80204CC0` are recovered as independent
source fragments:

| Source | Method | Retained code |
| --- | --- | ---: |
| `src/Game/hierarchy_selection_parameters.cpp` | `fn_802047B8` | 752 bytes |
| `src/Game/hierarchy_selection_vector.cpp` | `fn_80204AA8` | 536 bytes |

Both pass strict isolated comparison, complete DOL comparison, and native objdiff.
The full original translation unit boundary and class names remain
unknown.

The scalar helper serves `MakeCameraTexture`, `MakeCameraPatch` and
`MakeCameraFrame`. It requires console `argc >= 2` and nonzero `numeric[1]` at
`0x8A5`. It converts `values[1]` at `0x8B8` to an index and checks the observed
signed game count. Three native handles, with five, two, and three
zeroing layers, receive the group's selected objects. A valid target receives
optional virtual-slot-`0x80` commands using `values[2]` at `0x8BC` when
`argc >= 3 && numeric[2]`, and `values[3]` at `0x8C0` when
`argc >= 4 && numeric[3]`. Counts include the command token; these signed
bytes record numeric parsing success, including boolean aliases, not truth.
If the group's flag for the selected index is nonzero, the method formats
`SwitchCameraUser %d` and dispatches that string through `fn_801FAB38`. It then
sends the final supplied command with the shared zero float and cleans up the
handles.

The vector command is registered as `PlayerGotoCoord`. It accepts `argc == 4`
or `argc == 5`: command plus x/y/z, with an optional viewport argument. Four
tokens select index zero; five require `numeric[4]` and convert `values[4]` at
`0x8C4` to an index. The coordinate guard rejects only when all three flags
`numeric[1]`, `numeric[2]` and `numeric[3]` are false; it does not require all
three to be valid. It then checks the observed game count. After acquiring
the three handles, it builds a value from `values[1..3]` at
`0x8B8`/`0x8BC`/`0x8C0`. A valid first handle receives that value through
virtual slot `0x148`. These original guards and the cleanup order are
preserved; see [console argument layout](console-argument-layout.md).

## Compiler and source details

The private header `src/Game/hierarchy_selection_transform_internal.h` copies
the already verified handle layers and extends only its private console
argument and virtual-call views. The later console-field naming refinement preserves
the layouts and complete compiled objects. Six ordinary
inherited handle classes reproduce the repeated zero stores and automatic
cleanup without manual stack construction or explicit destructor flags.

Reading the vector components into ordinary locals in z/y/x order, then
constructing x/y/z, reproduces the original floating-register assignments. A
constructor call with direct field arguments has the same size and behavior,
but swaps the y/z load and store registers. The same read-before-write pattern
is present in the recovered TeleportVolume vector assignment.

GC/1.3.2 uses `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`, standard
Gekko hardware-FP flags, and `-i src/Game`. In a combined source the compiler
emits the vector method before the scalar method, with weak helper bodies
between them. Independent source fragments retain original function order with
normal linker dead stripping. The exploratory combined object is preserved in
scratch and explicitly marked unsuitable for integration.

## Data and verification

Neither source owns data, BSS, exception records, or padding. The scalar command
keeps the original format string at `0x802AD984` external. Its only zero-float
reference is at instruction `0x80204A5C`, targeting shared constant `0x8037A928`;
that constant also remains external. Neither method references `0x8037A92C`.

Reproduce both isolated candidates with:

```sh
python3 scratch/game_hierarchy_selection_transform/verify.py
```

The verifier checks the untouched original DOL SHA-1, production source and
private header hashes, all emitted symbol extents and allocated sections, and
applies each actual retained ELF relocation at its original address. All 752
scalar-command bytes and 26 relocations match; all 536 vector-command bytes and
19 relocations match. Every relocated byte is compared directly.

Each source additionally emits six unreferenced weak handle destructors,
564 bytes with 12 relocations. Their exact extents and weak binding are checked;
retained references to those bodies are rejected. They are excluded by normal
dead stripping and receive no source progress credit. Each fragment retains
exactly one strong function, so no linker reordering is required.

The original DOL SHA-1 remains
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Stable candidate records are
`config/GSQE78/candidates/game_hierarchy_selection_parameters.json` and
`game_hierarchy_selection_vector.json`; the transcript is
`scratch/game_hierarchy_selection_transform/verification.txt`.

Central integration passes the original DOL hash and direct whole-file byte
comparison. Native objdiff records all 1,288 code bytes and 2 functions as
matching, with zero owned data. The source-section extent guard and generated
progress checks pass. Original baseline source remains exact after the
documented native-accessor and padding accounting corrections.
