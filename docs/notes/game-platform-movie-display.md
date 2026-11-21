# Movie display worker

`src/Game/platform_movie_display.cpp` owns the 636-byte thread entry at
`8028D8BC..8028DB38`, with one function and no data. It is a partial text split
from the movie-platform region supported by the `GCMovie_Z.cpp` filename string.
The surrounding decoder bodies and conversion routine remain original. The
[storage unit](game-platform-movie-storage.md) now supplies the shared pool;
[decoder layout helpers](game-movie-decoder-layout.md) have independent ownership.

The worker waits on the semaphore at thread-pool offset `4630`, selects decoder
calls for mode values `10`, `20` and `30`, swaps the observed planar buffer
pointers, and signals the semaphore at `463C`. In mode `10`, the decoder's last
argument is the saved pre-swap pointer at `80378110`, which differs from the
new value of that global. This behavior is retained explicitly in source.

It alternates framebuffers for modes other than `30`, clears a framebuffer when
its corresponding shared flag is set, computes a centered output offset from
the original video-mode dimensions, and calls the original YUV converter.
After five frames it clears the platform black byte and updates GX/VI state.
A shared counter skips every sixth framebuffer submission. Each iteration ends
with the original callback at vtable slot `20`, using the original float at
`8037B91C`.

The typed physical views identify a four-byte decode-mode prefix, a callback
vptr at `1C`, and global callback/platform pointers at `154/15C`. Checked sizes
describe only the borrowed prefixes, without reconstructing unknown methods,
global-object extent or original class names. Shared state is not credited.

GC/1.3.2 reproduces all 636 bytes and 64 actual relocations from ordinary C++.
`scratch/game_movie_platform/verify_display.py --production` checks all emitted
bytes; inline fill and virtual declarations emit no helper bodies. The full
DOL and linked ELF checks, all previous source/header hashes and matches,
immutable baseline, source audits and 23 tests pass. Splitting the middle of an
original unit adds two provisional build units without changing the code,
function or data denominators. See
`scratch/platform_movie_display_checkpoint.json` for acceptance evidence.
