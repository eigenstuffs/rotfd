# Dolphin DSP release diagnostic hook

`src/dolphin/dsp/dsp_debug.c` recovers 1 linked C functions and 80 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __DSP_debug_printf | 0x801063F8 | 0x50 |

The Melee reference has a real empty variadic `__DSP_debug_printf` in release builds. The original 80-byte function saves incoming argument registers as required by the compiler's variadic calling convention, then returns. The recovered empty C body compiles to every original instruction. It is retained as the actual linked release implementation, not introduced as a substitute for missing behavior. The unlinked current-task getter is omitted. No data or BSS is owned.

References are [Melee's DSP family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/dsp) and [Pikmin 2's DSP family](https://github.com/projectPiki/pikmin2/tree/main/src/Dolphin/dsp). Unchanged reference files and hashes are retained under `reference/`; these are public community reconstructions and no original SDK source archive provenance is claimed.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/dsp -Cpp_exceptions off` and ordinary peephole optimization matches all 80 text bytes and 0 initialized data bytes after relocations are resolved. The reproducible isolated probes are in `scratch/dsp_debug`. No native assembly is counted. Full-DOL SHA-1 and native objdiff remain integration checks.
