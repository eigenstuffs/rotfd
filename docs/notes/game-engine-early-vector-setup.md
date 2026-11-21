# Early vector and scalar setup functions

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This isolated tranche recovers 24 original C entry points, 2,944 bytes of text and 480 bytes of compiler-emitted exception tables/index records. The existing global function names and all caller identities are preserved. Private fields are named by observed offsets; these views establish only the accessed layouts, not original class names.

Each routine calls one existing base/setup entry and then writes tables, words, bytes, floats, and/or zero vectors. The families include base table pointers at offset 0 or 8, secondary tables at 0x318 whose pointer is the primary plus 0x170, and arrays of three floats copied from the existing `game_vec3_zero`. The shared vector is declared as an external mutable float array: no source writes that global, but its aliasing relationship with float fields preserves the original interleaved loads/stores. A const-vector declaration incorrectly hoisted or reused loads in eight functions; those diagnostic differences are preserved in `report_const_vec.json` and receive no credit. External SDA float labels remain owned by their original data units.

Functions 80096AD4 and 8009AB58 are ordinary void setup/reset methods; they do not restore `self` as a return value. All other entries return their original `self` pointer. Existing incoming opaque word arguments are preserved where the code stores them after its base call. The callees in this tranche take only their observed `self` argument.

The production compiler is GC 1.3.2 with the established container-base flags, including `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. Strict verification checks every emitted allocation, symbol, raw owned byte, and real relocation. Each split owns its function plus the original eight-byte extab and twelve-byte extabindex record. The complete original extabindex and constructor/destructor tables are audited; no constructor/destructor registration pointer is moved. No aliases, assembly, masked comparisons, or extra output are used. These are bounded recovered fragments, not recovered original translation-unit boundaries.

`handoff.json` freezes source, recursive-header inventory (none), note, manifests, verifier, original ownership audit, and exact integration instructions. Root integration and the full original DOL hash remain required before progress is credited.
