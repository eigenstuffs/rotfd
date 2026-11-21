# In-game objects manipulator lifetime and borrowed handle

Current status: integrated through [the native InGame interface](game-ingame-manipulator-interface.md).
These three lifetime/handle objects retain 388 code bytes and four functions,
now with 34 actual relocations and 76 owned table bytes. The constructor emits
464 unreferenced weak bytes, all excluded from source credit. The native class
destructor emits the table; its four-byte original tail remains uncredited.

Verify the current source with
`python3 scratch/game_ingame_manipulator_interface/verify.py --production`,
then `python3 scratch/game_ingame_manipulator_interface/verify_link.py` after
the full build. Both pass the unchanged original DOL.

## Historical partial-interface snapshot

The remainder describes the earlier source and isolated proof, preserved under
`scratch/ingame_native_interface_before/`. Its external-table and explicit-vptr
statements and verification command do not describe the current source.


Three source fragments recover **388 code bytes across four functions**, with
17 actual relocations and zero isolated byte differences. The original DOL hash, direct
byte comparison and complete native objdiff integration all pass.

| Source | Range | Code bytes | Functions | Relocations |
| --- | --- | ---: | ---: | ---: |
| `ingame_manipulator_handle.cpp` | `802125F8..8021266C` | 116 | 2 | 4 |
| `ingame_manipulator_destructor.cpp` | `802127F4..802128A0` | 172 | 1 | 9 |
| `ingame_manipulator_constructor.cpp` | `802128A0..80212904` | 100 | 1 | 4 |

The accepted factory at `80209380` allocates `0x24` bytes and calls the native
constructor with `InGameObjectsManipulator_Z.h:35` as its source string. The
accepted type registry identifies `InGameObjectsManipulator` as a child of
`Manipulator`. This distinguishes it from the separate `ManipulatorDraw`
registration. The native working name is address-qualified as
`InGameObjectsManipulator_802128A0`; the exact original C++ spelling remains
unestablished.

The constructor calls the accepted Manipulator base constructor, installs the
external table at `802EB180`, and constructs the four-layer handle at `+20`.
The four zero stores follow naturally from those inherited constructors.
The source type size agrees with the factory's `0x24` allocation. The native
destructor uses an explicit vptr view, destroys the handle through all four
layers, restores the external Manipulator table and destroys the Activable
base. A positive native deletion flag releases the object through the existing
allocator. These separate lifetime views preserve the same observed layout;
complete original class interfaces and translation-unit boundaries are not
claimed.

`fn_802125F8` assigns the incoming borrowed handle with release/copy/retain.
`fn_80212664` returns the address of the existing handle, with no extra
reference acquisition or temporary destruction. Its pointer/reference spelling
and source-level constness cannot be recovered from the eight-byte body alone;
the source models the observed borrowed address.

All virtual tables remain external, and these fragments own no data or padding.
The constructor emits four unreferenced weak handle destructors totaling
360 bytes and eight relocations; normal dead stripping excludes them. The
other two objects emit only their retained functions.

The historical verifier was `python3 scratch/game_ingame_manipulator/verify.py UNIT`, where UNIT
is `ingame_manipulator_constructor`, `ingame_manipulator_destructor`, or
`ingame_manipulator_handle`. Each check compiled the then-current source, accounts for
all functions and allocated sections, checks global/weak bindings and
alignment, applies actual relocations, and compares every retained byte against
the protected original DOL. The original byte/hash check and complete native objdiff report pass in
`scratch/manipulator_checkpoint_full_build.log`. The adjacent update and
zero-word virtual query are documented separately; the original InGame table
remains external.
