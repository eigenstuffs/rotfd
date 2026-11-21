# Owner basis reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

One independent unit recovers `fn_8009DBEC`: `src/Game/owner_basis_reset_8009dbec.cpp`, text8009DBEC..8009DC5C(112), extab8000FB9C..8000FBA4(8), extabindex8001B228..8001B234(12). It uses the new frozen `include/Game/owner_basis_motion_views.h`, with this one verified production consumer.

The reset calls the existing base reset and control reset, clears64-bit flags0x81FFFE00, then sets0x400 and0x200. GC1.3.2 standard optimization needs only extra `['-Cpp_exceptions on']`.

`scratch/game_owner_basis_motion/manifest-list.json` records the frozen handoff. Strict verification proves all132allocated bytes, actual local EH/index names, two text relocations, two EH-index relocations and one nonallocated metadata reference. Full original DOL SHA1 and complete original extabindex/constructor/destructor table ownership checks pass. No data/BSS, weak helper, padding or gap ownership is claimed. Final full executable acceptance remains centrally owned.

The adjacent projection8009ED90 remains private/uncredited with308extent and seven floating-point register/scheduling differences after bounded ordinary source variants; see `scratch/game_owner_basis_motion/FINDINGS.md`.
