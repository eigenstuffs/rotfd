# Early actor scene-effect selection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_actor_scene_selection_80089328.cpp` matches the complete 1,500-byte routine at 80089328..80089904, its 112-byte extab at 8000E210..8000E280 and its 12-byte index at 8001A340..8001A34C. GC/1.3.2 with `-O4,s -Cpp_exceptions on` reproduces all retained bytes after 58 actual relocations. The complete original DOL and central acceptance checks pass.

The routine clears two cached effect pointers and selects named effects from actor flags and the current scene mode. One branch retains an owner Handle, looks up a named child, retains the returned Handle and resolves that child's related object. The default branch also invokes the already reconstructed scene-effect activation routine. String bytes at 8029D680 and all other data remain external.

Ordinary native Handle_80020C04 and Handle_80020B90 copy construction explains the two scoped retained values and their returned temporary. The complete original EH actions are preserved, including six retained references to the existing native Handle_8001FF78, Handle_80020B90 and Handle_80020C04 destructor owners. Each accepted strong owner is freshly recompiled and strictly verified. Distinct typed registry views for the outer and related lookup preserve the native entry-array reload; collapsing those views removes an original load. The final signed-char argument of scene lookup 80058778 is independently established by the original callee sign extension, as documented in the adjacent scene-effect batch.

The dedicated header `include/Game/early_actor_scene_selection_views.h` has one production consumer. The compiler emits four discarded typed destructor backups totaling 460 text bytes and 208 EH/index bytes; they receive no credit. Three have retained-EH strong-owner authorization. The fourth, Handle_80020834, has no retained references and is inventoried only through the separate source-bound native adapter at `scratch/game_early_actor_scene_selection_native_gate`. Its existing original strong owner is freshly verified there. The final native link must select the accepted original strong definitions and discard this source's backup text and metadata.

Frozen manifests are listed in `scratch/game_engine_batch115/manifest-list.json`. Every emitted allocation, actual relocation and compiler-local EH symbol is accounted for. Full original extabindex 80015F60..8001F2C0, ctors 80299920..80299980 and dtors 80299980..802999A0 scans retain the sole original exception owner and find no startup/shutdown reference. No assembly, register forcing, volatile barrier, linker alias, identifier migration, extra data/BSS or padding ownership is introduced. The older scene-effect sources, headers, evidence and native gates remain unchanged.
