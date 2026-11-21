# Early actor motion query output

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

fn_80092064..8009237C is reconstructed as an ordinary Vec3 value-return function with a hidden return pointer. The actor query supplies three local vectors and a resource with its transform at124. Two transformed points, wide flags, controller38/6 gates, and the actor448/449 state determine position and displacement outputs; the function returns the transformed movement or the original global zero vector.

GC1.3.2/Gekko/O4,s/exceptions on emits exactly792 text bytes, original8-byte extab8000EF58, and12-byte index8001A988. All8 actual relocations and every allocated byte pass the unchanged strict verifier; fresh production compilation is deterministic. Compiler locals are @83/@84. No weak helpers, additional allocations, owned literals, BSS, padding, symbol migrations, or new gates.

The transform helper writes x/y/z of a Vec3 result and returns it. This source structure preserves both original floating register lifetimes: a direct return constructor had25 operand differences, explicit XYZlocals left6, and ordinary result field assignments close them. Original callback table lbl802B93F4[1A4] and pointer802B9504 remain assembly-owned and unchanged, as does game_vec3_zero. Full original exception table/descriptor, constructor/destructor tables, initialized pointer words, and compiled source consumer inventories are preserved in ownership_audit.json.

Frozen integration handoff: scratch/game_engine_batch205/HANDOFF.md. Repeat scratch/game_early_motion_query_output/verify.py. Isolated source is exact; root performs native placement, original DOL hash, baseline/regression/extents/progress/tests and prior proofs before acceptance.
