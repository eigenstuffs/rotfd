# Callback handle relationship and classification

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80257E04` reconstructs the complete 492-byte function at
`0x80257E04..0x80257FF0`. It conditionally forwards the owner's handle at
`0x64` to the incoming object, forwards the handle at `0x58`, and retains
a typed copy of that object's related handle at `0x2C`. If the related
handle is valid and its first line matches the original category string,
the callback sets flag `0x01000000`. Cleanup destroys the retained copy.

The partial owner reuses the existing 64-bit flags declaration. That native
width reproduces the original constant loading and OR sequence; a private
32-bit view was four bytes short and remains uncredited. A reference to the
related member preserves its alias through native construction and retention.
The original line reader, string, data and neighboring methods retain their
owners.

The dedicated verifier checks the full retained extent, all allocated bytes
and actual relocations without masks. Three trailing unused weak destructors
occupy 264 bytes; their binding, names, offsets, extents, raw hashes and
relocations are recorded separately. They receive no source credit and must
be absent from the final executable. Original exception/startup ownership,
full DOL hash, baseline regressions, source extents, progress exports and
repository tests are required for central acceptance.
