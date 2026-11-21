# Returned-handle fallback dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8025795C` reconstructs the complete 396-byte function at
`0x8025795C..0x80257AE8`. It receives an owned value handle from
`fn_80257B70`, retains a typed copy and destroys the returned temporary.
An invalid typed handle returns immediately through its original cleanup.
A valid owner handle at `0x60` dispatches virtual slot `0x30` with the copy,
a null first argument and the caller's argument. Otherwise, a valid owner
handle at `0x64` calls the original fallback with arguments zero and one.
The typed copy is destroyed on each exit.

The private derived owner view extends the existing `0x60` owner with the
adjacent handle, preserving the native member-address calculation. A cast
between unrelated partial owner views produced an extra instruction and is
retained as an uncredited private probe. Shared declarations remain frozen.
Original data and neighboring methods retain their owners.

The dedicated verifier checks the exact retained extent, every allocated
byte and actual relocations without masks. Four existing compiler-generated
weak destructors occupy 348 trailing bytes; their raw hashes, binding,
offsets, extents and relocations are inventoried separately. They receive no
source credit and must be absent from the linked executable. Central
acceptance checks original exception/startup ownership, the full DOL hash,
baseline regressions, source extents, progress exports and tests.
