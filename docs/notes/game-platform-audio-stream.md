# Audio streaming levels, queries and close

Two partial source units reconstruct **1,060 code bytes / seven functions**:

| Source / entries | Native range | Code bytes / functions |
| --- | --- | ---: |
| `platform_audio_stream_levels.cpp` | `8028970C..80289968` | 604 / 4 |
| `platform_audio_stream_queries.cpp` | `8028A6C4..8028A88C` | 456 / 3 |

The new physical state view contains six 92-byte records beginning at `0`,
with flags at record offset `54`; six 60-byte voice states begin at `228`.
Each voice state exposes two AX voice pointers. Music uses the pair at `318`
and `31C`, while effect-level and pause loops use the first four voice states.
A thread queue resides at `650`, file-info storage at `4A28`, a signed open
byte at `4A68`, music/effect attenuation floats at `4A6C`/`4A70`, and six
sixteen-byte name slots at `4A74`. The complete class and all intervening
fields remain unknown; these physical names and extents are inferred.

The wake helper forwards its queue to `OSWakeupThread`. Effect-level changes
store the float and apply its integer truncation to each of four records that
has mask two set and mask `80` clear. Music-level changes do the same for both
music voices when record four has those masks. The secondary mute helper uses
input mask two for the music pair, applying the native literal **-904** while
muted and restoring separately read/truncated stored attenuation otherwise.
It sets/clears record mask `80`. Input mask one stops the first four active
effect voices; clearing that input restarts them and clears their mask `80`.
No clamp or additional AX voice null guard is introduced.

The indexed status helper returns a signed-byte **mask value two**, rather
than normalizing it to a boolean. It has no bounds check. The name query rejects
null, locks the original global mutex at `8035E958`, and walks the original
registry head at `803780D0`, with links at node offset `10C`. A matching
case-insensitive registry entry unlocks and returns one. Otherwise it unlocks,
searches six local name slots with a sixteen-character comparison, and returns
the selected record's signed-byte mask value or zero when absent. The inline
name-search helper reproduces the native branch/return shape.

Close examines all six records only when the open byte is nonzero. Records
with mask two and the high flag bit have their name cleared and are passed to
the original release helper. It then closes the DVD file, clears the open byte,
and returns one, including when already closed. Registry storage, mutex and
head pointer, original release/setup methods and owned state initialization
remain outside these source splits.

The accepted path wrapper and flush wrapper previously declared these callees
with void results. Their declarations now reflect the signed-byte query result
and integer close result; the callers continue to discard them, preserving
all 232 earlier code bytes. Their source was strictly reverified. Existing
shared headers and unrelated accepted source remain unchanged.

`scratch/game_audio_stream/verify.py` applies **25 actual relocations**, including
the registry head's real SDA register/base, and validates every allocated code
byte and symbol. No data, helper or padding is emitted or credited. Final
linked evidence includes both new units and the unchanged callers, in
`scratch/platform_audio_stream_link_proof.json`; full acceptance is recorded in
`scratch/platform_audio_stream_checkpoint.json`. These remain partial source
splits with no proven original translation-unit filename or complete hierarchy.
