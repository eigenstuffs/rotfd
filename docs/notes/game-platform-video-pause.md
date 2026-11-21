# Video transition pause

`src/Game/platform_video_pause.cpp` owns the 404-byte function at
`8028D568..8028D6FC`, with no owned data or emitted helper bodies. This partial
text split borrows the physical state view from the accepted resume unit.
Original class and translation-unit boundaries remain provisional.

When enabled and not already paused, it sets the paused byte at `00`, logs
transition messages, and suspends the thread at `8036E9D0`. It clears the shared
framebuffer twice with packed YCbCr `00800080`, flushing the cache and performing
VI synchronization after each clear. It waits for GX completion, configures the
game's video mode at offset `294`, and flushes/waits for retrace. The independent
black byte at `5D` requests `VISetBlack(0)`.

An ordinary inline fill helper resolved the earlier framebuffer cursor/end
register mismatch. GC/1.3.2 now reproduces all 404 bytes and 31 actual
relocations. `scratch/game_video_transition/verify_pause.py --production`
accounts for the entire emitted object; no masks, assembly or object patches
are used. Shared strings, mode and framebuffer state remain original. Thread
storage is now supplied by the independent [storage unit](game-platform-movie-storage.md).

The linked ELF proof, byte-identical DOL, unchanged previous source/header
hashes and matches, immutable baseline, source audits and all 23 tests pass.
See `scratch/platform_video_pause_checkpoint.json` for acceptance evidence.
