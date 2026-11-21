# Dolphin CARD BIOS

`src/dolphin/card/CARDBios.c` recovers 25 linked C functions and 4,920 code bytes at `0x80106CCC..0x80108004`.

| Function | Address | Size |
| --- | --- | --- |
| __CARDDefaultApiCallback | 0x80106CCC | 0x4 |
| __CARDSyncCallback | 0x80106CD0 | 0x34 |
| __CARDExtHandler | 0x80106D04 | 0xD8 |
| __CARDExiHandler | 0x80106DDC | 0x118 |
| __CARDTxHandler | 0x80106EF4 | 0xA8 |
| __CARDUnlockedHandler | 0x80106F9C | 0x84 |
| __CARDEnableInterrupt | 0x80107020 | 0xC0 |
| __CARDReadStatus | 0x801070E0 | 0xF0 |
| __CARDClearStatus | 0x801071D0 | 0xAC |
| TimeoutHandler | 0x8010727C | 0xA4 |
| Retry | 0x80107320 | 0x22C |
| UnlockedCallback | 0x8010754C | 0x110 |
| __CARDStart | 0x8010765C | 0x1B4 |
| __CARDReadSegment | 0x80107810 | 0x134 |
| __CARDWritePage | 0x80107944 | 0x11C |
| __CARDEraseSector | 0x80107A60 | 0xE0 |
| CARDInit | 0x80107B40 | 0xAC |
| __CARDGetFontEncode | 0x80107BEC | 0x8 |
| __CARDSetDiskID | 0x80107BF4 | 0x38 |
| __CARDGetControlBlock | 0x80107C2C | 0xB8 |
| __CARDPutControlBlock | 0x80107CE4 | 0x64 |
| CARDFreeBlocks | 0x80107D48 | 0x150 |
| CARDGetSectorSize | 0x80107E98 | 0x84 |
| __CARDSync | 0x80107F1C | 0x98 |
| OnReset | 0x80107FB4 | 0x50 |

[Pikmin 2's reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDBios.c) supplies the matching card interrupt callbacks, retry/timeout handling, read/write/erase commands, per-channel disk identifiers, initialization and synchronization. The target reports September 5, 2002 at 05:35:20. [Melee's reference](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDBios.c) supplies the additionally linked sector-size getter and corroborates private helper linkage. SetupTimeoutAlarm and CARDGetResultCode inline; the other helper functions retain their original private linkage. The real default API callback is an empty function in both the original image and reference; it is not introduced as a replacement for missing behavior.

The private ABI has two `0x110`-byte control records with the embedded `0x50`-byte DSP task, thread queue, callbacks, alarm, card identifier and disk-ID pointer at the verified offsets. All retry paths, interrupt calls and clock-derived timeout calculations are retained. No native assembly is introduced.

`.data` is `0x802CF1C0..0x802CF218` (88 bytes), containing the 70-byte version string, two padding bytes and the 16-byte reset registration record. Eight following zero bytes before the next data group remain external padding. `.bss` is `0x80334180..0x803343C0` (576 bytes), containing the two card records and the 32-byte empty disk identifier. `.sdata` is `0x80375D88..0x80375D8C` (four bytes), the version pointer, followed by four external alignment bytes. The font encoding is a two-byte object at `0x80377C38`; its original `.sbss` split ends at `0x80377C3C`, including two padding bytes. Another four bytes before the next aligned source state are external. All sections have alignment 8; the compiler's actual small-BSS section size is two bytes.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @3 | .data | 0x802CF1C0 | 0x46 |
| ResetFunctionInfo | .data | 0x802CF208 | 0x10 |
| __CARDBlock | .bss | 0x80334180 | 0x220 |
| __CARDDiskNone | .bss | 0x803343A0 | 0x20 |
| __CARDVersion | .sdata | 0x80375D88 | 0x4 |
| __CARDEncode | .sbss | 0x80377C38 | 0x2 |

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches all 4,920 text bytes and all 92 initialized data bytes after relocation. The isolated compile and verification scripts are in `scratch/CARDBios`; reference files and hashes are recorded under `reference/`. Full-DOL SHA-1 and native objdiff remain the integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/card/CARDBios.c` | `.sbss` | `0x80377C38..0x80377C3A` (2 bytes) | `0x80377C3A..0x80377C3C` (2 bytes) |

Current native objdiff credits `dolphin/card/CARDBios.c`: 670 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
