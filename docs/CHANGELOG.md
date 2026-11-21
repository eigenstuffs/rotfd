# Verified milestones

## 2026-10-02 — decoder records, workspace, frames and DPCM tables

Added six matching partial source units: 284 bytes for plane record setup,
1,124 for workspace initialization, 1,296 for the first frame decoder, 36 for
its neighboring dispatch wrapper and 1,448 for the second frame decoder.
The five functions add 4,188 code bytes. Formula-based DPCM tables add 3,560
initialized data bytes; their four preceding alignment bytes retain explicit
original ownership and receive no source credit.

The byte-identical DOL, original hash, immutable baseline, all prior matches
and source/header hashes, source audits and all 23 tests pass. Progress reaches
969,820 / 2,607,776 code bytes (37.1895%), 3,148 / 8,803 functions,
334,952 / 1,030,936 data bytes (32.4901%) and 753 source units. Six provisional
native units are added; all byte/function denominators are preserved. The byte
reader and DPCM decoder remain private probes. See the decoder unit notes and
`scratch/movie_decoder_session_checkpoint.json` for combined evidence.

## 2026-10-02 — movie pause, display, storage and decoder tables

Added six matching partial source units: 404 bytes for video pause, 168 for
movie initialization, 636 for the display worker, 184 across three decoder
layout helpers and 864 for table initialization. The seven functions add
2,256 matching code bytes. Movie thread, stack, semaphore and buffer storage
adds 18,224 BSS bytes; clipping and reciprocal tables add another 2,624.
Unknown fields remain explicit in the movie storage tail.

The DOL remains byte-identical, all earlier sources/headers and matches are
preserved, and all 23 tooling tests pass. Progress reaches 965,632 / 2,607,776
code bytes (37.0289%), 3,143 / 8,803 functions, 331,392 / 1,030,936 data bytes
(32.1448%) and 747 source units. The six partial splits add seven provisional
native build units; byte and function denominators remain unchanged. The DMA
and YUV conversion probes remain uncredited. See the updated movie unit notes
and `scratch/movie_platform_session_checkpoint.json` for combined evidence.

## 2026-10-02 — video resume, enabled query and allocation cleanup

Added three matching functions across two partial source units: 148 bytes for
video/thread resume, eight for the raw enabled query and 112 for allocation
cleanup and its conditional virtual callback. They add 268 code bytes with
no data credit. The neighboring 404-byte pause routine remains a private
probe with framebuffer pointer-register differences.

The DOL is byte-identical, all prior sources/headers and matches are preserved,
and all 23 tooling tests pass. Progress reaches 963,376 / 2,607,776 code bytes
(36.9424%), 3,136 functions and 741 source units. Data remains 310,544 /
1,030,936 (30.1225%). See [resume evidence](notes/game-platform-video-resume.md)
and [cleanup evidence](notes/game-platform-video-cleanup.md).

## 2026-10-02 — fallback font atlas and projection data

Reconstructed the 96-glyph I4 font as editable bit-pattern rows, its 32-byte
texture object and five projection constants. The data-only unit adds 3,124
matching data bytes, reaching 310,544 / 1,030,936 (30.1225%) and 739 source
units. Code remains 963,108 / 2,607,776 (36.9322%).

The four original projection-alignment bytes retain explicit uncredited
ownership and remain in the native denominator. The DOL is byte-identical,
all earlier sources and headers are unchanged, and all 23 tests pass.
See [font evidence](notes/game-platform-disc-font.md) and
`scratch/platform_disc_font_checkpoint.json`.

## 2026-10-02 — fallback disc error display

Added the complete 1,108-byte display routine, fifteen aligned message arrays
(380 bytes) and an eight-byte compiler conversion constant. The original text
renderer, texture and shared state remain original work. Native pooled message
addresses now match, including the first zero-offset `addi` instruction.

The DOL is byte-identical, all prior sources and headers retain their hashes,
and all 23 tests pass. Progress reaches 963,108 / 2,607,776 code bytes
(36.9322%), 3,133 functions, 307,420 data bytes and 738 source units. Unknown
units remain in the denominator. See [display evidence](notes/game-platform-disc-display.md)
and `scratch/platform_disc_display_checkpoint.json`.

## 2026-10-02 — disc polling and error handling

Expanded the accepted wait source with the 536-byte poll routine and added
the complete 448-byte shared error handler, including fatal-delay/reset code.
Their two additional compiler-generated status tables add 104 matched bytes.
The earlier wait body/table remain exact; unused helpers and seven isolated
static-state bytes remain uncredited. Shared flags/state retain original
ownership. Adjacent table alignment requires compiling wait and poll together.

The byte-identical DOL, original SHA-1, all prior source matches and all 23
tooling tests pass. Native objdiff exposes the neighboring 32-byte zero-filled
region as an unmatched placeholder function after the split; it remains in
the denominator, adding 32 total code bytes and one total function with no
source credit. The raw native report is preserved. See [poll evidence](notes/game-platform-disc-poll.md)
and [error handler evidence](notes/game-platform-disc-error.md).

## 2026-10-02 — disc wait and display restoration

Reconstructed the 792-byte disc wait routine and its 52-byte status table.
The source preserves DVD retry, serialized error handling, display restoration
and the native temporary handle lifetime. Its two unused compiler-generated
weak helpers remain excluded from progress.

Validation: complete DOL byte comparison and unchanged SHA-1 passed; all 736
linked source units remain exact. All 23 tooling tests and source audits pass.
The original baseline and all earlier source/header hashes are unchanged.
See [disc wait evidence](notes/game-platform-disc-wait.md).

## 2026-10-02 — Disc status and asynchronous-read wait wrappers

Two source units add **188 matching code bytes / two functions / four SBSS
bytes**, reaching **960,224 / 2,607,744 (36.8220%)** code, **3,129 / 8,802
functions**, **306,876 / 1,030,936 (29.7667%)** data and 735 source units.
The global drive-status query and read submission/wait wrapper now match; their
original wait/error implementation remains unfinished.

All earlier source/header hashes and matches are preserved, protected inputs
and the original baseline are unchanged, the DOL is byte-identical, and all 23
tests pass. Code/function/data denominators are fixed; provisional units
increase by five to 4,242. All 732 canonical manifests and 471 mapped header
hashes are current. Source audits pass. See [disc wrapper evidence](notes/game-platform-disc-status.md)
and `scratch/platform_disc_status_checkpoint.json`.

## 2026-10-02 — Streaming state initialization

One source unit adds **544 matching code bytes / one function**, reaching
**960,036 / 2,607,744 (36.8148%)** code, **3,127 / 8,802 functions** and 733
source units. Streaming record resets, allocations, music voices and worker
creation now match with an explicit physical state view.

All earlier source/header hashes and matches are preserved, protected inputs
and the original baseline are unchanged, the DOL is byte-identical, and all 23
tests pass. Data remains **306,872 / 1,030,936 (29.7663%)**; code/function/data
denominators are fixed. Provisional units increase by two to 4,237. All 730
canonical manifests and 469 mapped header hashes are current. Source audits
pass. See [initializer evidence](notes/game-platform-audio-stream-init.md) and
`scratch/platform_audio_stream_init_checkpoint.json`.

## 2026-10-02 — Streaming resource submission

One source unit adds **468 matching code bytes / one function**, reaching
**959,492 / 2,607,744 (36.7939%)** code, **3,126 / 8,802 functions**,
**306,872 / 1,030,936 (29.7663%)** data and 732 source units. Submission now
matches duplicate rejection, chained owner-handle resolution, callback/cookie
assignment, queued-node allocation and mutex-protected registry append.

All earlier source/header hashes and matches are preserved, protected inputs
and the original baseline are unchanged, the DOL is byte-identical, and all 23
tests pass. Code/function/data denominators remain fixed; provisional units
increase by one to 4,235. All 729 canonical manifests and 465 mapped header hashes
are current. Source audits pass. See [submission evidence](notes/game-platform-audio-stream-submit.md)
and `scratch/platform_audio_stream_submit_checkpoint.json`.

## 2026-10-02 — Indexed streaming cleanup and diagnostic strings

One source unit adds **468 matching code bytes / one function / 32 rodata
bytes**, reaching **959,024 / 2,607,744 (36.7760%)** code, **3,125 / 8,802
functions**, **306,872 / 1,030,936 (29.7663%)** data and 731 source units.
Diagnostic-call scheduling now matches without volatile fields or compiler
pragmas. Six earlier units are strictly reverified after the shared cleanup
result declaration changes to void.

All 731 source units fully match, unrelated sources/headers and protected inputs
are unchanged, the original baseline is preserved, the DOL is byte-identical,
and all 23 tests pass. Code/function/data denominators remain fixed;
provisional units increase by two to 4,234. All 728 canonical manifests and 459
mapped header hashes are current. Source extent and assembly audits pass. See
[cleanup evidence](notes/game-platform-audio-stream-cleanup.md) and
`scratch/platform_audio_stream_cleanup_checkpoint.json`.

## 2026-10-02 — Streaming removal, lifetime and file storage

Three source units add **616 matching code bytes / three functions / 92 BSS
bytes**, reaching **958,556 / 2,607,744 (36.7580%)** code, **3,124 / 8,802
functions**, **306,840 / 1,030,936 (29.7632%)** data and 730 source units.
Removal by name, constructor/destructor fragments and the shared DVD/path
storage now match. The indexed cleanup probe remains uncredited.

