# Aligned allocation wrappers

`src/Game/platform_heap_aligned_resize.cpp` owns `fn_8028F8AC` at
`8028F8AC..8028F8F0` (68 bytes). `platform_heap_aligned_alloc.cpp` owns
`fn_8028FACC` at `8028FACC..8028FAF4` (40 bytes). Both round sizes with
`(size + 31) & ~31U`, preserving native unsigned arithmetic. Resize returns
the supplied pointer when both rounded sizes are equal; otherwise it calls
the underlying resize operation. Allocation calls the original pool allocator.

The two partial text splits use GC/1.3.2, `-O4,p`, automatic inlining,
exceptions disabled, and `-use_lmw_stmw on`. They own no data, BSS, exception
records, helpers, or padding. The allocator context and other functions remain
outside these splits.

`python3 scratch/game_heap_aligned/verify.py` recompiles production source,
audits all allocated sections and symbol extents, resolves each actual branch
relocation, and compares all 108 bytes with the supported original DOL. Each
object has one separately checked nonallocated compiler-metadata relocation.
Full integration passes the original DOL SHA-1 and native objdiff checks.
