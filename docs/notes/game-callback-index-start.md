# Callback index start

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8025D1C8` reconstructs the complete 536-byte function at
`0x8025D1C8..0x8025D3E0`. It stores the selected index at `0x64`, starts the
object referenced by `0x6C` when owner flag `0x80000` is clear, optionally
resets the `0x60` object when flag `0x100000` is set, and sets flag `0x80000`
after calling the referenced object's start routine.

The start call receives a retained copy of the owner's handle at `0x04`,
the resolved `0x60` object's member at `0x0C`, the owner's member at `0x68`,
and its selected index. Three ordinary zero-initializing handle layers
preserve the native construction sequence. A const reference preserves the
owner-member alias, and resolving the target before the other arguments
preserves the original evaluation order. The temporary is destroyed before
the optional reset and final start call. Existing partial handle layouts
are reused without changing their shared header.

`scratch/game_callback_index_start/verify.py` checks the complete retained
function, exact extents and actual relocations without masks. Trailing
unused weak destructors are separately inventoried by name, offset, extent,
binding, raw hash and relocations; they receive no source credit and must
remain absent from the final executable. Original data and neighboring
functions retain their existing owners. Full executable and regression
acceptance is required before matching credit.
