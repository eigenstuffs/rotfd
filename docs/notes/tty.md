# Dolphin TTY output

`src/dolphin/mcc/tty.c` recovers three linked C functions and 772 code bytes at `0x80110014..0x80110318`.

| Function | Address | Size |
| --- | --- | --- |
| TTYPrintf | 0x80110014 | 0x238 |
| ttyWrite | 0x8011024C | 0x50 |
| ttyFlush | 0x8011029C | 0x7C |

The [Melee TTY reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/mcc/tty.c) supplies the exact formatted-output, ring-buffer and host-notification algorithms. The CodeWarrior variadic ABI is the same typed declaration already verified in OSError. Existing formatting bounds, newline flushing, wraparound transfers and busy waiting remain intact. Only linked functions and the inline initialization predicate are retained; initialization, event processing and other unlinked APIs are omitted.

No initialized data is owned. The volatile 8 KiB gBuf is at `.bss:0x803365E0..0x803385E0`, alignment 8. The five volatile 4-byte state fields gChID, gReadDone, gPrintfID, gBufHead and gBufTail occupy `.sbss:0x80377C88..0x80377C9C`, alignment 8, with four external padding bytes afterward. Every symbol retains private linkage. The TTY gBuf reference also establishes the preceding FIO buffer's end at `0x803365E0`.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/mcc -Cpp_exceptions off` matches every text byte after relocation against the original DOL. Isolated scripts are under `scratch/tty`; the source reference and hash are recorded under `reference/melee-sdk`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
