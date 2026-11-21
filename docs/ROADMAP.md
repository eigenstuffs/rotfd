# Work roadmap

The end goal is to rebuild the `GSQE78` executable from matching C/C++.
[`PROGRESS.md`](../PROGRESS.md) is the measured status; this document tracks the
work needed to reach it. A passing rebuild is the integration foundation, not
completion of the decompilation.

An earlier standard-build checkpoint is the
[native source continuation](notes/continuation-2026-10-12-native-source-checkpoint.md):
72,196 linked code bytes and 372,399 matched data bytes have been gained since its
saved start report. Its unchanged DOL hash, baseline regression check, native
allocation proofs, complete original section coverage, source extents and all
66 tests pass. The current generated report records 74.79% code and 94.88%
data matched from linked source; 806 functions remain outside linked source.
The [Python event names, glyph tokens and native cleanup adjustor](notes/game-python-glyph-cleanup-continuation-20261020.md)
add 284 exact data bytes and eight code bytes with all existing ownership preserved.
The [credits backdrop and menu rendering pair](notes/game-credits-menu-render-800b16e0.md)
adds 5,612 exact code bytes and 788 exception bytes, preserving all 616 prior data bytes.
The [menu record parameter tokens](notes/game-menu-parameter-tokens-80378ec0.md)
add 180 exact data bytes while preserving 16 bytes of original residual ownership.
The [menu backdrop and text renderer](notes/game-menu3d-render-80219510.md)
adds 1,464 exact code bytes and preserves all 32 previously matched scalar bytes.
The [collision-pair event dispatcher](notes/game-collision-pair-dispatch-80224ca8.md)
adds 2,476 exact code bytes and 12 scalar bytes with native Handle lifetimes.
The [nine trailing strings in eight pools](notes/game-final-readable-string-extensions-20261020.md)
add 151 exact data bytes while preserving 23 bytes of original residual ownership.
The [menu RTTI names and named-mode pool](notes/game-menu-named-mode-pools-20261020.md)
add 209 exact data bytes while preserving ten bytes of original residual ownership.
The [group-count initializer and letter-tile names](notes/game-group-count-template-8029ed14.md)
add 217 exact data bytes, preserving the original three-byte alignment tail.
The [voice-over diagnostic tail](notes/game-voiceover-diagnostic-tail-8029f0dc.md)
adds 44 exact data bytes while preserving the adjacent buffer initializers.
The [message-box drawing and layout pair](notes/game-message-box-draw-layout-800c293c.md)
adds 3,644 exact code bytes and 96 data/exception bytes, preserving all shared scalars.
The [secondary-base agent adjustor](notes/game-agent-secondary-adjustor-80062d98.md)
adds eight compiler-generated code bytes while preserving the existing methods.
The [registry and factory string continuation](notes/game-registry-factory-string-continuation-8029d05c.md)
adds 76 data bytes with the existing 988-byte registry function unchanged.
The [type-registry diagnostics](notes/game-type-registry-string-append-802ae024.md)
add 36 data bytes while preserving all 1,668 existing code bytes.
The [renderer string continuation](notes/game-renderer-string-continuation-802af064.md)
adds 152 exact data bytes and leaves six trailing original bytes uncredited.
The [callback activation flag guard](notes/game-callback-flag-guard-8025a244.md)
adds 224 exact code bytes with the existing handle declarations unchanged.
The [record completion loop](notes/game-record-completion-loop-8007256c.md) adds
280 exact code bytes and 20 exception bytes using the existing shared layout.
The [menu configuration parser](notes/game-menu-config-parser-800b0468.md) adds
2,120 code bytes and 136 exception bytes while preserving its shared token pool.
The [voice-over buffer initializers](notes/game-voiceover-buffer-initializers-8029f108.md)
add 4,096 data bytes whose capacities are established by the native copy loops.
The [native owner cleanup adjustor](notes/game-owner-cleanup-adjustor-80028140.md)
adds eight exact code bytes using the compiler’s multiple-inheritance support.
The [resource cleanup adjustor](notes/game-owner-cleanup-adjustor-800ccee4.md)
adds eight more code bytes while preserving its full original virtual table.
The [camera bitmap capture lifecycle](notes/game-camera-bitmap-capture-80235d54.md)
adds 3,328 code bytes and 20 scalar bytes with the full native ownership checked.
The [animation event pair](notes/game-animation-event-pair-80233450.md)
adds 3,236 exact code bytes and preserves all shared scalar identities and extents.
The [actor collision events](notes/game-actor-collision-events-8009aea8.md)
add 1,636 exact code bytes and 20 exception bytes with complete scalar ownership.
The [collision event dispatcher](notes/game-collision-event-dispatch-8021da20.md)
adds 1,528 exact code bytes with its native conversion pool and pointer lifetimes.
The [three engine flag arrays](notes/game-three-flag-arrays-reset-80232bb0.md)
add 2,208 exact code bytes and preserve the complete original section coverage.
The [native memory-card hierarchy](notes/game-memory-card-native-hierarchy.md)
adds eight code bytes and 97 data bytes, preserving all 344 affected callers.
The [Light, Fog and resource constructors](notes/game-resource-constructors-20261020.md)
add 416 exact code bytes and preserve all seven affected source objects.
The [indexed handle-pair dispatch](notes/game-indexed-handle-pair-dispatch-8023b418.md)
adds 240 exact code bytes with its native temporary lifetimes.
The [audio bigfile diagnostics](notes/game-audio-bigfile-diagnostics-802af660.md)
add 64 exact data bytes with their original global identity and native linker
retention.
The [small-object allocator diagnostics](notes/game-small-object-allocator-diagnostics-802afb58.md)
add 64 exact data bytes, including a naturally aligned order table.
The expanded [Python global-object strings](notes/game-python-global-object-strings.md)
add 103 exact data and alignment bytes within the existing source unit.
The [Python binding string continuation](notes/game-python-binding-string-continuation-2026-10-20.md)
adds 179 exact bytes by extending two accepted string units.
The [global-agent string pool](notes/game-global-agent-string-pool-802a11d4.md)
adds 1,510 exact data bytes by transferring 67 strings and internal alignment
from original ownership.
The [sound and particle string pool](notes/game-sound-particle-string-pool-8029b2e9.md)
adds 487 exact data bytes from 21 additional strings.
The [pause and menu string pool](notes/game-pause-menu-string-pool-8029a353.md)
adds 389 exact data bytes from 21 menu and agent identifiers.
The [BigFile and stream diagnostic pool](notes/game-bigfile-string-pool-802acaea.md)
adds 366 exact data bytes from 13 diagnostic strings and natural alignment.
The [LOD and split argument pool](notes/game-lod-split-string-pool-802acd70.md)
adds 302 exact data bytes from 15 strings and six boundary alignment bytes.
The [object and material string pool](notes/game-object-material-string-pool-802aef52.md)
adds 126 exact data bytes from six object-loading and material names.
The [game initialization diagnostic pool](notes/game-init-diagnostic-pool-802ae3c8.md)
adds 120 exact data bytes from eight startup and performance strings.
The [camera and music string pools](notes/game-camera-music-string-pools-802aea3a.md)
add 165 exact data bytes from nine resource names and natural alignment.
The [Game_Z binding string continuation](notes/game-python-node-object-strings-802a31a4.md)
adds 68 exact bytes from three additional native names.
The [Throwable and Breakable binding strings](notes/game-throwable-breakable-strings-802a543b.md)
add 77 exact bytes, including their preceding boundary alignment.
The [InGame camera diagnostic strings](notes/game-ingame-camera-strings-802ae549.md)
add 63 exact data bytes, including compiler-owned alignment.
The [voice-over and HUD trailing names](notes/game-voiceover-trailing-names-802a0108.md)
add 112 exact bytes. The adjacent 4,096-byte region is now recovered by the
separate voice-over buffer initializer source above.
The [native method and runtime-base group at 802AFDF4](notes/game-native-method-runtime-group-802afdf4.md)
adds 396 exact data bytes and 87 new pointer relocations.
The [Puzzletile and QSnail15 native records](notes/game-native-member-records-802b7c24-802bee14.md)
add 456 exact data bytes with 91 new pointer relocations.
The [four additional native table groups](notes/game-native-table-groups-20261020.md)
add 624 exact data bytes with 125 new pointer relocations.
The [small native method records](notes/game-native-small-method-records-20261020.md)
add 48 exact data bytes and preserve an unpromoted switch-table probe whose
isolated object matches but whose attempted link failed the DOL hash.
The [callback-owner base-list continuation](notes/game-native-callback-base-list-continuation-20261020.md)
adds 132 exact data bytes from eleven native records, with their original
linker placement preserved inside the preceding source units.
The [seven native method groups](notes/game-native-method-groups-20261020-continuation.md)
add 1,904 exact data bytes with 444 matching pointer relocations across
projectile, snail, LoadingScreen, helmet-state, breakable and camera records.
The [small token pools](notes/game-small-token-pools-20261020.md) add 2,032
data bytes from native menu, resource, editor and attachment names and their
adjacent constants, with all remaining padding under original ownership.
The [further method records and menu pool](notes/game-method-records-and-menu-pool-20261020.md)
add 893 data bytes and 133 matching relocations, preserving neighboring
original jump tables.
The [nine native method pools](notes/game-native-method-pools-20261020.md)
add 8,784 data bytes and 1,935 matching relocations from active automatic
splits, including menu, spatial, drawing, resource and platform interfaces.
Their thirteen smaller neighbors add another 1,016 data bytes, including a
verified HashKey base table and native geometry face indices. Four further
complete runtime tables and callback arrays add 168 bytes with ten relocations.
A further 29 complete callback globals add 1,476 data bytes through eleven
new source units and seventeen existing source extensions. Five more callback
arrays add 276 bytes while preserving all previously emitted weak helpers.
The [nested record handle release](notes/game-nested-record-handle-release-801acfc0.md)
contributes 212 verified code bytes, and [ContainerInVolume registration](notes/game-container-in-volume-registration-800c9ec8.md)
adds 184 code bytes and 36 exception/index bytes. Its complete 96-byte callback pool and the adjacent 148-byte native method table now also match from source. Constructor and callback closures, geometry routines, further native virtual
tables and remaining SDK routines are active work. Earlier frozen evidence remains preserved.

The [paired native owner tables](notes/game-native-owner-tables-802bf2c8.md)
add 800 verified data bytes and 196 matching relocations. The [shared scalar and file suffix block](notes/game-shared-scalars-and-file-suffixes-8037a1f0.md)
adds 52 data bytes while preserving the unresolved 20-byte string/gap interval.
The [native volume table and callback records](notes/game-native-volume-tables-802b2b60.md)
add 288 data bytes, and the [method-table/RTTI group](notes/game-native-rtti-pairs-802b0a18.md)
add 1,864 data bytes with exact relocations.
The [related native method tables and callback records](notes/game-native-method-pair-802b5ec0.md)
add another 384 verified data bytes with 88 matching relocations.
The [larger native owner method table](notes/game-native-method-owner-802bb070.md)
adds 416 data bytes with 101 matching relocations.
The [native runtime-base pool](notes/game-native-base-pool-802c0018.md) adds
4,408 data bytes and 220 matching relocations. The adjacent
[owner-family table group](notes/game-native-owner-family-802b308c.md)
now adds 1,732 bytes of linked source through an aligned enclosing unit.
The [paired agent tables and base list](notes/game-native-agent-tables-802c8c80.md)
add another 344 verified data bytes.
The [native state tables and base lists](notes/game-native-state-tables-802b95b8.md)
add 344 verified data bytes with 60 matching relocations.
The [root-derived method-table group](notes/game-native-root-method-tables-802b23ec.md)
adds 624 verified data bytes and 152 matching relocations across three tables.
The [adjacent root-derived table family](notes/game-native-root-method-family-802b1eac.md)
adds eight more tables, 1,248 verified data bytes and 304 matching relocations.
The [Snowball and projectile method records](notes/game-native-snowball-method-records-802b2934.md)
add 388 verified data bytes with 76 matching relocations.
The [callback dispatch runtime bases](notes/game-native-callback-base-802b2ad4.md)
add 24 data bytes next to two compiler switch tables.
The [native volume method-table group](notes/game-native-volume-method-tables-802b414c.md)
adds 616 verified data bytes and 139 matching relocations.
The [adjacent volume interface tables](notes/game-native-volume-lookat-method-tables-802b4404.md)
add 516 verified data bytes and 115 matching relocations.
The [Checkpoint and Force interface tables](notes/game-native-volume-checkpoint-force-tables-802b4634.md)
add 664 verified data bytes and 150 matching relocations.
The [Costume and Script interface tables](notes/game-native-volume-costume-script-tables-802b4924.md)
add 312 verified data bytes and 76 matching relocations.
The [wood-crate breakable method tables](notes/game-native-breakable-method-tables-802b01a4.md)
add 556 verified data bytes and 126 matching relocations.
The [native hook method records](notes/game-native-hook-method-records-802b0510.md)
add 280 verified data bytes across two adjacent source splits.
The [collectable-agent method records](notes/game-native-collectable-method-records-802b1220.md)
add 468 verified data bytes across three adjacent source splits.
The [Snail-family method and runtime-base records](notes/game-native-snail-method-tables-802bdefc.md)
add 3,220 verified data bytes across seven adjacent source splits.
The [three native neighbor method-record groups](notes/game-native-neighbor-method-records-802b5690.md)
add another 1,036 verified data bytes across three adjacent source splits.
The [nine adjacent native method-record groups](notes/game-native-neighbor-method-records-batch-20261020.md)
add 2,000 verified data bytes across nine adjacent source splits.
The [twenty-one adjacent native method-record groups](notes/game-native-neighbor-method-records-tail-20261020.md)
add 2,996 verified data bytes across twenty-one adjacent source splits.
The [twenty-three medium native neighbor groups](notes/game-native-neighbor-method-records-medium-20261020.md)
add 1,600 verified data bytes across twenty-three adjacent source splits.
The [fifty-three small native neighbor groups](notes/game-native-neighbor-method-records-small-20261020.md)
add 1,492 verified data bytes across fifty-three adjacent source splits.
The [five larger native table groups](notes/game-native-large-vtable-records-802bb6a4.md)
add 1,348 verified data bytes across five adjacent source splits.
The [BalancingBall method and jump-table records](notes/game-balancingball-method-jump-tables-802b7754.md)
add 580 verified data bytes to the preceding base-list source.
The [TeleportVolume method and jump-table records](notes/game-teleport-volume-jump-table-802c1308.md)
add 272 verified data bytes to the preceding base-list source.
The [actor motion clamp probe](notes/game-actor-motion-clamp-80092dac.md)
identifies a 128-byte unclassified function, but remains uncredited.
The [bitmap color decoder](notes/game-bitmap-color-decode-802380d0.md)
adds 176 exact code bytes to the existing bitmap conversion source unit.
The [readable resource and music names](notes/game-readable-resource-neighbors-2026-10-20.md)
add 264 verified data bytes from typed C++ records while preserving the
remaining original alignment bytes. The global resource-cache initializer has
an exact isolated C++ object probe, but its BSS ownership is still coupled to
the matched interpreter initializer and has not been linked as matching source.

The [Python resource factory callback](notes/game-python-resource-callback-800201b0.md)
adds 712 matched code bytes and one function, with all 68 owned exception
metadata bytes verified in the native link and weak duplicates discarded.

The [remaining diagnostic and binding pools](notes/game-readonly-pool-closures-20261020.md)
add 901 data bytes through four source closures with fourteen new globals.
Three further memory-card and actor diagnostic closures add 289 bytes and
ten complete globals. Three initialized counter templates add another 104
bytes with full copy and indexing evidence.

The [Camera constructor](notes/game-camera-constructor-80242120.md) adds
268 code bytes with its existing factory call target preserved. A further
92 [small scalar/token closures](notes/game-small-token-pools-20261020.md)
add 1,536 data bytes and 189 complete globals.
The [BRK movement and GC sound string closures](notes/game-brk-and-sound-string-closures-20261022.md)
add 28 verified data bytes within two existing source units; the adjacent
menu-loop string and its linker tail remain original-owned.
The [MetroTRK mutable state](notes/MetroTRK-mutable-state.md) adds 48 matched
data bytes across its restore, exception and step records.

## Work queue

