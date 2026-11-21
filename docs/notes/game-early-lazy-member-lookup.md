# Early lazy scene member lookup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80058F40` is reconstructed with its original C identity and single owner argument. If the first Handle at `+2F8` is valid, it leaves all seven members unchanged. Otherwise it performs seven named lookups through manager virtual slot `28` (manager table at `+24`) and retains the resulting Handles in consecutive members `+2F8..310`. This establishes the member storage also consumed by the adjacent sparse dispatcher at `80059340`; the private owner and manager views describe only observed offsets.

The retained ownership is text `80058F40..80059340` (1,024 bytes), extab `8000A2F0..8000A4D4` (484 bytes), and index `8001809C..800180A8` (12 bytes). The first ordinary C++ probe reproduces every instruction and stack lifetime with GC1.3.2 and established `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags. There are 77 real retained relocations and 14 backup relocations. Seven names at original shared pool `lbl_8029ACA8+6A0/6BC/6D8/6F4/710/72C/748` remain external original data; their original bytes and hashes are recorded. No pool, table, startup entry, compiler identity, or shared declaration changes are proposed.

Retained EH references the existing native strong destructors `Handle_8001FF78` and `Handle_8005287C`. Both canonical sources, recursive quoted headers, production objects and fresh recompiles were independently verified with their actual original relocations. The unchanged strict weak/EH verifier proves complete allocated ownership and original retained bytes after real strong resolution. The two compiler backup destructors total 228 text bytes plus 104 EH/index bytes, which receive no credit. An actual MWLD link selects both accepted strong inputs and discards all six backup text/EH/index allocations; the incorrect fixture-basename rejection passes.

The original full EH/startup tables and every initialized data word were scanned. Only the owned original index points into this function; no constructors or destructors transfer. Existing C entry consumers are inventoried and remain unchanged. This is a partial original translation unit: all other original code and data ownership remains external.

The independently frozen source, manifest, compiler proof, ownership audit, full allocation/relocation inventories, and standalone strict/native verification are in `scratch/game_early_lazy_member_lookup_continuation/`. The parent integrator must still pass the original full DOL hash, regressions, source extents/progress and repeated native audits before crediting this unit. No older handoff or verifier core was changed.
