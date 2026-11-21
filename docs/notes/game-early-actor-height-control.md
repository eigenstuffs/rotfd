# Actor height and control state transitions

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

fn80096C98 owns676text at80096C98..80096F3C,8exception bytes at8000F4D0..8000F4D8 and12index bytes at8001AD18..8001AD24. Ordinary C++ source src/Game/early_actor_height_control_80096C98.cpp matches all retained bytes and16actual relocations using GC1.3.2/Gekko/O4,s/exceptions on/use_lmw_stmw. No other allocated section or helper is emitted. Central original-DOL acceptance remains pending.

After updating actor actions, the routine skips controls3/4. It resolves the selected actor through registry and related handles, queries distance and virtual target geometry, and compares distance/height against actor thresholds. Control and event gates select control7; a separate distance/control6 branch selects control8. All floating operations are ordinary comparisons and addition, without estimate intrinsics or conversion literals.

The initial typed reconstruction had25 saved-self/target r29/r30 exchanges. Caching const Entry*entries before the generation comparison, using an ordinary getTag accessor and a wide int tag local, naturally restores the exact saved-register lifetimes. A distinct concrete RootNode entry preserves the nested manager reload. Independent void/Word-return helper variants also matched but are retained only as private research; the production source keeps typed Node pointers.

Complete original EH records and final descriptor, ctor/dtor tables, initialized pointer words and source-consumer inventory were audited. Original GLOBAL callback table lbl802B9D24[1AC] keeps its unchanged pointer802B9D5C. No native identities/callers change; no literals/data/BSS/padding or weak backups are owned/emitted. Strict production and deterministic fresh recompile pass all allocations and actual relocations. Frozen evidence is listed in scratch/game_engine_batch197; integration must still pass original-DOL/hash/baseline/extents/progress/tests. This isolated split does not claim whole original translation-unit recovery.
