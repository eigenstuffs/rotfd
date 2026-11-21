# Native Activable interface and virtual table

This integrated change completes the observed lower virtual interface using ordinary C++. The address-qualified `ObjectsOwner_80213D44` working name is retained for the runtime Activable class. No original C++ suffix or source-file name is asserted.

The native interface revisions preserve the accepted constructor (276 bytes), destructor (272), append method (476), upper callbacks (168), and activation pair (128): **1,320 existing code bytes remain exact**. Five newly recovered hooks add **48 code bytes**, and the genuine lower virtual table plus wrapper exception metadata add **64 data bytes**. The complete DOL SHA-1, direct byte comparison and native objdiff checks pass.

| Source | Original range | Code | Owned data | Actual retained relocations |
| --- | --- | ---: | ---: | ---: |
| `objects_owner_constructor.cpp` | `80213D44..80213E58` | 276 | 0 | 15 |
| `objects_owner_destructor.cpp` | `80213A58..80213B68` | 272 | 44 | 28 |
| `objects_owner_append.cpp` | `80213B68..80213D44` | 476 | 0 | 19 |
| `objects_owner_hooks.cpp` | `8002810C..80028134` | 40 | 20 | 3 |
| `root_empty_hooks.cpp` | `80023950..80023958` | 8 | 0 | 0 |
| `objects_root_callbacks.cpp` | `80213E58..80213F00` | 168 | 68: existing constant 4, later table 64 | 19 |
| `objects_owner_activate.cpp` | `802139D8..80213A58` | 128 | 0 | 0 |

The shared `objects_owner_internal.h` contains the observed native class interface, four-byte handle types, exact lower layout and inline handle/list operations. `ObjectsOwner_80213D44` has the Root prefix at offsets zero/eight, previous and next handles at `0x0C/0x10`, a word at `0x14`, and signed state byte at `0x18`; its size remains `0x1C`. The upper callback header `manipulator_callbacks_internal.h` includes this interface and adds the float at `0x1C`, preserving the `0x20` upper size. The activation-only view retains `objects_root_callbacks_internal.h`. Inherited `Root_80207414::slot1C()` retains its accepted signed-char return type.

The destructor is now genuinely virtual. The compiler installs its table naturally, replacing the previous explicit virtual-pointer field assignment. The original handle temporary lifetimes, member cleanup, base destruction and class-specific deletion produce exactly the same 272 instruction bytes after relocation. The append body becomes the native override `slot18__21ObjectsOwner_80213D44Fv`; its 476 bytes and 19 relocation targets remain unchanged. The constructor and its two empty-handle assignments also remain exact.

## Native table and remaining hooks

The compiler emits `__vt__21ObjectsOwner_80213D44` as one **44-byte global object** with natural `.data` alignment eight. Its original extent is `0x802EB1D0..0x802EB1FC`. `-RTTI off`, already established for the accepted Root table, produces the observed two leading zero words. The nine actual function-pointer relocations then select:

| Slot | Native identity | Original target |
| --- | --- | --- |
| `08` | `__dt__21ObjectsOwner_80213D44Fv` | `80213A58` |
| `0C` | `slot0C__13Root_80207414FUl` | `802072A0` |
| `10` | `slot10__13Root_80207414Fv` | `80023950` |
| `14` | `slot14__13Root_80207414Fv` | `80023954` |
| `18` | `slot18__21ObjectsOwner_80213D44Fv` | `80213B68` |
| `1C` | `slot1C__13Root_80207414Fv` | `80207354` |
| `20` | `slot20__21ObjectsOwner_80213D44Fv` | `8002810C` |
| `24` | `slot24__21ObjectsOwner_80213D44Fv` | `80028110` |
| `28` | `slot28__21ObjectsOwner_80213D44Fv` | `80028114` |

The four original zero bytes at `0x802EB1FC..0x802EB200` lie beyond the actual emitted table. They remain uncredited original fallback. No synthetic null slot `2C`, manually assembled function-pointer array, forced alignment, RTTI payload, or extra source padding is introduced. The upper table beginning at `0x802EB200` is now source-owned by the later callback unit. Its native inline destructor leaves table emission with that unit, while ordinary strong/weak resolution retains the existing early destructor. This resolves the earlier placement cycle; see the [Manipulator lifetime note](game-manipulator-native-lifetime.md).

Lower slots `20` and `24` are original, distinct four-byte empty hooks. The activation pair calls them only after changing the signed state byte. Slot `28` calls accepted `fn_80213A18(this)` in its original 16-byte frame. Its source compiles with C++ exceptions enabled to emit the genuine eight-byte `extab` at `0x800065C4..0x800065CC` and 12-byte `extabindex` at `0x80016638..0x80016644`. The metadata has its real function-size field and two pointer relocations; the remaining relocation is the code's call to the activation helper. These 20 bytes are checked as owned initialized data.

