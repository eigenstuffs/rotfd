# Settings snapshot (800541F0)

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The 3,116-byte routine copies a settings snapshot into a 15,196-byte output. It preserves the source header fields, two native virtual float queries, 100 signed shorts, seven groups and 300 pairs of original flag bytes. The group copy order is 0, 6, 1, 2, 3, 4, 5; capacities are 5, 3, 4, 4, 4, 5, 4. Each source group occupies 148 bytes and each fixed output record occupies 464 bytes. Ordinary loops copy the original 250-byte name and two 100-byte arrays without adding terminators or changing bounds.

Genuine typed structures, template capacities and ordinary repeated member accesses reproduce every native source reload and indexed destination store. Compile-time size declarations check the group, record and full output extents. The final flag getter accepts an integer index while the caller retains its original unsigned-short iteration; this closes the three operand differences from the initial probe. Source and destination memory, the global mode service and the original 24,000-byte flag table at 802F4208 remain external. There are no weak helpers, aliases, literal pools, data/BSS allocations or caller migrations.

Only the original C function, eight exception-table bytes and twelve index bytes are owned. This is a partial text split; every surrounding function, table and initialized datum remains in its original unit. The note is mutable acceptance documentation and is excluded from immutable compiler evidence.

Full original exception/startup table descriptors and padding, every initialized byte offset for function pointers, exact symbol/instruction extents and all actual relocations pass. This partial text split preserves original external tables, literals and callers. Complete production hash, regression and native checkpoint acceptance remain required.
