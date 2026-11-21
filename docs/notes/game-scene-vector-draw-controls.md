# Scene vector update and related draw callback

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two isolated production units match all original allocated sections and actual relocations; integrated production acceptance has passed.

`800E20BC` owns280 text bytes and20 exception table/index bytes. It conditionally resets the actor position, adds the original time-scaled vector and invokes virtual slot9C. The signed-byte flag query explicitly produces0 or1. Vector assignment and accumulation pass their three-float value by value, preserving the original native temporary copies. Retaining the actor pointer for the accumulation reproduces its original lifetime across those copies. All four floating-point constants remain external.

`800E2F84` owns272 text bytes and20 exception table/index bytes. It forwards four opaque arguments and a float to the selected component. Otherwise it resolves the Handle returned by virtual slot9C and invokes the original fallback only when flag bit2 is clear. The returned Handle is a reference, with no temporary ownership or destructor allocation. Native `-proc 750` reproduces the original floating-point save and exception-vector setting.

Both units emit only their primary text and original exception allocations. There are no additional data, weak definitions, padding, aliases, startup allocations, consumer edits or identity changes. Complete original extabindex/startup-table scans and initialized-data references are frozen in `scratch/game_scene_callback_controls_extended/ownership_audit.json`. The production recompile verifier requires every source/object hash, allocation, symbol extent and actual relocation.

The adjacent `800E3094` allocator routine is preserved as private research only. Its300-byte extent and original relocation targets are established, but14 saved-register operands differ. Native placement construction retains the already established Object_800E1A28 constructor identity. Bounded argument-type, helper and compiler-option variants did not establish a retained match and receive no source credit.