| ID | Work | Starting evidence | Completion condition |
| --- | --- | --- | --- |
| BUILD-01 | Maintain reproducible matching build and reports | Versioned DOL hash, linker template, compiler pins, and Ninja report targets exist | Standard build passes; snapshots describe the same build |
| RT-01 | Recover and preserve C runtime units | Allocator, termination, file/character I/O, formatted output, decimal conversion, strings, character maps, locale data, the retained math library and C++ exception unwinding are verified; the retained standard exception class methods and their RTTI/vtable records are verified; native ABI helpers and remaining shared data still need reconstruction | Changes retain object matches and the final DOL hash |
| PY-01 | Preserve verified `Objects/moduleobject.c` | Its recovered code, data, and small data are linked from Matching source; the full DOL hash passes | Retain the verified unit while refining names and shared Python declarations |
| PY-02 | Preserve full tuple TU recovery | All 18 linked functions, type/sequence tables, strings, and free list now match | Retain the full match when refining shared declarations |
| PY-03 | Expand interpreter object coverage | The recovered object API, containers, numeric objects, Unicode implementation and generated character tables pass the full DOL hash | Preserve these matches while resolving any remaining unidentified object code |
| PY-04 | Preserve complete embedded interpreter recovery | All 509,816 code bytes across the native Python range `0x80130084..0x801AC7FC`, 1,131 functions and their owned tables/data are integrated and verified | Preserve these matches while improving names and shared declarations |
| PY-05 | Preserve target-specific interpreter support | Module table, explicit signal initialization, path helpers, I/O shims and build-identification strings are integrated with the Python source | Retain exact helpers and tables without assuming the built-in table lists all initialized modules |
| MAP-01 | Recover original TU boundaries | `filemap.json` maps embedded source filenames to references | Confirm section ownership; replace provisional auto splits with named units without regressing the build |
| SDK-01 | Recover remaining runtime and SDK libraries | OS initialization, C exception-table helpers, debugger-interface support, scheduling, reset, SRAM and time are verified, together with startup, projection matrices, DVD operations, video, controller input and debugger transport; audio, AX/mixer, DSP and GBA support are verified; memory-card support including FAT allocation/freeing, host communication and graphics initialization through framebuffer, texture, indirect-texture and pixel operations are verified; display lists, viewport/projection transforms and performance counters are verified; MetroTRK v0.9 initialization, event queue, message buffers, byte-framing input, command handlers, file-support requests, stop notifications, target CPU/register/memory access, transport adaptation, debugger stdio support, memory helpers and reset-vector copying are verified; TEV state/input/alpha/depth operations and stage count are verified; lighting colors, TEV ordering and remaining MetroTRK routines remain active; EXI transfers/UART and SI transfers/polling/sampling tables and the inferred TPL getter are verified | Verify C code and owned data, while keeping native assembly entry points separately attributed and outside C completion |
| GAME-01 | Reconstruct TotemTech and game units | Descriptor-driven routines, key-array templates, controller lifetime/callbacks, viewport rendering, native viewport storage/lifetime and render-slot insertion/removal/dispatch, world-record callback dispatch/reference fixup/loading and native 20-/28-byte record resizing and native 60-/76-/80-byte curve-record resize/destructor pairs, random/scalar math, core arena allocation, file/registry operations, command logging/parsing, console display/screenshot/job callbacks and lifecycle/resource callbacks, resource decoding/resize/reference marking, hierarchy traversal and destruction, handle-array resizing and range distribution with owned identity dispatch, base-object methods and their virtual table, group selection/query/update and related-object forwarding/replacement routines, script-file loading, path conversion/commands, bitset range clearing/destruction, LoadingScreen base/derived setup, class metadata, resource binding/release and screen destructors, Collectable metadata, particle allocation, hierarchy/group forwarding, entry actions/reference assignment, plot setup, batch assignment/clearing, related-status queries, named-world removal and group creation/construction/capacity/activation/deactivation, selection actions/ranges and parameter/vector updates, named-entry/binding commands, hierarchy lifecycle/owner setup/construction with owned group/hierarchy constructor literals, RTC resource forwarding, entry dispatch/replacement, final-list reset/search, console command registration and four-list reset, complete hash-table code, case-folded name hashing, handle-pool setup and flag access, retain/reference updates, owned-token return, pool growth and the native handle destructor, type registration, QSnail initialization/events/derived registrations, TeleportVolume construction/destruction, property loading and event/registry hooks, ContainerInVolume callbacks/flag transitions and class metadata, 54 typed-handle and handle-member destructors, related-handle membership/notification/event-query wrappers, native ObjectsBreak/ObjectsBounce/ObjectsMove construction and destruction, record-pool destruction/release/reset, Activable/Manipulator construction/destruction/list append/word notification and activation/accumulated-float callbacks with a four-byte owned zero constant, the native Activable interface with owned 44-byte table and hooks, Activable list construction/mode-filtered update, InGameObjectsManipulator lifetime/borrowed-handle methods/rotation update with owned static state, literals and its native 76-byte table, Menu2D and Menu3D destruction/render-slot membership/pulse callbacks, native Menu base construction/destruction, Menu2D/Menu3D construction, Menu3D glyph/item/configuration parsing with owned shared strings/constants, Menu3D item insertion/Root callback, both menu color setup and parameterized item-text formatting, Menu2D item insertion/Root callback and the native name default constructor, and the upper Manipulator destructor/empty hook with exact exception metadata and its native 64-byte table owned by the later callback unit, class callback hooks and object factories including Txt, Bitmap, CameraZone and Occluder have verified source; filemap anchors include engine, agent, movement, rendering, and script interfaces | Match bounded units with evidence for names, structures, and shared interfaces |
| SCRIPT-01 | Validate embedded Python script recovery | Extraction/decompilation tools and prior control-flow notes exist | Check recovered control flow against bytecode; track script recovery separately from native code |

The evidence describes available work and explicitly verified increments.
CPython v2.1 is now the strongest verified interpreter source reference; older
version guesses in the research notebook are historical. A completed split
can still cover only part of an original TU. Consult the current source,
configuration, unit notes, and generated progress before taking an item.
The [native record value constructor](notes/game-engine-record-value-constructor.md)
is integrated: the single 64-bit argument resolves the old uncredited two-word
approximation's register differences. Its historical probes remain preserved.
The [list unlink](notes/game-owner-list-unlink.md) and adjacent
[list reorder routine](notes/game-owner-list-reorder.md) now match together
in a complete 3,460-byte source unit. Ordinary typed index and generation
accessors resolve their former register differences; the old private probes
remain preserved and uncredited. The upper Manipulator table now
belongs to the later callback unit: native inline-destructor emission and
ordinary strong/weak resolution preserve the existing early destructor and
resolve the former placement cycle. See [native lifetime evidence](notes/game-manipulator-native-lifetime.md). 

The [menu lifecycle units](notes/game-menu2d-lifecycle.md) now share one verified
Menu base declaration; [Menu3D](notes/game-menu3d-lifecycle.md) has the same
bounded four-function coverage. The [glyph parser](notes/game-input-glyph-parser.md)
is exact in isolation but remains uncredited: all three adjacent parsers must
reproduce their shared compiler-local string pool together before integration.
The configuration parser now matches in isolation; the item parser remains eight bytes short of exact. Their full shared data consumer scan is complete, and both remain uncredited pending exact combined integration. The [Menu base destructor](notes/game-menu-base-lifetime.md), [item insertion and Root callback](notes/game-menu2d-item-append.md), and [name constructor](notes/game-name-default-constructor.md) are integrated and verified. The [three native menu constructors](notes/game-menu-constructors.md) now also pass full integration; their tables and constants retain original ownership. The [Menu3D parser group](notes/game-menu3d-parsers.md) is also integrated with its shared strings/constants; its neighboring Menu2D group remains pending. [Menu3D insertion](notes/game-menu3d-item-append.md), [both color setup routines](notes/game-menu-color-setup.md) and [item-text formatting](notes/game-menu-item-text.md) are verified; the larger layout/rendering routines remain original. The [viewport storage helpers](notes/game-viewport-storage.md) now reconstruct its bounds accessors, reference replacement, native array construction and destruction. The [render-slot group](notes/game-viewport-slots.md) also matches insertion, pointer-based removal, and world/object dispatch. Neighboring projection/camera routines and original shared data remain outside these partial splits. The adjacent [world-record group](notes/game-world-record-callbacks.md) now owns three callbacks/loading routines and two native resize routines; the [native 60-/76-byte curve-record pairs](notes/game-world-curve-arrays.md) now also match resizing and destruction. The [80-byte record pair](notes/game-world-curve50.md) now also matches, completing resizing for the five arrays used by the recovered loader. The [specialized action-curve destructor and native table](notes/game-world-action-curve.md) also match, including nested array cleanup and occupied-token release. The [world record queries and callback dispatcher](notes/game-world-record-queries.md) now also match. The [native resource lifetime](notes/game-world-lifetime.md) now matches construction, destruction, and all three larger record-array destructors; its factory references `Rtc_Z.h`, while the current world-record names remain provisional. The [fixed 144-handle array lifetime](notes/game-world-handle-array.md) also matches. Its adjacent 728-byte population routine now also matches through an ordinary borrowed-pointer value; the previous register-allocation probes remain preserved. The [resource-slot reset](notes/game-resource-slot-reset.md) also matches its complete 1,272-byte body. The [three slot-pool operations](notes/game-resource-slot-pool.md) now also match. The [slot callback dispatcher](notes/game-resource-slot-callbacks.md) now matches as well. The native pool destructor remains an uncredited 412-byte candidate with 13 register/scheduling instruction differences. The [pool-growth routine](notes/game-resource-slot-growth.md), full [acquisition/setup routine](notes/game-resource-slot-acquire.md), and [native slot-resource destructor with its table](notes/game-resource-slot-destructor.md) now also match. The [slot-resource constructor](notes/game-resource-slot-constructor.md) and [handle-resource lifetime/query/callback group with its table](notes/game-handle-resource.md) now also match. The [six-handle resource destructor, loader, reference/status callbacks and table](notes/game-six-handle-resource.md) now also match. The [render object traversal](notes/game-render-object-dispatch.md) and [record-array clearing](notes/game-render-record-clear.md) now also match. The [six-handle constructor pair](notes/game-six-handle-resource-constructor.md), [viewport entry/handle helpers](notes/game-viewport-render-helpers.md), and [world reference callbacks](notes/game-world-reference-callbacks.md) now also match. The [world entry-pool resize](notes/game-world-entry-pool-resize.md) and [platform reset-monitor thread](notes/game-platform-reset-thread.md) now also match. The [platform array lifetime and scalar helpers](notes/game-platform-array-lifetime.md) now also match. The [greatest-age record selection and bounded removal loop](notes/game-platform-record-selection.md) now also match, with verified status/count/age fields. The [record access and reactivation pair](notes/game-platform-record-access.md) also matches; the [linked-index initializer and merge helper](notes/game-platform-index-lists.md) also match. The [record-release routine](notes/game-platform-record-release.md) also matches both chain returns and status/storage updates. The [record-growth routine](notes/game-platform-record-growth.md) also matches all 700 bytes and 21 relocations; the [native array constructor](notes/game-platform-arrays-constructor.md) also matches its 392 bytes, with 360 unlinked weak bytes excluded. The [record deactivation wrapper](notes/game-platform-record-deactivate.md) also matches. Original shared tables and the 440-byte reservation probe (13 instruction differences) remain active. The [platform shutdown and native item destructor](notes/game-platform-shutdown.md) now also match, with verified global declarations through offset `190`. The [cache binding operations and base sentinel](notes/game-platform-cache-binding.md) now also match. The [cache destructors](notes/game-platform-cache-lifetime.md) now match both 604-byte functions through an ordinary const index-reference API. Their complete native binding tables are also verified. Neighboring original code and data remain outside the partial text splits. The [platform pool constructor and destructor](notes/game-platform-pool-lifetime.md) now also match, including shared occupancy/storage cleanup. The [occupied-record sweep and explicit slot release](notes/game-platform-pool-release.md) now also match. The [vacant-slot acquisition and storage growth](notes/game-platform-pool-growth.md) now also match. The [texture initialization/binding routine, compiler jump table and empty hook](notes/game-platform-texture-binding.md) now also match, completing source coverage of the 2,532-byte texture-pool code block; neighboring cache tables remain original. The [aligned-buffer draw wrapper and native index-block interface](notes/game-platform-draw-helpers.md) now also match 252 code bytes and their 16-byte table. The [trigonometric interpolation, angle calculation and table initialization](notes/game-platform-trig.md) now also match 1,256 code bytes and their shared eight-byte conversion constant. Their [lookup arrays](notes/game-platform-trig-tables.md) now own 388 BSS bytes, with four trailing bytes still original. The [scalar logarithm/inverse-cosine wrappers and empty draw callback](notes/game-platform-math-wrappers.md) also match 132 code bytes. The [draw-dispatch wrapper](notes/game-platform-draw-dispatch.md) now matches 48 bytes through virtual slot `60`. The [sprite draw research](notes/game-platform-sprite-draw.md) now records linked-vertex, handle, transform and GX display-list layouts; its literal-constant 2,036-byte probe has 158 differing instruction positions and remains uncredited. The adjacent [flagged-quad renderer](notes/game-platform-debug-quads.md) has a 1,208-byte private probe against 1,220 native bytes; intrinsic rounding and broader instruction convergence remain unresolved. The [ARAM initialization/flush, request submission/completion and acquisition, cursor/reset helpers and two request banks](notes/game-platform-aram.md) now also match 1,836 code bytes and 4,608 BSS bytes. Its [owner/pool lifetime, startup storage and native bitset constructor](notes/game-platform-aram-lifetime.md) now also match 484 new code bytes and 52 data bytes, preserving all earlier callers and completing source code coverage of `8028531C..80285C74`. The adjacent bit search, larger platform draw routines, viewport-render preparation routine, world loader and other shared tables still use original code. The [world handle loader](notes/game-world-handle-loader.md) has its original 3,064-byte size with four load-order instruction differences and remains uncredited. The viewport-render candidate has its original 2,068-byte size but 49 floating-point register-allocation instruction differences and remains uncredited.

## Sequence

1. Preserve a passing reconstruction while expanding matching source.
2. Use small runtime and interpreter units to establish compiler settings and
   shared layouts. Treat function-only probes as evidence to integrate.
3. Recover TU and data ownership from references and section boundaries.
4. Expand into engine and gameplay units, grouping related functions and
   validating shared-header changes against existing matches.
5. Remove original fallback objects as their complete source replacements are
   verified. Finish remaining data and runtime coverage before claiming a
   complete source rebuild.

Do not assign a delivery date from the number of generated objects: their
boundaries are provisional and matching difficulty varies substantially.

## Work-item record

Use the queue ID plus a unit or symbol for a focused handoff. A work item should
contain:

- Unit, symbols, address ranges, and report category.
- State: available, in progress, blocked by a named dependency, or verified.
- Owner or branch, when one is actively working on it.
- Source evidence, compiler settings, and known remaining differences.
- Build, objdiff, and regression results needed to reproduce the conclusion.

The [contributor guide](CONTRIBUTING.md) describes the matching loop and
[progress policy](PROGRESS_POLICY.md) defines what can be counted. Keep research
discoveries in [unit notes](notes/) even when they do not yet produce a source
match; retain the historical research notebook as an archival reference.

The [object-list pool routines](notes/game-object-list-pool.md) now cover
1,228 code bytes across ten functions: record free-list operations, node
release, initialization, group key/object filtering and four cleanup/acquire
helpers. The 128-byte node acquisition and 200-byte combined node-list clear
remain private unresolved probes; original pool storage and borrowed floats
remain uncredited. The subsystem and original file boundary are provisional.

The [platform audio reset and completion routines](notes/game-platform-audio-reset.md)
cover 520 matching code bytes across four functions. The subsequent
[update/path group and scalar data](notes/game-platform-audio-update.md) adds
1,200 matching code bytes across five functions and 40 scalar data bytes.
Handle lookup, fused pan/fade arithmetic and native virtual dispatch now match
in the complete 928-byte update. The [resource loading and track setup routine](notes/game-platform-audio-load.md)
also matches 604 code bytes and eight extension-string bytes. Spatial mixing
and underlying streaming operations remain original; reciprocal-estimate
probes retain an extra rounding instruction and are uncredited.

The [audio control group](notes/game-platform-audio-controls.md) now adds
1,056 code bytes across eight functions, covering fades, level/attenuation
setters, mute flags, sound mode and stream-path forwarding. Native channel
acquisition at `80287178..80287454` remains original between the accepted splits.

The [audio track release helper](notes/game-audio-track-release.md) now matches
324 code bytes, including all three empty-handle lifetime sequences. Channel
selection at `8023B864` remains original.

The [track selector](notes/game-audio-track-select.md) now matches all 652 code
bytes, including both inline release paths and the track-zero fallback. The
[platform acquisition candidate](notes/game-platform-audio-acquire.md) matches
its 732-byte body and local conversion pool in isolation, but remains uncredited
because that eight-byte pool overlaps existing scalar source ownership.

The [audio lookup/setup group](notes/game-audio-track-setup.md) now matches
1,108 code bytes, including duplicate detection and all three handle assignments.
The previously accepted fade caller retains its complete match with a corrected
handle-reference declaration. Original relationship testing and streaming internals
remain available work.

The [audio streaming helper group](notes/game-platform-audio-stream.md) now
matches 1,060 code bytes through wakeup, level/mute controls, indexed/name status
queries and DVD close. Its underlying release/setup/thread routines and original
global mutex/registry/state ownership remain unfinished.

The [streaming mutex and registry-head definitions](notes/game-platform-audio-stream-globals.md)
now own 28 BSS bytes, with earlier consumers fully reverified. Original registry
nodes, state initialization, release/setup/thread code and adjacent data remain
uncredited.

The [streaming removal and lifetime fragments](notes/game-platform-audio-stream-release.md)
now match 616 code bytes across three functions and own 92 BSS bytes for the
shared DVD record and path buffer. The 468-byte indexed cleanup candidate still
differs around diagnostic-call scheduling and remains private, along with its
string definitions. Streaming resource setup, worker code and complete state
initialization remain original.

The [indexed streaming cleanup](notes/game-platform-audio-stream-cleanup.md)
now matches its full 468-byte body and two diagnostic strings (32 rodata bytes).
Its unsigned channel branches, DVD/AX/mixer teardown and original field-reset
order are preserved. Six earlier units retain exact matches after correcting
the shared cleanup result to void. Resource setup and worker code remain
available original streaming work.

The [streaming submission routine](notes/game-platform-audio-stream-submit.md)
now matches all 468 code bytes, including callback/cookie assignment and queue
append. Its 264-byte error callback remains original: the private C++ probe
produces 232 bytes and folds more of the status predicate than the target.
Callback/worker/I/O routines and remaining diagnostic data are available work.

The [streaming initializer](notes/game-platform-audio-stream-init.md) now matches
all 544 code bytes, including records, AX voices, allocation and worker creation.
The physical view now distinguishes four single voices, music and thread
storage. The big-file loader at `8028A88C` has a private 916-byte probe with
eight register differences; status and completion callbacks remain original.

