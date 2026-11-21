# Dolphin GX framebuffer controls

`src/dolphin/gx/GXFrameBuf.c` recovers fourteen linked C functions and 2,788 code bytes at `0x80113CF8..0x801147DC`.

| Function | Address | Size |
| --- | --- | --- |
| GXAdjustForOverscan | 0x80113CF8 | 0x120 |
| GXSetDispCopySrc | 0x80113E18 | 0x90 |
| GXSetTexCopySrc | 0x80113EA8 | 0x90 |
| GXSetDispCopyDst | 0x80113F38 | 0x3C |
| GXSetTexCopyDst | 0x80113F74 | 0x154 |
| GXSetDispCopyFrame2Field | 0x801140C8 | 0x28 |
| GXSetCopyClamp | 0x801140F0 | 0x68 |
| GXSetDispCopyYScale | 0x80114158 | 0xC8 |
| GXSetCopyClear | 0x80114220 | 0x68 |
| GXSetCopyFilter | 0x80114288 | 0x228 |
| GXSetDispCopyGamma | 0x801144B0 | 0x1C |
| GXCopyDisp | 0x801144CC | 0x15C |
| GXCopyTex | 0x80114628 | 0x17C |
| GXClearBoundingBox | 0x801147A4 | 0x38 |

The [Melee GXFrameBuf reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXFrameBuf.c) supplies framebuffer source/destination, filtering, copying and overscan algorithms. The target uses integer output-line calculation, corroborated by [Pikmin 2](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXFrameBuf.c), including the fractional-scale divisibility correction and 1,024-line cap. The source keeps the height increment unsigned long to preserve its expression type through CodeWarrior's inline optimization. The linked render modes are NTSC 480 interlaced with and without deflicker, MPAL 480 interlaced deflicker, PAL 528 interlaced deflicker, and EURGB60 480 interlaced deflicker. Other reference modes and unlinked bounding-box reads are omitted. Shared GX headers are unchanged.

The five structured render-mode objects own `.data:0x802CF978..0x802CFAA4` (300 bytes, alignment 8); four external alignment bytes follow. Each is exactly 60 bytes. One four-byte float, 256.0, owns `.sdata2:0x803798D0..0x803798D4` (alignment 8), with four external alignment bytes following. There is no BSS or writable small data. The manifest records every object address, size and scope.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 2,788 code bytes and 304 initialized data bytes after relocation against the original DOL. Isolated scripts are under `scratch/GXFrameBuf`; reference source hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
