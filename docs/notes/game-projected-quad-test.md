# Projected quad coarse test

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801B5D50..801B602C` matches all 732 original text bytes and both actual relocation targets under GC1.3.2 Gekko/O4,p, exceptions off. The initial ordinary source matched; production and fresh unchanged-core verification reproduce every allocated byte and exact GLOBAL function extent. No helpers, data/BSS, implicit literals, EH, startup or padding are emitted.

The query uses the already accepted 32-byte layout: position0, distanceC, direction10 and final float1C. Four 16-byte vertex pointers supply the quad corners; the normal and 48-byte result pointer are forwarded unchanged. The signed-char seven-argument ABI agrees with accepted `engine_grid_queries_801DF498.cpp`.

A nonzero direction.y selects the x/z projection, otherwise nonzero direction.x selects y/z, otherwise x/y. For each selected coordinate, the function rejects a query point strictly above all four vertices or strictly below all four. Surviving queries forward the existing `fn_80279558` result. The original GLOBAL zero `lbl_8037A250` remains borrowed under its existing .sdata2 owner.

Current native-symbol/canonical/body preflight scanned 1,693 manifests and 44,108 files without overlap or prior body. The fresh definition pattern excludes nested call parentheses so existing `if(fn_801B5D50(...))` consumer sites are not mistaken for definitions. A stable guarded audit scanned 5,610 active objects, 119,086 actual relocations and 777,360 initialized original words, proving unchanged config/object hashes, one original caller/entry reference, no aliases and no initialized pointers. Full original extabindex and terminal descriptor, ctor and dtor tables contain no ownership for this function. Existing grid-query caller source and C identity remain unchanged.

No shared header, native migration or new verification gate is required. Frozen handoff: `scratch/game_engine_batch253/manifest-list.json`. Root owns central integration and full native original-DOL acceptance.
