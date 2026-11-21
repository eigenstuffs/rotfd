# Dolphin DVD command state machine

`src/dolphin/dvd/dvd.c` recovers the complete linked DVD command-state unit, all 48 C functions at `0x800F85A4..0x800FAE04` (10,336 bytes), with its initialized data, dispatch tables, and BSS. No assembly fallback or partial C fragment is needed inside this unit.

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| defaultOptionalCommandChecker | 0x800F85A4 | 0x4 | local |
| DVDInit | 0x800F85A8 | 0xCC | global |
| stateReadingFST | 0x800F8674 | 0x94 | local |
| cbForStateReadingFST | 0x800F8708 | 0x8C | local |
| cbForStateError | 0x800F8794 | 0xAC | local |
| stateTimeout | 0x800F8840 | 0x34 | local |
| stateGettingError | 0x800F8874 | 0x28 | local |
| CategorizeError | 0x800F889C | 0xB4 | local |
| cbForStateGettingError | 0x800F8950 | 0x294 | local |
| cbForUnrecoveredError | 0x800F8BE4 | 0x68 | local |
| cbForUnrecoveredErrorRetry | 0x800F8C4C | 0x98 | local |
| stateGoToRetry | 0x800F8CE4 | 0x28 | local |
| cbForStateGoToRetry | 0x800F8D0C | 0x158 | local |
| stateCheckID | 0x800F8E64 | 0xE0 | local |
| stateCheckID3 | 0x800F8F44 | 0x34 | local |
| stateCheckID2a | 0x800F8F78 | 0x34 | local |
| cbForStateCheckID2a | 0x800F8FAC | 0x74 | local |
| stateCheckID2 | 0x800F9020 | 0x38 | local |
| cbForStateCheckID1 | 0x800F9058 | 0x114 | local |
| cbForStateCheckID2 | 0x800F916C | 0xE4 | local |
| cbForStateCheckID3 | 0x800F9250 | 0xFC | local |
| AlarmHandler | 0x800F934C | 0x44 | local |
| stateCoverClosed | 0x800F9390 | 0xCC | local |
| stateCoverClosed_CMD | 0x800F945C | 0x30 | local |
| cbForStateCoverClosed | 0x800F948C | 0x70 | local |
| stateMotorStopped | 0x800F94FC | 0x28 | local |
| cbForStateMotorStopped | 0x800F9524 | 0xE4 | local |
| stateReady | 0x800F9608 | 0x230 | local |
| stateBusy | 0x800F9838 | 0x320 | local |
| cbForStateBusy | 0x800F9B58 | 0x638 | local |
| DVDReadAbsAsyncPrio | 0x800FA190 | 0xDC | global |
| DVDReadAbsAsyncForBS | 0x800FA26C | 0xD0 | global |
| DVDReadDiskID | 0x800FA33C | 0xD4 | global |
| DVDCancelStreamAsync | 0x800FA410 | 0xBC | global |
| DVDInquiryAsync | 0x800FA4CC | 0xD0 | global |
| DVDReset | 0x800FA59C | 0x44 | global |
| DVDGetCommandBlockStatus | 0x800FA5E0 | 0x4C | global |
| DVDGetDriveStatus | 0x800FA62C | 0xAC | global |
| DVDSetAutoInvalidation | 0x800FA6D8 | 0x10 | global |
| DVDResume | 0x800FA6E8 | 0x50 | global |
| DVDCancelAsync | 0x800FA738 | 0x27C | global |
| DVDCancel | 0x800FA9B4 | 0xAC | global |
| cbForCancelSync | 0x800FAA60 | 0x24 | local |
| DVDCancelAll | 0x800FAA84 | 0x138 | global |
| cbForCancelAllSync | 0x800FABBC | 0x2C | local |
| DVDGetCurrentDiskID | 0x800FABE8 | 0x8 | global |
| DVDCheckDisk | 0x800FABF0 | 0xF8 | global |
| __DVDPrepareResetAsync | 0x800FACE8 | 0x11C | global |

The [Pikmin 2 SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/dvd/dvd.c) supplies the matching disc-change, drive-error, retry, command issue/completion, cancellation, and reset-preparation state machine. The target's linked synchronous `DVDCancelAll` and `cbForCancelAllSync` are recovered from the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/dvd/dvd.c). Their completion flag belongs between `ResetRequired` and `FirstTimeInBootrom` in small BSS. The target version literal identifies the DVD release build as October 29, 2002, 09:56:49, revision 0x2301. The FST-size panic uses source line 647 rather than the later reference's line 650.

The local header describes the original 32-byte boot block, 32-byte disc ID, 48-byte command block, 40-byte alarm, and the boot-information fields used by this unit. SDK register arrays, timing macros, and volatile state types retain the earlier verified ABI. Helpers for error handling, cancellation checks, command classification, queue issue, pause, and cancel-all dispatch inline into callers. Unlinked stream-preparation, synchronous stream cancellation, end-of-stream, and alarm-test APIs are omitted.

