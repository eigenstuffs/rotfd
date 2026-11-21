# Selected hierarchy traversal

`src/Game/hierarchy_apply.cpp` reconstructs the two consecutive methods at `0x801FBFD0..0x801FC514`, totaling 1,348 code bytes. They own no data. The strict verifier `scratch/game_hierarchy_apply/verify.py` checks emitted section alignment, applies all 33 ELF relocations, and compares the entire allocated text section with the original. Both routines match with GC/1.3.2 and `-O4,p -inline deferred -use_lmw_stmw on`; full-DOL identity and native objdiff integration passed.

Both methods visit four handle lists selected by mask bits 1, 2, 4, and 8, in that order. Their observed count/capacity/data triples are at offsets `0xA8`, `0x90`, `0xD0`, and `0xC4`. Each selected entry is checked through the original validity helper, except the third list, which uses its indexed predicate. The handle then resolves through the manager's 16-byte entry table, preserving the signed 24-bit index and signed eight-bit generation comparison. A mismatched generation yields a null target, which is passed onward exactly as in the original. The two variants differ in the owner argument: one uses the hierarchy itself; the other resolves a supplied owner handle once before traversing.

The private types describe observed storage and do not claim recovered original class names. The floating-point argument and opaque context are passed unchanged to `fn_802073E8`. Its wider semantic meaning remains unestablished.

Matching required two ordinary source choices. Keeping the generation test as a conditional expression in the final call argument reproduces argument-register preparation before the handle lookup. Reusing one function-local loop index across the four loops reproduces the original induction-variable initialization and lifetime. Factoring the lookup into a returning helper was semantically equivalent but moved argument-register setup and prevented a byte match. Scratch variants preserve that evidence.

No raw assembly substitutes, patched instructions, volatile workarounds, or masked comparisons were used. The protected original DOL SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; the complete original source-file boundary is unestablished.
