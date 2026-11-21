# Dolphin GX geometry setup

`src/dolphin/gx/GXGeometry.c` recovers nine linked C functions and 944 code bytes at `0x80113948..0x80113CF8`.

| Function | Address | Size |
| --- | --- | --- |
| __GXSetDirtyState | 0x80113948 | 0xA0 |
| GXBegin | 0x801139E8 | 0xF0 |
| __GXSendFlushPrim | 0x80113AD8 | 0x88 |
| GXSetLineWidth | 0x80113B60 | 0x48 |
| GXSetPointSize | 0x80113BA8 | 0x48 |
| GXEnableTexOffsets | 0x80113BF0 | 0x5C |
| GXSetCullMode | 0x80113C4C | 0x4C |
| GXSetCoPlanar | 0x80113C98 | 0x3C |
| __GXSetGenMode | 0x80113CD4 | 0x24 |

The [Melee GXGeometry reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXGeometry.c) supplies state flushing, primitive emission and geometry controls. The target invokes `__GXCalculateVLim` after descriptor or attribute format changes; this is corroborated by [Pikmin 2](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXGeometry.c). It retains the older direct repeated reads of `gx->dirtyState`, which generate the original instruction schedule. Unlinked state getters are omitted. Shared GX headers are unchanged.

The unit owns no initialized data, BSS or small data. GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 944 code bytes after relocation against the original DOL. Isolated scripts are under `scratch/GXGeometry`; reference source hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
