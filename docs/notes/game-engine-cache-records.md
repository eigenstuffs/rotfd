# Engine normalized string lookup and cache record research

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `scratch/game_engine_cache_records_continuation/final_integration.json`.
`fn_801B4C30` reproduces **228 original text bytes**, zero data and **seven actual relocations** under standard GC/1.3.2 flags. Production recompilation passes strict byte/relocation verification. All emitted allocations are accounted; there are no weak helpers. Production source SHA256 and empty recursive quoted-header inventory are frozen. Central integration/full DOL acceptance remain the integrator's responsibility.

The function copies its input name into the original 128-byte stack buffer, normalizes it with `fn_801F459C`, then iterates occupied bits using `fn_80207B94`. Pool strings are 129 bytes each. A matching `strcmp` returns its slot index. Otherwise `fn_801B4D14` supplies a new slot, the normalized string is copied into it, and that index is returned. The private pool view at owner+0xCC exposes count/capacity/data at +0/+4/+8, occupancy storage at +0xC, and logical slot limit at +0x1C. The direct conditional next-index expression reproduces the original rematerialized bitset pointer and avoids a compiler-only extra saved register.

Exact retained split is `.text 0x801B4C30..0x801B4D14`. This is a partial text-only split of original fragment `auto_03_801B4BF0_text`; its empty hook, virtual reset callback and string-pool insertion function remain assembly. The fragment owns no data. Complete original extabindex and constructor scans find no metadata for the retained function. Original external symbols are preserved. See adjacent `final_splits.txt`, `final_config.txt`, and `ownership_audit.json`.

Uncredited bounded research remains only in scratch:

- `fn_801B4D14` (712 bytes) reuses a free slot or grows text capacity by 32, grows occupancy-word storage, sets its slot bit and updates counts. Ordinary delta reserve, placement initialization and reverse destruction reproduce its complete original extent and all words except the swapped independent `li r4,1` / `clrlwi r0,r3,27` at offsets 0x298/0x29C. Literal, field, helper and local-expression variants preserve that near. No production source exists.
- `fn_801D864C` (352 bytes) resolves an owner handle, unlinks/prepends a 12-byte cache row through verified link operations and converts 0x90-byte resource records into 0x68-byte owner records. The closest ordinary inline loop variants differ in register allocation. No production source exists.
- `fn_801D87AC` (352 bytes) clears cache-row ownership for each non-sentinel record index at +0x60, destroys/frees its record array, calls the base destructor, and optionally frees the object. Its closest ordinary source differs in three words: indexed halfword addressing versus the original base-plus-offset followed by `lhz +0x60`. All remaining bytes match, including the compiler-generated empty destruction loop. No production source exists.
