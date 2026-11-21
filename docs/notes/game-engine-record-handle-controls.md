# Record Handle controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C entry points use four-byte retained reference handles. They preserve their existing names and do not change accepted callers or shared declarations:

| Function | Original text | Original extab | Original index | Actual retained relocations |
| --- | --- | --- | --- | ---: |
| `fn_800E6F84` | `800E6F84..800E7024` (160) | `80014DC4..80014DDC` (24) | `8001EA2C..8001EA38` (12) | 15 |
| `fn_800E731C` | `800E731C..800E73B8` (156) | `80014E08..80014E34` (44) | `8001EA44..8001EA50` (12) | 13 |
| `fn_800E73B8` | `800E73B8..800E745C` (164) | `80014E34..80014E60` (44) | `8001EA50..8001EA5C` (12) | 13 |

The first obtains a scoped handle from global member `14C` using the original seven-byte small-data key at `80379804`, assigns it to owner member `24`, and sets floats `28/2C/30` from the original constants. Assignment releases the previous owner reference, copies the word, then retains the source reference. The returned temporary has the original nontrivial hidden return-pointer ABI and cleanup lifetime.

The other two conditionally add or remove owner handle `04` from the collection at global member `114`. Addition uses zero as its final parameter; removal indexes collections by `index20 * 4C`. They test the signed byte at `18`, and invoke the original activation/deactivation functions after the retained temporary is destroyed. Binding a named reference to the member before constructing the temporary preserves the original member-pointer lifetime and register allocation.

`RecordHandleZero` is a private provisional empty handle layer. Its constructor clears the native raw handle after construction. `Handle_80021BCC` adds the second clear, and `Handle_8002F6B0` copies and retains the original reference. Their ordinary inline destructors invoke the existing native raw destructor with flag zero. The private `View` establishes only the observed offsets; its total extent and the meaning of unrelated storage are not recovered here.

The compiler is GC 1.3.2 with the established container flags, including `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. Each primary function matches every retained instruction and all original exception bytes after actual ELF relocation. Source and recursive quoted-header hashes are frozen; the production sources have no quoted headers.

## Defined weak destructor resolution

The compiler also emits weak backup destructors and their exception records. Retained exception pointers target those exact native symbols in the input object. The adopted bounded override gate independently recompiles each existing strong owner, checks all original bytes and actual relocations, and requires the exact production object SHA before resolving the pointers to their original strong addresses:

- `__dt__15Handle_800723F4Fv`: `800723F4`, 116 bytes; canonical `game_typed_handle_800723F4.json`.
- `__dt__15Handle_80021BCCFv`: `80021BCC`, 116 bytes; canonical `game_typed_handle_80021BCC.json`.
- `__dt__15Handle_8002F6B0Fv`: `8002F6B0`, 120 bytes; canonical `game_typed_handle_8002F6B0.json`.

The first unit emits 116 backup text bytes and 52 backup metadata bytes, with seven backup relocations. Each other unit emits 348 backup text bytes and 156 backup metadata bytes, with 21 backup relocations. Every backup function, exception object, and index is inventoried with binding, offset, extent, and raw SHA256. The unreferenced private `RecordHandleZero` backup is included. These 812 text and 364 metadata bytes receive no matching credit. Central acceptance must prove all backup input sections are discarded and all original strong destructor definitions remain at their original addresses.

## Original ownership

The full original exception index table (`80015F60..8001F2C0`, stride 12), constructor table (`80299920..80299980`, stride 4), destructor table (`80299980..802999A0`, stride 4), and every initialized data section were scanned. Each function has exactly its listed exception record; none has a startup-table entry. `fn_800E6F84` also remains referenced by the original table `lbl_802C8E88` at `802C8EA0` (table offset `18`). The original 72-byte table remains in assembly; no table ownership transfers. The other two have no initialized-data references beyond their own exception index. Existing source consumers and their hashes are recorded without identifier changes.

The handoff is `scratch/game_engine_record_handle_controls_continuation/handoff.json`. Its `final_integration.json` owns 480 code bytes and 148 original exception/index bytes, with 41 retained actual relocations. `verify.py` recompiles the three production sources and all strong owners, verifies the complete allocation inventory and actual strong resolution, and checks the frozen source/metadata hashes. Full-game native link, original DOL hash, regression checks, and backup-discard map audit remain the integrator's acceptance gates.

The root adoption gives the private zero-initializing helper in `800E73B8`
the distinct source-only type name `RecordZero_E73B8`. The original linker map
coalesced two copies without an exact second-input discard row; no such
incomplete evidence was accepted. This pending-source identifier change leaves
all allocated bytes and every retained actual relocation identical, preserves
the agent's complete original source/object/manifest, and adds no credit. The
unchanged adopted native-link checker now verifies each unused helper by its
exact input name. Evidence: `scratch/continuation_20261010/record-backup-name-revision/`.
