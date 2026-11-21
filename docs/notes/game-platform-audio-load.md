# Platform audio resource loading and track setup

`src/Game/platform_audio_load.cpp` reconstructs **604 code bytes / one
function**, `80286D9C..80286FF8`, and **eight data bytes**, the `DSP` and `WAV`
extension strings at `8037B8C0..8037B8C8`.

The loader compares the final three filename characters with the two extension
strings through the already matching case-insensitive comparison. It normalizes
separators into a 128-byte field, splits the filename into a neighboring
16-byte basename field and separate 16-byte suffix, rejoins the basename and
suffix, and uppercases the result. This 144-byte physical aggregate is inferred
from its native stack extent and by-value diagnostic copy. Its name and fields
are provisional. The native code has no short-name guard or added buffer check.

It submits the normalized name, extension kind, and flag bit one to the
original secondary-interface resource loader. For a successful DSP resource,
it asks the original channel-selection helper for an index. On failure it
passes the complete 144-byte aggregate by value to the diagnostic routine,
then releases the uppercase basename. This reproduces the native eighteen-pair
copy and variadic call; the diagnostic format and loader/selector implementations
still belong to original objects.

On success it marks the selected twenty-eight-byte track running, resets its
timer and owner handle, and assigns both object handles through the shared
manager's decrement/copy/increment sequence. A scoped empty handle preserves
construction, explicit zeroing and destruction in their native order. Channel
flags become `381`; fields `04` and `08` become zero, `0C` and `00` become
one, and `1C` stores the returned resource identifier. No new bounds, null or
capacity checks are inferred.

GC/1.3.2 reproduces the entire routine after applying **30 actual relocations**.
Both strong four-byte string definitions match their native bytes. Their
emitted `.sdata2` extent is exactly eight bytes, aligned to eight. An unused
84-byte weak `OwnerHandle` destructor is accounted for separately, excluded
from the source split and progress, and checked absent from the final ELF.
No padding is credited. Existing accepted sources and shared headers are
unchanged.

Strict proof is in `scratch/game_platform_audio_load/verify.py`; final linked
proof and full acceptance are in `scratch/platform_audio_load_link_proof.json`
and `scratch/platform_audio_load_checkpoint.json`. This is a partial split,
with no proven original source filename or translation-unit boundary. Spatial
mixing, underlying streaming operations, general channel acquisition and shared
original tables remain unfinished.