The [disc status/read fragments](notes/game-platform-disc-status.md) now match
188 code bytes across two functions and own four SBSS bytes. The status query
is global and reads no record argument. The [big-file loader investigation](notes/game-platform-audio-stream-open.md)
records a 916-byte private candidate with eight register differences and no
credit. Its metadata/index layout extends the initializer view; callbacks,
worker code, open/load and wait/error handling remain original work.

The [disc wait and display restoration routine](notes/game-platform-disc-wait.md)
now matches 792 code bytes and its 52-byte compiler-generated event table.
Its retry, temporary handle lifetime and display restoration preserve the
original execution path. Adjacent poll/error routines now match as documented below; shared state
remains available work.

The [disc poll group](notes/game-platform-disc-poll.md) now expands the wait
source unit by 536 code bytes and one 52-byte table. The [shared disc error
handler](notes/game-platform-disc-error.md) adds 448 code bytes and its 52-byte
table. Seven static-state bytes remain an isolated, uncredited probe; original
shared flags and callback/state storage remain available work. The native
report now exposes the neighboring zero-filled `8028F698..8028F6B8` region as
an unmatched 32-byte placeholder function; it remains in the denominator.

The [fallback disc display](notes/game-platform-disc-display.md) now matches
1,108 code bytes, 380 message bytes and an eight-byte conversion constant.
The complete GX setup, message selection and temporary handle lifetime are
verified. Its [432-byte text renderer investigation](notes/game-platform-disc-text.md)
has a private same-size probe with 37 instruction differences and no credit.
The text renderer and shared graphics/status storage remain original work.

The [fallback font data](notes/game-platform-disc-font.md) now owns the
3,072-byte I4 atlas as editable glyph rows, its 32-byte texture object and
20 projection-constant bytes. Four original alignment bytes remain explicitly
uncredited in the native denominator. This data-only unit adds no code;
renderer and shared state reconstruction remain available work.

The [video resume and enabled query](notes/game-platform-video-resume.md) now
match 156 code bytes across two functions; [allocation cleanup](notes/game-platform-video-cleanup.md)
adds 112 bytes and its native virtual callback. Shared video mode and small-data flags
remain original. The [404-byte pause routine](notes/game-platform-video-pause.md)
now matches, followed by [168-byte movie initialization](notes/game-platform-movie-init.md)
and the [636-byte display worker](notes/game-platform-movie-display.md).
The [movie storage layout](notes/game-platform-movie-storage.md) supplies
18,224 BSS bytes, preserving explicit unknown tail fields. Three
[decoder layout helpers](notes/game-movie-decoder-layout.md) add 184 code bytes.
The [table initializer](notes/game-movie-decoder-tables.md) adds 864 code bytes
and 2,624 BSS bytes for clipping and reciprocal arrays.
The [plane record initializer](notes/game-movie-decoder-record.md) adds 284
bytes, followed by [workspace setup](notes/game-movie-decoder-workspace.md)
at 1,124 bytes, the [first frame decoder](notes/game-movie-decoder-frame.md)
at 1,296 bytes and its neighboring [dispatch wrapper](notes/game-movie-decoder-dispatch.md)
at 36 bytes. The [second frame decoder](notes/game-movie-decoder-interframe.md)
adds 1,448 bytes; its reconstruction callee remains original.
The [DPCM tables](notes/game-movie-dpcm-tables.md) add 3,560 data bytes from
quantization steps and index rules. Their four preceding alignment bytes retain
explicit original ownership and remain uncredited.

The [remaining movie investigation](notes/game-platform-movie-research.md)
records a 164-byte probe for the native 168-byte DMA worker and a same-size
480-byte YUV converter with 32 differing instruction words. Neither earns
source credit. A 100-byte reader probe at `802912D0` still differs in 19 words.
The [1,044-byte DPCM decoder](notes/game-movie-dpcm-decode.md) now matches its
complete body and native stack frame. The remaining decoder routines, movie playback routine,
small-data state and font renderer remain available work.

The [allocation shims](notes/game-heap-wrappers.md) now match 204 code bytes
and 60 exception-record bytes. The [bounded game leaf fragments](notes/game-leaf-continuation.md)
add 684 functions and 4,068 code bytes through empty operations, scalar
accessors, constant returns and subobject addresses. Each fragment keeps
physical text ownership explicit; original tables, fields beyond the observed
accesses, larger callers, and native adjusting branch thunks remain outside
these partial splits.

The [later engine leaves](notes/game-leaf-late-continuation.md) add another
150 functions and 1,000 text bytes. The [extended scalar fragments](notes/game-leaf-extended.md)
add 64 functions, 1,340 text bytes and their four-byte startup reference;
the [late scalar operations](notes/game-scalar-late.md) add 48 functions,
2,304 text bytes and a separate four-byte startup reference. Original
constructors stay registered, and unowned tables retain fallback ownership.

The [aligned allocation wrappers](notes/game-heap-aligned-wrappers.md),
[pool resize](notes/game-platform-heap-resize.md) and
[pool release](notes/game-platform-heap-free.md) now match 1,180 text bytes.
Their private observed pool layout is shared only by the new fragments.
Allocator context storage, the allocation body, pool creation and record
release remain available work. The [selected-index collector](notes/game-index-selection-collect.md),
[grid traversal and record operations](notes/game-index-grid-records.md),
[grid growth](notes/game-index-grid-acquire.md), and
[handle-list operations](notes/game-handle-list-operations.md) now also match.

The [single-bit reader](notes/game-movie-decoder-bit.md) and
[Huffman-symbol reader](notes/game-movie-decoder-symbol.md) now match
176 code bytes. Plane unpacking and the neighboring predictor remain active
research. The [2026-10-10 continuation record](notes/continuation-2026-10-10.md)
records the preserved baseline, validation evidence and remaining work.

The [early scalar continuation](notes/game-scalar-early.md) and
[middle scalar operations](notes/game-scalar-middle.md) now add 110 functions,
4,972 code bytes, and 12 startup bytes with full-link acceptance.
[Handle control](notes/game-handle-list-control.md),
[action](notes/game-handle-list-action.md), and
[reverse lookup](notes/game-handle-reverse-find.md) add 924 code bytes.
[Sparse callback update](notes/game-sparse-callback-update.md) and
[drain](notes/game-sparse-callback-drain.md),
[fixed-record copy](notes/game-fixed-record-copy.md), and
[heap-record release](notes/game-platform-heap-record-release.md) add another
1,688 code bytes. Movie [output records](notes/game-movie-output-records.md),
[interpolation helpers](notes/game-movie-block-interpolation.md), and
[block dispatch](notes/game-movie-block-dispatch.md) now match 2,056 code bytes.
Original neighboring functions and shared data remain in their recorded
fallback units; these text fragments do not imply complete original units.

Further accepted partial source includes [resource lifetime/serialization](notes/game-resource-lifetime-801F0518.md),
[handle array clear](notes/game-handle-array-clear.md), [key lookup](notes/game-handle-key-find.md),
[owner update](notes/game-handle-owner-update.md), [sparse lookup](notes/game-sparse-handle-key-find.md),
and [indexed action](notes/game-indexed-handle-action.md). Movie [output rows](notes/game-movie-output-rows.md)
now match 776 bytes. The [early record initializers](notes/game-scalar-early-more.md)
match 12,028 code bytes and all 1,880 owned native exception bytes.
The [middle engine continuation](notes/game-scalar-middle-more.md) and
[late record setup](notes/game-record-setup-late.md) add 5,336 code bytes.
[Callback iteration](notes/game-callback-cycle.md) and [dispatch](notes/game-callback-dispatch.md),
[plane bounds testing](notes/game-plane-bounds-test.md), [array-pair reading](notes/game-array-pair-read.md),
[timer insertion](notes/game-timer-linked-list-insert.md), [grid resolution](notes/game-index-grid-resolve.md)
and [initialization](notes/game-index-grid-init.md) add another 2,632 code bytes.
Each batch passes the original complete-DOL hash and regression/source-extent checks.

[Callback flag/list controls](notes/game-callback-controls.md),
[pointer search and snapshots](notes/game-callback-snapshot.md),
[snapshot destruction](notes/game-callback-snapshot-destroy.md), and
[reset/recursive destruction](notes/game-callback-reset-and-destruction.md)
now have full executable acceptance. The [engine loop batch](notes/game-engine-loops.md),
[engine leaf/coalescer batch](notes/game-engine-leaf.md), and
[queue follow-up](notes/game-engine-queue-followup.md) also match completely
within their recorded partial extents. Controller [polling](notes/game-controller-poll.md),
[render setup](notes/game-render-state-init.md), [matrix loading](notes/game-render-matrix-load.md),
[depth clearing](notes/game-depth-rectangle-clear.md), and byte-buffer
[initialization](notes/game-byte-buffer-init.md), [reset](notes/game-byte-buffer-reset.md)
and [destruction](notes/game-byte-buffer-destroy.md) retain all external original data owners.

Callback [key updates](notes/game-callback-key-update.md),
[owner lifetime](notes/game-callback-owner-lifetime.md),
[facade wrappers](notes/game-callback-facade-wrappers.md), and
[handle-chain accessors](notes/game-callback-handle-chain.md) are accepted.
The engine [record/lifetime continuation](notes/game-engine-records-more.md),
[queue iterator](notes/game-engine-queue-iterator.md), and
[event dispatch](notes/game-engine-record-dispatch.md) also have full hash
acceptance. Controller [acquisition](notes/game-controller-record-acquire.md)
and [lifecycle](notes/game-controller-status-lifecycle.md) match, as do the
memory-card [owner operations](notes/game-memory-card-owner-ops.md),
[query](notes/game-memory-card-query.md), [state](notes/game-memory-card-state.md),
[preparation](notes/game-memory-card-prepare.md), [labels](notes/game-memory-card-labels.md)
and [initialization](notes/game-memory-card-init.md). These text fragments
preserve external original data, tables, startup and neighboring ownership.

Further callback source now includes [object wrappers](notes/game-callback-object-wrappers.md),
[record lifetime](notes/game-callback-record-lifetime.md),
[related-object dispatch](notes/game-callback-related-dispatch.md),
[state adapters](notes/game-callback-state-adapters.md),
[virtual handle operations](notes/game-callback-virtual-handles.md),
[line reading](notes/game-callback-line-reader.md),
[startup wrappers](notes/game-callback-startup.md), and
[typed-handle assignment](notes/game-callback-typed-assignment.md).
Ordinary C++ object lifetimes reproduce the observed initialization and
cleanup. Unused weak destructors are explicitly inventoried, discarded by
the linker, and excluded from progress.

Engine [registry operations](notes/game-engine-registry.md),
[dispatch](notes/game-engine-dispatch.md), [vector operations](notes/game-engine-vector-ops.md),
[handle paths](notes/game-engine-handle-paths.md),
[tree records](notes/game-engine-tree-records.md),
[record buffers](notes/game-engine-record-buffers.md),
[transform records](notes/game-engine-transform-records.md),
[record lookup](notes/game-engine-record-lookup.md),
[matrix traversal](notes/game-engine-matrix-tree.md), and
[record clearing](notes/game-engine-record-clear.md) have full executable
acceptance. Each remains a partial original unit with explicit external data
and neighboring-function ownership.

The later handle work includes [returned-handle access](notes/game-callback-return-handle.md),
[returned-handle dispatch](notes/game-callback-return-dispatch.md),
[buffer serialization](notes/game-callback-buffer-serialization.md),
[named selection](notes/game-callback-named-selection.md), and
[nested flags](notes/game-callback-nested-flags.md).
Engine [list/drawing lifetimes](notes/game-engine-links.md),
[pool lifetimes](notes/game-engine-pool-lifetime.md),
[member lifetimes](notes/game-engine-member-lifetime.md),
[array-owner cleanup](notes/game-engine-array-owner-cleanup.md), and
[menu-array cleanup](notes/game-engine-menu-array-cleanup.md) retain strict
text-only ownership and full executable acceptance.

Memory-card [file lookup](notes/game-card-file-exists.md),
[deletion](notes/game-card-file-delete.md), [replacement](notes/game-card-file-replace.md),
and [thread initialization](notes/game-card-threads-init.md) are accepted,
as are [audio resource streaming](notes/game-audio-resource-stream.md),
[context path loading](notes/game-context-path-load.md) and
[saving](notes/game-context-path-save.md). Original buffers, pooled strings,
constants and remaining neighboring operations retain external ownership.

The [unique-value list](notes/game-callback-value-list.md),
[returned-handle pair](notes/game-callback-return-pair.md), and
[indexed matrix lookup](notes/game-callback-indexed-matrix.md) now pass full
executable acceptance, along with [array growth](notes/game-engine-array-growth.md),
[additional array operations](notes/game-engine-array-operations-more.md) and
[nested pool resizing](notes/game-engine-pool-resize.md). The
[record-stream reader](notes/game-owner-record-stream.md),
[record-owner cleanup](notes/game-owner-record-destroy.md),
[resource-owner cleanup](notes/game-resource-owner-destroy.md), and
[transform-owner cleanup](notes/game-transform-owner-destroy.md) also match.
Original data and methods outside these explicit text ranges remain original;
unreferenced compiler cleanup functions receive no source credit.

Further accepted callback work covers [related-object removal](notes/game-callback-related-remove.md),
[parent transfer](notes/game-callback-parent-transfer.md),
[owner linking](notes/game-callback-owner-link.md),
[fallback dispatch](notes/game-callback-return-fallback.md),
[named target creation](notes/game-callback-named-target.md),
[handle classification](notes/game-callback-handle-classify.md),
[descriptor creation](notes/game-callback-descriptor-factory.md), and
[transform copying](notes/game-callback-transform-copy.md).
Engine [range operations](notes/game-engine-range-operations.md),
[range dispatch](notes/game-engine-range-dispatch.md),
[range allocation](notes/game-engine-range-allocation.md),
[curve resizing](notes/game-engine-curve-resize.md),
[cache setup](notes/game-engine-cache-setup.md),
[reset polling](notes/game-engine-reset-poll.md),
[viewport console parsing](notes/game-engine-viewport-console.md),
[collision results](notes/game-engine-collision-results.md), and
[record transfers](notes/game-engine-record-transfer.md) also pass full
executable acceptance. The [curve update](notes/game-curve-channels-update.md)
and [reset](notes/game-curve-channels-reset.md) methods, together with
[owned-array append](notes/game-owned-array-push.md) and
[compaction](notes/game-owned-array-compact.md), retain explicit text-only
ownership. Each note records the established partial layouts and external
data; discarded weak helpers remain outside the progress count.

The callback [index start](notes/game-callback-index-start.md),
[record defaults](notes/game-callback-record-defaults.md),
[index dispatch and conversion literal](notes/game-callback-index-dispatch.md),
[quaternion chain](notes/game-callback-quaternion-chain.md), and
[indexed rotation](notes/game-callback-indexed-rotation.md) now pass full
executable acceptance. Their private layouts express observed fields and
calling conventions without asserting complete original class identities.
The [record-owner constructor](notes/game-callback-record-owner-construct.md)
and [destructor](notes/game-callback-record-owner-destroy.md), together with
[both tail-owner cleanup paths](notes/game-callback-tail-destroy.md), retain
native C++ lifetime behavior and exact existing callers.

The [bit-record assignment](notes/game-bit-record-assignment.md) and
[native copy constructor](notes/game-bit-record-copy-constructor.md),
[property snapshot](notes/game-owner-property-snapshot.md) and
[restore](notes/game-owner-property-restore.md), and
[parent handle replacement](notes/game-owner-parent-handle-set.md) also match.
The native copy-constructor spelling migration preserves every byte in all
three shared-header consumers. [Conditional position](notes/game-owner-conditional-position.md),
[composed orientation](notes/game-owner-composed-orientation.md), and
[playback reset](notes/game-owner-playback-reset.md) retain exact text ownership.

Engine [record output](notes/game-engine-record-output.md),
[transform building](notes/game-engine-transform-build.md),
[fixed records](notes/game-engine-fixed-records.md),
[vector storage and cleanup](notes/game-engine-vector-owner.md),
[frame gating](notes/game-engine-frame-gate.md),
[handle reset](notes/game-engine-handle-reset.md), and
[handle-stream visits and reading](notes/game-engine-handle-stream.md) now have
full executable acceptance. Original strings, shared tables and neighboring
operations remain outside these partial source splits.

The [native container constructor](notes/game-container-native-construct.md),
[base initialization](notes/game-container-initialization.md),
[layer initialization](notes/game-container-layer-initialization.md), and
[two-handle initialization](notes/game-container-two-handle-initialization.md)
now match. Unreferenced private compiler helpers are excluded from progress.
Where a weak cleanup duplicate shares an existing native name, acceptance
proves that the exact earlier strong source definition, its owned exception
data, address, extent and linked original bytes remain in place.

Further accepted work covers [primary callback reset](notes/game-callback-primary-reset.md),
[indexed vector copying](notes/game-callback-indexed-vector.md),
[motion reset](notes/game-owner-motion-reset.md) and
[start](notes/game-owner-motion-start.md),
[base motion reset](notes/game-owner-base-motion-reset.md),
[parent reconciliation](notes/game-owner-parent-reconcile.md),
[facing dispatch](notes/game-owner-facing-dispatch.md), and
[flagged dispatch](notes/game-owner-flagged-dispatch.md).
The [native default record constructor](notes/game-bit-record-default-constructor.md)
and its array caller retain all 1,620 original consumer bytes after native
symbol migration. Engine [handle rebinding](notes/game-engine-handle-rebind.md),
[array readback](notes/game-engine-array-readback.md), and
[flagged handle search](notes/game-owner-flagged-handle-find.md) also pass full
executable acceptance. Unlinked cleanup backups receive no source credit.

[Queue target replacement](notes/game-queue-target-replace.md),
[small owner operations](notes/game-engine-owner-small.md),
[motion target assignment](notes/game-owner-motion-target-set.md), and
[nested array resize/cleanup](notes/game-engine-nested-arrays.md) now pass full
executable acceptance. These source units claim their explicit original text
ranges; external data and unused compiler cleanup backups remain uncredited.

