# Early motion input update

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_motion_input_update_80077678.cpp` reconstructs `80077678..80077A48` (976 text bytes), with extab `8000D004..8000D00C` and extabindex `800195FC..80019608`. GC1.3.2/Gekko with O4,s and exceptions enabled emits no extra allocations, weak helpers or owned literals. All 38 actual relocations and all allocated bytes match in isolated production verification. Native link/full-DOL acceptance is pending with the central integrator.

The routine reads four motion axes, updates activated/timer/direction state for the current control mode, gates actor controller state through a generation-checked Handle, and applies bounded vertical motion. Ordinary `__fabs` followed by float conversion reproduces the original fabs/frsp sequence. Concrete members recover the original state layout. Declaring the two byte settings in reverse order, then initializing them in call order, naturally gives their original adjacent stack addresses and store order.

`freeze.py` records complete original extabindex/descriptor, ctors/dtors and initialized pointer-word ownership, plus existing source consumers; no callable data table points at this function and the original external callees and SDA data stay unchanged. `verify.py` recompiles the production source and repeats strict allocated-byte/actual-relocation verification. Frozen batch 208 includes this unit only.

The related 632-byte angular gate at 800768C0 remains private and uncredited under `scratch/game_early_motion_angle_gate`. Its exact diagnostic needs a natural four-byte 360.0f literal whose original global identity has other consumers; no data transfer or alias is authorized.
