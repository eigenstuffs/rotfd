# Dolphin initial filesystem-table loading

`src/dolphin/dvd/fstload.c` recovers all 2 linked C functions at `0x800FB2BC..0x800FB4FC` (576 bytes).

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| cb | 0x800FB2BC | 0xD8 | local |
| __fstLoad | 0x800FB394 | 0x168 | global |

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/dvd/fstload.c) supplies the typed boot-block, command-block, and disc-ID algorithms. The [Pikmin 2 reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/dvd/fstload.c) corroborates the target's 63-byte static boot-block buffer. The callback first reads the boot block and then the filesystem table, and restarts disc identification after a cover-close result. `__fstLoad` waits for the drive to finish, installs the table's location and maximum length in low memory, copies the disc ID, prints the original diagnostics, and updates the arena high boundary.

The source retains the initial arena-high query even though its result is unused. The reference's empty switch in the polling loop is omitted; it emitted no target instructions. Buffer rounding and the original local disc-ID scratch allocation preserve the 0x60-byte stack frame. The local typed command block replaces the later reference's opaque byte array.

`.data` is `0x802CA440..0x802CA4B0` (112 bytes), containing all five diagnostic strings and their padding. `.sdata` is `0x80375D18..0x80375D24` (12 bytes), containing newline, OFF, and ON strings with separate padding; four following alignment bytes are outside this split. `.bss` is `0x80319718..0x80319788` (112 bytes): a 63-byte buffer, one padding byte, and a 48-byte static command block. `.sbss` is `0x80377A30..0x80377A3C` (12 bytes); the following four-byte gap is outside the unit. All sections have 8-byte alignment and all objects are local. The manifest records all eight literal symbols and their exact lengths.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @26 | .data | 0x802CA440 | 0x1A |
| @27 | .data | 0x802CA45C | 0x16 |
| @28 | .data | 0x802CA474 | 0x14 |
| @29 | .data | 0x802CA488 | 0x14 |
| @32 | .data | 0x802CA49C | 0x14 |
| bb2Buf | .bss | 0x80319718 | 0x3F |
| block$14 | .bss | 0x80319758 | 0x30 |
| @25 | .sdata | 0x80375D18 | 0x2 |
| @30 | .sdata | 0x80375D1C | 0x4 |
| @31 | .sdata | 0x80375D20 | 0x3 |
| status | .sbss | 0x80377A30 | 0x4 |
| bb2 | .sbss | 0x80377A34 | 0x4 |
| idTmp | .sbss | 0x80377A38 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dvd -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/fstload` resolve all call, address, and small-data relocations, then compare every emitted byte against the original DOL. They verify 576 code bytes and 124 initialized data bytes exactly. No assembly is introduced or counted by this unit. Whole-DOL SHA-1 and native objdiff verification remain the integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/dvd/fstload.c` | `.sdata` | `0x80375D18..0x80375D23` (11 bytes) | `0x80375D23..0x80375D24` (1 byte) |

Current native objdiff credits `dolphin/dvd/fstload.c`: 247 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
