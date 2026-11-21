# Dolphin GX pixel engine controls

`src/dolphin/gx/GXPixel.c` recovers twelve linked C functions and 1,592 code bytes at `0x801164F0..0x80116B28`.

| Function | Address | Size |
| --- | --- | --- |
| GXSetFog | 0x801164F0 | 0x21C |
| GXSetFogRangeAdj | 0x8011670C | 0x100 |
| GXSetBlendMode | 0x8011680C | 0x54 |
| GXSetColorUpdate | 0x80116860 | 0x2C |
| GXSetAlphaUpdate | 0x8011688C | 0x2C |
| GXSetZMode | 0x801168B8 | 0x34 |
| GXSetZCompLoc | 0x801168EC | 0x38 |
| GXSetPixelFmt | 0x80116924 | 0xE8 |
| GXSetDither | 0x80116A0C | 0x2C |
| GXSetDstAlpha | 0x80116A38 | 0x3C |
| GXSetFieldMask | 0x80116A74 | 0x38 |
| GXSetFieldMode | 0x80116AAC | 0x7C |

The [Melee GXPixel reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXPixel.c) supplies fog, blending, depth and field-state algorithms. The target includes orthographic fog and local register updates using compiler bitfield intrinsics, corroborated by [Pikmin 2](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXPixel.c). The existing perspective-fog normalization, fog range emission, pixel-format mapping and field helpers retain their older forms. The unlinked fog-adjustment table initializer is omitted. Shared GX headers are unchanged.

The eight-entry pixel-format mapping owns `.data:0x802CFC50..0x802CFC70` (32 bytes, alignment 8). Floating-point constants own `.sdata2:0x80379900..0x80379938` (56 bytes, alignment 8), including the compiler's internal alignment gaps before doubles. There is no BSS or writable small data. The manifest lists every constant and its actual size.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 1,592 code bytes and 88 initialized data bytes after relocation against the original DOL. Isolated scripts are under `scratch/GXPixel`; reference hashes are recorded under `reference/`. Compiler bitfield intrinsics remain C expressions; no native assembly bodies are introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
