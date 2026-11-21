# Owner control dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_control_dispatch_80093574.cpp` reconstructs `80093574..800936D0` (348textbytes), with owned extab `8000EFF0..8000EFF8` and index `8001A9E8..8001A9F4`. Its manifest is listed in `scratch/game_owner_control_dispatch/manifest-list.json`. GC1.3.2 uses standard optimization and extra `['-Cpp_exceptions on']`.

The function checks controls `0x1D/1E/1F/20/23/2A` in order through the agent's `0x318` subobject. It obtains the first active control record and calls virtual slot `0x1C`, then stops. The new frozen `include/Game/owner_control_dispatch_views.h` has its sole production consumer verified.

Strict verification proves all368allocated bytes, exactly one function plus extab8/index12 with actual local ELF names. All12text relocations, two EH-index references and one nonallocated metadata reference are audited. Full original DOL SHA1 and complete original exception/constructor/destructor ownership table audits pass. No data/BSS, weak helper, padding or gap ownership is claimed. Full executable acceptance remains centrally owned.

The adjacent648byte flag synchronizer at `800936D0` is private, uncredited research. `scratch/game_owner_control_dispatch/FINDINGS.md` preserves its bounded comparison. It is excluded from the production manifest.