[Indexed device dispatch](notes/game-indexed-device-dispatch.md),
[small owner wrappers](notes/game-engine-owner-wrappers.md),
[resource rebinding](notes/game-engine-resource-rebind.md), and
[handle-array capacity operations](notes/game-engine-handle-arraycopy.md) now
retain full executable acceptance. Their notes distinguish exact retained
source from neighboring private probes and unused weak helper output.

The face-record reader and owner move initializer/record release add 960 verified code bytes across three functions. See [face-record readback](notes/game-face-record-readback.md), [owner move initialization](notes/game-owner-move-init.md), and [owner record release](notes/game-owner-record-release.md). Their full build passes the original DOL hash, baseline regression checks, source extents, generated progress and all 26 tests.

The [32-byte record stream reader](notes/game-engine-record-stream-more.md) and [motion preparation](notes/game-owner-motion-prepare.md) add another 920 accepted code bytes. The original executable hash, baseline regression checks, source extents, generated progress and all 26 tests pass.

[Handle transfers](notes/game-engine-handle-transfers.md) and [indexed timing dispatch](notes/game-owner-indexed-timing-dispatch.md) bring accepted code to 44.042740%, with 4,983 matching functions. Full original executable hash, baseline regression, source extent/progress checks and all 26 tests pass.

[Motion completion](notes/game-owner-motion-finish.md), [parameterized native record construction](notes/game-bit-record-parameter-constructor.md), and [nested array cleanup](notes/game-engine-nested-cleanup.md) add 1,544 accepted code bytes. Full executable acceptance passes the original hash, baseline regression, source extent/progress checks and all 26 tests. The constructor has no remaining provisional-name callers.

The [ObjectsMove native destructor](notes/game-objects-move-destructor.md) and [related-origin setter](notes/game-owner-related-origin-set.md) add 900 accepted code bytes with full original executable acceptance. The destructor reconciles the external base identity without changing its address, ownership or source credit.

The [ObjectsBase native destructor and original exception metadata](notes/game-objects-base-destruction.md), [related transform dispatch](notes/game-owner-related-transform-dispatch.md), and [array start/read operations](notes/game-engine-array-starts.md) add 2,832 accepted code bytes and 52 data bytes. Original executable hash, baseline regressions, source extents, generated progress and all 26 tests pass.

The [early native object destructor chain](notes/game-objects-early-destructor-chain.md), [related-position setter](notes/game-owner-related-position-set.md), [indexed-parent reset](notes/game-owner-indexed-parent-reset.md), and [grid collision queries](notes/game-engine-grid-queries.md) add 2,620 accepted code bytes and 156 original exception metadata bytes. Full executable hash, baseline regressions, source extents, generated progress and all 26 tests pass.

[Early native array destructors](notes/game-array-early-destructors.md) and [handle event visitation](notes/game-owner-handle-event-visit.md) add 1,444 accepted code bytes and 216 data bytes, including the event visitor’s exclusive compiler conversion literal. Full executable hash, baseline regression, source extent/progress checks and all 26 tests pass. Verified matching functions now exceed 5,000.

[Further native array destructors](notes/game-array-more-destructors.md), [record timeout visitation](notes/game-owner-record-timeout-visit.md), and [facing interpolation](notes/game-owner-facing-interpolate.md) add 1,664 accepted code bytes and 260 original exception metadata bytes. The original executable hash, baseline regression checks, source extents, generated progress and all 26 tests pass.

[Nested native record/array lifetime](notes/game-nested-lifetime-destructors.md), [record property dispatch](notes/game-owner-record-property-dispatch.md), [relative-position readback](notes/game-owner-relative-position-get.md), and [index-chain insertion](notes/game-engine-index-chain.md) pass full executable acceptance with 2,080 additional code bytes and 208 exception metadata bytes.

[Early engine lifetime](notes/game-engine-early-eh.md), [agent lifetime](notes/game-engine-agent-eh.md), [container agents](notes/game-engine-container-agents.md), [agent routes](notes/game-engine-agent-routes.md), [multiple container agents](notes/game-engine-multi-agents.md), [rotation start](notes/game-owner-rotation-start.md), [rotation parent assignment](notes/game-owner-rotation-parent-set.md), [related transform application](notes/game-owner-related-transform-apply.md), [related position application](notes/game-owner-related-position-apply.md), and the [base](notes/game-engine-base-factory.md)/[game](notes/game-engine-game-factory.md) factories add 7,196 accepted code bytes and 1,144 original exception metadata bytes. The dependency inventory includes only actual undefined ELF symbols, avoiding collisions with compiler-local exception labels.

[Container member destruction](notes/game-container-member-destruction.md), [shared secondary-base destruction](notes/game-engine-secondary-base.md), and [active-motion visitation](notes/game-owner-active-motion-visit.md) add 2,504 accepted code bytes and 104 exception metadata bytes. Original executable hash, baseline regressions, source extents, generated progress and all 26 tests pass; verified code reaches 44.916435%.

[Fixed record-array lifetime](notes/game-fixed-array-lifetime.md), [container variants](notes/game-engine-container-variants.md), [group membership](notes/game-engine-group-membership.md), and [bounds reduction](notes/game-owner-bounds-reduce.md) add 5,820 accepted code bytes and 780 exception metadata bytes. Full original executable hash, baseline regression, source extent/progress checks and all 26 tests pass. Verified code reaches 45.139613%, with 5,067 functions.

[Nested container allocation cleanup](notes/game-container-nested-cleanup.md), [small native engine lifetime](notes/game-engine-small-eh.md), and [record append/copy](notes/game-engine-record-append.md) add 3,380 accepted code bytes and 788 original exception metadata bytes. Full executable acceptance passes the original hash, baseline regressions, source extent/progress checks and all 26 tests. Verified code reaches 45.269226%, with 5,081 functions.

[Native array lifetime](notes/game-engine-array-eh.md), [owner cleanup](notes/game-engine-owner-eh.md), [protected-name cleanup](notes/game-engine-protected-eh.md), [descendant collection](notes/game-object-descendant-collect.md), and [record stream initialization](notes/game-engine-record-stream.md) add 4,384 accepted code bytes and 884 exception metadata bytes. The protected entry preserves existing callers through ordinary C++ exception-aware deletion. Full original executable hash, baseline regression, source extent/progress checks and all 26 tests pass. Verified code reaches 45.437338%, with 5,100 functions.

[Spatial-grid updates](notes/game-object-spatial-grid-update.md), [scoped handle lookup](notes/game-scoped-handle-lookup.md), and [record-owner cleanup](notes/game-engine-record-owner-destroy.md) add 1,512 accepted code bytes. The original executable hash, baseline regression, source extent/progress checks and all 26 tests pass. Verified code reaches 45.495319%, with 5,103 functions.

[Reverse sphere lookup](notes/game-reverse-sphere-lookup.md) and [reverse hit lookup](notes/game-reverse-hit-lookup.md) add 664 accepted code bytes. The full build preserves the original executable hash and passes baseline regression, source extent/progress checks and all 26 tests. Their ten unreferenced weak backups remain uncredited and absent from the final executable. Verified code reaches 45.520781%, with 5,105 functions.

[Nested handle transfer](notes/game-engine-handle-transfer.md) adds 324 accepted code bytes. Full original executable hash, baseline regressions, source extent/progress checks and all 26 tests pass. Verified code reaches 45.533205%, with 5,106 functions.

[Typed pool-cluster cleanup](notes/game-pool-cluster-destructors.md) adds 1,140 accepted code bytes and 104 original exception metadata bytes. Both routines matched their first ordinary C++ probes. Full original executable hash, baseline regression, source extent/progress checks and all 26 tests pass. Verified code reaches 45.576921%, with 5,108 functions.

[Native handle reset destruction](notes/game-container-reset-destructors.md), [further engine lifetime](notes/game-engine-fn-eh.md), [sparse handle deletion](notes/game-sparse-handle-erase.md) and [insertion](notes/game-sparse-handle-insert.md), [handle-type collection](notes/game-handle-type-collect.md), and [group-record append](notes/game-engine-group-record-append.md) add 5,676 accepted code bytes and 520 original exception metadata bytes. The three reset destructors retain exact exception pointers to independently verified strong Handle definitions. Full native linking proves that all 756 backup code/metadata bytes are discarded and uncredited. Original executable hash, baseline regressions, source extent/progress checks and all 26 tests pass. Verified code reaches 45.794577%, with 5,118 functions.

[Menu pool lifetime](notes/game-menu-pool-destructors.md), [two-level native lifetime](notes/game-engine-fn-layers.md), [three-level native lifetime](notes/game-engine-fn-three-layers.md), and [group-record updates](notes/game-engine-group-record-update.md) add 10,404 accepted code bytes and 3,328 original exception metadata bytes across 65 functions. Full original executable hash, baseline regression, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 46.193538%, with 5,183 functions.

[Further container lifetime](notes/game-container-more-destructors.md), [resetting native base layers](notes/game-engine-fn-reset-layers.md), and [additional table layers](notes/game-engine-fn-layers-more.md) add 14,880 accepted code bytes and 5,148 original exception metadata bytes across 99 functions. The original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 46.764139%, with 5,282 functions.

[C-entry lifetime forwarding](notes/game-engine-fn-forward-eh.md), [native resource-owner destruction](notes/game-complex-owner-destructors.md), and [sparse-pool cleanup](notes/game-sparse-pool-destroy.md) add 9,644 accepted code bytes and 3,732 original exception metadata bytes across 72 functions. Existing C entry names remain intact for compiled callers. The original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 47.133956%, with 5,354 functions.

[Inline C-entry lifetime](notes/game-engine-fn-inline-eh.md), [native base cleanup](notes/game-engine-fn-cleanup-eh.md), and the [ScreenBase factory](notes/game-screen-base-factory.md) add 4,284 accepted code bytes and 1,560 original exception metadata bytes across 31 functions. The factory's three unused weak Handle destructors remain uncredited and absent from the final executable. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 47.298234%, with 5,385 functions.

[Resource-pointer/storage-owner destruction](notes/game-resource-owner-destructors.md) and [Handle/container cleanup](notes/game-engine-fn-handle-cleanup-eh.md) add 7,104 accepted code bytes and 2,024 original exception metadata bytes across 31 functions. Full original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 47.570650%, with 5,416 functions.

[Final small lifetime cleanup](notes/game-engine-fn-final-cleanup-eh.md) and [grid sphere traversal](notes/game-grid-sphere-visit.md) add 1,432 accepted code bytes and 332 original exception metadata bytes across seven functions. The protected C entry and all eleven pre-existing caller/header files remain intact. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 47.625563%, with 5,423 functions.

[Callback forwarding](notes/game-engine-callback-forward.md), [callback lookup](notes/game-engine-callback-lookup.md), [virtual setup](notes/game-engine-virtual-setup.md), [Python native factories](notes/game-python-owner-factories.md), [Handle copy construction](notes/game-engine-handle-copy-pair.md), [queue reset](notes/game-engine-queue-reset.md), [queue transfer](notes/game-engine-queue-transfer.md), and [grid sphere collection](notes/game-grid-sphere-collect.md) add 32,032 accepted code bytes and 3,540 original exception metadata bytes across 182 functions. Full original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 48.853889%, with 5,605 functions.

[Early construction](notes/game-engine-early-construct.md), [additional setup](notes/game-engine-early-setup-more.md), [Python scalar getters](notes/game-python-scalar-bindings.md), [render index reset](notes/game-render-index-reset.md), [grid X clipping](notes/game-grid-x-clip.md), [queue-grid reset](notes/game-engine-queue-grid-reset.md), and [Handle-array lookup](notes/game-engine-handle-array-find.md) add 12,964 accepted code bytes and 2,580 original exception metadata bytes across 133 functions. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 49.351018%, with 5,738 functions.

[Python scalar arguments](notes/game-python-scalar-inputs.md), [void virtual methods](notes/game-python-void-bindings.md), [native void methods](notes/game-python-native-void-bindings.md), and [vector setup](notes/game-engine-early-vector-setup.md) add 20,896 accepted code bytes and 2,800 original exception metadata bytes across 140 functions. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 50.152314%, with 5,878 functions.

[Python two-object bindings](notes/game-python-two-object-bindings.md), [scalar/default setup](notes/game-engine-early-scalar-setup.md), and the [Bitmap parameter constructor](notes/game-engine-bitmap-param-constructor.md) add 14,512 accepted code bytes and 1,440 original exception metadata bytes across 73 functions. The constructor uses a guarded native C++ identity without changing compiled callers. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 50.708803%, with 5,951 functions.

[Python three-object bindings](notes/game-python-three-object-bindings.md), [native pointer returns](notes/game-python-pointer-bindings.md), [Python integer-object arguments](notes/game-python-long-inputs.md), [native member setup](notes/game-engine-early-member-setup.md), and the [three-handle constructor](notes/game-engine-triple-handle-constructor.md) add 9,108 accepted code bytes and 980 original exception metadata bytes across 45 functions. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 51.058066%, with 5,996 functions.

[Python flags/default bindings](notes/game-python-misc-bindings.md) and [native flag construction](notes/game-engine-early-flag-construct.md) add 4,508 accepted code bytes and 620 original exception metadata bytes across 27 functions. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 51.230934%, with 6,023 functions.

[Mixed Python object/scalar bindings](notes/game-python-mixed-object-bindings.md), [Handle value setup](notes/game-engine-handle-value-setup.md), [flag setup](notes/game-engine-early-flag-setup.md), [spatial Handle construction](notes/game-engine-spatial-handle-constructor.md), [basis-resource construction](notes/game-engine-basis-resource-constructor.md), [spatial-binding construction](notes/game-engine-spatial-binding-constructor.md), and adjacent record/key setup add 9,132 accepted code bytes and 1,000 original exception metadata bytes across 53 functions. Guarded identifier migrations preserve all allocated consumer bytes and resolved targets; complete originals and frozen proofs are retained. The isolated text-color routine remains uncredited because its shared conversion pool is unresolved. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit pass. Verified code reaches 51.581117%, with 6,076 functions.

[Material animation construction](notes/game-engine-material-anim-constructor.md), additional queue/draw/menu constructors, [scene Handle setup](notes/game-engine-scene-handle-setup.md), [Handle member assignment](notes/game-engine-handle-member-assign.md), and [scene owner construction](notes/game-engine-scene-owner-construct.md) add 3,964 accepted code bytes and 856 original exception metadata bytes across 20 functions. Three initial factory files retain their complete originals; audited identifier replacements preserve all allocated bytes and resolved targets. Full original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard checks across 17 source units pass. Verified code reaches 51.733124%, with 6,096 functions.

[Python multi-integer bindings](notes/game-python-multi-integer-bindings.md), [native name/Handle construction](notes/game-engine-name-handle-construct.md), [inline base construction](notes/game-engine-inline-base-construct.md), [corrected guarded layout](notes/game-engine-guarded-native-layout.md), [viewport manipulator construction](notes/game-engine-manipulator-resource-constructor.md) and destruction, plus key lookup and formatting add 8,656 accepted code bytes and 792 original exception metadata bytes across 37 functions. Preserved caller migration proofs include the original viewport literal pool and complete factory objects. Full original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard checks across 18 source units pass. Ten disposable guard tests cover accepted identifier chains and rejected source/object/proof changes. Verified code reaches 52.065055%, with 6,133 functions.

[Derived Handle construction](notes/game-engine-derived-handle-construct.md), [neighbor-grid queries](notes/game-neighbor-grid-query.md), and [flag/member queries](notes/game-flag-member-query.md) add 1,560 accepted code bytes and 340 original exception metadata bytes across eight functions. A repeated factory identifier migration extends the preserved proof chain without changing allocated consumer bytes or relocation targets. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests and repeated native backup-discard audit across 18 source units pass. Verified code reaches 52.124876%, with 6,141 functions.

[Base/Handle construction](notes/game-engine-base-handle-construct.md), [Python name and Handle pointer bindings](notes/game-python-pointer-key-bindings.md), [event counters](notes/game-event-counter-update.md), and [child-volume queries](notes/game-engine-volume-children-query.md) add 7,556 accepted code bytes and 1,852 original exception metadata bytes across 22 functions. Original executable hash, baseline regressions, source extent/progress checks, all 26 tests, preserved consumer migration chains and repeated native backup-discard audit across 18 source units pass. The counter manifest preserves its original semantic EH labels separately from actual compiler-local object names. Verified code reaches 52.414625%, with 6,163 functions.

The `layered-return-queries` checkpoint reaches 1,371,536 verified code bytes
(52.594088%) and 6,185 functions. It accepts native local, temporary and layered
construction, two callback/container constructors, two Python Handle return
bindings, and nine independent owner/resource queries. All retained code and
exception records match in production objects; the original DOL hash, baseline
regression check, source extents, generated progress and 26 tests pass. Twenty
source units also pass the full native-link weak-helper and backup-EH discard
audit. Fourteen callers retain identical allocated bytes and actual targets
through the preserved identifier-only migration proof.

The `camera-callback-factories` checkpoint reaches 1,374,400 verified code bytes
(52.703913%) and 6,197 functions. It accepts the full camera constructor, three
callback constructors, five native Python factories and three independent
resource updates. Thirteen consumer files and thirteen objects retain identical
allocated code and actual resolved targets through the guarded name migrations.
Original hash, no-regression checks, source extents, progress, 26 tests and all
twenty native-link override audits pass.

The `resource-native-construct` checkpoint reaches 1,376,564 verified code bytes
(52.786896%) and 6,211 functions. Fourteen resource constructors add 2,164 exact
code bytes and 680 owned exception/index bytes, with 236 actual relocations and
no extra allocations. Three existing factory sources pass the unchanged-byte
native-name migration guard. The original hash, no regressions, source extents,
progress exports, 26 tests and twenty native-link override audits pass.

