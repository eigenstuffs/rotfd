# Callback handle-chain accessors

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-callback-handle-chain.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

`src/Game/callback_handle_chain.cpp` reconstructs all **480 bytes** of three
complete adjacent original functions, `8025E11C..8025E2FC`. Each resolves the
owner handle at `+58`, then the resulting object's related handle at `+1C`.
Both lookups compare the packed signed 8-bit generation with the generation
in the 16-byte manager record and select the object pointer only on equality.
The original functions dereference the result without a separate null check;
the source preserves that behavior.

`fn_8025E11C` (184 bytes) calls the original two target cleanup helpers.
`fn_8025E1D4` (148 bytes) returns the address of an indexed word in the array
at target `+88`. The observed word span ends at the float fields starting
at `+B0`; the view expresses that member array directly. `fn_8025E268`
(148 bytes) reads the indexed float at `+B0`. These prefix views do not claim
the complete original class or original translation-unit boundary.

The source and its new private header are frozen in
`scratch/game_callback_handle_chain/candidate.json`. `verify.py` recompiles
and checks all allocated bytes, all three global function extents and **eight
actual relocations**. Every byte matches after applying real relocation
addresses; no data, vtables, exception sections or weak functions are emitted.
A raw pointer-arithmetic probe had five instruction differences; expressing
the observed word array as a C++ member resolved them. No byte patch or
assembly was used. Production/full-DOL acceptance remains required.
