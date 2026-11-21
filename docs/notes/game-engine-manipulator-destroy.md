# Manipulator owner destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Status: frozen isolated exact source; original-DOL acceptance and progress credit remain with the central integrator.

`src/Game/engine_manipulator_destroy.cpp` reconstructs the complete544-byte C-entry `fn_80211508` at `80211508..80211728`, retaining its original global identity. The owner removes its membership when the group system and active flag permit it, using a distinct retained handle copy. It destroys the four wrapped handles and three native array elements, releases each element in its dynamic handle array, frees that storage, runs the inline drawing/root base cleanup and conditionally deallocates the owner. The ordinary inline helper structure preserves the original nested null checks and stride4 loop.

This is adjacent to the native constructor handoff in `engine_manipulator_resource_ctor_20261010ci`. Its80-byte vtable at802EB130 is referenced by the audited prospective native identity `__vt__28ViewportManipulator_802EB130`; the manifest retains `original_symbol=lbl_802EB130` for the integrator guard and claims no original data ownership. No constructor or destructor identity alias is introduced.

GC1.3.2 standard optimization flags plus `-use_lmw_stmw on` reproduce every retained byte and all30 real relocations. The compiler also emits264 bytes of three unused weak membership-handle destructors with6 relocations. They are fully inventoried by raw hashes and symbol extents; no retained relocation references them. There is no emitted data, BSS, padding, exception metadata or startup allocation.

The complete raw original extabindex `80015F60..8001F2C0`, constructor table `80299920..80299980` and destructor table `80299980..802999A0`, including descriptors and trailing zero slots, contain no references to this retained range. The existing initial-source viewport caller retains `fn_80211508` unchanged. Existing shared declarations, consumers, central symbols, splits and configuration were not edited.

Strict manifest and verifier: `scratch/engine_manipulator_destroy_20261010cj/final_integration.json` and `verify.py`. The original probe, all allocation evidence, full table audit and frozen production/header/script hashes are preserved in this distinct namespace. The reconstruction reuses the accepted membership helper semantics from the earlier owner-destruction work but owns a distinct complete function.
