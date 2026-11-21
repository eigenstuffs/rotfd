# Engine native-handle array capacities

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `fn_801D1D6C` and `fn_801D21A4`, 556 retained text bytes each (1,112 total), zero data bytes, and 29 actual retained relocations each (58 total). Ranges are 0x801D1D6C..0x801D1F98 and 0x801D21A4..0x801D23D0. Existing external names are preserved. GC/1.3.2 uses the ordinary hardware Gekko optimization flags plus `-use_lmw_stmw on`, with exceptions off.

Both routines operate on an ordinary count/capacity/pointer array of native handles. A requested capacity below the live count clips the array with element destruction and reallocates storage; otherwise the routine changes capacity without changing the live count. Native handle construction is followed by two observed zero-initializing derived layers. Element destruction follows that same hierarchy. The retained code matches exactly using private C++ declarations and ordinary allocation, construction, destruction, and loop expressions.

Reusing one ordinary loop index declared outside both growth and shrink branches reproduces the original register allocation. Separate branch-local indices produced four genuine instruction differences. No assembly or relocation masking is used.

Each object also emits one unreferenced weak `Zero1` cleanup destructor, 84 bytes at object offset 556. Their names are `__dt__14Zero1_801D1D6CFv` and `__dt__14Zero1_801D21A4Fv`; both have raw SHA256 `fdd9fcf5ab58f46f986c50b59ae57e9c65a7b53acdde19888e0e8987b285adb0`. Each has two actual relocations, to the native handle destructor and `__dl__FPv`. These 168 bytes and four relocations are fully inventoried but uncredited; central acceptance requires both weak symbols to be absent from the final ELF.

`final_integration.json` under `scratch/game_engine_handle_arraycopy_continuation` freezes source SHA256, empty recursive quoted-header inventories, all retained and unused symbol extents, all allocated sections and actual relocations. Proposed central split/config edits and `ownership_audit.json` are siblings. Strict production recompile through `verify.py` passes, accounting for all 1,280 emitted text bytes. No data, BSS, or padding is emitted. Full extabindex, constructor, and destructor table audits find no owned records. The remainder of original 0x801D0650..0x801D23D0 stays assembly: this is a partial text split. Parent final DOL and regression acceptance remain required.

The neighboring copy routines `fn_801D1B60` and `fn_801D1F98` remain uncredited research. Their 524-byte probes each have six genuine register differences in an inlined growth path. Bounded loop, constructor-shape and optimizer variants did not resolve them. No source or integration ranges are published for those routines; their reservations are released.
