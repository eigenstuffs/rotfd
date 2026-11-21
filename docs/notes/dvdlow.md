# Dolphin DVD low-level commands

`src/dolphin/dvd/dvdlow.c` recovers all 20 linked C functions in `0x800F6FC4..0x800F7E04` (3648 bytes). No native assembly is present in this group.

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| __DVDInitWA | 0x800F6FC4 | 0x40 | global |
| __DVDInterruptHandler | 0x800F7004 | 0x2E0 | global |
| AlarmHandler | 0x800F72E4 | 0x84 | local |
| AlarmHandlerForTimeout | 0x800F7368 | 0x70 | local |
| Read | 0x800F73D8 | 0x110 | local |
| SeekTwiceBeforeRead | 0x800F74E8 | 0x80 | local |
| DVDLowRead | 0x800F7568 | 0x298 | global |
| DVDLowSeek | 0x800F7800 | 0x94 | global |
| DVDLowWaitCoverClose | 0x800F7894 | 0x2C | global |
| DVDLowReadDiskID | 0x800F78C0 | 0xA4 | global |
| DVDLowStopMotor | 0x800F7964 | 0x8C | global |
| DVDLowRequestError | 0x800F79F0 | 0x8C | global |
| DVDLowInquiry | 0x800F7A7C | 0x9C | global |
| DVDLowAudioStream | 0x800F7B18 | 0x98 | global |
| DVDLowRequestAudioStatus | 0x800F7BB0 | 0x8C | global |
| DVDLowAudioBufferConfig | 0x800F7C3C | 0x9C | global |
| DVDLowReset | 0x800F7CD8 | 0xBC | global |
| DVDLowBreak | 0x800F7D94 | 0x14 | global |
| DVDLowClearCallback | 0x800F7DA8 | 0x18 | global |
| __DVDLowSetWAType | 0x800F7DC0 | 0x44 | global |

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/dvd/dvdlow.c) supplies the drive commands, interrupt decoding, timeout and read-workaround algorithms. The local header reconstructs the alarm, disc ID, and drive-info layouts, absolute volatile DI/PI register arrays, and bus-clock-based timing macros. Using register arrays rather than cast pointer expressions is significant for matching the compiler's address calculations.

The target interrupt handler cancels its timeout alarm only after detecting a nonzero completion/error cause, in the same branch that clears `ResetOccurred`. The reference cancels it unconditionally at entry. Moving this operation to the original conditional position recovers both register allocation and all instruction bytes. Remaining algorithms match the reference after header adaptation. The read-history fields are named by their actual use (buffer address, byte length, disc offset). The original cache-hit condition and timing arithmetic are preserved exactly.

`ProcessNextCommand`, `SetTimeoutAlarm`, `HitCache`, `DoJustRead`, and `WaitBeforeRead` inline into their callers. The unlinked reset-cover callback setter and cover-status getter are omitted. `__DVDLowSetWAType` has external linkage in this reconstruction, consistent with the existing target map. Other public definitions are emitted with global ELF binding; previously inferred weak labels do not change original instruction bytes. All private functions and all data objects retain local linkage.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| CommandList | .bss | 0x80319590 | 0x3C |
| AlarmForWA | .bss | 0x803195D0 | 0x28 |
| AlarmForTimeout | .bss | 0x803195F8 | 0x28 |
| AlarmForBreak | .bss | 0x80319620 | 0x28 |
| Prev | .bss | 0x80319648 | 0xC |
| Curr | .bss | 0x80319654 | 0xC |
| FirstRead | .sdata | 0x80375CF0 | 0x4 |
| StopAtNextInt | .sbss | 0x80377970 | 0x4 |
| LastLength | .sbss | 0x80377974 | 0x4 |
| Callback | .sbss | 0x80377978 | 0x4 |
| ResetCoverCallback | .sbss | 0x8037797C | 0x4 |
| LastResetEnd | .sbss | 0x80377980 | 0x8 |
| ResetOccurred | .sbss | 0x80377988 | 0x4 |
| WaitingCoverClose | .sbss | 0x8037798C | 0x4 |
| Breaking | .sbss | 0x80377990 | 0x4 |
| WorkAroundType | .sbss | 0x80377994 | 0x4 |
| WorkAroundSeekLocation | .sbss | 0x80377998 | 0x4 |
| LastReadFinished | .sbss | 0x803779A0 | 0x8 |
| LastReadIssued | .sbss | 0x803779A8 | 0x8 |
| LastCommandWasRead | .sbss | 0x803779B0 | 0x4 |
| NextCommandNumber | .sbss | 0x803779B4 | 0x4 |

`.bss` occupies `0x80319590..0x80319660` (208 bytes), including the four-byte alignment gap after the three 20-byte commands. The three alarms are 40 bytes each; the unused break alarm remains in the target BSS. `.sbss` occupies `0x80377970..0x803779B8` (72 bytes), including four bytes of alignment before the 64-bit `LastReadFinished`. Its three time values each occupy eight bytes, not separate four-byte objects at their interior references. `.sdata` owns only the four-byte initial true value for `FirstRead` at `0x80375CF0..0x80375CF4`; the following four bytes are alignment outside the object. All three sections have 8-byte alignment. There are no strings or jump tables.

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dvd -Cpp_exceptions off`; peephole optimization remains enabled. `scratch/dvdlow/compile.py` and `scratch/dvdlow/verify.py` resolve every call, absolute address, and small-data relocation and report `TEXT 3648 3648` and `.sdata 4 EXACT`. The manifest records each object's complete size and all scopes and external mappings. Whole-DOL SHA-1 and native objdiff verification remain integration checks.
