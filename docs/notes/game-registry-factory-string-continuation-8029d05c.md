# Registry and factory string continuation at 8029D05C

The accepted `game_type_registry.cpp` read-only pool extends from 746 to 822
bytes, ending at `8029D0A6`. Four GLOBAL arrays supply Anonymous New,
GCMemCardManipulator.h, SBPantsMove.h and WaterHelmetMove.h. Their original
names, addresses and complete string sizes remain unchanged.

This adds 69 string bytes and seven natural alignment bytes, for **76 new data
bytes**. The final two bytes through `8029D0A8` remain explicitly original-owned.
The former two-byte boundary alignment is now internal to the emitted pool.
No padding arrays are used.

The existing 988 code bytes, 20 exception bytes, 125 real relocations and one
compiler metadata reference remain unchanged. The complete production object
matches the independently recompiled candidate. Its 43 undefined symbols have
GLOBAL binding; no weak functions or extra allocations are introduced.

All 6,870 active linker inputs at capture were audited. Ninety pool references
come from four unchanged source consumers. Existing factory calls establish
the allocation label and filename types; three checked immediate-offset uses
also address Anonymous New through the unchanged registry pool base. No
consumer source or object changes were needed.

The original DOL hash, no-regression comparison, source extent audit and all
66 tooling tests pass. The frozen handoff is
`scratch/game_registry_string_append_20261020_parallel/`; production verification
is in `scratch/registry_strings_integration_20261020/`. A bounded successor in
`scratch/game_registry_string_history_20261020_parallel/` requires the complete
current native owner when accepting the exact old registry source/object
receipt. Old inventories and source hashes remain preserved.
