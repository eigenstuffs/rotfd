# Platform audio reset and channel completion

Two partial source units reconstruct **520 code bytes / four functions**:

| Source / entry | Native range | Code bytes |
| --- | --- | ---: |
| `platform_audio_reset.cpp`, two float getters and reset | `80286288..80286398` | 272 |
| `platform_audio_channel_cleanup.cpp`, completed-channel cleanup | `80286738..80286830` | 248 |

The getters return owner floats at `418` and `414`. Reset walks all 32
forty-byte channel records through the pointer at owner offset `410`.
For entries with flag bit zero set, it stops a non-null AX voice when its
native state is one, restores six scalar/flag fields, and then invokes
`fn_8023B720` for every index, including inactive entries. After the loop it
calls the matching ARAM reset through the global owner pointer at `18C`.

Completion cleanup accepts any nonnegative index; no upper-bound check is
present. For channels with mask `200`, it tests the original streaming helper
at owner offset `420` using the channel identifier at `1C`. Otherwise it
reads the AX voice state directly, without a null guard. When complete, it
invokes `fn_8023B720`, restores four floats, clears the flags and sets the
identifier to minus one. The native signed-byte intermediate is preserved.

The new header shares the already verified AX voice layout and object-manager
declaration. The AX state resides at `146` in that layout. The owner's other
fields and complete native class hierarchy remain unknown; its declaration
is a physical view sufficient for these functions. Existing shared headers
and source are unchanged. Constants `8037B898`, `8037B89C`, and `8037B8A0`
are borrowed from original small data; their original ownership is retained.
Other audio functions, channel allocation, callbacks and streaming state
remain original and uncredited.

GC/1.3.2 reproduces all retained code after applying **12 actual relocations**,
including the three SDA2 references. No data, padding or compiler helper is
emitted or credited by either source unit. Strict evidence is in
`scratch/game_platform_audio/verify.py`; final ELF byte verification is in
`scratch/platform_audio_reset_link_proof.json`. Full acceptance is recorded
in `scratch/platform_audio_reset_checkpoint.json`: byte-identical DOL, all
prior source matches, immutable original baseline, current candidate/header
hashes, passing source extent and assembly audits, and 23 passing tooling
tests. These partial splits do not establish the original audio file boundary.

The subsequent [update/path group](game-platform-audio-update.md) now matches
its complete 928-byte update, two path wrappers, flush wrapper and scalar
clamp. It also owns the shared 40-byte scalar block previously borrowed here.
The earlier 38-instruction private probe has been superseded by strict
relocation-aware proof and final linked byte verification.
