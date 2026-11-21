# Controller status and storage lifecycle

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-controller-status-lifecycle.json`. The full normalized DOL
passes its original SHA-1, `ninja changes` shows no regressions, source extents
and generated progress checks pass, and all 26 unit tests pass.

`src/Game/controller_status_lifecycle.cpp` reconstructs two consecutive
engine functions:

| Function | Original range | Bytes |
| --- | --- | ---: |
| `fn_80276754` | `80276754..802767D0` | 124 |
| `fn_802767D0` | `802767D0..8027696C` | 412 |

The first enables status byte `70`, logs the original message, clears the eight
following bytes, enables PAD recalibration and returns 1. The second installs
the original derived virtual table, invokes shutdown through virtual slot
`0C`, installs the original base table and destroys its two 64-byte record
arrays in reverse member order. The empty per-record destruction loops and
both native null checks remain present before freeing backing storage. A
positive signed low-half deletion flag releases the receiver.

The virtual interface has a 28-byte nonpolymorphic base, placing its pointer
at `1C`. The declarations emit no new virtual table or method bodies. Array
cleanup reuses the frozen `PollRecord` layout and preserves its original
count/capacity/data descriptor.

GC/1.3.2 with standard optimized Game flags reproduces all 536 emitted bytes
after nineteen actual relocations. Run:

```
python3 scratch/game_controller_status_lifecycle/verify.py
```

The verifier requires both original global symbols and `.text` only, checking
every allocated byte and relocation. There are no weak helpers, constants,
data, BSS, constructor/destructor tables, exception tables or owned padding.
The protected-DOL original extabindex, `.ctors` and `.dtors` audit finds no
exception entry overlapping either function and no reference into the retained
range. `candidate.json`, `actual_relocations.json` and
`original_metadata_audit.json` preserve the complete isolated evidence.

This partial text split leaves the original virtual tables at `802ED6F8` and
`802ED740`, message at `802AF120`, allocator storage and neighboring routines
under existing ownership. Full DOL linking, native objdiff, source-extent
auditing and regression checks remain the integrator's acceptance step.
