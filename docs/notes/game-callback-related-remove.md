# Callback related-object removal

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_802529E8` reconstructs the complete 364-byte function at
`0x802529E8..0x80252B54`. It returns zero when the Root gate rejects the
owner. Otherwise, a valid handle at `0x188` is used to find a related handle
through the original resource collection. A native typed copy retains that
related handle while virtual slot `0x1C` runs on the original object and,
if still valid, its related object. Cleanup releases the typed copy and the
callback returns one.

The private native/zero/copy layers preserve one zero store, the original
word copy and reference update, and destructor flag zero. The partial global
context exposes the original manager at `0x118` and resource collection at
`0x120`. Existing shared declarations and all original data retain their
owners. `scratch/game_callback_related_remove/verify.py` checks the exact
retained extent, every allocated byte, and actual relocations without masks.

Three trailing compiler cleanup destructors occupy 264 additional bytes.
Their exact weak names, offsets, extents, raw byte hashes and relocations are
recorded separately. Retained source does not reference these functions;
central acceptance requires their absence from the linked executable, and
they receive no progress credit. Original exception/startup ownership, full
executable hash, baseline regressions, source extents, progress exports and
repository tests are checked centrally before acceptance.
