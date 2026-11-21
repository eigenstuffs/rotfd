# Actor Handle-array capacity

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary typed array implementation matches fn_8008AE74 (564 bytes) plus its original8-byte extab and12-byte index with GC1.3.2 processor750/O4,s. The array stores signed count/capacity and a pointer to four-byte typed handles. Changing capacity below the current count calls the inlined resize operation; otherwise only storage capacity changes. Shared growth/shrink loop index lifetime reproduces the original register allocation and preserves the native redundant comparison after inlining.

Three ordinary zeroing constructor layers reproduce three original stores, and genuine destructor layers reproduce three nullable cleanup checks. Two private weak backup destructors and their EH/index are fully inventoried and receive no ownership or credit; final native discard is mandatory. No shared data, literals, BSS or padding is claimed. Original C entry spelling and all external allocator/Handle identities remain unchanged.

Verification and complete original exception/startup/pointer ownership evidence are in scratch/game_early_actor_handle_array_capacity. Central full-DOL acceptance remains pending.
