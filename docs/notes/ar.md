# Dolphin audio RAM driver

`src/dolphin/ar/ar.c` recovers all 6 linked C functions at `0x800FF424..0x80100E90` (6,764 bytes).

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| ARRegisterDMACallback | 0x800FF424 | 0x44 | global |
| ARStartDMA | 0x800FF468 | 0xF0 | global |
| ARInit | 0x800FF558 | 0xC4 | global |
| ARGetBaseAddress | 0x800FF61C | 0x8 | global |
| __ARHandler | 0x800FF624 | 0x78 | local |
| __ARChecksize | 0x800FF69C | 0x17F4 | local |

The [Pikmin 2 AR reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/ar/ar.c) supplies the exact DMA, initialization, interrupt, and size-detection algorithms. The target's version string identifies September 5, 2002. Unlinked allocation/getter APIs and unused declarations are omitted. DMA read/write, interrupt acknowledgement, and transfer polling helpers are explicitly inline because no out-of-line copies occur here. The interrupt handler and size probe retain their original static linkage.

The 6,132-byte size probe uses eight local 63-byte arrays rounded to 32-byte addresses. It preserves old audio-memory contents, writes distinguishing patterns, probes address aliasing, selects memory-controller size/mode bits, restores the saved contents, and publishes the detected size through the uncached low-memory mapping. All memory transactions, waits, flushes, and synchronization calls are retained. The stack and hardware access pattern are exact; no generated assembly substitutes for the probe's C algorithm.

`.data` is `0x802CA920..0x802CA964` (68 bytes), the version literal. Four following alignment bytes are outside the unit. `.sdata` is `0x80375D60..0x80375D64` (four bytes), the version pointer, also followed by four external padding bytes. `.sbss` is `0x80377B00..0x80377B20` (32 bytes), eight private four-byte values. No ordinary BSS is owned. All sections have alignment 8. Literal and state sizes are recorded individually in the candidate manifest.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @1 | .data | 0x802CA920 | 0x44 |
| __ARVersion | .sdata | 0x80375D60 | 0x4 |
| __AR_Callback | .sbss | 0x80377B00 | 0x4 |
| __AR_Size | .sbss | 0x80377B04 | 0x4 |
| __AR_InternalSize | .sbss | 0x80377B08 | 0x4 |
| __AR_ExpansionSize | .sbss | 0x80377B0C | 0x4 |
| __AR_StackPointer | .sbss | 0x80377B10 | 0x4 |
| __AR_FreeBlocks | .sbss | 0x80377B14 | 0x4 |
| __AR_BlockLength | .sbss | 0x80377B18 | 0x4 |
| __AR_init_flag | .sbss | 0x80377B1C | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ar -Cpp_exceptions off` and peephole optimization enabled. The isolated scripts in `scratch/ar` resolve every call, pointer, and small-data relocation, then compare all 6,764 code bytes and 72 initialized data bytes against the original DOL. No assembly fallback is needed within this unit; existing external hardware helper routines remain outside its source coverage. Whole-DOL SHA-1 and native objdiff remain the integration checks.