All earlier source/header hashes and matches are preserved, the original
baseline is unchanged, the DOL is byte-identical, and all 23 tests pass.
Code/function/data denominators are unchanged; provisional units increase by
four to 4,232. All 727 canonical manifests and 456 mapped header hashes are
current. Source extent and assembly audits pass. See
[verified evidence](notes/game-platform-audio-stream-release.md) and
`scratch/platform_audio_stream_release_checkpoint.json`.

## 2026-10-02 — Audio streaming global mutex and registry head

One source unit adds **28 matching BSS bytes**, reaching **306,748 / 1,030,936
(29.7543%)** data and 727 source units. Code remains **957,940 / 2,607,744
(36.7344%)**, with **3,121 / 8,802 functions**. The 24-byte SDK mutex and
four-byte registry-head pointer now have typed source definitions. Both streaming
consumers retain all 1,060 matching code bytes after the mutex declaration is
made concrete.

All 727 source units fully match, unrelated sources/headers and the original
baseline are unchanged, the DOL is byte-identical and all 23 tests pass.
Code/function/data denominators are preserved; provisional units increase by
three to 4,228 with original surrounding storage retained. No helper, code or
padding is credited. All 724 canonical manifests and 439 mapped header hashes
are current. See [global storage evidence](notes/game-platform-audio-stream-globals.md)
and `scratch/platform_audio_stream_globals_checkpoint.json`.

## 2026-10-02 — Audio streaming level, status and close helpers

Two source units add **1,060 matching code bytes / seven functions**, reaching
**957,940 / 2,607,744 (36.7344%)** code, **3,121 / 8,802 functions**,
**306,720 / 1,030,936 (29.7516%)** data and 726 source units. Thread wakeup,
effect/music levels, secondary mute/pause control, status queries and close
now match. Two earlier caller declarations gain their recovered result types,
preserving all 232 caller code bytes and earlier credit.

All 726 source units fully match, earlier shared headers and unrelated sources
are unchanged, the original baseline remains immutable, the DOL is byte-identical
and all 23 tests pass. Code/function/data denominators are preserved; provisional
units increase by four to 4,225 with original fragments retained. No data,
helper or padding is credited. All 723 canonical manifests and 434 mapped header
hashes are current. See [streaming evidence](notes/game-platform-audio-stream.md)
and `scratch/platform_audio_stream_checkpoint.json`.

## 2026-10-02 — Audio track lookup and generic setup

Two source units add **1,108 matching code bytes / two functions**, reaching
**956,880 / 2,607,744 (36.6938%)** code, **3,114 / 8,802 functions**,
**306,720 / 1,030,936 (29.7516%)** data and 724 source units. Running-track
lookup, relationship rejection, duplicate detection and generic handle setup
now match. The existing fade caller's third argument is corrected to a handle
reference while preserving all 248 compiled bytes and its earlier credit.

All 724 source units fully match, all shared headers and unrelated earlier
sources are unchanged, the original baseline remains immutable, the DOL is
byte-identical and all 23 tests pass. Code/function/data denominators are
preserved; provisional units increase by three to 4,221 with original fragments
retained. No data, helpers or padding are credited. All 721 canonical manifests
and 424 mapped header hashes are current. See
[setup evidence](notes/game-audio-track-setup.md) and
`scratch/audio_track_setup_checkpoint.json`.

## 2026-10-02 — Audio track selection

One source unit adds **652 matching code bytes / one function**, reaching
**955,772 / 2,607,744 (36.6513%)** code, **3,112 / 8,802 functions**,
**306,720 / 1,030,936 (29.7516%)** data and 722 source units. Selection
of inactive or greatest-timer tracks, both inline release paths and fallback
to track zero now match.

All 722 source units fully match; earlier sources, headers and the original
baseline are unchanged. The DOL is byte-identical and all 23 tests pass.
Code/function/data denominators are preserved; provisional units increase by
one to 4,218, retaining downstream original code. An unused 84-byte weak
destructor remains unlinked and uncredited. All 719 canonical manifests and
414 mapped header hashes are current. See
[selection evidence](notes/game-audio-track-select.md) and
`scratch/audio_track_select_checkpoint.json`. The adjacent platform acquisition
routine remains [private pending conversion-pool ownership](notes/game-platform-audio-acquire.md).

## 2026-10-02 — Audio track release

One source unit adds **324 matching code bytes / one function**, reaching
**955,120 / 2,607,744 (36.6263%)** code, **3,111 / 8,802 functions**,
**306,720 / 1,030,936 (29.7516%)** data and 721 source units. Clearing a
track's running/timer fields and releasing all three handles now match.

All 721 source units fully match; earlier sources, headers and the original
baseline are unchanged. The DOL is byte-identical and all 23 tests pass.
Code/function/data denominators are preserved; the provisional unit count
grows by two to 4,217, retaining the original neighboring routines. An unused
84-byte weak destructor remains unlinked and uncredited. All 718 canonical
manifests and 409 mapped header hashes are current. See
[release evidence](notes/game-audio-track-release.md) and
`scratch/audio_track_release_checkpoint.json`.

## 2026-10-02 — Audio fades, levels, mute and sound-mode controls

Five source units add **1,056 matching code bytes / eight functions**, reaching
**954,796 / 2,607,744 (36.6139%)** code, **3,110 / 8,802 functions**,
**306,720 / 1,030,936 (29.7516%)** data and 720 source units. Stream-path
forwarding, fade setup, both level setters, channel mute flags, OS sound-mode
access and an empty hook now match.

All 720 source units fully match; earlier sources, headers and the original
baseline are unchanged. The DOL is byte-identical and all 23 tests pass.
Code/function/data denominators are preserved; the provisional unit count
increases by six to 4,215 while retaining the original channel acquisition
routine and downstream code. No helpers, data or padding are credited. All
717 canonical manifests and 404 mapped header hashes are current. See
[control evidence](notes/game-platform-audio-controls.md) and
`scratch/platform_audio_controls_checkpoint.json`.

## 2026-10-02 — Audio resource loading and track setup

One source unit adds **604 matching code bytes / one function** and **eight
matching data bytes**, reaching **953,740 / 2,607,744 (36.5734%)** code,
**3,102 / 8,802 functions**, **306,720 / 1,030,936 (29.7516%)** data and
715 source units. DSP/WAV selection, normalized resource names, failure
handling and successful channel/handle setup now match the original routine.

All 715 source units fully match, earlier source/header hashes and the original
baseline are unchanged, the DOL is byte-identical, and all 23 tests pass. All
denominators are preserved, including 4,209 provisional units. An unused
84-byte weak destructor is absent from the final ELF and excluded from credit.
All 712 canonical manifests and 379 mapped header hashes are current. See
[loading evidence](notes/game-platform-audio-load.md) and
`scratch/platform_audio_load_checkpoint.json`.

## 2026-10-02 — Audio update, path handling and shared scalar data

Five source units add **1,200 matching code bytes / five functions** and
**40 matching data bytes**, reaching **953,136 / 2,607,744 (36.5502%)** code,
**3,101 / 8,802 functions**, **306,712 / 1,030,936 (29.7508%)** data and
714 source units. The complete 928-byte update now matches handle resolution,
fused pan/fade arithmetic, attenuation and native completion dispatch. Two
path wrappers, streaming flush and an ordered scalar clamp also match.

All 714 source units fully match, all earlier source/header hashes and the
original baseline are unchanged, the rebuilt DOL is byte-identical, and all
23 tests pass. Code/function/data denominators are preserved. The provisional
unit count grows by six to 4,209, retaining original fragments. No helpers or
padding are credited. All 711 canonical manifests and 374 mapped header hashes
are current. See [audio evidence](notes/game-platform-audio-update.md) and
`scratch/platform_audio_update_checkpoint.json`. Spatial mixing and resource
loading remain original.

## 2026-10-02 — Platform audio reset and completion cleanup

Two source units add **520 matching code bytes / four functions**, reaching
**951,936 / 2,607,744 (36.5042%)** code, **3,096 / 8,802 functions**,
**306,672 / 1,030,936 (29.7469%)** data and 709 source units. The verified
increment contains two float getters, reset of all 32 audio channels with AX
voice state handling and ARAM reset, and completed-channel cleanup.

All 709 source units fully match, the DOL is byte-identical, all 23 tests pass,
and all earlier source/header files and the original baseline are unchanged.
Code, function and data denominators are preserved. The provisional unit
denominator grows by three to 4,203 while preserving original ranges around
the partial text splits. No owned data, helpers or padding are emitted. All
706 canonical candidate manifests and 361 mapped header hashes are current.
See [audio evidence](notes/game-platform-audio-reset.md) and
`scratch/platform_audio_reset_checkpoint.json`. The larger 928-byte update
routine remains a private source probe with unresolved instruction differences.

## 2026-10-02 — Object-list pools and group removal

Five source units add **1,228 matching code bytes / ten functions**, reaching
**951,416 / 2,607,744 (36.4843%)** code, **3,092 / 8,802 functions**,
**306,672 / 1,030,936 (29.7469%)** data and 707 source units. The verified
increment covers record push/pop, node release, pool initialization, removal
by key and optional resolved object, and four group cleanup/acquire helpers.
Native node acquisition and combined list clearing remain uncredited probes.

All 707 source units fully match, the rebuilt DOL is byte-identical, all 23
tests pass, and all earlier source/header files and the original baseline are
unchanged. Code, function and data denominators are preserved. The provisional
unit denominator grows by seven to 4,200 as the new source splits retain two
additional original ranges. An unused 84-byte temporary cleanup helper remains
unlinked and uncredited. All 704 candidate manifests and 353 mapped header
hashes are current. See [pool evidence](notes/game-object-list-pool.md) and
`scratch/object_list_pool_checkpoint.json`.