The `refined-callback-bindings-v3` checkpoint reaches 1,383,076 verified code
bytes (53.036611%) and 6,245 functions. It adds nine native Python factories,
a typed Handle-copy binding, one callback constructor, the TRK dispatcher
initializer and independent owner/resource updates: 6,512 new code bytes across
34 functions. Eight existing constructor bodies receive native C++ identities
while preserving all 1,184 owned code and exception/index bytes. Complete
source-history proofs cover 53 consumer objects; thirteen refinement guard
tests and ten identifier-migration guard tests pass. The original hash, no
regressions, source extents, progress exports, 26 repository tests and twenty-one
native-link override audits pass.

The `record-owner-updates` checkpoint reaches 1,385,556 verified code bytes
(53.131711%) and 6,256 functions. Three native record/string constructors and
eight independent owner callbacks add 2,480 exact code bytes and 552 owned
exception/index bytes. The complete nested Record body independently confirms
its 0x3B5C stride. One initial factory extends the unchanged-byte identifier
migration chain. The original hash, no regressions, source extents, progress,
26 repository tests and twenty-one native-link override audits pass.

The `handle-menu-controls` checkpoint reaches 1,388,640 verified code bytes
(53.249972%) and 6,266 functions. A native Python Handle allocation binding,
three Record Handle controls, the menu resource loader and five owner control
callbacks add 3,084 exact code bytes and 328 owned exception/index bytes. Four
nonsemantic exception padding bytes use supported DTK cleanup with independent
raw/clean instruction, semantic-field, symbol, actual-relocation and compiler
category audits; twelve rejection/acceptance guard tests pass. A source-only
backup type receives a unique pending-unit name without changing any allocated
bytes or retained targets. The original hash, no regressions, source extents,
progress, 26 repository tests and twenty-five unchanged native-link discard
audits pass.

The `record-menu-bindings` checkpoint reaches 1,397,332 verified code bytes
(53.583283%) and 6,307 functions. Forty-one new functions add 8,692 exact code
bytes and 750 owned data/exception/index bytes: Record lifecycle and operations,
menu parsing and selection, nine Python pointer wrappers and owner callbacks.
The parser owns its complete 50-byte compiler literal contribution; the final
two original padding bytes remain external and uncredited with explicit original
alignment. The original hash, no regressions, source extents, progress exports,
26 repository tests, twenty-five native-link discard audits and the existing
supported compiler-padding audit pass.

The `record-state-menu-transitions` checkpoint reaches 1,403,580 verified code
bytes (53.822874%) and 6,337 functions. Thirty new source units add 6,248 exact
code bytes and 520 owned exception/index bytes: the singleton Python pointer
binding, nineteen Record data/state operations, menu transitions and Record
switching, and independent owner basis/resource/target callbacks. The original
hash, no regressions, source extents, progress exports, 26 repository tests,
twenty-five native-link discard audits and the existing supported compiler
padding audit pass.

The `record-dispatch-owner-controls` checkpoint reaches 1,407,696 verified
code bytes (53.980710%) and 6,347 functions. Ten functions add 4,116 exact code
bytes, 160 exception/index bytes and 124 original compiler-generated jump-table
bytes. The source includes Record action/countdown/member-pointer dispatch,
owner key lookup, menu selection and owner acceleration/motion controls. Every
real table relocation retains its original bounded target. The original hash,
no regressions, source extents, progress exports, 26 repository tests,
twenty-five native-link discard audits and the existing supported compiler
padding audit pass.

The `owner-record-color-updates` checkpoint reaches 1,409,988 verified code
bytes (54.068601%) and 6,357 functions. Ten functions across nine source units
add 2,292 exact code bytes and 192 owned exception/index bytes: native Record
Handle notifications, three menu state wrappers, four owner motion steps and
the cached render-color update. Existing strong native destructors retain all
live code and exception references; their compiler backups receive no credit.
The original hash, no regressions, source extents, progress exports, 26
repository tests, twenty-seven native-link discard audits and the existing
supported compiler-padding audit pass.

The `scene-callback-factories` checkpoint reaches 1,421,288 verified code bytes
(54.501920%) and 6,379 functions. Twenty-two source units add 11,300 exact code
bytes and 940 owned exception/index bytes: fifteen native Record scene
operations, five callback factories, contact-event dispatch and late callback
readiness. Every original callable-table reference remains accounted for,
including the cleanup entry with two original references. Compiler-generated
native backups receive no credit and existing strong owners remain selected.
The original hash, no regressions, source extents, progress exports, 26
repository tests, forty-two native-link discard audits and the existing
supported compiler-padding audit pass.

The `record-early-callbacks` checkpoint reaches 1,430,568 of 2,607,776 verified code bytes (54.857779%) and 6,414 of 8,803 functions. It adds 35 functions across record state updates and scene variants, early callback factories/controllers and owner callback arrays, a display-list wrapper, and audio voice shutdown. All original exception/startup references and emitted allocations are accounted for; 47 native helper selection/discard audits and the supported padding audit pass. The production DOL retains the original SHA1, `ninja changes` reports no regressions, and all 26 repository tests pass.

The `python-audio-branch` checkpoint reaches 1,435,548 of 2,607,776 verified code bytes (55.048747%) and 6,432 of 8,803 functions. It adds 15 early Python event wrappers, two audio array routines, and recursive owner dirty propagation. A separately adopted text-branch gate checks nine actual REL24 bindings to eight already matching strong helpers, with complete source/object/backup inventories and 21 rejection/fixture tests; the existing ELF/EH core and original frozen handoff remain unchanged. The full native map gate selects all eight strong owners and discards all eight weak copies without credit. All 48 native source audits, the supported padding audit, original DOL SHA1, no-regression check, and 26 repository tests pass.

The dispatch/control/bounds checkpoint verifies 1,449,840 / 2,607,776 code bytes (55.596800%) and 6,467 / 8,803 functions. It adds 35 functions and 14,292 code bytes: record callback dispatchers, early owner/controller/distance/handle operations, record construction/vector copy/bounds reduction, platform and audio destruction, and platform state transfer. Three dispatch units also recover 180 genuine member-pointer metadata bytes beside their compiler switch tables, preserving original eight-byte section placement. Original registry first-record identities remain unchanged; supported native FORCEACTIVE retains the borrowed-base record tails, and a repeating map/ELF gate proves their exact placement. The original full DOL SHA-1, baseline regression, source extents, generated progress, 48 complete native weak-override audits, supported exception cleanup and all 26 repository tests pass. Private near matches remain uncredited.

The `callback-setup-resource` checkpoint reaches 1,457,408 of 2,607,776 verified code bytes (55.887009%) and 6,480 of 8,803 functions. Thirteen functions add 7,568 exact code bytes: callback setup/operations, early resource controls/setup/lookup binding and owner spatial application. A separate native-only gate accounts for three unreferenced weak Handle backups while preserving the existing strict ELF/EH verifier and its retained-reference authorization. The gate repeats exact strong-source ownership and rejects retained references by name, symbol index, aliases or section-relative targets; 150 independent guard tests pass. All 52 complete native selection/discard audits, original full DOL SHA1, baseline regression, source extents, generated progress, supported exception padding and 26 repository tests pass.

The `dispatch-controller-owner` checkpoint reaches 1,478,008 of 2,607,776 verified code bytes (56.676954%) and 6,518 of 8,803 functions. Thirty-eight source functions add 20,600 exact code bytes: twenty-one callback dispatch variants/actions, fourteen early controller/actor/owner operations, sphere collection and two small owner/curve loops. Ten dispatch source units also recover 600 genuine original member-pointer record bytes. The repeating native map/ELF gate proves all ten retained source owners at their original addresses and preserves the original first-record identities; no object payload is rewritten. The complete original DOL SHA1, baseline regression, source extents, generated progress, 52 native weak-override audits, all thirteen pool ownership cases, supported exception cleanup and all 26 repository tests pass.

The `handle-platform-transform` checkpoint reaches 1,482,048 of 2,607,776 verified code bytes (56.831875%) and 6,526 of 8,803 functions. Eight functions add 4,040 exact code bytes: two callback Handle dispatchers, three owner operation controls, platform curve application/action reset and recursive owner transform update. A separately frozen bounded adapter admits only a complete 28-byte, eight-byte-aligned local switch table with seven actual ADDR32 references to its primary function; all previous ELF/EH core checks and files remain unchanged. All 62 adapter guards pass. The full original DOL SHA1, baseline regression, source extents, generated progress, 54 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `handle-controller-events` checkpoint reaches 1,486,744 of 2,607,776 verified code bytes (57.011952%) and 6,534 of 8,803 functions. Eight functions add 4,696 exact code bytes: callback Handle event dispatch, early owner pointer/flag operations and agent operation binding. Three new source-specific opt-ins reuse the unchanged seven-entry table adapter; 27 additional source/hash/section/owner guard fixtures pass. Independent source declarations retain copied Handle lifetimes and the observed16-bit mask. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `resolved-profile-platform` checkpoint reaches 1,493,332 of 2,607,776 verified code bytes (57.264581%) and 6,542 of 8,803 functions. Eight functions add 6,588 exact code bytes: two resolved callback Handle chains, four agent profile bindings, owner readiness and buffered platform reading. Original switch tables and genuine temporary Handle exception metadata are owned in full. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `record-phase-viewport` checkpoint reaches 1,495,216 of 2,607,776 verified code bytes (57.336826%) and 6,548 of 8,803 functions. Six functions add 1,884 exact code bytes: three record-completion operations, two transform-phase updates and viewport layout. The viewport owns its original eight-byte compiler conversion constant; repeated original-code/pointer/source audits prove exclusive ownership, with the preceding alignment gap retained externally. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `camera-control-completion` checkpoint reaches 1,496,716 of 2,607,776 verified code bytes (57.394347%) and 6,557 of 8,803 functions. Nine functions add 1,500 exact code bytes: five observer/virtual callback controls, three camera state operations and platform owner completion. The completion routine preserves its genuine three-layer zero Handle temporary and the existing transfer callee's two arguments; three unused weak destructors are inventoried and absent from the native link without credit. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `camera-query-completion` checkpoint reaches 1,498,392 of 2,607,776 verified code bytes (57.458616%) and 6,566 of 8,803 functions. Nine functions add 1,676 exact code bytes: four callback control completions, two camera queries and three camera target/smoothing gates. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `control-context-motion` checkpoint reaches 1,500,636 of 2,607,776 verified code bytes (57.544666%) and 6,583 of 8,803 functions. Seventeen functions add 2,244 exact code bytes: six callback state controls, three early context startup/transform operations, four component calls and four motion/flag updates. The motion update preserves the original base callee result, and all original exception/startup references remain accounted for. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `actor-registration-controls` checkpoint reaches 1,502,416 of 2,607,776 verified code bytes (57.612924%) and 6,591 of 8,803 functions. Eight functions add 1,780 exact code bytes: six early actor event controls and two callback registration queries. The actor flag and Handle checks preserve their original signed-byte/unsigned-pointer behavior, with complete owned exception metadata. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `action-phase-controls` checkpoint reaches 1,504,096 of 2,607,776 verified code bytes (57.677347%) and 6,617 of 8,803 functions. Twenty-six functions add 1,680 exact code bytes: twenty-one action/component controls and five actor phase methods. Native virtual calls, individual floating-component copies, 64-bit flag operations and double phase deltas preserve all original code and exception records. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `motion-forwarding-events` checkpoint reaches 1,506,348 of 2,607,776 verified code bytes (57.763704%) and 6,648 of 8,803 functions. Thirty-one functions add 2,252 exact code bytes: twenty-five motion forwarding/reset entries and six actor motion/event operations. Forwarding declarations preserve floating deltas, vector parameters and callback values; the motion routines preserve their original local vector copies and snapshots. The full original DOL SHA1, baseline regression, source extents, generated progress, 57 native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `registration-owner-lifetimes` checkpoint reaches 1,511,384 of 2,607,776 verified code bytes (57.956818%) and 6,657 of 8,803 functions. Nine functions add 5,036 exact code bytes: seven callback registrations and two owner/list destructors. A source-bound outer routing layer preserves every existing verifier and native-orchestrator file unchanged, independently rechecks the accepted aggregate Agent owner, and adds ContainerBase only to a deep-copied native discard proposal after proving no retained references. All 371 native ownership guard cases and six root routing tests, including 140 frozen-field mutations, pass. The seven startup objects discard 5,460 backup text bytes and 1,092 backup metadata bytes without credit. The full original DOL SHA1, baseline regression, source extents, generated progress, 64 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `input-factory-lists` checkpoint reaches 1,514,972 of 2,607,776 verified code bytes (58.094407%) and 6,666 of 8,803 functions. Nine functions add 3,588 exact code bytes: six actor input controls, two game/spatial list destructors and an action allocation/binding routine. Ordinary nested array and Handle destruction reproduces the original repeated null checks, cleanup loops and return values; all original dependencies and borrowed data keep their native owners. The full original DOL SHA1, baseline regression, source extents, generated progress, 64 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `motion-controller-notifications` checkpoint reaches 1,517,272 of 2,607,776 verified code bytes (58.182605%) and 6,682 of 8,803 functions. Sixteen functions add 2,300 exact code bytes: three controller events, eleven resolved Handle events and two callback setup/notification routines. Complete temporary Handle exception records and original event masks retain their native semantics; the unused weak Handle backup is discarded without credit. The full original DOL SHA1, baseline regression, source extents, generated progress, 65 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `scoped-controller-shutdown` checkpoint reaches 1,519,588 of 2,607,776 verified code bytes (58.271416%) and 6,685 of 8,803 functions. Three functions add 2,316 exact code bytes: callback Handle followup, actor scoped Handle update and controller shutdown. Ordinary four-Handle array ownership, layered deletion and scoped exception cleanup reproduce the complete original allocations and relocations. The full original DOL SHA1, baseline regression, source extents, generated progress, 66 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `registry-array-bitmap-state` checkpoint reaches 1,522,948 of 2,607,776 verified code bytes (58.400261%) and 6,696 of 8,803 functions. Eleven functions add 3,360 exact code bytes: spatial registry destruction, native Array copy construction, bitmap conversion and eight actor state transitions. The converter owns its complete original 56-byte switch table; an independent scan of 5,494 active original ELFs and initialized original words proves its two exclusive instruction references and no external pointer words. The constructor adopts its genuine native identity at the same address after a complete source/assembly consumer audit proves thirteen calls in twelve assembly units and no existing source consumers. The full original DOL SHA1, baseline regression, source extents, generated progress, 67 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `actor-motion-scalar-completion` checkpoint reaches 1,525,328 of 2,607,776 verified code bytes (58.491527%) and 6,714 of 8,803 functions. Eighteen functions add 2,380 exact code bytes: ten actor completion/reset operations, two scalar/record queries and six motion callback controls. Native float deltas, signed-byte64-bit flag normalization and typed Actor reset methods preserve the original lifetimes and pointer reuse. External callback/type records retain their original owners. The full original DOL SHA1, baseline regression, source extents, generated progress, 67 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `scene-setup-callback-family` checkpoint reaches 1,535,688 of 2,607,776 verified code bytes (58.888800%) and 6,760 of 8,803 functions. Forty-six functions add 10,360 exact code bytes: fourteen scene resource/scalar setup routines and thirty-two callback forwarding/query controls. Every routine owns its complete original exception metadata, while callback/type records and all borrowed constants keep their original owners. The full original DOL SHA1, baseline regression, source extents, generated progress, 67 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `scene-resource-array-resize` checkpoint reaches 1,539,464 of 2,607,776 verified code bytes (59.033598%) and 6,763 of 8,803 functions. Three functions add 3,776 exact code bytes: scene resource setup and two dynamic-array resize routines. Typed nested Handle and element lifetimes preserve every original loop and relocation; all unused weak destructor allocations remain uncredited. The full original DOL SHA1, baseline regression, source extents, generated progress, 68 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `actor-scene-effect-controls` checkpoint reaches 1,544,728 of 2,607,776 verified code bytes (59.235456%) and 6,781 of 8,803 functions. Eighteen functions add 5,264 exact code bytes: three scene effect/selection routines, five actor callback controls and ten scene leaf controls. Two source-bound native-only gates independently prove unreferenced Handle20834 backups without broadening retained exception authorization. All 124 agent guard tests and four root routing tests, including 82 field/pin rejection cases, pass. The full original DOL SHA1, baseline regression, source extents, generated progress, 71 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `scene-property-timed-reset` checkpoint reaches 1,549,484 of 2,607,776 verified code bytes (59.417833%) and 6,808 of 8,803 functions. Twenty-seven functions add 4,756 exact code bytes: six actor scene controls, three timed callbacks, motion owner reset and seventeen scene/Python property controls. Native float/double deltas, linked getter/setter callbacks, inherited calls and ordinary Handle/array cleanup preserve complete original allocations and relocations. The full original DOL SHA1, baseline regression, source extents, generated progress, 71 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

The `scene-constructor-record-events` checkpoint reaches 1,551,968 of 2,607,776 verified code bytes (59.513087%) and 6,822 of 8,803 functions. Fourteen functions add 2,484 exact code bytes: scene construction, five scene record controls, three actor event forwards and five scene callbacks. The constructor owns its exclusive original eight-byte conversion literal after independent complete active ELF, initialized-word and overlap audits; the original global literal becomes compiler-local without aliases or consumer changes. One event forward uses the documented native compiler noprop option to preserve its original default-selector test. The full original DOL SHA1, baseline regression, source extents, generated progress, 71 complete native selection/discard audits, thirteen original pool-owner audits, supported exception cleanup and all 26 repository tests pass.

