# Audio voice shutdown

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80287718` at `0x80287718` is reconstructed as ordinary C++ in
`src/Game/audio_voice_shutdown.cpp`. It stops, releases the mixer channel,
and frees each of the 32 voices in the owner's channel array, clears their
pointers, shuts down AX, runs the owner cleanup, and logs the result.
The private partial layout records only the observed channel and logger
fields; it does not claim the complete original class declaration.

The GC 1.3.2 production flags reproduce all 196 original text bytes and all
ten actual external relocations. The function emits no other allocated
sections, weak helpers, or local data. The full original exception-index,
constructor, and destructor table scans contain no references to this
function. Its original external string remains with the assembly owner.
The frozen manifest and isolated proof are in
`scratch/game_audio_runtime_controls/final_integration.json`.

This text-only split awaits the central production build and original DOL
hash check. Other audio routines and the original translation unit's data
remain outside this source split.
