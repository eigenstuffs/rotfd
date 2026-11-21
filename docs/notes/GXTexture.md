# Dolphin GX texture state

`src/dolphin/gx/GXTexture.c` recovers eighteen linked C functions and 3,684 code bytes at `0x80114BA4..0x80115A08`.

| Function | Address | Size |
| --- | --- | --- |
| __GetImageTileCount | 0x80114BA4 | 0xC8 |
| GXInitTexObj | 0x80114C6C | 0x274 |
| GXInitTexObjCI | 0x80114EE0 | 0x48 |
| GXInitTexObjLOD | 0x80114F28 | 0x194 |
| GXInitTexObjWrapMode | 0x801150BC | 0x28 |
| GXGetTexObjFmt | 0x801150E4 | 0x8 |
| GXLoadTexObjPreLoaded | 0x801150EC | 0x198 |
| GXLoadTexObj | 0x80115284 | 0x54 |
| GXInitTlutObj | 0x801152D8 | 0x48 |
| GXLoadTlut | 0x80115320 | 0x9C |
| GXInitTexCacheRegion | 0x801153BC | 0x120 |
| GXInitTlutRegion | 0x801154DC | 0x48 |
| GXInvalidateTexAll | 0x80115524 | 0x48 |
| GXSetTexRegionCallback | 0x8011556C | 0x14 |
| GXSetTlutRegionCallback | 0x80115580 | 0x14 |
| __SetSURegs | 0x80115594 | 0xB8 |
| __GXSetSUTexRegs | 0x8011564C | 0x17C |
| __GXSetTmemConfig | 0x801157C8 | 0x240 |

The [Melee GXTexture reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXTexture.c) supplies image tiling, texture/TLUT objects, loading, cache regions and texture-coordinate state. The target additionally checks the `tevTcEnab` stage bit when automatically setting texture-coordinate registers, corroborated by [Pikmin 2](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXTexture.c). The older target TMEM configuration routine matches Melee. The tile-shift helper is inline; unlinked texture getters, preload APIs and unused conversion tables are omitted. Release-only code excludes the reference debug assertions. Shared GX headers are unchanged.

Two compiler jump tables own `.data:0x802CFAA8..0x802CFBD8` (304 bytes, alignment 8). Seven eight-byte hardware register-ID arrays and the six-byte GX-to-hardware filter table own `.sdata:0x80375DD0..0x80375E0E` (62 bytes, alignment 8); two external alignment bytes follow. Floating-point constants own `.sdata2:0x803798D8..0x80379900` (40 bytes, alignment 8), including the four-byte internal alignment gap before the conversion double. There is no BSS. The manifest lists all objects, literal sizes, jump tables and scopes.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 3,684 code bytes and 406 initialized data bytes after relocation against the original DOL. Isolated scripts are under `scratch/GXTexture`; original reference hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
