# Dolphin audio interface

Two C fragments recover 21 functions and 2,224 code bytes from the linked AI unit. `src/dolphin/ai/ai.c` covers `0x800FEB1C..0x800FF1E8` (20 functions, 1,740 bytes); `ai_src.c` covers `0x800FF240..0x800FF424` (one function, 484 bytes).

The 88-byte `__AICallbackStackSwitch` at `0x800FF1E8..0x800FF240` remains original assembly fallback. It saves the current stack, changes to a caller-supplied stack, invokes a callback, and restores the original stack. Public reference assembly is preserved in the reference sources for research, without adding assembly to production source or C completion totals.

| Function | Address | Size |
| --- | --- | --- |
| AIRegisterDMACallback | 0x800FEB1C | 0x44 |
| AIInitDMA | 0x800FEB60 | 0x88 |
| AIStartDMA | 0x800FEBE8 | 0x18 |
| AIStopDMA | 0x800FEC00 | 0x18 |
| AIGetDMABytesLeft | 0x800FEC18 | 0x10 |
| AICheckInit | 0x800FEC28 | 0x8 |
| AISetStreamPlayState | 0x800FEC30 | 0xD8 |
| AIGetStreamPlayState | 0x800FED08 | 0x10 |
| AISetDSPSampleRate | 0x800FED18 | 0xE0 |
| AIGetDSPSampleRate | 0x800FEDF8 | 0x14 |
| __AI_set_stream_sample_rate | 0x800FEE0C | 0xD4 |
| AIGetStreamSampleRate | 0x800FEEE0 | 0x10 |
| AISetStreamVolLeft | 0x800FEEF0 | 0x1C |
| AIGetStreamVolLeft | 0x800FEF0C | 0x10 |
| AISetStreamVolRight | 0x800FEF1C | 0x1C |
| AIGetStreamVolRight | 0x800FEF38 | 0x10 |
| AIInit | 0x800FEF48 | 0x16C |
| AIReset | 0x800FF0B4 | 0xC |
| __AISHandler | 0x800FF0C0 | 0x7C |
| __AIDHandler | 0x800FF13C | 0xAC |
| __AI_SRC_INIT | 0x800FF240 | 0x1E4 |

The [Pikmin 2 AI reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/ai/ai.c) supplies the retained DMA, stream, interrupt, and sample-rate converter algorithms. The target's version string identifies September 5, 2002. The [Melee AI reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/ai/ai.c) supplies real bodies for three APIs only represented by unlinked placeholders in the later source: reading DMA bytes left, querying initialization, and resetting initialization. Unlinked APIs and all remaining placeholders are omitted.

The sample-rate converter polls actual sample-counter changes and waits for a clock interval selected from the measured difference. Its empty polling loops are the original algorithm. This function requires `-opt nopeephole`, preserving redundant branch-to-next-instruction operations and instruction ordering. The other 20 functions require normal peephole optimization. Both fragments use GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ai -Cpp_exceptions off`.

The first C fragment owns the complete initialized and zero-initialized state. `.data` is `0x802CA8D8..0x802CA91C` (68 bytes), the exact version literal. Four following alignment bytes are outside the fragment. `.sdata` is `0x80375D58..0x80375D5C` (four bytes), the version pointer; four following bytes are also outside. `.sbss` is `0x80377AC0..0x80377B00` (64 bytes): six four-byte callback/initialization values followed by five eight-byte timing values. All sections have alignment 8. The second fragment owns no data.

The original private timing values are exposed globally to connect the two C fragments. `__CallbackStack` and `__OldStack` are exposed for the original assembly fallback. Explicit zero initializers preserve their declaration order after external linkage is introduced. `__AI_SRC_INIT` and the fallback wrapper are likewise externally linked only to connect these fragments. Their original static linkage is documented here. The bus-clock word is declared as a constant absolute symbol at `0x800000F8`: this preserves the original single load and avoids conservative aliasing introduced by the newly exported timing values. No cached clock substitute or hard-coded tick count is used.

| Object | Section | Address | Size | Production scope |
| --- | --- | --- | --- | --- |
| @1 | .data | 0x802CA8D8 | 0x44 | local |
| __AIVersion | .sdata | 0x80375D58 | 0x4 | global |
| __AIS_Callback | .sbss | 0x80377AC0 | 0x4 | local |
| __AID_Callback | .sbss | 0x80377AC4 | 0x4 | local |
| __CallbackStack | .sbss | 0x80377AC8 | 0x4 | global |
| __OldStack | .sbss | 0x80377ACC | 0x4 | global |
| __AI_init_flag | .sbss | 0x80377AD0 | 0x4 | local |
| __AID_Active | .sbss | 0x80377AD4 | 0x4 | local |
| bound_32KHz | .sbss | 0x80377AD8 | 0x8 | global |
| bound_48KHz | .sbss | 0x80377AE0 | 0x8 | global |
| min_wait | .sbss | 0x80377AE8 | 0x8 | global |
| max_wait | .sbss | 0x80377AF0 | 0x8 | global |
| buffer | .sbss | 0x80377AF8 | 0x8 | global |

The two isolated verification scripts resolve every call, pointer, and small-data relocation and compare all 2,224 C instruction bytes and 72 initialized data bytes against the original DOL. The original assembly interval is excluded from these totals. Whole-DOL SHA-1 and native objdiff remain integration checks.