- Continuation `early-event-vector-search`: five verified functions add 1,784 code bytes and 100 EH/index bytes. Matching source now covers 1,553,752 / 2,607,776 code bytes (59.581498%), 6,827 / 8,803 functions. Full original DOL hash, source extents, baseline regressions, all 71 native weak-discard source audits, full denominator and all 26 repository tests passed. See the early-event-flags and vector-search unit notes. The private message allocator remains uncredited because its string-pool base has an additional original consumer.

- Continuation `actor-message-record-controls`: five verified functions add 848 code bytes and 80 EH/index bytes. Matching source now covers 1,554,600 / 2,607,776 code bytes (59.614016%), 6,832 / 8,803 functions. Original DOL hash, source extents, baseline regressions, all 71 native weak-discard source audits, full denominator and all 26 repository tests passed. Scene message initialization/key lookup and actor jump/reflection controls remain documented as partial original translation units.

- Continuation `name-pointer-actor-flags`: six verified functions add 3,548 code bytes and 231 owned data/EH bytes. Matching source now covers 1,558,148 / 2,607,776 code bytes (59.750071%), 6,838 / 8,803 functions. The two input parsers own 143 bytes of natural string literals and the complete eight-byte bias, with the one-byte trailing original padding explicitly aligned to 1 and uncredited. A source-bound outer adapter checks the exact native Name constructor pointer pair, fresh accepted strong owner and all five discarded weak allocations; every existing verifier/adoption remains unchanged. Original DOL hash, no regressions, extents, all 71 prior native source audits, complete target Name-pointer native proof, 21 agent guards, 3 root routing tests and all 26 repository tests passed.

The `scene-handle-lookup-motion` checkpoint reaches 1,560,620 of 2,607,776 verified code bytes (59.844864%) and 6,845 of 8,803 functions. Seven functions add 2,472 exact code bytes and 332 owned exception/index bytes: three lookup binders, indexed record dispatch, related motion forwarding, scene Handle creation and collection. A source-bound collector adapter verifies the exact legacy aggregate Array owner by fresh compilation and strict bytes/relocations; every previous verifier and native-link gate remains unchanged. All 9 agent guards, including 78 negative cases, and 4 root routing tests pass. The original full DOL SHA1, no regressions, source extents, generated progress, 74 native source selection/discard audits, the complete Name-pointer proof and all 26 repository tests pass.

The `actor-handle-argument-controls` checkpoint reaches 1,562,456 of 2,607,776 verified code bytes (59.915269%) and 6,859 of 8,803 functions. Fourteen functions add 1,836 exact code bytes and 280 owned exception/index bytes: five early Handle commands, six actor/index operations and three scene argument parsers. All are complete allocated-byte matches with actual relocations, original identities and full exception/startup table ownership. The original full DOL SHA1, no regressions, source extents, generated progress, 74 native source audits, the complete Name-pointer proof and all 26 repository tests pass.

The `motion-collect-mode-controls` checkpoint reaches 1,565,200 of 2,607,776 verified code bytes (60.020493%) and 6,872 of 8,803 functions. Thirteen functions add 2,744 exact code bytes and 240 owned exception/index bytes: eleven early event operations, motion/contact collection and scene mode selection. Direct consumption of the genuine hidden-return typed Handle preserves its original temporary lifetime without an extra slicing copy. The original full DOL SHA1, no regressions, source extents, generated progress, 75 native source selection/discard audits, the complete Name-pointer proof and all 26 repository tests pass. Private one-word near matches remain uncredited.

The `nested-state-record-dispatch-unique` checkpoint reaches 1,567,536 of 2,607,776 verified code bytes (60.110071%) and 6,880 of 8,803 functions. Eight functions add 2,336 exact code bytes and 232 owned exception/index bytes: five nested state controls, scene argument action and two scene record operations. Distinct private zero-layer names preserve independent native UNUSED evidence for both new record inputs; the rejected shared-name attempt is preserved, and all verifier/native gate files remain unchanged. The original full DOL SHA1, no regressions, source extents, generated progress, 77 native source selection/discard audits, the complete Name-pointer proof and all 26 repository tests pass.

The `spatial-argument-timed-record` checkpoint reaches 1,569,780 of 2,607,776 verified code bytes (60.196121%) and 6,887 of 8,803 functions. Seven functions add 2,244 exact code bytes and 208 owned exception/index bytes: four spatial/state controls, two scene argument lifetime operations and a timed scene record. Original identities, complete original exception/startup ownership and actual relocations are preserved. The original full DOL SHA1, no regressions, source extents, generated progress, 80 native source selection/discard audits, the complete Name-pointer proof and all 26 repository tests pass.

The `selection-position-registry-controls` checkpoint reaches 1,576,964 of 2,607,776 verified code bytes (60.471605%) and 6,917 of 8,803 functions. Thirty functions add 7,184 exact code bytes and 620 owned exception/index bytes: selection/event and actor position controls, related records, scene argument setup, registry and Handle queries, effect motion selection, owner flags and record streaming. Typed manager reloads recover both preserved position-copy routines; direct hidden-return Handle consumption preserves both effect selection lifetimes. The original full DOL SHA1, no regressions, source extents, generated progress, 85 native source selection/discard audits, the complete Name-pointer proof and all 26 repository tests pass.

The `startup-dispatch-child-reset` checkpoint reaches 1,579,316 of 2,607,776 verified code bytes (60.561797%) and 6,928 of 8,803 functions. Eleven functions add 2,352 exact code bytes and 200 owned exception/index bytes: three early actor/record operations, scene-layer startup, scene-agent startup, five Agent setup sequences and owner child reset. Ordinary inline lifetimes recover both temporary stack positions and all original cleanup arguments; unused layer/Handle destructor allocations remain uncredited. The original full DOL SHA1, no regressions, source extents, generated progress, 86 native source selection/discard audits, the complete Name-pointer proof and all 26 repository tests pass.

The `motion-enum-container-startup` checkpoint reaches 1,580,960 of 2,607,776 verified code bytes (60.624839%) and 6,936 of 8,803 functions. Eight functions add 1,644 exact code bytes and 136 owned data/exception bytes: two motion controls, two scene setup operations, two enum maps and two library container startups. Native FORCEACTIVE preserves the original unreferenced enum functions and their complete56-byte switch-table pair; a frozen repeating native audit checks actual placement, fresh production-object equality and the original full DOL. The failed discarded-function build is preserved. Native speed optimization and exceptions-disabled settings recover both container startups, with existing strong destructor ownership preserved and unused backups uncredited. All previous verifier/gate files remain unchanged; the original full DOL SHA1, no regressions, source extents, generated progress, 86 native weak source audits, complete Name-pointer and enum retention proofs, two new guards including10 rejection cases, and all26 repository tests pass.

- Continuation checkpoint `record-service-masked-lists`: accepted 56 functions in 56 source units, adding 8,744 code bytes and 1,116 exception metadata bytes. Original normalized DOL SHA1, baseline regression comparison, complete allocated extents and relocations, native retention/discard audits, generated progress and all 26 repository tests pass. Matching source now covers 1,589,704 / 2,607,776 code bytes (60.960144%) and 6,992 / 8,803 functions.

- Continuation checkpoint `token-callback-owner-controls`: accepted 21 functions in 21 source units, adding 5,684 code bytes and 648 exception metadata bytes. The original normalized DOL SHA1, baseline regression comparison, complete allocated extents and relocations, native retention/discard audits, generated progress and all 26 repository tests pass. Matching source now covers 1,595,388 / 2,607,776 code bytes (61.178107%) and 7,013 / 8,803 functions.

- Continuation checkpoint `screen-vector-property-controls`: accepted eight functions in eight source units, adding 2,696 code bytes and 252 exception metadata bytes. The original normalized DOL SHA1, baseline regression comparison, complete allocated extents and relocations, native retention/discard audits, generated progress and all 26 repository tests pass. Matching source now covers 1,598,084 / 2,607,776 code bytes (61.281490%) and 7,021 / 8,803 functions.

- Accepted `screen-token-clone-selection`: 16 functions, 5,276 matching code bytes and 556 original exception/data bytes. The original DOL hash, unchanged baseline, strict allocation/relocation/extent and native-discard checks, generated progress verification and all 26 tests pass. Global matching code is 61.483808%.

- Accepted `native-binding-record-registration`: 7 functions, 1,776 matching code bytes and 172 original exception/data bytes. The original DOL hash, unchanged baseline, strict allocation/relocation/extent and native-discard checks, generated progress verification and all 26 tests pass. Global matching code is 61.551912%.

- Accepted `controller-legacy-slot-controls`: five functions add 1,860 matching code bytes and 200 original exception/index bytes. The original DOL hash, unchanged baseline, strict allocation/relocation/extent checks, 97 native selection/discard source audits, generated progress and all 26 tests pass. Matching source now covers 1,606,996 / 2,607,776 code bytes (61.623238%) and 7,049 / 8,803 functions.

- Accepted `matrix-controller-state-controls`: six functions add 4,772 matching code bytes and 100 original exception/index bytes. The132-byte Matrix assignment owner was replaced with a verified native C++ operator at zero additional credit. Full original DOL hash, unchanged baseline, strict actual relocations/extents,99 native selection/discard source audits, generated progress and all26 tests pass. Matching source now covers 1,611,768 / 2,607,776 code bytes (61.806229%) and 7,055 / 8,803 functions.

- Accepted `stream-sphere-offset-controls`: ten functions add 2,200 matching code bytes and80 original exception/index bytes. Stream record/scalar/block helpers, two sphere return routines, capacity/module removal, actor offset completion and menu activation pass the original hash, baseline, allocation/relocation/extents,99 native source audits, progress and26 tests. Matching source now covers 1,613,968 / 2,607,776 code bytes (61.890592%) and 7,065 / 8,803 functions.

- Accepted `message-literal-pool-loader`: one function adds536 matching code bytes,88 original exception/index bytes and54 original compiler literal/alignment bytes. The original2-byte tail remains in an explicit align2 assembly split with no source credit. A fresh complete active-input consumer audit proves pool exclusivity; original-placement native checks retain all literals/tail/neighbor and discard all6 backups. Original DOL hash, baseline, extents,100 native source audits, progress and26 tests pass. Matching source now covers 1,614,504 / 2,607,776 code bytes (61.911146%) and 7,066 / 8,803 functions.

- Accepted `native-record-construction-events`: two functions add 712 matching code bytes and 120 original exception/index bytes. The native428-byte Record constructor replaces its provisional identity after ten concrete byte/relocation-identical source consumer migrations; the event routine uses the independently verified legacy aggregate destructor. Full original DOL hash, unchanged baseline, strict allocations/extents/actual relocations,102 native source audits, native constructor/event and all prior literal/enum/pointer checks, generated progress and26 tests pass. Matching source now covers1,615,216 /2,607,776 code bytes (61.938449%) and7,068 /8,803 functions.

- Accepted `group-grid-record-resize`: three functions add2,316 matching code bytes,72 original exception/index bytes and66 original literal/alignment bytes. The parser adopts its exclusive literal pool after a fresh complete active-input audit; an explicit original align2 tail remains NonMatching with zero credit. Full original DOL hash, unchanged baseline, strict allocated bytes/extents/all actual relocations,104 native source audits, dual complete-ELF literal/tail/neighbor checks, all prior enum/pointer/constructor proofs, generated progress and26 tests pass. Matching source now covers1,617,532 /2,607,776 code bytes (62.027260%) and7,071 /8,803 functions.

- Accepted `pool-owner-selection-assignment`: two functions add704 matching code bytes and84 original exception/index bytes. The native492-byte pool-owner constructor preserves both external vtable identities and uses a concrete unused-header migration across three byte/relocation-identical accepted objects. Its local exception symbol name is excluded from external dependency promotion by exact ELF section/index evidence. The212-byte resolved-owner assignment reuses verified Handle/Name declarations unchanged. Full original DOL hash, unchanged baseline, strict allocations/extents/actual relocations,104 native source audits, dual complete-ELF constructor/vtable/pool checks, all prior proofs, generated progress and26 tests pass. Matching source now covers1,618,236 /2,607,776 code bytes (62.054256%) and7,073 /8,803 functions.

- Accepted `token-record-array-dispatch`: five functions add 3,052 matching code bytes and 152 original exception/index bytes. Resource-token masking780, text-record formatting648, actor-flag gating924, token-selection stop160, and record-array dispatch540 retain original C identities and external pools/tables. The new source-specific legacy Array destructor gate preserves every earlier route; dual complete native links prove three original strong owners and all18 backup allocations discarded. Original DOL hash, baseline, strict bytes/extents/actual relocations,105 native weak source audits, all earlier pool/native constructor/enum checks, generated progress and26 tests pass. Coverage is1,621,288 /2,607,776 code bytes (62.171291%) and7,078 /8,803 functions.

- Accepted `node-settings-short-values`: four functions add1,712 matching code bytes and76 original exception/index bytes. Node cleanup1,144 retains complete original Handle lifetime behavior and excludes352 unused weak bytes; default record settings424 uses the independently recompiled original strong Handle destructor. Virtual short addition92 and assignment52 preserve existing Python callers and emit no helpers. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations,106 native weak source audits and all prior literal/enum/native constructor checks, generated progress and26 tests pass. Coverage is1,623,000 /2,607,776 code bytes (62.236941%) and7,082 /8,803 functions. An initial mistyped object target failed before promotion; the preserved retry uses the real production target and every acceptance check passed.

- Accepted `activation-token-handle-setup`: four functions add2,768 matching code bytes and116 original exception/index bytes. Resource Handle cloning1,388, record activation468, token-selection start396 and scene-record setup516 preserve original C entry points and external tables/pools. The new exact-source legacy Record gate requires the existing real native constructor428 and strong destructor176 in both complete links; source backups and metadata remain uncredited. Original DOL hash, baseline, strict bytes/extents/actual relocations,108 native weak source audits, all preceding literal/enum/native pool constructor checks, generated progress and26 tests pass. Coverage is1,625,768 /2,607,776 code bytes (62.343085%) and7,086 /8,803 functions.

- Accepted `typed-scene-handle-setup`: one function adds420 matching code bytes and212 original exception/index bytes. Native initialization and copy layers retain the original420-byte body and200-byte action table. Five accepted strong Handle owners are independently recompiled; all24 unused backup allocations remain uncredited. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations,109 native weak source audits, every preceding native constructor/literal/enum proof, generated progress and26 tests pass. Coverage is1,626,188 /2,607,776 code bytes (62.359190%) and7,087 /8,803 functions.

- Accepted `nullable-owner-interpolation`: four functions add1,476 matching code bytes and40 original exception/index bytes. Nullable Handle forwarding204 and paired forwarding672 retain full-expression cleanup; owner-slot teardown492 preserves sentinel and64-bit flag controls; vector interpolation108 uses an ordinary copied division result to preserve its intermediate stack stores. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, all109 native weak source audits and earlier native/literal/enum proofs, generated progress and26 tests pass. Coverage is1,627,664 /2,607,776 code bytes (62.415790%) and7,091 /8,803 functions.

- `scene-array-handle-controls`: accepted14 functions,8,356 text bytes and276 EH/index bytes. Matching source now covers1,636,020/2,607,776code bytes (62.736217%) and7,105/8,803functions. The original DOL hash, baseline regression check, strict extents/real relocations, generated progress and26tests pass. All prior native ownership/weak/enum/pool proofs remain required. The272-byte Python bytecode text-only candidate is deferred withzero credit because DTK requires the exception index and function to share a split; all original bytes remain assembly-owned.

- `resource-controls-forwarders`: accepted24 functions,4,776 text bytes and460 owned EH/index bytes, including18 thin typed forwarding entries, resource parent binding, record startup, effect activation, checked actor events and screen Handle registration. Matching source covers1,640,796/2,607,776code bytes (62.919361%) and7,129/8,803functions. Original DOL hash, baseline regression, exact allocated extents/actual relocations, generated progress,26tests and all115 native weak-source audits/prior owner proofs pass. The1064-byte event selector with its unaligned standalone switch table remains deferred pending genuine preceding-record ownership; no source credit is claimed for it.

- `selector-record-token-teardown`: accepted8 functions,9,312 text bytes and356 owned nontext bytes. Global callback teardown2308, token-kind dispatcher1452, single-record event684, actor resource setup848, resource selection736/slot insertion840 and selector pair1064/1380 pass the original DOL hash, unchanged baseline, exact allocations/extents/actual relocations, generated progress and26tests. Both selector units own genuine60-byte original callback arrays followed by28-byte compiler switch tables; exact original global data retention and placement pass in both full ELFs withzero synthetic padding. The exact single-event legacy Array gate retains the original220-byte strong destructor and discards all3 backup allocations; the root audit now correctly distinguishes26 total actual relocs from16 retained plus10 discarded, preserving the failed first check. All117 native weak-source audits and prior ownership/literal/enum proofs pass. Coverage is1,650,108/2,607,776code bytes (63.276447%) and7,137/8,803functions.

- `actor-factory-card-selectors`: accepted19 functions,12,952 code bytes and708 owned nontext bytes. Actor callback setup4248, owner setup1720, related slot selector1380/controller mode952/actor state1140, lazy Handle binding808, ten96-byte notification helpers, card sector preparation584/mount628/format532 retain original identities and external storage. The selector owns genuine60-byte callback records plus28-byte switch data with exact original GLOBAL retention in both full ELFs; the mount worker owns its exclusive56-byte switch table at natural8-byte alignment. Lazy binding uses four independently recompiled original strong Handle owners and discards18 backup allocations. Original DOL hash, unchanged baseline, strict allocated bytes/extents/actual relocations, generated progress,26tests and all118 native weak-source audits/prior native/literal/enum proofs pass. Coverage is1,663,060/2,607,776code bytes (63.773115%) and7,156/8,803functions.
- `console-constructor-card-controls`: accepted6 functions,2116 code bytes and140 owned exception/index bytes. Original console registration788, native multiple-inheritance constructor120, card texture registration792, two card controls148 and formatted scene command268 pass all strict source, original hash and baseline checks. The native constructor retains original base lifetime identities and92-byte primary/secondary vtable span in both full ELFs; its existing factory consumer has a preserved identifier-only migration with identical allocated bytes/extents and physical relocation targets. All26tests,119 native weak-source audits and prior ownership/literal/enum proofs pass. Coverage is1,665,176/2,607,776code bytes (63.854257%) and7,162/8,803functions.

