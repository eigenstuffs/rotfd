# Menu3D lifecycle and render registration

`src/Game/menu3d_lifecycle.cpp` reproduces four consecutive original functions
at `0x80217FA0..0x8021827C`: **732 code bytes** and **35 actual relocations**.
The full byte-identical DOL and native objdiff verify this source unit. No initialized
data, BSS, table or constant-pool ownership is claimed.

| Original range | Bytes | Recovered role |
| --- | ---: | --- |
| `0x80217FA0..0x802180D0` | 304 | Native Menu3D deleting destructor |
| `0x802180D0..0x80218174` | 164 | Deactivate and remove identity from the selected render slot |
| `0x80218174..0x80218228` | 180 | Select render slot, activate, initialize and register identity |
| `0x80218228..0x8021827C` | 84 | Update a sine-based pulse from accumulated time |

The runtime identity is supported by original strings and an accepted factory.
`0x8037AA28` contains `Menu3D`; the registry makes it a child of `Menu`
(`0x8037AA20`). Factory `fn_802097BC` reports `Menu3D_Z.h:80`, allocates `0xC0`
bytes, and calls the constructor at `0x802193C0`. The `Menu` registration itself
uses the same factory. The neighboring `Menu2D` registration has a different
factory and is covered independently. The evidence is recorded in
`scratch/game_class_80217FA0/identity.json`.

The native working class is `Menu3D_802193C0`. Its destructor corresponds to
`__dt__15Menu3D_802193C0Fv`. The original external base destructor at
`0x8021D7E4` uses the shared working identity
`__dt__17MenuBase_8021D7E4Fv`, coordinated with the Menu2D reconstruction.
These are address-qualified reconstruction names; the exact original C++
declarations and complete inheritance chain remain unproven.

The observed base storage is `0x4C` bytes, with identity at `+4`, vptr at `+8`,
accumulated float at `+0x1C`, and an unsigned render-slot selector at `+0x34`.
Menu3D adds two native handle layers at `+0x4C`, a list at `+0x68`, another
two-layer handle at `+0x74`, and a pulse float at `+0x78`. The list has signed
count and capacity followed by its pointer; each element occupies `0xBC` bytes.
Unknown fields remain explicit storage, and compile-time size checks preserve
the factory's `0xC0` allocation.

The native destructor restores original table `0x802EB298`, destroys the handle
at `+0x74`, iterates the list's explicit trivial element destructors, releases
`capacity * 0xBC` bytes through `fn_8028FD50`, destroys the handle at `+0x4C`,
and calls the external base destructor. A positive signed 16-bit deleting flag
then frees the complete object through `fn_801EF610`. Ordinary C++ destruction
produces the original null checks, two wrapper layers and redundant list
pointer clears. The trivial element destructor loop produces the original
empty loop after inlining; it is not replaced with assembly or omitted.

The two registration methods use the render-slot array at global offset
`0x114`, selecting a `0x4C`-byte record with the object's byte at `+0x34`.
The original `fn_801E2E70` reads that record's four viewport rectangle words.
`fn_801E1F3C` searches its eight handle entries at `+0x28..+0x44` and clears the
first matching resolved identity. `fn_801E2074`, called here with a zero signed
byte flag, inserts into an empty handle slot. The caller constructs a scoped
retained identity handle, passes it to the helper, and destroys it afterward.
A const-reference identity getter and two native zero-initializing layers
preserve the original pointer lifetime, two zero stores and reference-count
call. Activation stores the incoming selector before activating and calling
`fn_8021894C`; no extra selector bounds checks are introduced.

The final function occupies virtual slot `+0x38`. Its float argument is retained
in the prototype because the accepted upper `slot2C(float)` dispatches it, but
the body ignores that argument and uses accumulated time at `+0x1C`. It stores
`0.7 * (1 + sin(2 * time)) * 0.5` at `+0x78`, using the four original external
floats at `0x8037AE90..0x8037AEA0`. A named intermediate preserves the final
multiply's original operand order. The 88-byte table at
`0x802EB298..0x802EB2F0`, those constants and both allocator globals remain
external original storage.

Run `python3 scratch/game_class_80217FA0/verify.py`. The compiler is
`GC/1.3.2`, using Gekko hardware floating point,
`-O4,p -inline auto -Cpp_exceptions off -RTTI off -use_lmw_stmw on`.
The verifier checks the original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, applies every retained ELF
relocation and compares every retained instruction byte. The original assembly
snapshot is `scratch/game_class_80217FA0/original.s`.

The compiler emits a single 996-byte `.text` section: the four retained
functions plus three unused weak handle destructors of 92, 88 and 84 bytes.
Those **264 excluded bytes are interleaved** at object offsets
`0x1D4..0x2DC`, between the two registration methods. The verifier proves full
contiguous function coverage, all bindings, exact weak extents and all six
excluded references, which target only the native handle destructor and global
delete. No retained reference targets those weak functions. Their original
identities are not claimed; they receive no source credit and require ordinary
linker dead stripping. There are no other allocated sections or padding.

The candidate `config/GSQE78/candidates/game-menu3d-lifecycle.json` records
each retained function's original address and actual object offset, all source
and header hashes, the 35 retained versus six excluded relocations, and zero
data ownership. No opcode masking, object patches, fixed-register constraints,
new EOF/bounds guards or assembly function bodies are used.

Both menu units use the same `menu_base_internal.h` definition, including its
native handle identity and accumulated-time field. The Menu3D temporary is
named `Menu3DHandle`, so the two units do not define different helper classes
under the same name. Common renderer declarations accept the native handle
base, and activation declarations use the accepted Activable pointer with an
explicit zero-offset prefix cast. Both complete relocation proofs remain exact
after these declaration changes. Historical views are preserved under
`scratch/menu_interface_before/` and `scratch/menu_call_declarations_before/`.
Current integration evidence is `scratch/menu_lifecycle_full_build.log` and
`scratch/menu_checkpoint.json`.
