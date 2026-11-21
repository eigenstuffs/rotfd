# Manipulator resource and native array-element constructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Status: frozen isolated exact source; central registration, original-DOL hash acceptance and progress credit remain with the integrator.

`src/Game/engine_manipulator_resource_ctor.cpp` reconstructs the complete 684-byte entry at `80211728..802119D4` as `ViewportManipulator_802EB130::ViewportManipulator_802EB130()`. It uses genuine `ObjectsRoot_80213EBC` / `ManipulatorDraw_802BC9D0` construction, a three-word array, four two-zero handles, and three native `Handle_80020B90` array elements. `src/Game/engine_manipulator_array_handle_ctor.cpp` independently reconstructs the complete 60-byte element constructor at `802119D4..80211A10`.

The constructor initializes its six scalar parameters, creates two pairs of name values, receives nontrivial handle returns from `fn_801B550C`, and retains distinct copied handle temporaries. The first full expression assigns the member at48. The second resolves that member by signed 24-bit index and generation, assigns the target member at1C, and calls `fn_8023D648` before destroying the copied and returned temporaries. Ordinary full-expression lifetime rules reproduce both destructor arguments, all stack slots, and all native registers. The two small-data name strings use their audited five- and seven-byte extents, which preserves actual SDA21 addressing.

GC1.3.2 standard `-O4,p -inline auto -Cpp_exceptions off` flags reproduce every retained byte. The 684-byte unit has44 retained real relocations and260 bytes of three unused weak destructors with6 relocations; the60-byte unit has1 retained real relocation and84 bytes of one unused weak destructor with2 relocations. Every allocated emission and raw weak body is inventoried, and no retained relocation references discarded weak code. There are no emitted data, BSS, padding, EH or startup-table allocations.

The full raw original extabindex `80015F60..8001F2C0`, constructor table `80299920..80299980` and destructor table `80299980..802999A0`, including descriptors and trailing zero slots, contain no references to either retained range. Original vtable ownership remains outside these text-only units. Its audited80-byte identity at802EB130 migrates from `lbl_802EB130` to `__vt__28ViewportManipulator_802EB130` with the original extent and attributes retained. The native array-element identity migrates from `fn_802119D4` to `__ct__15Handle_80020B90Fv` at the original60-byte extent.

The compiled old-name consumers are exactly `src/Game/viewport.cpp` (initial source; fn80211728 declaration and call) and `src/Game/owner_handle_array_init.cpp` (fn802119D4 declaration and array callback). There are no old-name header or vtable consumers. The exact inventory includes their current canonical manifests. Neither consumer nor any central symbols, splits or configuration was edited here; the integrator owns preserved originals, identifier-only migration and complete allocated-byte/resolved-target proof for consumers.

Strict handoff: `scratch/engine_manipulator_resource_ctor_20261010ci/final_integration.json`. Run its `verify.py` to recompile both production sources, apply real relocations, compare retained bytes, check all allocations and original table audits, and validate frozen hashes. Probe and intermediate evidence are retained in the same distinct namespace. No masked diagnostic result is claimed as matching progress.
