# Audio track selection

`src/Game/audio_track_select.cpp` reconstructs **652 code bytes / one
function**, `fn_8023B864` at `8023B864..8023BAF0`.

The selector begins at the signed integer stored at owner offset `400` and
scans through track 31. It returns the first inactive track immediately.
Otherwise it records the running track whose timer exceeds the greatest value
seen, initially the borrowed zero constant at `8037B318`. For a recorded index
in `0..31`, it clears that track through an inline release operation and returns
its index. With no eligible greatest timer it clears track zero and returns zero.
The native code does not add a guard against a negative starting index.

Inline release preserves the nonnegative-index check, running/timer reset,
and the three scoped empty-handle construction, assignment and destruction
sequences established by the matching release routine. The constant zero
index in the fallback removes its redundant index check through ordinary
compiler optimization. The complete native class hierarchy and original
translation-unit boundary remain unproven.

Strict proof in `scratch/game_audio_track_select/verify.py` applies **31 actual
relocations** and verifies all 652 code bytes against the original DOL. No data
or padding is emitted or credited. An unused 84-byte weak handle destructor
is separately accounted for, excluded from progress and checked absent from
the final ELF. Existing source and headers remain unchanged. Full linked byte
verification and acceptance are recorded in `scratch/audio_track_select_link_proof.json`
and `scratch/audio_track_select_checkpoint.json`. The source selector now
supplies the previously accepted audio loading caller. Other selection/setup
methods, spatial callbacks and original shared data remain unfinished.
