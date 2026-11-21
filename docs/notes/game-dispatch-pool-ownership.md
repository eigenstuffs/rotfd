# Dispatch metadata ownership and native layout

The callback/control/bounds checkpoint owns three real five-record member-pointer spans beside their compiler-generated switch tables:

| Function | Record span | Record words | Table span |
| --- | --- | --- | --- |
| 80034F44 | 802B1BE0..802B1C1C | {0,0x8C,8} | 802B1C1C..802B1C38 |
| 800E3C70 | 802C8AE8..802C8B24 | {0,0x94,8} | 802C8B24..802C8B40 |
| 800E7784 | 802C8EE8..802C8F24 | {0,0x98,8} | 802C8F24..802C8F40 |

Each ordinary C++ MemberPointer array owns exactly five complete original twelve-byte records. Each unchanged compiler table owns seven actual function relocations. The combined compiler .data section is88 bytes with alignment8 and starts at the original aligned record address. This reproduces the original layout without rewriting object payloads or inserting synthetic padding. Standalone28-byte table sections had introduced32 bytes across the full native link; forcing a split alignment could not lower compiler section alignment.

The original base labels lbl_802C8ADC and lbl_802C8EDC retain their first twelve-byte records and their existing registry consumers. The new tail identities lbl_802C8AE8 and lbl_802C8EE8 describe the recovered five-record subarrays. lbl_802B1BE0 retains its original sixty-byte identity. Other member-pointer records and surrounding original data remain outside these partial source units.

The functions still borrow the broader original pool bases, so the compiler emits no direct relocation to the recovered globals. The supported target force_active list retains exactly these three original record arrays. The complete native map identifies each array in its source object at its original address and sixty-byte size; the final ELF and DOL preserve every byte. This is a data ownership refinement, not a change to the protected executable or a relaxation of comparison.

`scratch/game_dispatch_pool_ownership_continuation/handoff.json` preserves the independently frozen proposal, complete original ownership tables, twelve-unit layout audit, source-consumer inventory and unchanged original sources. The root adoption proof recompiles before/after objects and verifies unchanged text, EH, tables and every retained relocation. `scratch/continuation_20261010/audit_dispatch_pool_ownership.py` repeats source/canonical verification, supported retention, native map placement, all original allocations and preserved first records at every accepted checkpoint.

The accepted checkpoint passes the original full DOL SHA-1, baseline regressions, source extents, generated progress, native weak-override checks and all26 repository tests. These pools add180 source data bytes and zero extra function or code credit.
