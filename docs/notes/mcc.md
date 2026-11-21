# Dolphin multi-channel host communication

`src/dolphin/mcc/mcc.c` recovers 23 linked C functions and 6,420 text bytes at `0x8010DCDC..0x8010F5F0`.

| Function | Address | Size |
| --- | --- | --- |
| callbackEventStream | 0x8010DCDC | 0x84 |
| MCCStreamOpen | 0x8010DD60 | 0x78 |
| MCCStreamClose | 0x8010DDD8 | 0x38 |
| MCCStreamRead | 0x8010DE10 | 0x1E8 |
| LoadChannelInfo | 0x8010DFF8 | 0x11C |
| FlushChannelInfo | 0x8010E114 | 0x104 |
| SetChannelInfoDirty | 0x8010E218 | 0x8 |
| MakeMemoryMap | 0x8010E220 | 0xB8 |
| SearchFreeBlocks | 0x8010E2D8 | 0x100 |
| NotifyCompulsorily | 0x8010E3D8 | 0x108 |
| WaitAMinute | 0x8010E4E0 | 0x90 |
| MCCTxCallback | 0x8010E570 | 0x1C |
| MCCRxCallback | 0x8010E58C | 0x1C |
| MCCGetLastError | 0x8010E5A8 | 0x8 |
| MCCGetChannelInfo | 0x8010E5B0 | 0xD0 |
| MCCGetConnectionStatus | 0x8010E680 | 0xC0 |
| MCCNotify | 0x8010E740 | 0xDC |
| MCCSetChannelEventMask | 0x8010E81C | 0x110 |
| MCCOpen | 0x8010E92C | 0x21C |
| MCCClose | 0x8010EB48 | 0x1DC |
| MCCRead | 0x8010ED24 | 0x34C |
| MCCWrite | 0x8010F070 | 0x364 |
| MCCCheckAsyncDone | 0x8010F3D4 | 0x21C |

The [Melee MCC reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/mcc/mcc.c) supplies the channel map, allocation, host notification, stream transfer and asynchronous-state algorithms. The target's MCCStreamRead includes a first/repeated connection handshake before waiting: the first call marks the channel stream as started, subsequent calls notify the host with value zero. This is also present in the reference stream-write path and matches the target read instructions exactly.

Only linked APIs and their required inline helpers are included. Device initialization, stream write, channel lock/unlock, mailbox processing and other unlinked public APIs are omitted. The reference's empty debug helper is inline and contributes no function coverage or literal data. Original control flow and edge behavior, including the map loop's end condition, are retained.

The reconstruction retains explicitly named `reservedStack` local words where the reference uses unidentified unused locals. Their original semantic identities are unknown; they preserve the measured frame layout and are not invented game state. An isolated removal experiment changed 356 code bytes (stack accesses and frame sizes) while leaving the function sizes unchanged. The final source is again verified exact. These frame reservations are C declarations, with no generated assembly or fixed instruction words.

Owned BSS is `0x803343C0..0x803345E0` (544 bytes, alignment 32): gChannelInfo[16] is 384 bytes, gStreamWork, m_szAdapterMode and m_szInitCode are 32 bytes each, then channelInfo[16] is 64 bytes. The two unused adapter/initialization work buffers remain in the original pooled BSS, as shown by channelInfo references at offset 0x1E0. Removing them shifts six original instructions. `.sdata:0x80375DA8` holds the four-byte initialized dirty flag with alignment 8 and four external padding bytes. `.sbss:0x80377C50..0x80377C5C` has the one-byte last error, three padding bytes, a four-byte initialized-state flag, a two-byte asynchronous state and two tail padding bytes; the section requires alignment 8 and four external padding bytes follow. All symbols and exact object sizes are listed in the candidate.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/mcc -Cpp_exceptions off` matches all 6,420 text bytes and all four initialized bytes directly after relocation. The isolated scripts are under `scratch/mcc`, and unchanged references plus SHA-256 hashes are under `reference/melee-sdk`. Full-DOL SHA-1 and native objdiff remain integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/mcc/mcc.c` | `.sbss` | `0x80377C50..0x80377C5A` (10 bytes) | `0x80377C5A..0x80377C5C` (2 bytes) |

Current native objdiff credits `dolphin/mcc/mcc.c`: 558 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
