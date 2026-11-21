# Dolphin CARD mounting and probing

`src/dolphin/card/CARDMount.c` recovers nine linked C functions and 2,808 code bytes at `0x8010AAB4..0x8010B5AC`.

| Function | Address | Size |
| --- | --- | --- |
| IsCard | 0x8010AAB4 | 0xCC |
| CARDProbe | 0x8010AB80 | 0x38 |
| CARDProbeEx | 0x8010ABB8 | 0x17C |
| DoMount | 0x8010AD34 | 0x410 |
| __CARDMountCallback | 0x8010B144 | 0x138 |
| CARDMountAsync | 0x8010B27C | 0x1A0 |
| CARDMount | 0x8010B41C | 0x48 |
| DoUnmount | 0x8010B464 | 0x9C |
| CARDUnmount | 0x8010B500 | 0xAC |

The [Pikmin 2 reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDMount.c) supplies the exact device checks, sector/latency selection, SRAM flash-ID persistence, mount state machine, callbacks, and unmount flow. The original GameChoice bit at absolute address `0x800030E3` disables card probing/mounting when set. The vendor-ID gate is an externally owned setting; it is not recreated or initialized in this unit. EXI locking, error propagation, cache invalidation, interrupt protection and callback ordering are preserved.

Two private eight-element unsigned-word tables occupy `.data` `0x802CF380..0x802CF3C0` (64 bytes), alignment 8: `SectorSizeTable` at F380 and `LatencyTable` at F3A0. No BSS or small data is owned. The shared CARD ABI and already integrated units are unchanged.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 2,808 text bytes and all 64 table bytes after relocation in `scratch/CARDMount`. Reference hashes are recorded under `reference/pikmin2-sdk`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
