# Dolphin AX compressor coefficients

`src/dolphin/ax/AXComp.c` recovers 0 linked C functions and 0 code bytes.

The newer TTYD reconstruction supplies the exact 3,360-entry unsigned 16-bit compressor table. The compiled table matches all original bytes at `.data` `0x802CAAE0..0x802CC520` (6,720 bytes), alignment 8. The table has global linkage and is referenced by the recovered AX command-list builder. This is a data-only source unit: it adds no recovered PowerPC function or code bytes to C coverage.

The direct references are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged reference files, file hashes and license information are preserved under `reference/`. Source differences described above are verified against the original game instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __AXCompressorTable | .data | 0x802CAAE0 | 0x1A40 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/AXComp` resolve all applicable relocations and verify 0/0 code bytes and 6,720/6,720 initialized data bytes exactly against the original DOL. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.
