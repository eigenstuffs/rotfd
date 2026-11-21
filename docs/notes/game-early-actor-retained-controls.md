# Early actor retained controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ routines recover 372 text bytes and 112 bytes of original exception metadata/index. Both use standard GC1.3.2 Gekko `-O4,s`, exceptions on, the established native `Handle_801F7F10` lifetime, and the existing bounded `production-defined-weak-eh-override-v1` proof. Production sources use prefix `early_actor_retained_control_`; the dedicated header has two production consumers.

| Address | Text bytes | Behavior |
| --- | ---: | --- |
| 800A7798 | 168 | When its signed activity byte is zero, retain its handle in a full-expression temporary, bind it to the indexed list, then start the owner |
| 800B5188 | 204 | Stop the owner, retain its handle for indexed list removal, clear activity/scalar, and invoke the output service's virtual clear operation |

Capturing the original handle by const reference before constructing the native retained temporary reproduces saved-register lifetimes and all reference-count calls. Each primary has 44 original exception bytes and a 12-byte index. The retained-EH references to native `Handle_80021BCC` and `Handle_8002F6B0` destructors are independently proven against their existing strong production owners. Neither strong owner or its consumers is edited.

Each object emits three unused weak destructor backups totaling 348 text and 156 metadata bytes. Every backup section, extent, actual relocation and raw hash is inventoried separately; it earns no matching credit. The extra private zero-layer destructor has a unique per-source name (`RecordZero_800A7798` or `RecordZero_800B5188`) and must be absent from the final ELF. The two original native weak destructor definitions must resolve to their proven existing strong owners, with all source backup code/EH discarded. No new gate or schema is introduced.

Strict all-allocated-byte/actual-relocation verification passes, accounting for 29 retained and 42 backup relocations. Full original extabindex (`80015F60..8001F2C0`), constructor (`80299920..80299980`) and destructor (`80299980..802999A0`) ownership scans pass. A complete initialized original word scan identifies the source's EH index and one existing callable-table consumer for `800B5188`: `lbl_802BD800` (`802BD800..802BD858`), entry `802BD848`. That table remains original-owned and unchanged. No data/BSS/padding, native identity migration or alias is introduced. Final original-DOL/native backup-discard acceptance remains with the integrator.

Private uncredited probes are preserved: `800AEE00` has exact 244-byte extent with five call-argument register/order differences; `800B4D1C` emits 296 versus 300 bytes because its inlined name lookup loses an original copy store. Bounded name/ref/value/getter variants did not close them. Original code/EH/data for both remain outside retained ranges.

Handoff, complete production manifests, original asm, header consumer inventory and frozen hashes are under `scratch/game_engine_batch138/`. Initial freeze preflight correctly stopped upon finding the extra original vtable consumer; `freeze_resume.py` records its precise unchanged original ownership without widening source allocation.

Accepted on 2026-10-12: `early_actor_retained_control_800b4d1c.cpp` owns
300 text bytes and its 44-byte extab plus 12-byte index. The implicit Name
copy constructor preserves the native stack argument copy; both prior
complete header consumers are unchanged. Frozen evidence is under
`scratch/literal_group_20261012_b/retained-control/` and
`scratch/continuation_20261012_b/startup-retained-native-proof.json`. The
original full DOL hash, baseline comparison, coverage and extents audits,
strong destructor selection/complete backup discard, and all 66 tests pass.