## 2026-10-02 — ARAM lifetime and native bitset construction

Three source units add **484 matching code bytes / three functions** and
**52 matching data bytes**, reaching **950,188 / 2,607,744 (36.4372%)** code,
**3,082 / 8,802 functions**, **306,672 / 1,030,936 (29.7469%)** data and
702 source units. Owner initialization, pool destruction and generated C++
startup now match, including the constructor pointer and destructor-registration
record. All 2,392 code bytes in `8028531C..80285C74` are now linked from source.

The shared bitset constructor is recovered as a real C++ declaration and
24-byte definition, preserving its existing code credit. The ARAM pool now
shares its actual storage base and bitset member. All 22 affected earlier
units retain their matching code/data. All 702 units fully match, the DOL is
byte-identical, all 23 tests pass, the original baseline is immutable and all
denominators are unchanged. Unused compiler cleanup helpers remain unlinked
and uncredited. See [lifetime evidence](notes/game-platform-aram-lifetime.md)
and `scratch/platform_aram_lifetime_checkpoint.json`.

## 2026-10-02 — ARAM token acquisition and cursor reset

Two further source units add **812 matching code bytes / two functions**,
reaching **949,704 / 2,607,744 (36.4186%)** code, **3,079 / 8,802 functions**,
**306,620 / 1,030,936 (29.7419%)** data and 699 source units. The full ARAM
group now owns **1,836 code bytes / eight functions** and **4,608 BSS bytes**.
Its byte-valued token acquisition grows storage in blocks of 256 and updates
the occupancy bitset; the reset helper restores both native cursors.

All 699 source units fully match, the original DOL hash and direct comparison
pass, all 23 tests pass, and the original baseline is unchanged. The shared
ARAM header gained two declarations; strict reproof preserves every earlier
ARAM code/data byte. All pre-session source/header files are unchanged.
The provisional unit denominator is 4,193; code, function and data denominators
are unchanged. The owner constructor remains a private 120-byte probe against
124 native bytes. See [ARAM evidence](notes/game-platform-aram.md) and
`scratch/platform_aram_checkpoint.json`.

## 2026-10-02 — Platform ARAM requests and initialization

Seven source units add **1,024 matching code bytes / six functions** and
**4,608 matching BSS bytes**, reaching **948,892 / 2,607,744 (36.3875%)**
code, **3,077 / 8,802 functions**, **306,620 / 1,030,936 (29.7419%)** data
and 697 source units. Initialization, flush, submission/completion and two
aligned cursor helpers match; both 64-entry request banks have verified
36-byte strides. Original token-pool acquisition/lifetime and borrowed strings
remain pending. See [ARAM evidence](notes/game-platform-aram.md) and
`scratch/platform_aram_initial_checkpoint.json`.

All 697 source units fully match, the DOL is byte-identical, all 23 tests pass,
and the original baseline and all earlier source/header files are unchanged.
The provisional unit denominator is 4,192; code, function and data denominators
are preserved. An explicit original-padding unit retains the four uncredited
trig-table alignment bytes when the following ARAM bank is split out.

New [sprite research](notes/game-platform-sprite-draw.md) uses literal constants
and reaches the original 2,036-byte size with 158 differing instruction
positions. The separate 92-byte table initializer matches code after actual
relocations, but its local constant-pool order differs from the original.
Both remain uncredited.

## 2026-10-02 — Platform draw dispatch and trig-table ownership

One wrapper adds **48 matching code bytes / one function**, and two lookup
arrays add **388 matching BSS bytes**, reaching **947,868 / 2,607,744
(36.3482%)** code, **3,071 / 8,802 functions**, **302,012 / 1,030,936
(29.2949%)** data and 690 source units. The 64-/33-float tables preserve four
trailing bytes under original ownership. The provisional unit denominator is
now 4,183 after splitting original units; total code, function and data
denominators are unchanged. All 690 units fully match, the DOL is byte-identical,
all 23 tests pass, all other sources are unchanged and the original baseline
is immutable. The trig declaration refinement preserves every earlier code
and owned data byte. See [dispatch evidence](notes/game-platform-draw-dispatch.md),
[table ownership](notes/game-platform-trig-tables.md) and
`scratch/platform_draw_tables_checkpoint.json`.

The [sprite renderer](notes/game-platform-sprite-draw.md) now has private
structural improvements in loop unrolling, vector temporaries, texture writes,
manager lookup and color narrowing. Its 2,036-byte probe retains both native facing comparisons, the advancing
group pointer copy and the original color/culling stack order; 164 instruction
positions still differ, so it remains uncredited.
The adjacent [flagged-quad renderer](notes/game-platform-debug-quads.md) now has
verified layout/behavior notes and a 1,208-byte private probe; it also remains
uncredited. Neither diagnostic score is counted as matching source.

## 2026-10-02 — Platform scalar math wrappers

Three functions add **132 matching code bytes**, reaching **947,820 /
2,607,744 (36.3464%)**, **3,070 / 8,802 functions** and 688 source units.
The empty draw callback, logarithm and clamped inverse-cosine wrappers preserve
all eight native relocations. The DOL is byte-identical, all audits and all 23
tests pass, and earlier sources and the initial baseline remain unchanged.
See [scalar math evidence](notes/game-platform-math-wrappers.md) and
`scratch/platform_math_wrappers_checkpoint.json`. This continuation adds
**1,388 code bytes, eight functions, eight data bytes and two source units**;
consolidated acceptance is in `scratch/platform_math_resume_checkpoint.json`.
The [sprite display-list probe](notes/game-platform-sprite-draw.md) remains
uncredited pending instruction and ABI convergence.

## 2026-10-02 — Platform trigonometric interpolation

Five functions add **1,256 matching code bytes** and an **eight-byte shared
conversion constant**, reaching **947,688 / 2,607,744 (36.3413%)**,
**3,067 / 8,802 functions**, **301,624 / 1,030,936 data bytes (29.2573%)**,
and 687 source units. Tangent, sine, cosine, angle calculation and native table
initialization now resolve all consumers of the compiler-local bias. The full
DOL is byte-identical; previous sources and the original baseline are unchanged,
all audits pass and all 23 tests pass. See
[trigonometric evidence](notes/game-platform-trig.md) and
`scratch/platform_trig_checkpoint.json`.

## 2026-10-02 — Platform draw helpers and native interface table

Four functions add **252 matching code bytes** and a **16-byte native table**,
reaching **946,432 / 2,607,744 (36.2931%)**, **3,062 / 8,802 functions**,
**301,616 / 1,030,936 data bytes (29.2565%)**, and 686 source units.
The aligned-buffer draw wrapper and native index-block methods now use
verified C++ virtual dispatch and a nonvirtual destructor. All source/progress
audits and all 23 tests pass; the DOL, earlier source files and baseline are
unchanged. See [draw/interface evidence](notes/game-platform-draw-helpers.md)
and `scratch/platform_draw_helpers_checkpoint.json`.

This record/list continuation adds **2,372 code bytes, 12 functions, 16 data
bytes and eight source units**. Consolidated acceptance is preserved in
`scratch/platform_record_list_resume_checkpoint.json`. The neighboring
440-byte record-reservation probe remains uncredited with 13 instruction
differences.

## 2026-10-02 — Platform record deactivation

One wrapper adds **60 matching code bytes**, reaching **946,180 /
2,607,744 (36.2835%)**, **3,058 / 8,802 functions**, and 685 source units.
It preserves the nonnegative-index check and status-1 record release. The
neighboring 440-byte reservation probe remains uncredited with 13 instruction
differences. The DOL, all audits and all 23 tests pass; earlier sources and
the original baseline are unchanged. See
[deactivation evidence](notes/game-platform-record-deactivate.md) and
`scratch/platform_record_deactivate_checkpoint.json`.

## 2026-10-02 — Platform record/link array construction

The native constructor adds **392 matching code bytes**, reaching **946,120 /
2,607,744 (36.2812%)**, **3,057 / 8,802 functions**, and 684 source units.
It preserves empty storage initialization, clock/threshold setup, two-link
free-list initialization and the original flags. All eight earlier related
units remain exact after refining the declarations. The 360 unlinked weak
cleanup bytes receive no credit. The full DOL, all audits and all 23 tests
pass; prior source files and the original baseline are unchanged. See
[array construction evidence](notes/game-platform-arrays-constructor.md) and
`scratch/platform_arrays_constructor_checkpoint.json`.

## 2026-10-02 — Platform record growth and activation

One function adds **700 matching code bytes**, reaching **945,728 /
2,607,744 (36.2661%)**, **3,056 / 8,802 functions**, and 683 source units.
The allocator preserves reclamation, link-storage growth, the 32,000-entry
limit and free-chain transfer. All 21 relocations match, and all dependencies
from this record/list continuation resolve through matching source. Data
remains **301,600 / 1,030,936**. The DOL is byte-identical, prior sources
and baseline are unchanged, all audits and all 23 tests pass. See
[record growth evidence](notes/game-platform-record-growth.md) and
`scratch/platform_record_growth_checkpoint.json`.

## 2026-10-02 — Platform record release

One function adds **180 matching code bytes**, reaching **945,028 /
2,607,744 (36.2393%)**, **3,055 / 8,802 functions**, and 682 source units.
Record release merges both chains into the free list and preserves status and
storage-address updates. The typed free-list declaration preserves all six
earlier related units byte for byte. The full DOL is identical, the baseline
and prior sources are unchanged, all audits pass, and all 23 tests pass.
See [record release evidence](notes/game-platform-record-release.md) and
`scratch/platform_record_release_checkpoint.json`.

