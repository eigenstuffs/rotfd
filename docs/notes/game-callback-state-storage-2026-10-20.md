# Callback and actor state storage, 2026-10-20

Six `.sbss` units now replace their original assembly providers:

| Original range | Source | Verified storage |
| --- | --- | --- |
| `80377618..80377620` | `src/Game/callback_registry_keys_80377618.c` | Two four-byte class binding slots used by existing callback accessors and teardown. |
| `80377620..80377628` | `src/Game/callback_group_slot_80377620.c` | Eight-byte callback group slot; existing code uses its first word as a nullable group pointer. |
| `80377640..80377648` | `src/Game/callback_dispatch_counter_80377640.c` | Eight-byte dispatch state slot; existing code uses its first word as a shared counter. |
| `80377648..80377650` | `src/Game/callback_registry_keys_80377648.c` | Two four-byte registry keys used by existing registration, lookup, and forwarding code. |
| `80377688..803776B8` | `src/Game/callback_group_bundle_storage_80377688.c` | Six original global slots for callback groups, keys, and the shared effect handle (48 bytes). |
| `803776B8..803776C0` | `src/Game/actor_monitor_and_record_storage.c` | Four-byte actor monitor pointer and four-byte selected timed-record pointer. |

The five eight-byte native objdiff targets each have exactly eight `.sbss`
bytes, the original GLOBAL symbols at the original offsets and sizes, 100%
data match, and no extra allocated sections or relocations. Neighboring
original storage remains under its existing ownership. Consumers preserve
their original small-data relocations in the full link. The two later slots
are single original eight-byte symbols; their second words are not yet typed
beyond four-byte state, so the sources use provisional two-word arrays.

The later 48-byte bundle has six GLOBAL symbols at offsets 0, 8, 12, 24, 32,
and 40 with the original sizes 8, 4, 12, 8, 8, and 8. Native objdiff reports
100% data and symbol matches, and no extra allocated sections or relocations.
The 12-byte slot requires `-sdata 16` to stay in the original `.sbss` section.
The rebuilt DOL retained the expected SHA-1 after this bundle, increasing
matched data from 913,825 to 913,873 bytes. The two later slots also pass
native objdiff and the full DOL hash check, bringing matched data to 913,889
bytes. No code bytes or functions are claimed by these storage units.

GC/1.2.5n emits these tentative definitions in reverse declaration order,
so each source lists its higher-address symbol first. The first natural-order
probe swapped `lbl_80377648` and `lbl_8037764C`, failed the DOL hash, and
was corrected before acceptance. The final standard rebuild passes the
original DOL SHA-1. Matched data rises from 913,801 to 913,825 bytes; no
code bytes or functions are claimed.
