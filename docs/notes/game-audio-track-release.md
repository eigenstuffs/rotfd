# Audio track release

`src/Game/audio_track_release.cpp` reconstructs **324 code bytes / one
function**, `fn_8023B720` at `8023B720..8023B864`.

For a nonnegative index it clears the selected track's running byte and timer,
then replaces each of its three handles with an empty handle. Each replacement
preserves construction, explicit zeroing, manager decrement/copy/increment,
and destruction. Separate scoped temporary handles reproduce all three native
stack slots and lifetime sequences. The native routine has no upper-bound
check. Its four-byte zero constant at `8037B318` retains original ownership.

The source uses the shared twenty-eight-byte track view and the pre-existing
physical owner interface declaration. It does not change accepted headers or
assert a complete original class hierarchy. Previously accepted reset,
completion cleanup and loading routines now call this source implementation.

Strict verification in `scratch/game_audio_track_release/verify.py` applies
**15 actual relocations** and verifies all 324 retained bytes against the
immutable DOL. An unused 84-byte weak handle destructor is accounted for
separately, excluded from the split and progress, and verified absent from the
final ELF. No data or padding is emitted or credited. Full linked and regression
evidence is in `scratch/audio_track_release_link_proof.json` and
`scratch/audio_track_release_checkpoint.json`. Neighboring spatial/object
callbacks and track selection remain original.