## 2026-10-02 — Platform signed-index list helpers

Two partial text units add **456 matching code bytes** and two functions,
reaching **944,848 / 2,607,744 (36.2324%)**, **3,054 / 8,802 functions**,
and 681 source units. The list initializer and merge routine preserve native
signed-short endpoints/counts and the six-byte aggregate return ABI. Data
remains **301,600 / 1,030,936**. The DOL is byte-identical; all prior
sources, progress/source audits, the original baseline and all 23 tests pass.
See [index-list evidence](notes/game-platform-index-lists.md) and
`scratch/platform_index_lists_checkpoint.json`.

## 2026-10-02 — Platform record access and reactivation

Two functions add **332 matching code bytes**, reaching **944,392 /
2,607,744 (36.2149%)**, **3,052 / 8,802 functions**, and 679 source units.
Record lookup now preserves status checks, timestamp/storage updates and the
optional reactivation result. Data remains **301,600 / 1,030,936**. The DOL
is byte-identical; prior source and the original baseline are unchanged,
all source/progress audits pass, and all 23 tests pass. See
[record access evidence](notes/game-platform-record-access.md) and
`scratch/platform_record_access_checkpoint.json`.

## 2026-10-02 — Texture initialization, binding and owned switch table

Texture binding and the adjacent empty hook add **940 matching code bytes**,
**60 data bytes** and two functions, reaching **944,060 / 2,607,744
(36.2022%)**, **3,050 / 8,802 functions**, **301,600 / 1,030,936 data bytes
(29.2550%)**, and 678 source units. The seven-entry texture-pool code block
now reconstructs all 2,532 native code bytes. Native GX declarations preserve
all earlier bytes; the ordinary switch emits its exact 60-byte jump table.
The DOL is byte-identical, all 23 tests and source/progress audits pass, and
the original baseline is unchanged. See [texture binding evidence](notes/game-platform-texture-binding.md),
`scratch/platform_texture_bind_checkpoint.json` and
`scratch/platform_pool_hook_checkpoint.json`.

The resumed pool continuation adds **2,788 code bytes, nine functions and
60 data bytes** across five new source units, including the pool lifetime,
record selection, release, growth and texture-binding increments. Consolidated
evidence is in `scratch/platform_texture_pool_resume_checkpoint.json`. The
bit search and incompatible native cache-table probes remain uncredited.

## 2026-10-02 — Platform vacant-slot acquisition and growth

One function adds **712 matching code bytes**, reaching **943,120 /
2,607,744 (36.1661%)**, **3,048 / 8,802 functions**, and 677 source units.
Vacant-slot acquisition now preserves record growth in blocks of eight,
bitset sizing and occupancy updates. All earlier sources remain unchanged.
Data remains **301,540 / 1,030,936**. The DOL is byte-identical, all 23
tests and source/progress audits pass, and the original baseline is unchanged.
See [pool growth evidence](notes/game-platform-pool-growth.md) and
`scratch/platform_pool_growth_checkpoint.json`.

## 2026-10-02 — Platform pool sweep and explicit release

Two functions add **352 matching code bytes**, reaching **942,408 /
2,607,744 (36.1388%)**, **3,047 / 8,802 functions**, and 676 source units.
The occupied-record sweep and explicit release preserve the mark flag, object
slot and occupancy count behavior. Shared flag declarations preserve all
earlier matches. Data remains **301,540 / 1,030,936**. The DOL is
byte-identical, all 23 tests and source/progress audits pass, and the original
baseline is unchanged. See [pool release evidence](notes/game-platform-pool-release.md)
and `scratch/platform_pool_release_checkpoint.json`.

## 2026-10-02 — Platform record selection and removal

Two functions add **256 matching code bytes**, reaching **942,056 /
2,607,744 (36.1253%)**, **3,045 / 8,802 functions**, and 675 source units.
The greatest-age selector and bounded removal loop now match, including
signed count narrowing and unordered floating-point behavior. The refined
record layout preserves both earlier array-lifetime units. Data remains
**301,540 / 1,030,936**. The DOL is byte-identical, all 23 tests and
source/progress audits pass, and the original baseline is unchanged. See
[record selection evidence](notes/game-platform-record-selection.md) and
`scratch/platform_record_selection_checkpoint.json`.

## 2026-10-02 — Platform pool construction and destruction

Two native functions add **528 matching code bytes**, reaching **941,800 /
2,607,744 (36.1155%)**, **3,043 / 8,802 functions**, and 674 source units.
The pool now reconstructs occupied-slot release and its nested storage
lifetime. Shared bitset/shutdown declarations preserve all previous matches.
The existing initializer stays with its earlier owning unit; 584 unlinked
weak-helper bytes receive no credit. Data remains **301,540 / 1,030,936**.
The DOL is byte-identical, all 23 tests and source/progress audits pass, and
the original baseline is unchanged. See [pool lifetime evidence](notes/game-platform-pool-lifetime.md)
and `scratch/platform_pool_lifetime_checkpoint.json`.

## 2026-10-02 — Native cache binding operations

Three functions add **420 matching code bytes**, reaching **941,272 /
2,607,744 (36.0953%)**, **3,041 / 8,802 functions**, and 673 source units.
Both concrete cache bindings and the base sentinel now match, including
generation-checked handle resolution and old mapping invalidation. Shared
cache declarations retain the verified storage/vptr layout; shutdown remains
exact. Binding tables and cache destructor loops still use original objects.
Data remains **301,540 / 1,030,936 bytes**. The full DOL is byte-identical,
all 23 tests and source/progress audits pass, and the original baseline is
unchanged. See [cache binding evidence](notes/game-platform-cache-binding.md)
and `scratch/platform_cache_bind_checkpoint.json`.

This resumed continuation adds **768 code bytes and five functions** across
four units. Consolidated verification is recorded in
`scratch/platform_lifecycle_binding_resume_checkpoint.json`. The cache
destructor probes retain their original 604-byte size with 32 remaining
register-choice differences each and receive no source credit.

## 2026-10-02 — Platform shutdown and item deletion

Two functions add **348 matching code bytes**, reaching **940,852 /
2,607,744 (36.0792%)**, **3,038 / 8,802 functions**, and 671 source units.
Shutdown preserves the original cache/resource/pool destruction and video/
graphics cleanup order. The final item now has a matching native destructor.
Verified global declarations extend through `190`; every earlier source
unit remains exact after recompilation. Data remains **301,540 / 1,030,936**.
The DOL is byte-identical, all 23 tests and source/progress audits pass, and
the original baseline is unchanged. See [shutdown evidence](notes/game-platform-shutdown.md)
and `scratch/platform_shutdown_checkpoint.json`.

## 2026-10-02 — Platform array lifetime checkpoint

Five functions across two source units add **480 matching code bytes**,
reaching **940,504 / 2,607,744 (36.0658%)** and **3,036 / 8,802 functions**.
All 669 source units remain exact; data remains **301,540 / 1,030,936 bytes**.
The native array destructors, float accumulator and integer extrema helpers
pass strict relocation checks and the full original DOL hash. Their shared
vtable group retains original ownership. All 23 tests and source extent/
assembly audits pass, and the saved baseline is unchanged. See
[platform array lifetime](notes/game-platform-array-lifetime.md) and
`scratch/platform_array_lifetime_checkpoint.json`.

## 2026-09-27 — Platform reset-monitor thread

Three functions add **368 matching code bytes**, reaching **940,024 /
2,607,744 (36.0474%)**, **3,031 / 8,802 functions**, and 667 source units.
The thread suspend/resume wrappers and reset monitor now match, including
the original signed-byte flags and ordered graphics/cache/disc reset calls.
Their shared storage and literals retain their existing ownership.

This continuation adds ten functions and **2,276 code bytes** across five
source units. Data remains **301,540 / 1,030,936 bytes**. All source units
remain exact, the DOL is byte-identical, all 23 tests and progress/extent/
assembly audits pass, and the original baseline is unchanged. See
[reset-thread evidence](notes/game-platform-reset-thread.md) and
`scratch/world_reference_construction_resume_checkpoint.json`.

## 2026-09-27 — World entry-pool resizing

One function adds **768 matching code bytes**, reaching **939,656 /
2,607,744 (36.0333%)**, **3,028 / 8,802 functions**, and 666 source units.
The pool's record initialization, storage resizing and occupancy-bitset
updates now match. Data remains **301,540 / 1,030,936 bytes**.

The new split exposes a 540-byte original global-storage region as a
leading unmatched fallback function in native objdiff. Its denominator
therefore increases by 540 code bytes and one function; those bytes receive
no credit. The native report is preserved. The neighboring 3,064-byte
loader remains private with four load-order instruction differences.

All source units remain exact, the full DOL is byte-identical, all 23 tests
and progress/extent/assembly checks pass, and the original baseline is
unchanged. See [pool resizing](notes/game-world-entry-pool-resize.md),
[loader research](notes/game-world-handle-loader.md), and
`scratch/world_entry_pool_resize_checkpoint.json`.

## 2026-09-27 — World reference callbacks and native construction

Six functions add **1,140 matching code bytes**, reaching **938,888 /
2,607,204 (36.0113%)**, **3,027 / 8,801 functions**, and 665 source units.
Both world reference callbacks, the viewport entry/handle helpers, and the
six-handle resource constructor pair now match. Data remains **301,540 /
1,030,936 bytes**. The 2,068-byte viewport-render candidate remains private
and uncredited while its floating-point register differences are resolved.

