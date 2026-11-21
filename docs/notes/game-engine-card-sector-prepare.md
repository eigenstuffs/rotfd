# Memory-card sector preparation

Isolated ordinary C++ source matches fn_802776D0 at 802776D0..80277918: **584 text bytes and 37 actual relocations**. Original-DOL acceptance is pending with root. The original C entry, all dependency names, and existing callers remain unchanged.

The routine queries the card sector size, requires 8192-byte sectors, checks the card, and queries free bytes/files. Each CARD operation retries busy result -1 up to 1000 attempts. While polling, it preserves reset-switch transitions in the original signed-byte globals, logs a released reset switch and requests reset, logs a held reset switch, and logs retry exhaustion. It returns zero on an unsuccessful sector/check stage and normalizes the final free-space result to zero or one.

The source uses the existing MemoryCardOwnerView fields and includes its unchanged header. The first probe had the original extent and one boolean-result mask difference; expressing the final normalization as `result ? 0 : 1` gives the original integer normalization and closes every byte. The borrowed message pool uses its original external base address; all pool bytes and reset state remain outside this unit.

Compiler: GC/1.3.2 standard Game flags, -O4,p and exceptions off, plus -use_lmw_stmw on. The complete production object contains exactly one 584-byte .text function. There are no unused helpers, weak duplicates, data, BSS, EH, startup allocations or owned padding. The strict verifier resolves all 37 actual relocations to original targets and audits every allocation/symbol.

The complete original extabindex 80015F60..8001F2C0 (including descriptor/padding), ctor 80299920..80299980 and dtor 80299980..802999A0 ranges have no references to this body. Existing memory_card_prepare.cpp and memory_card_query.cpp consumers use the same C entry and same shared owner view; their current hashes are inventoried and no edits are required. Adjacent card/TPL bodies, shared message pool, and every original data owner retain their existing ownership.

Production strict bytes/actual-target/full-allocation and frozen hashes pass. final_integration.json, final_splits.txt, final_config.txt, consumer_inventory.json and original_full_tables.json form the isolated handoff. Root owns central integration and final hash/regression acceptance. No existing source/header, central configuration or original input was modified.
