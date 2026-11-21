# Dolphin DVD command queues

`src/dolphin/dvd/dvdqueue.c` recovers all 5 linked C functions at `0x800FAE04..0x800FAFFC` (504 bytes).

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| __DVDClearWaitingQueue | 0x800FAE04 | 0x38 | global |
| __DVDPushWaitingQueue | 0x800FAE3C | 0x68 | global |
| __DVDPopWaitingQueue | 0x800FAEA4 | 0xA0 | global |
| __DVDCheckWaitingQueue | 0x800FAF44 | 0x58 | global |
| __DVDDequeueWaitingQueue | 0x800FAF9C | 0x60 | global |

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/dvd/dvdqueue.c) supplies the exact four-priority circular-queue algorithms. Queue heads are eight-byte sentinel records sharing the command block's first two link fields. Interrupt protection surrounds searches and mutations; the pop operation preserves the original release/reacquire sequence between finding a queue and detaching its first command. `PopWaitingQueuePrio` inlines. The unlinked membership test and queue-dump API, including its names and diagnostic strings, are omitted.

The only owned object is local `WaitingQueue`, 32 bytes at `.bss` `0x803196F8..0x80319718`, alignment 8. This unit has no initialized data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| WaitingQueue | .bss | 0x803196F8 | 0x20 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dvd -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/dvdqueue` resolve all call, address, and small-data relocations, then compare every emitted byte against the original DOL. They verify 504 code bytes and 0 initialized data bytes exactly. No assembly is introduced or counted by this unit. Whole-DOL SHA-1 and native objdiff verification remain the integration checks.