All source units remain exact, the complete DOL is byte-identical, and all
23 tests and progress/extent/assembly checks pass. Existing sources changed
only through the verified six-handle constructor/vector declarations; the
baseline is unchanged. See [world callbacks](notes/game-world-reference-callbacks.md),
[viewport helpers](notes/game-viewport-render-helpers.md),
[resource construction](notes/game-six-handle-resource-constructor.md), and
`scratch/world_reference_callbacks_checkpoint.json`.

## 2026-09-27 — Render traversal and record clearing

Two functions add **1,368 matching code bytes**, reaching **937,748 /
2,607,204 (35.9676%)**, **3,021 / 8,801 functions**, and 662 source units.
The complete object traversal now reproduces matrix/context setup, sphere
selection, the bounded entry list and geometry/material callbacks. The
adjacent resize-to-zero routine also matches. Data remains **301,540 /
1,030,936 bytes**.

This continuation adds 13 functions, **4,600 code bytes** and **68 table
bytes** across six source units. All source units remain exact, the DOL is
byte-identical, and all 23 tests and progress/extent/assembly checks pass.
See [render dispatch](notes/game-render-object-dispatch.md),
[array clearing](notes/game-render-record-clear.md), and
`scratch/render_object_dispatch_checkpoint.json`.

## 2026-09-27 — Six-handle resource callbacks and lifetime

Five functions add **596 matching code bytes** and **36 table bytes**,
reaching **936,380 / 2,607,204 (35.9151%)**, **3,019 / 8,801 functions**,
**301,540 / 1,030,936 data bytes**, and 660 linked source units. Destruction,
reference marking, loading, the empty hook, and the separately located status
callback now match. Original table alignment remains excluded from credit.

All source units remain exact, the full DOL is byte-identical, and all 23
tests and progress/extent/assembly checks pass. See
[six-handle resource evidence](notes/game-six-handle-resource.md) and
`scratch/six_handle_resource_status_checkpoint.json`.

## 2026-09-27 — Slot-resource construction and handle-resource callbacks

Six functions add **2,636 matching code bytes** and **32 table bytes**,
reaching **935,784 / 2,607,204 (35.8922%)**, **3,014 / 8,801 functions**,
**301,504 / 1,030,936 data bytes**, and 658 linked source units. The native
slot-resource constructor and five handle-resource lifetime/query/callback
routines now match. Unlinked weak helpers receive no credit.

All source units remain exact, the full DOL is byte-identical, and all 23
tests and progress/extent/assembly checks pass. The existing factory retains
its exact code after the native virtual-table rename. See
[construction](notes/game-resource-slot-constructor.md),
[handle-resource evidence](notes/game-handle-resource.md), and
`scratch/handle_resource_checkpoint.json`.

## 2026-09-27 — Resource acquisition, growth and native destruction

Three functions add **3,664 matching code bytes** and **12 table bytes**,
reaching **933,148 / 2,607,204 (35.7911%)**, **3,008 / 8,801 functions**,
**301,472 / 1,030,936 data bytes**, and 656 linked source units. The full
2,576-byte acquisition/setup routine, 824-byte pool growth routine, and
264-byte native destructor now match. Original table padding remains excluded.

All source units remain exact, the full DOL is byte-identical, and all 23
tests and progress/extent/assembly checks pass. The pool destructor remains
a private near-match. See [acquisition](notes/game-resource-slot-acquire.md),
[growth](notes/game-resource-slot-growth.md), and
[native lifetime evidence](notes/game-resource-slot-destructor.md), plus
`scratch/resource_slot_acquire_checkpoint.json`.

## 2026-09-27 — Resource slot callback dispatcher

One routine adds **388 matching code bytes**, reaching **929,484 /
2,607,204 (35.6506%)**, **3,005 / 8,801 functions**, and 653 source units.
This continuation adds five functions and **2,620 code bytes** across three
units. All prior source matches remain exact, the full DOL is byte-identical,
and all 23 tests and progress/extent/assembly checks pass. The native pool
destructor remains a private near-match. See
[callback evidence](notes/game-resource-slot-callbacks.md) and
`scratch/resource_slot_callbacks_checkpoint.json`.

## 2026-09-27 — Resource slot-pool operations

Three routines add **960 matching code bytes**, reaching **929,096 /
2,607,204 (35.6357%)**, **3,004 / 8,801 functions**, and 652 source units.
Slot return, acquisition and reference-counted record release now match.
The full DOL and every prior source unit remain exact; all 23 tests and
progress/extent/assembly checks pass. Data remains unchanged. See
[pool evidence](notes/game-resource-slot-pool.md) and
`scratch/resource_slot_pool_checkpoint.json`.

## 2026-09-27 — Resource-slot reset

One routine adds **1,272 matching code bytes**, reaching **928,136 /
2,607,204 (35.5989%)**, **3,001 / 8,801 functions**, and 651 linked source
units. It removes an occupied resource slot and clears its retained references.
Data remains **301,460 / 1,030,936 bytes**. All source units remain exact,
the DOL is byte-identical, and all 23 tests and progress/extent/assembly checks
pass. See [reset evidence](notes/game-resource-slot-reset.md) and
`scratch/resource_slot_reset_checkpoint.json`.

## 2026-09-27 — Fixed handle-array lifetime, 3,000 matching functions

Four native lifetime routines add **352 code bytes**, reaching **926,864 /
2,607,204 (35.5501%)**, **3,000 / 8,801 functions**, and 650 linked source
units. The fixed array contains 144 handles; C++ reproduces its native array
helper calls and the element construction/destruction layers. Emitted unused
helpers receive no credit. Data remains **301,460 / 1,030,936 bytes**.

This continuation adds nine functions and 2,040 code bytes. All 650 source
units remain exact, the complete DOL is byte-identical, and all 23 tests and
progress/extent/assembly checks pass. The adjacent population routine remains
uncredited, with six register-allocation instruction differences preserved.
See [handle-array evidence](notes/game-world-handle-array.md) and
`scratch/world_handle_array_checkpoint.json`.

## 2026-09-27 — Native world-record resource lifetime

Five native lifetime functions add **1,688 matching code bytes**, reaching
**926,512 / 2,607,204 (35.5366%)**, **2,996 / 8,801 functions**, and 649
linked source units. Construction, destruction and the three larger record
array destructors now match. The original tables retain data ownership.

All 649 source units remain exact, the full DOL is byte-identical, and all
23 tests and progress/extent/assembly checks pass. The factory's constructor
identifier is updated without changing its code. See
[lifetime evidence](notes/game-world-lifetime.md) and
`scratch/world_lifetime_checkpoint.json`.

## 2026-09-27 — World record queries and dispatch

Three functions add **872 matching code bytes**, reaching **924,824 /
2,607,204 (35.4719%)**, **2,991 / 8,801 functions**, and 644 linked source
units. Data remains **301,460 / 1,030,936 bytes**. The recovered routines
search flagged records by resolved object, map record names to signed IDs,
and dispatch the world callback through retained handles.

The signed flag declaration preserves all five earlier record loader/resize
matches. All 644 source units remain exact, the complete DOL is byte-identical,
and all 23 tests and progress/extent/assembly checks pass. This continuation
adds four functions, 1,452 code bytes and 12 table bytes. See
[query evidence](notes/game-world-record-queries.md) and
`scratch/world_record_queries_checkpoint.json`.

## 2026-09-27 — Specialized world action-curve lifetime

The nested action-curve destructor and native table add **580 code bytes**
and **12 data bytes**, reaching **923,952 / 2,607,204 (35.4384%)**,
**2,988 / 8,801 functions**, **301,460 / 1,030,936 data bytes**, and 643
linked source units. Four original bytes after the table remain separately
owned alignment storage.

The shared class declaration now covers both construction and destruction;
both existing 80-byte record routines remain byte-exact. All 643 source units
match, the full DOL is byte-identical, and all 23 tests and progress/extent/
assembly checks pass. The original baseline is unchanged. See
[specialized curve evidence](notes/game-world-action-curve.md) and
`scratch/world_action_curve_checkpoint.json`.

## 2026-09-27 — Final world-loader array resize pair

The 80-byte curve-record resize/destructor pair adds **1,180 code bytes**,
reaching **923,372 / 2,607,204 (35.4162%)**, **2,987 / 8,801 functions**,
and 642 linked source units. Data remains **301,448 / 1,030,936 bytes**.
All five record-array resize routines used by the recovered world loader now
match. The specialized inner curve destructor and shared tables retain
original ownership.

This continuation adds six functions and 3,624 code bytes across the three
curve-record pairs. All 642 source units match, the full DOL is byte-identical,
and all 23 tests and progress/extent/assembly checks pass. See
[80-byte record evidence](notes/game-world-curve50.md) and
`scratch/world_curve50_checkpoint.json`.

## 2026-09-27 — Native curve-record arrays

Four routines add **2,444 matching code bytes**, reaching **922,192 /
2,607,204 (35.3709%)**, **2,985 / 8,801 functions**, and 640 linked source
units. Data remains **301,448 / 1,030,936 bytes**. Native C++ curve ownership
reproduces the 60- and 76-byte record resize/destructor pairs and all 91
retained relocations. Original strong tables retain data ownership; discarded
weak helpers and table copies receive no credit.

The full DOL is byte-identical, all 640 source units remain exact, and all
23 tests and progress/extent/assembly checks pass. Existing curve-base code
only gains native constructor/destructor names; its bytes and all earlier
source matches are preserved. See [curve-array evidence](notes/game-world-curve-arrays.md)
and `scratch/world_curve_arrays_checkpoint.json`.

