# Movie clipping and reciprocal tables

`src/Game/movie_decoder_tables.cpp` owns the 864-byte initializer at
`80290B88..80290EE8` and 2,624 bytes of BSS at `80373140..80373B80`.
This partial unit does not establish the original decoder library or complete
translation-unit boundary. Workspace initialization and the first frame decoder
have separate accepted units; the other decoding routines remain original work.

Three arrays preserve the original addresses and extents:

| Symbol | Type and extent | Initialized values |
| --- | --- | --- |
| `lbl_80373140` | 512 unsigned bytes | Clamp values -128 through 383 to 0..255 |
| `lbl_80373340` | 16 signed words | Zero at index 0; `(4096/(i<<4))<<4` otherwise |
| `lbl_80373380` | 512 signed words | Zero at index 0; `4096/i` otherwise |

The two reciprocal arrays previously occupied one original 0x840-byte symbol.
Separating them preserves every address and byte while expressing the distinct
loops. Four-byte signed integers and array extents are checked at compile time.
The compiler unrolls the ordinary loops; no instruction bytes are embedded in
the source.

GC/1.2.5n with `-pool on` matches all emitted text and BSS. A combined structure
view folded table-base calculations differently. An explicit value counter
from -128 to 383, incrementing the index before the value, restores the native
clipping schedule. Three separate pooled arrays restore the reciprocal cursor
addresses and registers. Earlier variants are retained as private probes.

`scratch/game_movie_platform/verify_decoder_tables.py --production` checks
the two actual address relocations, sole emitted function and all three BSS
objects. Its nonallocated compiler-metadata reference is checked separately
and receives no code or data credit. No masks, patched objects or helper bodies
are used.

The linked ELF proof, byte-identical DOL, unchanged original SHA-1 and baseline,
all prior source/header hashes and matches, source audits and all 23 tests pass.
Code, function, data and native unit denominators are unchanged by this stage.
See `scratch/movie_decoder_tables_checkpoint.json` and the combined
`scratch/movie_platform_session_checkpoint.json`.
