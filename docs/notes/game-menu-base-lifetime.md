# Menu base native destructor

Status: integrated and verified by the complete byte-identical DOL and native objdiff. The native `MenuBase_8021D7E4::~MenuBase_8021D7E4` at `0x8021D7E4..0x8021D968` reproduces all 388 original bytes after applying 17 real ELF relocations. This source unit credits one C++ function and no data, BSS, exception metadata or padding.

The private reconstruction and strict verifier are in `scratch/game_menu_base_lifetime`. Run:

```sh
python3 scratch/game_menu_base_lifetime/verify.py --production
```

`candidate.json`, `relocations.json`, `original_evidence.json` and `accepted_header_fingerprints.json` record the exact candidate, every retained/excluded relocation, original tables/layout, and untouched accepted declarations. The compiler is GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off -RTTI off -use_lmw_stmw on`, ordinary string reuse and the project's normal Gekko options. No object bytes are patched before relocation, and no comparison fields are masked.

## Recovered behavior and interface

The accepted runtime registry names `Menu` as a child of `ManipulatorDraw`, whose parent is `Manipulator`. The original destructor installs the Menu table at `0x802EB3A0`, conditionally calls virtual slot `0x48` when its inherited signed activity byte is nonzero and the renderer pointer at globals `+0x114` exists, destroys its list at `+0x38`, then destroys its owned handles at `+0x24` and `+0x20`. Both handles have two ordinary wrapper layers. The list's element stride is four bytes; its trivial element destructor leaves the original counter-only loop under this compiler.

The native inline base chain installs the intermediate table at `0x802BC9D0`, then the accepted Manipulator table at `0x802EB200`, and calls the accepted Activable destructor. The native deleting-destructor flag controls the final call to the game allocator. The observed class occupies `0x4C` bytes and retains the accepted identity, activity, accumulated-time and selector offsets.

The Menu declaration places its already observed slot `0x18` override before the destructor, so this destructor does not own the Menu vtable. The private destructor-only interface declares the virtual entries it needs through slot `0x48`; the original external table also contains slots `0x4C`, `0x50` and `0x54`, whose unused declarations are not invented here. Slot `0x44` takes the selector byte; slot `0x48` deactivates through the accepted lower helper. The original pure entries of ManipulatorDraw are retained by ordinary inheritance, rather than inserted as raw table values.

Address-qualified class names are working C++ identities. The runtime names support the inheritance; they do not establish the original source's exact class spelling or every unused method signature.

## Weak output and required original ownership

The compiler naturally emits 508 text bytes and a 68-byte weak intermediate vtable:

| Output | Emitted bytes | Verified credit |
| --- | ---: | ---: |
| Strong Menu destructor | 388 | 388 code |
| Weak ManipulatorDraw destructor | 120 | 0 |
| Weak ManipulatorDraw table | 68 | 0 |

The weak outputs contain 21 relocations: eight in the destructor and thirteen in the table. The retained destructor has two relocations to the weak table symbol, which must resolve to the existing original **strong** table through normal strong/weak symbol resolution. The verifier checks that the current linked ELF contains these original global definitions with their actual addresses, sizes and types. Integration preserves them under these canonical native names:

| Original identity | Native identity | Original address/extent |
| --- | --- | --- |
| `lbl_802BC9D0` | `__vt__24ManipulatorDraw_802BC9D0` | `0x802BC9D0`, current 72 bytes |
| `dtor_800A6004` | `__dt__24ManipulatorDraw_802BC9D0Fv` | `0x800A6004`, 140 bytes |
| `lbl_802EB3A0` | `__vt__17MenuBase_8021D7E4` | `0x802EB3A0`, 88 bytes |

The generated 120-byte weak intermediate destructor is not claimed to match the original exception-enabled 140-byte body. The generated RTTI-disabled table is also not claimed to match the original table's nonzero RTTI word. Both weak definitions must be discarded entirely. Their sizes, bindings, body hashes and complete relocation lists are recorded; the original table and its RTTI/destructor remain uncredited fallback. The existing 72-byte coarse intermediate extent is not refined in this task, including its possible four-byte trailing alignment.

The full normal link confirms that each original strong definition remains selected and both generated weak outputs are absent. `scratch/menu_completion_link_check.py` verifies final ELF identities, sizes, bindings, original bytes and fallback ownership; `scratch/menu_completion_link_proof.json` records the passing result.

## Compatibility scope

The accepted Menu2D/Menu3D units currently share `src/Game/menu_base_internal.h`, an explicit storage view with the same `0x4C` prefix and native destructor identity. This destructor source uses native inheritance to recover the base lifetime behavior; it does not alter those accepted declarations, their source, or their generated objects. The different class definitions remain a documented scope-limited ABI view, not a claim that a complete common C++ class interface has been recovered. A later shared native-interface refinement must reverify both derived units and every affected header user.

The production files are `src/Game/menu_base_destructor.cpp` and `src/Game/menu_base_native_internal.h`. The canonical candidate is `config/GSQE78/candidates/game-menu-base-destructor.json`. Integration changed the source split and required native identities; the original input, preserved baseline and existing source files remain unchanged.

The later [constructor integration](game-menu-constructors.md) extends the native
header with constructor/array initialization and handle assignment. The original
destructor remains exact; the former constructor-only gap is now matched source.
