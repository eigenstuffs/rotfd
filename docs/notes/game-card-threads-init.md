# Memory-card thread initialization

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/card_threads_init.cpp` reconstructs `fn_80278EC4`, original `.text`
range `80278EC4..80279044` (384 bytes), as ordinary C++.

The initializer creates the original 96-byte local resource guard, initializes
the card library, reads two external configuration keys and configures optional
transfer values. It allocates two aligned 4 KiB stacks, initializes the owner's
queue and mutex, creates the owner worker and resumes it, then creates the
shared worker. Each exit invokes the existing guard destructor with native
argument -1. Failed thread creation returns 0; success returns 1. External
configuration and thread-creation results retain their native signed-byte ABI.

The local partial owner view records the existing thread at 0x38, queue at
0x350, mutex at 0x358, stack pointer at 0x374 and configuration words at
0x414/0x418. It emits no storage. The diagnostic/configuration pool is addressed
as an external array object before casting to a character pointer; this retains
the native common base without forcing a register or introducing volatile
access. Existing shared headers are unchanged.

Run `python3 scratch/game_card_threads_init/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce every allocated byte, exact function extent and
all actual relocations. The verifier checks relocation site, kind, symbol,
addend and target, including SDA21 section/base/displacement, then compares the
relocated instructions against the protected original DOL.

No weak helpers, initialized data, BSS, padding or other allocated sections are
emitted. Thread storage, stack globals, pooled strings, allocator and helper
functions retain external ownership. Original extabindex, `.ctors` and `.dtors`
audits find no overlap or reference into the range. Candidate, relocation and
original-metadata JSON preserve hashes and dependencies. This partial text-only
split leaves neighboring functions and data external. Central integration must
pass the full DOL hash, native objdiff, source-extent and regression checks.
No new symbols, owned data or special flags are needed.
