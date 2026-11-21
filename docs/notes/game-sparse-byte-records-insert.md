# Sparse byte-record insertion

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801B4D14..801B4FDC` matches all 712 original text bytes and 28 actual relocations under GC1.3.2 Gekko/O4,p, exceptions off. Production and fresh unchanged-core verifier recompiles pass every allocated section and exact function extent; no helper, data/BSS, EH, startup or padding allocation is emitted.

The pool stores 129-byte string records in a count/capacity/data array at offsets 0/4/8, followed by the BitSet word array at C/10/14, requested bit count18, high-water count1C and active count20. Insertion searches for a clear bit, increments the active count, reuses a free record when available, otherwise grows record capacity by 32, extends occupancy storage, marks the next slot and returns the previous high-water count. Ordinary placement construction and destruction of trivial words reproduce the native empty counted loops without initializing the newly allocated storage.

The old private probes in `scratch/game_engine_cache_records_continuation` remain untouched. Their documented two-word near was at offsets298/29C: independent li/clrlwi scheduling in the reuse branch. The new source returns immediately from the append branch with `return self->high++`. A controlled variant replacing this with assignment to a shared return-index local restores exactly those two differences. Changing the unsigned word or mask literal alone leaves the exact match intact, so the verified closure is the ordinary result lifetime, not literal typing.

Current symbol/canonical/body preflight scanned 1,686 manifests and 44,059 body files, with no active ownership overlap and all 15 explicitly inventoried older uncredited definitions preserved. A stable guarded scan of 5,602 active objects, 119,086 actual relocations and 777,360 initialized original words found one original caller/entry reference, no aliases and no initialized pointers. Every config/object hash remained unchanged during the scan. Full original extabindex including terminal descriptor and ctors/dtors scans find no ownership for this function.

Existing `src/Game/engine_cache_records_801B4C30.cpp` remains unchanged and retains the original C call spelling. All allocator/BitSet identities remain external. No shared header, migration or new verification gate is required. Frozen handoff: `scratch/game_engine_batch252/manifest-list.json`. Root owns central integration and full native original-DOL acceptance.
