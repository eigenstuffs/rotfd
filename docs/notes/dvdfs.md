# Dolphin DVD filesystem

`src/dolphin/dvd/dvdfs.c` recovers all nine linked C functions at `0x800F7E04..0x800F85A4` (1952 bytes), with their complete literal data and small BSS.

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| __DVDFSInit | 0x800F7E04 | 0x38 | global |
| DVDConvertPathToEntrynum | 0x800F7E3C | 0x2F4 | global |
| DVDFastOpen | 0x800F8130 | 0x74 | global |
| DVDOpen | 0x800F81A4 | 0xC8 | global |
| DVDClose | 0x800F826C | 0x24 | global |
| entryToPath | 0x800F8290 | 0x160 | local |
| DVDGetCurrentDir | 0x800F83F0 | 0xC4 | global |
| DVDReadAsyncPrio | 0x800F84B4 | 0xC0 | global |
| cbForReadAsync | 0x800F8574 | 0x30 | local |

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/dvd/dvdfs.c) supplies the matching file-table initialization, path traversal, 8.3 format validation, opening, closing, path reconstruction, and asynchronous read algorithms. Unlinked directory enumeration, synchronous reads, seeks, stream preparation, and transfer-status APIs are omitted. `isSame`, `myStrncpy`, and `DVDConvertEntrynumToPath` inline; recursive `entryToPath` remains an emitted local function with the target's inline recursion expansion.

The local ABI describes the 12-byte FST entries, 48-byte command block, 60-byte file-info record, and the boot-information FST pointer at offset 0x38. Path comparisons use the external original `tolower` function and signed character promotion. The production filename literal is the original basename `dvdfs.c`. Three panic source-line values are 379, 742, and 748, each three lines later than the reference reconstruction; all runtime validation and message text otherwise match.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| BootInfo | .sbss | 0x803779B8 | 0x4 |
| FstStart | .sbss | 0x803779BC | 0x4 |
| FstStringStart | .sbss | 0x803779C0 | 0x4 |
| MaxEntryNum | .sbss | 0x803779C4 | 0x4 |
| currentDirectory | .sbss | 0x803779C8 | 0x4 |
| __DVDLongFileNameFlag | .sbss | 0x803779CC | 0x4 |
| __DVDThreadQueue | .sbss | 0x803779D0 | 0x8 |
| @114 | .data | 0x802CA140 | 0xC8 |
| @135 | .data | 0x802CA208 | 0x37 |
| @204 | .data | 0x802CA240 | 0x34 |
| @113 | .sdata | 0x80375CF8 | 0x8 |

The three `.data` strings occupy `0x802CA140..0x802CA274` (308 bytes), including a single padding byte after the 55-byte open warning. The following four-byte alignment gap precedes the next unit and is outside this split. The filename occupies `.sdata` `0x80375CF8..0x80375D00` (8 bytes). Small BSS occupies `0x803779B8..0x803779D8` (32 bytes); `__DVDLongFileNameFlag` and the eight-byte `__DVDThreadQueue` are global, and the other five pointers/counters are local. All sections have 8-byte alignment. The candidate lists the four compiler-local strings with exact sizes for native objdiff matching.

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dvd -Cpp_exceptions off`. `scratch/dvdfs/compile.py` and `scratch/dvdfs/verify.py` compare all text and initialized data after applying every call, address, and small-data relocation. The isolated result is `TEXT 1952 1952`, `.data 308 EXACT`, and `.sdata 8 EXACT`. There is no assembly inside this group. Whole-DOL SHA-1 and native objdiff verification remain integration checks.
