# Early quaternion callback and indexed record controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ functions match all emitted allocated bytes and actual relocation targets in isolated production compilation. Central original-DOL/regression acceptance remains pending.

| Function | Text | Original extab | Original extabindex | Actual relocations |
|---|---:|---|---|---:|
| fn800AB950 |144|80010CE0..80010CE8|8001BCCC..8001BCD8|8|
| fn800B3288 |144|800116EC..800116F4|8001BFA8..8001BFB4|12|

GC1.3.2, processor Gekko, O4,s, exceptions on, use_lmw_stmw on. Each isolated source emits only its144-byte GLOBAL C entry and exact8/12-byte local exception objects (@6/@7). There are no weak backups, owned literals, other data, BSS or padding.

AB950 forms a quaternion from constant-angle cosine/sine, then forwards it to virtual slotC0 through its actor pointer. Declaring the cosine local before the sine call and constructing the quaternion afterward preserves original f31 save/lifetime; storing it into the stack quaternion before the second call produced124 bytes. B3288 initializes a20-byte indexed record with four independent random-value calls and borrowed scalar constants. Its first ordinary array-field probe was exact.

Full original3141-entry exception-table/descriptor and constructor/destructor table audits confirm only each owned exception index and no startup registration. An all-initialized-DOL-word scan finds AB950 also referenced by the original untouched GLOBAL lbl802BCEF0 table (1C bytes) at802BCF08; B3288 has only its exception index. Neither source has compiled source/header consumers requiring identity migration. Both original C identities remain unchanged; all borrowed constants, trig/random functions and the original callback table retain their existing owners.

Frozen evidence: scratch/game_engine_batch189/HANDOFF.md and manifest-list.json; strict production verifier/objects, actual relocation inventories and full ownership audits in scratch/game_early_callback_value_controls. No configure, symbols, splits, baseline, source denominator or expected hash was changed by this handoff.
