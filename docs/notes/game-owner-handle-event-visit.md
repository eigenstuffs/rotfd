# Owner handle event visit

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_handle_event_visit.cpp` reconstructs `fn_8021FE84`,
`0x8021FE84..0x80220124` (672 bytes), with standard GC 1.3.2 settings.
It also owns its naturally emitted eight-byte integer conversion literal at
`0x8037B090..0x8037B098`, bits `4330000080000000`.

When the owner's handle at `0x24` is valid, the function creates an empty local
handle array and fills it through `fn_8023F744` for the supplied input handle.
For each element it resolves the object, then its parent handle at `0x130`.
A non-null parent with flag `0x400000` in its 64-bit flags at `0x38` resolves
its query handle at `0x70`, calls virtual slot `0x98` with the current array
handle as an argument, and dispatches the requested event through `fn_802073E8`
using the returned integer converted to float. The event recipient is the
object resolved from the original owner's handle; the parent is event context.

The current array handle remains in r4 across the nested resolutions. That
explains the original virtual call's apparently absent argument setup: slot
`0x98` consumes that already-live handle reference. The input handle pointer
is mutable, preserving the original array-initialization scheduling. Explicit
index and byte-offset loop variables express the observed array traversal.
The temporary array releases its two-layer elements, frees capacity times four
bytes of storage, and clears its pointer. Ordinary layered C++ destruction
accounts for both native element null checks.

The integer-to-float cast naturally emits the exact conversion pool. The
strict verifier scans every direct SDA2 operand throughout all original text
sections and every aligned word of the untouched DOL for absolute pointers
into the eight-byte pool. The only consumer is `0x8022006C`; there are no
absolute pointers. No other source group needs this literal.

`python3 scratch/game_owner_handle_event_visit/verify.py` recompiles frozen
production source, verifies all 672 text bytes and eight literal bytes, checks
the complete actual relocation identities and all ten retained relocations,
and accounts for all allocated sections. Text allocation is 884 bytes: the
retained function and one unused weak array-destructor backup of 212 bytes.
The backup's five actual relocations and two nonallocated metadata references
are inventoried; the backup must be absent from the final ELF. Retained code
does not reference it. Complete original extabindex, constructor, and destructor
table audits show no retained ownership. BSS and owned padding are zero. This
partial text/literal split does not recover the original engine translation
unit. Central integration and final DOL hash acceptance are parent-owned.