- `scene-selector-pointer-conversion`: accepted3 functions,3404 code bytes and184 owned data/exception/index bytes. Scene selector1772 owns five genuine60-byte callback records and28-byte switch data; related event scaling772 preserves its original strong Handle owners and discards all backup allocations; Python pointer conversion860 preserves original cache storage, type lookup and reference cleanup. Original DOL hash, unchanged baseline, strict allocated bytes/extents/actual relocations, generated progress,26tests and all120 native weak-source audits/prior native ownership proofs pass. Coverage is1,668,580/2,607,776 code bytes (63.984790%) and7,165/8,803functions.

- `menu-actor-resource-modes`: accepted7functions,7036 code bytes and252 owned nontext bytes. Level/menu setup2828, native actor constructor196, four mesh controls168 and named resource modes3844 pass the original DOL hash, unchanged baseline, exact allocations/extents/actual relocations, generated progress and26tests. The constructor retains its original396-byte primary/secondary vtable and base lifetime identities after one concrete unchanged-byte factory migration. The source-bound two-table route retains both40-byte original tables at natural8-byte alignment, selects both original strong Handle destructors and discards all12 backup allocations in both full native links. All121 native weak-source audits and every earlier ownership/enum/pool proof pass; newrootguards2positive/69negative and independently repeated agentguards3positive/224negative pass. Coverage is1,675,616/2,607,776 code bytes (64.254599%) and7,172/8,803functions.

- `named-scene-handle-capacity`: accepted2functions,1480 code bytes and40 owned exception/index bytes. Named scene setup916 and Handle-array capacity564 retain original C identities and external storage; all unused helper allocations remain uncredited. Original DOL hash, unchanged baseline, strict allocated bytes/extents/actual relocations, generated progress,26tests and all123 native weak-source audits/prior native ownership proofs pass. Coverage is1,677,096/2,607,776 code bytes (64.311352%) and7,174/8,803functions.
- `resource-assignment-text-display`: accepted3functions,3212 code bytes and60 owned exception/index bytes. Resource target selection1348, Handle-array assignment536 and independent display-renderer dispatch1328 retain original identities and external pools; all unused helper allocations remain uncredited. Original DOL hash, unchanged baseline, strict allocated bytes/extents/actual relocations, generated progress,26tests and all124 native weak-source audits/prior native ownership proofs pass. Coverage is1,680,308/2,607,776 code bytes (64.434522%) and7,177/8,803functions.
- `actor-resource-mesh-transfer`: accepted2functions,1132 code bytes and20 owned exception/index bytes. Actor selected-resource setup792 and mesh pass transfer340 retain original C identities, external literal pools and external scratch storage. Ordinary typed owner views and named local lifetimes recover all original register/stack choices. Original DOL hash, unchanged baseline, strict allocated bytes/extents/actual relocations, generated progress,26tests and all124 native weak-source audits/prior native ownership proofs pass. Coverage is1,681,440/2,607,776 code bytes (64.477931%) and7,179/8,803functions.
- `scene-callback-renderer-rectangles`: accepted6functions,3256 code bytes and340 owned exception/index bytes. Scene member dispatch892, two callback/indexed controls288 and three renderer rectangle routines2076 preserve original identities and external pools. All unused Handle helpers remain uncredited. Original DOL hash, unchanged baseline, strict allocated bytes/extents/actual relocations, generated progress,26tests and all125 native weak-source audits/prior native ownership proofs pass. Coverage is1,684,696/2,607,776 code bytes (64.602788%) and7,185/8,803functions.

- `named-resource-registration`: accepted5 functions,3232 code bytes and676 owned exception/index bytes. Python resource registration468, lazy member lookup1024, named resource callback512 and named flag controls600/628 retain original C identities and external strings/storage. The exact two-source legacy Array route independently verifies the original strong240-byte destructor and discards all three backups per input in both full native ELFs. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress,26 tests and all129 native weak-source audits/prior ownership proofs pass. Fresh root guards9 positive/2410 negative, agent guards11 positive/2768 negative and independent root-route review pass. Coverage is1,687,928/2,607,776 code bytes (64.726725%) and7,190/8,803 functions.

- `mesh-scratch-startup`: accepted the genuine92-byte native LOCAL startup and its original4-byte constructor-table entry plus98,304 bytes of original NOBITS storage. Two ordinary4096-element Vector3 arrays preserve original GLOBAL buffer names, sizes, order and alignment. A narrowly frozen source verifier accounts for SHT_NOBITS explicitly using the unchanged ELF reader and original DOL BSS extent. Both complete native ELFs retain the exact startup identity/ctor word/49152-byte buffers without aliases or consumer edits. Original DOL hash, unchanged baseline, strict allocations/extents/all11 actual relocations, generated progress,26 tests and all129 native weak-source audits/prior ownership proofs pass; source/object mutation guards and independent review also pass. Coverage is1,688,020/2,607,776 code bytes (64.730253%) and7,191/8,803 functions.

- `record-scene-position-controls`: accepted3 functions,2644 code bytes and212 owned exception/index bytes. Record-type reset1236, scene resource transition808 and named actor position600 retain original C identities, external strings/records and native lifetime behavior. Cached const entry views recover the scene transition's original register allocation. The exact record-type source gate independently verifies all five original strong owners including legacy Array25634, and both full native links discard all24 backups. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress,26 tests and all132 native weak-source audits/prior ownership proofs pass. Root route guards8 positive/3965 negative, independent4328 negative mutations and repeated source guards16 positive/4947 negative pass. Compiler handoff notes pinned by native adoptions stay immutable; accepted status is recorded here and in the continuation report. Coverage is1,690,664/2,607,776 code bytes (64.831642%) and7,194/8,803 functions.

- `sphere-actor-handle-actions` adds three exact routines (2,216 code bytes and 76 exception metadata bytes): sphere record filtering, named actor targets and a Handle action sweep. Verified matching code is 1,692,880 / 2,607,776 bytes (64.916619%), with 7,197 / 8,803 functions; the original DOL hash, baseline regression checks, complete native audits and all 26 tests pass.

- `actor-height-sparse-action-owner` adds two exact routines (1,400 code bytes and 20 exception metadata bytes): actor height control and sparse action-owner destruction. Verified matching code is 1,694,280 / 2,607,776 bytes (64.970304%), with 7,199 / 8,803 functions; the original DOL hash, baseline regression checks, all 134 native weak-source audits and all 26 tests pass.

- `settings-owner-streams` adds nine exact routines (9,668 code bytes and 120 exception metadata bytes): settings snapshot, owner action setup, four selection/position callbacks and three stream readers. Verified matching code is 1,703,948 / 2,607,776 bytes (65.341042%), with 7,208 / 8,803 functions; the original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, all prior native ownership audits and all 26 tests pass. Frozen compiler handoff notes remain immutable; acceptance is recorded here and in the continuation report.

- `record-actor-scene-controls` adds four exact routines (3,636 code bytes and112 exception metadata bytes): record selection, damage-volume events, named actor state and scene transition controls. The original strong Handle owners remain at their verified addresses and all nine transition backup allocations are discarded. Verified matching code is 1,707,584 / 2,607,776 bytes (65.480471%), with 7,212 / 8,803 functions; the original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, all prior native ownership audits and all26 tests pass.

- `resource-motion-callback-selectors-v2` adds eight exact routines (6,200 code bytes and 200 table/exception bytes): resource event loops, position activation, motion query output and five callback selectors. Adjacent selector pairs naturally preserve the original 28-byte table layout and alignment; both unused resource-wrapper destructors and their metadata are discarded. Verified matching code is 1,713,784 / 2,607,776 bytes (65.718221%), with 7,220 / 8,803 functions; the original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, all prior native ownership audits and all 26 tests pass.

- `scene-mode-resource-events` adds two exact routines (1,708 code bytes and 252 exception metadata bytes): scene mode actions and resource event controls. Original strong Handle/Name owners remain at their verified addresses and all unused backup allocations are discarded. Verified matching code is 1,715,492 / 2,607,776 bytes (65.783718%), with 7,222 / 8,803 functions; the original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, all prior native ownership audits and all 26 tests pass.

- `motion-effects-handle-startup` adds five exact routines (3,616 code bytes and 284 exception metadata bytes): motion input update, named actor effect reset, named Handle lookup/create, GBA transfer polling and dynamic callback startup. Native strong owners and original C identities are preserved; unused backup allocations remain uncredited and are discarded. Verified matching code is 1,719,108 / 2,607,776 bytes (65.922380%), with 7,227 / 8,803 functions; the original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, all prior native ownership audits and all 26 tests pass.

- `resource-selection-scene-skin-startup` adds four exact routines (1,748 code bytes and 268 exception metadata bytes): resource selection controls, mirrored scene Handle activation/removal and skin callback startup. Original lifetime identities and strong owners are preserved; unused backups remain uncredited and are discarded. Verified matching code is 1,720,856 / 2,607,776 bytes (65.989410%), with 7,231 / 8,803 functions; the original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, all prior native ownership audits and all 26 tests pass.

- Verified `actor-record-pair-startup`: five ordinary routines add3,176 code bytes and360 owned EH/index bytes; pair selection560, actor group transition616, actor record reset800, mirrored record flags1,024 and callback startup176. Original DOL hash, baseline regressions, full source extents, generated progress,26 tests and148 native weak-source audits pass. Exact source-bound Array routes repeat original GLOBAL owners and all21 backup allocation discards in both native outputs. Current matching source: 1,724,032 /2,607,776 bytes (66.111200%), 7,236 /8,803 functions. Original unknown denominator preserved.

- Verified `record-switch-hierarchy`: ten routines add 5,468 code bytes, 264 genuine record/switch bytes and 444 exception/index bytes. Three exact source-bound selector routes preserve GLOBAL record identities, original LOCAL switches and the untouched shared record prefix; both full native outputs discard all 18 corresponding backup allocations. Hierarchy append, name/Handle assignment, native member activation and two actor Handle controls also match. Current matching source: 1,729,500 / 2,607,776 code bytes (66.320880%), 7,246 / 8,803 functions. Original DOL hash, baseline regressions, all source extents, generated progress, 26 tests and 153 native weak-source audits pass; the unknown denominator is preserved.

- Verified `actor-move-constructor`: native actor constructor adds 596 code bytes and 40 exception/index bytes. Its sole factory consumer changes only two identifier spellings; complete before/after allocated payloads and all 380 caller relocations remain identical. Both full native outputs retain the original constructor/base lifetime identities and unchanged 420-byte borrowed vtable. Matching source now covers 1,730,096 / 2,607,776 code bytes (66.343735%), 7,247 / 8,803 functions. Original hash, baseline regressions, extents, generated progress, all prior native ownership audits and 26 tests pass.

- Verified `related-actor-reset-controls`: adjacent actor disable and related actor reset routines add 2,216 exact code bytes and 312 exception/index bytes. The original table pointer to the reset entry is preserved, and both full native links select the three accepted strong Handle owners and discard all 18 backup allocations. Matching source now covers 1,732,312 / 2,607,776 code bytes (66.428712%) and 7,249 / 8,803 functions. Original DOL hash, unchanged baseline, source extents, generated progress, 155 native weak-source audits, all earlier native ownership checks and 26 tests pass.

- Verified `actor-controller-event-stream`: actor action selection, controller port updates, sparse actor event dispatch and vector/record array stream reading add 3,488 exact code bytes and 56 exception/index bytes. All four retain original identities and borrowed table/state regions; their emitted sections have no unused helpers. Matching source now covers 1,735,800 / 2,607,776 bytes (66.562465%) and 7,253 / 8,803 functions. Original hash, unchanged baseline, extents, generated progress, all 155 native weak-source audits, earlier ownership proofs and 26 tests pass.

- Verified `scene-camera-array-card`: six routines add 5,076 exact code bytes and 288 exception/index bytes: selected scene record, camera sphere query, float-record array copy, card-file reader, unique Handle append and record-array owner destruction. The exact two-source lifetime route selects nine original strong owners, including two legacy aggregate owners, and both complete native links discard all 30 corresponding backup allocations. Matching source now covers 1,740,876 / 2,607,776 code bytes (66.757114%) and 7,259 / 8,803 functions. Original hash, unchanged baseline, extents, generated progress, all 157 native weak-source audits, every earlier ownership proof and 26 tests pass; compiler handoffs and unknown denominator remain preserved.

- Verified `audio-owner-menu-stream`: four routines add 3,296 exact code bytes and 80 exception/index bytes: audio-owner initialization/mixer setup, menu-record parsing, and nested record-array destruction. The parser retains its two original strong Handle owners and both native links discard all nine backup allocations. Matching source now covers 1,744,172 / 2,607,776 code bytes (66.883505%) and 7,263 / 8,803 functions. Original hash, unchanged baseline, extents, generated progress, all 158 native weak-source audits, earlier ownership proofs and 26 tests pass; original tables, shared pools, source consumers and full denominator remain preserved.

- Verified `menu-player-audio-stream-arrays`: five routines add 8,436 exact code bytes and 56 exception/index bytes: menu-player binding, audio buffer transfer, scene named-mode switching, and two array stream readers. Original hash, unchanged baseline, allocated extents/actual relocations, progress and 26 tests pass. All 159 native weak-override source cases and earlier native ownership proofs pass. A supplemental dual-link proof also confirms exact placement of the four menu/player/stream/unique-append owners and discards all 15 unused weak allocations per link. Matching source covers 1,752,608 / 2,607,776 code bytes (67.206999%) and 7,268 / 8,803 functions; borrowed pools, tables, literals, consumer identities and full denominator remain preserved.

- Verified `scene-controller-owner-shutdown`: native controller construction364, scene-owner destruction652 and a sphere-record stream reader504 add1,520 exact code bytes and40 exception/index bytes. Eleven existing source consumers undergo identifier-only migration with all allocated bytes and actual targets unchanged. Both full native links preserve the native constructor/destructor identities, original Handle lifetimes,104/80-byte vtables and discard all15 previously audited unused helpers. Original DOL hash, unchanged baseline, extents, generated progress,26tests,159 weak-override source cases and every earlier ownership proof pass. Source now covers1,754,128/2,607,776 code bytes (67.265287%) and7,271/8,803 functions; original data and denominator remain preserved.

- Verified `named-resource-owner-sparse-arrays`: native named-resource construction440, resource-owner teardown2,344 and sparse Handle-array destruction848 add3,632 exact code bytes and184 exception/index bytes. Both native links retain the native constructor, original72-byte external table and strong Handle owners, with all6 constructor backup allocations discarded. Two existing source consumers change only identifiers; all allocations and actual targets stay identical. Original DOL hash, unchanged baseline, extents, generated progress,26 tests,160 native weak-source cases and every prior ownership proof pass. The final new outer audit required legacy manifest normalization using the existing normalizer; initial failure and successful supplemental proof are preserved. Source now covers1,757,760/2,607,776 code bytes (67.404562%) and7,274/8,803 functions; full original denominator remains preserved.

- Verified `loading-screen-vertex-incidence`: native loading-screen construction352 and mesh vertex incidence1,088 add1,440 exact code bytes and80 exception/index bytes. Two existing consumers change only identifiers with every allocation and target unchanged. Both complete native links preserve the C destructor and72-byte external vtable, discard all6 constructor backups and the unused208-byte mesh-array destructor. Original DOL hash, unchanged baseline, source extents, generated progress,26 tests,161 native weak-source cases and every prior ownership proof pass. Matching source covers1,759,200/2,607,776 code bytes (67.459782%) and7,276/8,803 functions; full original denominator remains preserved.

- Accepted `heap-texture-stream`: the heap allocator, texture stream reader and genuine TexturePayloadRecord constructor add 3,176 matching code bytes and a 56-byte compiler LOCAL switch table. Native constructor identity replaces its provisional spelling at the same 12-byte original extent; the original Bitmap vtable and borrowed literals remain exact. Full original DOL hash, no baseline regressions, strict allocations/extents/actual relocations, 161 native override source audits, every prior native proof, dual texture ownership proof, generated progress and 26 tests pass. Matching source now covers 1,762,376 / 2,607,776 code bytes (67.581571%) and 7,279 / 8,803 functions.

- Accepted `reticle-group-resets`: native reticle construction, resource group setup and twelve context reset routines add 3,864 matching code bytes, 63 genuine compiler LOCAL literal bytes and 360 exception/index bytes. A zero-credit Handle constructor refinement preserves every existing allocated byte and actual target. Both native links retain the original external vtable and strong Handle destructor, preserve the four internal literal alignment bytes and separate original trailing padding, and discard all three reticle backups. Original DOL hash, unchanged baseline, strict extents/actual relocations, generated progress, 26 tests, 162 native override source cases and all prior/new ownership proofs pass. Initial path-comparison failure and successful v2 supplemental acceptance are preserved. Matching source covers 1,766,240 / 2,607,776 code bytes (67.729744%) and 7,293 / 8,803 functions.

- Accepted `context-callback-guards`: 33 ordinary context callback/reset/guard routines add 2,484 exact code bytes and 660 exception/index bytes. Every original entry identity and external table owner is preserved; there are no extra helper allocations or new verifier routes. Original DOL hash, unchanged baseline, strict allocated extents/actual relocations, generated progress, 26 tests, all 162 native override cases and every earlier ownership proof pass. Matching source covers 1,768,724 / 2,607,776 code bytes (67.824997%) and 7,326 / 8,803 functions.

