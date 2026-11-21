# Native volume table and callback records at 0x802B2B60

`src/Game/native_volume_tables_802B2B60.cpp` owns the 144-byte native method table at `0x802B2B60` and its 144-byte array of twelve member-function records at `0x802B2BF0`. The method table retains its runtime type pointer and exact native function targets. Each member record has three four-byte words: receiver adjustment, virtual slot and table offset. These are bounded ABI views rather than a complete class declaration.

GC/1.3.2 emits a single 288-byte `.data` section at the original eight-byte-aligned address. Native objdiff reports 100% data, including all actual relocations. The full DOL hash passes, `ninja changes` shows no regression, all 66 tests pass, and generated progress/extents verify. No neighboring data or code is claimed.
