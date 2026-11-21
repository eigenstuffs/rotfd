# Transformed sphere clipping investigation

Uncredited isolated research: `fn_801B6338`, 248 original bytes. No production source or central changes. Scratch sources, objects and strict actual-relocation failures are retained in `scratch/game_engine_clip_queries_continuation`; the reservation is released.

The routine transforms the sphere center through the first three affine matrix columns, scales its radius independently along each output axis, and tests against the original two bounds. `-fp_contract on` reproduces the fused arithmetic; the first 88 bytes of the direct ordinary scalar form are exact. The remaining nineteen real word differences concern floating-register allocation. Ordinary local radius declarations, vector fields/constructors, nontrivial assignment and named-result affine helpers do not solve the register differences. No masked comparison is accepted as a match. Full original exception/constructor/destructor prechecks find no references to the target.
