# SDK and shared game typed storage continuation

This continuation reconstructs ordinary typed storage only. It emits no
assembly, executable stubs, bytecode or firmware images. The exact object
contracts and reproducible compiler probes are under
`scratch/sdk_continuation_20261012_b/`; the integrator owns final source
registration, section partitioning, native DOL verification and progress.

All candidates use GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse
-common off -O4,p -inline auto -sdata 8 -sdata2 8 -pool off -Cpp_exceptions off`.
CARD and AX sources add their existing local header include directories.
Every object retains its original GLOBAL binding. No LOCAL symbol is promoted.

| Source | Exact emitted section | Bytes | Typed ownership |
| --- | --- | ---: | --- |
| `src/MSL/float_limits.c` | `.sdata 80375E48..80375E78` | 48 | Existing `int[1]` and `int[2]` API representations of IEEE limits |
| `src/MSL/errno.c` | `.sbss 80377D10..80377D14` | 4 | Process error integer |
| `src/dolphin/card/CARDVendor.c` | `.sdata 80375D98..80375D9A` | 2 | Existing unsigned short vendor ID, initially `0xFFFF` |
| `src/dolphin/ax/DSPCode_length.c` | `.sdata 80375D78..80375D7A` | 2 | Existing unsigned short DSP program byte length, 7968 |
| `src/Python/frozen_registry.c` | `.data 802DE760..802DE7AC`; `.sdata 803767C0..803767C4` | 80 | Two module names, four `_frozen` records and mutable registry pointer |
| `src/dolphin/mtx/mtx_native_constants.c` | `.sdata2 80379880..80379888` | 8 | Native matrix constants `1.0f` and `0.0f` |
| `src/Game/callback_dispatch_storage.c` | `.sbss 80378088..80378098` | 16 | Node pointer, two dispatch words and signed index |
| `src/Game/worker_request_storage.c` | `.sbss 80378098..803780A0` | 8 | Two worker request words |
| `src/Game/frame_timing_storage.c` | `.sbss 803780A0..803780A8` | 8 | Two frame timing floats |
| `src/Game/python_event_shared_storage.c` | `.sbss 803776C0..803776E8` | 40 | Six short controls and seven event argument pointers |
| `src/Game/scene_callback_shared_storage.c` | `.sbss 80377828..80377868` | 64 | Sixteen nullable callback group pointers |
| `src/Game/callback_group_storage_80377588.c` | `.sbss 80377588..803775B4` | 44 | Eleven nullable callback group pointers |
| `src/Game/callback_group_storage_803775E8.c` | `.sbss 803775E8..80377614` | 44 | Eleven nullable callback group pointers |
| `src/Game/callback_group_storage_80377628.c` | `.sbss 80377628..80377640` | 24 | Six nullable callback group pointers |
| `src/Game/callback_group_storage_80377650.c` | `.sbss 80377650..80377660` | 16 | Four nullable callback group pointers |
| `src/Game/python_factory_type_storage.c` | `.bss 80318988..80318A68` | 224 | Fifty-six registered native type pointers |
| `src/Game/audio_lookup_storage.c` | `.bss 8035E758..8035E958` | 512 | 128 floats filled by matched audio startup |
| `src/Game/platform_movie_shared_storage.c` | `.sbss 803780F0..80378130` | 64 | Decode/display buffer pointers, dimensions, frame index and two bounded arrays |
| `src/Game/scene_saved_transform_storage.c` | `.bss 80306E08..80306E24` | 28 | Saved three-float position and four-float rotation |
| `src/Game/ground_collision_constants.c` | `.sdata2 8037B940..8037B964` | 36 | Nine typed ground query thresholds and direction components |
| `src/Game/callback_text_shared_storage.c` | `.sbss 80377660..80377688` | 40 | Nine nullable callback pointers and a signed text selector |
| `src/Game/service_slot_shared_storage.c` | `.sbss 803777A8..803777D0` | 40 | Saved signed-byte service flag, natural alignment and nine signed registration keys |

The frozen registry emits seven actual address relocations, six record pointers
and the public registry pointer. Its signed size `-90` marks the package.
Original serialized code at `802DE6F8..802DE752`, the first module name at
`802DE754..802DE75E`, their alignment and all neighboring Python data remain
original dependencies. The one internal alignment byte at `802DE76B` is a
natural compiler allocation. The native matrix routines remain original; their
complete constant-reference closure is `800F6D0C`, `800F6D10`, and `800F6E34`.

The game pointer definitions follow the recovered API declarations and complete
native consumer inventories in their contracts. The nullable group pointers
are passed to the already recovered destructor by
`global_nullable_teardown_800bbfd8.cpp`; they are not inferred from zero bytes.
All small-state BSS objects emit no relocations, code, exception records or
undefined dependencies. The service slot group naturally emits three original
alignment bytes between its one-byte flag and first integer. All other small
state groups emit no internal padding.

The factory registry's exact bound is independently established by native
`fn_800E023C`. It reads the list at `802C1E78 + 2DE4 = 802C4C5C`, which contains
56 non-null descriptor pointers followed by a null terminator. The store at
`800E033C` uses the byte index incremented by four at `800E0340`. Direct native
consumers cover every four-byte element offset `0..DC`, with no larger element
offset. The existing factory header declares this storage as `FactoryType*[]`.
The initializer's 656 code bytes and its 228-byte input list remain original.

Original tails remain excluded: `80375D7A..80375D80`,
`80375D9A..80375DA0`, `80377D14..80377D18`, `802DE7AC..802DE7B0`,
`803767C4..803767C8`, `803775B4..803775B8`, and
`80318A68..80318A80`, `80306E24..80306E28`, and
`8037B964..8037B968`. The inferred scalar/array symbol sizes are corrected to
their emitted sizes; no original bytes are discarded. In particular,
`80377614..80377618` is a separate real global and remains original storage,
not padding. Any new split must explicitly preserve its four-byte alignment.
The original prefixes `80375D74..80375D78` and `80375D94..80375D98` must also
remain present when splitting the neighboring unsigned shorts.

The individual freezes check every positive allocated section, full symbol
extents and bindings, actual relocations, semantic initialized values, BSS
header containment and consumer closure. Parent integration has confirmed the
original DOL hash and native objdiff for the four SDK scalar sources, frozen
registry, matrix constants and nine callback/event/frame/worker state sources.
The factory registry and all later storage/constant groups listed here have
also passed the full native build, allocation proof and source-extent audit. These
findings do not claim completion of the remaining game executable.

The audio table bound is established by the existing matched startup and native
128-iteration float store loop; it emits no new code. The saved transform types
follow the existing matched position/rotation assignments, preserving all three
and four scalar fields. The ground callback constants retain nine original
GLOBAL identities and exact float values. Every native direct consumer lies in
the already matched 1008-byte callback. The final scalar
`lbl_8037B960` is four bytes; its four-byte original terminal alignment remains
separate. No local literal pool is exported or reconstructed as raw words.

Movie state types follow the existing matched internal headers, including two
dirty flags and two framebuffer pointers. Service keys follow the existing
matched registration function returning signed integers. The saved service flag
is stored at `800BE3F4`, loaded at `800BE918` and sign-tested at `800BE91C`; its
original native object binding is GLOBAL. The natural three-byte compiler gap
at `803777A9..803777AC` is explicitly included in the contract.