## 2026-09-27 — World record loading and lifetime

Five routines add **2,528 matching code bytes**, reaching **919,748 /
2,607,204 (35.2772%)**, **2,981 / 8,801 functions**, and 636 linked source
units. Data remains **301,448 / 1,030,936 bytes**. Callback dispatch,
reference fixup and binary loading establish five array layouts; native
construction and destruction now match resizing of the 20- and 28-byte
records. All 89 retained relocations match. The compiler's 260 discarded
weak-helper bytes receive no credit.

The full DOL is byte-identical, all 636 source units remain exact, and all
23 tests and progress/extent/assembly checks pass. The baseline and previously
linked source files are unchanged. See [world-record evidence](notes/game-world-record-callbacks.md)
and `scratch/world_records_checkpoint.json`.

## 2026-09-27 — Viewport render-slot management

Three slot-management routines add **1,076 matching code bytes**, reaching
**917,220 / 2,607,204 (35.1802%)**, **2,976 / 8,801 functions**, and 634
linked source units. Data remains **301,448 / 1,030,936 bytes**. Priority and
ordinary insertion, resolved-pointer removal, and world/object render dispatch
preserve the original reference lifetimes and all 30 actual relocations.

Together with viewport storage, this adds eleven functions and 1,812 code
bytes. All 634 source units match, the full DOL is byte-identical, and all
23 tests and progress/extent/assembly checks pass. The original baseline and
previously linked source remain unchanged. See
[slot evidence](notes/game-viewport-slots.md) and
`scratch/viewport_slots_checkpoint.json`.

## 2026-09-27 — Native viewport storage

Eight viewport helpers add **736 matching code bytes**, reaching **916,144 /
2,607,204 (35.1389%)**, **2,973 / 8,801 functions**, and 633 linked source
units. Data remains **301,448 / 1,030,936 bytes**. Recovered C++ bounds,
reference assignment, record arrays and native object lifetime reproduce all
39 retained relocations. The compiler's 172 unreferenced weak helper bytes
are discarded and receive no credit.

The complete DOL is byte-identical; all source units remain exact. All 23
tests and the progress, source extent and assembly checks pass. The original
baseline and previously linked source files are unchanged. See
[viewport storage evidence](notes/game-viewport-storage.md) and
`scratch/viewport_storage_checkpoint.json`.

## 2026-09-27 — Menu insertion, color setup and text formatting

Verified source coverage reaches **915,408 / 2,607,204 code bytes
(35.1107%)**, **2,965 / 8,801 functions**, and
**301,448 / 1,030,936 data bytes**, across 632 linked source units.

Menu3D item insertion and its qualified Root callback add 604 code bytes;
the two menu color-setup routines add 520; the two item-text formatting
routines add 432. Together these six functions add 1,556 code bytes across
six ordinary text-only objects, with no data, weak-code or padding credit.
All 33 actual relocations match. Existing item layouts and generational
handle resolution are reused, preserving the original container, color and
formatting behavior.

The full DOL is byte-identical and all 632 source units match. The original
baseline and all previously linked source files are unchanged by these three
integrations. All 23 tests, progress checks, source extent checks and assembly
audits pass. All 629 candidate source/object hashes and 80 recorded header
hashes are current. See [Menu3D insertion](notes/game-menu3d-item-append.md),
[color setup](notes/game-menu-color-setup.md), [item text](notes/game-menu-item-text.md),
and `scratch/menu_item_text_checkpoint.json`.

## 2026-09-27 — Menu3D configuration parsing

Verified source coverage reaches **913,852 / 2,607,204 code bytes
(35.0510%)**, **2,959 / 8,801 functions**, and
**301,448 / 1,030,936 data bytes**, across 626 linked source units.

The glyph, item and configuration parsers add 4,536 code bytes, three functions
and 575 data bytes. All 273 real relocations match. A complete original-object
scan verifies their shared string/constant ownership. The 356 emitted weak
helper bytes and one original trailing alignment byte receive no source credit.
The source preserves the original eight-bit item flag accumulator, including
its truncation of the FOREVERACCESS bit.

The full DOL is byte-identical; all 626 source units match; all previous source
files and the baseline are unchanged. All 23 tests, progress checks and source
audits pass. The 623 candidate source/object hashes and 70 recorded header
hashes are current. See [parser findings](notes/game-menu3d-parsers.md) and
`scratch/menu3d_parsers_checkpoint.json`. The Menu2D parser remains uncredited
with its preserved two-instruction scheduling difference.

## 2026-09-27 — Native menu constructors

Verified source coverage reaches **909,316 / 2,607,204 code bytes
(34.8771%)**, **2,956 / 8,801 functions**, and
**300,873 / 1,030,936 data bytes**, across 625 linked source units.

The Menu base, Menu2D and Menu3D constructors add 832 code bytes and three
functions. They recover native inheritance, handle initialization and
assignment, empty array setup, and default menu colors. Their 40 actual
relocations match. The 948 emitted weak helper bytes and 68-byte weak table
receive no credit; original strong table/destructor ownership is preserved.

The rebuilt DOL is byte-identical. All 625 source units match, the original
baseline is unchanged, all 23 tests pass, and source extent and assembly-token
audits pass. Existing source edits only rename verified native constructor
and table symbols. All 622 candidate source/object hashes and 70 recorded
header hashes are current. See [constructor findings](notes/game-menu-constructors.md)
and `scratch/menu_constructors_checkpoint.json`.

## 2026-09-27 — Menu lifetime and item insertion

Verified source coverage reaches **908,484 / 2,607,204 code bytes
(34.8451%)**, **2,953 / 8,801 functions**, and
**300,873 / 1,030,936 data bytes**, across 622 linked source units.

The shared Menu destructor, Menu2D item insertion and qualified Root callback
add 992 code bytes and three functions. This milestone also records the
12-byte native name constructor linked before the interruption: together these
four source units add 1,004 code bytes and four functions since the preceding
documented checkpoint, with no new data credit.

The Menu destructor releases its word list and owned handles through the
observed native inheritance chain. Its compiler-generated 120-byte weak base
destructor and 68-byte weak table are discarded in favor of verified original
strong definitions. Those duplicates and all original RTTI/table data remain
uncredited. Item insertion copy-constructs a 188-byte item, grows both arrays
in blocks of 32, and returns the inserted pointer's index.

The rebuilt DOL is byte-identical to the protected original. All 622 source
units have complete native objdiff matches; 619 candidate source/object hashes
and 59 recorded header hashes were checked. The original baseline and all
previously linked source files are unchanged. All 23 tests pass, and source
extent and assembly-token audits pass. Evidence is recorded in
`scratch/menu_completion_checkpoint.json` and
`scratch/menu_completion_link_proof.json`.

The combined glyph/item/configuration parser remains uncredited. Its first
and third functions and all 593 emitted data bytes match, but two adjacent
conversion instructions in the item parser remain reversed. Eight bounded
probes using the recovered vector copy behavior preserve or worsen this known
difference; they are retained under `scratch/game_menu_position_copy/`.

## 2026-09-08 — OS initialization, device interfaces and game-object lifetimes

Verified source coverage reaches **907,480 / 2,607,204 code bytes
(34.8066%)**, **2,949 / 8,801 functions**, and
**300,873 / 1,030,936 data bytes**, across 618 linked source units.
This increment adds 402 functions and 83,360 code bytes.
The original DOL SHA-1 and direct byte comparison pass, all linked source units
have complete native objdiff code/data matches, generated progress checks pass,
and all original C/C++ code in the four baseline source units remains exact.
The baseline is preserved with the accounting correction described below.

Menu2D and Menu3D destruction, render-slot removal/registration, and sine-pulse
updates add eight functions and 1,464 code bytes in two source units. Their
shared Menu base and common call declarations pass complete relocation checks;
528 unreferenced weak helper bytes receive no credit. The InGame native
interface also adds its exact 76-byte virtual table within an existing unit,
leaving the following four bytes as explicit original padding. This checkpoint
adds 1,464 code bytes, eight functions and 76 data bytes; the initial baseline
is unchanged. The three neighboring menu parsers share a compiler-local string
pool, so their isolated proofs remain uncredited until combined ownership and
the full link are verified.

SDK source adds OS initialization and exception-table helpers, the debugger
interface, MetroTRK CPU/register access and transport adapters, stdio and memory
helpers, reset-vector copying, EXI device transfers/UART output, SI controller
transfers/polling/sampling tables, all CARD FAT allocation routines, TEV graphics
state/stage methods, the TPL getter, and the retained `std::exception` destructor/diagnostic and exact class metadata. The CARD
pointer-type correction was checked against all 13 previously integrated CARD
units before and after applying it; their allocated bytes and relocations are
unchanged.

Game source adds 54 typed-handle/member cleanup units, script-file loading and
destruction, group queries/updates and related-object operations, hierarchy and
handle-list destruction, hierarchy commands, console lifecycle/registration/
interpreter callbacks, base-object methods with their virtual table, path
commands and path lookup, bitset clearing/destruction, particle allocation,
Collectable and LoadingScreen metadata/setup/resource methods, screen class
destruction, DamageVolume metadata/lifetime/configuration, ContainerInVolume lifetimes,
ContainerInVolume callbacks/class methods, hierarchy entry actions/reference
assignment/plot setup/list reset/resize/distribution, batch assignment/clearing,
related-status queries, named-world removal, lifecycle and owner setup,
hierarchy construction/RTC resource forwarding, selection actions/ranges,
selection parameter/vector updates, group creation/construction/capacity/activation/deactivation,
named-entry and binding commands, handle flags/retain/reference updates and the
native handle destructor, owned-token return and handle-pool growth,
hierarchy command registration/final-list search, entry reset, and
entry dispatch/replacement with its native conversion pool, and TeleportVolume construction/destruction with exact compiler
exception records. Generated weak duplicates are checked against their original
owners and receive no duplicate credit. Unresolved near-matches stay uncredited.

