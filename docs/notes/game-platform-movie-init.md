# Movie platform initialization

`src/Game/platform_movie_init.cpp` owns the 168-byte initializer at
`8028D76C..8028D814`, with one function and no data. The nearby original string
at `802AF7B0` names `GCMovie_Z.cpp`; it supports movie-platform ownership but
does not establish a complete original translation-unit boundary.

The routine calls `fn_801C9AC0` and returns zero when that call fails. It queries
the TV format, selects the original `GXNtsc480Int` mode, and stores its pointer
at `80378120`. Framebuffer bytes at `80378104` are twice the mode height times
its width rounded up to sixteen pixels. It clears enabled/black at `5C/5D` and
the word at `48`, allocates 96 bytes with 32-byte alignment through the original
allocator, saves the pointer at `50`, and returns one. The original callee and
allocation-failure behavior are preserved without additional inferred checks.

The checked physical object view is 96 bytes; the borrowed video-mode prefix
locates width at `04` and height at `08`. These views do not claim recovered
class names or complete video-mode ownership. Reading the newly stored global
mode pointer for the framebuffer calculation resolves the native scheduling.
The heap, strings, video mode and shared words remain original data.

GC/1.3.2 matches all 168 bytes and 13 actual relocations.
`scratch/game_movie_platform/verify_init.py --production` accounts for every
emitted byte with no helpers or data. The full DOL and linked ELF checks,
previous match/hash preservation, immutable baseline, source audits and all
23 tests pass. The provisional build-unit count grows by one; code, function
and data denominators are unchanged. See
`scratch/platform_movie_init_checkpoint.json` for acceptance evidence.
