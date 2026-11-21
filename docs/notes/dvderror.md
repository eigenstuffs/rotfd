# Dolphin DVD error-code storage

`src/dolphin/dvd/dvderror.c` recovers all 2 linked C functions at `0x800FAFFC..0x800FB194` (408 bytes).

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| ErrorCode2Num | 0x800FAFFC | 0x11C | local |
| __DVDStoreErrorCode | 0x800FB118 | 0x7C | global |

The [Pikmin 2 SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/dvd/dvderror.c) supplies the exact 18-entry error table and conversion logic. The older Melee table has only 16 entries. `ErrorCode2Num` retains local linkage and the reference's no-inline pragma, reproducing its unrolled search. Two special error values encode as 255 and 254; other errors combine a clamped status byte with a table/range lookup. The resulting byte is written to `OSSramEx.dvdErrorCode` at offset 0x24 through the verified SRAM lock/unlock API. The local SRAM extension layout follows the Melee SDK header.

The only owned data is global `ErrorTable`, eighteen 32-bit words at `.data` `0x802CA3F8..0x802CA440` (72 bytes), alignment 8. There is no BSS.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| ErrorTable | .data | 0x802CA3F8 | 0x48 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dvd -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/dvderror` resolve all call, address, and small-data relocations, then compare every emitted byte against the original DOL. They verify 408 code bytes and 72 initialized data bytes exactly. No assembly is introduced or counted by this unit. Whole-DOL SHA-1 and native objdiff verification remain the integration checks.
