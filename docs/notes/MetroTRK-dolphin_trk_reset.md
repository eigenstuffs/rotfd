# MetroTRK exception-vector installation

`src/MetroTRK/dolphin_trk_reset.c` recovers the 260-byte C __TRK_reset at 0x80005330..0x80005434 in the original .init section. The [Melee Dolphin target source](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/dolphin_trk.c) supplies the reset wrapper, vector-copy loop and address translation. The original compiler inlines the latter helpers into __TRK_reset.

The routine reads the exception mask at translated address 0x44, tests all fifteen supported vector bits, copies each selected 256-byte vector from the original vector table to its translated address, and flushes its cache range. Translation reuses the exact locked-cache-window logic recovered in dolphin_trk_target.c. The private inline copy is required by this fragment boundary and does not introduce another exported translator or mutable state object.

The source owns the fifteen-entry TRK_ISR_OFFSETS array, 60 initialized bytes at 0x802CFE50..0x802CFE8C in .data with alignment 8. It is compiler-local and records vector offsets 0x100 through 0x1700 in the original order. The following four bytes to 0x802CFE90 are external alignment padding before the transport table. The .init section alignment is 4. The original gTRKInterruptVectorTableEnd label shares __TRK_reset's start address; it remains a boundary label, not another function.

GC/1.3.2 with the ordinary MetroTRK auto,deferred flags reproduces all 260 code bytes, every relocation and all 60 array bytes. The manifest is config/GSQE78/candidates/MetroTRK-dolphin_trk_reset.json, with isolated scripts under scratch/MetroTRK. The existing interrupt-vector machine code and TRK_flush_cache remain original assembly fallback and receive no C credit from this routine. The integrated source passes whole-DOL byte equality, native objdiff code/data checks, and the original-source regression audit.

The complete original vector-image extent and its native-report classification are recorded in [the vector-image note](MetroTRK-interrupt-vector.md). The full image remains NonMatching; its denominator correction does not add recovered source.
