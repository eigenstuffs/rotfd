# Callback owner-link transfer

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80259008` reconstructs the complete 348-byte function at
`0x80259008..0x80259164`. It resolves the incoming handle, forwards the
owner's handle at `0x80` with mode four, retains a native copy of the owner's
handle at `0x04`, and assigns a typed copy into the resolved `0x80` object's
handle at `0x24`. Both temporary handles are destroyed before the original
follow-up callback `fn_8025A0A4` runs.

The explicit reference to the owner member preserves its original alias.
The native copy has no zero layer; the typed copy has one. Assignment first
releases the destination, copies its word, and retains the source. Existing
handle declarations are reused without changing the shared header. Original
data and neighboring methods retain their owners.

`scratch/game_callback_owner_link/verify.py` checks the complete retained
extent, all allocated bytes and actual relocations without masks. Four
trailing unused weak destructors occupy 352 bytes; their names, offsets,
extents, binding, raw hashes and relocations are separately recorded, receive
no source credit, and must be absent from the final executable. Central
acceptance also checks original exception/startup ownership, the original
DOL hash, baseline regressions, source extents, progress exports and tests.
