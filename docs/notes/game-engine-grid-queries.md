# Engine nearest collision scans over grids

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `fn_801DF498` and `fn_801DF604`, 364 retained text bytes each (728 total), zero data bytes and one actual relocation each. Existing external names are preserved. GC/1.3.2 uses the ordinary hardware Gekko optimization flags with exceptions off and `-use_lmw_stmw on`. Production source recompiles and passes strict original-byte, allocated-section, function extent and actual-relocation verification; parent integration and full DOL/regression checks remain required.

Each routine copies the 32-byte input query and scans an n-by-n grid of 16-byte vertices. Four vertex pointers advance through each cell and skip one entry at the end of a row; a parallel record pointer starts after the (n+1)^2 vertices and advances by 32 bytes per cell. The external intersection routine writes a 48-byte result record, matching the separately verified collision-result layout. A nearer hit updates the query distance and copies result normal, point and distance into the output. The return value records whether any qualifying hit was found. The pair differs only in the external callee, `fn_801B5D50` versus `fn_80279558`.

Private ordinary C++ vector copy construction and assignment reproduce the field loads/stores. Declaring the found flag before the vertex pointers reproduces original register assignment. Declaring the local result before the query reproduces original stack order; the complete 48-byte result extent reproduces the 0x80-byte frame. An initial truncated result declaration had a genuinely incorrect frame and remains uncredited research in scratch. No assembly, intrinsic substitutions or masked scoring are used.

`final_integration.json` under `scratch/game_engine_grid_queries_continuation` freezes source SHA256, empty recursive quoted-header inventories, all symbol extents, allocated bytes and actual relocations. Proposed central splits/configuration and `ownership_audit.json` are siblings. No weak/helper functions, data, BSS, padding, exception records or constructor/destructor references are emitted or owned. Full original-table audits use extabindex 0x80015F60..0x8001F2C0, ctors 0x80299920..0x80299980 and dtors 0x80299980..0x802999A0. Original surrounding functions and data remain assembly: these are partial text splits, 0x801DF498..0x801DF604 and 0x801DF604..0x801DF770.
