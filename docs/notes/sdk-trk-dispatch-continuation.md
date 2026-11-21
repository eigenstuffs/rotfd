# MetroTRK dispatcher continuation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/MetroTRK/dispatch_init.c` recovers the ordinary C initializer at
`0x801190C8..0x801190E0`: set the original dispatch-size word at `0x8033AA70`
to 32, then return success. The separate source preserves the existing C
entry point and all accepted callers. It emits exactly 24 text bytes and two
real address relocations under GC/1.3.2 and the established MetroTRK flags.
`scratch/sdk_trk_dispatch_continuation/verify.py` recompiles the production
source and checks every allocation, symbol extent, relocated byte and target.
The original function extent and full exception-index/constructor/destructor
tables were audited: this function has no metadata or startup ownership.

This is a partial text split. `TRKDispatchMessage` at
`0x80119044..0x801190C8`, the 34 callback-pointer table at
`0x802CFD60..0x802CFDE8`, and the original size-word BSS allocation
`0x8033AA70..0x8033AA78` remain original fallback. The latter contains the
observed four-byte word plus four bytes of original trailing allocation;
this handoff owns neither. The existing data symbol is published for the
initializer's real relocation; its name and address are preserved.

A fresh bounded dispatcher pass preserved the older near-match source and
artifacts. Independent ordinary helper forms, result-pointer helpers,
byte aggregates, callback/getter helpers, declaration order, register
keywords, local names and bounded optimization switches did not close its
three differing register operands. Its best candidate still loads the byte
into r5 rather than original r4. No variant earns partial source credit;
all diagnostics apply actual ELF relocations and reject differing extents.
The original full source and earlier callback-table evidence remain unchanged.

Only the initializer is proposed for integration. Full native DOL/hash,
regression and source-extent acceptance remain the integrator's responsibility.
