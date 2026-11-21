# Named actor flag clear

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_800AEE00` looks up the named scene resource, resolves its returned Handle, releases the temporary, and calls the resource operation before setting flag `0x40000` and clearing `0x20000` in its 64-bit flags at offset `0x38`.

The ordinary source in `src/Game/early_named_actor_flag_clear_800AEE00.cpp` matches all244 text bytes and the original8-byte exception record at80011078 plus12-byte index at8001BE34. GC1.3.2, processor750, O4,s and C++ exceptions on are required; the original exception record has no Elf Vector flag. The signed-byte third argument to80058778 restores the native hidden-return/Name argument order. A private genuine derived Handle return object gives the original base destructor argument0 and preserves the original full-expression cleanup. Earlier raw Handle probes remain unchanged.

The strict verifier accounts for every allocated byte and real relocation. Twelve retained relocations and four unused backup relocations are recorded. One private weak return-wrapper destructor emits76 text bytes and20 metadata bytes; these are uncredited and must be discarded in the final native link. No strong weak override is required. There are no non-EH data, BSS or padding allocations; the existing registry string802A0178 stays external.

Complete original extabindex80015F60..8001F2C0, ctor80299920..80299980 and dtor80299980..802999A0 audits pass. The complete initialized-word scan finds only the owned index and unchanged callback pointer802BD4E8 in original24-byte tablelbl802BD4D4. No existing source/header consumer uses this entry. The original C entry spelling is retained.

Frozen handoff: `scratch/game_engine_batch168/HANDOFF.md`. Repeat `python3 scratch/game_early_named_actor_flag_clear/verify.py`. Isolated verification passes; central original-DOL hash, native helper discard and no-regression acceptance remain pending. No progress credit is claimed before integration.
