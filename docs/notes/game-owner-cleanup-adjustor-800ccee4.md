# Native owner cleanup adjustor at 800CCEE4

The partial virtual view in `include/Game/owner_cleanup_virtual_view_800CC6CC.h`
reconstructs the compiler-generated eight-byte secondary-base cleanup adjustor
at 800CCEE4. The existing 228-byte cleanup, four-byte hook, eight-byte hook
adjustor and 72 exception bytes remain exact. This adds one function and no data.

The original input census found no typed destructor, base-subobject destructor,
exception cleanup-action or interior-entry callers. Four configured identities
migrate together to the observed virtual cleanup ABI. The existing base cleanup
at 800A8F90 retains its identity and calling convention.

The two complete production objects match the frozen compiler inventories.
All 15 retained actual relocations resolve to the original bytes; every used
undefined symbol has GLOBAL binding. The native linker retains both WEAK
adjustors and discards the compiler's 32-byte partial table. The complete
424-byte original table at 802C1A90 remains original and uncredited.

Evidence is in
`scratch/resource_finder_inline_20261020/native_owner_adjustor_800CCEE4/`.
Its `evidence_refresh/native-proof.json` checks the complete active reference
topology, unique providers, native boundaries, old-name removal and original
DOL hash. Bounded successors preserve the previous canonical and guard receipts.
The standard build, `ninja changes`, source extent audit and all 66 tests pass.
