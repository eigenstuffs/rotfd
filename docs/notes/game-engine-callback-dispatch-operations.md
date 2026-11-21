# Callback membership-counter dispatch operations

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_800CAA20` (920 bytes) and `fn_800CA644` (988 bytes) reproduce their entire
ordinary dispatch bodies, eight-byte exception records, twelve-byte indices,
and 28-byte compiler switch tables. The production sources are
`engine_callback_dispatch_operations_800CAA20.cpp` and
`engine_callback_dispatch_operations_800CA644.cpp`. Every emitted allocation
and all 63 real relocations match the original executable in isolation. There
are no extra helpers, weak functions, native-name migrations, or startup entries.

The event zero through six paths use the established three-word callback
member-pointer records through the original external pool `802C1590`.
The used five-record ranges start at offsets `D4` and `7C`, respectively.
The original switch tables at `802C16A0` and `802C1648` already satisfy the
compiler's emitted eight-byte `.data` alignment. These two sources own only
their 28-byte switch tables; all original member-pointer records remain outside
the partial units.

Action fourteen queries selector `8B` or `8A`. Action fifteen resolves the
handle at object offset `28`, then the linked handle at resolved offset `58`.
It scans indices zero through the unsigned byte at `62`, inclusive, using the
borrowed handle word returned by `fn_8025E1D4`. Each handle has the established
signed 24-bit index and signed eight-bit generation. Manager `118`, its entry
pointer at offset eight, sixteen-byte entry stride, object pointer at zero,
and generation byte at `C` match the existing Handle lookup evidence.

The comparison loop stops at the first matching resolved object. `800CAA20`
decrements the signed counter byte at `63`, then calls virtual slot `7C(0,0)`
when the mode byte at `60` is two. `800CA644` increments the counter; when it
equals the count and the global observer exists, it sends selector `8A` with
the observer's virtual-slot-`14` result and the original external float at
`80379650`. It then calls slot `80(0,0)` when the mode is one.

Two genuine pointer views express the nested manager lookups. The first uses
the typed sixteen-byte entry array. The second accesses the same manager's
entry storage through its observed byte pointer and casts the indexed record
back to the established entry view. This ordinary byte-backed storage view
preserves the native second entry-pointer load; using one typed view throughout
lets the compiler reuse that load and shortens the function by four bytes.
Both the byte-backed-first and byte-backed-second alternatives match; the
production sources choose the latter. All initial probes and both alternatives
remain preserved in scratch.

The borrowed-word getter takes an integer index, consistent with the already
accepted `callback_handle_chain.cpp` definition. The unsigned-byte loop index
therefore undergoes the original word argument promotion before each getter
call. Its initial provisional unsigned-byte argument declaration omitted the
native narrowing instruction and is retained only as excluded probe evidence.

`ownership_audit.json` scans the full original exception-index, constructor,
and destructor tables, and records original initialized-data references and
existing source callers. `final_integration.json` records all source hashes,
emitted symbol extents, actual relocations, dependencies, and section ranges.
`verify.py` independently recompiles and checks each production object.
Complete native linking, the original DOL hash, and regression checks remain
the root integrator's acceptance gates; this isolated handoff claims no progress.
