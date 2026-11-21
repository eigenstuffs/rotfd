# Video transition resume and enabled query

`src/Game/platform_video_resume.cpp` owns the 148-byte routine at
`8028D4CC..8028D560` and the adjacent eight-byte enabled-state getter at
`8028D560..8028D568`. This partial text split adds 156 code bytes and two
functions, with no owned data. Names and original TU boundaries remain
provisional; surrounding transition routines and shared storage are separate.

The physical state view identifies signed-byte paused, enabled and black
fields at offsets `00`, `5C` and `5D`. When enabled and paused, the routine
configures the original video-mode pointer, flushes and waits for retrace,
sets both original shared words at `803780F0` to one, clears video black,
flushes and resumes the original thread at `8036E9D0`. It then clears paused.
The final black flag requests `VISetBlack(1)` independently of that branch.
The adjacent getter returns the raw enabled byte as an unsigned byte.

The header preserves these observed offsets and borrows the mode pointer,
shared words and thread object. It supplies no data ownership or original
method-table reconstruction. GC/1.3.2 reproduces both bodies from ordinary
C++ on the first probe. `scratch/game_video_transition/verify_resume.py
--production` proves all 156 code bytes and 12 real relocations. The full DOL
and linked ELF proofs pass without masks, assembly or helper bodies. See
`scratch/platform_video_resume_checkpoint.json` for the accepted stage.

The adjacent 404-byte pause routine at `8028D568..8028D6FC` is now independently
[accepted](game-platform-video-pause.md). An ordinary inline fill helper
resolved the framebuffer cursor/end register difference. Earlier unsuccessful
private probes remain preserved under `scratch/game_video_transition/`.
