# Descriptor callback object factory

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8025222C` reconstructs the complete 516-byte function at
`0x8025222C..0x80252430`. It looks up the original category and descriptor
name, retains a typed copy of the returned handle, and replaces the caller's
output handle. It copies the descriptor's four floats at `0x10`, resolves
the output again, and copies the incoming object's signed key at `0x74`
into its key at `0x30`.

The inline index updater uses the original record owner at global offset
`0x16C`: it releases an existing index, requests a new index for the key,
and stores the result, or stores minus one when the record owner is absent.
Its explicit result-output declarations follow the already accepted index
adapter ABI. Keeping these locals inside the inline helper reproduces the
native stack slots; an extended typed global declaration preserves the
native record-owner load. Earlier variants remain private and uncredited.

Partial layouts describe only observed fields. Original names, manager and
record data, neighboring methods and all other class fields retain their
owners. The dedicated verifier checks the complete retained extent, every
allocated byte and actual relocations without masks. Four trailing unused
weak cleanup destructors occupy 348 bytes, with binding, names, offsets,
extents, raw hashes and relocations separately inventoried. They receive no
credit and must be absent from the final executable. Central acceptance also
audits original exception/startup ownership and checks the full DOL hash,
baseline regressions, source extents, generated progress and tests.
