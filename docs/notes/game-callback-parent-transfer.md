# Callback parent-handle transfer

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80254F70` reconstructs the complete 348-byte function at
`0x80254F70..0x802550CC`. It invokes the original preparation routine,
releases the owner's old handle at `0x58`, copies and retains the incoming
handle, and forwards it through virtual slot `0x44` on the resolved handle
at `0x64`. It then resolves the incoming object's handle at `0x1C`, copies
that object's first word into the owner's word at `0x60`, and invokes the
owner's virtual slot `0x38`.

The partial virtual interface and object views describe only native accesses.
All signed index/generation comparisons, reference-update calls, and original
external data ownership are preserved. No extra functions, allocated data,
padding or startup records are emitted. The dedicated
`scratch/game_callback_parent_transfer/verify.py` checks every allocated byte,
the complete extent and actual relocations without masks. Central acceptance
also audits original exception/startup references and checks the full DOL
hash, baseline regressions, source extents, progress exports and tests.
