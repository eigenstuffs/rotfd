# Dolphin host I/O

`src/dolphin/hio/hio.c` recovers eight C functions and 2,252 text bytes at `0x8010D410..0x8010DCDC`.

| Function | Address | Size |
| --- | --- | --- |
| TxHandler | 0x8010D410 | 0x40 |
| RxHandler | 0x8010D450 | 0x40 |
| HIOWriteMailbox | 0x8010D490 | 0x12C |
| HIORead | 0x8010D5BC | 0x17C |
| HIOWrite | 0x8010D738 | 0x17C |
| HIOReadAsync | 0x8010D8B4 | 0x160 |
| HIOWriteAsync | 0x8010DA14 | 0x160 |
| HIOReadStatus | 0x8010DB74 | 0x168 |

The [Melee host-I/O reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/hio/hio.c) supplies the EXI mailbox/status and synchronous/asynchronous DMA algorithms. The target adds an inline development-device check: when `__OSGetDIConfig()` returns `0xFF`, the unsigned halfword at low-memory `0x800030E6` must equal `0x8200`. The observed switch control flow and comparison types reproduce every instruction, including the two branch paths of that check. All EXI lock/select failures and accumulated transfer errors retain their original behavior.

Only linked functions are included. Device enumeration, initialization, mailbox read and their private handlers are absent from this range. The original private state is retained: Chan is initialized to -1 at `.sdata:0x80375DA0` (4 bytes), then Dev, TxCallback and RxCallback are three 4-byte BSS objects at `.sbss:0x80377C40..0x80377C4C`. This image retains the transfer functions despite the unlinked initialization API; these state values are not changed to invent functional behavior. Both sections require alignment 8; four external padding bytes follow each owned section. No other data or BSS is owned.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/hio -Cpp_exceptions off` matches all 2,252 text bytes and the four initialized data bytes after relocation. `scratch/hio/verify.py` checks directly against the original DOL and records all private symbol scopes. Unchanged reference files and hashes are recorded under `reference/melee-sdk`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