The related-handle membership, notification and event-query wrappers now match,
together with the Txt, Bitmap, CameraZone and Occluder resource factories.
Native ObjectsBreak, ObjectsBounce and ObjectsMove construction/destruction
covers 704 code bytes. Record-pool destruction, occupied-slot release and record
lifecycle cover all four routines, totaling 1,028 code bytes. Factory caller
spellings were reconciled with native constructor symbols while preserving
their exact original linked bytes.

The group and hierarchy constructors now own 39 verified literal bytes: 27
for the two camera names, including two compiler-emitted internal alignment
bytes, and 12 for `ObjectsGame`. Their following five- and four-byte original
alignment tails remain separate fallback owners. All emitted section extents
and alignments pass the source-extent guard. The 20-byte `SwitchCameraUser %d`
literal remains uncredited because its standalone compiler section alignment
does not fit the original address; no shared-pool ownership is inferred.

Activable/Manipulator lifetime, list append and word-update notification,
activation transitions, and accumulated-float callbacks cover 1,504 code bytes
and ten functions. The lower native interface now also owns its 44-byte virtual
table and three hooks, including their 20 exception/index bytes; two inherited
Root empty hooks add eight more code bytes. Its following four original zero
bytes remain fallback padding. The callback zero float at
`0x8037AC50..0x8037AC54` is compiler-local `@19` after upper table recovery;
the following four bytes remain original padding. All seven affected production
objects pass strict verification with the pointer-shaped handle-lookup return
and known signed-char Root slot1C result.

InGameObjectsManipulator construction, destruction and borrowed-handle methods,
its rotation update and zero-word query, the Activable list constructor and
mode-filtered update, and the upper Manipulator destructor/empty hook add
1,572 code bytes across 12 functions. Together with the five newly recovered
native-interface hooks, this checkpoint adds 1,620 code bytes, 17 functions
and 205 data/BSS bytes across eleven new source units. The rotation update
owns 20 constant bytes and five static-state bytes; its four- and three-byte
original alignment tails stay uncredited. The upper destructor owns 52
exception/index bytes. Its native 64-byte virtual table is now owned by the
existing later callback unit. An inline native destructor moves table emission
to that unit without changing the early strong destructor. Ordinary strong/weak
resolution discards its exact 124-byte destructor duplicate and 52 metadata
bytes; they receive no duplicate credit. The callback unit retains 19 actual
relocations and excludes nine from those duplicate records. This ordinary
source layout resolves the earlier placement cycle, with no forced ordering or
binary patch. Full-DOL and native objdiff checks pass.

The separate [record constructor](notes/game-record-constructor.md) remains
uncredited with four instruction bytes unresolved. The
[list unlink routine](notes/game-owner-list-unlink.md) remains an uncredited
1,316-byte near-match with ten differing bytes in seven instructions; its
original singleton/invalid-neighbor early-return behavior is preserved. The adjacent
[list reorder routine](notes/game-owner-list-reorder.md) has eleven differing
bytes across ten instructions and remains uncredited; its mode-9 append and
subsequent unlink behavior are preserved.

The recovered command registry and existing console parser prove that earlier
hierarchy “engine state” labels were console argument counts and parsed values.
[The console argument note](notes/console-argument-layout.md) records the corrected
names and numeric-validity flags. All 16 affected complete compiled objects are
identical before and after the source-label refinement; source credit is unchanged.

The code denominator now includes the original 7,988-byte MetroTRK native
interrupt-vector image, previously omitted because its boundaries had only
zero-size labels. DTK requires this native executable block to use function-kind
metadata, adding one provisional function-inventory entry. It remains entirely
original fallback with no C/C++ credit; the data denominator is unchanged.
[The vector-image note](notes/MetroTRK-interrupt-vector.md) records the tool
constraint and preserved original boundaries.

Explicit byte alignment on both padding splits and their object symbols keeps
the one-byte OS data tail and seven-byte TRK BSS tail outside source credit while
retaining the original layout. Terminal DOL section padding is likewise excluded.
No original binary, expected hash, emitted instruction, or pinned tool was patched.

An audit of linked C/C++ found an older standalone assembly accessor in the
exception initializer. `GetR2` now remains an explicit eight-byte native fallback;
the two C++ registration routines still match all 116 bytes. Four adjacent linker
alignment bytes also leave source credit. The generated progress therefore
subtracts eight code bytes, one function and four data bytes from historical
credit without changing either denominator or the saved baseline. The
[initializer note](notes/runtime-init-cpp-exceptions.md) records the exact ranges,
full-build result and narrowly checked baseline exception. No other executable
assembly body remains in the audited source tree.

The combined DamageVolume lifetime/configuration source replaces its earlier
callback-only split. Both observed users of its native 1.0f constant now belong
to that unit, allowing the compiler-generated literal to retain local linkage.
The original callbacks remain exact and are counted once; their earlier source
and acceptance manifest are preserved as superseded research history.

The subsequent [section-extent audit](notes/source-section-padding.md) excludes
366 additional trailing data/BSS bytes across 82 source units. The original
bytes now have explicit fallback padding owners, preserving both byte
denominators and every recovered instruction. The retained baseline exposes
moduleobject's one-byte data correction alongside the earlier GetR2 correction.
The build now checks compiler section extents before exporting progress.

## 2026-09-08 — TeleportVolume and debugger command support

Verified source coverage reaches **824,120 / 2,599,216 code bytes
(31.7065%)**, **2,547 / 8,800 functions**, and **294,426 / 1,030,936 data
bytes**, across 423 linked source units. This increment adds 40 functions and
14,276 code bytes. The original DOL SHA-1 and direct byte comparison pass,
all linked source units retain full native objdiff code/data coverage,
generated progress checks pass, and the four original baseline source units
retain or improve their matches.

Game code adds case-folded CRC name hashing and its complete table/BSS,
handle-pool setup and attachment, and nine TeleportVolume methods covering
parameter loading, destination orientation, lifecycle hooks, event dispatch,
property enumeration and lookup. Shared callback descriptors and floating
constants stay original data until all consumers are recovered.

MetroTRK adds 18 message handlers, five file-support/request routines, three
release-build mutex adapters and stop notification. The memory-read handler
remains an uncredited near-match; its table remains original data. The
connection-state variable owns four BSS bytes, and its four alignment bytes
remain a separate original-padding split. No code or data denominator was
reduced, and no original binary or expected hash was changed.

## 2026-09-08 — QSnail, console commands and MetroTRK

The verified build now matches **809,844 / 2,599,216 code bytes
(31.1572%)**, **2,507 / 8,800 functions**, and
**292,922 / 1,030,936 data bytes**, across 412 linked source units.
The original DOL SHA-1 and direct comparison pass, every linked source unit has
full native objdiff code/data coverage, generated progress checks pass, and all
four original baseline source units retain or improve their matches.

This increment adds display lists, projection/viewport operations, graphics
performance counters, and MetroTRK v0.9 initialization, event queues, message
buffers, serial framing and serial output. Game code adds resource decoding, nested-array
resizing, reference marking, channel application, generation-checked handle
access and construction, hierarchy traversal, and console display/screenshot/job
commands. Console constants now have one verified owner, preserving the original
eight-byte section alignment and references from all existing callers.

QSnail initialization, event dispatch, fifteen derived registration hooks and
state accessors are integrated with their exact compiler-generated cleanup data.
The weak destructor duplicate emitted by inline code is independently exact;
normal linker resolution retains the existing strong definition, with no duplicate
progress credit. The linked class-registration/QSnail set now covers 117 functions
and 11,828 code bytes across 71 fragments.

The remaining QSnail behavior, handle lifetime methods, command history and
registration, TEV/color routines, card-block code and TRK message sending remain
uncredited near-matches. The TeleportVolume registration is an isolated exact
candidate awaiting shared constant-pool ownership. Object/padding refinements
update the native report's data denominator; the full code denominator remains
2,599,216 bytes. No original binary, expected hash, instructions or semantic
exception records were changed to obtain a match.

## 2026-09-08 — thirty percent of native code matched

The verified source build now matches **790,060 / 2,599,216 code bytes
(30.3961%)**, **2,404 / 8,800 functions**, and **283,408 / 1,030,944 data
bytes**, across 388 source units. The original DOL SHA-1, direct byte comparison,
native objdiff source audit and generated progress checks pass. Every original
baseline source unit retains or improves its match.

This increment adds texture, indirect-texture and pixel operations, plus bounded
lighting fragments. Game work expands registry lookup, cleanup, slot allocation,
bindings and resource actions; it adds command dispatch/help and class
registration/lifetime methods. The class work covers 98 functions with exact
exception metadata, including the QSnail deleting destructor's exception
specification. The hash-table/key code is fully recovered over its 3,168-byte
range; class tables and other original data retain separate ownership.

Unfinished lighting colors, TEV instruction ordering, card-block code, command
history/registration loops and other near-matches remain outside source credit.
Explicit padding splits preserve the original layout without claiming alignment
bytes as recovered data. Unknown code remains in the unchanged full denominator.
No original executable, expected hash, instruction bytes or semantic exception
metadata was edited to obtain a match.

