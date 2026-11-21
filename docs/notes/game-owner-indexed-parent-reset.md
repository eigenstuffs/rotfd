# Indexed owner parent reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_indexed_parent_reset.cpp` reconstructs `fn_8021FC00`,
`0x8021FC00..0x8021FD9C` (412 bytes), with standard GC 1.3.2 settings.

The owner obtains the selected handle through virtual slot `0x9C` and resolves
its preferred parent handle returned by `fn_80240F28`. It resolves the selected
object again and, unless object flag `0x20000` at `0x120` is set, detaches it
with `fn_80240120`, retains a one-layer copied handle while attaching it to the
preferred parent through `fn_802408BC`, releases the copy, and refreshes the
object with `fn_8023DE28`. It then sets the selected axis returned by virtual
slot `0xF0` to the external zero/one/zero scalar values.

`python3 scratch/game_owner_indexed_parent_reset/verify.py` recompiles frozen
production source, checks all 11 actual retained relocations including both
small-data constants, and compares all 412 retained bytes to the original
hash-verified DOL. The sole allocated section has 584 text bytes: 412 retained
and two unused weak destructor backups totaling 172. Their four relocations
are inventoried; the backups must be absent from the final ELF. Retained code
does not reference them. Complete original extabindex, constructor, and
destructor table audits show no retained ownership. Data, BSS, and owned padding
are zero. The original engine translation unit remains incomplete. Central
integration and final DOL hash acceptance are parent-owned.
