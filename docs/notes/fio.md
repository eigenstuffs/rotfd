# Dolphin host file I/O

`src/dolphin/mcc/fio.c` recovers ten linked C functions and 2,596 text bytes at `0x8010F5F0..0x80110014`.

| Function | Address | Size |
| --- | --- | --- |
| fioMccChannelEvent | 0x8010F5F0 | 0xC0 |
| FIOFclose | 0x8010F6B0 | 0xB4 |
| FIOFread | 0x8010F764 | 0xE0 |
| FIOFseek | 0x8010F844 | 0x12C |
| fioPacketMakeHeader | 0x8010F970 | 0xC4 |
| fioPacketSendPacket | 0x8010FA34 | 0x144 |
| fioPacketReceiveResult | 0x8010FB78 | 0x168 |
| fioPacketReceiveDone | 0x8010FCE0 | 0xC |
| fioPacketRead | 0x8010FCEC | 0xC4 |
| fioPacketResultRead | 0x8010FDB0 | 0x264 |

The [Melee FIO reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/mcc/fio.c) supplies the packet headers, sequence tracking, stream reads, completion callbacks, and close/read/seek API algorithms. The target additionally rejects read buffers whose address is not 32-byte aligned. Error delivery and the original busy/completion polling are preserved. Only linked functions and the inline helpers they use are included; unlinked initialization, open, write and other APIs are omitted.

The original pooled data survives removed APIs. Nineteen descriptive static character arrays retain all original strings in their observed order, including the Sep 5 2002 FIO version, channel diagnostics and write-error messages. This preserves both linked literal references and unreferenced bytes without adding dummy functions. These are source text literals, not binary blobs. The unlinked print buffer is omitted; the adjacent TTY buffer proves the FIO BSS boundary. Reference hashes are recorded under `reference/melee-sdk`.

Owned `.data` is `0x802CF3C0..0x802CF613` (595 bytes, alignment 8); five external padding bytes precede GX data at `0x802CF618`. BSS is `0x803345E0..0x803365E0` (8,192 bytes, alignment 8), containing gBuf[8192]. `.sdata:0x80375DB0..0x80375DB8` holds the one-byte block count, three padding bytes, and four-byte completion flag. `.sbss:0x80377C60..0x80377C84` contains the exact private 4-byte state fields plus the one-byte last error and three padding bytes; four external padding bytes follow. Both small sections require alignment 8. The candidate records each string's actual size and every private symbol scope.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/mcc -Cpp_exceptions off` matches all 2,596 text bytes and all 603 initialized data bytes after relocation against the original DOL. Isolated scripts are under `scratch/fio`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
