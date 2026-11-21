# Child geometry query probes

Research only; no matching-source credit or proposed integration.

The untouched functions `fn_801D32CC` (400 bytes) and `fn_801D345C` (440 bytes) perform an initial transformed-sphere bounds check, refresh paired child state through `fn_801D38A4`, then visit paired handle arrays and call child virtual slots 0x48 and 0x44 respectively. The observed ABI uses two 64-bit masks; the first starts at r9/r10 and the second is stack-passed. Handle words contain signed generation/index bitfields of widths 8/24. Manager entries are 16 bytes, with object at 0 and generation at 0xC; generation equality gates the lookup.

The best 400-byte source probe reproduces the initial sphere transformation, scalar copy, bounds check, saved arguments, and first lookup exactly under the ordinary compiler flags plus `-use_lmw_stmw on`. Its second lookup prepares argument r4 and stack mask words at different points, leaving 23 genuine instruction differences. Inline child/state forwarding, explicit handle member helpers, two-wide-mask declarations, and a bounded optimizer pass did not resolve them. The 440-byte sphere pair also elides a 12-byte vector stack temporary and changes FPR allocation. Neither is accepted.

Sources, isolated objects, actual-relocation comparisons, and failure inventories are preserved under `scratch/game_engine_child_queries_continuation`. `batch_integration.json` and all retry integration manifests are empty. Every attempted function has no original extabindex or constructor record. Original ownership and all original bytes remain unchanged. These reservations are released.