- Accepted `delegate-handle-resize`: 65 ordinary delegate/cleanup routines and nested Handle-record array resizing add 3,664 exact code bytes and 1,300 exception/index bytes. Both native links preserve the resize entry and discard its unused 212-byte weak array destructor. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress, 26 tests, 162 native override cases, all earlier ownership proofs and all 23 plain unused weak discards per link pass. Matching source covers 1,772,388 / 2,607,776 code bytes (67.965500%) and 7,392 / 8,803 functions.

- Accepted `vector-wrapped-handle-scalar`: context-derived vector output, wrapped Handle-array resizing and ten mode/scalar delegates add 1,532 exact code bytes and 220 exception/index bytes. Both native links preserve original identities and discard the two unused 88/84-byte array helpers. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress, 26 tests, all 162 native override cases, prior ownership proofs and all 25 plain unused weak allocations per link pass. Matching source covers 1,773,920 / 2,607,776 code bytes (68.024247%) and 7,404 / 8,803 functions.

- Accepted `virtual-control-sparse-insert`: fifteen ordinary virtual-control delegates and sparse slot insertion add 1,572 exact code bytes and 300 exception/index bytes. Original identities and external owners remain preserved, with no new helpers or verifier routes. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress, 26 tests, all 162 native override cases and every prior native ownership proof pass. Matching source covers 1,775,492 / 2,607,776 code bytes (68.084529%) and 7,420 / 8,803 functions.

- Accepted `motion-curve-setup`: scalar easing, fifteen ordinary setup/flag routines, curve stream/application wrappers and actor transform tracks add 3,036 exact code bytes and 320 exception/index bytes across 21 functions. Original C identities, borrowed constants and external table owners are preserved; no new helper allocations or verifier routes. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress, 26 tests, all 162 native override cases and every prior native ownership proof pass. Matching source covers 1,778,528 / 2,607,776 code bytes (68.200950%) and 7,441 / 8,803 functions.

- Accepted `control-platform-bound-curves`: fifteen control delegates, thirteen platform controls, two bounded-owner curve routines and actor launch/reset add 2,944 exact code bytes and 320 exception/index bytes across 31 functions. Original C identities, external owners and borrowed constants are preserved. The launch scalar view reproduces the observed single load without asserting an original volatile declaration. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress, 26 tests, all 162 native override cases and every prior native ownership proof pass. Matching source covers 1,781,472 / 2,607,776 code bytes (68.313843%) and 7,472 / 8,803 functions.

- Accepted `short-initializer-curve-actions`: thirty short controls, five original C-entry resource initializers, three curve/Handle encoders, sparse byte-record insertion and actor quaternion/action control add 3,556 exact code bytes and 620 exception/index bytes across 40 functions. Original entry/base/vtable identities and all external storage remain preserved; no new helpers or verifier routes. Explicit append-branch return closes the sparse insertion scheduling difference while all older probes remain preserved. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress, 26 tests, all 162 native override cases and every earlier ownership proof pass. Matching source covers 1,785,028 / 2,607,776 code bytes (68.450204%) and 7,512 / 8,803 functions.

- Accepted `logged-phase-projected-quad`: seventeen logger/timed delegates, fifteen actor phase delegates and projected-quad coarse rejection add 2,512 exact code bytes and 640 exception/index bytes across 33 functions. Original C entries, borrowed strings/constants and external table/storage owners are preserved. Three delegates retain original processor750 scalar-save conventions; all other per-unit flags remain frozen. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress, 26 tests, 162 native override cases and every earlier ownership proof pass. Matching source covers 1,787,540 / 2,607,776 code bytes (68.546532%) and 7,545 / 8,803 functions.

- Accepted `state-vector-render-controls-v2`: ten timer/reset controls, six scalar/query controls, two state/collision controls, scene-list destruction, object-list acquisition, four vector/controller/owner forwarding routines, render-index quicksort, six-buffer display-list setup and actor state transition add 4,296 exact code bytes and 380 exception/index bytes across 27 functions. The original20-routine checkpoint passed build checks but its final native audit rejected a missing per-input unused-helper map row. A new trivial partial Handle view and explicit original cleanup preserve all128 retained acquire bytes and four targets while removing the unused84-byte backup; the prior source/header/freeze and failure remain preserved, with zero extra credit. An initial registration wrapper rejected aligned split whitespace before changing files; the separately preserved v2 retry fixes only that structural parser. All established verifier routes and core gates remain unchanged. Original DOL hash, unchanged baseline, strict allocations/extents/actual relocations, generated progress, 26 tests, all162 native override cases, all25 plain unused allocations in both native links and every earlier ownership proof pass. Matching source covers1,791,836 /2,607,776 code bytes (68.711270%) and7,572 /8,803 functions.

## Motion, Reefblower constructor and face render checkpoint

Accepted four original routines, adding1,652 text bytes and60 EH/index bytes: two motion-vector updates580, the genuine Reefblower-derived native constructor132, and six-face render dispatch940. Both original constructor callers migrated identifiers with unchanged allocated bytes/targets. A separate zero-credit startup storage refinement expands the observed wrapper fromB0 to its factory-provedB8 capacity with identical code and12 actual relocations. The render compiler emits unique unused88/84-byte cleanup backups; the unchanged complete native map/discard gate proves every allocation discarded, with zero credit.

The full original DOL hash, baseline regression, source extent and generated progress checks, all26 tests and every prior source/native ownership audit pass. No verifier/core or denominator changes. Current matching code is1,793,488 /2,607,776 (68.774619%), covering7,576 /8,803 functions. Frozen producer notes and failed/unmatched probes remain preserved.


- Accepted `handle-event-time-dispatch-v2`: system actor Handle query388, timed actor event control576 and callback time dispatch828 add1,792 exact code bytes and140 owned EH/index bytes. The complete native map proves original strong-owner selection and discards every emitted backup without credit. The initial final audit rejected a missing canonical_manifest field after build/hash/tests passed; v2 adds only the required metadata path, preserving source, all allocated payloads/actual targets and the failed log. All established verifier/core gates remain unchanged. Original DOL hash, unchanged baseline, strict extents/actual relocations, generated progress,26 tests,164 native override cases and every earlier source/native ownership audit pass. Matching source covers1,795,280 /2,607,776 code bytes (68.843336%) and7,579 /8,803 functions; complete owned data is511,299 /1,030,936, while native matched data remains499,611. Full denominator and all frozen producer findings remain preserved.


- Accepted `audio-record-setup`: audio system startup620, stereo voice-buffer application968, randomized actor-record setup956 and record-key query252 add2,796 exact code bytes and116 owned nontext bytes. The exclusive8-byte unsigned-conversion bias retains its original address/alignment as a compiler LOCAL literal; untouched parts of the original constant provider and borrowed vtable remain original. A new one-source outer route selects the already accepted legacy Record218F8 strong destructor without changing any earlier verifier/core. Both complete native links prove six backup allocations discarded and original GLOBAL primary/strong-owner identities; every preceding ownership check remains mandatory. Original DOL hash, baseline regression, strict extents/actual relocations, generated progress,26 tests and166 native override source cases pass. Matching source covers1,798,076 /2,607,776 code bytes (68.950554%) and7,583 /8,803 functions; matched data is499,619 and complete owned data511,415 /1,030,936. All frozen producer notes and independent route review remain preserved.


- Accepted `adpcm-grid-sample-v2`: ADPCM voice-buffer application1056 and bicubic grid sampling1632 add2,688 exact code bytes and8 owned constant bytes. A second exclusive unsigned-conversion bias retains its original8-byte address/alignment as compiler LOCAL@48; untouched provider fragments remain original. The v1 full build passed all checks, then final acceptance rejected rich producer relocation records against the unchanged core compact records. A bounded exact16-record projection preserves every section/site/address/kind/symbol/addend/target and all v1 evidence; v2 changes no source, object, canonical payload or central registration. Both complete native links, original DOL hash, baseline regression, strict extents/actual relocations, generated progress,26 tests,166 existing native override cases and every preceding proof pass. Matching source covers1,800,764 /2,607,776 code bytes (69.053630%) and7,585 /8,803 functions; matched data499,627 and complete owned data511,423 /1,030,936.


- Accepted `drawpair-animframe-effects-v4`: native DrawPair construction504, AnimFrame construction400 and vertical-effect reset776 add1,680 exact code bytes and20 owned EH/index bytes. Two constructor callers migrate identifiers with identical allocated bytes and actual targets; both full native links preserve original borrowed identities and discard all nine unused backups. A44-byte original allocator state fragment stays in its original unclassified fallback with zero source/data credit. The linker retains its exact raw DTK object; native objdiff uses an identical-payload copy correcting only two artificial symbol metadata bytes, preserving every original unit and the full8,803-function address/extent inventory. Independent metadata and BSS audit reviews pass; failed attempts remain preserved. Original DOL hash, unchanged baseline, strict extents/actual relocations, generated progress,32 tests,167 native override source cases and every prior proof pass. Matching source covers1,802,444 /2,607,776 code bytes (69.118053%) and7,588 /8,803 functions; matched data499,627 and complete owned data511,443 /1,030,936.


- Accepted `curve-timer-resource-callback-v2`: two original curve-owner destructors3,756, timer dispatch568, handle release/cache clear64, resource registry paths672 and callback action752 add5,812 exact code bytes and28 genuine LOCAL switch-table bytes. All seven C entries, borrowed original data/BSS identities and neighboring storage remain preserved. The initial object build revealed repeated Ninja reconfiguration when an unchanged report co-output retained its old timestamp; its logs remain preserved. A bounded v3 wrapper runs the unchanged v2 object validation before completing only the report-copy timestamp. Independent11-case CLI review, unchanged old32tests plus2 timestamp regression tests, finite Ninja dryrun, original DOL hash, baseline regression, strict extents/actual relocations, generated progress and all earlier/native ownership proofs pass. The raw linker object and report-copy payload/metadata hashes remain unchanged. Matching source covers1,808,256 /2,607,776 code bytes (69.340925%) and7,595 /8,803 functions; matched data499,655 and complete owned data511,471 /1,030,936.


- Accepted `resource-action-callbacks`: resource action/reset1304 and target callback940 add2,244 exact code bytes and28 genuine LOCAL switch-table bytes. Both complete native links preserve original C identities, all borrowed dependencies and original table targets, and discard all three unique unused private destructors264 without credit. Rich producer relocations are projected exactly into unchanged core records; payloads, addresses, scopes and actual targets remain unchanged. Original DOL hash, unchanged baseline, strict extents/actual relocations, generated progress,34 tests,167 existing native override source cases, timestamp completion and every prior ownership proof pass. Matching source covers1,810,500 /2,607,776 code bytes (69.426975%) and7,597 /8,803 functions; matched data499,683 and complete owned data511,499 /1,030,936. Full original denominator and frozen research remain preserved.


- Accepted `motion-skin-actions-v5`: resource motion dispatch740 and skin callback1128 add1,868 exact code bytes, original GLOBAL vtable124 and genuine LOCAL switch tables64. All95 skin relocations equal the frozen89 retained+6 unused inventory; World275 contributes22. Earlier preparations and failed final native audit remain preserved. A bounded, independently reviewed outer extension covers all45 real table pointers with unchanged native allocation/map-discard checks, and distinguishes one undefined original100-byte neighboring callee from projected backup offsets. All other prior-source rules and verifier/native cores remain unchanged. Independent63 negative checks, both complete original native links, seven discarded backups608, original DOL hash, baseline regression, strict extents/actual relocations, progress and34tests pass. Matching source covers1,812,368 /2,607,776 code bytes (69.498607%) and7,599 /8,803 functions; matched data499,871 and complete owned data511,687 /1,030,936.


- Accepted `service-callback-tables`: platform services startup840 and three callback routines2348 add3,188 exact code bytes, original GLOBAL vtables404 and genuine LOCAL switch tables84. The clock-action body and table preserve the earlier frozen700+28 bytes; recovered full original vtable ownership establishes its natural8-byte alignment. All four original entry identities, every actual relocation, borrowed storage and existing consumers remain exact. Both complete native links, original DOL hash, baseline regression, strict allocation/extents, generated progress,34 tests and every previous native audit pass. Matching source covers1,815,556 /2,607,776 code bytes (69.620857%) and7,603 /8,803 functions; matched data500,359 and complete owned data512,175 /1,030,936. All original units and the full denominator remain preserved.


- Accepted `console-step-validity-v2`: console group binding492, original TRK range/single stepping248 and handle validity48 add788 exact code bytes and156 owned EH/index bytes. The first final audit caught missing canonical-path registration metadata; the failed log and a bounded field-only repair are preserved. Both complete native links retain all original GLOBAL entries, LOCAL EH objects, five original strong destructors and every borrowed initialized/NOBITS owner, while discarding six duplicate/private backups652 plus280 metadata without credit. The independently replayed TRK type-byte qualification describes the observed stored-byte reload; original qualifier provenance and an asynchronous writer remain unestablished. Original DOL hash, unchanged baseline, strict actual relocations/extents, generated progress,34 tests and all168 native override source cases pass. Matching source covers1,816,344 /2,607,776 code bytes (69.651074%) and7,607 /8,803 functions; matched data500,359 and complete owned data512,331 /1,030,936. Full denominator and earlier frozen evidence remain preserved.


- Accepted `record-small-forwarders`: timed event-record update788 and32 independent small owner/field/virtual delegates1292 add2,080 exact code bytes across33 original GLOBAL entries. All53 real relocations, borrowed floats/vtables/BSS, full original EH/startup inventory and source allocation ownership pass with no extra source data. Both complete native links, original DOL hash, unchanged baseline, strict extents, generated progress,34 tests and every earlier source-history/native proof pass. Matching source covers1,818,424 /2,607,776 code bytes (69.730836%) and7,640 /8,803 functions; matched data500,359 and complete owned data512,331 /1,030,936. The full original denominator and frozen near probes remain preserved.


- Accepted `menu2d-record-collision`: Menu2D construction364, transform-record append452 and collision-grid triangle sweep576 add1,392 exact code bytes and116 owned EH/index bytes. Four constructor/vtable consumers migrate only identifiers with byte-identical allocations and actual targets. Both complete native links retain the original constructor/destructor/vtable identities and borrowed storage, and discard six unused constructor backups/metadata264 without credit. Original DOL hash, unchanged baseline, strict actual relocations/extents, generated progress,34 tests and every earlier source-history/native proof pass. Matching source covers1,819,816 /2,607,776 code bytes (69.784215%) and7,643 /8,803 functions; matched data500,359 and complete owned data512,447 /1,030,936. Full original denominator and frozen evidence remain preserved.


- Accepted `allocator-startup-v2`: original allocator initializer56 and its sole LOCAL startup pointer4 match. The original GLOBAL32-byte allocator storage stays borrowed in its original assembly owner with zero credit. A final outer audit caught an oversized constructor-section read; the failed checkpoint is preserved. A bounded v2 check requires the exact80-byte native ELF constructor header/prefix plus original16-byte zero alignment tail, while the complete original table/native/core gates remain unchanged. Both complete native links, original DOL hash, unchanged baseline, strict extents/three actual relocations, generated progress,34 tests and every prior proof pass. Matching source covers1,819,872 /2,607,776 code bytes (69.786362%) and7,644 /8,803 functions; matched data500,363 and complete owned data512,451 /1,030,936. Full denominator and original inputs remain preserved.


- Accepted `owner-selection-v2`: owner selection update328 adds exact code, its exclusive compiler LOCAL signed-conversion bias8 and genuine EH/index20. The complete active relocation and initialized-pointer census proves sole literal ownership at the original address/alignment; every neighboring original provider byte remains preserved. An early staging attempt ran before preparation finished and failed without staging mutations; its log and bounded identical-job replay remain preserved. Both complete native links, original DOL hash, unchanged baseline, strict extents/18 actual relocations, generated progress,34 tests and every preceding source-history/native proof pass. Matching source covers1,820,200 /2,607,776 code bytes (69.798940%) and7,645 /8,803 functions; matched data500,391 and complete owned data512,479 /1,030,936. Full denominator, original inputs and frozen research remain preserved.

- Accepted `file-module-sphere-delegates-v4`: native File identities retain704 existing bytes with zero new credit; Python module1024, sphere dispatcher1264, and nine delegates456 add2744 code bytes plus164 owned EH/index bytes. Verified1,822,944/2,607,776 code bytes (69.90416354778938%),7,656/8,803 functions, original DOL hash, no regressions, all43 tests and170 native override source-unit checks. The raw baseline/report and original34 tests remain preserved; bounded function-identity comparison and strict43-test audit derivatives are sealed in `scratch/continuation_20261010/file-module-sphere-delegates-root-route-seal-v4.json`.


Accepted `bytecode-delegates` continuation: the genuine native File lifetime
restores the bytecode saver's272 source bytes and36 original exception/index
bytes; four ordinary delegates add284 source bytes. The full build retains the
original DOL hash, baseline comparison has no regressions, all43 repository
tests and every prior native ownership gate pass. Both full native ELFs retain
all five owners and the unchanged original616-byte borrowed context. Generated
progress is1,823,500/2,607,776 matching code bytes (69.92548439743291%) and
7,661/8,803 matching functions. The independently reviewed93-pin route seal is
`scratch/continuation_20261010/bytecode-delegates-root-route-seal-v1.json`.

Verified checkpoint `remaining-hooks-fields-v2`: 63 ordinary functions add 444 matching code bytes and 48 original exception/startup bytes. Total matching source is 1,823,944 / 2,607,776 code bytes (69.942510%), 7,724 / 8,803 functions, and 500,535 / 1,030,936 data bytes. Both native links retain the original array storage without credit; full original hash, unchanged baseline regression checks, all existing native ownership gates, and 43 tests pass. Frozen review and complete route evidence are retained in `scratch/continuation_20261010/remaining-hooks-fields-root-route-seal-v2.json`.
