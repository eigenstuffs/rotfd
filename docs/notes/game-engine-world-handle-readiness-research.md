# World Handle readiness sweep research

Private ordinary-source reconstruction of fn8026B038 at 8026B038..8026B440, 1,032 original text bytes. No production source, matching claim or central ownership change is proposed. All earlier accepted source and research remain unchanged.

The routine calls Root's qualified native slot1C and returns zero on false. Otherwise it applies virtual slot1C to generation-resolved objects from three dynamic Handle arrays, a scalar Handle, two eight-slot fixed Handle ranges, and two final scalar Handles, then returns one. The fixed ranges deliberately have no external validity test. Their stored counts bound iteration. The original high fields lie at C100..C16C; the same-layout probe keeps the intervening opaque storage explicit.

GC/1.3.2 O4,p/exceptions-off with LMW produces the exact 1,032-byte extent, all real relocation targets and every indirect-call/resolve instruction shape. The best separate_fixed.cpp and fixed_member_accessor.cpp still differ in 12 ordinary words: one zero-initialization move at the second dynamic loop, and saved-register/base-address allocation in the first fixed loop and the next loop's setup. No extra allocations or compiler helpers are emitted. The external fn801F7EB8 declaration is a truth-result-only unsigned view of its pointer return, as in the accepted action sweep; no pointer is consumed from that call.

Bounded alternatives preserve the complete artifacts: shared counter/offset declarations, first-loop initializer order, natural typed subscripts, independently scoped offsets, a distinct first counter, separate fixed-loop offset, chained zero initializers, an inline fixed-array accessor, and a genuine array visit member. All remain private. The most promising remaining structural question is the original lifetimes of the loop counters and the high fixed-array receiver, rather than resolver semantics.

Directory: scratch/engine_world_handle_readiness_20261011hm. It includes the original body, actual-relocation and all-allocation diagnostics, full original table scan, and active/original pointer/branch inventories. All current C and native identities remain unchanged.