## 2026-09-08 — graphics, registries and command parser

The verified build matches **773,144 / 2,599,216 code bytes (29.7453%)**,
**2,262 / 8,800 functions**, and **281,127 / 1,030,956 data bytes**, across
322 source units. The protected DOL and source rebuild have zero differences;
native objdiff, generated progress checks and the original source baseline pass.

New source covers memory-card operations, HIO/MCC/FIO/TTY host communication,
and graphics initialization, FIFO, vertex attributes, geometry and framebuffer
operations. Game work adds file lifetime/asynchronous helpers, indexed registries,
time conversion, logger append/command parsing, all 3,168 bytes of the hash-table
and key code, type-registration tables and fourteen class callback hooks.
Each accepted fragment reproduces its owned data and exception metadata.

Refined string-pool boundaries keep external alignment padding separately
attributed. One false function boundary at `0x801F4598` was a trailing return
inside string comparison; the full code denominator remains unchanged. No
original executable or expected hash was changed. Unknown game code, native
assembly and unfinished class data remain outside completion credit.

## 2026-09-08 — more than two thousand matched functions

The source build now matches **707,388 / 2,599,216 code bytes (27.2154%)**,
**2,014 / 8,801 functions**, and **256,217 / 1,030,996 data bytes**, across
267 source units. The original SHA-1, direct DOL comparison, native objdiff
source audit and generated progress checks all pass.

New work adds memory-card unlock support, the first sixteen game file-I/O
functions, the allocator's word-copy helper, and further engine factories.
The factory reconstruction now covers 223 functions with explicit allocation,
construction and observed field initialization. These fragments retain
external dependencies and do not claim complete class recovery.

The math global constructor is now integrated unchanged. Separating the
random generator's state from its code resolves the original section-order
constraint; its signed-byte initialization guard remains explicit C++, and
all 860 original random-code bytes still match. Both the shared literal pool
and global-object storage retain their original placement. No executable,
expected hash, source instruction or semantic exception field was patched.

## 2026-09-07 — audio, allocator and object factories

The verified build now matches **697,184 / 2,599,216 code bytes (26.8229%)**,
**1,972 / 8,801 functions**, and **255,773 / 1,031,000 data bytes**, across
249 source units. The protected original and rebuilt DOL have zero byte
differences; every linked source unit matches its code and owned data.

Audio work completes the retained AX voice/output/studio/profile units and
the mixer, then adds DSP task support and the first CARD BIOS routines. Game
work adds six allocator methods, scalar inverse/transform helpers, and 205
ordinary C++ object factories covering allocation, construction and virtual
table installation. Factory fragments retain their exact constructor and
diagnostic dependencies; they do not claim recovery of entire game classes.

The random-number and scalar-math literals share one original constant pool.
Keeping those definitions together preserves its original alignment. The
math-object global constructor remains an isolated candidate because its
text and storage ordering cannot yet be split faithfully. Unresolved source,
native assembly primitives and DSP program assets remain outside C code
completion. Refined data boundaries and alignment gaps explain inventory
changes; the full code denominator and initial comparison baseline remain
unchanged. Progress exports and the source regression audit pass.

## 2026-09-07 — one quarter of native code matched

The verified source rebuild has crossed 25%: **652,320 / 2,599,216 code bytes
(25.0968%)**, **1,675 / 8,801 functions**, and **152,761 / 1,031,028 data
bytes**, across 199 source units. Unknown code remains in the full denominator.

New work includes audio and audio-memory support, the first AX mixer units,
GBA transport/boot support, runtime exception unwinding and variadic arguments,
scalar matrix operations, the game's seeded generator, and allocator hooks
and startup. The original DOL hash and direct comparison both pass. All linked
source matches its owned code and data, and the original baseline is intact.

The unwinder uses the existing build toolkit's cleanup for two nonsemantic
compiler-generated exception-padding bytes. Raw and cleaned object hashes,
exact offsets and the unchanged semantic fields are documented in its
[unit notes](notes/runtime-gecko-exception.md). Native assembly and unfinished
class data remain explicitly outside these recovered C/C++ fragments.

## 2026-09-07 — runtime, SDK and viewport expansion

The verified build now matches **624,560 / 2,599,216 code bytes (24.0288%)**,
**1,552 / 8,801 functions**, and **129,313 / 1,031,060 data bytes** across
174 source units. All linked source owns matching code and data, and the full
normalized DOL still has zero byte differences from the protected reference.

The expansion covers formatted output, decimal conversion, all 33 retained
math units, locale data, C++ array/exception support, OS scheduling and reset
support, DVD operations, video output, controller input and debugger transport.
Game work adds controller callbacks, lifetime and initialization routines, plus
viewport rendering with a recovered inlined perspective calculation. Shared
game declarations preserve the observed virtual dispatch and member pointers.

Validation: full DOL SHA-1 and direct comparison passed, every source unit's
native objdiff code/data counts matched, progress exports passed validation,
and all eight tooling tests passed. The initial source baseline is preserved.
Refined data extents and explicit alignment gaps account for data inventory
changes; all unknown code remains in the unchanged code denominator. Native
assembly primitives remain separately attributed original fallback code.

## 2026-09-07 — interpreter completed; runtime and engine expansion

The source rebuild now matches **522,844 / 2,599,216 code bytes (20.1154%)**,
**1,194 / 8,801 functions**, and **115,061 / 1,031,124 data bytes**. All 86
registered source units match their owned code and data. The full normalized
DOL remains byte-identical with SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Every code byte in the embedded Python range `0x80130084..0x801AC7FC` is now
linked from source: 509,816 bytes, 1,131 functions and 113,489 owned data bytes
across 63 interpreter/platform units. This includes the evaluator, compiler,
parser and generated grammar, import system, built-ins, exceptions and target
platform support. The game's own code remains a separate workstream.

The verified expansion adds C runtime strings, memory, integer conversion,
scanner callbacks, random numbers, signals and termination; SDK alarm,
arena, audio, cache and context C functions; and eleven game/engine functions,
including nine key-array loaders reconstructed with C++ templates.
Original SDK assembly entry points remain fallback objects and receive no C
completion credit. The context fragments share their diagnostic message
storage to preserve the original translation unit's alignment.

Validation: full DOL hash and direct comparison passed; generated progress
checks passed; all eight tooling tests passed. The saved initial source units
retained or increased their matched counts. Remaining `ninja changes` entries
are zero-denominator percentages on automatically partitioned units, not
source regressions. The unchanged code denominator and original DOL retain all
unknown code; refined data-symbol extents and alignment padding explain data
inventory changes. See individual [unit notes](notes/) for exact boundaries,
compiler settings and provenance.

## 2026-09-07 — complete CPython object units

The full normalized executable remains byte-identical to the reference.
CPython v2.1 source, recovered ABI declarations, and GC/2.0 compiler settings
now reproduce 25 interpreter units plus the two previously matched runtime
units.

| Measurement | Earlier checkpoint | Verified checkpoint |
| --- | ---: | ---: |
| Matched code | 5,816 bytes (0.2238%) | 202,720 bytes (7.7993%) |
| Matched functions | 29 / 8,803 | 539 / 8,801 |
| Matched data | 436 bytes | 26,808 bytes |
| Completed build units | 4 | 27 |

This includes complete class, dictionary, file, frame, integer, floating-point,
complex, long-integer, list, string, and other object units, plus numeric
parsing, state management, struct-member access, and tracebacks. All code and
data owned by these source units match; unclassified original objects remain
in the progress denominator.

The two-function reduction in the inventory corrects heuristic boundaries:
the trailing return instructions at 0x801406E0 and 0x80152F90 belong to
`PyDict_Next` and `long_hash`. No code bytes were removed. BSS pointer sizes
and alignment gaps were also corrected from compiled section evidence.

Validation: standard DOL SHA-1 passed; direct comparison found zero byte
differences; all original source units retained or increased their matched
counts; all eight tooling tests passed. Automatic-unit changes in
`ninja changes` were inspected separately from source regressions. See
[recovered CPython configuration](notes/cpython-abi.md) and individual unit
notes for the compiler, layout, and padding evidence. Later progress is
reported in the generated snapshot.

## 2026-09-07 — matching source and project tracking

The normalized GSQE78 executable rebuilt with SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5` before and after this work.

| Measurement | Starting point | Verified result |
| --- | ---: | ---: |
| Matched functions | 5 / 8,803 | 29 / 8,803 |
| Matched code bytes | 220 / 2,599,216 | 5,816 / 2,599,216 |
| Matched data bytes | 28 / 1,031,283 | 436 / 1,031,283 |
| Completed build units | 2 | 4 |

- Reconstructed the 9-function Python module unit, including its type object
  and string data, and 15 consecutive tuple functions. Tuple tables and free
  lists remain original data outside the incremental text split.
- Verified GC/2.0 with explicit speed optimization; recovered module function
  emission order and per-unit data pooling settings.
- Added generated progress summaries and an inventory of all 8,803 functions,
  with a visible unclassified category and native decomp.dev report artifacts.
- Added contributor guidance, a roadmap, unit notes, reference preparation,
  and input-protection/progress-accounting tests. Preserved the previous README
  as a historical research notebook.

Validation: full DOL SHA check passed, direct comparison found no byte
differences, `ninja changes` reported no match regressions, and all 8 tooling
tests passed. The GitHub workflow was prepared locally; no remote workflow,
repository publication, or decomp.dev registration was performed.