The four-byte default optional-command callback is intentionally empty in the reference and target and is selected by an initialized function pointer. `ImmCommand` and `DmaCommand` are actual optional-command identifier arrays, initialized to -1 and used by command classification. The unused disc-change diagnostic string is retained in the original data and the public reference. Its descriptive C name is a reconstruction choice. `DVDCancelAsync` retains one reserved local word from the reference to reproduce the original stack frame; its original source-level purpose is unknown.

| Object | Section | Address | Size | Kind where relevant |
| --- | --- | --- | --- | --- |
| @1 | .data | 0x802CA278 | 0x45 | string |
| @12 | .data | 0x802CA2C0 | 0xA | string |
| @18 | .data | 0x802CA2CC | 0x34 | string |
| @328 | .data | 0x802CA300 | 0x40 | jumptable |
| ImmCommand | .data | 0x802CA340 | 0xC |  |
| string_DVDChangeDiskAsyncMsg | .data | 0x802CA34C | 0x41 | string |
| @640 | .data | 0x802CA390 | 0x34 | jumptable |
| @736 | .data | 0x802CA3C4 | 0x34 | jumptable |
| BB2 | .bss | 0x80319660 | 0x20 |  |
| CurrDiskID | .bss | 0x80319680 | 0x20 |  |
| DummyCommandBlock | .bss | 0x803196A0 | 0x30 |  |
| ResetAlarm | .bss | 0x803196D0 | 0x28 |  |
| __DVDVersion | .sdata | 0x80375D00 | 0x4 |  |
| autoInvalidation | .sdata | 0x80375D04 | 0x4 |  |
| checkOptionalCommand | .sdata | 0x80375D08 | 0x4 |  |
| @17 | .sdata | 0x80375D0C | 0x6 | string |
| DmaCommand | .sdata | 0x80375D14 | 0x4 |  |
| executing | .sbss | 0x803779D8 | 0x4 |  |
| IDShouldBe | .sbss | 0x803779DC | 0x4 |  |
| bootInfo | .sbss | 0x803779E0 | 0x4 |  |
| PauseFlag | .sbss | 0x803779E4 | 0x4 |  |
| PausingFlag | .sbss | 0x803779E8 | 0x4 |  |
| AutoFinishing | .sbss | 0x803779EC | 0x4 |  |
| FatalErrorFlag | .sbss | 0x803779F0 | 0x4 |  |
| CurrCommand | .sbss | 0x803779F4 | 0x4 |  |
| Canceling | .sbss | 0x803779F8 | 0x4 |  |
| CancelCallback | .sbss | 0x803779FC | 0x4 |  |
| ResumeFromHere | .sbss | 0x80377A00 | 0x4 |  |
| CancelLastError | .sbss | 0x80377A04 | 0x4 |  |
| LastError | .sbss | 0x80377A08 | 0x4 |  |
| NumInternalRetry | .sbss | 0x80377A0C | 0x4 |  |
| ResetRequired | .sbss | 0x80377A10 | 0x4 |  |
| CancelAllSyncComplete | .sbss | 0x80377A14 | 0x4 |  |
| FirstTimeInBootrom | .sbss | 0x80377A18 | 0x4 |  |
| DVDInitialized | .sbss | 0x80377A1C | 0x4 |  |
| LastState | .sbss | 0x80377A20 | 0x4 |  |

Section ownership and padding:

- `.data` is `0x802CA278..0x802CA3F8` (384 bytes), alignment 8. It includes three compiler-local literal strings, one named retained message, the three-word immediate-command array, and three compiler-generated jump tables. The tables are 64 bytes at `0x802CA300`, 52 bytes at `0x802CA390`, and 52 bytes at `0x802CA3C4`. Literal padding is separate from object sizes.
- `.bss` is `0x80319660..0x803196F8` (152 bytes), alignment 32. The first two objects each require 32-byte alignment. The command block and reset alarm follow immediately, with no invented trailing padding object.
- `.sdata` is `0x80375D00..0x80375D18` (24 bytes), alignment 8. The six-byte filename at `0x80375D0C` has two padding bytes before the four-byte DMA-command array at `0x80375D14`.
- `.sbss` is `0x803779D8..0x80377A24` (76 bytes), alignment 8. Its 19 state objects each occupy four bytes. `LastState` at `0x80377A20` has size four; the next four bytes are an alignment gap outside this split. `LastState` and `__DVDVersion` are global. Other owned state/data objects are local.

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dvd -Cpp_exceptions off`, with peephole optimization enabled. `scratch/dvd/compile.py` and `scratch/dvd/verify.py` reproduce the isolated verification. Every code, address, callback-pointer, jump-table, and small-data relocation is resolved to its original address before comparison against the DOL. The result is `TEXT 10336 10336`, `.data 384 EXACT`, and `.sdata 24 EXACT`. The manifest includes all function scopes, exact object sizes, compiler-local literals, and jump-table classifications. Whole-DOL SHA-1 and native objdiff verification remain the integration checks.
