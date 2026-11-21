# Dolphin GX indirect texture state

`src/dolphin/gx/GXBump.c` recovers six linked C functions and 888 code bytes at `0x80115A08..0x80115D80`.

| Function | Address | Size |
| --- | --- | --- |
| GXSetTevIndirect | 0x80115A08 | 0x9C |
| GXSetIndTexCoordScale | 0x80115AA4 | 0x17C |
| GXSetNumIndStages | 0x80115C20 | 0x28 |
| GXSetTevDirect | 0x80115C48 | 0x48 |
| __GXUpdateBPMask | 0x80115C90 | 0xCC |
| __GXFlushTextureState | 0x80115D5C | 0x24 |

The linked subset of the [Melee GXBump reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXBump.c) matches directly: indirect-stage setup and scaling, stage count, direct-mode helper, indirect texture mask and texture-state flush. Other reference APIs are unlinked and omitted. No initialized data, BSS or small data belongs to this unit; shared GX headers are unchanged.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 888 code bytes after relocation against the original DOL. Isolated scripts are under `scratch/GXBump`; the original reference hash is recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
