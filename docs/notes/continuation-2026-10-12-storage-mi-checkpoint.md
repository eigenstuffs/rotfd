# Storage and native virtual-method continuation

This extends the [storage, owner and TRK checkpoint](continuation-2026-10-12-storage-owner-trk.md)
and records the passing standard build on 2026-10-12. Work continues toward
complete source reconstruction.

Additional source-owned zero storage:

| Source | Owned range | Bytes | Observed use |
| --- | --- | ---: | --- |
| `src/Game/scene_gba_loading_storage.cpp` | `80306E28..80318988` | 72,544 | 70,000-byte GBA boot buffer, four 36-byte scene records, 100 24-byte loading particles |
| `src/Game/engine_mesh_render_scratch.cpp` | `80359360..8035D360` | 16,384 | Mesh rendering scratch buffer; the original caller flushes exactly `0x4000` bytes |
| `src/MetroTRK/dolphin_trk_glue.c` | `8033B010..8033D236` | 8,742 | Existing 4,380-byte UART state type and 4,362-byte write buffer |
| `src/MetroTRK/targimpl_state.c` | `8033AB28..8033AFFC` | 1,236 | Existing 1,072-byte CPU state, 148-byte default save state and 16-byte temporary value |

The added storage totals 98,906 bytes. Definitions emit ordinary compiler
NOBITS sections with exact symbol offsets, sizes and visibility. Existing
startup routines remain external; no new static initialization is emitted.
The UART source's previous 1,028 text and 28 initialized-data bytes remain
exact. Deferred C definitions are deliberately ordered to yield the native
BSS order. Two UART trailing bytes and four target-state trailing bytes keep
separate original padding ownership. The local saved exception ID and
preceding target control state retain their original visibility/ownership.
No padding is credited as a field or array element.

The [native virtual-method findings](continuation-2026-10-12-native-owner-hook.md)
add another 328 code bytes across 41 genuine compiler-generated adjustment
thunks. They preserve earlier matching primaries, neighbor leaves, exception
records and complete original vtables. Consolidating old source splits into
C++ groups changes provisional build-unit counts without changing any byte or
function denominator. Another 56 already source-owned exception bytes now
compare exactly under native symbol identities.

`ninja changes` now supplies full baseline/current reports to
`tools/changes_fmt.py`. Strict ownership receipts reconcile a retired complete
source unit only when all of its positive section ranges and all functions
are uniquely covered by complete current source in the same native module.
New owners must match fully. Gaps, overlaps, aliases, ambiguous identities,
malformed records and extent/module/binding changes fail closed. Aggregate
and still-present-unit regressions remain visible. Prior data scores may be
imperfect only when the old unit was already completely linked from source;
replacement data must compare exactly. The native reports and baseline are
read unchanged. Fifty retired owners are reconciled in this checkpoint.
The baseline is deliberately not a Ninja dependency because its explicit
snapshot target would otherwise overwrite the pre-edit comparison.

Acceptance evidence is in `scratch/continuation_20261012_b/`:
`build-next-promote.log` records the original DOL SHA-1 PASS,
`changes-next-promote.log` has no regressions, `extents-next.log` passes 4,816
linked source units and 5,817 data/BSS sections, and `tests-next.log` passes all
66 tests. Native allocation and MI proof scripts bind source inventories to
the current ELF and unchanged executable; unclaimed padding/helpers remain
outside the source credit.

The generated checkpoint is 1,859,628 / 2,607,776 matching code bytes,
7,802 / 8,803 functions and 795,394 / 1,030,936 matching data bytes. Compared
with this continuation's saved starting report, that is 2,456 code bytes,
51 functions and 252,652 matched data bytes gained. Of the data improvement,
252,596 bytes are newly source-owned and 56 bytes improve earlier data scores.
The remaining 748,148 code bytes and 235,542 data bytes still require work.
