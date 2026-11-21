# Video transition allocation cleanup

`src/Game/platform_video_cleanup.cpp` owns the 112-byte routine at
`8028D6FC..8028D76C`. The partial text split adds one code function and no
data. Its name and original TU boundary remain provisional.

The routine reads the allocation pointer at object offset `50`, frees it
through the original allocator at `801EF5C8` when present, and clears that
field. It calls the original `fn_801C9ABC` with the same object. When the
signed-byte enabled flag at `5C` is set, it invokes the method at virtual
table slot `18`. No behavior is inferred for the still-original callee or
unknown virtual methods.

The typed physical view places the virtual interface at offset `08` using
an eight-byte prefix, then retains allocation and enabled/black offsets.
Its checked C++ view is 96 bytes after alignment, without claiming the complete
original class size, name, constructor or virtual table. The original table,
allocator and other object fields remain outside source ownership.

GC/1.3.2 reproduces the routine on the first ordinary C++ probe.
`scratch/game_video_transition/verify_cleanup.py --production` checks all 112
bytes and four actual relocations. The native indirect call and object offsets
match exactly, with no emitted helpers or owned data. The linked ELF proof,
byte-identical DOL, prior source/header hashes and matches, original baseline,
source audits and all 23 tests pass. See
`scratch/platform_video_cleanup_checkpoint.json` for the accepted stage.
