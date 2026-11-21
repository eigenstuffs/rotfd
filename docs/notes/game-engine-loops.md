# Engine array and lifetime continuation

This separate handoff contains **16 partial C fragments, 17 original functions,
and 2,532 text bytes** in `801B26DC..801DA8B8`. It follows the frozen
`scalar_middle_more` tranche and does not change any earlier source or manifest.
Private fields describe observed offsets and strides; existing versioned names
preserve the original entry points.

The canonical handoff is
`scratch/game_engine_loops_continuation/final_integration.json`.
Exact proposed central edits are in `final_splits.txt` and `final_config.txt`;
`ownership_audit.json` records complete original function ranges and original
section ownership. No central symbols, splits, flags, or progress files were
edited. These are accepted matching source fragments after the native full-DOL
hash and regression checks.

## Recovered behavior

- Two 208-byte record-array destructors visit records with verified strides 80
  and 140, invoke their original element destructor, release the buffer using
  its original allocated size, retain both pointer-zero stores, and optionally
  release the array object itself.
- The 184-byte handle refresh lookup at `801B3E54` and adjacent 188-byte key
  setter/refresh at `801B3F0C`. The manager has 16-byte handle entries at pointer
  `+8` and a lookup object at `+C4`. The helper builds a key, queries the lookup,
  checks the resolved entry's object pointer, updates the handle's signed
  24-bit index and signed 8-bit generation, and increments its reference using
  `fn_801F86C8(...,1)`. Failure clears the handle. These are refresh/acquire
  operations, not handle release helpers; this corrects the provisional
  release labels on earlier callers of `fn_801B3E54`.
- Resource, text-resource, owner-derived, embedded-handle, and occluder
  destructors with their observed virtual-table stores, nested null checks,
  member/base destructor calls, and optional object release preserved.
- Counted transfer of 32-byte records through `fn_801F2BD4`, a root-state reset,
  and a derived node-array initializer clearing the observed fields.
- A 276-byte loop visiting 144-byte node records. It validates the node handle,
  resolves the node and its nested handle through the cached manager, and
  updates the resolved object's float at `+18`.

## Verification and ownership

`python3 scratch/game_engine_loops_continuation/verify.py` recompiles all 16
current production sources with GC/1.3.2. It verifies every allocated section,
function binding, full size, offset, and all **94 real relocations**, resolving
SDA21, ADDR16_HA/LO, and REL24 addresses before comparing every byte with the
normalized original DOL. It rejects unknown targets, unexpected allocated
sections, and shortened original function extents. No relocation bits are
masked.

Only the physically adjacent refresh pair is grouped. All fragments use the
standard Game isolated flags except `801C866C` and `801D7DE8`, which require
`-opt nocse` to preserve the original repeated checks/table reads.

The independent audit also scans the complete original DOL `extabindex` and
`.ctors` tables. None of the 17 selected functions has an exception record or
constructor reference. The fragments emit and claim **zero data bytes**.
External virtual tables, constants, and all neighboring functions/data retain
their existing owners. The metadata-ownership hazard from the earlier
initializer batch therefore does not apply to these selected functions.

## Preserved unmatched probes

The 180-byte pool slot assignment, a nested resolved-float query, a resolved
handle replacement, and a prefixed-buffer-array destructor remain unmatched.
Their isolated sources and failed verification results are preserved. Failed
probes and diagnostic masked scores are not part of the canonical handoff.

## Accepted integration

The production units were strictly verified before Matching promotion. The
full DOL passes the original SHA-1, `ninja changes` reports no regressions,
source-extent/progress audits pass, and all 26 unit tests pass. Referenced
external data and adjacent original functions remain with their existing owners.
