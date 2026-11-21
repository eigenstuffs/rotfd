# Callback transform composition and forwarding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80254C74` reconstructs the complete 488-byte function at
`0x80254C74..0x80254E5C`. With a primary source at owner offset `0x68`,
it copies the source's 16-float transform through `0x124` and nine-float
basis at `0x30`. An optional secondary source at `0x6C` composes both
through the original matrix routines. The callback extracts translation,
converts the basis to a quaternion, and forwards both to the resolved owner
handle at `0x58`, then invokes its refresh operation.

Ordinary aggregate copies reproduce the native word loads/stores. Declaring
the basis and quaternion before the corresponding matrix/vector initialization
preserves the original stack slots without added accesses or padding. Private
earlier declaration orders retain their near-match evidence. Shared handle
declarations remain frozen; original matrices, data and neighboring methods
retain their owners.

`scratch/game_callback_transform_copy/verify.py` checks every allocated byte,
the full function extent and actual relocations without masks. No extra
functions, allocated data, weak helpers or padding are emitted. Central
acceptance audits original exception/startup ownership and requires the full
DOL hash, baseline regressions, source extents, progress exports and tests.
