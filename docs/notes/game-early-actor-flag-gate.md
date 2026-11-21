# Actor flag-gated dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_actor_flag_gate_800af6e8.cpp` reconstructs the924-byte dispatch routine at800AF6E8. When the local record's flag1 is set, it resolves the current system-group, related group and optional actor, checking actor-record flags2C,2D and2E in order. If all three are clear, it sets the local byte at2C8 and clears the local record state. It then forwards the original four arguments and time to the resolved record target. Otherwise it invokes the original fallback dispatcher.

The three repeated resolution chains remain separate, matching the native loads around external queries. The group accessor returns its member Handle by const reference; this keeps the member address across each validity query and reproduces all three native checked resolver branches. A raw field expression instead retains the group base, shortening each chain by one instruction. The source uses ordinary typed manager views and C++ references, with no assembly or register constraints.

The isolated GC1.3.2 O4,s/exceptions-on production object exactly matches924 text bytes, eight EH bytes at80011168 and12 index bytes at8001BEC4, including all15 actual allocated relocations and full symbol extents. It emits no helper code, literals, BSS or padding. Dependencies are selected from actual undefined ELF symbol indices, avoiding compiler-local name collisions.

Full original exception-index and startup-table scans pass. The complete initialized-data word scan finds its owned index and an unchanged callback at802BD604 inside the original348-byte `lbl_802BD5C4` table. This table remains externally owned with its original identity. No existing source caller or shared header needs migration; the new private header has only this production consumer. Matching credit waits for root integration, original DOL hash and regression acceptance.

Frozen handoff: `scratch/game_engine_batch159/HANDOFF.md`. Repeat: `python3 scratch/game_early_actor_flag_gate/verify.py`.
