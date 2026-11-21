# Platform audio controls

Five partial source units reconstruct **1,056 code bytes / eight functions**:

| Source | Native range | Code bytes / functions |
| --- | --- | ---: |
| `platform_audio_stream_path.cpp` | `8028701C..80287080` | 100 / 1 |
| `platform_audio_fade.cpp` | `80287080..80287178` | 248 / 1 |
| `platform_audio_levels.cpp` | `80287454..80287554` | 256 / 2 |
| `platform_audio_mute.cpp` | `80287554..802876AC` | 344 / 1 |
| `platform_audio_sound_mode.cpp` | `802876AC..80287718` | 108 / 3 |

The stream-path wrapper ignores null names, normalizes separators into a
128-byte stack buffer, appends the original `.sgc` string, and forwards the
result and mode to the original secondary-interface helper. The five-byte
string and its three following alignment bytes retain original ownership.

Fade setup first rejects an unresolved handle, then calls the original
selection helper. A negative result returns minus one. For nonnegative fade
duration it sets channel mask `400`, stores the reciprocal duration at `14`
and one at `18`; negative duration stops the AX voice immediately. The native
code permits zero duration and introduces no separate check. Unordered floating
comparisons follow the ordinary C comparison behavior observed in the native
routine. The selected index is returned.

The two volume setters store their values at owner offsets `414` and `418`,
call the matching scalar clamp, and discard its result. They then read the
stored value again and derive attenuation: zero above one, -900 at or below
zero, otherwise 150 times the matching logarithm wrapper. Separate original
secondary-interface methods receive the float attenuation. Keeping the native
ignored return is necessary to reproduce behavior and bytes.

The mute routine walks 32 channels. Active streaming channels (mask `200`)
set or clear secondary flag one from input mask four; this native loop means
the last such channel determines that flag. Other active channels set or clear
mask two using input mask two for channels with mask `10`, or input mask one
otherwise. Input mask eight controls secondary flag two, then the original
secondary helper receives the result. GC/1.3.2 reproduces the native two-entry
loop unrolling without source duplication.

The sound-mode getter returns a signed-byte boolean for OS sound mode one.
The setter maps nonzero integer input to OS mode one and zero to mode zero.
The final empty hook emits its native four-byte return. Full original class
hierarchy, unused virtual slots and exact original source filename remain
unproven; these functions use the existing physical audio owner/channel views.

Strict verification in `scratch/game_platform_audio_controls/verify.py`
applies **33 actual relocations**, checks all symbol bindings and section
extents, and compares every retained byte with the immutable original DOL.
No data, helper or padding is emitted or credited. All earlier source and
headers are unchanged. Final linked byte proof and acceptance are recorded
in `scratch/platform_audio_controls_link_proof.json` and
`scratch/platform_audio_controls_checkpoint.json`. Original channel acquisition
at `80287178..80287454`, spatial mixing and underlying streaming operations
remain outside these partial source splits.
