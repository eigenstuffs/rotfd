# Registry pool growth

`src/Game/handle_pool_growth.cpp` reconstructs the complete 988-byte C++ function `fn_801F88AC` at `0x801F88AC..0x801F8C88`. Its isolated result is exact and ready for central integration. The original class names and full translation-unit boundaries are not claimed.

The method adds the requested count to the pool limit, resizes the slot array and the free-index array, records the new free count and limit, and fills the free-index array with descending new slot indices. The observed layout has 12-byte array descriptors at offsets `0x00` and `0x0C`, followed by the limit at `0x18` and free count at `0x1C`. Each slot is 16 bytes. Its constructor clears the object, hash, reference count and active flag, sets generation to one, and leaves the key and alignment bytes untouched.

The array template preserves both growth and shrink paths, including the compiler-emitted empty construction/destruction loops. Allocation, reallocation and freeing use the original shared allocator at `lbl_8028F698`. The accepted pool initialization and retain/release sources provide independent layout evidence; they were read without alteration.

The earlier `scratch/game_handles/pool_indexlong.cpp` reconstruction had the correct 988-byte body with 34 differing register bytes in the final unrolled loop. A local base pointer in the ordinary array accessor resolves those differences:

```cpp
T& operator[](int index) {
    T* base = data;
    return base[index];
}
```

This preserves the original reuse of the array-load temporary across the compiler's eight unrolled stores. A local element reference before the decrement independently produces the same exact instructions. No explicit unrolling, assembly, register binding, binary patching or new compiler switches were used. Bounded accessor probes and their results remain under `scratch/game_handle_pool_growth/`.

The compiler is `GC/1.3.2` with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on -i src/Game`. The retained function is a strong global symbol and preserves the original 32-byte stack frame.

`python3 scratch/game_handle_pool_growth/verify.py` verifies the original DOL SHA-1, all allocated ELF sections, the exact function extent and binding, and all 36 actual ELF relocations before comparing every retained byte. The relocations are recorded in `scratch/game_handle_pool_growth/relocations.json`; they resolve only to the existing allocator object and three allocation functions. Result: **988 code bytes, 36 relocations, zero differences**. The object emits no data, BSS, metadata, padding or unused helper functions. No original external storage receives source credit.

The candidate is `config/GSQE78/candidates/game_handle_pool_growth.json`. Full-DOL integration and native objdiff acceptance are verified below.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 988/988 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
