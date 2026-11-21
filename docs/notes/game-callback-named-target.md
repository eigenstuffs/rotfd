# Callback named-target binding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8025361C` reconstructs the complete 396-byte function at
`0x8025361C..0x802537A8`. It constructs pooled names from the caller's
name and original category string, receives an owned lookup result, retains
a typed copy with two zero layers, and assigns it to the owner handle at
`0x48`. It then passes a separately retained one-layer copy of the owner's
handle at `0x04` to the resolved target and invokes virtual slots `0x50`
and `0x28`, the latter with argument four.

Temporary name and handle expressions reproduce native evaluation order
and stack slots. An explicit reference to the owner member preserves its
alias through the native constructor/reference calls. Earlier named-local
and uncaptured-expression probes remain private and uncredited. Partial
interfaces describe only accessed fields; pooled strings, manager objects,
neighboring methods and all original data retain their owners.

The dedicated verifier checks the full retained extent, all allocated bytes
and actual relocations without masks. Six trailing weak cleanup destructors
occupy 536 bytes. Their names, binding, offsets, extents, raw hashes and
relocations are separately recorded; they receive no credit and must be
absent from the final executable. Central acceptance also audits original
exception/startup ownership and checks the full DOL hash, baseline regressions,
source extents, generated progress exports and repository tests.
