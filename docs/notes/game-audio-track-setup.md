# Audio track lookup and generic setup

Two partial source units reconstruct **1,108 code bytes / two functions**:

| Source | Native range | Code bytes |
| --- | --- | ---: |
| `audio_track_find.cpp` | `8023AF08..8023B03C` | 308 |
| `audio_track_setup.cpp` | `8023B03C..8023B35C` | 800 |

Lookup walks all 32 tracks and returns the first running track whose resolved
owner and first-object pointers equal the requested resource and object. Both
sides use the native unchecked handle index/generation lookup. Null resolved
pointers compare equal; no extra null guard is inferred. An unmatched search
returns minus one. The duration argument is unused by this implementation,
although the native fade caller passes it.

Generic setup first tests whether the first object resolves. If so, it calls
the original spatial/object relationship helper with both resolved objects
and rejects a nonzero signed-byte result. It then searches running tracks for
a resolved resource/first/second triple; a duplicate returns its index plus 32.
Otherwise it calls the matching track selector, marks that track running and
assigns all three handles through the shared manager decrement/copy/increment
sequence. The flag argument is unused here. The selected index is not checked
again before track access, matching the original implementation.

The equality helper explicitly resolves stored handles before requested
handles. The last callback argument uses explicit index/generation locals and
early returns to reproduce the native register scheduling. Both choices preserve
the inferred operation and all native comparisons, without authored assembly.
Names and physical class views remain inferred; no complete original hierarchy
or translation-unit boundary is claimed. The final handle reference in the
setup interface represents the native borrowed view of caller-owned storage.

The previously accepted fade wrapper's third argument was labeled an integer
mode. Its callee now establishes that this register contains an object-handle
reference. The caller declaration and parameter are corrected accordingly,
without changing any compiled bytes or earlier progress credit. All five prior
control units were recompiled and strictly verified; the other four sources and
all accepted shared headers are unchanged.

Strict evidence in `scratch/game_audio_setup/verify.py` applies **15 actual
relocations** and checks every emitted allocated byte and symbol. The units emit
no owned data, helper or padding. Final linked-byte proof includes both new
functions and the unchanged 248-byte fade caller; full acceptance is recorded
in `scratch/audio_track_setup_link_proof.json` and
`scratch/audio_track_setup_checkpoint.json`. Other audio relationship callbacks,
original tables, underlying streaming methods and the private platform
acquisition conversion-pool ownership remain unfinished.
