# Movie interframe plane dispatch (private nonmatching research)

`fn_80294B78` owns original text `80294B78..80294FB4` (1,084 bytes).
This investigation adds **no matching source or credit**. Its isolated evidence
is in `scratch/movie_interframe_plane_dispatch_20261011kd/`; accepted functions,
shared headers, configuration, splits and symbols are unchanged.

The routine prepares three 52-byte output records, dispatches the initial
plane runs, and walks an 8-by-8 block grid. A block's flag selects an intra
operation or one of two previous images. Changing the previous image clears
the two motion components. Each component combines a Huffman symbol with
residual bits, then wraps into a signed interval. The routine selects either
the direct or interpolated block copy and advances the three records.

The direct partial record view identifies row cursor `+14` and previous-image
base `+18`, which the accepted shared record header leaves opaque. Its full
52-byte layout agrees with the existing record initialization and block
dispatch routines. This private view does not change their declarations.

An ordinary shared next-output pointer preserves the original retained `r3`
across the second and third plane setup. Separate source/cursor assignments
preserve their original store order. An inline row-advance helper with a named
next cursor removes three extra reloads. Those changes close the original
1,084-byte extent and all seven actual branch targets.

The best bounded probe is `deltaref.cpp` with GC 1.2.5, `-O4,p`,
`-use_lmw_stmw on`, and `-inline auto,level=3`. Its only allocation is
1,084 bytes of `.text`, containing one GLOBAL original C entry and seven
actual REL24 relocations. A fresh compilation reproduces the full raw payload
and relocation inventory. **149 full instruction words still differ**.
The original frame is `0x150` with records at `0x68`; this probe uses `0x108`
with records at `0x20`. Saved-register allocation, residual-bit scheduling,
and cached-reader versus workspace-relative field accesses also differ.

Bounded alternatives preserve direct versus opaque record fields, explicit
cached readers, bit result return/reference/byte types, separate symbol and
delta helpers, inline depths, deferred inlining, size optimization and
propagation/loop options. No forced stack slots or instruction constraints
were used. The original complete exception-index, constructor and destructor
tables contain no references to this extent. No original data, literal pool,
BSS or metadata allocation is claimed. `bounded_verification.json` records
the fresh compile and complete allocation/actual-relocation result;
`frozen_private_sha256.json` seals all private artifacts and this note.
