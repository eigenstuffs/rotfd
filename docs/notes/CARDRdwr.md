# Dolphin CARDRdwr

`src/dolphin/card/CARDRdwr.c` recovers 4 linked C functions and 640 text bytes.

| Function | Address | Size |
| --- | --- | --- |
| BlockReadCallback | 0x80109264 | 0xDC |
| __CARDRead | 0x80109340 | 0x64 |
| BlockWriteCallback | 0x801093A4 | 0xDC |
| __CARDWrite | 0x80109480 | 0x64 |

The [Pikmin 2 reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/card/CARDRdwr.c) supplies the exact algorithms; the [Melee reference](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/card/CARDRdwr.c) corroborates their private callback linkage. The segment/page callbacks advance buffer pointers and transfer counters, repeat the low-level operation and deliver the final callback. Errors release the control block when appropriate. The cast-lvalue pointer increment follows the original compiler-supported C syntax.

No data or BSS is owned; card state belongs to CARDBios. The shared ABI and already integrated source units are unchanged. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/card -Cpp_exceptions off` matches every text byte after relocation in the isolated `scratch/CARDRdwr` scripts. Reference files and hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