Inherited Root slots `10` and `14` already had native names but still belonged to original fallback in the 605-source checkpoint. Their two empty out-of-line definitions now recover the original eight bytes without metadata. All five newly recovered hook functions retain strong global binding. Empty bodies are evidence-backed original functions, not added placeholders or padding credit.

## Verification and integration

Current production verification is split between the unchanged lower units and
the updated upper table owner:

```sh
python3 scratch/game_activable_interface/verify.py --production --skip-upper
python3 scratch/game_manipulator_vtable_emission/verify_replacement.py --production
```

The first checks 1,200 retained code bytes, 64 initialized bytes and 65 actual
relocations in six lower/activation units. The second checks the existing 168
callback code bytes, 64 newly owned table bytes, the existing four-byte zero
constant and 19 retained relocations. Together these seven units retain
**1,368 code bytes, 132 initialized bytes and 84 relocations**, with zero
byte differences. All allocated output, original alignments and real relocation
targets are checked. The earlier interface-only proof's 68 initialized bytes
and 71 relocations are historical; the increase is solely the upper table.

The constructor emits one unreferenced 84-byte weak handle destructor; the destructor and append each emit two such helpers. The verifier enumerates all five weak bodies (420 bytes total), proves no retained relocation targets them, and checks their ten actual relocations—one native handle-destructor call and one ordinary delete call per body. They remain excluded through ordinary dead stripping. The lower hooks and activation fragment emit no additional weak bodies. The updated upper callback object emits a separate 124-byte weak native destructor and 52 bytes of exception/index metadata with nine relocations. Those bytes independently match the existing early strong destructor and its metadata and are discarded through ordinary linker resolution; they receive no duplicate credit. No unaccounted allocated output is ignored.

The upper compiler-local zero symbol changed from `@9` to `@14` during lower interface completion and is now `@19` after native upper table emission. Its four bytes at `0x8037AC50` and both SDA2 instructions remain unchanged. The integrated callback manifest records `@19` and keeps `0x8037AC54..0x8037AC58` uncredited. The activation object remains byte-identical even as an entire ELF file. Private historical probes explicitly select their header copies; the current verification commands above select production sources and headers.

The integrated source includes `objects_owner_internal.h`,
`objects_owner_hooks.cpp`, and `root_empty_hooks.cpp`, with corresponding
candidates `game-objects-owner-hooks.json` and `game-root-empty-hooks.json`.
The coordinated constructor/destructor/append/header patch and proposed
manifest snapshots remain in `scratch/game_activable_interface` as historical
proof inputs; their former contents are preserved in `before_*` files and
`accepted_input_hashes.json`. The integrator applied the changes and validated
the full executable. The original DOL and preserved baseline remain unchanged.

At the native-interface checkpoint, overall progress is 905,496 code bytes,
2,937 functions, 300,656 data bytes and 612 completed source units. The exact
increment attributable to this interface is 48 code bytes, five functions and
64 data bytes. Every previously accepted source unit remained exact. The later
upper table integration adds 64 more data bytes without changing those code
counts or source-unit identities. The final combined checkpoint is 906,016 code
bytes, 2,941 functions, 300,797 data bytes and 616 source units.

## Companion ABI and ownership review

A read-only review of the lower/upper interface, InGame lifetime/handle/update
views and owner-list views found no material calling-convention, field-offset,
virtual-slot or ownership contradiction. The lower prefix is `0x1C`, the upper
Manipulator prefix is `0x20`, InGame adds its four-layer handle at `0x20` and
has the factory-confirmed size `0x24`, and the separate list has head/tail at
zero/four plus a signed filter byte at eight and total size `0xC`.

The list update view exposes virtual slot `0x2C` on borrowed update-capable
objects. It emits no table or instances and does not prove an additional lower
Activable slot. InGame's original table supplies its concrete float callback
at `0x38`; its lifetime fragments leave that table external. The list's next
handle is borrowed after dispatch, while assignments and lifetime temporaries
retain/release through the accepted manager. Those distinct ownership
behaviors agree with their original instructions.

The shared append-only `OwnerList` is a two-handle prefix view, not the complete
12-byte `OwnerList_80213824`; no allocation or `sizeof` operation relies on the
smaller view. The lower word `field14` is unsigned storage in construction and
signed mode storage in the setter/traversal views; their recovered constant
stores and equality tests have the same 32-bit ABI and behavior. These partial
views should not be treated as complete original class definitions.

The review identified a declaration refinement: the accepted
`handle_access.cpp` returns an object pointer from `fn_801F7EB8`, while the
initial shared interface declared an unsigned word for its null-only use.
Both use the same return register, so this did not invalidate the byte proof.
The shared declaration now returns `ObjectsOwner_80213D44*`. All seven
production objects passed strict verification after this correction, including
their table, metadata and literal bytes. The current split verification commands
above also cover the later upper table change. The ABI refinement is resolved;
no accepted source was edited during the original read-only audit.
