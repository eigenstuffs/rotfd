# Disc status and synchronous wait wrappers

`platform_disc_status.c` reconstructs the 36-byte `8028F4B4..8028F4D8` routine and
owns the four-byte status word at `80378168..8037816C`. It calls the SDK's global
`DVDGetDriveStatus`, stores the returned status and returns it. It reads no
incoming argument. The earlier private streaming callback happened to keep a
record address in r3 at the call site; this does not make the query per record.

`platform_disc_read.c` reconstructs all 152 bytes of `8028EEEC..8028EF84`. A null
file record, null destination, or zero byte count returns zero. It requests an
asynchronous read at priority two with no completion callback. A nonzero SDK
result calls the original `8028EF84` wait routine on the owner and returns that
routine's result; failed submission returns zero. The wait/error implementation
remains original. Negative lengths and offsets retain native behavior without
additional validation.

These are physical C ABI fragments, not recovered original file boundaries.
The state word is a strong NOBITS small-BSS object, exactly four emitted bytes
at section alignment eight. Following flags retain original ownership. There
are no helper functions, initialized data or source-owned alignment bytes.

`python3 scratch/game_disc_status/verify.py --production` proves all status
code bytes, its two actual relocations, the strong BSS symbol and original DOL
BSS bounds. `verify_read.py --production` proves every read-wrapper byte and
both actual call relocations. Both check exact allocated section extents,
bindings/types and included headers. Final DOL, linked proof, native objdiff,
previous source/hash preservation, source audits and tooling tests establish
integration credit; original wait logic and flags remain in the denominator.
