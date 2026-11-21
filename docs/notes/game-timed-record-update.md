# Timed record update at 801C6980

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary C++ source `src/Game/timed_record_update_801C6980.cpp` reconstructs the 788-byte update at 801C6980..801C6C94. Isolated production compilation and fresh strict verification match every allocated byte and all 16 actual relocations. It emits only the GLOBAL primary .text function. Central original-placement/full-DOL acceptance is pending.

The routine advances current/previous time, constructs 64 original 44-byte work records through the existing fn_801C6968 callback, queries action events, processes loop-start and repeat boundaries, rewinds related targets, clamps completion time and sends the final event. The two flag clears are masks ~4 and ~6, preserving the independent flags shown by the native word masks. The curve call forwards previous time, clamped end time and resource duration.

The explicit byte offset for the related-handle array is ordinary indexed storage access. Declaring the offset before the loop index and initializing it after the index preserves the native saved-register and initialization ordering. Independent for/comma and while variants produce identical matching code. The final inline resolver returns an unsigned address before the normal target-pointer cast; this preserves native call-argument scheduling. The first two resolvers retain their typed target result. No assembly, register forcing, volatile declarations or compiler-owned data aliases are used.

Full original extabindex 80015F60..8001F2C0 (including its terminal descriptor), ctors 80299920..80299980 and dtors 80299980..802999A0 audits establish no owned exception/startup entries. All three small-data floats remain original external GLOBAL objects, as do the context, callback and callees. There are no helper backups, data/BSS allocations, padding transfers or native identity migrations.

The stable active-original audit scans 5,641 objects, 119,086 actual relocations and 777,360 initialized words: sole original GLOBAL788 function, one original callback relocation and one initialized callback pointer, no direct calls, aliases or overlapping text owners. Pointer-containing original data and all compiled consumers remain untouched. An isolated MWLD link retains the GLOBAL788 function with every real primary relocation applied exactly and no extra source allocations; its wrong-primary-extent guard rejects the mutation. Frozen handoff/evidence: scratch/game_engine_batch283/.
