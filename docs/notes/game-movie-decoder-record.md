# Decoder plane record setup

`src/Game/movie_decoder_record.cpp` owns the 284-byte initializer at
`80290EE8..80291004`, with no data. It selects a 0x38-byte plane record from
the decoder workspace and fills fields used by the larger initializer.

| Offset | Verified field or value |
| --- | --- |
| `00..07` | Preserved, not initialized here |
| `08`, `0A` | Width/height divided by four times the supplied mode |
| `0C`, `0E` | Corresponding block dimension plus two |
| `10`, `16` | Zero, one |
| `12`, `14` | Padded width, padded width plus one |
| `18`, `24` | Zero, four |
| `1C`, `20` | Plane width times four, then plus four |
| `28`, `2A`, `2C` | Plane width, height and their product |
| `30`, `31` | One when the respective byte mode equals two, otherwise zero |
| `32`, `33`, `34` | Two shifted by each flag, then the product of those scales |
| `35..37` | Preserved unknown bytes |

The modes are unsigned bytes; arithmetic follows their ordinary integer
promotions, including signed division. No new mode validation is inferred.
Record size and the dimension/shift offsets have compile-time checks.

GC/1.2.5n reproduces every instruction. Local values for padded width and row
bytes preserve the original reuse across stores; reloading those fields emits
two extra instructions. `scratch/game_movie_platform/verify_decoder_record.py
--production` checks the sole emitted function and compares all text bytes.
There are no allocated relocations or helpers. One nonallocated metadata
reference is checked separately without progress credit.

The full linked DOL is byte-identical. Prior sources, headers, matches, protected
inputs and baseline retain their hashes. All 23 tooling tests and source audits
pass. This partial split adds one provisional build unit and preserves code,
function and data denominators. Original library and complete TU boundaries
remain unconfirmed. See `scratch/movie_decoder_record_checkpoint.json`.
