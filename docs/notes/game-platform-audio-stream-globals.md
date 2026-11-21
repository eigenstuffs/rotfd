# Audio streaming mutex and registry-head storage

`src/Game/platform_audio_stream_globals.cpp` owns **28 matching BSS bytes**:

| Symbol | Native range | Source definition |
| --- | --- | --- |
| `lbl_8035E958` | `8035E958..8035E970` | 24-byte mutex |
| `lbl_803780D0` | `803780D0..803780D4` | four-byte registry-head pointer |

The mutex layout follows the already matched SDK `src/dolphin/os/OSMutex.c`:
eight-byte thread queue, thread-owner pointer, signed count, and next/previous
mutex links. The streaming code uses this address for lock/unlock calls. Its
registry query establishes the head-pointer type and each node's next link at
`10C`. Both global definitions have native static zero initialization, with no
constructor, destructor-registration record or runtime helper emitted.

The streaming header now declares the mutex as a typed object, replacing its
previous opaque array view. Query calls take the object's address explicitly;
all 456 query/close bytes and all 604 streaming level/control bytes remain exact.
Both affected source units were recompiled and strictly reverified, with updated
candidate and header hashes. All unrelated accepted headers and source remain
unchanged. The new definitions retain strong global binding for all original
and source callers.

`scratch/game_audio_stream_globals/verify.py` checks both object symbols,
section type/size/alignment and their ranges inside the immutable DOL's zeroed
BSS extent. The compiler emits exactly 24 `.bss` bytes and four `.sbss` bytes,
with eight-byte section alignment. No trailing alignment is owned or credited;
original storage beginning at `803780D4` is preserved. No text, initialized data,
helper, relocation or padding is emitted by this unit.

Final linked-address/zero-storage proof and acceptance are in
`scratch/platform_audio_stream_globals_link_proof.json` and
`scratch/platform_audio_stream_globals_checkpoint.json`. The registry nodes,
larger streaming state, thread/initialization implementation and adjacent
original data remain unfinished. This storage split does not establish the
complete original source filename or translation-unit boundary.
